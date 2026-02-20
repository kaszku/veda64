#!/usr/bin/env python3
"""Generate per-instruction ARM64 reference from ISA XML."""
import re, xml.etree.ElementTree as ET
from pathlib import Path

XML_DIR = Path("arm64/ISA_A64_xml_A_profile-2025-12")
OUT_FILE = Path("_arm64_operands.md")


def get_text(el):
    return "".join(el.itertext()).strip()


def asm_template_str(tmpl_el):
    """Reconstruct assembler template string from <asmtemplate> element."""
    parts = []
    # tmpl_el may have direct text then mixed children
    if tmpl_el.text:
        parts.append(tmpl_el.text)
    for child in tmpl_el:
        tag = child.tag
        if tag == "text":
            parts.append(child.text or "")
        elif tag == "a":
            parts.append(get_text(child))
        else:
            parts.append(get_text(child))
        if child.tail:
            parts.append(child.tail)
    return "".join(parts).strip()


def parse_file(path):
    """Parse one XML file → list of instruction-family dicts."""
    try:
        tree = ET.parse(path)
    except ET.ParseError:
        return []
    root = tree.getroot()

    # Only A64 instructions
    is_a64 = any(
        dv.get("key") == "isa" and dv.get("value") == "A64"
        for dv in root.iter("docvar")
    )
    if not is_a64:
        return []

    # --- Field widths from regdiagram boxes ---
    # Collect per-iclass field widths (box name → width)
    # We build a global map first, then per-iclass below
    global_field_widths = {}
    for box in root.iter("box"):
        name = box.get("name", "")
        width = box.get("width", "1")
        if name and not box.get("settings"):
            try:
                global_field_widths[name] = int(width)
            except ValueError:
                global_field_widths[name] = 1

    # --- Explanation map: link → (field_name, desc) ---
    explanations = {}  # link → (encodedin, intro_text)
    for expl in root.iter("explanation"):
        for sym_el in expl.iter("symbol"):
            link = sym_el.get("link", "")
            if not link:
                continue
            account = expl.find("account")
            if account is not None:
                encodedin = account.get("encodedin", "")
                intro = account.find("intro")
                desc = get_text(intro) if intro is not None else get_text(account)
            else:
                encodedin = ""
                desc = ""
            if link not in explanations:
                explanations[link] = (encodedin, desc)


    # --- Instruction section ---
    # Root element IS the instructionsection
    instr_sec = root if root.tag == "instructionsection" else root.find("instructionsection")
    if instr_sec is None:
        return []

    title = instr_sec.get("title", "")
    sec_id = instr_sec.get("id", "")
    is_alias = instr_sec.get("type", "") == "alias"

    # Alias target
    alias_for = ""
    if is_alias:
        for aliasto in instr_sec.iter("aliasto"):
            alias_for = aliasto.get("iformid", "")
            break

    families = []

    for iclass in instr_sec.iter("iclass"):
        iclass_name = iclass.get("name", "")

        # Per-iclass field widths (override global)
        iclass_field_widths = dict(global_field_widths)
        for box in iclass.iter("box"):
            name = box.get("name", "")
            width = box.get("width", "1")
            if name and not box.get("settings"):
                try:
                    iclass_field_widths[name] = int(width)
                except ValueError:
                    iclass_field_widths[name] = 1

        # Per-iclass decode pseudocode: noheading ps_section entries keyed by encoding name.
        # The ps 'name' attribute ends with the encoding name (e.g. "A64.foo.BAR_enc_name").
        iclass_decode_ps = {}  # encoding_name → decode text
        for child in iclass:
            if child.tag != "ps_section":
                continue
            for ps in child.iter("ps"):
                if ps.get("secttype", "") != "noheading":
                    continue
                pstext_el = ps.find("pstext")
                if pstext_el is None:
                    continue
                text = get_text(pstext_el)
                ps_name = ps.get("name", "")
                # ps name is like "A64.group.subgroup.ENC_NAME" — take last segment
                enc_key = ps_name.split(".")[-1]
                iclass_decode_ps[enc_key] = text

        encodings_out = []

        for enc in iclass.iter("encoding"):
            enc_name = enc.get("name", "")
            enc_label = enc.get("label", "")

            # Mnemonic from docvar
            mnemonic = ""
            for dv in enc.iter("docvar"):
                if dv.get("key") == "mnemonic":
                    mnemonic = dv.get("value", "")
                    break

            # Assembler template
            asm_templates = []
            for tmpl in enc.iter("asmtemplate"):
                s = asm_template_str(tmpl)
                if s:
                    asm_templates.append(s)
            asm_str = " / ".join(asm_templates)

            # Collect operand symbols from this encoding's asmtemplate
            operands = []
            seen_links = set()
            for tmpl in enc.iter("asmtemplate"):
                for a_el in tmpl.iter("a"):
                    link = a_el.get("link", "")
                    sym = get_text(a_el)
                    if not sym:
                        continue
                    if link in seen_links:
                        continue
                    seen_links.add(link)
                    encodedin, desc = explanations.get(link, ("", ""))
                    width = iclass_field_widths.get(encodedin, None)
                    field_str = f"{encodedin} ({width}b)" if encodedin and width else encodedin or "—"
                    operands.append({
                        "symbol": sym,
                        "link": link,
                        "encodedin": encodedin,
                        "field_str": field_str,
                        "desc": desc,
                    })

            # Decode pseudocode: from iclass noheading ps matching this encoding name.
            # If no exact match, fall back to the single ps in the iclass (shared decode).
            enc_ps_decode = iclass_decode_ps.get(enc_name, "")
            if not enc_ps_decode and len(iclass_decode_ps) == 1:
                enc_ps_decode = next(iter(iclass_decode_ps.values()))

            # For each operand, extract relevant decode lines
            for op in operands:
                field = op["encodedin"]
                if field and enc_ps_decode:
                    lines = [l for l in enc_ps_decode.splitlines()
                             if re.search(r'\b' + re.escape(field) + r'\b', l)]
                    op["ps_lines"] = lines
                else:
                    op["ps_lines"] = []

            encodings_out.append({
                "name": enc_name,
                "label": enc_label,
                "mnemonic": mnemonic,
                "asm": asm_str,
                "operands": operands,
                "decode_ps": enc_ps_decode,
            })

        if encodings_out:
            families.append({
                "title": title,
                "id": sec_id,
                "is_alias": is_alias,
                "alias_for": alias_for,
                "iclass": iclass_name,
                "encodings": encodings_out,
            })

    return families


def render_md(all_families):
    lines = []
    lines.append("# ARM64 Per-Instruction Reference\n")
    lines.append("Generated from ARM ISA XML A64 profile (2025-12).\n")

    # Group by instruction title/id
    from collections import defaultdict
    by_title = defaultdict(list)
    for fam in all_families:
        by_title[(fam["id"], fam["title"])].append(fam)

    instr_count = len(by_title)
    enc_count = sum(
        len(f["encodings"]) for fams in by_title.values() for f in fams
    )
    lines.append(f"Total: {instr_count} instructions, {enc_count} encodings.\n")
    lines.append("---\n")

    for (sec_id, title), fams in sorted(by_title.items(), key=lambda x: x[0][1]):
        # Section header
        alias_tag = ""
        if fams and fams[0]["is_alias"]:
            af = fams[0]["alias_for"]
            alias_tag = f" *(alias for {af})*" if af else " *(alias)*"
        lines.append(f"## {title}{alias_tag}\n")

        for fam in fams:
            for enc in fam["encodings"]:
                enc_name = enc["name"]
                label = enc["label"]
                mnemonic = enc["mnemonic"]
                heading = f"### Encoding: `{enc_name}`"
                if label:
                    heading += f"  [{label}]"
                if mnemonic:
                    heading += f"  — {mnemonic}"
                lines.append(heading + "\n")

                if enc["asm"]:
                    lines.append(f"**Assembly:** `{enc['asm']}`\n")

                if enc["operands"]:
                    lines.append("**Operands:**\n")
                    lines.append("| Symbol | Field | encoding-notes | pseudocode |")
                    lines.append("|--------|-------|----------------|------------|")
                    for op in enc["operands"]:
                        sym = op["symbol"].replace("|", "\\|")
                        field = op["field_str"].replace("|", "\\|")
                        desc = op["desc"][:120].replace("|", "\\|").replace("\n", " ")
                        ps = "<br>".join(
                            l.strip().replace("|", "\\|") for l in op["ps_lines"]
                        ) if op["ps_lines"] else ""
                        lines.append(f"| `{sym}` | {field} | {desc} | {ps} |")
                    lines.append("")

                if enc["decode_ps"]:
                    lines.append("**Pseudocode (Decode):**")
                    lines.append("```")
                    lines.append(enc["decode_ps"])
                    lines.append("```\n")


        lines.append("---\n")

    return "\n".join(lines) + "\n"


def main():
    xml_files = sorted(XML_DIR.glob("*.xml"))
    print(f"Parsing {len(xml_files)} XML files...")

    all_families = []
    for path in xml_files:
        all_families.extend(parse_file(path))

    print(f"Parsed {len(all_families)} iclass groups, rendering...")
    md = render_md(all_families)
    OUT_FILE.write_text(md, encoding="utf-8")

    # Count stats
    from collections import defaultdict
    by_title = defaultdict(list)
    for fam in all_families:
        by_title[(fam["id"], fam["title"])].append(fam)
    enc_count = sum(len(f["encodings"]) for fams in by_title.values() for f in fams)
    print(f"Written {OUT_FILE} — {len(by_title)} instructions, {enc_count} encodings")


if __name__ == "__main__":
    main()
