#!/usr/bin/env python3
"""
ARM64 Instruction XML Parser

This script parses ARM64 instruction encoding XML files and extracts
structured information about each instruction including encodings,
operands, and descriptions.
"""

import xml.etree.ElementTree as ET
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple
from dataclasses import dataclass, field
import json
import re as _re_module





# Map arrangement character to C++ Arrangement enum name
_CHAR_TO_ARR = {'b': 'Arrangement::B', 'h': 'Arrangement::H', 's': 'Arrangement::S', 'd': 'Arrangement::D', 'q': 'Arrangement::Q'}
_STR_TO_ARR = {
    'b': 'Arrangement::B', 'h': 'Arrangement::H', 's': 'Arrangement::S', 'd': 'Arrangement::D', 'q': 'Arrangement::Q',
    '8b': 'Arrangement::B8', '4h': 'Arrangement::H4', '2s': 'Arrangement::S2', '1d': 'Arrangement::D1',
    '16b': 'Arrangement::B16', '8h': 'Arrangement::H8', '4s': 'Arrangement::S4', '2d': 'Arrangement::D2',
    '1q': 'Arrangement::Q1', '2b': 'Arrangement::B2', '4b': 'Arrangement::B4', '2h': 'Arrangement::H2',
}

def _arr_enum(s):
    """Convert arrangement string to C++ Arrangement enum. Returns None for runtime/unknown."""
    if s is None:
        return None
    return _STR_TO_ARR.get(s)


class InstructionEncoding:
    """Represents a single encoding variant of an instruction."""

    def __init__(self):
        self.name: str = ""
        self.label: str = ""
        self.asm_template: str = ""
        self.bit_pattern: Dict[str, str] = {}
        self.fields: Dict[str, Dict] = {}
        self.docvars: Dict[str, str] = {}
        # Format information extracted from psname (e.g., A64.dpimm.addsub_imm.ADD_32_addsub_imm)
        self.format_group: str = ""   # e.g., 'dpimm', 'dpreg', 'ldst', 'sve', 'sme'
        self.format_iclass: str = ""  # e.g., 'addsub_imm', 'log_shift', 'branch_imm'
        self.symbol_map: Dict[str, Any] = {}  # {symbol_text: {'field': str, 'value_table': dict, 'description': str}}
        self.decode_ps: str = ''              # Raw ASL decode pseudocode text
        self.execute_ps: str = ''             # Raw ASL execute pseudocode text

    def to_dict(self) -> Dict:
        return {
            'name': self.name,
            'label': self.label,
            'asm_template': self.asm_template,
            'bit_pattern': self.bit_pattern,
            'fields': self.fields,
            'docvars': self.docvars,
            'format_group': self.format_group,
            'format_iclass': self.format_iclass
        }


class Instruction:
    """Represents an ARM64 instruction with all its variants."""

    def __init__(self):
        self.id: str = ""
        self.title: str = ""
        self.mnemonic: str = ""
        self.brief: str = ""
        self.description: str = ""
        self.instr_class: str = ""
        self.isa: str = ""
        self.encodings: List[InstructionEncoding] = []
        self.aliases: List[Dict] = []
        self.operands: List[Dict] = []
        self.docvars: Dict[str, str] = {}

    def to_dict(self) -> Dict:
        return {
            'id': self.id,
            'title': self.title,
            'mnemonic': self.mnemonic,
            'brief': self.brief,
            'description': self.description,
            'instr_class': self.instr_class,
            'isa': self.isa,
            'encodings': [enc.to_dict() for enc in self.encodings],
            'aliases': self.aliases,
            'operands': self.operands,
            'docvars': self.docvars
        }


class ARM64XMLParser:
    """Parser for ARM64 instruction XML files."""

    def __init__(self, xml_dir: Path):
        self.xml_dir = xml_dir
        self.instructions: List[Instruction] = []

    @staticmethod
    def _license_header() -> List[str]:
        """Return MIT license preamble lines for generated files."""
        return [
            "// SPDX-License-Identifier: MIT",
            "// Copyright (c) 2026 Kevin Szkudlapski",
            "// Auto-generated — do not edit",
            "",
        ]

    @staticmethod
    def _write_file(output_file: Path, code: List[str]):
        """Write file with trailing spaces removed."""
        with open(output_file, 'w', encoding='utf-8') as f:
            # Strip trailing spaces from each line
            cleaned_lines = [line.rstrip() for line in code]
            f.write('\n'.join(cleaned_lines))

    def parse_all(self) -> List[Instruction]:
        """Parse all XML files in the directory."""
        xml_files = sorted(self.xml_dir.glob("*.xml"))
        print(f"Found {len(xml_files)} XML files to parse")

        for xml_file in xml_files:
            try:
                instr = self.parse_file(xml_file)
                if instr:
                    self.instructions.append(instr)
            except Exception as e:
                print(f"Error parsing {xml_file.name}: {e}")

        print(f"Successfully parsed {len(self.instructions)} instructions")
        return self.instructions

    def parse_file(self, xml_file: Path) -> Optional[Instruction]:
        """Parse a single XML file."""
        tree = ET.parse(xml_file)
        root = tree.getroot()

        if root.tag != 'instructionsection':
            return None

        instr = Instruction()
        instr.id = root.get('id', '')
        instr.title = root.get('title', '')

        # Parse docvars at root level
        docvars_elem = root.find('docvars')
        if docvars_elem is not None:
            instr.docvars = self._parse_docvars(docvars_elem)
            instr.mnemonic = instr.docvars.get('mnemonic', '')
            instr.isa = instr.docvars.get('isa', '')
            instr.instr_class = instr.docvars.get('instr-class', '')

        # Parse description
        desc_elem = root.find('desc')
        if desc_elem is not None:
            brief_elem = desc_elem.find('brief/para')
            if brief_elem is not None:
                instr.brief = self._get_text(brief_elem)

            authored_elem = desc_elem.find('authored/para')
            if authored_elem is not None:
                instr.description = self._get_text(authored_elem)

        # Parse aliases
        alias_list = root.find('alias_list')
        if alias_list is not None:
            instr.aliases = self._parse_aliases(alias_list)

        # Parse operand explanations and build per-encoding symbol map
        explanations_elem = root.find('explanations')
        symbol_map_by_enc = {}
        if explanations_elem is not None:
            instr.operands = self._parse_operands(explanations_elem)
            symbol_map_by_enc = self._parse_symbol_map_by_encoding(explanations_elem)

        # Parse encodings with symbol data
        classes_elem = root.find('classes')
        if classes_elem is not None:
            instr.encodings = self._parse_encodings(classes_elem, symbol_map_by_enc)

        # Extract execute pseudocode (at instruction level, shared by all encodings)
        execute_ps_elem = root.find('.//pstext[@rep_section="execute"]')
        if execute_ps_elem is not None:
            execute_text = ''.join(execute_ps_elem.itertext()).strip()
            for enc in instr.encodings:
                enc.execute_ps = execute_text

        return instr

    def _parse_docvars(self, docvars_elem: ET.Element) -> Dict[str, str]:
        """Parse docvar elements into a dictionary."""
        docvars = {}
        for docvar in docvars_elem.findall('docvar'):
            key = docvar.get('key', '')
            value = docvar.get('value', '')
            if key:
                docvars[key] = value
        return docvars

    def _parse_aliases(self, alias_list: ET.Element) -> List[Dict]:
        """Parse alias information."""
        aliases = []
        for aliasref in alias_list.findall('aliasref'):
            alias = {
                'name': self._get_text(aliasref.find('text')),
                'page_id': aliasref.get('aliaspageid', ''),
                'file': aliasref.get('aliasfile', ''),
                'condition': self._get_text(aliasref.find('aliaspref'))
            }
            aliases.append(alias)
        return aliases

    def _parse_encodings(self, classes_elem: ET.Element, symbol_map_by_enc=None) -> List[InstructionEncoding]:
        """Parse encoding information from classes."""
        encodings = []

        for iclass in classes_elem.findall('iclass'):
            for encoding_elem in iclass.findall('encoding'):
                encoding = InstructionEncoding()
                encoding.name = encoding_elem.get('name', '')
                encoding.label = encoding_elem.get('label', '')

                # Parse docvars for this encoding
                docvars_elem = encoding_elem.find('docvars')
                if docvars_elem is not None:
                    encoding.docvars = self._parse_docvars(docvars_elem)

                # Parse assembly template
                asmtemplate_elem = encoding_elem.find('asmtemplate')
                if asmtemplate_elem is not None:
                    encoding.asm_template = self._parse_asm_template(asmtemplate_elem)

                # Parse bit fields from regdiagram (in parent iclass)
                regdiagram = iclass.find('regdiagram')
                if regdiagram is not None:
                    encoding.bit_pattern, encoding.fields = self._parse_regdiagram(regdiagram)
                    # Extract format from psname (e.g., A64.dpimm.addsub_imm.ADD_32_addsub_imm)
                    psname = regdiagram.get('psname', '')
                    parts = psname.split('.')
                    if len(parts) >= 3 and parts[0] == 'A64':
                        encoding.format_group = parts[1]   # e.g., 'dpimm'
                        encoding.format_iclass = parts[2]  # e.g., 'addsub_imm'

                # Also get specific box overrides from encoding element
                for box in encoding_elem.findall('box'):
                    name = box.get('name', '')
                    if name:
                        c_elements = box.findall('c')
                        if c_elements:
                            # Concatenate all <c> elements
                            binary_value = ''.join([c.text.strip() if c.text else '' for c in c_elements])
                            if binary_value:
                                encoding.bit_pattern[name] = binary_value

                # Parse bitdiffs attribute (e.g., "size == 10", "Q == 1", "cmode == 10x1", or "Q == 0 && size == 00")
                bitdiffs = encoding_elem.get('bitdiffs', '')
                if bitdiffs:
                    # Parse equality expressions, potentially with && (AND) operators
                    import re
                    # Split by && and process each condition
                    conditions = bitdiffs.split('&&')
                    for condition in conditions:
                        condition = condition.strip()
                        # Match patterns like "field == value" or "field == 0b101" or "field == 10x1" (with x for don't care)
                        # Also handle HTML entity &amp;&amp; if present
                        condition = condition.replace('&amp;', '&')
                        match = re.match(r'(\w+)\s*==\s*(0b)?([01x]+)', condition)
                        if match:
                            field_name = match.group(1)
                            pattern_value = match.group(3)

                            # Handle patterns with 'x' (don't care bits)
                            if 'x' in pattern_value.lower():
                                # For patterns like "10x1", we need to set a partial pattern
                                # Only the non-x bits are fixed
                                # Store this as a partial pattern in the encoding
                                if field_name in encoding.fields:
                                    encoding.fields[field_name]['partial_pattern'] = pattern_value
                                # Don't add to bit_pattern since it's partial
                            else:
                                # Simple binary value without don't care bits
                                # Override the field value in bit_pattern
                                encoding.bit_pattern[field_name] = pattern_value
                                # Also update the fields dict to mark this as fixed
                                if field_name in encoding.fields:
                                    encoding.fields[field_name]['fixed'] = pattern_value

                # Store per-encoding symbol map
                if symbol_map_by_enc and encoding.name in symbol_map_by_enc:
                    encoding.symbol_map = symbol_map_by_enc[encoding.name]

                # Store decode pseudocode from parent iclass
                decode_ps = iclass.find('.//pstext[@rep_section="decode"]')
                if decode_ps is not None:
                    encoding.decode_ps = ''.join(decode_ps.itertext()).strip()

                encodings.append(encoding)

        return encodings

    def _parse_regdiagram(self, regdiagram: ET.Element) -> tuple:
        """Parse register diagram to extract bit fields."""
        bit_pattern = {}
        fields = {}
        unnamed_field_count = 0

        for box in regdiagram.findall('box'):
            name = box.get('name', '')
            hibit = box.get('hibit', '')
            width = box.get('width', '1')
            settings = box.get('settings')

            # Generate a name for unnamed fields
            if not name:
                name = f'_unnamed_{unnamed_field_count}'
                unnamed_field_count += 1

            constraint = box.get('constraint', '')

            field_info = {
                'hibit': int(hibit) if hibit else None,
                'width': int(width) if width else 1,
            }

            # Capture constraint like "!= 0000" as a partial_pattern
            if constraint and constraint.startswith('!='):
                field_info['constraint'] = constraint

            # Check if this is a fixed value (may have multiple <c> elements)
            if settings:
                c_elements = box.findall('c')
                if c_elements:
                    # Concatenate all <c> elements to form the complete binary value
                    # Handle partial patterns like "x1" where some bits are fixed
                    binary_value = ''.join([c.text.strip() if c.text else '' for c in c_elements])
                    # ARM XML uses (1) and (0) for "should be" bits — strip parens
                    has_should_be = '(' in binary_value
                    clean_value = binary_value.replace('(', '').replace(')', '')
                    if clean_value:
                        # Check if fully fixed (all 0s and 1s)
                        if all(b in '01' for b in clean_value):
                            if has_should_be:
                                # "Should be" bits: fixed for operand purposes but
                                # NOT included in match mask (permissive decoding)
                                field_info['fixed'] = clean_value
                                field_info['should_be'] = True
                            else:
                                bit_pattern[name] = clean_value
                                field_info['fixed'] = clean_value
                        # Check if partially fixed (has some 0s or 1s mixed with x)
                        elif any(b in '01' for b in clean_value):
                            # Store raw pattern for reference, but mark as partial
                            field_info['fixed'] = None
                            field_info['partial_pattern'] = clean_value
                        else:
                            field_info['fixed'] = None
                    else:
                        field_info['fixed'] = None
                else:
                    field_info['fixed'] = None
            else:
                field_info['fixed'] = None

            fields[name] = field_info

        return bit_pattern, fields

    def _parse_asm_template(self, asmtemplate_elem: ET.Element) -> str:
        """Parse assembly template into a string."""
        parts = []
        for child in asmtemplate_elem:
            if child.tag == 'text':
                parts.append(child.text or '')
            elif child.tag == 'a':
                parts.append(child.text or '')

        # Also get any direct text
        if asmtemplate_elem.text:
            parts.insert(0, asmtemplate_elem.text)

        return ''.join(parts).strip()

    @staticmethod
    def _parse_template_operands(template: str) -> list:
        """Parse ARM assembly template to extract operand order and metadata.

        Returns list of dicts with keys: field, arrangement, qualifier, is_list, mem_base, mem_index
        Example: 'BRKPBS  <Pd>.B, <Pg>/Z, <Pn>.B, <Pm>.B'
        → [{'field': 'Pd', 'arrangement': 'b', 'qualifier': None},
           {'field': 'Pg', 'arrangement': None, 'qualifier': 'z'},
           {'field': 'Pn', 'arrangement': 'b', 'qualifier': None},
           {'field': 'Pm', 'arrangement': 'b', 'qualifier': None}]
        """
        import re
        # Strip mnemonic
        parts = template.strip().split(None, 1)
        if len(parts) < 2:
            return []
        operand_str = parts[1]

        result = []
        # Match template operands like <Pd>.B, <Pg>/Z, <Zn>.<T>, { <Zt>.S }, [<Xn|SP>], #<imm>
        # Split by comma but respect brackets
        depth = 0
        current = ''
        tokens = []
        for ch in operand_str:
            if ch in '{[':
                depth += 1
            elif ch in '}]':
                depth -= 1
            if ch == ',' and depth == 0:
                tokens.append(current.strip())
                current = ''
            else:
                current += ch
        if current.strip():
            tokens.append(current.strip())

        for token in tokens:
            # Detect memory bracket token vs register list token
            is_in_mem = token.strip().startswith('[')
            # is_list: only for explicit { } outside memory brackets (not [Xn{, #imm}] optional notation)
            is_list = '{' in token and not is_in_mem

            # For memory bracket tokens: extract optional imm field and mul_vl flag
            mem_imm_field = None
            mul_vl = False
            if is_in_mem:
                imm_inside = re.search(r'#<(\w+)>', token)
                if imm_inside:
                    mem_imm_field = imm_inside.group(1)
                mul_vl = 'MUL VL' in token.upper()

            # Find ALL field references in this token (handles register pairs like { <Zn1>.B, <Zn2>.B })
            # Each <Field> reference within the token becomes a separate operand entry
            field_matches = re.findall(r'<(\w+?)(?:\|SP)?>(?:\.([BHSDQbhsdq]))?(?:\[<(\w+)>\])?', token)
            if not field_matches:
                # Check for arrangement/qualifier patterns outside <> refs
                field_match = re.search(r'<(\w+?)(?:\|SP)?>', token)
                if not field_match:
                    imm_match = re.search(r'#<(\w+)>', token)
                    if imm_match:
                        result.append({'field': imm_match.group(1), 'type': 'imm', 'arrangement': None, 'qualifier': None,
                                       'in_mem_bracket': False, 'mul_vl': False, 'mem_imm_field': None, 'complex_mem': False})
                    elif re.search(r'\bZT0\b', token):
                        # Literal ZT0 register operand (SME lookup table)
                        result.append({'field': 'ZT0', 'type': 'zt0', 'arrangement': None, 'qualifier': None,
                                       'in_mem_bracket': False, 'mul_vl': False, 'mem_imm_field': None, 'complex_mem': False,
                                       'is_list': False, 'has_elem_index': False, 'index_field': None})
                    continue
                field_matches = [(field_match.group(1), '', '')]

            # For memory brackets with >1 REGISTER field reference: mark as complex (two-reg [Xn, Zm] form)
            # Exclude immediate fields (lowercase 'imm...') from the count — they're optional extra notation
            # like [<Xn|SP>{, #<imm>, MUL VL}] which has Xn + imm but is NOT a complex two-register bracket
            reg_field_matches = [(f, a, i) for f, a, i in field_matches
                                 if not f.lower().startswith('imm') and f != mem_imm_field]
            complex_mem = is_in_mem and len(reg_field_matches) > 1

            # Expand range notation: { <Zt1>.D-<Zt4>.D } → Zt1, Zt2, Zt3, Zt4
            # This happens when a list token has exactly 2 numbered Z-reg matches with a dash between them
            if is_list and len(field_matches) == 2:
                m1 = re.match(r'^(Z\w+?)(\d+)$', field_matches[0][0])
                m2 = re.match(r'^(Z\w+?)(\d+)$', field_matches[1][0])
                if m1 and m2 and m1.group(1) == m2.group(1):
                    n1, n2 = int(m1.group(2)), int(m2.group(2))
                    if n2 > n1 + 1:
                        # Range notation: expand intermediate registers
                        base_name = m1.group(1)
                        arr_char0 = field_matches[0][1]
                        field_matches = [(f'{base_name}{i}', arr_char0, '') for i in range(n1, n2 + 1)]

            # Merge <V><d> / <V><n> / <V><m> pairs into Vd/Vn/Vm scalar register references
            # Also merge <R><dn> / <R><n> pairs into Rdn/Rn GP register references
            merged = []
            skip_next = False
            _merge_suffixes = ('d', 'n', 'm', 'dn', 'da', 't')
            for fi in range(len(field_matches)):
                if skip_next:
                    skip_next = False
                    continue
                f, a, idx = field_matches[fi]
                if f in ('V', 'R') and fi + 1 < len(field_matches) and field_matches[fi + 1][0] in _merge_suffixes:
                    next_f = field_matches[fi + 1][0]
                    merged.append((f + next_f, a, idx))
                    skip_next = True
                else:
                    merged.append((f, a, idx))
            field_matches = merged

            for field, arr_char, idx_field in field_matches:
                # Check for arrangement: from <Field>.B capture or token-level search
                arr = arr_char.lower() if arr_char else None
                if not arr:
                    # Fallback: search entire token for arrangement
                    arr_match = re.search(r'<' + re.escape(field) + r'(?:\|SP)?>\s*\.([BHSDQbhsdq])\b', token)
                    arr = arr_match.group(1).lower() if arr_match else None
                # Variable arrangement like .<T> means use size field
                if not arr:
                    t_match = re.search(r'\.<(T\w*)>', token)
                    if t_match:
                        arr = t_match.group(1)

                # Check for qualifier: /Z, /M, or /<ZM> (variable M field)
                qual_match = re.search(r'/([ZMzm])\b', token)
                qual = qual_match.group(1).lower() if qual_match else None
                if not qual and '/<ZM>' in token:
                    qual = 'zm'  # variable qualifier: M=0→/Z, M=1→/M

                # Check for element index
                has_elem_index = bool(idx_field)
                index_field_name = idx_field if idx_field else None
                if not has_elem_index:
                    idx_match = re.search(r'\[<(\w+)>\]', token)
                    has_elem_index = idx_match is not None
                    index_field_name = idx_match.group(1) if idx_match else None

                result.append({
                    'field': field,
                    'arrangement': arr,
                    'qualifier': qual,
                    'is_list': is_list,
                    'has_elem_index': has_elem_index,
                    'index_field': index_field_name,
                    'type': 'reg',
                    'in_mem_bracket': is_in_mem,
                    'mul_vl': mul_vl,
                    'mem_imm_field': mem_imm_field,
                    'complex_mem': complex_mem,
                })

        return result

    def _generate_sve_index_expr(self, field_map, member_name, encoding_name):
        """Generate C++ expression to compute SVE element index from split i2/i3 fields."""
        # Try common index field patterns: i3h:i3l, i2h:i2l, i2, i3, imm
        for hi, lo, hi_w in [('i4h', 'i4l', None), ('i3h', 'i3l', None), ('i2h', 'i2l', None)]:
            if hi in field_map and not field_map[hi]['is_fixed'] and lo in field_map and not field_map[lo]['is_fixed']:
                hi_f = field_map[hi]['name']
                lo_f = field_map[lo]['name']
                lo_width = field_map[lo]['width']
                return f"op.index = (enc.{member_name}.{hi_f} << {lo_width}) | enc.{member_name}.{lo_f}; op.has_index = true;"
        # Split i4A/i4B/i4C pattern (e.g., fmlal_za_z8z8i_1)
        if 'i4A' in field_map and 'i4B' in field_map and 'i4C' in field_map:
            a_f = field_map['i4A']['name']
            b_f = field_map['i4B']['name']
            c_f = field_map['i4C']['name']
            b_w = field_map['i4B']['width']
            c_w = field_map['i4C']['width']
            return f"op.index = (enc.{member_name}.{a_f} << {b_w + c_w}) | (enc.{member_name}.{b_f} << {c_w}) | enc.{member_name}.{c_f}; op.has_index = true;"
        # Single index fields
        for idx_name in ['i4', 'i2', 'i3', 'i1']:
            if idx_name in field_map and not field_map[idx_name]['is_fixed']:
                idx_f = field_map[idx_name]['name']
                return f"op.index = enc.{member_name}.{idx_f}; op.has_index = true;"
        return None

    def _parse_operands(self, explanations_elem: ET.Element) -> List[Dict]:
        """Parse operand explanations."""
        operands = []

        for explanation in explanations_elem.findall('explanation'):
            symbol_elem = explanation.find('symbol')
            account_elem = explanation.find('account')

            if symbol_elem is not None:
                operand = {
                    'symbol': symbol_elem.text or '',
                    'encodedin': account_elem.get('encodedin', '') if account_elem is not None else '',
                    'description': ''
                }

                if account_elem is not None:
                    intro_para = account_elem.find('intro/para')
                    if intro_para is not None:
                        operand['description'] = self._get_text(intro_para)

                operands.append(operand)

        return operands

    def _parse_symbol_map_by_encoding(self, explanations_elem: ET.Element) -> Dict[str, Dict]:
        """Parse explanations into per-encoding symbol maps.

        Returns: {encoding_name: {symbol_text: {'field': str, 'value_table': dict, 'description': str}}}
        """
        result = {}
        for explanation in explanations_elem.findall('explanation'):
            enclist_str = explanation.get('enclist', '')
            enc_names = [e.strip() for e in enclist_str.split(',') if e.strip()]

            symbol_elem = explanation.find('symbol')
            if symbol_elem is None:
                continue
            symbol_text = symbol_elem.text or ''

            # Parse account (simple field mapping)
            account_elem = explanation.find('account')
            defn_elem = explanation.find('definition')

            sym_info: Dict[str, Any] = {'field': '', 'value_table': {}, 'description': ''}

            if account_elem is not None:
                sym_info['field'] = account_elem.get('encodedin', '')
                intro = account_elem.find('intro/para')
                if intro is not None:
                    desc = self._get_text(intro)
                    sym_info['description'] = desc
                    # Extract "defaulting to N" for optional operands
                    import re as _re_def
                    m_def = _re_def.search(r'defaulting to (\d+)', desc)
                    if m_def:
                        sym_info['default_val'] = int(m_def.group(1))

            if defn_elem is not None:
                sym_info['field'] = defn_elem.get('encodedin', '')
                # Parse value table
                tbl = defn_elem.find('table')
                if tbl is not None:
                    rows = tbl.findall('.//row')
                    # Skip header row (contains field name, not value)
                    for row in rows:
                        entries = [e.text or '' for e in row.findall('entry')]
                        if len(entries) >= 2 and entries[0].strip() not in ('', sym_info['field']):
                            sym_info['value_table'][entries[0].strip()] = entries[1].strip()

            for enc_name in enc_names:
                if enc_name not in result:
                    result[enc_name] = {}
                result[enc_name][symbol_text] = sym_info

        return result

    def _parse_asl_decode_ops(self, ps_text: str) -> Dict[str, tuple]:
        """Parse ARM ASL decode pseudocode to extract field transform operations.

        Returns dict mapping variable name to transform tuple:
        - ('uint', field)              for UInt(field)
        - ('signext', field)           for SignExtend(field)
        - ('signext_shift', field, n)  for SignExtend(field::'0'*n) -- branch offsets
        - ('shift_left', field, n)     for UInt(field) << n
        - ('conditional', field)       for if field == 'x' then ... else ...
        - ('opaque',)                  for anything else
        """
        import re
        ops: Dict[str, tuple] = {}
        if not ps_text:
            return ops

        for line in ps_text.splitlines():
            line = line.strip()
            if not line or line.startswith('//') or line.startswith('--'):
                continue

            # let d = UInt(Rd);  or  let n = UInt(Rn);
            m = re.match(r'let\s+(\w+)[^=]*=\s*UInt\((\w+)\)\s*;', line)
            if m:
                ops[m.group(1)] = ('uint', m.group(2))
                continue

            # let offset = SignExtend{}(imm26::'00');  (branch: field concat zeros)
            m = re.match(r"let\s+(\w+)[^=]*=\s*SignExtend\s*\{?\}?\s*\((\w+)::'(0+)'\)\s*;", line)
            if m:
                ops[m.group(1)] = ('signext_shift', m.group(2), len(m.group(3)))
                continue

            # let offset = SignExtend{}(imm9);
            m = re.match(r'let\s+(\w+)[^=]*=\s*SignExtend\s*\{?\}?\s*\((\w+)\)\s*;', line)
            if m:
                ops[m.group(1)] = ('signext', m.group(2))
                continue

            # let pos = UInt(hw) << 4;
            m = re.match(r'let\s+(\w+)[^=]*=\s*UInt\((\w+)\)\s*<<\s*(\d+)\s*;', line)
            if m:
                ops[m.group(1)] = ('shift_left', m.group(2), int(m.group(3)))
                continue

            # let offset = LSL(ZeroExtend{}(imm12), scale);  -- shift by variable
            # e.g. ARM ldst_pos: scale=UInt(size), offset=LSL(imm12, scale)
            m = re.match(r'let\s+(\w+)[^=]*=\s*LSL\([^,]+\((\w+)\)\s*,\s*(\w+)\)\s*;', line)
            if m:
                var, field_name, shift_var = m.group(1), m.group(2), m.group(3)
                # Record as shift_left_var: shifted by a variable that maps to a field
                ops[var] = ('shift_left_var', field_name, shift_var)
                continue

            # if sh == '0' then ... else ... (conditional immediate)
            m = re.match(r"let\s+(\w+)[^=]*=\s*if\s+(\w+)\s*==", line)
            if m:
                ops[m.group(1)] = ('conditional', m.group(2))
                continue

        # Second pass: resolve shift_left_var where shift_var maps to a uint field
        resolved = {}
        for var, op in ops.items():
            if op[0] == 'shift_left_var':
                _, field_name, shift_var = op
                shift_op = ops.get(shift_var)
                if shift_op and shift_op[0] == 'uint':
                    # shift_var = UInt(some_field) → shift_left_field
                    resolved[var] = ('shift_left_field', field_name, shift_op[1])
                else:
                    resolved[var] = ('opaque',)
            else:
                resolved[var] = op
        return resolved

    def _classify_symbol(self, symbol_text: str, sym_info: Dict, decode_ops: Dict) -> Optional[tuple]:
        """Classify an assembler symbol into an operand type.

        Returns tuple: (operand_type_tag, field, extras) or None if unclassifiable.
        operand_type_tag is one of: 'reg64', 'reg32', 'reg_sp64', 'reg_sp32',
        'imm_unsigned', 'imm_signed', 'label', 'shift_table', 'extend_table',
        'barrier_table', 'prefetch_table', 'condition', 'system_reg'
        """
        import re
        field = sym_info.get('field', '')
        value_table = sym_info.get('value_table', {})

        s = symbol_text.strip('<>').lower()

        # Register classification by symbol name pattern
        # X registers (64-bit)
        if re.match(r'^x[dtnm](\d+)?$', s) or re.match(r'^x[a-z]$', s):
            return ('reg64', field, {})
        # W registers (32-bit)
        if re.match(r'^w[dtnm](\d+)?$', s) or re.match(r'^w[a-z]$', s):
            return ('reg32', field, {})
        # Xd|SP, Xn|SP (64-bit with SP option)
        if '|wsp' in symbol_text.lower() or symbol_text.lower() in ('<wd|wsp>', '<wn|wsp>'):
            return ('reg_sp32', field, {})
        if '|sp' in symbol_text.lower() or symbol_text.lower() in ('<xd|sp>', '<xn|sp>'):
            return ('reg_sp64', field, {})

        # Value table types
        if value_table:
            sample_vals = list(value_table.values())
            if any('lsl' in v.lower() or 'lsr' in v.lower() or 'asr' in v.lower() or 'ror' in v.lower()
                   for v in sample_vals):
                return ('shift_table', field, {'table': value_table})
            if any('uxtb' in v.lower() or 'sxtb' in v.lower() or 'uxtw' in v.lower() or 'sxtx' in v.lower()
                   for v in sample_vals):
                return ('extend_table', field, {'table': value_table})
            if any(v.lower() in ('sy', 'st', 'ld', 'ish', 'ishst', 'ishld', 'nsh', 'nshst', 'osh')
                   for v in sample_vals):
                return ('barrier_table', field, {'table': value_table})
            # Generic value table (prefetch, option, etc.)
            return ('option_table', field, {'table': value_table})

        # Immediate classification
        if re.match(r'^imm\d*$', s) or s in ('simm', 'offset', 'pimm', 'uimm'):
            # Symbol name 'simm' explicitly means signed immediate (e.g. SMAX/SMIN imm8)
            if s == 'simm':
                return ('imm_signed', field, {})
            # Check decode_ops for transform type — look for ops referencing this field
            for var, op in decode_ops.items():
                if len(op) >= 2 and op[1] == field:
                    if op[0] == 'signext':
                        return ('imm_signed', field, {})
                    if op[0] == 'signext_shift':
                        return ('label', field, {'shift': op[2]})
            extras_imm = {}
            if 'default_val' in sym_info:
                extras_imm['default_val'] = sym_info['default_val']
            return ('imm_unsigned', field, extras_imm)

        if s in ('label', 'pcrel_addr'):
            # Check decode_ops for field-specific signext_shift
            for var, op in decode_ops.items():
                if len(op) >= 3 and op[1] == field and op[0] == 'signext_shift':
                    return ('label', field, {'shift': op[2]})
            return ('label', field, {'shift': 0})

        if s == 'cond':
            return ('condition', field, {})

        # System register
        if s in ('systemreg', 'sysreg', 'prfop', 'pstatefield', 'dc_op', 'at_op', 'tlbi_op'):
            return ('system', field, {})

        return None  # Cannot classify

    def _get_text(self, elem: Optional[ET.Element]) -> str:
        """Get text content from an element, handling None."""
        if elem is None:
            return ''
        return ''.join(elem.itertext()).strip()

    def save_to_json(self, output_file: Path):
        """Save parsed instructions to JSON file."""
        data = [instr.to_dict() for instr in self.instructions]
        with open(output_file, 'w', encoding='utf-8') as f:
            json.dump(data, f, indent=2, ensure_ascii=False)
        print(f"Saved {len(data)} instructions to {output_file}")

    def print_summary(self):
        """Print a summary of parsed instructions."""
        print("\n=== Instruction Summary ===")
        print(f"Total instructions: {len(self.instructions)}")

        # Count by instruction class
        class_counts = {}
        for instr in self.instructions:
            cls = instr.instr_class or 'unknown'
            class_counts[cls] = class_counts.get(cls, 0) + 1

        print("\nBy instruction class:")
        for cls, count in sorted(class_counts.items()):
            print(f"  {cls}: {count}")

        # Show sample instructions
        print("\nSample instructions:")
        for instr in self.instructions[:5]:
            print(f"  {instr.mnemonic}: {instr.brief}")
            print(f"    Encodings: {len(instr.encodings)}")
            if instr.encodings:
                print(f"    Example: {instr.encodings[0].asm_template}")

    def generate_cpp_files(self, include_dir: Path, lib_dir: Path):
        """Generate C++ header and implementation files for each instruction class."""
        # Group instructions by class
        by_class = {}
        for instr in self.instructions:
            cls = instr.instr_class or 'unknown'
            if cls not in by_class:
                by_class[cls] = []
            by_class[cls].append(instr)

        print(f"\n=== Generating Instruction Class Files ===")
        for cls, instrs in sorted(by_class.items()):
            header_file = include_dir / f"{cls}.hpp"
            cpp_file = lib_dir / f"{cls}.cpp"
            self._generate_class_files(cls, instrs, header_file, cpp_file)
            print(f"Generated {header_file.name} and {cpp_file.name} ({len(instrs)} instructions)")

    def generate_header_files(self, include_dir: Path, lib_dir: Path):
        """Generate base header files."""
        print(f"\n=== Generating Base Headers ===")

        # Create sub-header directory
        veda64_dir = include_dir / "veda64"
        veda64_dir.mkdir(exist_ok=True)

        # Generate sub-headers
        self._generate_util_header(veda64_dir / "util.hpp")
        self._generate_mnemonic_header(veda64_dir / "mnemonic.hpp")
        self._generate_types_header(veda64_dir / "types.hpp")
        self._generate_sysreg_header(veda64_dir / "sysreg.hpp")
        self._generate_pstate_header(veda64_dir / "pstate.hpp")
        self._generate_prefetch_header(veda64_dir / "prefetch.hpp")
        self._generate_barrier_header(veda64_dir / "barrier.hpp")
        self._generate_pattern_header(veda64_dir / "pattern.hpp")
        self._generate_sysop_header(veda64_dir / "sysop.hpp")
        self._generate_operand_header(veda64_dir / "operand.hpp")
        self._generate_instruction_subheader(veda64_dir / "instruction.hpp")
        self._generate_hook_header(veda64_dir / "hook.hpp")

        # Generate umbrella header
        self._generate_veda64_header(include_dir / "veda64.hpp")

        # Generate implementation
        veda64_impl = lib_dir / "veda64.cpp"
        self._generate_veda64_implementation(veda64_impl)
        self._generate_sysreg_implementation(lib_dir / "sysreg.cpp")
        self._generate_pstate_implementation(lib_dir / "pstate.cpp")
        self._generate_prefetch_implementation(lib_dir / "prefetch.cpp")
        self._generate_barrier_implementation(lib_dir / "barrier.cpp")
        self._generate_pattern_implementation(lib_dir / "pattern.cpp")
        self._generate_sysop_implementation(lib_dir / "sysop.cpp")
        print(f"Generated veda64/ sub-headers, veda64.hpp umbrella, veda64.cpp, and enum files")

    def generate_format_files(self, include_format_dir: Path, lib_format_dir: Path):
        """Generate format-based header and implementation files.

        This organizes code by ARM64 top-level decode groups as defined in
        encodingindex.xml from the ARM Architecture Reference Manual:

        | Group    | Description                                       |
        |----------|---------------------------------------------------|
        | reserved | Reserved                                          |
        | sme      | SME encodings                                     |
        | sve      | SVE encodings                                     |
        | dpimm    | Data Processing -- Immediate                      |
        | control  | Branches, Exception Generating and System          |
        | dpreg    | Data Processing -- Register                       |
        | simd_dp  | Data Processing -- Scalar FP and Advanced SIMD    |
        | ldst     | Loads and Stores                                  |

        Each group file contains:
        - Bitfield structs for each encoding
        - Encode functions for each instruction variant
        - A decode function with proper operand extraction
        """
        # Clean output directories of stale files before generating
        for d in (include_format_dir, lib_format_dir):
            for f in d.iterdir():
                if f.is_file():
                    f.unlink()

        # Group encodings by ARM64 decode group using psname from XML
        by_group = self._classify_by_arm64_decode_group()

        print(f"\n=== Generating ARM64 Decode Group Files ({len(by_group)} groups) ===")

        # Generate files for each group
        for group_name, data in sorted(by_group.items()):
            header_file = include_format_dir / f"{group_name}.hpp"
            cpp_file = lib_format_dir / f"{group_name}.cpp"
            self._generate_group_header(group_name, data, header_file)
            self._generate_group_impl(group_name, data, cpp_file)
            print(f"Generated {group_name}.hpp ({len(data['encodings'])} encodings)")

        # Generate unified format.hpp header
        format_header = include_format_dir / "format.hpp"
        self._generate_format_main_header_v2(by_group, format_header)
        print(f"Generated format.hpp")

    def _classify_by_arm64_decode_group(self) -> Dict:
        """Classify all instructions by ARM64 top-level decode group.

        Uses the format_group field extracted from each encoding's psname
        (e.g., A64.dpimm.addsub_imm.ADD_32_addsub_imm -> 'dpimm'),
        which directly corresponds to the top-level groupname attributes
        in encodingindex.xml.
        """
        groups = {
            'reserved': {'display_name': 'Reserved', 'encodings': []},
            'sme': {'display_name': 'SME Encodings', 'encodings': []},
            'sve': {'display_name': 'SVE Encodings', 'encodings': []},
            'dpimm': {'display_name': 'Data Processing -- Immediate', 'encodings': []},
            'control': {'display_name': 'Branches, Exception Generating and System', 'encodings': []},
            'dpreg': {'display_name': 'Data Processing -- Register', 'encodings': []},
            'simd_dp': {'display_name': 'Data Processing -- Scalar FP and Advanced SIMD', 'encodings': []},
            'ldst': {'display_name': 'Loads and Stores', 'encodings': []},
        }

        for instr in self.instructions:
            for encoding in instr.encodings:
                group_name = encoding.format_group
                if group_name not in groups:
                    # Fallback: use bit-pattern heuristic for encodings without psname
                    fixed_bits, fixed_mask = self._get_encoding_fixed_bits(encoding)
                    group_name = self._determine_decode_group(fixed_bits, fixed_mask)
                groups[group_name]['encodings'].append((instr, encoding))

        # Remove empty groups
        return {k: v for k, v in groups.items() if v['encodings']}

    def _get_encoding_fixed_bits(self, encoding: 'InstructionEncoding') -> tuple:
        """Extract fixed bits and mask from an encoding."""
        fixed_bits = 0
        fixed_mask = 0

        for field_name, field_info in encoding.fields.items():
            fixed = field_info.get('fixed')
            hibit = field_info.get('hibit')
            width = field_info.get('width', 1)

            if hibit is None:
                continue

            # Skip "should be" fields — don't include in match mask
            if field_info.get('should_be'):
                continue

            lobit = hibit - width + 1

            if fixed is not None and self._is_binary_string(fixed):
                fixed_val = int(fixed, 2)
                for i in range(width):
                    bit_pos = lobit + i
                    if bit_pos < 32:
                        fixed_mask |= (1 << bit_pos)
                        if (fixed_val >> i) & 1:
                            fixed_bits |= (1 << bit_pos)

        return fixed_bits, fixed_mask

    def _determine_decode_group(self, fixed_bits: int, fixed_mask: int) -> str:
        """Determine the ARM64 decode group from fixed bits (fallback heuristic).

        Only used when an encoding lacks psname/format_group information.
        Group names match encodingindex.xml top-level groupname attributes.
        """
        # op0 is bit 31, op1 is bits [28:25]
        op0_bit = 31
        op1_bits = [28, 27, 26, 25]

        # Check if op0 is known
        op0_known = (fixed_mask >> op0_bit) & 1
        op0 = (fixed_bits >> op0_bit) & 1 if op0_known else None

        # Build op1 with known/unknown bits
        op1_known_mask = 0
        op1_value = 0
        for i, bit in enumerate(reversed(op1_bits)):  # bit 25 is LSB
            if (fixed_mask >> bit) & 1:
                op1_known_mask |= (1 << i)
                if (fixed_bits >> bit) & 1:
                    op1_value |= (1 << i)

        # Match patterns (x = don't care)
        # op0=0, op1=0000 -> Reserved
        if op0 == 0 and op1_known_mask == 0xF and op1_value == 0b0000:
            return 'reserved'
        # op0=1, op1=0000 -> SME
        if op0 == 1 and op1_known_mask == 0xF and op1_value == 0b0000:
            return 'sme'
        # op1=0010 -> SVE
        if op1_known_mask == 0xF and op1_value == 0b0010:
            return 'sve'
        # op1=100x -> Data Processing -- Immediate (bits [28:26]=100, bit 25=x)
        if (op1_known_mask & 0b1110) == 0b1110 and (op1_value & 0b1110) == 0b1000:
            return 'dpimm'
        # op1=101x -> Branches, Exception Generating and System (bits [28:26]=101, bit 25=x)
        if (op1_known_mask & 0b1110) == 0b1110 and (op1_value & 0b1110) == 0b1010:
            return 'control'
        # op1=x101 -> Data Processing -- Register (bits [27:25]=101)
        if (op1_known_mask & 0b0111) == 0b0111 and (op1_value & 0b0111) == 0b0101:
            return 'dpreg'
        # op1=x111 -> Data Processing -- Scalar FP and SIMD (bits [27:25]=111)
        if (op1_known_mask & 0b0111) == 0b0111 and (op1_value & 0b0111) == 0b0111:
            return 'simd_dp'
        # op1=x1x0 -> Loads and Stores (bits [27]=1, [25]=0)
        if (op1_known_mask & 0b0101) == 0b0101 and (op1_value & 0b0101) == 0b0100:
            return 'ldst'

        # Default fallback
        return 'dpreg'

    def _generate_group_header(self, group_name: str, data: Dict, output_file: Path):
        """Generate header file for an ARM64 decode group."""
        code = self._license_header()
        display_name = data['display_name']
        encodings = data['encodings']

        # Build encoding info using the same pattern as class generation
        seen_encodings = set()
        encoding_info = []

        for instr, encoding in encodings:
            if encoding.name in seen_encodings:
                continue
            seen_encodings.add(encoding.name)

            struct_name = self._sanitize_struct_name(encoding.name)
            struct_code, field_list, fixed_bits, fixed_mask, full_pattern, full_mask = self._generate_encoding_struct(instr, encoding)

            mnemonic = encoding.docvars.get('mnemonic', instr.mnemonic)

            encoding_info.append({
                'struct_name': struct_name,
                'encoding_name': encoding.name,
                'field_list': field_list,
                'struct_code': struct_code,
                'fixed_bits': fixed_bits,
                'fixed_mask': fixed_mask,
                'full_pattern': full_pattern,
                'full_mask': full_mask,
                'mnemonic': mnemonic,
                'asm_template': encoding.asm_template,
                'symbol_map': encoding.symbol_map,
                'decode_ps': encoding.decode_ps
            })

        # Header
        code.append("#pragma once")
        code.append(f"// ARM64 Decode Group: {display_name}")
        code.append(f"// {len(encoding_info)} instruction encodings")
        code.append("")
        code.append("#include <cstdint>")
        code.append("#include <optional>")
        code.append("#include \"../veda64.hpp\"")
        code.append("")
        code.append("namespace veda64 {")
        code.append("namespace format {")
        code.append(f"namespace {self._group_namespace_name(group_name)} {{")
        code.append("")

        # Generate encode function declarations
        code.append("// Encode functions")
        for info in encoding_info:
            code.extend(self._generate_encode_declaration(
                info['struct_name'],
                info['encoding_name'],
                info['field_list']
            ))
        code.append("")

        # Generate decode function declaration
        code.append("// Decode function")
        code.extend(self._generate_decode_declaration(group_name))
        code.append("")

        code.append(f"}} // namespace {self._group_namespace_name(group_name)}")
        code.append("} // namespace format")
        code.append("} // namespace veda64")
        code.append("")

        self._write_file(output_file, code)

    def _generate_group_impl(self, group_name: str, data: Dict, output_file: Path):
        """Generate implementation file for an ARM64 decode group."""
        code = self._license_header()
        display_name = data['display_name']
        encodings = data['encodings']

        # Build encoding info
        seen_encodings = set()
        encoding_info = []

        for instr, encoding in encodings:
            if encoding.name in seen_encodings:
                continue
            seen_encodings.add(encoding.name)

            struct_name = self._sanitize_struct_name(encoding.name)
            struct_code, field_list, fixed_bits, fixed_mask, full_pattern, full_mask = self._generate_encoding_struct(instr, encoding)

            mnemonic = encoding.docvars.get('mnemonic', instr.mnemonic)

            encoding_info.append({
                'struct_name': struct_name,
                'encoding_name': encoding.name,
                'field_list': field_list,
                'struct_code': struct_code,
                'fixed_bits': fixed_bits,
                'fixed_mask': fixed_mask,
                'full_pattern': full_pattern,
                'full_mask': full_mask,
                'mnemonic': mnemonic,
                'asm_template': encoding.asm_template,
                'symbol_map': encoding.symbol_map,
                'decode_ps': encoding.decode_ps
            })

        # Include header
        code.append(f"#include \"format/{group_name}.hpp\"")
        code.append("")
        code.append("// Suppress MSVC warning for is_64bit declared but unused in some decode stubs")
        code.append("#ifdef _MSC_VER")
        code.append("#pragma warning(disable: 4189)")
        code.append("#endif")
        code.append("")
        code.append("namespace veda64 {")
        code.append("namespace format {")
        code.append(f"namespace {self._group_namespace_name(group_name)} {{")
        code.append("")

        # Generate encoding union (all structs share same union for decoding)
        code.append("// Encoding structures union")
        code.append(f"union {self._sanitize_struct_name(group_name)}Encoding {{")
        code.append("    uint32_t raw;")
        for info in encoding_info:
            code.extend(["    " + line for line in info['struct_code']])
            member_name = self._struct_to_member_name(info['struct_name'])
            code.append(f"    {info['struct_name']} {member_name};")
            code.append("")
        code.append("};")
        union_name = f"{self._sanitize_struct_name(group_name)}Encoding"
        code.append(f"static_assert(sizeof({union_name}) == 4, \"Encoding union must be 32 bits\");")
        code.append("")

        # Generate encode function implementations
        code.append("// Encode function implementations")
        for info in encoding_info:
            code.extend(self._generate_encode_implementation(
                group_name,
                info['struct_name'],
                info['encoding_name'],
                info['field_list']
            ))
            code.append("")

        # For the control group, inject the SYS alias lookup table before the decode function
        if group_name == 'control':
            sys_entries = self._build_sys_table()
            op_names = []
            op_name_idx = {}
            for (key, mnem, op_name, has_xt) in sys_entries:
                if op_name not in op_name_idx:
                    op_name_idx[op_name] = len(op_names)
                    op_names.append(op_name)
            code.append("#if !defined(VEDA64_NO_STRINGS) && !defined(VEDA64_NO_MNEMONIC_OPERANDS)")
            code.append("// SYS alias operation name string table")
            names_str = ', '.join(f'"{n.lower()}"' for n in op_names) if op_names else '"<unknown>"'
            code.append(f"static const char* sys_ops[] = {{{names_str}}};")
            code.append("")
            code.append("// SYS alias lookup table entry")
            code.append("struct SysTableEntry { uint16_t key; Mnemonic mnem; uint16_t op_idx; bool has_xt; };")
            code.append("static const SysTableEntry sys_table[] = {")
            for (key, mnem, op_name, has_xt) in sys_entries:
                idx = op_name_idx[op_name]
                xt_str = "true" if has_xt else "false"
                comment = f"// {mnem.lower()} {op_name.lower()}"
                code.append(f"    {{0x{key:04x}u, Mnemonic::{mnem}, {idx}u, {xt_str}}},  {comment}")
            code.append("};")
            code.append("static const size_t sys_table_size = sizeof(sys_table)/sizeof(sys_table[0]);")
            code.append("")
            code.append("static bool decode_sys_alias(uint32_t insn, Instruction& result) {")
            code.append("    uint32_t op1 = (insn >> 16) & 7;")
            code.append("    uint32_t CRn = (insn >> 12) & 0xF;")
            code.append("    uint32_t CRm = (insn >> 8) & 0xF;")
            code.append("    uint32_t op2 = (insn >> 5) & 7;")
            code.append("    uint32_t Rt  = insn & 0x1F;")
            code.append("    uint16_t key = static_cast<uint16_t>((op1 << 11) | (CRn << 7) | (CRm << 3) | op2);")
            code.append("    for (size_t i = 0; i < sys_table_size; i++) {")
            code.append("        if (sys_table[i].key == key) {")
            code.append("            result.mnemonic = sys_table[i].mnem;")
            code.append("            result.operands.push_back(Operand(OperandType::SysOp, sys_table[i].op_idx, false));")
            code.append("            result.operands.back().sysop = sysop_from_value(sys_table[i].op_idx);")
            code.append("            if (sys_table[i].has_xt)")
            code.append("                result.operands.push_back(Operand(OperandType::Register, Rt, true));")
            code.append("            return true;")
            code.append("        }")
            code.append("    }")
            code.append("    return false;")
            code.append("}")
            code.append("#endif  // !VEDA64_NO_STRINGS && !VEDA64_NO_MNEMONIC_OPERANDS")
            code.append("")

        # Generate decode function
        code.extend(self._generate_decode_function(group_name, encoding_info))
        code.append("")

        code.append(f"}} // namespace {self._group_namespace_name(group_name)}")
        code.append("} // namespace format")
        code.append("} // namespace veda64")
        code.append("")

        self._write_file(output_file, code)

    def _generate_format_main_header_v2(self, by_group: Dict, output_file: Path):
        """Generate main format.hpp header that includes all group headers."""
        code = self._license_header()

        code.append("#pragma once")
        code.append("// ARM64 Decode Group Headers")
        code.append("// Auto-generated from encodingindex.xml top-level decode groups")
        code.append("//")
        code.append("// Groups based on op0 (bit 31) and op1 (bits [28:25]):")
        code.append("// | op0 | op1  | Group                                          |")
        code.append("// |-----|------|------------------------------------------------|")
        code.append("// | 0   | 0000 | Reserved                                       |")
        code.append("// | 1   | 0000 | SME encodings                                  |")
        code.append("// | x   | 0010 | SVE encodings                                  |")
        code.append("// | x   | 100x | Data Processing -- Immediate                   |")
        code.append("// | x   | 101x | Branches, Exception Generating and System      |")
        code.append("// | x   | x101 | Data Processing -- Register                    |")
        code.append("// | x   | x111 | Data Processing -- Scalar FP and Advanced SIMD |")
        code.append("// | x   | x1x0 | Loads and Stores                               |")
        code.append("")

        # Include all group headers
        for group_name in sorted(by_group.keys()):
            code.append(f"#include \"format/{group_name}.hpp\"")
        code.append("")

        # Add unified decode function using switch/case on 5-bit key
        # key = (op0 << 4) | op1 where op0 = bit[31], op1 = bits[28:25]
        # All 32 values are enumerated for a compiler jump table.
        code.append("namespace veda64 {")
        code.append("")
        code.append("// Unified decode function that dispatches to appropriate group decoder")
        code.append("// Uses switch/case on 5-bit key = (op0 << 4) | op1 for jump table optimization")
        code.append("inline std::optional<Instruction> decode_format(uint32_t insn) {")
        code.append("    // Combine op0 (bit 31) and op1 (bits [28:25]) into 5-bit dispatch key")
        code.append("    uint32_t key = ((insn >> 27) & 0x10) | ((insn >> 25) & 0xF);")
        code.append("")
        code.append("    switch (key) {")

        # Build dispatch calls for each group, with fallback to nullopt
        def call(group):
            if group in by_group:
                return f"return format::{self._group_namespace_name(group)}::decode_{self._sanitize_function_name(group)}(insn);"
            return "return std::nullopt;"

        # key 0: op0=0, op1=0000 -> Reserved
        code.append("    case 0:  // op0=0, op1=0000: Reserved")
        code.append(f"        {call('reserved')}")
        # key 16: op0=1, op1=0000 -> SME
        code.append("    case 16: // op0=1, op1=0000: SME")
        code.append(f"        {call('sme')}")
        # keys 2,18: op1=0010 -> SVE
        code.append("    case 2:  // op0=0, op1=0010: SVE")
        code.append("    case 18: // op0=1, op1=0010: SVE")
        code.append(f"        {call('sve')}")
        # keys 8,9,24,25: op1=100x -> Dpimm
        code.append("    case 8:  // op0=0, op1=1000: Data Processing - Immediate")
        code.append("    case 9:  // op0=0, op1=1001")
        code.append("    case 24: // op0=1, op1=1000")
        code.append("    case 25: // op0=1, op1=1001")
        code.append(f"        {call('dpimm')}")
        # keys 10,11,26,27: op1=101x -> Control
        code.append("    case 10: // op0=0, op1=1010: Branches, Exception & System")
        code.append("    case 11: // op0=0, op1=1011")
        code.append("    case 26: // op0=1, op1=1010")
        code.append("    case 27: // op0=1, op1=1011")
        code.append(f"        {call('control')}")
        # keys 5,13,21,29: op1=x101 -> Dpreg
        code.append("    case 5:  // op0=0, op1=0101: Data Processing - Register")
        code.append("    case 13: // op0=0, op1=1101")
        code.append("    case 21: // op0=1, op1=0101")
        code.append("    case 29: // op0=1, op1=1101")
        code.append(f"        {call('dpreg')}")
        # keys 7,15,23,31: op1=x111 -> SimdDp
        code.append("    case 7:  // op0=0, op1=0111: Scalar FP & Advanced SIMD")
        code.append("    case 15: // op0=0, op1=1111")
        code.append("    case 23: // op0=1, op1=0111")
        code.append("    case 31: // op0=1, op1=1111")
        code.append(f"        {call('simd_dp')}")
        # keys 4,6,12,14,20,22,28,30: op1=x1x0 -> Ldst
        code.append("    case 4:  // op0=0, op1=0100: Loads and Stores")
        code.append("    case 6:  // op0=0, op1=0110")
        code.append("    case 12: // op0=0, op1=1100")
        code.append("    case 14: // op0=0, op1=1110")
        code.append("    case 20: // op0=1, op1=0100")
        code.append("    case 22: // op0=1, op1=0110")
        code.append("    case 28: // op0=1, op1=1100")
        code.append("    case 30: // op0=1, op1=1110")
        code.append(f"        {call('ldst')}")
        # default: unallocated (keys 1,3,17,19)
        code.append("    default: // Unallocated (op1=0001 or op1=0011)")
        code.append("        return std::nullopt;")

        code.append("    }")
        code.append("}")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")

        self._write_file(output_file, code)

    def _group_namespace_name(self, group_name: str) -> str:
        """Convert group name to valid C++ namespace name."""
        return group_name

    def _generate_instruction_header(self, output_file: Path):
        """Generate instruction.hpp with base Instruction class, enums, and Operand class."""
        code = self._license_header()

        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("#include <string>")
        code.append("#include <vector>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")

        # Generate Mnemonic enum
        code.append("// Mnemonic enumeration")
        code.append("enum class Mnemonic {")

        # Collect all unique mnemonics from both instruction-level and encoding-level docvars
        mnemonics = set()
        for instr in self.instructions:
            if instr.mnemonic:
                mnemonics.add(instr.mnemonic)
            # Also check encoding-level mnemonics
            for encoding in instr.encodings:
                encoding_mnemonic = encoding.docvars.get('mnemonic', '')
                if encoding_mnemonic:
                    mnemonics.add(encoding_mnemonic)

        # Add HINT aliases that are decoded at runtime (complete list from ARM64 XML)
        hint_aliases = ['NOP', 'YIELD', 'WFE', 'WFI', 'SEV', 'SEVL', 'DGH', 'XPACLRI',
                        'PACIA1716', 'PACIB1716', 'AUTIA1716', 'AUTIB1716',
                        'ESB', 'PSB', 'TSB', 'GCSB', 'CSDB', 'CLRBHB',
                        'PACIAZ', 'PACIASP', 'PACIBZ', 'PACIBSP',
                        'AUTIAZ', 'AUTIASP', 'AUTIBZ', 'AUTIBSP']
        mnemonics.update(hint_aliases)
        mnemonics.update(['TLBI', 'DC', 'AT', 'IC', 'GIC', 'BRB', 'CFP', 'CPP', 'DVP', 'APAS'])

        for mnem in sorted(mnemonics):
            code.append(f"    {mnem},")
        code.append("    UNKNOWN")
        code.append("};")
        code.append("")


        # Generate OperandType enum
        code.append("// Operand type enumeration")
        code.append("enum class OperandType {")
        code.append("    Register,           // General purpose register (Xn, Wn)")
        code.append("    VectorRegister,     // Vector/SIMD register (Vn, Qn, Dn, Sn, Hn, Bn)")
        code.append("    SVERegister,        // SVE scalable vector register (Zn)")
        code.append("    PredicateRegister,  // SVE predicate register (Pn)")
        code.append("    PredicateNRegister, // SVE predicate-as-counter register (PNn, pn8-pn15)")
        code.append("    SMETileRegister,    // SME tile register (ZAn)")
        code.append("    Immediate,          // Immediate value")
        code.append("    SignedImmediate,    // Signed immediate value")
        code.append("    MemoryBase,         // Memory operand [base]")
        code.append("    MemoryOffset,       // Memory operand [base, #offset]")
        code.append("    MemoryPreIndex,     // Memory operand [base, #offset]! (pre-index writeback)")
        code.append("    MemoryPostIndex,    // Memory operand [base], #offset (post-index writeback)")
        code.append("    MemoryRegOffset,    // Memory operand [base, Rm{, extend {#amount}}]")
        code.append("    Label,              // Branch target label/offset")
        code.append("    Relative,          // PC-relative offset for branches")
        code.append("    SystemRegister,     // System register")
        code.append("    Shift,              // Shift specifier (LSL, LSR, ASR, ROR)")
        code.append("    Extend,             // Extend specifier (UXTB, SXTW, etc.)")
        code.append("    Index,              // Element index")
        code.append("    Pattern,            // SVE pattern specifier")
        code.append("    SVEMulImm,          // SVE mul multiplier (MUL #N where N=imm4+1)")
        code.append("    Prefetch,           // Prefetch operation")
        code.append("    Barrier,            // Barrier option")
        code.append("    FloatImmediate,     // Floating-point immediate (#0.0, etc.)")
        code.append("    VectorRegisterList, // Vector register list { Vt.T, Vt+1.T, ... }")
        code.append("    SVERegisterList,    // SVE register list { Zt.T, Zt+1.T, ... }")
        code.append("    MemoryOffsetMulVL,  // SVE memory [base, #offset, mul vl]")
        code.append("    MemorySVEOffset,    // SVE gather memory [Zn.T, #offset]")
        code.append("    SMEZTRegister,      // SME ZT0 lookup table register")
        code.append("    PstateField,        // PSTATE field name for MSR/MRS immediate (SPSel, DAIFSet, etc.)")
        code.append("    FixedSym,           // Fixed symbolic operand (e.g. CSYNC, DSYNC)")
        code.append("    SysOp,              // SYS alias operation name (tlbi vmalle1 etc.)")
        code.append("    SVEVLxImm,          // SVE VL specifier (vlx2 or vlx4) for WHILE* pn_rr")
        code.append("    PredicateRegisterList, // Predicate register list { Pn.T, Pn+1.T, ... }")
        code.append("    Unknown")
        code.append("};")
        code.append("")

        # Generate Arrangement enum
        code.append("// Vector arrangement specifier")
        code.append("enum class Arrangement : uint8_t {")
        code.append("    None = 0,")
        code.append("    B, H, S, D, Q,           // Scalar element sizes")
        code.append("    B8, H4, S2, D1,           // 64-bit vector")
        code.append("    B16, H8, S4, D2,          // 128-bit vector")
        code.append("    Q1, B2, B4, H2,           // Special")
        code.append("};")
        code.append("")

        # Generate Operand class
        code.append("// Operand representation")
        code.append("class Operand {")
        code.append("public:")
        code.append("    Operand() = default;")
        code.append("")
        code.append("    // Constructor for simple operands (registers, immediates)")
        code.append("    Operand(OperandType t, uint32_t v, bool is_64 = true)")
        code.append("        : type(t), value(v), is_64bit(is_64) {}")
        code.append("")
        code.append("    // Constructor for memory operands")
        code.append("    Operand(OperandType t, uint32_t base, int32_t off, uint32_t idx_reg = 0, uint32_t ext = 0, uint32_t amt = 0)")
        code.append("        : type(t), base_reg(base), offset(off), index_reg(idx_reg), extend(ext), amount(amt) {}")
        code.append("")
        code.append("    // Static factory methods for memory operands")
        code.append("    static Operand memory_base(uint32_t base) {")
        code.append("        return Operand(OperandType::MemoryBase, base, 0);")
        code.append("    }")
        code.append("    static Operand memory_offset(uint32_t base, int32_t offset) {")
        code.append("        return Operand(OperandType::MemoryOffset, base, offset);")
        code.append("    }")
        code.append("    static Operand memory_pre_index(uint32_t base, int32_t offset) {")
        code.append("        return Operand(OperandType::MemoryPreIndex, base, offset);")
        code.append("    }")
        code.append("    static Operand memory_post_index(uint32_t base, int32_t offset) {")
        code.append("        return Operand(OperandType::MemoryPostIndex, base, offset);")
        code.append("    }")
        code.append("    static Operand memory_reg_offset(uint32_t base, uint32_t index, uint32_t extend = 0, uint32_t amount = 0) {")
        code.append("        return Operand(OperandType::MemoryRegOffset, base, 0, index, extend, amount);")
        code.append("    }")
        code.append("")
        code.append("    OperandType type = OperandType::Unknown;")
        code.append("    uint32_t value = 0;          // Raw field value for simple operands")
        code.append("    uint64_t imm64 = 0;          // 64-bit immediate value (for logical immediates)")
        code.append("    bool is_64bit = true;        // True for 64-bit registers (X), false for 32-bit (W)")
        code.append("    bool is_sp = false;          // True if reg 31 should be SP/WSP, false for XZR/WZR")
        code.append("    Arrangement arrangement = Arrangement::None;  // Vector arrangement specifier (.16b, .4s, etc.)")
        code.append("    uint32_t index = 0;           // Element index for indexed vector operands (v0.b[3])")
        code.append("    bool has_index = false;       // True if index field is valid")
        code.append("    bool prefer_decimal = false;  // True if immediate should always be formatted as decimal")
        code.append("")
        code.append("    // Memory operand fields")
        code.append("    uint32_t base_reg = 0;       // Base register number")
        code.append("    int32_t offset = 0;          // Signed offset")
        code.append("    uint32_t index_reg = 0;      // Index register for reg+reg addressing")
        code.append("    uint32_t extend = 0;         // Extend type for reg+reg addressing")
        code.append("    uint32_t amount = 0;         // Shift/extend amount")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("    // Format operand for disassembly")
        code.append("    std::string to_string() const;")
        code.append("    static const char* arrangement_to_string(Arrangement a);")
        code.append("")
        code.append("private:")
        code.append("    // Helper functions for formatting")
        code.append("    static std::string format_register(uint32_t reg, bool is_64bit, bool is_sp = false);")
        code.append("    static std::string format_vector_register(uint32_t reg, Arrangement arrangement);")
        code.append("    static Arrangement arr_from_size(uint32_t size);")
        code.append("    static Arrangement arr_narrow_from_size(uint32_t size);")
        code.append("    static Arrangement arr_wide_from_size(uint32_t size);")
        code.append("    static Arrangement vec_arr(uint32_t size, uint32_t q);")
        code.append("#endif")
        code.append("};")
        code.append("")

        # Generate helper function declaration
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("// Convert mnemonic enum to string")
        code.append("const char* mnemonic_to_string(Mnemonic mnem);")
        code.append("")
        code.append("// Determine vector arrangement for MOVI/MVNI based on Q and cmode fields")
        code.append("Arrangement get_movi_arrangement(uint32_t insn);")
        code.append("// Returns shift amount for MOVI/MVNI (0=none, >0=LSL, <0=MSL with abs value)")
        code.append("int get_movi_shift(uint32_t insn);")
        code.append("#endif")
        code.append("")

        # Generate Instruction class
        code.append("// Instruction representation")
        code.append("class Instruction {")
        code.append("public:")
        code.append("    Instruction() = default;")
        code.append("    Instruction(Mnemonic mnem, uint32_t raw)")
        code.append("        : mnemonic(mnem), raw_value(raw) {}")
        code.append("")
        code.append("    Mnemonic mnemonic = Mnemonic::UNKNOWN;")
        code.append("    uint32_t raw_value = 0;")
        code.append("    std::vector<Operand> operands;")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("    // Format as disassembled instruction")
        code.append("    std::string to_string() const;")
        code.append("#endif")
        code.append("};")
        code.append("")

        code.append("} // namespace veda64")
        code.append("")

        self._write_file(output_file, code)

    def _build_sys_table(self) -> list:
        """Parse ARM XML files to build SYS alias lookup table.
        Returns list of (key, mnem, op_name, has_xt) tuples.
        key = (op1<<11)|(CRn<<7)|(CRm<<3)|op2
        has_xt: True=always emit Rt, False=only emit if Rt!=31
        """
        import xml.etree.ElementTree as ET

        # Find the XML directory
        xml_dirs = sorted(p for p in Path('arm64').glob('ISA_A64_xml_A_profile-*') if p.is_dir())
        if not xml_dirs:
            return []
        xml_dir = xml_dirs[-1]  # Use latest

        entries = []

        def parse_binary(s):
            """Parse binary string, return int or None if has non-binary chars."""
            s = s.strip()
            if all(c in '01' for c in s) and s:
                return int(s, 2)
            return None

        def add_entry(op1, CRn, CRm, op2, mnem, op_name, has_xt):
            key = (op1 << 11) | (CRn << 7) | (CRm << 3) | op2
            entries.append((key, mnem, op_name.upper(), has_xt))

        def tlbi_has_xt(name):
            n = name.upper()
            # TLBI operations that take a VA/PA/ASID register operand
            return any(n.startswith(p) for p in ('VA', 'IPAS', 'ASIDE', 'RIPA'))

        # TLBI: 4-column table (op1, CRn, CRm, op2, name)
        tlbi_file = xml_dir / 'tlbi_sys.xml'
        if tlbi_file.exists():
            tree = ET.parse(str(tlbi_file))
            root = tree.getroot()
            for tbl in root.iter('table'):
                for row in tbl.iter('row'):
                    cells = [c.text or '' for c in row.findall('entry')]
                    if len(cells) >= 5:
                        op1 = parse_binary(cells[0])
                        CRn = parse_binary(cells[1])
                        CRm = parse_binary(cells[2])
                        op2 = parse_binary(cells[3])
                        name = cells[4].strip()
                        if op1 is not None and CRn is not None and CRm is not None and op2 is not None and name and not name.startswith('<'):
                            add_entry(op1, CRn, CRm, op2, 'TLBI', name, tlbi_has_xt(name))

        # DC: 3-column table (op1, CRm, op2, name), CRn=7 fixed
        dc_file = xml_dir / 'dc_sys.xml'
        if dc_file.exists():
            tree = ET.parse(str(dc_file))
            root = tree.getroot()
            for tbl in root.iter('table'):
                for row in tbl.iter('row'):
                    cells = [c.text or '' for c in row.findall('entry')]
                    if len(cells) >= 4:
                        op1 = parse_binary(cells[0])
                        CRm = parse_binary(cells[1])
                        op2 = parse_binary(cells[2])
                        name = cells[3].strip()
                        if op1 is not None and CRm is not None and op2 is not None and name and not name.startswith('<'):
                            add_entry(op1, 7, CRm, op2, 'DC', name, True)

        # AT: 3-column table (op1, CRm, op2, name), CRn=7 fixed
        at_file = xml_dir / 'at_sys.xml'
        if at_file.exists():
            tree = ET.parse(str(at_file))
            root = tree.getroot()
            for tbl in root.iter('table'):
                for row in tbl.iter('row'):
                    cells = [c.text or '' for c in row.findall('entry')]
                    if len(cells) >= 4:
                        op1 = parse_binary(cells[0])
                        CRm_s = cells[1].strip()
                        # CRm may have 'x' wildcard (AT uses 100x), take fixed prefix
                        CRm_clean = CRm_s.replace('x', '0')
                        CRm = parse_binary(CRm_clean)
                        op2 = parse_binary(cells[2])
                        name = cells[3].strip()
                        if op1 is not None and CRm is not None and op2 is not None and name and not name.startswith('<'):
                            add_entry(op1, 7, CRm, op2, 'AT', name, True)

        # IC: 3-column table (op1, CRm, op2, name), CRn=7 fixed
        ic_file = xml_dir / 'ic_sys.xml'
        if ic_file.exists():
            tree = ET.parse(str(ic_file))
            root = tree.getroot()
            for tbl in root.iter('table'):
                for row in tbl.iter('row'):
                    cells = [c.text or '' for c in row.findall('entry')]
                    if len(cells) >= 4:
                        op1 = parse_binary(cells[0])
                        CRm = parse_binary(cells[1])
                        op2 = parse_binary(cells[2])
                        name = cells[3].strip()
                        if op1 is not None and CRm is not None and op2 is not None and name and not name.startswith('<'):
                            # IVAU takes Xt (virtual address); IALLUIS/IALLU do not
                            add_entry(op1, 7, CRm, op2, 'IC', name, name.upper() == 'IVAU')

        # GIC: 3-column table (op1, CRm, op2, name), CRn=12 fixed
        gic_file = xml_dir / 'gic_sys.xml'
        if gic_file.exists():
            tree = ET.parse(str(gic_file))
            root = tree.getroot()
            for tbl in root.iter('table'):
                for row in tbl.iter('row'):
                    cells = [c.text or '' for c in row.findall('entry')]
                    if len(cells) >= 4:
                        op1 = parse_binary(cells[0])
                        CRm_s = cells[1].strip()
                        # CRm may be "IN {0001, 0010}" - skip non-simple
                        CRm = parse_binary(CRm_s)
                        op2 = parse_binary(cells[2])
                        name = cells[3].strip()
                        if op1 is not None and CRm is not None and op2 is not None and name and not name.startswith('<'):
                            add_entry(op1, 12, CRm, op2, 'GIC', name, False)

        # BRB: 1-column table (op2, name), op1=1 CRn=7 CRm=2 fixed
        brb_file = xml_dir / 'brb_sys.xml'
        if brb_file.exists():
            tree = ET.parse(str(brb_file))
            root = tree.getroot()
            for tbl in root.iter('table'):
                for row in tbl.iter('row'):
                    cells = [c.text or '' for c in row.findall('entry')]
                    if len(cells) >= 2:
                        op2 = parse_binary(cells[0])
                        name = cells[1].strip()
                        if op2 is not None and name and not name.startswith('<'):
                            add_entry(1, 7, 2, op2, 'BRB', name, False)

        # CFP/CPP/DVP: prediction restriction by context, all take Xt
        cfp_file = xml_dir / 'cfp_sys.xml'
        if cfp_file.exists():
            add_entry(3, 7, 3, 4, 'CFP', 'RCTX', True)
        cpp_file = xml_dir / 'cpp_sys.xml'
        if cpp_file.exists():
            add_entry(3, 7, 3, 7, 'CPP', 'RCTX', True)
        dvp_file = xml_dir / 'dvp_sys.xml'
        if dvp_file.exists():
            add_entry(3, 7, 3, 5, 'DVP', 'RCTX', True)

        # APAS: single encoding op1=6, CRn=7, CRm=0, op2=0
        apas_file = xml_dir / 'apas_sys.xml'
        if apas_file.exists():
            add_entry(6, 7, 0, 0, 'APAS', 'S2POC', True)

        return entries

    def _generate_veda64_implementation(self, output_file: Path):
        """Generate veda64.cpp with implementations."""
        code = self._license_header()

        code.append("#include \"veda64.hpp\"")
        code.append("#include \"format/format.hpp\"")
        code.append("#include <cstring>")
        code.append("#include <iomanip>")
        code.append("#include <sstream>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")

        # Collect all unique mnemonics (must match enum generation)
        mnemonics = set()
        for instr in self.instructions:
            if instr.mnemonic:
                mnemonics.add(instr.mnemonic)
            for encoding in instr.encodings:
                encoding_mnemonic = encoding.docvars.get('mnemonic', '')
                if encoding_mnemonic:
                    mnemonics.add(encoding_mnemonic)

        # Add HINT aliases that are decoded at runtime (complete list from ARM64 XML)
        hint_aliases = ['NOP', 'YIELD', 'WFE', 'WFI', 'SEV', 'SEVL', 'DGH', 'XPACLRI',
                        'PACIA1716', 'PACIB1716', 'AUTIA1716', 'AUTIB1716',
                        'ESB', 'PSB', 'TSB', 'GCSB', 'CSDB', 'CLRBHB',
                        'PACIAZ', 'PACIASP', 'PACIBZ', 'PACIBSP',
                        'AUTIAZ', 'AUTIASP', 'AUTIBZ', 'AUTIBSP']
        mnemonics.update(hint_aliases)
        mnemonics.update(['TLBI', 'DC', 'AT', 'IC', 'GIC', 'BRB', 'CFP', 'CPP', 'DVP', 'APAS'])

        sorted_mnemonics = sorted(mnemonics)

        # Generate mnemonic_to_string function (conditionally compiled)
        code.append("#if !defined(VEDA64_NO_STRINGS) && !defined(VEDA64_NO_MNEMONIC_OPERANDS)")
        code.append("// Convert mnemonic enum to string")
        code.append("const char* mnemonic_to_string(Mnemonic mnem) {")
        code.append("    switch (mnem) {")
        for mnem in sorted_mnemonics:
            code.append(f"        case Mnemonic::{mnem}: return \"{mnem.lower()}\";")
        code.append("        case Mnemonic::UNKNOWN: return \"<unknown>\";")
        code.append("        default: return \"<invalid>\";")
        code.append("    }")
        code.append("}")
        code.append("")

        # Generate SYS alias lookup table and decode helper
        sys_entries = self._build_sys_table()

        # Collect all unique op_names
        op_names = []
        op_name_idx = {}
        for (key, mnem, op_name, has_xt) in sys_entries:
            if op_name not in op_name_idx:
                op_name_idx[op_name] = len(op_names)
                op_names.append(op_name)

        # Only emit sys_ops[] here (used by Operand::to_string). The full table and
        # decode_sys_alias function are emitted in control.cpp where they are called.
        code.append("#if !defined(VEDA64_NO_STRINGS) && !defined(VEDA64_NO_MNEMONIC_OPERANDS)")
        code.append("// SYS alias operation name string table (used by Operand::to_string)")
        if op_names:
            names_str = ', '.join(f'"{n.lower()}"' for n in op_names)
        else:
            names_str = '"<unknown>"'  # fallback if XML not present
        code.append(f"static const char* sys_ops[] = {{{names_str}}};")
        code.append("#endif  // !VEDA64_NO_STRINGS && !VEDA64_NO_MNEMONIC_OPERANDS")
        code.append("")

        # Generate format_register helper (now in Operand class)
        code.append("// Format a general purpose register")
        code.append("std::string Operand::format_register(uint32_t reg, bool is_64bit, bool is_sp) {")
        code.append("    if (reg == 31) {")
        code.append("        if (is_sp) {")
        code.append("            return is_64bit ? \"sp\" : \"wsp\";")
        code.append("        } else {")
        code.append("            return is_64bit ? \"xzr\" : \"wzr\";")
        code.append("        }")
        code.append("    }")
        code.append("    // Note: x29/x30 shown as x29/x30, not fp/lr (ARM disassembly convention)")
        code.append("    char prefix = is_64bit ? 'x' : 'w';")
        code.append("    return std::string(1, prefix) + std::to_string(reg);")
        code.append("}")
        code.append("")

        # Generate format_vector_register helper (now in Operand class)
        code.append("// Format a vector register")
        code.append("std::string Operand::format_vector_register(uint32_t reg, Arrangement arrangement) {")
        code.append("    // Scalar prefixes: B→b, H→h, S→s, D→d, Q→q")
        code.append("    if (arrangement >= Arrangement::B && arrangement <= Arrangement::Q) {")
        code.append("        const char prefix[] = {0, 'b', 'h', 's', 'd', 'q'};")
        code.append("        return std::string(1, prefix[static_cast<int>(arrangement)]) + std::to_string(reg);")
        code.append("    }")
        code.append("    std::string result = \"v\" + std::to_string(reg);")
        code.append("    if (arrangement != Arrangement::None) {")
        code.append("        result += \".\";")
        code.append("        result += arrangement_to_string(arrangement);")
        code.append("    }")
        code.append("    return result;")
        code.append("}")
        code.append("")
        # Static helpers for arrangement enum
        code.append("Arrangement Operand::arr_from_size(uint32_t size) {")
        code.append("    static const Arrangement table[] = { Arrangement::B, Arrangement::H, Arrangement::S, Arrangement::D };")
        code.append("    return size < 4 ? table[size] : Arrangement::None;")
        code.append("}")
        code.append("")
        code.append("Arrangement Operand::arr_narrow_from_size(uint32_t size) {")
        code.append("    static const Arrangement table[] = { Arrangement::None, Arrangement::B, Arrangement::H, Arrangement::S };")
        code.append("    return size < 4 ? table[size] : Arrangement::None;")
        code.append("}")
        code.append("")
        code.append("Arrangement Operand::arr_wide_from_size(uint32_t size) {")
        code.append("    static const Arrangement table[] = { Arrangement::H, Arrangement::S, Arrangement::D };")
        code.append("    return size < 3 ? table[size] : Arrangement::None;")
        code.append("}")
        code.append("")
        code.append("Arrangement Operand::vec_arr(uint32_t size, uint32_t q) {")
        code.append("    static const Arrangement table[2][4] = {")
        code.append("        { Arrangement::B8, Arrangement::H4, Arrangement::S2, Arrangement::D1 },")
        code.append("        { Arrangement::B16, Arrangement::H8, Arrangement::S4, Arrangement::D2 }")
        code.append("    };")
        code.append("    return (size < 4 && q < 2) ? table[q][size] : Arrangement::None;")
        code.append("}")
        code.append("")
        code.append("const char* Operand::arrangement_to_string(Arrangement a) {")
        code.append("    switch (a) {")
        code.append("        case Arrangement::None: return \"\";")
        code.append("        case Arrangement::B: return \"b\";")
        code.append("        case Arrangement::H: return \"h\";")
        code.append("        case Arrangement::S: return \"s\";")
        code.append("        case Arrangement::D: return \"d\";")
        code.append("        case Arrangement::Q: return \"q\";")
        code.append("        case Arrangement::B8: return \"8b\";")
        code.append("        case Arrangement::H4: return \"4h\";")
        code.append("        case Arrangement::S2: return \"2s\";")
        code.append("        case Arrangement::D1: return \"1d\";")
        code.append("        case Arrangement::B16: return \"16b\";")
        code.append("        case Arrangement::H8: return \"8h\";")
        code.append("        case Arrangement::S4: return \"4s\";")
        code.append("        case Arrangement::D2: return \"2d\";")
        code.append("        case Arrangement::Q1: return \"1q\";")
        code.append("        case Arrangement::B2: return \"2b\";")
        code.append("        case Arrangement::B4: return \"4b\";")
        code.append("        case Arrangement::H2: return \"2h\";")
        code.append("        default: return \"\";")
        code.append("    }")
        code.append("}")
        code.append("")

        # Generate helper for MOVI/MVNI arrangement determination
        code.append("// Determine vector arrangement for MOVI/MVNI based on Q and cmode fields")
        code.append("Arrangement get_movi_arrangement(uint32_t insn) {")
        code.append("    uint32_t Q = (insn >> 30) & 1;")
        code.append("    uint32_t op = (insn >> 29) & 1;")
        code.append("    uint32_t cmode = (insn >> 12) & 0xF;")
        code.append("    ")
        code.append("    // 8-bit (cmode=1110, op=0 MOVI)")
        code.append("    if (op == 0 && cmode == 0xE) {")
        code.append("        return Q ? Arrangement::B16 : Arrangement::B8;")
        code.append("    }")
        code.append("    // 64-bit (cmode=1110, op=1 MOVI)")
        code.append("    if (op == 1 && cmode == 0xE) {")
        code.append("        return Q ? Arrangement::D2 : Arrangement::D;  // Scalar D register form")
        code.append("    }")
        code.append("    // 16-bit shifted (cmode=10x0) — MOVI op=0 and MVNI op=1")
        code.append("    if ((cmode & 0xD) == 0x8) {")
        code.append("        return Q ? Arrangement::H8 : Arrangement::H4;")
        code.append("    }")
        code.append("    // 32-bit shifted (cmode=0xx0) — MOVI op=0 and MVNI op=1")
        code.append("    if ((cmode & 0x9) == 0x0) {")
        code.append("        return Q ? Arrangement::S4 : Arrangement::S2;")
        code.append("    }")
        code.append("    // 32-bit shifting ones (cmode=110x) — MOVI op=0 and MVNI op=1")
        code.append("    if ((cmode & 0xE) == 0xC) {")
        code.append("        return Q ? Arrangement::S4 : Arrangement::S2;")
        code.append("    }")
        code.append("    // FP modified immediate (cmode=1111) — FMOV vector variants")
        code.append("    if (cmode == 0xF) {")
        code.append("        uint32_t o2 = (insn >> 11) & 1;")
        code.append("        if (o2 == 1) return Q ? Arrangement::H8 : Arrangement::H4;  // FP16 (.8h/.4h)")
        code.append("        if (op == 0) return Q ? Arrangement::S4 : Arrangement::S2;  // Single-precision (.4s/.2s)")
        code.append("        return Q ? Arrangement::D2 : Arrangement::D;  // Double-precision (.2d)")
        code.append("    }")
        code.append("    return Arrangement::None;")
        code.append("}")
        code.append("")
        # Generate get_movi_shift: returns shift amount for MOVI/MVNI based on cmode
        code.append("// Returns shift amount for MOVI/MVNI, or -1 if no shift / MSL encoding")
        code.append("int get_movi_shift(uint32_t insn) {")
        code.append("    uint32_t cmode = (insn >> 12) & 0xF;")
        code.append("    // 16-bit shifted (cmode=10x0): shift = cmode[1] * 8 — MOVI op=0 and MVNI op=1")
        code.append("    if ((cmode & 0xD) == 0x8) {")
        code.append("        return ((cmode >> 1) & 1) * 8;")
        code.append("    }")
        code.append("    // 32-bit shifted (cmode=0xx0): shift = cmode[2:1] * 8 — MOVI op=0 and MVNI op=1")
        code.append("    if ((cmode & 0x9) == 0x0) {")
        code.append("        return ((cmode >> 1) & 3) * 8;")
        code.append("    }")
        code.append("    // 32-bit shifting ones (cmode=110x): MSL — MOVI op=0 and MVNI op=1")
        code.append("    if ((cmode & 0xE) == 0xC) {")
        code.append("        return -((cmode & 1) ? 16 : 8);  // Negative = MSL")
        code.append("    }")
        code.append("    // 8-bit, 64-bit, FMOV: no shift")
        code.append("    return 0;")
        code.append("}")
        code.append("")

        # Generate condition_to_string function
        code.append("const char* condition_to_string(Condition cond) {")
        code.append("    static const char* names[] = {\"eq\", \"ne\", \"hs\", \"lo\", \"mi\", \"pl\", \"vs\", \"vc\",")
        code.append("                                   \"hi\", \"ls\", \"ge\", \"lt\", \"gt\", \"le\", \"al\", \"nv\"};")
        code.append("    auto idx = static_cast<int8_t>(cond);")
        code.append("    if (idx >= 0 && idx < 16) return names[idx];")
        code.append("    return nullptr;")
        code.append("}")
        code.append("")

        # Generate synthesize_alias function
        code.append("// Synthesize pseudo-instruction aliases")
        code.append("std::optional<std::string> synthesize_alias(const Instruction& insn) {")
        code.append("    // MOV Aliases: ADD/ORR with sp or Rn==Rm pattern")
        code.append("    if (insn.mnemonic == Mnemonic::ADD) {")
        code.append("        // MOV: 2-operand form (alias decoder emitted Rd, Rn with imm=0 implied)")
        code.append("        // Alias condition: Rd==31 || Rn==31 (one must be SP)")
        code.append("        if (insn.operands.size() == 2) {")
        code.append("            auto& op0 = insn.operands[0]; auto& op1 = insn.operands[1];")
        code.append("            if (op0.type == OperandType::Register && op1.type == OperandType::Register) {")
        code.append("                if (op0.value == 31 || op1.value == 31) {")
        code.append('                    return std::string("mov ") + op0.to_string() + ", " + op1.to_string();')
        code.append("                } else {")
        code.append("                    // ADD Xd, Xn, #0 with neither being SP: show as add Xd, Xn, #0")
        code.append('                    std::string r0 = op0.to_string(), r1 = op1.to_string();')
        code.append('                    return std::string("add ") + r0 + ", " + r1 + ", #0";')
        code.append("                }")
        code.append("            }")
        code.append("        }")
        code.append("        if (insn.operands.size() >= 3) {")
        code.append("        auto& op0 = insn.operands[0];")
        code.append("        auto& op1 = insn.operands[1];")
        code.append("        auto& op2 = insn.operands[2];")
        code.append("        if ((op0.value == 31 || op1.value == 31) &&")
        code.append("            op2.type == OperandType::Immediate && op2.value == 0) {")
        code.append('            return std::string("mov ") + op0.to_string() + ", " + op1.to_string();')
        code.append("        }")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    if (insn.mnemonic == Mnemonic::ORR && insn.operands.size() >= 2) {")
        code.append("        // MOV Rd, Rm = ORR Rd, XZR/WZR, Rm (no shift)")
        code.append("        if (insn.operands.size() == 2 && insn.operands[1].type == OperandType::Register) {")
        code.append("            // 2-operand form: MOV alias encoding (Rn=XZR is implicit)")
        code.append('            return std::string("mov ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string();')
        code.append("        }")
        code.append("        if (insn.operands.size() >= 3 && insn.operands[1].value == 31 && insn.operands[1].type == OperandType::Register) {")
        code.append("            bool no_shift = insn.operands.size() < 4 || insn.operands[3].type != OperandType::Shift || insn.operands[3].value == 0;")
        code.append("            if (no_shift) {")
        code.append('                return std::string("mov ") + insn.operands[0].to_string() + ", " + insn.operands[2].to_string();')
        code.append("            }")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // MOVZ/MOVN/MOVK with or without shifts -> MOV/MVN alias")
        code.append("    if (insn.mnemonic == Mnemonic::MOVZ && insn.operands.size() >= 2) {")
        code.append("        // hw = bits 22:21 of raw instruction; shift_amt = hw * 16")
        code.append("        uint32_t hw_val = (insn.raw_value >> 21) & 0x3;")
        code.append("        uint64_t imm_val = insn.operands[1].value;")
        code.append("        bool is_64z = insn.operands[0].is_64bit;")
        code.append("        uint64_t final_val = imm_val << (hw_val * 16);")
        code.append("        std::ostringstream oss;")
        code.append("        oss << \"mov \" << insn.operands[0].to_string() << \", #\";")
        code.append("        if (!is_64z && final_val >= 0x80000000ULL)")
        code.append("            oss << \"-0x\" << std::hex << (0x100000000ULL - final_val);")
        code.append("        else if (is_64z && final_val >= 0x8000000000000000ULL)")
        code.append("            oss << \"-0x\" << std::hex << (0ULL - final_val);")
        code.append("        else")
        code.append("            oss << \"0x\" << std::hex << final_val;")
        code.append("        return oss.str();")
        code.append("    }")
        code.append("")
        code.append("    if (insn.mnemonic == Mnemonic::MOVN && insn.operands.size() >= 2) {")
        code.append("        // hw = bits 22:21 of raw instruction; shift_amt = hw * 16")
        code.append("        uint32_t hw_val = (insn.raw_value >> 21) & 0x3;")
        code.append("        uint64_t imm_val = insn.operands[1].value;")
        code.append("        bool is_64n = insn.operands[0].is_64bit;")
        code.append("        uint64_t final_val = ~(imm_val << (hw_val * 16));")
        code.append("        if (!is_64n) final_val &= 0xFFFFFFFFULL;")
        code.append("        std::ostringstream oss;")
        code.append("        oss << \"mov \" << insn.operands[0].to_string() << \", #\";")
        code.append("        if (!is_64n && final_val >= 0x80000000ULL)")
        code.append("            oss << \"-0x\" << std::hex << (0x100000000ULL - final_val);")
        code.append("        else if (is_64n && final_val >= 0x8000000000000000ULL)")
        code.append("            oss << \"-0x\" << std::hex << (0ULL - final_val);")
        code.append("        else")
        code.append("            oss << \"0x\" << std::hex << final_val;")
        code.append("        return oss.str();")
        code.append("    }")
        code.append("")
        code.append("    // CMP/CMN/TST aliases: Rd (bits [4:0]) == 31 (XZR)")
        code.append("    // Use raw bits to detect - alias encodings may omit Rd from operands")
        code.append("    if (insn.mnemonic == Mnemonic::SUBS && (insn.raw_value & 0x1F) == 0x1F) {")
        code.append("        // CMP alias: skip Rd if present in operands")
        code.append("        size_t start = (insn.operands.size() >= 3 && insn.operands[0].type == OperandType::Register && insn.operands[0].value == 31) ? 1 : 0;")
        code.append('        std::string result = "cmp";')
        code.append("        for (size_t i = start; i < insn.operands.size(); ++i) {")
        code.append('            result += (i == start ? " " : ", ") + insn.operands[i].to_string();')
        code.append("        }")
        code.append("        return result;")
        code.append("    }")
        code.append("")
        code.append("    if (insn.mnemonic == Mnemonic::ADDS && (insn.raw_value & 0x1F) == 0x1F) {")
        code.append("        size_t start = (insn.operands.size() >= 3 && insn.operands[0].type == OperandType::Register && insn.operands[0].value == 31) ? 1 : 0;")
        code.append('        std::string result = "cmn";')
        code.append("        for (size_t i = start; i < insn.operands.size(); ++i) {")
        code.append('            result += (i == start ? " " : ", ") + insn.operands[i].to_string();')
        code.append("        }")
        code.append("        return result;")
        code.append("    }")
        code.append("")
        code.append("    if (insn.mnemonic == Mnemonic::ANDS && (insn.raw_value & 0x1F) == 0x1F) {")
        code.append("        size_t start = (insn.operands.size() >= 3 && insn.operands[0].type == OperandType::Register && insn.operands[0].value == 31) ? 1 : 0;")
        code.append('        std::string result = "tst";')
        code.append("        for (size_t i = start; i < insn.operands.size(); ++i) {")
        code.append('            result += (i == start ? " " : ", ") + insn.operands[i].to_string();')
        code.append("        }")
        code.append("        return result;")
        code.append("    }")
        code.append("")
        code.append("    // NEG Aliases: SUB/SUBS with Rn (bits [9:5]) == 31 (shifted register form only)")
        code.append("    // Shifted register: bit 28=0 (register form), bit 21=0 (not extended)")
        code.append("    // Extended register: bit 21=1, Rn=31 means SP not XZR — NOT a NEG")
        code.append("    if (insn.mnemonic == Mnemonic::SUB && ((insn.raw_value >> 5) & 0x1F) == 0x1F) {")
        code.append("        if ((insn.raw_value & (1u << 28)) == 0 && (insn.raw_value & (1u << 21)) == 0) {")
        code.append("            // Emit Rd, Rm (skip Rn which is xzr)")
        code.append("            size_t rd_idx = 0;")
        code.append("            size_t rm_idx = (insn.operands.size() >= 3 && insn.operands[1].type == OperandType::Register && insn.operands[1].value == 31) ? 2 : 1;")
        code.append('            std::string result = "neg " + insn.operands[rd_idx].to_string();')
        code.append("            for (size_t i = rm_idx; i < insn.operands.size(); ++i) {")
        code.append('                result += ", " + insn.operands[i].to_string();')
        code.append("            }")
        code.append("            return result;")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    if (insn.mnemonic == Mnemonic::SUBS && ((insn.raw_value >> 5) & 0x1F) == 0x1F && (insn.raw_value & 0x1F) != 0x1F) {")
        code.append("        if ((insn.raw_value & (1u << 28)) == 0 && (insn.raw_value & (1u << 21)) == 0) {")
        code.append("            size_t rd_idx = 0;")
        code.append("            size_t rm_idx = (insn.operands.size() >= 3 && insn.operands[1].type == OperandType::Register && insn.operands[1].value == 31) ? 2 : 1;")
        code.append('            std::string result = "negs " + insn.operands[rd_idx].to_string();')
        code.append("            for (size_t i = rm_idx; i < insn.operands.size(); ++i) {")
        code.append('                result += ", " + insn.operands[i].to_string();')
        code.append("            }")
        code.append("            return result;")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // MUL Aliases: MADD/MSUB with Ra==31 (4 operands) or alias encoding (3 operands)")
        code.append("    if (insn.mnemonic == Mnemonic::MADD) {")
        code.append("        if (insn.operands.size() == 3 || (insn.operands.size() >= 4 && insn.operands[3].value == 31)) {")
        code.append('            return std::string("mul ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();')
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    if (insn.mnemonic == Mnemonic::MSUB) {")
        code.append("        if (insn.operands.size() == 3 || (insn.operands.size() >= 4 && insn.operands[3].value == 31)) {")
        code.append('            return std::string("mneg ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();')
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // SMULL/UMULL/SMNEGL/UMNEGL Aliases")
        code.append("    if (insn.mnemonic == Mnemonic::SMADDL) {")
        code.append("        if (insn.operands.size() == 3 || (insn.operands.size() >= 4 && insn.operands[3].value == 31)) {")
        code.append('            return std::string("smull ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();')
        code.append("        }")
        code.append("    }")
        code.append("    if (insn.mnemonic == Mnemonic::UMADDL) {")
        code.append("        if (insn.operands.size() == 3 || (insn.operands.size() >= 4 && insn.operands[3].value == 31)) {")
        code.append('            return std::string("umull ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();')
        code.append("        }")
        code.append("    }")
        code.append("    if (insn.mnemonic == Mnemonic::SMSUBL) {")
        code.append("        if (insn.operands.size() == 3 || (insn.operands.size() >= 4 && insn.operands[3].value == 31)) {")
        code.append('            return std::string("smnegl ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();')
        code.append("        }")
        code.append("    }")
        code.append("    if (insn.mnemonic == Mnemonic::UMSUBL) {")
        code.append("        if (insn.operands.size() == 3 || (insn.operands.size() >= 4 && insn.operands[3].value == 31)) {")
        code.append('            return std::string("umnegl ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();')
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // ROR Aliases: EXTR with Rn==Rm (ROR is EXTR with both operands same)")
        code.append("    if (insn.mnemonic == Mnemonic::EXTR && insn.operands.size() >= 4) {")
        code.append("        if (insn.operands[1].value == insn.operands[2].value) {")
        code.append('            return std::string("ror ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[3].to_string();')
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // RORV -> ROR alias (variable rotate is just called ROR in disassembly)")
        code.append("    if (insn.mnemonic == Mnemonic::RORV && insn.operands.size() >= 3) {")
        code.append('        return std::string("ror ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();')
        code.append("    }")
        code.append("")
        code.append("    // LSLV/LSRV/ASRV -> LSL/LSR/ASR aliases (variable shift is just called LSL/LSR/ASR)")
        code.append("    if (insn.mnemonic == Mnemonic::LSLV && insn.operands.size() >= 3) {")
        code.append('        return std::string("lsl ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();')
        code.append("    }")
        code.append("    if (insn.mnemonic == Mnemonic::LSRV && insn.operands.size() >= 3) {")
        code.append('        return std::string("lsr ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();')
        code.append("    }")
        code.append("    if (insn.mnemonic == Mnemonic::ASRV && insn.operands.size() >= 3) {")
        code.append('        return std::string("asr ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();')
        code.append("    }")
        code.append("")
        code.append("    // UBFM/SBFM/BFM aliases: Extract immr/imms from raw bits since specific")
        code.append("    // alias encodings (LSR_UBFM, ASR_SBFM etc.) have imms as fixed field")
        code.append("    if (insn.mnemonic == Mnemonic::UBFM && insn.operands.size() >= 2) {")
        code.append("        uint32_t immr = (insn.raw_value >> 16) & 0x3F;")
        code.append("        uint32_t imms = (insn.raw_value >> 10) & 0x3F;")
        code.append("        bool is_64 = insn.operands[0].is_64bit;")
        code.append("        uint32_t regsize = is_64 ? 64 : 32;")
        code.append("        auto& rd = insn.operands[0];")
        code.append("        auto& rn = insn.operands[1];")
        code.append("        if (!is_64 && immr == 0 && imms == 7) {")
        code.append('            return std::string("uxtb ") + rd.to_string() + ", " + rn.to_string();')
        code.append("        }")
        code.append("        if (!is_64 && immr == 0 && imms == 15) {")
        code.append('            return std::string("uxth ") + rd.to_string() + ", " + rn.to_string();')
        code.append("        }")
        code.append("        if (imms == regsize - 1) {")
        code.append('            return std::string("lsr ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(immr);')
        code.append("        }")
        code.append("        if (imms + 1 == immr) {")
        code.append("            uint32_t shift = regsize - immr;")
        code.append('            return std::string("lsl ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(shift);')
        code.append("        }")
        code.append("        if (imms >= immr) {")
        code.append("            uint32_t width = imms - immr + 1;")
        code.append('            return std::string("ubfx ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(immr) + ", #" + std::to_string(width);')
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    if (insn.mnemonic == Mnemonic::SBFM && insn.operands.size() >= 2) {")
        code.append("        uint32_t immr = (insn.raw_value >> 16) & 0x3F;")
        code.append("        uint32_t imms = (insn.raw_value >> 10) & 0x3F;")
        code.append("        bool is_64 = insn.operands[0].is_64bit;")
        code.append("        uint32_t regsize = is_64 ? 64 : 32;")
        code.append("        auto& rd = insn.operands[0];")
        code.append("        auto& rn = insn.operands[1];")
        code.append("        // SXT aliases: source register is always W-form (sign-extending from smaller type)")
        code.append('        std::string rn_w = rn.value == 31 ? "wzr" : "w" + std::to_string(rn.value);')
        code.append("        if (immr == 0 && imms == 7) {")
        code.append('            return std::string("sxtb ") + rd.to_string() + ", " + rn_w;')
        code.append("        }")
        code.append("        if (immr == 0 && imms == 15) {")
        code.append('            return std::string("sxth ") + rd.to_string() + ", " + rn_w;')
        code.append("        }")
        code.append("        if (is_64 && immr == 0 && imms == 31) {")
        code.append('            return std::string("sxtw ") + rd.to_string() + ", " + rn_w;')
        code.append("        }")
        code.append("        if (imms == regsize - 1) {")
        code.append('            return std::string("asr ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(immr);')
        code.append("        }")
        code.append("        if (imms >= immr) {")
        code.append("            uint32_t width = imms - immr + 1;")
        code.append('            return std::string("sbfx ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(immr) + ", #" + std::to_string(width);')
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    if (insn.mnemonic == Mnemonic::BFM && insn.operands.size() >= 2) {")
        code.append("        uint32_t immr = (insn.raw_value >> 16) & 0x3F;")
        code.append("        uint32_t imms = (insn.raw_value >> 10) & 0x3F;")
        code.append("        bool is_64 = insn.operands[0].is_64bit;")
        code.append("        uint32_t regsize = is_64 ? 64 : 32;")
        code.append("        auto& rd = insn.operands[0];")
        code.append("        auto& rn = insn.operands[1];")
        code.append("        if (imms < immr) {")
        code.append("            uint32_t lsb = (regsize - immr) & (regsize - 1);")
        code.append("            uint32_t width = imms + 1;")
        code.append('            return std::string("bfi ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(lsb) + ", #" + std::to_string(width);')
        code.append("        } else {")
        code.append("            uint32_t width = imms - immr + 1;")
        code.append('            return std::string("bfxil ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(immr) + ", #" + std::to_string(width);')
        code.append("        }")
        code.append("    }")
        code.append("")
        # CSINC aliases: CSET (Rn=Rm=31), CINC (Rn==Rm)
        code.append("    // CSINC aliases: CSET (Rn=Rm=31), CINC (Rn==Rm)")
        code.append("    if (insn.mnemonic == Mnemonic::CSINC && insn.condition != Condition::None) {")
        code.append("        int cond_val = static_cast<int>(insn.condition);")
        code.append("        if ((cond_val & 0xE) != 0xE) {  // Not AL/NV")
        code.append("            const char* inv_cond = condition_to_string(static_cast<Condition>(cond_val ^ 1));")
        code.append("            // CSET: Rn=Rm=31 implied (1-operand form from alias-specific decoder)")
        code.append("            if (insn.operands.size() == 1) {")
        code.append('                return std::string("cset ") + insn.operands[0].to_string() + ", " + inv_cond;')
        code.append("            }")
        code.append("            // 2-operand form: Rm from raw instruction, check Rn==Rm for CINC")
        code.append("            if (insn.operands.size() == 2) {")
        code.append("                uint32_t raw_rn = (insn.raw_value >> 5) & 0x1F;")
        code.append("                uint32_t raw_rm = (insn.raw_value >> 16) & 0x1F;")
        code.append("                bool is_64 = insn.operands[1].is_64bit;")
        code.append("                if (raw_rn == raw_rm) {")
        code.append('                    return std::string("cinc ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + inv_cond;')
        code.append("                } else {")
        code.append("                    // Rn!=Rm: full CSINC form, reconstruct Rm operand from raw")
        code.append("                    Operand rm_op(OperandType::Register, raw_rm, is_64);")
        code.append('                    return std::string("csinc ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + rm_op.to_string() + ", " + condition_to_string(insn.condition);')
        code.append("                }")
        code.append("            }")
        code.append("            if (insn.operands.size() >= 3) {")
        code.append("                auto& rn = insn.operands[1];")
        code.append("                auto& rm = insn.operands[2];")
        code.append("                if (rn.value == 31 && rm.value == 31) {")
        code.append('                    return std::string("cset ") + insn.operands[0].to_string() + ", " + inv_cond;')
        code.append("                }")
        code.append("                if (rn.value == rm.value) {")
        code.append('                    return std::string("cinc ") + insn.operands[0].to_string() + ", " + rn.to_string() + ", " + inv_cond;')
        code.append("                }")
        code.append("            }")
        code.append("        }")
        code.append("    }")
        code.append("")

        # CSINV aliases: CSETM (Rn=Rm=31), CINV (Rn==Rm)
        code.append("    // CSINV aliases: CSETM (Rn=Rm=31), CINV (Rn==Rm)")
        code.append("    if (insn.mnemonic == Mnemonic::CSINV && insn.condition != Condition::None) {")
        code.append("        int cond_val = static_cast<int>(insn.condition);")
        code.append("        if ((cond_val & 0xE) != 0xE) {  // Not AL/NV")
        code.append("            const char* inv_cond = condition_to_string(static_cast<Condition>(cond_val ^ 1));")
        code.append("            // CSETM: Rn=Rm=31 implied (1-operand form from alias-specific decoder)")
        code.append("            if (insn.operands.size() == 1) {")
        code.append('                return std::string("csetm ") + insn.operands[0].to_string() + ", " + inv_cond;')
        code.append("            }")
        code.append("            // 2-operand form: check Rn==Rm from raw for CINV")
        code.append("            if (insn.operands.size() == 2) {")
        code.append("                uint32_t raw_rn = (insn.raw_value >> 5) & 0x1F;")
        code.append("                uint32_t raw_rm = (insn.raw_value >> 16) & 0x1F;")
        code.append("                bool is_64 = insn.operands[1].is_64bit;")
        code.append("                if (raw_rn == raw_rm) {")
        code.append('                    return std::string("cinv ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + inv_cond;')
        code.append("                } else {")
        code.append("                    Operand rm_op(OperandType::Register, raw_rm, is_64);")
        code.append('                    return std::string("csinv ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + rm_op.to_string() + ", " + condition_to_string(insn.condition);')
        code.append("                }")
        code.append("            }")
        code.append("            if (insn.operands.size() >= 3) {")
        code.append("                auto& rn = insn.operands[1];")
        code.append("                auto& rm = insn.operands[2];")
        code.append("                if (rn.value == 31 && rm.value == 31) {")
        code.append('                    return std::string("csetm ") + insn.operands[0].to_string() + ", " + inv_cond;')
        code.append("                }")
        code.append("                if (rn.value == rm.value) {")
        code.append('                    return std::string("cinv ") + insn.operands[0].to_string() + ", " + rn.to_string() + ", " + inv_cond;')
        code.append("                }")
        code.append("            }")
        code.append("        }")
        code.append("    }")
        code.append("")

        # CSNEG alias: CNEG (Rn==Rm)
        code.append("    // CSNEG alias: CNEG (Rn==Rm)")
        code.append("    if (insn.mnemonic == Mnemonic::CSNEG && insn.condition != Condition::None) {")
        code.append("        int cond_val = static_cast<int>(insn.condition);")
        code.append("        if ((cond_val & 0xE) != 0xE) {  // Not AL/NV")
        code.append("            const char* inv_cond = condition_to_string(static_cast<Condition>(cond_val ^ 1));")
        code.append("            // 2-operand form: check Rn==Rm from raw for CNEG")
        code.append("            if (insn.operands.size() == 2) {")
        code.append("                uint32_t raw_rn = (insn.raw_value >> 5) & 0x1F;")
        code.append("                uint32_t raw_rm = (insn.raw_value >> 16) & 0x1F;")
        code.append("                bool is_64 = insn.operands[1].is_64bit;")
        code.append("                if (raw_rn == raw_rm) {")
        code.append('                    return std::string("cneg ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + inv_cond;')
        code.append("                } else {")
        code.append("                    Operand rm_op(OperandType::Register, raw_rm, is_64);")
        code.append('                    return std::string("csneg ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + rm_op.to_string() + ", " + condition_to_string(insn.condition);')
        code.append("                }")
        code.append("            }")
        code.append("            if (insn.operands.size() >= 3) {")
        code.append("            auto& rn = insn.operands[1];")
        code.append("            auto& rm = insn.operands[2];")
        code.append("            if (rn.value == rm.value) {")
        code.append('                return std::string("cneg ") + insn.operands[0].to_string() + ", " + rn.to_string() + ", " + inv_cond;')
        code.append("            }")
        code.append("            }")
        code.append("        }")
        code.append("    }")
        code.append("")

        # MOVA → MOV alias: decode raw instruction for proper ZA tile slice format
        code.append("    // MOVA → MOV: ZA tile slice operand format")
        code.append("    if (insn.mnemonic == Mnemonic::MOVA) {")
        code.append("        uint32_t raw = insn.raw_value;")
        code.append("        // Detect mov_za_p_rz variants (vector to/from ZA tile with predicate)")
        code.append("        // These have top byte 0xC0 and bit 20=0, bits [19:16]=0")
        code.append("        if ((raw & 0xFF200000u) == 0xC0000000u && ((raw >> 16) & 0xF) == 0) {")
        code.append("            uint32_t size = (raw >> 22) & 3;")
        code.append("            bool is_q = ((raw >> 16) & 1) != 0;  // Q bit for .Q variant")
        code.append("            uint32_t V = (raw >> 15) & 1;")
        code.append("            uint32_t Rs = (raw >> 13) & 3;")
        code.append("            uint32_t Pg = (raw >> 10) & 7;")
        code.append("            uint32_t Zn = (raw >> 5) & 0x1F;")
        code.append("            std::ostringstream oss;")
        code.append("            oss << \"mov \";")
        code.append("            // ZA tile operand: za<tile><hv>.<sz>[w<12+Rs>, <offset>]")
        code.append("            const char* hv = V ? \"v\" : \"h\";")
        code.append("            const char* sz_name;")
        code.append("            uint32_t tile, offset;")
        code.append("            if (size == 0 && !is_q) {")
        code.append("                // .B: ZAd is always 0, offset is 4 bits [3:0]")
        code.append("                sz_name = \"b\"; tile = 0; offset = raw & 0xF;")
        code.append("            } else if (size == 1) {")
        code.append("                // .H: ZAd is 1 bit [3], offset is 3 bits [2:0]")
        code.append("                sz_name = \"h\"; tile = (raw >> 3) & 1; offset = raw & 7;")
        code.append("            } else if (size == 2) {")
        code.append("                // .S: ZAd is 2 bits [3:2], offset is 2 bits [1:0]")
        code.append("                sz_name = \"s\"; tile = (raw >> 2) & 3; offset = raw & 3;")
        code.append("            } else if (size == 3 && !is_q) {")
        code.append("                // .D: ZAd is 3 bits [3:1], offset is 1 bit [0]")
        code.append("                sz_name = \"d\"; tile = (raw >> 1) & 7; offset = raw & 1;")
        code.append("            } else {")
        code.append("                // .Q: ZAd is 4 bits [3:0], no offset")
        code.append("                sz_name = \"q\"; tile = raw & 0xF; offset = 0;")
        code.append("            }")
        code.append("            oss << \"za\" << tile << hv << \".\" << sz_name;")
        code.append("            oss << \"[w\" << (12 + Rs) << \", \";")
        code.append("            if (offset >= 10) oss << \"0x\" << std::hex << offset;")
        code.append("            else oss << std::dec << offset;")
        code.append("            oss << \"], p\" << std::dec << Pg << \"/m, z\" << Zn << \".\" << sz_name;")
        code.append("            return oss.str();")
        code.append("        }")
        code.append("        // Detect mov_z_p_rza variants (ZA tile slice → Z vector): bit17=1, bits[21:18]=0")
        code.append("        if ((raw & 0xFF3E0000u) == 0xC0020000u) {")
        code.append("            uint32_t size = (raw >> 22) & 3;")
        code.append("            bool is_q = ((raw >> 16) & 1) != 0;")
        code.append("            uint32_t V = (raw >> 15) & 1;")
        code.append("            uint32_t Rs = (raw >> 13) & 3;")
        code.append("            uint32_t Pg = (raw >> 10) & 7;")
        code.append("            uint32_t Zd = raw & 0x1F;")
        code.append("            std::ostringstream oss;")
        code.append("            oss << \"mov \";")
        code.append("            const char* hv = V ? \"v\" : \"h\";")
        code.append("            const char* sz_name;")
        code.append("            uint32_t tile, offset;")
        code.append("            // tile/offset encoded in bits[8:5] of the instruction")
        code.append("            if (size == 0 && !is_q) {")
        code.append("                sz_name = \"b\"; tile = 0; offset = (raw >> 5) & 0xF;")
        code.append("            } else if (size == 1 && !is_q) {")
        code.append("                sz_name = \"h\"; tile = (raw >> 8) & 1; offset = (raw >> 5) & 7;")
        code.append("            } else if (size == 2 && !is_q) {")
        code.append("                sz_name = \"s\"; tile = (raw >> 7) & 3; offset = (raw >> 5) & 3;")
        code.append("            } else if (size == 3 && !is_q) {")
        code.append("                sz_name = \"d\"; tile = (raw >> 6) & 7; offset = (raw >> 5) & 1;")
        code.append("            } else {")
        code.append("                sz_name = \"q\"; tile = (raw >> 5) & 0xF; offset = 0;")
        code.append("            }")
        code.append("            oss << \"z\" << Zd << \".\" << sz_name;")
        code.append("            oss << \", p\" << std::dec << Pg << \"/m, \";")
        code.append("            oss << \"za\" << tile << hv << \".\" << sz_name;")
        code.append("            oss << \"[w\" << (12 + Rs) << \", \";")
        code.append("            if (offset >= 10) oss << \"0x\" << std::hex << offset;")
        code.append("            else oss << std::dec << offset;")
        code.append("            oss << \"]\";")
        code.append("            return oss.str();")
        code.append("        }")
        code.append("    }")
        code.append("")
        # DSB CRm=0 → SSBB, CRm=4 → PSSBB
        code.append("    // DSB CRm=0 → SSBB, CRm=4 → PSSBB")
        code.append("    if (insn.mnemonic == Mnemonic::DSB) {")
        code.append("        // Fixed-CRm encodings (no operands): check raw instruction bits")
        code.append("        uint32_t crm = (insn.raw_value >> 8) & 0xF;")
        code.append('        if (crm == 0) return std::string("ssbb");')
        code.append('        if (crm == 4) return std::string("pssbb");')
        code.append("    }")
        code.append("")
        # SVE CPY → MOV alias (CPY with /Z or /M predicate → MOV)
        code.append("    // SVE: CPY → MOV alias")
        code.append("    if (insn.mnemonic == Mnemonic::CPY && insn.operands.size() >= 3) {")
        code.append("        std::ostringstream oss;")
        code.append('        oss << "mov";')
        code.append("        for (size_t i = 0; i < insn.operands.size(); ++i) {")
        code.append('            oss << (i == 0 ? " " : ", ") << insn.operands[i].to_string();')
        code.append("        }")
        code.append("        return oss.str();")
        code.append("    }")
        code.append("")
        # SVE AND Pd, Pg/Z, Pn, Pm with Pn==Pm → MOV Pd, Pg/Z, Pn
        code.append("    // SVE: AND p,p/z,p,p with Pn==Pm → MOV p,p/z,p")
        code.append("    if (insn.mnemonic == Mnemonic::AND && insn.operands.size() == 4) {")
        code.append("        auto& op2 = insn.operands[2]; auto& op3 = insn.operands[3];")
        code.append("        if (op2.type == OperandType::PredicateRegister && op3.type == OperandType::PredicateRegister && op2.value == op3.value) {")
        code.append("            std::ostringstream oss;")
        code.append('            oss << "mov " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string() << ", " << op2.to_string();')
        code.append("            return oss.str();")
        code.append("        }")
        code.append("    }")
        code.append("")
        # SVE EOR Pd, Pg/Z, Pn, Pm with Pm==Pg → NOT Pd, Pg/Z, Pn
        code.append("    // SVE: EOR p,p/z,p,p with Pm==Pg → NOT p,p/z,p")
        code.append("    if (insn.mnemonic == Mnemonic::EOR && insn.operands.size() == 4) {")
        code.append("        auto& op1 = insn.operands[1]; auto& op3 = insn.operands[3];")
        code.append("        if (op1.type == OperandType::PredicateRegister && op3.type == OperandType::PredicateRegister && op1.value == op3.value) {")
        code.append("            std::ostringstream oss;")
        code.append('            oss << "not " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string() << ", " << insn.operands[2].to_string();')
        code.append("            return oss.str();")
        code.append("        }")
        code.append("    }")
        code.append("")
        # SVE ANDS → MOVS alias (same as AND → MOV but with S suffix)
        code.append("    // SVE: ANDS p,p/z,p,p with Pn==Pm → MOVS p,p/z,p")
        code.append("    if (insn.mnemonic == Mnemonic::ANDS && insn.operands.size() == 4) {")
        code.append("        auto& op2 = insn.operands[2]; auto& op3 = insn.operands[3];")
        code.append("        if (op2.type == OperandType::PredicateRegister && op3.type == OperandType::PredicateRegister && op2.value == op3.value) {")
        code.append("            std::ostringstream oss;")
        code.append('            oss << "movs " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string() << ", " << op2.to_string();')
        code.append("            return oss.str();")
        code.append("        }")
        code.append("    }")
        code.append("")
        # SVE EORS Pd, Pg/Z, Pn, Pm with Pm==Pg → NOTS Pd, Pg/Z, Pn
        code.append("    // SVE: EORS p,p/z,p,p with Pm==Pg → NOTS p,p/z,p")
        code.append("    if (insn.mnemonic == Mnemonic::EORS && insn.operands.size() == 4) {")
        code.append("        auto& op1 = insn.operands[1]; auto& op3 = insn.operands[3];")
        code.append("        if (op1.type == OperandType::PredicateRegister && op3.type == OperandType::PredicateRegister && op1.value == op3.value) {")
        code.append("            std::ostringstream oss;")
        code.append('            oss << "nots " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string() << ", " << insn.operands[2].to_string();')
        code.append("            return oss.str();")
        code.append("        }")
        code.append("    }")
        code.append("")
        # SVE DUP → MOV alias (all DUP Z forms)
        code.append("    // SVE: DUP → MOV alias")
        code.append("    if (insn.mnemonic == Mnemonic::DUP && insn.operands.size() >= 1 && insn.operands[0].type == OperandType::SVERegister) {")
        code.append("        std::ostringstream oss;")
        code.append('        oss << "mov";')
        code.append("        for (size_t i = 0; i < insn.operands.size(); ++i) {")
        code.append('            oss << (i == 0 ? " " : ", ") << insn.operands[i].to_string();')
        code.append("        }")
        code.append("        return oss.str();")
        code.append("    }")
        code.append("")
        # SVE SEL Pd, Pg/M, Pn, Pm → MOV Pd, Pg/M, Pn (predicate form)
        code.append("    // SVE: SEL p → MOV p (predicate form)")
        code.append("    if (insn.mnemonic == Mnemonic::SEL && insn.operands.size() >= 3 && insn.operands[0].type == OperandType::PredicateRegister) {")
        code.append("        std::ostringstream oss;")
        code.append('        oss << "mov " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string() << ", " << insn.operands[2].to_string();')
        code.append("        return oss.str();")
        code.append("    }")
        code.append("")
        # SVE SEL Zd, Pg/M, Zn, Zm → MOV Zd, Pg/M, Zn (vector form)
        code.append("    // SVE: SEL z → MOV z (vector form)")
        code.append("    if (insn.mnemonic == Mnemonic::SEL && insn.operands.size() >= 3 && insn.operands[0].type == OperandType::SVERegister) {")
        code.append("        std::ostringstream oss;")
        code.append('        oss << "mov " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string() << ", " << insn.operands[2].to_string();')
        code.append("        return oss.str();")
        code.append("    }")
        code.append("")
        # SVE ORR Zd, Zn, Zm with Zn==Zm → MOV Zd, Zn
        code.append("    // SVE: ORR z,z,z with Zn==Zm → MOV z,z")
        code.append("    if (insn.mnemonic == Mnemonic::ORR && insn.operands.size() == 3 && insn.operands[0].type == OperandType::SVERegister) {")
        code.append("        auto& op1 = insn.operands[1]; auto& op2 = insn.operands[2];")
        code.append("        if (op1.type == OperandType::SVERegister && op2.type == OperandType::SVERegister && op1.value == op2.value) {")
        code.append("            std::ostringstream oss;")
        code.append('            oss << "mov " << insn.operands[0].to_string() << ", " << op1.to_string();')
        code.append("            return oss.str();")
        code.append("        }")
        code.append("    }")
        code.append("")
        # SVE ORR Pd, Pg/Z, Pn, Pm with Pn==Pm → MOV Pd, Pg/Z, Pn (predicate form)
        code.append("    // SVE: ORR p,p/z,p,p with Pn==Pm → MOV p,p/z,p")
        code.append("    if (insn.mnemonic == Mnemonic::ORR && insn.operands.size() == 4 && insn.operands[0].type == OperandType::PredicateRegister) {")
        code.append("        auto& op1 = insn.operands[1]; auto& op2 = insn.operands[2]; auto& op3 = insn.operands[3];")
        code.append("        if (op2.type == OperandType::PredicateRegister && op3.type == OperandType::PredicateRegister && op2.value == op3.value) {")
        code.append("            std::ostringstream oss;")
        code.append("            if (op1.value == op2.value)")
        code.append('                oss << "mov " << insn.operands[0].to_string() << ", " << op1.to_string();')
        code.append("            else")
        code.append('                oss << "mov " << insn.operands[0].to_string() << ", " << op1.to_string() << ", " << op2.to_string();')
        code.append("            return oss.str();")
        code.append("        }")
        code.append("    }")
        code.append("")
        # SVE ORRS Pd, Pg/Z, Pn, Pm with Pn==Pm → MOVS Pd, Pg/Z, Pn
        code.append("    // SVE: ORRS p,p/z,p,p with Pn==Pm → MOVS p,p/z,p")
        code.append("    if (insn.mnemonic == Mnemonic::ORRS && insn.operands.size() == 4) {")
        code.append("        auto& op1 = insn.operands[1]; auto& op2 = insn.operands[2]; auto& op3 = insn.operands[3];")
        code.append("        if (op2.type == OperandType::PredicateRegister && op3.type == OperandType::PredicateRegister && op2.value == op3.value) {")
        code.append("            std::ostringstream oss;")
        code.append("            if (op1.value == op2.value)")
        code.append('                oss << "movs " << insn.operands[0].to_string() << ", " << op1.to_string();')
        code.append("            else")
        code.append('                oss << "movs " << insn.operands[0].to_string() << ", " << op1.to_string() << ", " << op2.to_string();')
        code.append("            return oss.str();")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // NOT (SIMD vector) → MVN alias")
        code.append("    if (insn.mnemonic == Mnemonic::NOT && !insn.operands.empty() && insn.operands[0].type == OperandType::VectorRegister) {")
        code.append("        std::ostringstream oss;")
        code.append('        oss << "mvn";')
        code.append('        for (size_t i = 0; i < insn.operands.size(); ++i) { oss << (i == 0 ? " " : ", ") << insn.operands[i].to_string(); }')
        code.append("        return oss.str();")
        code.append("    }")
        code.append("")
        code.append("    return std::nullopt;  // No alias")
        code.append("}")
        code.append("")

        # Generate Instruction::to_string - with alias synthesis
        code.append("// Format instruction as disassembly")
        code.append("std::string Instruction::to_string() const {")
        code.append("    // Try to synthesize a pseudo-instruction alias")
        code.append("    auto alias = synthesize_alias(*this);")
        code.append("    if (alias) {")
        code.append("        return *alias;")
        code.append("    }")
        code.append("")
        code.append("    // Fall back to base mnemonic")
        code.append("    std::string result = mnemonic_to_string(mnemonic);")
        code.append("")
        code.append("    // SIMD long/wide instructions: Q=1 → add '2' suffix (PMULL→PMULL2, SMLAL→SMLAL2, etc.)")
        code.append("    // Only for SIMD (bit31=0); SME2 instructions have bit31=1 and must not get this suffix")
        code.append("    // Also exclude scalar forms (asisdmisc) which have bit30=1 as fixed but no Q field")
        code.append("    // Check: first operand must have a multi-element arrangement (not scalar B/H/S/D/Q)")
        code.append("    bool _has_vector_arr = !operands.empty() && operands[0].type == OperandType::VectorRegister &&")
        code.append("        operands[0].arrangement != Arrangement::B && operands[0].arrangement != Arrangement::H &&")
        code.append("        operands[0].arrangement != Arrangement::S && operands[0].arrangement != Arrangement::D &&")
        code.append("        operands[0].arrangement != Arrangement::Q && operands[0].arrangement != Arrangement::None;")
        code.append("    if (_has_vector_arr && !(raw_value >> 31) && ((raw_value >> 30) & 1)) {  // Q bit, non-SME only")
        code.append("        if (mnemonic == Mnemonic::PMULL || mnemonic == Mnemonic::SMLAL || mnemonic == Mnemonic::SMLSL ||")
        code.append("            mnemonic == Mnemonic::UMLAL || mnemonic == Mnemonic::UMLSL || mnemonic == Mnemonic::SMULL ||")
        code.append("            mnemonic == Mnemonic::UMULL || mnemonic == Mnemonic::SQDMLAL || mnemonic == Mnemonic::SQDMLSL ||")
        code.append("            mnemonic == Mnemonic::SQDMULL || mnemonic == Mnemonic::SABAL || mnemonic == Mnemonic::UABAL ||")
        code.append("            mnemonic == Mnemonic::SABDL || mnemonic == Mnemonic::UABDL || mnemonic == Mnemonic::SADDL ||")
        code.append("            mnemonic == Mnemonic::UADDL || mnemonic == Mnemonic::SSUBL || mnemonic == Mnemonic::USUBL ||")
        code.append("            mnemonic == Mnemonic::SSHLL || mnemonic == Mnemonic::USHLL ||")
        code.append("            mnemonic == Mnemonic::ADDHN || mnemonic == Mnemonic::SUBHN ||")
        code.append("            mnemonic == Mnemonic::RADDHN || mnemonic == Mnemonic::RSUBHN ||")
        code.append("            mnemonic == Mnemonic::FCVTXN ||")
        code.append("            mnemonic == Mnemonic::XTN || mnemonic == Mnemonic::SQXTN ||")
        code.append("            mnemonic == Mnemonic::UQXTN || mnemonic == Mnemonic::SQXTUN) {")
        code.append('            result += "2";')
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // For B/BC: condition is a suffix on the mnemonic (e.g., b.eq)")
        code.append("    if (condition != Condition::None &&")
        code.append("        (mnemonic == Mnemonic::B || mnemonic == Mnemonic::BC)) {")
        code.append("        const char* cond_str = condition_to_string(condition);")
        code.append("        if (cond_str) {")
        code.append('            result += ".";')
        code.append("            result += cond_str;")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    if (!operands.empty()) {")
        code.append("        result += \" \";")
        code.append("        for (size_t i = 0; i < operands.size(); ++i) {")
        code.append("            if (i > 0) result += \", \";")
        code.append("            result += operands[i].to_string();")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // For other instructions: condition at the end (e.g., ccmp w0, w0, #0, ne)")
        code.append("    if (condition != Condition::None &&")
        code.append("        mnemonic != Mnemonic::B && mnemonic != Mnemonic::BC) {")
        code.append("        const char* cond_str = condition_to_string(condition);")
        code.append("        if (cond_str) {")
        code.append('            if (!operands.empty()) result += ", ";')
        code.append('            else result += " ";')
        code.append("            result += cond_str;")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    return result;")
        code.append("}")
        code.append("")

        # Generate Operand::to_string - contains ALL formatting logic
        code.append("// Format operand for disassembly")
        code.append("std::string Operand::to_string() const {")
        code.append("    switch (type) {")
        code.append("        case OperandType::Register: {")
        code.append("            return format_register(value, is_64bit, is_sp);")
        code.append("        }")
        code.append("        ")
        code.append("        case OperandType::Immediate:")
        code.append("            {")
        code.append("                std::ostringstream oss;")
        code.append("                // Use imm64 for 64-bit logical immediates")
        code.append("                uint64_t display_val = imm64 ? imm64 : static_cast<uint64_t>(value);")
        code.append("                if (prefer_decimal || display_val <= 9) {")
        code.append("                    oss << \"#\" << std::dec << display_val;")
        code.append("                } else {")
        code.append("                    oss << \"#0x\" << std::hex << display_val;")
        code.append("                }")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::SignedImmediate:")
        code.append("            {")
        code.append("                std::ostringstream oss;")
        code.append("                int32_t sval = static_cast<int32_t>(value);")
        code.append("                if (sval < 0) {")
        code.append("                    if (sval >= -9) {")
        code.append("                        oss << \"#\" << std::dec << sval;")
        code.append("                    } else {")
        code.append("                        oss << \"#-0x\" << std::hex << (-sval);")
        code.append("                    }")
        code.append("                } else {")
        code.append("                    if (sval <= 9) {")
        code.append("                        oss << \"#\" << std::dec << sval;")
        code.append("                    } else {")
        code.append("                        oss << \"#0x\" << std::hex << sval;")
        code.append("                    }")
        code.append("                }")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::VectorRegister:")
        code.append("            // is_64bit used to select Q prefix for 128-bit context (STP/LDP Q)")
        code.append("            if (is_64bit) return \"q\" + std::to_string(value);")
        code.append("            {")
        code.append("                if (has_index && arrangement != Arrangement::None) {")
        code.append("                    // Indexed element: always use v<n>.<T>[<idx>] format")
        code.append("                    std::string _idx_s;")
        code.append("                    if (index >= 10) { std::ostringstream _oss; _oss << \"0x\" << std::hex << index; _idx_s = _oss.str(); }")
        code.append("                    else _idx_s = std::to_string(index);")
        code.append("                    return \"v\" + std::to_string(value) + \".\" + arrangement_to_string(arrangement) + \"[\" + _idx_s + \"]\";")
        code.append("                } else if (has_index) {")
        code.append("                    // Indexed without arrangement (LUTI4 Vm[idx])")
        code.append("                    return \"v\" + std::to_string(value) + \"[\" + std::to_string(index) + \"]\";")
        code.append("                }")
        code.append("                std::string vr = format_vector_register(value, arrangement);")
        code.append("                return vr;")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::SVERegister: {")
        code.append("            std::string r = \"z\" + std::to_string(value);")
        code.append("            if (arrangement != Arrangement::None) {")
        code.append("                r += \".\";")
        code.append("                r += Operand::arrangement_to_string(arrangement);")
        code.append("            }")
        code.append("            if (has_index) {")
        code.append("                if (index >= 10) { std::ostringstream _oss; _oss << \"[0x\" << std::hex << index << \"]\"; r += _oss.str(); }")
        code.append("                else r += \"[\" + std::to_string(index) + \"]\";")
        code.append("            }")
        code.append("            return r;")
        code.append("        }")
        code.append("        ")
        code.append("        case OperandType::PredicateRegister: {")
        code.append("            std::string r = \"p\" + std::to_string(value);")
        code.append("            if (arrangement != Arrangement::None) {")
        code.append("                r += \".\";")
        code.append("                r += Operand::arrangement_to_string(arrangement);")
        code.append("            }")
        code.append("            // is_sp is reused for predicate qualifier: 0=none, 1=/z, 2=/m")
        code.append("            if (is_sp) {")
        code.append("                r += is_64bit ? \"/m\" : \"/z\";")
        code.append("            }")
        code.append("            // has_index: PSEL Pm compound index [wN, imm]")
        code.append("            if (has_index) r += \"[w\" + std::to_string(index_reg) + \", \" + std::to_string(index) + \"]\";")
        code.append("            return r;")
        code.append("        }")
        code.append("        ")
        code.extend("""\
        case OperandType::SMETileRegister:
            // extend==2: VGx mode: za.T[wN, offs{, vgxN}]
            if (has_index && extend == 2) {
                std::string r = "za";
                if (arrangement != Arrangement::None) { r += "."; r += Operand::arrangement_to_string(arrangement); }
                r += "[w" + std::to_string(index) + ", " + std::to_string(amount);
                int32_t vgx = (int32_t)offset;
                if (vgx > 1) r += ", vgx" + std::to_string(vgx);
                r += "]";
                return r;
            }
            // extend==1 or 3: ZA accumulator range za.T[wN, start:end{, vgxN}]
            if (has_index && (extend == 1 || extend == 3)) {
                std::string r = "za";
                if (arrangement != Arrangement::None) { r += "."; r += Operand::arrangement_to_string(arrangement); }
                r += "[w" + std::to_string(index) + ", ";
                if (amount >= 10) { std::ostringstream oss; oss << "0x" << std::hex << amount; r += oss.str(); }
                else r += std::to_string(amount);
                r += ":";
                uint32_t range_end = (uint32_t)(offset & 0xFFFF);
                if (range_end >= 10) { std::ostringstream oss; oss << "0x" << std::hex << range_end; r += oss.str(); }
                else r += std::to_string(range_end);
                if (extend == 3) { int32_t vgx = (offset >> 16) & 0xFFFF; if (vgx > 1) r += ", vgx" + std::to_string(vgx); }
                r += "]";
                return r;
            }
            // extend==5: LDR/STR ZA: za[wN, offs] (no tile number, no H/V)
            if (has_index && extend == 5) {
                std::string r = "za[w" + std::to_string(index) + ", " + std::to_string(amount) + "]";
                return r;
            }
            // extend==4: MOVA-style za tile with H/V + range: zaTILEh/v.T[wN, start:end]
            if (has_index && extend == 4) {
                std::string r = "za" + std::to_string(value);
                r += is_sp ? "v" : "h";
                if (arrangement != Arrangement::None) { r += "."; r += Operand::arrangement_to_string(arrangement); }
                r += "[w" + std::to_string(index) + ", ";
                r += std::to_string(amount);
                uint32_t range_end = (uint32_t)(offset & 0xFFFF);
                if (range_end != amount) { r += ":"; r += std::to_string(range_end); }
                r += "]";
                return r;
            }
            // has_index=true: ZA tile slice {zaXv/h.T[wN, offs]} (no spaces inside braces)
            if (has_index) {
                std::string r = "{za" + std::to_string(value);
                r += is_sp ? "v" : "h";
                if (arrangement != Arrangement::None) { r += "."; r += Operand::arrangement_to_string(arrangement); }
                r += "[w" + std::to_string(index) + ", ";
                if (amount >= 10) { std::ostringstream oss; oss << "0x" << std::hex << amount; r += oss.str(); }
                else r += std::to_string(amount);
                r += "]}";
                return r;
            }
            {
                std::string r = "za" + std::to_string(value);
                if (arrangement != Arrangement::None) { r += "."; r += Operand::arrangement_to_string(arrangement); }
                return r;
            }""".split('\n'))
        code.append("        ")
        code.append("        case OperandType::PredicateNRegister: {")
        code.append("            std::string r = \"pn\";")
        code.append("            if (value >= 10) { std::ostringstream oss; oss << \"0x\" << std::hex << value; r += oss.str(); }")
        code.append("            else r += std::to_string(value);")
        code.append("            if (arrangement != Arrangement::None) { r += \".\"; r += Operand::arrangement_to_string(arrangement); }")
        code.append("            if (has_index) r += \"[\" + std::to_string(index) + \"]\";")
        code.append("            if (is_sp) { r += is_64bit ? \"/m\" : \"/z\"; }")
        code.append("            return r;")
        code.append("        }")
        code.append("        ")
        code.append("        case OperandType::SMEZTRegister:")
        code.append("            if (has_index) return \"zt0[\" + std::to_string(index) + \"]\";")
        code.append("            return \"zt0\";")
        code.append("        ")
        code.append("        case OperandType::PstateField:")
        code.append("            {")
        code.append("                const char* s = pstate_to_string(pstate);")
        code.append("                if (s) return s;")
        code.append("                return \"#\" + std::to_string(value);")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::FixedSym:")
        code.append("            {")
        code.append("                static const char* fixed_syms[] = {\"csync\", \"dsync\"};")
        code.append("                if (value < 2) return fixed_syms[value];")
        code.append("                return \"?\";")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::SysOp:")
        code.append("            {")
        code.append("                const char* s = sysop_to_string(sysop);")
        code.append("                if (s) return s;")
        code.append("                return sys_ops[value];")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::MemoryBase:")
        code.append("            // [Xn|SP]")
        code.append("            return \"[\" + format_register(base_reg, true, true) + \"]\";")
        code.append("        ")
        code.append("        case OperandType::MemoryOffset:")
        code.append("            // [Xn|SP, #offset]")
        code.append("            if (offset == 0) {")
        code.append("                return \"[\" + format_register(base_reg, true, true) + \"]\";")
        code.append("            }")
        code.append("            {")
        code.append("                std::ostringstream oss;")
        code.append("                oss << \"[\" << format_register(base_reg, true, true) << \", #\";")
        code.append("                if (offset < 0) {")
        code.append("                    if (offset >= -15) oss << std::dec << offset;")
        code.append("                    else oss << \"-0x\" << std::hex << (-offset);")
        code.append("                } else {")
        code.append("                    if (offset <= 15) oss << std::dec << offset;")
        code.append("                    else oss << \"0x\" << std::hex << offset;")
        code.append("                }")
        code.append("                oss << \"]\";")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::MemoryPreIndex:")
        code.append("            // [Xn|SP, #offset]!")
        code.append("            {")
        code.append("                std::ostringstream oss;")
        code.append("                oss << \"[\" << format_register(base_reg, true, true) << \", #\";")
        code.append("                if (offset < 0) {")
        code.append("                    if (offset >= -15) oss << std::dec << offset;")
        code.append("                    else oss << \"-0x\" << std::hex << (-offset);")
        code.append("                } else {")
        code.append("                    if (offset <= 15) oss << std::dec << offset;")
        code.append("                    else oss << \"0x\" << std::hex << offset;")
        code.append("                }")
        code.append("                oss << \"]!\";")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::MemoryPostIndex:")
        code.append("            // [Xn|SP], #offset")
        code.append("            {")
        code.append("                std::ostringstream oss;")
        code.append("                oss << \"[\" << format_register(base_reg, true, true) << \"], #\";")
        code.append("                if (offset < 0) {")
        code.append("                    if (offset >= -15) oss << std::dec << offset;")
        code.append("                    else oss << \"-0x\" << std::hex << (-offset);")
        code.append("                } else {")
        code.append("                    if (offset <= 15) oss << std::dec << offset;")
        code.append("                    else oss << \"0x\" << std::hex << offset;")
        code.append("                }")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::MemoryRegOffset:")
        code.append("            // [Xn|SP, Rm{, extend {#amount}}] or [Xn|SP, Zm.T{, lsl #N}]")
        code.append("            {")
        code.append("                std::string result = \"[\" + format_register(base_reg, true, true) + \", \";")
        code.append("                if (arrangement != Arrangement::None) {")
        code.append("                    // SVE Z register index: [Xn, Zm.T{, mod #N}]")
        code.append("                    result += \"z\" + std::to_string(index_reg) + \".\" + Operand::arrangement_to_string(arrangement);")
        code.append("                    const char* sve_extends[] = {\"uxtb\", \"uxth\", \"uxtw\", \"lsl\",")
        code.append("                                                  \"sxtb\", \"sxth\", \"sxtw\", \"sxtx\"};")
        code.append("                    if (extend < 8 && extend != 0) {")
        code.append("                        result += std::string(\", \") + sve_extends[extend];")
        code.append("                        if (amount > 0) result += \" #\" + std::to_string(amount);")
        code.append("                    } else if (amount > 0) {")
        code.append("                        result += \", lsl #\" + std::to_string(amount);")
        code.append("                    }")
        code.append("                } else {")
        code.append("                    // Index register: W for UXTW(2)/SXTW(6), X for UXTX(3)/SXTX(7)/LSL")
        code.append("                    bool index_is_32 = (extend == 2 || extend == 6);")
        code.append("                    result += format_register(index_reg, !index_is_32, false);")
        code.append("                    // extend=3 (UXTX) is equivalent to LSL for 64-bit index")
        code.append("                    // Suppress extend=3 with amount=0 (it's the default)")
        code.append("                    if (extend == 3 && amount == 0) {")
        code.append("                        // Default: no extend/shift needed")
        code.append("                    } else if (extend != 0 || amount != 0) {")
        code.append("                        const char* extends[] = {\"uxtb\", \"uxth\", \"uxtw\", \"lsl\", ")
        code.append("                                                 \"sxtb\", \"sxth\", \"sxtw\", \"sxtx\"};")
        code.append("                        if (extend < 8) {")
        code.append("                            result += \", \" + std::string(extends[extend]);")
        code.append("                            if (amount != 0) {")
        code.append("                                result += \" #\" + std::to_string(amount);")
        code.append("                            }")
        code.append("                        }")
        code.append("                    }")
        code.append("                }")
        code.append("                result += \"]\";")
        code.append("                return result;")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::SystemRegister:")
        code.append("            {")
        code.append("                if (sysreg != SystemRegister::UNKNOWN) {")
        code.append("                    return sysreg_to_string(sysreg);")
        code.append("                }")
        code.append("                // Fallback: decode from raw value for backward compat")
        code.append("                uint32_t o0 = (value >> 14) & 1;")
        code.append("                uint32_t op1 = (value >> 11) & 7;")
        code.append("                uint32_t crn = (value >> 7) & 0xF;")
        code.append("                uint32_t crm = (value >> 3) & 0xF;")
        code.append("                uint32_t op2v = value & 7;")
        code.append("                // Try lookup from encoding")
        code.append("                SystemRegister sr = sysreg_from_encoding(2 + o0, op1, crn, crm, op2v);")
        code.append("                if (sr != SystemRegister::UNKNOWN) {")
        code.append("                    return sysreg_to_string(sr);")
        code.append("                }")
        code.append("                // Final fallback: S<op0>_<op1>_C<CRn>_C<CRm>_<op2>")
        code.append("                std::ostringstream oss;")
        code.append("                oss << \"s\" << (2 + o0) << \"_\" << op1 << \"_c\" << crn << \"_c\" << crm << \"_\" << op2v;")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::Shift:")
        code.append("            {")
        code.append("                // value encodes shift_type in bits [9:8] and amount in bits [7:0]")
        code.append("                const char* shifts[] = {\"lsl\", \"lsr\", \"asr\", \"ror\", \"msl\"};")
        code.append("                uint32_t shift_type = (value >> 8) & 0x7;")
        code.append("                if (shift_type > 4) shift_type = 0;  // safety")
        code.append("                uint32_t shift_amount = value & 0xFF;")
        code.append("                std::ostringstream oss;")
        code.append("                oss << shifts[shift_type] << \" #\";")
        code.append("                if (shift_amount <= 15) oss << std::dec << shift_amount;")
        code.append("                else oss << \"0x\" << std::hex << shift_amount;")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::Extend:")
        code.append("            {")
        code.append("                // Combined format: option in bits [2:0], amount in bits [10:8]")
        code.append("                // Legacy format (value < 8): option only, amount=0")
        code.append("                uint32_t ext_type = value & 0x7;")
        code.append("                uint32_t ext_amount = (value >> 8) & 0x7;")
        code.append("                // Index 3: 'lsl' for 64-bit (UXTX alias), 'uxtx' for 32-bit")
        code.append("                const char* extends_64[] = {\"uxtb\", \"uxth\", \"uxtw\", \"lsl\",")
        code.append("                                            \"sxtb\", \"sxth\", \"sxtw\", \"sxtx\"};")
        code.append("                const char* extends_32[] = {\"uxtb\", \"uxth\", \"uxtw\", \"uxtx\",")
        code.append("                                            \"sxtb\", \"sxth\", \"sxtw\", \"sxtx\"};")
        code.append("                const char* const* ext_table = is_64bit ? extends_64 : extends_32;")
        code.append("                std::string result = ext_table[ext_type];")
        code.append("                if (ext_amount != 0) result += \" #\" + std::to_string(ext_amount);")
        code.append("                return result;")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::Index:")
        code.append("            return \"[\" + std::to_string(value) + \"]\";")
        code.append("        ")
        code.append("        case OperandType::Label:")
        code.append("            // Format as signed hex offset")
        code.append("            {")
        code.append("                std::ostringstream oss;")
        code.append("                int32_t sval = static_cast<int32_t>(value);")
        code.append("                if (sval < 0) oss << \"#-0x\" << std::hex << (-sval);")
        code.append("                else oss << \"#0x\" << std::hex << sval;")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::Relative:")
        code.append("            // Format as PC-relative offset (.+0x10 or .-0x10)")
        code.append("            {")
        code.append("                std::ostringstream oss;")
        code.append("                // Use imm64 for wide offsets (ADRP), fall back to value")
        code.append("                int64_t sval = imm64 ? static_cast<int64_t>(imm64) : static_cast<int64_t>(static_cast<int32_t>(value));")
        code.append("                if (sval < 0) oss << \".-0x\" << std::hex << (-sval);")
        code.append("                else oss << \".+0x\" << std::hex << sval;")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::Pattern:")
        code.append("            {")
        code.append("                const char* s = pattern_to_string(pattern);")
        code.append("                if (s) return s;")
        code.append("                return \"#\" + std::to_string(value);")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::SVEMulImm:")
        code.append("            // SVE multiplier: 'mul #N' where value is already N (=imm4+1)")
        code.append("            if (value >= 10) {")
        code.append("                std::ostringstream _oss; _oss << \"mul #0x\" << std::hex << value;")
        code.append("                return _oss.str();")
        code.append("            }")
        code.append("            return \"mul #\" + std::to_string(value);")
        code.append("        ")
        code.append("        case OperandType::SVEVLxImm:")
        code.append("            // SVE VL specifier: vlx2 or vlx4")
        code.append("            return value == 4 ? \"vlx4\" : \"vlx2\";")
        code.append("        ")
        code.append("        case OperandType::PredicateRegisterList:")
        code.append("            {")
        code.append("                // value = first register, index = count, arrangement = element type")
        code.append("                std::string result = \"{ \";")
        code.append("                for (uint32_t i = 0; i < index; ++i) {")
        code.append("                    if (i > 0) result += \", \";")
        code.append("                    uint32_t reg = (value + i) & 15;")
        code.append("                    result += \"p\" + std::to_string(reg);")
        code.append("                    if (arrangement != Arrangement::None) { result += \".\"; result += Operand::arrangement_to_string(arrangement); }")
        code.append("                }")
        code.append("                result += \" }\";")
        code.append("                return result;")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::Prefetch:")
        code.append("            {")
        code.append("                const char* s = prefetch_to_string(prefetch);")
        code.append("                if (s) return s;")
        code.append("                return \"#\" + std::to_string(value);")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::Barrier:")
        code.append("            {")
        code.append("                const char* s = barrier_to_string(barrier);")
        code.append("                if (s) return s;")
        code.append("                return \"#\" + std::to_string(value);")
        code.append("            }")
        code.append("")
        code.append("        case OperandType::FloatImmediate:")
        code.append("            {")
        code.append("                // Literal zero marker (FCMPE/FCMP #0.0)")
        code.append("                if (imm64 == UINT64_MAX) return \"#0.0\";")
        code.append("                // Decode ARM VFPExpandImm{64}: imm8 → double")
        code.append("                // exp = NOT(imm8[6]):Replicate{8}(imm8[6]):imm8[5:4]")
        code.append("                // frac = imm8[3:0]:Zeros{48}")
        code.append("                uint64_t sign_bit = (value >> 7) & 1;")
        code.append("                uint64_t b = (value >> 6) & 1;")
        code.append("                uint64_t cd = (value >> 4) & 0x3;")
        code.append("                uint64_t efgh = value & 0xF;")
        code.append("                // NOT(b):Replicate{8}(b):cd = 11-bit exponent")
        code.append("                uint64_t exp = ((1 - b) << 10) | ((b ? 0xFF : 0x00) << 2) | cd;")
        code.append("                uint64_t frac = static_cast<uint64_t>(efgh) << 48;")
        code.append("                uint64_t bits = (sign_bit << 63) | (exp << 52) | frac;")
        code.append("                double fval;")
        code.append("                std::memcpy(&fval, &bits, 8);")
        code.append("                std::ostringstream oss;")
        code.append("                oss << \"#\" << std::fixed << std::setprecision(8) << fval;")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("")
        code.append("        case OperandType::VectorRegisterList:")
        code.append("            {")
        code.append("                // value = first register, index = count, arrangement = element type")
        code.append("                std::string result = \"{ \";")
        code.append("                for (uint32_t i = 0; i < index; ++i) {")
        code.append("                    if (i > 0) result += \", \";")
        code.append("                    uint32_t reg = (value + i) & 31;")
        code.append("                    result += \"v\" + std::to_string(reg);")
        code.append("                    if (arrangement != Arrangement::None) {")
        code.append("                        result += \".\";")
        code.append("                        result += Operand::arrangement_to_string(arrangement);")
        code.append("                    }")
        code.append("                }")
        code.append("                result += \" }\";")
        code.append("                if (has_index) {")
        code.append("                    result += \"[\" + std::to_string(amount) + \"]\";")
        code.append("                }")
        code.append("                return result;")
        code.append("            }")
        code.append("")
        code.extend("""\
        case OperandType::SVERegisterList:
            {
                // value = first register, index = count, arrangement = element type
                // offset = stride (0 or 1 = consecutive, >1 = strided)
                uint32_t stride = (offset > 1) ? (uint32_t)offset : 1;
                // Use range notation { Zn.T - Zn+k.T } for count>=3 when consecutive and non-wrapping
                if (stride == 1 && index >= 3 && (value + index - 1) <= 31) {
                    std::string result = "{ z" + std::to_string(value);
                    if (arrangement != Arrangement::None) { result += "."; result += Operand::arrangement_to_string(arrangement); }
                    result += " - z" + std::to_string(value + index - 1);
                    if (arrangement != Arrangement::None) { result += "."; result += Operand::arrangement_to_string(arrangement); }
                    result += " }";
                    return result;
                }
                std::string result = "{ ";
                for (uint32_t i = 0; i < index; ++i) {
                    if (i > 0) result += ", ";
                    uint32_t reg = (value + i * stride) & 31;
                    result += "z" + std::to_string(reg);
                    if (arrangement != Arrangement::None) {
                        result += ".";
                        result += Operand::arrangement_to_string(arrangement);
                    }
                }
                result += " }";
                if (has_index) {
                    result += "[" + std::to_string(amount) + "]";
                }
                return result;""".split('\n'))
        code.append("            }")
        code.append("")
        code.append("        case OperandType::MemoryOffsetMulVL:")
        code.append("            // [Xn|SP, #offset, mul vl] or [Xn|SP] when offset==0")
        code.append("            if (offset == 0) {")
        code.append("                return \"[\" + format_register(base_reg, true, true) + \"]\";")
        code.append("            }")
        code.append("            {")
        code.append("                std::ostringstream oss;")
        code.append("                oss << \"[\" << format_register(base_reg, true, true) << \", #\";")
        code.append("                if (offset < 0) {")
        code.append("                    if (offset >= -9) oss << std::dec << offset;")
        code.append("                    else oss << \"-0x\" << std::hex << (-offset);")
        code.append("                } else {")
        code.append("                    if (offset <= 9) oss << std::dec << offset;")
        code.append("                    else oss << \"0x\" << std::hex << offset;")
        code.append("                }")
        code.append("                oss << \", mul vl]\";")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("")
        code.append("        case OperandType::MemorySVEOffset:")
        code.append("            // [Zn.T, #offset] or [Zn.T] when offset==0")
        code.append("            {")
        code.append("                std::string result = \"[z\" + std::to_string(base_reg);")
        code.append("                if (arrangement != Arrangement::None) { result += \".\"; result += Operand::arrangement_to_string(arrangement); }")
        code.append("                if (offset != 0) {")
        code.append("                    std::ostringstream oss;")
        code.append("                    oss << \", #\";")
        code.append("                    if (offset < 0) {")
        code.append("                        if (offset >= -9) oss << std::dec << offset;")
        code.append("                        else oss << \"-0x\" << std::hex << (-offset);")
        code.append("                    } else {")
        code.append("                        if (offset <= 9) oss << std::dec << offset;")
        code.append("                        else oss << \"0x\" << std::hex << offset;")
        code.append("                    }")
        code.append("                    result += oss.str();")
        code.append("                }")
        code.append("                result += \"]\";")
        code.append("                return result;")
        code.append("            }")
        code.append("")
        code.append("        default:")
        code.append("            return std::to_string(value);")
        code.append("    }")
        code.append("}")
        code.append("#endif // !VEDA64_NO_STRINGS")
        code.append("")

        # Generate unified decode function - delegates to format-based decoder
        code.append("// Unified decode function - dispatches to format-based group decoders")
        code.append("std::optional<Instruction> decode(uint32_t insn) {")
        code.append("    return decode_format(insn);")
        code.append("}")
        code.append("")

        code.append("} // namespace veda64")
        code.append("")

        self._write_file(output_file, code)


    def _generate_util_header(self, output_file: Path):
        """Generate veda64/util.hpp with version constants, byte-order utils, DecodeBitMasks."""
        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("// Library version")
        code.append("constexpr int VERSION_MAJOR = 0;")
        code.append("constexpr int VERSION_MINOR = 1;")
        code.append("constexpr int VERSION_PATCH = 0;")
        code.append("")
        code.append("// Byte-order conversion utilities")
        code.append("// ARM64 stores instructions in little-endian byte order")
        code.append("// These convert between raw memory bytes and the uint32_t used by decode()")
        code.append("// e.g., PACIBSP in memory: {0x7f, 0x23, 0x03, 0xd5} -> 0xd503237f")
        code.append("")
        code.append("// Read a little-endian uint32_t from 4 bytes in memory")
        code.append("// {0x7f, 0x23, 0x03, 0xd5} -> 0xd503237f")
        code.append("inline uint32_t from_bytes(const uint8_t* bytes) {")
        code.append("    return static_cast<uint32_t>(bytes[0]) |")
        code.append("           (static_cast<uint32_t>(bytes[1]) << 8) |")
        code.append("           (static_cast<uint32_t>(bytes[2]) << 16) |")
        code.append("           (static_cast<uint32_t>(bytes[3]) << 24);")
        code.append("}")
        code.append("")
        code.append("// Write a uint32_t as 4 little-endian bytes to memory")
        code.append("// 0xd503237f -> {0x7f, 0x23, 0x03, 0xd5}")
        code.append("inline void to_bytes(uint32_t insn, uint8_t* bytes) {")
        code.append("    bytes[0] = static_cast<uint8_t>(insn);")
        code.append("    bytes[1] = static_cast<uint8_t>(insn >> 8);")
        code.append("    bytes[2] = static_cast<uint8_t>(insn >> 16);")
        code.append("    bytes[3] = static_cast<uint8_t>(insn >> 24);")
        code.append("}")
        code.append("")
        code.append("// ARM64 DecodeBitMasks - decodes N:imms:immr into a bitmask immediate")
        code.append("inline uint64_t decode_bit_masks(uint32_t N, uint32_t imms, uint32_t immr, bool is_64bit) {")
        code.append("    uint32_t len = 0;")
        code.append("    uint32_t combined = (N << 6) | (~imms & 0x3F);")
        code.append("    for (int i = 6; i >= 0; --i) {")
        code.append("        if (combined & (1u << i)) { len = i; break; }")
        code.append("    }")
        code.append("    uint32_t esize = 1u << len;")
        code.append("    uint32_t levels = esize - 1;")
        code.append("    uint32_t S = imms & levels;")
        code.append("    uint32_t R = immr & levels;")
        code.append("    uint64_t welem = (S + 1 == 64) ? ~0ULL : ((1ULL << (S + 1)) - 1);")
        code.append("    uint64_t emask = (esize == 64) ? ~0ULL : ((1ULL << esize) - 1);")
        code.append("    if (R != 0) {")
        code.append("        welem = ((welem >> R) | (welem << (esize - R))) & emask;")
        code.append("    }")
        code.append("    uint64_t result = 0;")
        code.append("    uint32_t regsize = is_64bit ? 64 : 32;")
        code.append("    for (uint32_t i = 0; i < regsize; i += esize) {")
        code.append("        result |= welem << i;")
        code.append("    }")
        code.append("    if (!is_64bit) result &= 0xFFFFFFFFULL;")
        code.append("    return result;")
        code.append("}")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    def _generate_mnemonic_header(self, output_file: Path):
        """Generate veda64/mnemonic.hpp with Mnemonic enum."""
        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("// Mnemonic enumeration")
        code.append("enum class Mnemonic {")

        mnemonics = set()
        for instr in self.instructions:
            if instr.mnemonic:
                mnemonics.add(instr.mnemonic)
            for encoding in instr.encodings:
                encoding_mnemonic = encoding.docvars.get('mnemonic', '')
                if encoding_mnemonic:
                    mnemonics.add(encoding_mnemonic)

        mnemonics.update(['TLBI', 'DC', 'AT', 'IC', 'GIC', 'BRB', 'CFP', 'CPP', 'DVP', 'APAS'])
        for mnem in sorted(mnemonics):
            code.append(f"    {mnem},")
        code.append("    UNKNOWN")
        code.append("};")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    def _generate_types_header(self, output_file: Path):
        """Generate veda64/types.hpp with Condition, OperandType, Arrangement enums."""
        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("// ARM64 condition codes")
        code.append("enum class Condition : int8_t {")
        code.append("    None = -1,")
        code.append("    EQ = 0,   // Equal")
        code.append("    NE = 1,   // Not equal")
        code.append("    CS = 2,   // Carry set / unsigned higher or same (HS)")
        code.append("    CC = 3,   // Carry clear / unsigned lower (LO)")
        code.append("    MI = 4,   // Minus / negative")
        code.append("    PL = 5,   // Plus / positive or zero")
        code.append("    VS = 6,   // Overflow")
        code.append("    VC = 7,   // No overflow")
        code.append("    HI = 8,   // Unsigned higher")
        code.append("    LS = 9,   // Unsigned lower or same")
        code.append("    GE = 10,  // Signed greater than or equal")
        code.append("    LT = 11,  // Signed less than")
        code.append("    GT = 12,  // Signed greater than")
        code.append("    LE = 13,  // Signed less than or equal")
        code.append("    AL = 14,  // Always")
        code.append("    NV = 15   // Never (behaves like AL)")
        code.append("};")
        code.append("")
        code.append("// Operand type enumeration")
        code.append("enum class OperandType {")
        code.append("    Register,           // General purpose register (Xn, Wn)")
        code.append("    VectorRegister,     // Vector/SIMD register (Vn, Qn, Dn, Sn, Hn, Bn)")
        code.append("    SVERegister,        // SVE scalable vector register (Zn)")
        code.append("    PredicateRegister,  // SVE predicate register (Pn)")
        code.append("    PredicateNRegister, // SVE predicate-as-counter register (PNn, pn8-pn15)")
        code.append("    SMETileRegister,    // SME tile register (ZAn)")
        code.append("    Immediate,          // Immediate value")
        code.append("    SignedImmediate,    // Signed immediate value")
        code.append("    MemoryBase,         // Memory operand [base]")
        code.append("    MemoryOffset,       // Memory operand [base, #offset]")
        code.append("    MemoryPreIndex,     // Memory operand [base, #offset]! (pre-index writeback)")
        code.append("    MemoryPostIndex,    // Memory operand [base], #offset (post-index writeback)")
        code.append("    MemoryRegOffset,    // Memory operand [base, Rm{, extend {#amount}}]")
        code.append("    Label,              // Branch target label/offset")
        code.append("    Relative,          // PC-relative offset for branches")
        code.append("    SystemRegister,     // System register")
        code.append("    Shift,              // Shift specifier (LSL, LSR, ASR, ROR)")
        code.append("    Extend,             // Extend specifier (UXTB, SXTW, etc.)")
        code.append("    Index,              // Element index")
        code.append("    Pattern,            // SVE pattern specifier")
        code.append("    SVEMulImm,          // SVE mul multiplier (MUL #N where N=imm4+1)")
        code.append("    Prefetch,           // Prefetch operation")
        code.append("    Barrier,            // Barrier option")
        code.append("    FloatImmediate,     // Floating-point immediate (#0.0, etc.)")
        code.append("    VectorRegisterList, // Vector register list { Vt.T, Vt+1.T, ... }")
        code.append("    SVERegisterList,    // SVE register list { Zt.T, Zt+1.T, ... }")
        code.append("    MemoryOffsetMulVL,  // SVE memory [base, #offset, mul vl]")
        code.append("    MemorySVEOffset,    // SVE gather memory [Zn.T, #offset]")
        code.append("    SMEZTRegister,      // SME ZT0 lookup table register")
        code.append("    PstateField,        // PSTATE field name for MSR/MRS immediate (SPSel, DAIFSet, etc.)")
        code.append("    FixedSym,           // Fixed symbolic operand (e.g. CSYNC, DSYNC)")
        code.append("    SysOp,              // SYS alias operation name (tlbi vmalle1 etc.)")
        code.append("    SVEVLxImm,          // SVE VL specifier (vlx2 or vlx4) for WHILE* pn_rr")
        code.append("    PredicateRegisterList, // Predicate register list { Pn.T, Pn+1.T, ... }")
        code.append("    Unknown")
        code.append("};")
        code.append("")
        code.append("// Vector arrangement specifier")
        code.append("enum class Arrangement : uint8_t {")
        code.append("    None = 0,")
        code.append("    B, H, S, D, Q,           // Scalar element sizes")
        code.append("    B8, H4, S2, D1,           // 64-bit vector")
        code.append("    B16, H8, S4, D2,          // 128-bit vector")
        code.append("    Q1, B2, B4, H2,           // Special")
        code.append("};")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    def _build_sysreg_entries(self):
        """Build deduplicated sysreg entries: list of (key, enum_name, display_name)."""
        from sysreg_table import SYSREG_NAMES
        from collections import Counter
        sysregs = dict(SYSREG_NAMES)

        # Detect duplicate uppercase names
        name_counts = Counter(v.upper() for v in sysregs.values())

        entries = []
        for (op0, op1, crn, crm, op2_val), name in sorted(sysregs.items()):
            key = (op0 << 14) | (op1 << 11) | (crn << 7) | (crm << 3) | op2_val
            enum_name = name.upper()
            if name_counts[enum_name] > 1:
                enum_name = f"{enum_name}_0x{key:04X}"
            entries.append((key, enum_name, name))
        return entries

    def _generate_sysreg_header(self, output_file: Path):
        """Generate veda64/sysreg.hpp with SystemRegister enum."""
        entries = self._build_sysreg_entries()

        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("// System register identifiers for MSR/MRS instructions")
        code.append("enum class SystemRegister : uint16_t {")

        for key, enum_name, _ in entries:
            code.append(f"    {enum_name} = 0x{key:04X}u,")

        code.append(f"    UNKNOWN = 0xFFFFu")
        code.append("};")
        code.append("")
        code.append("// Look up SystemRegister enum from encoding fields")
        code.append("SystemRegister sysreg_from_encoding(uint32_t op0, uint32_t op1, uint32_t CRn, uint32_t CRm, uint32_t op2);")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("// Convert SystemRegister to its lowercase string name")
        code.append("const char* sysreg_to_string(SystemRegister reg);")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    def _generate_sysreg_implementation(self, output_file: Path):
        """Generate lib/sysreg.cpp with sysreg_to_string() and sysreg_from_encoding()."""
        entries = self._build_sysreg_entries()

        code = self._license_header()
        code.append("#include \"veda64/sysreg.hpp\"")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")

        # sysreg_from_encoding
        code.append("SystemRegister sysreg_from_encoding(uint32_t op0, uint32_t op1, uint32_t CRn, uint32_t CRm, uint32_t op2) {")
        code.append("    uint32_t key = (op0 << 14) | (op1 << 11) | (CRn << 7) | (CRm << 3) | op2;")
        code.append("    switch (key) {")
        for key, enum_name, _ in entries:
            code.append(f"        case 0x{key:04X}u: return SystemRegister::{enum_name};")
        code.append("        default: return SystemRegister::UNKNOWN;")
        code.append("    }")
        code.append("}")
        code.append("")

        # sysreg_to_string
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("const char* sysreg_to_string(SystemRegister reg) {")
        code.append("    switch (reg) {")
        for key, enum_name, display_name in entries:
            code.append(f'        case SystemRegister::{enum_name}: return "{display_name}";')
        code.append('        default: return nullptr;')
        code.append("    }")
        code.append("}")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    # ── PstateField enum ──────────────────────────────────────────────

    # PstateField entries: (enum_index, enum_name, display_name)
    _PSTATE_ENTRIES = [
        (0, "UAO",       "uao"),
        (1, "PAN",       "pan"),
        (2, "SPSEL",     "spsel"),
        (3, "ALLINT",    "allint"),
        (4, "PM",        "pm"),
        (5, "SSBS",      "ssbs"),
        (6, "DIT",       "dit"),
        (7, "SVCRSM",   "svcrsm"),
        (8, "SVCRZA",    "svcrza"),
        (9, "SVCRSMZA", "svcrsmza"),
        (10, "TCO",       "tco"),
        (11, "DAIFSET",   "daifset"),
        (12, "DAIFCLR",   "daifclr"),
    ]

    def _generate_pstate_header(self, output_file: Path):
        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("// PSTATE field identifiers for MSR (immediate) instructions")
        code.append("enum class PstateField : uint8_t {")
        for idx, enum_name, _ in self._PSTATE_ENTRIES:
            code.append(f"    {enum_name} = {idx}u,")
        code.append(f"    UNKNOWN = 255u")
        code.append("};")
        code.append("")
        code.append("// Look up PstateField from packed (op1<<7)|(CRm<<3)|op2 value")
        code.append("PstateField pstate_from_value(uint32_t packed);")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("const char* pstate_to_string(PstateField f);")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    def _generate_pstate_implementation(self, output_file: Path):
        code = self._license_header()
        code.append("#include \"veda64/pstate.hpp\"")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        # The packed value is (op1<<7)|(CRm<<3)|op2. Some entries match any CRm,
        # others match on CRm[3:1]. We must replicate the original matching logic.
        code.append("PstateField pstate_from_value(uint32_t packed) {")
        code.append("    uint8_t op1 = (packed >> 7) & 7;")
        code.append("    uint8_t CRm = (packed >> 3) & 0xF;")
        code.append("    uint8_t op2 = packed & 7;")
        code.append("    if (op1 == 0 && op2 == 3) return PstateField::UAO;")
        code.append("    if (op1 == 0 && op2 == 4) return PstateField::PAN;")
        code.append("    if (op1 == 0 && op2 == 5) return PstateField::SPSEL;")
        code.append("    if (op1 == 1 && op2 == 0 && (CRm >> 1) == 0) return PstateField::ALLINT;")
        code.append("    if (op1 == 1 && op2 == 0 && (CRm >> 1) == 1) return PstateField::PM;")
        code.append("    if (op1 == 3 && op2 == 1) return PstateField::SSBS;")
        code.append("    if (op1 == 3 && op2 == 2) return PstateField::DIT;")
        code.append("    if (op1 == 3 && op2 == 3 && (CRm >> 1) == 1) return PstateField::SVCRSM;")
        code.append("    if (op1 == 3 && op2 == 3 && (CRm >> 1) == 2) return PstateField::SVCRZA;")
        code.append("    if (op1 == 3 && op2 == 3 && (CRm >> 1) == 3) return PstateField::SVCRSMZA;")
        code.append("    if (op1 == 3 && op2 == 4) return PstateField::TCO;")
        code.append("    if (op1 == 3 && op2 == 6) return PstateField::DAIFSET;")
        code.append("    if (op1 == 3 && op2 == 7) return PstateField::DAIFCLR;")
        code.append("    return PstateField::UNKNOWN;")
        code.append("}")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("const char* pstate_to_string(PstateField f) {")
        code.append("    switch (f) {")
        for _, enum_name, display_name in self._PSTATE_ENTRIES:
            code.append(f'        case PstateField::{enum_name}: return "{display_name}";')
        code.append("        default: return nullptr;")
        code.append("    }")
        code.append("}")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    # ── PrefetchOp enum ──────────────────────────────────────────────

    _PREFETCH_ENTRIES = [
        (0, "PLDL1KEEP"), (1, "PLDL1STRM"), (2, "PLDL2KEEP"), (3, "PLDL2STRM"),
        (4, "PLDL3KEEP"), (5, "PLDL3STRM"), (6, "PLDSLCKEEP"), (7, "PLDSLCSTRM"),
        (8, "PLIL1KEEP"), (9, "PLIL1STRM"), (10, "PLIL2KEEP"), (11, "PLIL2STRM"),
        (12, "PLIL3KEEP"), (13, "PLIL3STRM"), (14, "PLISLCKEEP"), (15, "PLISLCSTRM"),
        (16, "PSTL1KEEP"), (17, "PSTL1STRM"), (18, "PSTL2KEEP"), (19, "PSTL2STRM"),
        (20, "PSTL3KEEP"), (21, "PSTL3STRM"), (22, "PSTSLCKEEP"), (23, "PSTSLCSTRM"),
    ]

    def _generate_prefetch_header(self, output_file: Path):
        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("// Prefetch operation identifiers for PRFM/PRFUM instructions")
        code.append("enum class PrefetchOp : uint8_t {")
        for val, name in self._PREFETCH_ENTRIES:
            code.append(f"    {name} = {val}u,")
        code.append(f"    UNKNOWN = 255u")
        code.append("};")
        code.append("")
        code.append("// Look up PrefetchOp from 5-bit prfop field")
        code.append("PrefetchOp prefetch_from_value(uint32_t prfop);")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("const char* prefetch_to_string(PrefetchOp op);")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    def _generate_prefetch_implementation(self, output_file: Path):
        code = self._license_header()
        code.append("#include \"veda64/prefetch.hpp\"")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("PrefetchOp prefetch_from_value(uint32_t prfop) {")
        code.append("    if (prfop < 24) return static_cast<PrefetchOp>(prfop);")
        code.append("    return PrefetchOp::UNKNOWN;")
        code.append("}")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("const char* prefetch_to_string(PrefetchOp op) {")
        code.append("    switch (op) {")
        for val, name in self._PREFETCH_ENTRIES:
            code.append(f'        case PrefetchOp::{name}: return "{name.lower()}";')
        code.append("        default: return nullptr;")
        code.append("    }")
        code.append("}")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    # ── BarrierOp enum ───────────────────────────────────────────────

    _BARRIER_ENTRIES = [
        (1, "OSHLD"), (2, "OSHST"), (3, "OSH"),
        (5, "NSHLD"), (6, "NSHST"), (7, "NSH"),
        (9, "ISHLD"), (10, "ISHST"), (11, "ISH"),
        (13, "LD"), (14, "ST"), (15, "SY"),
    ]

    def _generate_barrier_header(self, output_file: Path):
        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("// Barrier option identifiers for DMB/DSB/ISB instructions")
        code.append("enum class BarrierOp : uint8_t {")
        for val, name in self._BARRIER_ENTRIES:
            code.append(f"    {name} = {val}u,")
        code.append(f"    UNKNOWN = 255u")
        code.append("};")
        code.append("")
        code.append("// Look up BarrierOp from 4-bit CRm field")
        code.append("BarrierOp barrier_from_value(uint32_t crm);")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("const char* barrier_to_string(BarrierOp op);")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    def _generate_barrier_implementation(self, output_file: Path):
        code = self._license_header()
        code.append("#include \"veda64/barrier.hpp\"")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("BarrierOp barrier_from_value(uint32_t crm) {")
        code.append("    switch (crm) {")
        for val, name in self._BARRIER_ENTRIES:
            code.append(f"        case {val}u: return BarrierOp::{name};")
        code.append("        default: return BarrierOp::UNKNOWN;")
        code.append("    }")
        code.append("}")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("const char* barrier_to_string(BarrierOp op) {")
        code.append("    switch (op) {")
        for val, name in self._BARRIER_ENTRIES:
            code.append(f'        case BarrierOp::{name}: return "{name.lower()}";')
        code.append("        default: return nullptr;")
        code.append("    }")
        code.append("}")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    # ── SvePattern enum ──────────────────────────────────────────────

    _SVE_PATTERN_ENTRIES = [
        (0, "POW2"), (1, "VL1"), (2, "VL2"), (3, "VL3"), (4, "VL4"),
        (5, "VL5"), (6, "VL6"), (7, "VL7"), (8, "VL8"),
        (9, "VL16"), (10, "VL32"), (11, "VL64"), (12, "VL128"), (13, "VL256"),
        (29, "MUL4"), (30, "MUL3"), (31, "ALL"),
    ]

    def _generate_pattern_header(self, output_file: Path):
        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("// SVE predicate pattern identifiers")
        code.append("enum class SvePattern : uint8_t {")
        for val, name in self._SVE_PATTERN_ENTRIES:
            code.append(f"    {name} = {val}u,")
        code.append(f"    UNKNOWN = 255u")
        code.append("};")
        code.append("")
        code.append("// Look up SvePattern from 5-bit pattern field")
        code.append("SvePattern pattern_from_value(uint32_t pattern);")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("const char* pattern_to_string(SvePattern pat);")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    def _generate_pattern_implementation(self, output_file: Path):
        code = self._license_header()
        code.append("#include \"veda64/pattern.hpp\"")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("SvePattern pattern_from_value(uint32_t pattern) {")
        code.append("    switch (pattern) {")
        for val, name in self._SVE_PATTERN_ENTRIES:
            code.append(f"        case {val}u: return SvePattern::{name};")
        code.append("        default: return SvePattern::UNKNOWN;")
        code.append("    }")
        code.append("}")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("const char* pattern_to_string(SvePattern pat) {")
        code.append("    switch (pat) {")
        for val, name in self._SVE_PATTERN_ENTRIES:
            code.append(f'        case SvePattern::{name}: return "{name.lower()}";')
        code.append("        default: return nullptr;")
        code.append("    }")
        code.append("}")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    # ── SysOp enum ───────────────────────────────────────────────────

    def _build_sysop_entries(self):
        """Build SysOp enum entries from the sys_table.
        Returns list of (index, enum_name, display_name)."""
        sys_entries = self._build_sys_table()
        op_names = []
        op_name_set = set()
        for (key, mnem, op_name, has_xt) in sys_entries:
            if op_name not in op_name_set:
                op_name_set.add(op_name)
                op_names.append((mnem, op_name))

        entries = []
        from collections import Counter
        name_counts = Counter(op_name for _, op_name in op_names)
        for idx, (mnem, op_name) in enumerate(op_names):
            enum_name = f"{mnem}_{op_name}" if name_counts[op_name] > 1 else op_name
            entries.append((idx, enum_name, op_name.lower()))
        return entries

    def _generate_sysop_header(self, output_file: Path):
        entries = self._build_sysop_entries()
        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("// System operation identifiers for TLBI/DC/AT/IC/etc. instructions")
        code.append("enum class SysOp : uint16_t {")
        for idx, enum_name, _ in entries:
            code.append(f"    {enum_name} = {idx}u,")
        code.append(f"    UNKNOWN = 0xFFFFu")
        code.append("};")
        code.append("")
        code.append("// Look up SysOp from index into sys_ops table")
        code.append("SysOp sysop_from_value(uint32_t idx);")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("const char* sysop_to_string(SysOp op);")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    def _generate_sysop_implementation(self, output_file: Path):
        entries = self._build_sysop_entries()
        code = self._license_header()
        code.append("#include \"veda64/sysop.hpp\"")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append(f"SysOp sysop_from_value(uint32_t idx) {{")
        code.append(f"    if (idx < {len(entries)}u) return static_cast<SysOp>(idx);")
        code.append("    return SysOp::UNKNOWN;")
        code.append("}")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("const char* sysop_to_string(SysOp op) {")
        code.append("    switch (op) {")
        for idx, enum_name, display_name in entries:
            code.append(f'        case SysOp::{enum_name}: return "{display_name}";')
        code.append("        default: return nullptr;")
        code.append("    }")
        code.append("}")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    # ─────────────────────────────────────────────────────────────────

    def _generate_operand_header(self, output_file: Path):
        """Generate veda64/operand.hpp with Operand class."""
        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("#include <string>")
        code.append("#include \"mnemonic.hpp\"")
        code.append("#include \"types.hpp\"")
        code.append("#include \"sysreg.hpp\"")
        code.append("#include \"pstate.hpp\"")
        code.append("#include \"prefetch.hpp\"")
        code.append("#include \"barrier.hpp\"")
        code.append("#include \"pattern.hpp\"")
        code.append("#include \"sysop.hpp\"")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("// Operand representation")
        code.append("class Operand {")
        code.append("public:")
        code.append("    Operand() = default;")
        code.append("")
        code.append("    // Constructor for simple operands (registers, immediates)")
        code.append("    Operand(OperandType t, uint32_t v, bool is_64 = true)")
        code.append("        : type(t), value(v), is_64bit(is_64) {}")
        code.append("")
        code.append("    // Constructor for memory operands")
        code.append("    Operand(OperandType t, uint32_t base, int32_t off, uint32_t idx_reg = 0, uint32_t ext = 0, uint32_t amt = 0)")
        code.append("        : type(t), base_reg(base), offset(off), index_reg(idx_reg), extend(ext), amount(amt) {}")
        code.append("")
        code.append("    // Static factory methods for memory operands")
        code.append("    static Operand memory_base(uint32_t base) {")
        code.append("        return Operand(OperandType::MemoryBase, base, 0);")
        code.append("    }")
        code.append("    static Operand memory_offset(uint32_t base, int32_t offset) {")
        code.append("        return Operand(OperandType::MemoryOffset, base, offset);")
        code.append("    }")
        code.append("    static Operand memory_pre_index(uint32_t base, int32_t offset) {")
        code.append("        return Operand(OperandType::MemoryPreIndex, base, offset);")
        code.append("    }")
        code.append("    static Operand memory_post_index(uint32_t base, int32_t offset) {")
        code.append("        return Operand(OperandType::MemoryPostIndex, base, offset);")
        code.append("    }")
        code.append("    static Operand memory_reg_offset(uint32_t base, uint32_t index, uint32_t extend = 0, uint32_t amount = 0) {")
        code.append("        return Operand(OperandType::MemoryRegOffset, base, 0, index, extend, amount);")
        code.append("    }")
        code.append("")
        code.append("    OperandType type = OperandType::Unknown;")
        code.append("    uint32_t value = 0;          // Raw field value for simple operands")
        code.append("    uint64_t imm64 = 0;          // 64-bit immediate value (for logical immediates)")
        code.append("    bool is_64bit = true;        // True for 64-bit registers (X), false for 32-bit (W)")
        code.append("    bool is_sp = false;          // True if reg 31 should be SP/WSP, false for XZR/WZR")
        code.append("    Arrangement arrangement = Arrangement::None;  // Vector arrangement specifier (.16b, .4s, etc.)")
        code.append("    uint32_t index = 0;           // Element index for indexed vector operands (v0.b[3])")
        code.append("    bool has_index = false;       // True if index field is valid")
        code.append("    bool prefer_decimal = false;  // True if immediate should always be formatted as decimal")
        code.append("    SystemRegister sysreg = SystemRegister::UNKNOWN;  // System register for MSR/MRS operands")
        code.append("    PstateField pstate = PstateField::UNKNOWN;        // PSTATE field for MSR (immediate)")
        code.append("    PrefetchOp prefetch = PrefetchOp::UNKNOWN;        // Prefetch operation for PRFM")
        code.append("    BarrierOp barrier = BarrierOp::UNKNOWN;           // Barrier option for DMB/DSB/ISB")
        code.append("    SvePattern pattern = SvePattern::UNKNOWN;         // SVE predicate pattern")
        code.append("    SysOp sysop = SysOp::UNKNOWN;                    // System operation for TLBI/DC/AT/IC/etc.")
        code.append("")
        code.append("    // Memory operand fields")
        code.append("    uint32_t base_reg = 0;       // Base register number")
        code.append("    int32_t offset = 0;          // Signed offset")
        code.append("    uint32_t index_reg = 0;      // Index register for reg+reg addressing")
        code.append("    uint32_t extend = 0;         // Extend type for reg+reg addressing")
        code.append("    uint32_t amount = 0;         // Shift/extend amount")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("    // Format operand for disassembly")
        code.append("    std::string to_string() const;")
        code.append("    static const char* arrangement_to_string(Arrangement a);")
        code.append("")
        code.append("private:")
        code.append("    // Helper functions for formatting")
        code.append("    static std::string format_register(uint32_t reg, bool is_64bit, bool is_sp = false);")
        code.append("    static std::string format_vector_register(uint32_t reg, Arrangement arrangement);")
        code.append("    static Arrangement arr_from_size(uint32_t size);")
        code.append("    static Arrangement arr_narrow_from_size(uint32_t size);")
        code.append("    static Arrangement arr_wide_from_size(uint32_t size);")
        code.append("    static Arrangement vec_arr(uint32_t size, uint32_t q);")
        code.append("#endif")
        code.append("};")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("// Convert mnemonic enum to string")
        code.append("const char* mnemonic_to_string(Mnemonic mnem);")
        code.append("")
        code.append("// Determine vector arrangement for MOVI/MVNI based on Q and cmode fields")
        code.append("Arrangement get_movi_arrangement(uint32_t insn);")
        code.append("int get_movi_shift(uint32_t insn);")
        code.append("")
        code.append("// Convert condition code to string (\"eq\", \"ne\", etc.)")
        code.append("const char* condition_to_string(Condition cond);")
        code.append("#endif")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    def _generate_instruction_subheader(self, output_file: Path):
        """Generate veda64/instruction.hpp with Instruction class and decode() declarations."""
        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("#include <string>")
        code.append("#include <vector>")
        code.append("#include <optional>")
        code.append("#include \"mnemonic.hpp\"")
        code.append("#include \"types.hpp\"")
        code.append("#include \"operand.hpp\"")
        code.append("#include \"util.hpp\"")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("// Instruction representation")
        code.append("class Instruction {")
        code.append("public:")
        code.append("    Instruction() = default;")
        code.append("    Instruction(Mnemonic mnem, uint32_t raw)")
        code.append("        : mnemonic(mnem), raw_value(raw) {}")
        code.append("")
        code.append("    Mnemonic mnemonic = Mnemonic::UNKNOWN;")
        code.append("    Condition condition = Condition::None;")
        code.append("    uint32_t raw_value = 0;")
        code.append("    std::vector<Operand> operands;")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("    // Format as disassembled instruction")
        code.append("    std::string to_string() const;")
        code.append("#endif")
        code.append("};")
        code.append("")
        code.append("// Decode a single ARM64 instruction from a uint32_t (native little-endian value)")
        code.append("std::optional<Instruction> decode(uint32_t insn);")
        code.append("")
        code.append("// Decode a single ARM64 instruction from 4 bytes in memory (little-endian)")
        code.append("inline std::optional<Instruction> decode(const uint8_t* bytes) {")
        code.append("    return decode(from_bytes(bytes));")
        code.append("}")
        code.append("")
        code.append("} // namespace veda64")
        code.append("")
        self._write_file(output_file, code)

    def _generate_hook_header(self, output_file: Path):
        """Generate veda64/hook.hpp with Hook API declarations."""
        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("#if !defined(VEDA64_NO_HOOKS) && (defined(_WIN32) || defined(VEDA64_HOOK_SUPPORT))")
        code.append("")
        code.append("#include <cstdint>")
        code.append("#include <cstddef>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("namespace hook {")
        code.append("")
        code.append("// Forward declarations")
        code.append("struct HookContext;")
        code.append("struct Trampoline;")
        code.append("")
        code.append("// Hook status codes")
        code.append("enum class HookStatus {")
        code.append("    Success = 0,")
        code.append("    NotInitialized,")
        code.append("    InvalidTarget,")
        code.append("    InvalidDetour,")
        code.append("    AllocationFailed,")
        code.append("    ProtectionFailed,")
        code.append("    DisassemblyFailed,")
        code.append("    RelocationFailed,")
        code.append("    InstructionTooComplex,")
        code.append("    HookAlreadyInstalled,")
        code.append("    HookNotFound,")
        code.append("    HookDisabled,")
        code.append("    InternalError")
        code.append("};")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("// Convert status to string")
        code.append("const char* status_to_string(HookStatus status);")
        code.append("#endif")
        code.append("")
        code.append("// Hook handle - opaque pointer to hook context")
        code.append("using HookHandle = HookContext*;")
        code.append("")
        code.append("// Hook configuration options")
        code.append("struct HookConfig {")
        code.append("    // Minimum bytes to overwrite (default: 16 for LDR+BR sequence)")
        code.append("    size_t min_hook_size = 16;")
        code.append("")
        code.append("    // Maximum instructions to relocate in trampoline")
        code.append("    size_t max_relocated_insns = 32;")
        code.append("")
        code.append("    // Enable thread-safe hook installation (uses suspend/resume)")
        code.append("    bool thread_safe = true;")
        code.append("")
        code.append("    // Preserve CPU flags across hook")
        code.append("    bool preserve_flags = true;")
        code.append("")
        code.append("    // Allow hooking of already-hooked functions (chain hooks)")
        code.append("    bool allow_chain = false;")
        code.append("};")
        code.append("")
        code.append("// Global configuration")
        code.append("void set_config(const HookConfig& config);")
        code.append("HookConfig get_config();")
        code.append("")
        code.append("// Initialize the hooking subsystem")
        code.append("// Must be called before any other hook functions")
        code.append("HookStatus initialize();")
        code.append("")
        code.append("// Shutdown the hooking subsystem")
        code.append("// Automatically removes all installed hooks")
        code.append("void shutdown();")
        code.append("")
        code.append("// Check if hooking subsystem is initialized")
        code.append("bool is_initialized();")
        code.append("")
        code.append("// Internal install (void* interface)")
        code.append("HookStatus install_impl(void* target, void* detour, void** original, HookHandle* handle);")
        code.append("")
        code.append("// Install an inline hook (starts disabled — call enable() to activate)")
        code.append("// Type-safe: target and detour must have matching signatures.")
        code.append("// original receives a callable trampoline to the original function.")
        code.append("// Usage: hook::install(&MessageBoxA, &my_detour, &original_ptr, &handle);")
        code.append("template<typename Fn>")
        code.append("HookStatus install(Fn* target, Fn* detour, Fn** original, HookHandle* handle = nullptr) {")
        code.append("    return install_impl(reinterpret_cast<void*>(target),")
        code.append("                        reinterpret_cast<void*>(detour),")
        code.append("                        reinterpret_cast<void**>(original), handle);")
        code.append("}")
        code.append("")
        code.append("// Non-template overload for raw void* pointers")
        code.append("inline HookStatus install(void* target, void* detour, void** original, HookHandle* handle = nullptr) {")
        code.append("    return install_impl(target, detour, original, handle);")
        code.append("}")
        code.append("")
        code.append("// Remove a previously installed hook")
        code.append("// Restores original bytes and frees trampoline")
        code.append("HookStatus remove(HookHandle handle);")
        code.append("")
        code.append("// Remove all hooks")
        code.append("void remove_all();")
        code.append("")
        code.append("// Enable a disabled hook")
        code.append("HookStatus enable(HookHandle handle);")
        code.append("")
        code.append("// Disable a hook (restores original bytes but keeps trampoline)")
        code.append("HookStatus disable(HookHandle handle);")
        code.append("")
        code.append("// Enable all installed hooks")
        code.append("HookStatus enable_all();")
        code.append("")
        code.append("// Disable all installed hooks")
        code.append("HookStatus disable_all();")
        code.append("")
        code.append("// Check if hook is enabled")
        code.append("bool is_enabled(HookHandle handle);")
        code.append("")
        code.append("// Get hook information")
        code.append("void* get_target(HookHandle handle);")
        code.append("void* get_detour(HookHandle handle);")
        code.append("void* get_trampoline(HookHandle handle);")
        code.append("")
        code.append("// Get number of bytes overwritten at target")
        code.append("size_t get_hook_size(HookHandle handle);")
        code.append("")
        code.append("// Get number of instructions relocated to trampoline")
        code.append("size_t get_relocated_count(HookHandle handle);")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("// Debug: Dump hook information")
        code.append("void dump_hook(HookHandle handle);")
        code.append("#endif")
        code.append("")
        code.append("// ============================================================================")
        code.append("// Low-level API for advanced usage")
        code.append("// ============================================================================")
        code.append("")
        code.append("namespace detail {")
        code.append("")
        code.append("// Generate a jump sequence to target address")
        code.append("// buffer: output buffer (must be at least 16 bytes)")
        code.append("// target: destination address")
        code.append("// Returns: number of bytes written")
        code.append("size_t generate_jump(uint8_t* buffer, void* target);")
        code.append("")
        code.append("// Generate a call sequence (saves return address)")
        code.append("// buffer: output buffer (must be at least 16 bytes)")
        code.append("// target: destination address")
        code.append("// Returns: number of bytes written")
        code.append("size_t generate_call(uint8_t* buffer, void* target);")
        code.append("")
        code.append("// Check if an instruction is PC-relative")
        code.append("bool is_pc_relative(uint32_t insn);")
        code.append("")
        code.append("// Check if an instruction can be safely relocated")
        code.append("bool can_relocate(uint32_t insn);")
        code.append("")
        code.append("// Detect Windows ARM64 syscall stub pattern (SVC + RET + 0 + 0)")
        code.append("bool is_syscall_stub(const uint8_t* target);")
        code.append("")
        code.append("// Resolve forwarding stubs (follows unconditional B chains)")
        code.append("void* resolve_forwarding_stub(void* target);")
        code.append("")
        code.append("// Relocate a single instruction to a new address")
        code.append("bool relocate_instruction(")
        code.append("    uint32_t insn,")
        code.append("    uint64_t old_pc,")
        code.append("    uint64_t new_pc,")
        code.append("    uint32_t* out_insn,")
        code.append("    size_t* out_count")
        code.append(");")
        code.append("")
        code.append("// Allocate executable memory for trampolines")
        code.append("void* alloc_executable(size_t size);")
        code.append("")
        code.append("// Free executable memory")
        code.append("void free_executable(void* ptr, size_t size);")
        code.append("")
        code.append("// Make memory region writable temporarily")
        code.append("// Returns previous protection value")
        code.append("uint32_t make_writable(void* addr, size_t size);")
        code.append("")
        code.append("// Restore memory protection")
        code.append("void restore_protection(void* addr, size_t size, uint32_t old_protect);")
        code.append("")
        code.append("// Flush instruction cache")
        code.append("void flush_icache(void* addr, size_t size);")
        code.append("")
        code.append("// Suspend all threads except current (for safe hook installation)")
        code.append("void suspend_threads();")
        code.append("")
        code.append("// Resume all suspended threads")
        code.append("void resume_threads();")
        code.append("")
        code.append("} // namespace detail")
        code.append("")
        code.append("} // namespace hook")
        code.append("} // namespace veda64")
        code.append("")
        code.append("#endif // !VEDA64_NO_HOOKS && (_WIN32 || VEDA64_HOOK_SUPPORT)")
        code.append("")
        self._write_file(output_file, code)

    def _generate_veda64_header(self, output_file: Path):
        """Generate the umbrella veda64.hpp header that includes all sub-headers."""
        code = self._license_header()
        code.append("#pragma once")
        code.append("")
        code.append("#include \"veda64/util.hpp\"")
        code.append("#include \"veda64/mnemonic.hpp\"")
        code.append("#include \"veda64/types.hpp\"")
        code.append("#include \"veda64/operand.hpp\"")
        code.append("#include \"veda64/instruction.hpp\"")
        code.append("")
        code.append("#if !defined(VEDA64_NO_HOOKS) && (defined(_WIN32) || defined(VEDA64_HOOK_SUPPORT))")
        code.append("#include \"veda64/hook.hpp\"")
        code.append("#endif")
        code.append("")

        self._write_file(output_file, code)

    def _generate_class_files(self, class_name: str, instructions: List[Instruction],
                              header_file: Path, cpp_file: Path):
        """Generate C++ header and implementation files for a specific instruction class."""

        # Generate encoding structures and collect info
        seen_encodings = set()
        struct_names = []
        encoding_info = []

        for instr in instructions:
            for encoding in instr.encodings:
                if encoding.name in seen_encodings:
                    continue
                seen_encodings.add(encoding.name)

                struct_name = self._sanitize_struct_name(encoding.name)
                struct_names.append(struct_name)

                struct_code, field_list, fixed_bits, fixed_mask, full_pattern, full_mask = self._generate_encoding_struct(instr, encoding)

                # Use alias_mnemonic if this is an alias instruction (e.g., MUL is alias of MADD)
                # Otherwise use encoding-specific mnemonic, falling back to instruction mnemonic
                mnemonic = encoding.docvars.get('mnemonic', instr.mnemonic)

                encoding_info.append({
                    'struct_name': struct_name,
                    'encoding_name': encoding.name,
                    'field_list': field_list,
                    'struct_code': struct_code,
                    'fixed_bits': fixed_bits,
                    'fixed_mask': fixed_mask,
                    'full_pattern': full_pattern,
                    'full_mask': full_mask,
                    'mnemonic': mnemonic
                })

        # Generate header file
        self._generate_class_header(class_name, struct_names, encoding_info, header_file)

        # Generate implementation file
        self._generate_class_implementation(class_name, encoding_info, cpp_file)

    def _generate_class_header(self, class_name: str, struct_names: List[str],
                                encoding_info: List[Dict], output_file: Path):
        """Generate C++ header file with only function declarations."""
        code = self._license_header()

        # Header guard
        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("#include <optional>")
        code.append("#include \"../veda64.hpp\"")
        code.append("")
        code.append("namespace veda64 {")
        code.append(f"namespace {self._sanitize_namespace(class_name)} {{")
        code.append("")

        # Generate encode function declarations
        code.append("// Encode functions")
        for info in encoding_info:
            code.extend(self._generate_encode_declaration(
                info['struct_name'],
                info['encoding_name'],
                info['field_list']
            ))

        code.append("")

        # Generate decode function declaration
        code.append("// Decode function")
        code.extend(self._generate_decode_declaration(class_name))
        code.append("")

        code.append(f"}} // namespace {self._sanitize_namespace(class_name)}")
        code.append("} // namespace veda64")
        code.append("")

        # Write to file
        self._write_file(output_file, code)

    def _generate_class_implementation(self, class_name: str, encoding_info: List[Dict], output_file: Path):
        """Generate C++ implementation file with structures and function definitions."""
        code = self._license_header()

        # Include header
        code.append(f"#include \"class/{class_name}.hpp\"")
        code.append("")
        code.append("namespace veda64 {")
        code.append(f"namespace {self._sanitize_namespace(class_name)} {{")
        code.append("")

        # Generate encoding structures (private to this .cpp file)
        code.append("// Internal encoding structures")
        for info in encoding_info:
            code.extend(info['struct_code'])
            code.append("")

        # Generate union (private to this .cpp file)
        struct_names = [info['struct_name'] for info in encoding_info]
        code.extend(self._generate_union(class_name, struct_names))
        code.append("")

        # Generate encode function implementations
        code.append("// Encode function implementations")
        for info in encoding_info:
            code.extend(self._generate_encode_implementation(
                class_name,
                info['struct_name'],
                info['encoding_name'],
                info['field_list']
            ))
            code.append("")

        # Generate decode function implementation
        code.append("// Decode function implementation")
        code.extend(self._generate_decode_function(class_name, encoding_info))
        code.append("")

        code.append(f"}} // namespace {self._sanitize_namespace(class_name)}")
        code.append("} // namespace veda64")
        code.append("")

        # Write to file
        self._write_file(output_file, code)

    def _generate_encoding_struct(self, instr: Instruction, encoding: InstructionEncoding) -> tuple:
        """Generate C++ struct for a specific encoding with bitfields."""
        code = []

        # Comment with instruction info
        code.append(f"// {instr.mnemonic}: {instr.brief}")
        code.append(f"// Encoding: {encoding.name}")
        code.append(f"// Template: {encoding.asm_template}")

        # Struct definition with bitfields
        struct_name = self._sanitize_struct_name(encoding.name)
        code.append(f"struct {struct_name} {{")

        # Create a map of all bit positions to fields
        bit_map = [None] * 32
        field_list = []  # Track fields in order for function generation

        for field_name, field_info in encoding.fields.items():
            hibit = field_info.get('hibit')
            width = field_info.get('width', 1)
            if hibit is not None:
                lobit = hibit - width + 1
                for bit in range(lobit, hibit + 1):
                    if bit < 32:
                        bit_map[bit] = (field_name, field_info)

        # Generate bitfields from bit 0 to 31
        current_bit = 0
        reserved_count = 0

        while current_bit < 32:
            if bit_map[current_bit] is None:
                # Find consecutive reserved bits
                reserved_start = current_bit
                while current_bit < 32 and bit_map[current_bit] is None:
                    current_bit += 1
                reserved_width = current_bit - reserved_start
                code.append(f"    uint32_t reserved{reserved_count} : {reserved_width};")
                reserved_count += 1
            else:
                # Get the field info
                field_name, field_info = bit_map[current_bit]
                width = field_info.get('width', 1)
                hibit = field_info.get('hibit')
                lobit = hibit - width + 1
                fixed = field_info.get('fixed')

                # Skip if this field doesn't start at current_bit
                if lobit != current_bit:
                    current_bit += 1
                    continue

                # Generate bitfield
                sanitized_name = self._sanitize_field_name(field_name)

                # Determine if field should be signed
                is_signed = self._is_signed_field(field_name) and not (fixed is not None and self._is_binary_string(fixed))
                field_type = "int32_t" if is_signed else "uint32_t"

                # Add comment with fixed value if applicable
                comment = ""
                is_fixed = fixed is not None and self._is_binary_string(fixed)
                partial_pattern = field_info.get('partial_pattern')
                if is_fixed:
                    fixed_val = int(fixed, 2)
                    comment = f"  // fixed: 0b{fixed} (0x{fixed_val:X})"
                elif partial_pattern:
                    comment = f"  // partial: {partial_pattern}"

                code.append(f"    {field_type} {sanitized_name} : {width};{comment}")

                # Track field for function generation
                field_list.append({
                    'name': sanitized_name,
                    'original_name': field_name,
                    'width': width,
                    'fixed': fixed if is_fixed else None,
                    'is_fixed': is_fixed,
                    'partial_pattern': partial_pattern,
                    'constraint': field_info.get('constraint'),
                    'is_signed': is_signed,
                    'hibit': hibit,
                    'lobit': lobit
                })

                current_bit += width

        code.append("};")
        code.append("")

        # Calculate fixed bits and full pattern for decoding
        fixed_bits = 0
        fixed_mask = 0
        full_pattern = 0
        full_mask = 0

        # Operand field names (these are variable and should NOT be in the match pattern)
        # Include fields that are encoder parameters (entirely variable, not partially fixed)
        operand_fields = {
            # Register operands
            'Rd', 'Rn', 'Rm', 'Ra', 'Rt', 'Rt2', 'Rs',
            # Immediate operands
            'imm', 'imm12', 'imm16', 'imm19', 'imm26', 'immr', 'imms', 'immlo', 'immhi',
            'imm2', 'imm3', 'imm4', 'imm5', 'imm6', 'imm7', 'imm8', 'imm9', 'imm13',
            # Shift/extend/condition operands
            'hw', 'shift', 'cond', 'nzcv', 'option', 'S',
            # System register operands
            'CRm', 'CRn', 'op1', 'op2',
            # SVE/SME variable fields
            'Pg', 'Pd', 'Pn', 'Pm', 'Zd', 'Zn', 'Zm', 'Zt', 'Za', 'ZAda', 'ZAn',
            # Size/arrangement operands that are often variable parameters
            'Q', 'size', 'sz',
        }

        # Include all bits EXCEPT operand fields
        for field_name, field_info in encoding.fields.items():
            fixed = field_info.get('fixed')
            hibit = field_info.get('hibit')
            width = field_info.get('width', 1)

            if hibit is None:
                continue

            lobit = hibit - width + 1

            # Skip "should be" fields — don't include in match mask (permissive)
            if field_info.get('should_be'):
                continue

            # Always include fixed bits
            if fixed is not None and self._is_binary_string(fixed):
                fixed_val = int(fixed, 2)
                fixed_bits |= (fixed_val << lobit)
                fixed_mask |= (((1 << width) - 1) << lobit)
                full_pattern |= (fixed_val << lobit)
                full_mask |= (((1 << width) - 1) << lobit)
            # Handle partially fixed patterns like "x1" (some bits fixed, some variable)
            elif field_info.get('partial_pattern'):
                partial = field_info['partial_pattern']
                # Skip constraint text like "!= 0000" — these are NOT bit patterns.
                # The constraint is handled by _generate_constraint_guards() at runtime.
                if partial.startswith('!=') or partial.startswith('!'):
                    pass
                else:
                    # Extract only the fixed bits from the partial pattern
                    # Pattern is in MSB-to-LSB order, so reverse for bit position calculation
                    for i, bit_char in enumerate(reversed(partial)):
                        if bit_char in '01':
                            bit_val = int(bit_char)
                            bit_pos = lobit + i
                            fixed_bits |= (bit_val << bit_pos)
                            fixed_mask |= (1 << bit_pos)
                            full_pattern |= (bit_val << bit_pos)
                            full_mask |= (1 << bit_pos)
            # Also include non-operand, non-reserved variable fields
            elif not field_name.startswith('reserved') and field_name not in operand_fields:
                # Try to infer value from encoding name for common fields
                inferred_value = None
                encoding_lower = encoding.name.lower()
                mnemonic_lower = instr.mnemonic.lower()

                if field_name == 'sf':
                    # Size flag: 0=32-bit, 1=64-bit
                    if '_32_' in encoding_lower or encoding_lower.startswith('32_'):
                        inferred_value = 0
                    elif '_64_' in encoding_lower or encoding_lower.startswith('64_'):
                        inferred_value = 1
                elif field_name == 'Q':
                    # Scalar vs Vector: 0=scalar, 1=vector
                    # Only infer when explicitly indicated in encoding name
                    # Do NOT infer Q=1 for all 'asimd' encodings - Q is often a variable parameter
                    if '_q0' in encoding_lower:
                        inferred_value = 0
                    elif '_q1' in encoding_lower:
                        inferred_value = 1
                    elif 'asisd' in encoding_lower:
                        # Scalar SIMD always has Q=0
                        inferred_value = 0
                    # Check for CVT variants: BF1CVTL/F1CVTL (Q=0) vs BF2CVTL/F2CVTL (Q=1)
                    elif mnemonic_lower.endswith('1cvtl') or mnemonic_lower.endswith('1cvt'):
                        inferred_value = 0
                    elif mnemonic_lower.endswith('2cvtl') or mnemonic_lower.endswith('2cvt'):
                        inferred_value = 1
                elif field_name in ['A', 'R']:
                    # Atomic operation acquire/release flags
                    # A=1 for acquire (suffix 'a' or 'al'), R=1 for release (suffix 'l' or 'al')
                    if field_name == 'A':
                        if mnemonic_lower.endswith('a') or mnemonic_lower.endswith('al'):
                            inferred_value = 1
                        else:
                            inferred_value = 0
                    elif field_name == 'R':
                        if mnemonic_lower.endswith('l') or mnemonic_lower.endswith('al'):
                            inferred_value = 1
                        else:
                            inferred_value = 0
                elif field_name == 'U':
                    # Unsigned flag: 0=signed, 1=unsigned
                    if mnemonic_lower.startswith('u'):
                        inferred_value = 1
                    elif mnemonic_lower.startswith('s'):
                        inferred_value = 0
                elif field_name == 'size':
                    # Size encoding for SIMD operations and LD/ST variants
                    if width == 2:  # Common 2-bit size field
                        if '_b_' in encoding_lower or encoding_lower.endswith('_b') or '_i8' in encoding_lower:
                            inferred_value = 0  # 8-bit
                        elif '_h_' in encoding_lower or encoding_lower.endswith('_h') or '_i16' in encoding_lower:
                            inferred_value = 1  # 16-bit
                        elif '_s_' in encoding_lower or encoding_lower.endswith('_s') or '_i32' in encoding_lower:
                            inferred_value = 2  # 32-bit
                        elif '_d_' in encoding_lower or encoding_lower.endswith('_d') or '_i64' in encoding_lower:
                            inferred_value = 3  # 64-bit
                        # Also check for numbered variants
                        elif '_2b' in encoding_lower or '_i2b' in encoding_lower:
                            inferred_value = 0
                        elif '_2h' in encoding_lower or '_i2h' in encoding_lower:
                            inferred_value = 1
                        elif '_2s' in encoding_lower or '_i2s' in encoding_lower:
                            inferred_value = 2
                        elif '_2d' in encoding_lower or '_i2d' in encoding_lower:
                            inferred_value = 3
                        elif '_4b' in encoding_lower or '_i4b' in encoding_lower:
                            inferred_value = 0
                        elif '_4h' in encoding_lower or '_i4h' in encoding_lower:
                            inferred_value = 1
                        elif '_4s' in encoding_lower or '_i4s' in encoding_lower:
                            inferred_value = 2
                        elif '_4d' in encoding_lower or '_i4d' in encoding_lower:
                            inferred_value = 3
                        # LD/ST element size patterns: _B1, _H1, _S1, _D1, etc.
                        elif '_b1' in encoding_lower or '_bx' in encoding_lower:
                            inferred_value = 0
                        elif '_h1' in encoding_lower or '_hx' in encoding_lower:
                            inferred_value = 1
                        elif '_s1' in encoding_lower or '_sx' in encoding_lower:
                            inferred_value = 2
                        elif '_d1' in encoding_lower or '_dx' in encoding_lower:
                            inferred_value = 3
                elif field_name == 'len':
                    # Table lookup length field
                    if '_l1_1' in encoding_lower:
                        inferred_value = 0
                    elif '_l2_2' in encoding_lower:
                        inferred_value = 1
                    elif '_l3_3' in encoding_lower:
                        inferred_value = 2
                    elif '_l4_4' in encoding_lower:
                        inferred_value = 3
                elif field_name == 'L':
                    # Various L flags
                    if '_l0' in encoding_lower or encoding_lower.endswith('_l0'):
                        inferred_value = 0
                    elif '_l1' in encoding_lower or encoding_lower.endswith('_l1'):
                        inferred_value = 1
                    # For store operations, L=0
                    elif mnemonic_lower.startswith('st'):
                        inferred_value = 0
                    # For load operations, L=1
                    elif mnemonic_lower.startswith('ld'):
                        inferred_value = 1
                elif field_name == 'o0':
                    if '_o0' in encoding_lower or encoding_lower.endswith('_o0'):
                        inferred_value = 0
                    elif '_o1' in encoding_lower or encoding_lower.endswith('_o1'):
                        inferred_value = 1
                elif field_name == 'op':
                    # Operation field - try to extract from encoding name
                    if '_op0' in encoding_lower:
                        inferred_value = 0
                    elif '_op1' in encoding_lower:
                        inferred_value = 1
                    elif '_op2' in encoding_lower:
                        inferred_value = 2
                    elif '_op3' in encoding_lower:
                        inferred_value = 3
                elif field_name == 'S':
                    # Set flags bit
                    if encoding_lower.endswith('_s') or '_s_' in encoding_lower:
                        inferred_value = 1
                    # Check mnemonic for 'S' suffix (like ADDS, SUBS)
                    elif mnemonic_lower.endswith('s') and len(mnemonic_lower) > 1:
                        # Be careful not to match mnemonics that naturally end in 's'
                        base_mnem = mnemonic_lower[:-1]
                        if base_mnem in ['add', 'sub', 'and', 'orr', 'eor', 'bic']:
                            inferred_value = 1
                        else:
                            inferred_value = 0
                    else:
                        inferred_value = 0
                elif field_name == 'T' or field_name == 'B':
                    # Top/Bottom bit for instructions like FMLALT vs FMLALB
                    if mnemonic_lower.endswith('t'):
                        inferred_value = 1 if field_name == 'T' else 0
                    elif mnemonic_lower.endswith('b'):
                        inferred_value = 0 if field_name == 'T' else 1
                elif field_name in ['T1', 'T2']:
                    # Top/Bottom bits for instructions with multiple T/B variants (FMLALLBB, FMLALLBT, etc.)
                    if 'bb' in mnemonic_lower:
                        inferred_value = 0
                    elif 'bt' in mnemonic_lower:
                        inferred_value = 1 if field_name == 'T2' else 0
                    elif 'tb' in mnemonic_lower:
                        inferred_value = 1 if field_name == 'T1' else 0
                    elif 'tt' in mnemonic_lower:
                        inferred_value = 1
                elif field_name == 'type' and width == 2:
                    # Type field for different instruction variants
                    # Often indicates register count or operation type
                    if '_1v' in encoding_lower or '_r1' in encoding_lower:
                        inferred_value = 0
                    elif '_2v' in encoding_lower or '_r2' in encoding_lower:
                        inferred_value = 1
                    elif '_3v' in encoding_lower or '_r3' in encoding_lower:
                        inferred_value = 2
                    elif '_4v' in encoding_lower or '_r4' in encoding_lower:
                        inferred_value = 3
                elif field_name == 'mode' and width == 2:
                    # Mode field for immediate shift modes
                    if '_hl' in encoding_lower or 'imm_l_hl' in encoding_lower:
                        inferred_value = 1  # shift left by 0 or 8 (half-word left)
                    elif '_sl' in encoding_lower or 'imm_l_sl' in encoding_lower:
                        inferred_value = 2  # shift left by 8 (single left)
                    elif '_sm' in encoding_lower or 'imm_m_sm' in encoding_lower:
                        inferred_value = 3  # MSL (shift and mask)
                elif field_name == 'cmode' and width == 4:
                    # 4-bit cmode field for SIMD immediate values
                    # Try to infer from encoding name patterns
                    if '_hl' in encoding_lower or 'imm_l_hl' in encoding_lower:
                        # Half-word left shift variants (cmode depends on other factors)
                        pass  # Can't reliably infer 4-bit cmode
                    elif '_sl' in encoding_lower or 'imm_l_sl' in encoding_lower:
                        pass  # Can't reliably infer 4-bit cmode
                elif field_name == 'opc' and width == 2:
                    # Operation code - try to extract from encoding suffix
                    if '_j' in encoding_lower or encoding_lower.endswith('_j'):
                        pass  # Can't infer
                    elif '_g' in encoding_lower or encoding_lower.endswith('_g'):
                        pass  # Can't infer
                    elif '_h' in encoding_lower or encoding_lower.endswith('_h'):
                        pass  # Can't infer
                elif field_name == 'ftype' and width == 2:
                    # Floating point type
                    if '_s' in encoding_lower or encoding_lower.endswith('_s'):
                        inferred_value = 0  # Single precision
                    elif '_d' in encoding_lower or encoding_lower.endswith('_d'):
                        inferred_value = 1  # Double precision
                    elif '_h' in encoding_lower or encoding_lower.endswith('_h'):
                        inferred_value = 3  # Half precision
                elif field_name == 'opcode' and (width == 2 or width == 4):
                    # LD/ST register count variants
                    if '_r1_1v' in encoding_lower or '_r1_' in encoding_lower:
                        inferred_value = 0  # 1 register
                    elif '_r2_2v' in encoding_lower or '_r2_' in encoding_lower:
                        inferred_value = 2  # 2 registers
                    elif '_r3_3v' in encoding_lower or '_r3_' in encoding_lower:
                        inferred_value = 4  # 3 registers
                    elif '_r4_4v' in encoding_lower or '_r4_' in encoding_lower:
                        inferred_value = 6  # 4 registers
                    # Also check patterns like _1v, _2v, _3v, _4v
                    elif '_1v' in encoding_lower:
                        inferred_value = 0
                    elif '_2v' in encoding_lower:
                        inferred_value = 2
                    elif '_3v' in encoding_lower:
                        inferred_value = 4
                    elif '_4v' in encoding_lower:
                        inferred_value = 6
                elif field_name == 'opcode' and width == 3:
                    # 3-bit opcode for LD/ST variants
                    # Check for post-index immediate vs register patterns
                    if '_i1' in encoding_lower or '_i2' in encoding_lower or '_i3' in encoding_lower or '_i4' in encoding_lower:
                        # Immediate post-index (pattern depends on instruction)
                        pass  # Can't reliably infer 3-bit opcode
                    elif '_r1' in encoding_lower or '_r2' in encoding_lower or '_r3' in encoding_lower or '_r4' in encoding_lower:
                        # Register post-index (pattern depends on instruction)
                        pass  # Can't reliably infer 3-bit opcode
                elif field_name in ['Rm', 'rm'] and width == 5:
                    # Register offset field for LD/ST
                    # Check if this is a register-offset variant (_r suffix) or immediate (_i suffix)
                    if '_i1' in encoding_lower or '_i2' in encoding_lower or '_i3' in encoding_lower or '_i4' in encoding_lower or '_i' in encoding_lower:
                        inferred_value = 31  # 0b11111 indicates immediate offset mode
                    # For _r patterns, Rm is variable, don't include in mask

                if inferred_value is not None:
                    full_pattern |= (inferred_value << lobit)
                    full_mask |= (((1 << width) - 1) << lobit)
                    # Also update field_list with the inferred value for the encoder
                    for field in field_list:
                        if field['original_name'] == field_name:
                            field['inferred_value'] = inferred_value
                            break

        return code, field_list, fixed_bits, fixed_mask, full_pattern, full_mask

    def _generate_union(self, class_name: str, struct_names: List[str]) -> List[str]:
        """Generate union containing all encoding structs and raw uint32_t."""
        code = []

        union_name = f"{self._sanitize_struct_name(class_name)}Encoding"
        code.append(f"// Union for {class_name} instruction class")
        code.append(f"union {union_name} {{")

        # Add all struct members
        for struct_name in struct_names:
            member_name = self._struct_to_member_name(struct_name)
            code.append(f"    {struct_name} {member_name};")

        # Add raw uint32_t
        code.append("    uint32_t raw;")
        code.append("};")
        code.append(f"static_assert(sizeof({union_name}) == 4, \"Encoding union must be 32 bits\");")

        return code

    def _generate_instruction_struct(self) -> List[str]:
        """Generate using statement for Instruction class."""
        code = []
        code.append("// Use the veda64::Instruction class")
        code.append("using veda64::Instruction;")
        return code

    def _generate_decode_function(self, class_name: str, encoding_info: List[Dict]) -> List[str]:
        """Generate optimized decode function implementation for an instruction class."""
        code = []

        func_name = f"decode_{self._sanitize_function_name(class_name)}"
        code.append(f"// Decode a {class_name} instruction")
        code.append(f"// Input is in native ARM64 format (as read from memory)")
        code.append(f"std::optional<Instruction> {func_name}(uint32_t insn) {{")

        # Check for duplicate patterns before generating decoder
        pattern_to_encodings = {}
        for info in encoding_info:
            key = (info['full_mask'], info['full_pattern'])
            if key not in pattern_to_encodings:
                pattern_to_encodings[key] = []
            pattern_to_encodings[key].append(info)

        # Define known ARM architectural aliases - these are intentional duplicates
        known_aliases = {
            # Shift operation aliases
            ('ASR', 'ASRV'), ('ASRV', 'ASR'),
            ('LSL', 'LSLV'), ('LSLV', 'LSL'),
            ('LSR', 'LSRV'), ('LSRV', 'LSR'),
            ('ROR', 'RORV'), ('RORV', 'ROR'),

            # Bitfield operation aliases
            ('BFC', 'BFM'), ('BFI', 'BFM'), ('BFXIL', 'BFM'),
            ('SBFIZ', 'SBFM'), ('SBFX', 'SBFM'), ('UBFIZ', 'UBFM'), ('UBFX', 'UBFM'),

            # Logical operation aliases
            ('MVN', 'ORN'), ('ORN', 'MVN'),
            ('TST', 'ANDS'), ('ANDS', 'TST'),
            ('MVN', 'NOT'), ('NOT', 'MVN'),

            # Arithmetic operation aliases
            ('CMP', 'SUBS'), ('SUBS', 'CMP'),
            ('CMN', 'ADDS'), ('ADDS', 'CMN'),
            ('NEG', 'SUB'), ('NEGS', 'SUBS'),
            ('NGC', 'SBC'), ('NGCS', 'SBCS'),

            # Move operation aliases
            ('MOV', 'ORR'), ('ORR', 'MOV'),
            ('MOV', 'ADD'), ('ADD', 'MOV'),

            # Conditional branch aliases (swapped conditions)
            ('CBBGT', 'CBBLT'), ('CBBLT', 'CBBGT'),
            ('CBBGE', 'CBBLE'), ('CBBLE', 'CBBGE'),
            ('CBBHI', 'CBBLO'), ('CBBLO', 'CBBHI'),
            ('CBBHS', 'CBBLS'), ('CBBLS', 'CBBHS'),

            # SIMD immediate aliases
            ('BIC', 'MVNI'), ('MVNI', 'BIC'),
            ('MOVI', 'ORR'), ('ORR', 'MOVI'),
            ('MOVI', 'MVNI'), ('MVNI', 'MOVI'),
            ('MOVI', 'FMOV'), ('FMOV', 'MOVI'),
            ('MVNI', 'SQSHLU'), ('SQSHLU', 'MVNI'),
            ('FCVTZS', 'FMOV'), ('FMOV', 'FCVTZS'),
            ('SCVTF', 'MOVI'), ('MOVI', 'SCVTF'),

            # Extract aliases
            ('ROR', 'EXTR'), ('EXTR', 'ROR'),

            # System instruction aliases
            ('DC', 'SYS'), ('IC', 'SYS'), ('AT', 'SYS'), ('TLBI', 'SYS'),

            # SVE/SME same-operation different-config aliases
            ('AND', 'ANDS'), # predicate versions

            # Load/Store with different semantics but overlapping patterns
            ('LDLAR', 'LDXR'), ('LDXR', 'LDLAR'),
            ('LDLARB', 'LDXRB'), ('LDXRB', 'LDLARB'),
            ('LDLARH', 'LDXRH'), ('LDXRH', 'LDLARH'),
            ('STLLR', 'STXR'), ('STXR', 'STLLR'),
            ('STLLRB', 'STXRB'), ('STXRB', 'STLLRB'),
            ('STLLRH', 'STXRH'), ('STXRH', 'STLLRH'),

            # Prefetch variants
            ('PRFM', 'RPRFM'), ('RPRFM', 'PRFM'),

            # Multiply high signed/unsigned
            ('SMULH', 'UMULH'), ('UMULH', 'SMULH'),
            ('SMULL', 'UMULL'), ('UMULL', 'SMULL'),

            # BFloat16 vs Float SME operations
            ('BFCLAMP', 'FCLAMP'), ('FCLAMP', 'BFCLAMP'),
            ('BFMAX', 'FMAX'), ('FMAX', 'BFMAX'),
            ('BFMAXNM', 'FMAXNM'), ('FMAXNM', 'BFMAXNM'),
            ('BFMIN', 'FMIN'), ('FMIN', 'BFMIN'),
            ('BFMINNM', 'FMINNM'), ('FMINNM', 'BFMINNM'),
            ('BFMUL', 'FMUL'), ('FMUL', 'BFMUL'),
            ('BFMLA', 'FMLA'), ('FMLA', 'BFMLA'),
            ('BFMLS', 'FMLS'), ('FMLS', 'BFMLS'),
            ('BFADD', 'FADD'), ('FADD', 'BFADD'),
            ('BFSUB', 'FSUB'), ('FSUB', 'BFSUB'),
            ('BFSCALE', 'FSCALE'), ('FSCALE', 'BFSCALE'),
        }

        # Report duplicates as warnings but use priority system (first match wins)
        has_duplicates = False
        for (mask, pattern), infos in pattern_to_encodings.items():
            if len(infos) > 1:
                # Check if these are just aliases
                mnemonics = set(info['mnemonic'] for info in infos)
                encoding_names = [info['encoding_name'] for info in infos]

                # Check various alias patterns
                is_alias_group = False

                # Pattern 1: All have the same mnemonic (just different encoding names)
                if len(mnemonics) == 1:
                    is_alias_group = True

                # Pattern 2: Known architectural aliases
                if len(mnemonics) == 2:
                    mnem_tuple = tuple(sorted(mnemonics))
                    if mnem_tuple in known_aliases:
                        is_alias_group = True

                # Pattern 3: MOV_ prefix aliases
                if not is_alias_group:
                    non_mov = [name for name in encoding_names if not name.startswith('MOV_')]
                    mov_aliases = [name for name in encoding_names if name.startswith('MOV_')]
                    if mov_aliases and non_mov:
                        is_alias_group = True

                # Pattern 4: Instruction name prefix aliases (ASR_, BFC_, etc.)
                if not is_alias_group:
                    # Check if encoding names are like "ASR_ASRV_..." and "ASRV_..."
                    base_names = set()
                    for name in encoding_names:
                        # Extract the mnemonic part before the first underscore after the prefix
                        parts = name.split('_')
                        if len(parts) >= 2:
                            base_names.add(parts[0])

                    # If we have prefixed versions, it's an alias group
                    for base in base_names:
                        other_bases = [b for b in base_names if b != base and base.startswith(b[:3])]
                        if other_bases:
                            is_alias_group = True
                            break

                if not is_alias_group:
                    has_duplicates = True
                    print(f"\nWARNING: Duplicate pattern detected in {class_name} class (using priority system):")
                    print(f"  Mask:    0x{mask:08X}")
                    print(f"  Pattern: 0x{pattern:08X}")
                    print(f"  Conflicting encodings (first match will be used):")
                    for i, info in enumerate(infos):
                        priority = "**PRIORITY**" if i == 0 else ""
                        print(f"    - {info['encoding_name']} ({info['mnemonic']}) {priority}")

        # Group encodings by (mask, pattern) pairs for optimal switch generation
        mask_pattern_groups = {}
        for info in encoding_info:
            key = (info['full_mask'], info['full_pattern'])
            if key not in mask_pattern_groups:
                mask_pattern_groups[key] = []
            mask_pattern_groups[key].append(info)

        # Further group by mask to generate efficient switch statements
        mask_groups = {}
        for (mask, pattern), infos in mask_pattern_groups.items():
            if mask not in mask_groups:
                mask_groups[mask] = []
            mask_groups[mask].append({
                'pattern': pattern,
                'encodings': infos
            })

        # Generate optimized decode logic with switches - always use switch for consistency
        for mask, pattern_infos in sorted(mask_groups.items(), reverse=True):
            total_encodings = sum(len(p['encodings']) for p in pattern_infos)
            unique_patterns = len(pattern_infos)
            code.append(f"    // Switch for mask 0x{mask:08X}u ({unique_patterns} pattern{'s' if unique_patterns > 1 else ''}, {total_encodings} encoding{'s' if total_encodings > 1 else ''})")
            code.append(f"    switch (insn & 0x{mask:08X}u) {{")

            for pattern_info in sorted(pattern_infos, key=lambda x: x['pattern']):
                pattern = pattern_info['pattern']
                encodings = pattern_info['encodings']

                if len(encodings) == 1:
                    info = encodings[0]
                    code.append(f"        case 0x{pattern:08X}u: {{ // {info['encoding_name']}")
                    # Add constraint guards for fields with != constraints
                    guards = self._generate_constraint_guards(info)
                    if guards:
                        code.append(f"            {guards}")
                    code.extend(['            ' + line for line in self._generate_operand_extraction(class_name, info, indent=3)])
                    code.append(f"        }}")
                else:
                    # Multiple encodings with identical pattern
                    # Primary is typically the preferred alias; secondaries are base forms.
                    # When primary constraints fail, fall through to first secondary (if any).
                    primary = encodings[0]
                    secondaries = encodings[1:]
                    code.append(f"        case 0x{pattern:08X}u: {{ // {primary['encoding_name']}")
                    for alt in secondaries:
                        code.append(f"            // Also matches: {alt['encoding_name']} ({alt['mnemonic']})")
                    guards = self._generate_constraint_guards(primary)
                    if guards and secondaries:
                        # Extract the boolean condition from "if (COND) break;"
                        guards_cond = guards[4:-8]  # strip 'if (' prefix and ') break;' suffix
                        code.append(f"            if (!({guards_cond})) {{")
                        code.extend(['                ' + line for line in self._generate_operand_extraction(class_name, primary, indent=4)])
                        code.append(f"            }}")
                        # Fallback to first secondary when primary constraint fails
                        fallback = secondaries[0]
                        fallback_guards = self._generate_constraint_guards(fallback)
                        if fallback_guards:
                            code.append(f"            {fallback_guards}")
                        code.extend(['            ' + line for line in self._generate_operand_extraction(class_name, fallback, indent=3)])
                    else:
                        if guards:
                            code.append(f"            {guards}")
                        code.extend(['            ' + line for line in self._generate_operand_extraction(class_name, primary, indent=3)])
                    code.append(f"        }}")

            code.append("        default: break;")
            code.append("    }")
            code.append("")

        code.append("    // No matching encoding found")
        code.append("    return std::nullopt;")
        code.append("}")

        return code

    def _generate_constraint_guards(self, info: Dict) -> str:
        """Generate C++ guard conditions for field constraints like '!= 0000'.

        Returns a C++ 'if (...) break;' statement, or empty string if no constraints.
        These handle fields where certain bit patterns are invalid for the encoding
        (e.g., immh != 0000 for asimdshf instructions).
        """
        guard_set = set()  # Deduplicate identical guards
        for field in info.get('field_list', []):
            # Check both partial_pattern and constraint for != patterns
            for src in [field.get('partial_pattern', ''), field.get('constraint', '')]:
                if not src:
                    continue
                if src.startswith('!= '):
                    forbidden = src[3:].strip()
                    if self._is_binary_string(forbidden):
                        forbidden_val = int(forbidden, 2)
                        mask = (1 << field['width']) - 1
                        guard_set.add(f"((insn >> {field['lobit']}) & 0x{mask:X}) == 0x{forbidden_val:X}")
                elif src == '!= 0':
                    mask = (1 << field['width']) - 1
                    guard_set.add(f"((insn >> {field['lobit']}) & 0x{mask:X}) == 0")
        if guard_set:
            condition = ' || '.join(sorted(guard_set))
            return f"if ({condition}) break;"
        return ''

    def _generate_encode_declaration(self, struct_name: str, encoding_name: str, field_list: List[Dict]) -> List[str]:
        """Generate encode function declaration."""
        code = []

        # Collect non-fixed, non-reserved fields for parameters
        params = []
        for field in field_list:
            if not field['is_fixed'] and not field['name'].startswith('reserved'):
                params.append(field)

        # Generate function signature
        func_name = self._sanitize_function_name(encoding_name)
        param_list = ', '.join([f"{'int32_t' if p.get('is_signed', False) else 'uint32_t'} {p['name']}" for p in params])

        code.append(f"uint32_t encode_{func_name}({param_list});")

        return code

    def _generate_encode_implementation(self, class_name: str, struct_name: str, encoding_name: str, field_list: List[Dict]) -> List[str]:
        """Generate encode function implementation."""
        code = []

        # Collect non-fixed, non-reserved fields for parameters
        # Fields with partial patterns are still parameters (for the variable bits)
        params = []
        for field in field_list:
            if not field['is_fixed'] and not field['name'].startswith('reserved'):
                params.append(field)

        # Generate function signature
        func_name = self._sanitize_function_name(encoding_name)
        param_list = ', '.join([f"{'int32_t' if p.get('is_signed', False) else 'uint32_t'} {p['name']}" for p in params])

        union_name = f"{self._sanitize_struct_name(class_name)}Encoding"
        member_name = self._struct_to_member_name(struct_name)

        code.append(f"uint32_t encode_{func_name}({param_list}) {{")
        code.append(f"    {union_name} insn = {{}};")

        # Set all fields (skip reserved, they default to 0)
        for field in field_list:
            if field['name'].startswith('reserved'):
                # Reserved fields default to 0, skip
                continue
            elif field['is_fixed']:
                # Fixed fields get their fixed value (use binary format)
                fixed_val = int(field['fixed'], 2)
                width = field.get('width', 1)
                code.append(f"    insn.{member_name}.{field['name']} = 0b{fixed_val:0{width}b};")
            else:
                # Variable fields (including partial patterns) get the parameter value directly
                code.append(f"    insn.{member_name}.{field['name']} = {field['name']};")

        # Return native ARM64 instruction format (no byte-swap needed)
        code.append(f"    return insn.raw;")
        code.append("}")

        return code

    def _generate_decode_declaration(self, class_name: str) -> List[str]:
        """Generate decode function declaration."""
        code = []
        func_name = f"decode_{self._sanitize_function_name(class_name)}"
        code.append(f"// Decode a {class_name} instruction from a uint32_t")
        code.append(f"std::optional<Instruction> {func_name}(uint32_t insn);")
        code.append("")
        code.append(f"// Decode a {class_name} instruction from 4 bytes in memory (little-endian)")
        code.append(f"inline std::optional<Instruction> {func_name}(const uint8_t* bytes) {{")
        code.append(f"    return {func_name}(from_bytes(bytes));")
        code.append("}")
        return code

    def _parse_template_for_v2(self, asm_template: str, symbol_map: Dict) -> Optional[List[Dict]]:
        """Parse ASM template for v2 XML-driven extraction.

        Returns list of token dicts: {'sym': str, 'optional': bool, 'in_mem': bool}
        Returns None if the template is too complex for the XML-driven path
        (memory brackets with multiple regs, SVE registers, register lists, etc.).
        """
        import re
        if not asm_template:
            return None

        # Strip mnemonic
        parts = asm_template.strip().split(None, 1)
        if len(parts) < 2:
            return []  # No operands (e.g. NOP, WFE)
        operand_str = parts[1]

        # Reject SVE/SIMD-specific syntax
        if any(x in operand_str for x in ['<Zn', '<Zt', '<Pd', '<Pg', '<Pn', '<Pm',
                                            'ZA', 'ZT0', '{ <Z', '{ <P', '<Za']):
            return None

        # Reject SIMD Vn.T syntax
        if re.search(r'<V[a-z]\d*>\.', operand_str, re.IGNORECASE):
            return None

        tokens = []
        pos = 0
        n = len(operand_str)
        optional_depth = 0
        mem_depth = 0

        while pos < n:
            ch = operand_str[pos]

            if ch == '{':
                optional_depth += 1
                pos += 1
                continue
            elif ch == '}':
                optional_depth -= 1
                pos += 1
                continue
            elif ch == '[':
                mem_depth += 1
                pos += 1
                continue
            elif ch == ']':
                mem_depth -= 1
                if mem_depth < 0:
                    mem_depth = 0
                pos += 1
                # Check for '!' (pre-index writeback)
                if pos < n and operand_str[pos] == '!':
                    pos += 1
                continue
            elif ch == '<':
                # Find closing >
                end = operand_str.find('>', pos)
                if end == -1:
                    return None
                sym_inner = operand_str[pos:end+1]  # e.g. '<Wd|WSP>'
                # Skip if this is a literal text token like '<shift>' that's actually
                # NOT in symbol_map (it's a fixed text like 'LSL')
                # We try to find this in symbol_map
                tokens.append({
                    'sym': sym_inner,
                    'optional': optional_depth > 0,
                    'in_mem': mem_depth > 0,
                })
                pos = end + 1
                continue
            elif ch == '#':
                # '#<field>' pattern — find the <field>
                m = re.match(r'#<(\w+)>', operand_str[pos:])
                if m:
                    sym_inner = f'<{m.group(1)}>'
                    tokens.append({
                        'sym': sym_inner,
                        'optional': optional_depth > 0,
                        'in_mem': mem_depth > 0,
                    })
                    pos += len(m.group(0))
                    continue
            pos += 1

        # Validate: all symbols that are in symbol_map must appear in our token list
        # Also check for memory bracket complexity (more than one register in brackets)
        mem_regs = [t for t in tokens if t['in_mem'] and t['sym'] in symbol_map]
        non_mem_tokens = [t for t in tokens if not t['in_mem']]

        # Fail for complex memory: multiple registers in a single bracket group
        # (e.g. [Xn, Xm] register-offset addressing without immediate)
        if len(mem_regs) > 2:
            return None

        # Return only tokens that are in symbol_map (skip things like LSL fixed text)
        result = [t for t in tokens if t['sym'] in symbol_map]
        return result

    def _emit_operand_v2(self, ind: str, op_type: str, field: str, mem_ref: str,
                          is_optional: bool, in_mem: bool,
                          extras: Dict, field_map: Dict) -> List[str]:
        """Emit C++ code for a single classified operand.

        Returns list of C++ lines.
        """
        code = []

        if op_type == 'reg64':
            if in_mem:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::MemoryBase, {mem_ref}, true));")
            else:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, {mem_ref}, true));")

        elif op_type == 'reg32':
            if in_mem:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::MemoryBase, {mem_ref}, false));")
            else:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, {mem_ref}, false));")

        elif op_type == 'reg_sp64':
            if in_mem:
                code.append(f"{ind}{{")
                code.append(f"{ind}    Operand op(OperandType::MemoryBase, {mem_ref}, true); op.is_sp = true;")
                code.append(f"{ind}    result.operands.push_back(op);")
                code.append(f"{ind}}}")
            else:
                code.append(f"{ind}{{ Operand op(OperandType::Register, {mem_ref}, true); op.is_sp = true; result.operands.push_back(op); }}")

        elif op_type == 'reg_sp32':
            if in_mem:
                code.append(f"{ind}{{")
                code.append(f"{ind}    Operand op(OperandType::MemoryBase, {mem_ref}, false); op.is_sp = true;")
                code.append(f"{ind}    result.operands.push_back(op);")
                code.append(f"{ind}}}")
            else:
                code.append(f"{ind}{{ Operand op(OperandType::Register, {mem_ref}, false); op.is_sp = true; result.operands.push_back(op); }}")

        elif op_type == 'imm_unsigned':
            if in_mem:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::MemoryOffset, {mem_ref}, true));")
            elif field == 'imm4' and 'pattern' in field_map and not field_map['pattern'].get('is_fixed', True):
                # SVE MUL multiplier: display value = imm4+1, default = MUL #1 (imm4=0)
                code.append(f"{ind}if ({mem_ref} != 0)")
                code.append(f"{ind}    result.operands.push_back(Operand(OperandType::SVEMulImm, {mem_ref} + 1u, true));")
            elif is_optional:
                default_val = extras.get('default_val', 0)
                code.append(f"{ind}if ({mem_ref} != {default_val}) result.operands.push_back(Operand(OperandType::Immediate, {mem_ref}, true));")
            else:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, {mem_ref}, true));")

        elif op_type == 'imm_signed':
            # Determine field width from field_map for sign extension
            fw = field_map.get(field, {}).get('width', 0)
            already_signed = field_map.get(field, {}).get('is_signed', False)
            if fw > 0:
                sign_bit = fw - 1
                if in_mem:
                    code.append(f"{ind}{{")
                    if already_signed:
                        code.append(f"{ind}    int32_t soff = (int32_t){mem_ref};")
                    else:
                        code.append(f"{ind}    int32_t soff = (int32_t)(({mem_ref} ^ (1u << {sign_bit})) - (1u << {sign_bit}));")
                    code.append(f"{ind}    result.operands.push_back(Operand(OperandType::MemoryOffset, (uint32_t)soff, true));")
                    code.append(f"{ind}}}")
                else:
                    code.append(f"{ind}{{")
                    if already_signed:
                        code.append(f"{ind}    int32_t simm = (int32_t){mem_ref};")
                    else:
                        code.append(f"{ind}    int32_t simm = (int32_t)(({mem_ref} ^ (1u << {sign_bit})) - (1u << {sign_bit}));")
                    code.append(f"{ind}    result.operands.push_back(Operand(OperandType::SignedImmediate, (uint32_t)simm, true));")
                    code.append(f"{ind}}}")
            else:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, {mem_ref}, true));")

        elif op_type == 'label':
            # Use OperandType::Relative for PC-relative branch targets
            shift = extras.get('shift', 0)
            fw = field_map.get(field, {}).get('width', 0)
            if fw > 0 and shift > 0:
                code.append(f"{ind}{{")
                code.append(f"{ind}    int32_t loff = static_cast<int32_t>({mem_ref} << {32 - fw}) >> {32 - fw};")
                code.append(f"{ind}    loff <<= {shift};")
                code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(loff), true));")
                code.append(f"{ind}}}")
            elif fw > 0:
                code.append(f"{ind}{{")
                code.append(f"{ind}    int32_t loff = static_cast<int32_t>({mem_ref} << {32 - fw}) >> {32 - fw};")
                code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(loff), true));")
                code.append(f"{ind}}}")
            else:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Relative, {mem_ref}, true));")

        elif op_type == 'condition':
            # Store in result.condition so normalization (CSINC→CINC etc.) works
            code.append(f"{ind}result.condition = static_cast<Condition>({mem_ref});")

        elif op_type == 'condition_table':
            # Set instruction condition instead of adding an operand
            code.append(f"{ind}result.condition = static_cast<Condition>({mem_ref});")

        elif op_type == 'shift_table':
            table = extras.get('table', {})
            # Find the non-zero/non-default entries — emit shift when field != 0
            # For ADD-style optional shift: sh=0→LSL#0 (default), sh=1→LSL#12
            if is_optional and len(table) == 2:
                # Find the non-zero entry's shift amount
                for bitval, sym_val in table.items():
                    if bitval.strip('0') and sym_val:
                        # e.g. '1' → 'LSL #12'
                        import re as _re
                        m = _re.search(r'(\d+)$', sym_val)
                        if m:
                            shift_amount = int(m.group(1))
                            code.append(f"{ind}if ({mem_ref} != 0) result.operands.push_back(Operand(OperandType::Shift, {shift_amount}, true));")
                            break
            else:
                # Generate a switch for the table
                code.append(f"{ind}switch ({mem_ref}) {{")
                for bitval, sym_val in sorted(table.items()):
                    import re as _re
                    # Parse "LSL #12" → shift_type=0, amount=12
                    m = _re.match(r'(lsl|lsr|asr|ror)\s*#(\d+)', sym_val.lower())
                    if m:
                        stype_map = {'lsl': 0, 'lsr': 1, 'asr': 2, 'ror': 3}
                        stype = stype_map.get(m.group(1), 0)
                        samount = int(m.group(2))
                        code.append(f"{ind}    case {bitval}: result.operands.push_back(Operand(OperandType::Shift, {samount}, true)); break;")
                    else:
                        code.append(f"{ind}    // Unhandled table entry: {bitval} -> {sym_val}")
                code.append(f"{ind}}}")

        elif op_type == 'extend_table':
            # Emit extend operand using value table
            code.append(f"{ind}// extend_table for {field} - unimplemented in v2")

        elif op_type == 'barrier_table':
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Barrier, {mem_ref}, false));")
            code.append(f"{ind}result.operands.back().barrier = barrier_from_value({mem_ref});")

        elif op_type == 'option_table':
            # SVE pattern field → use Pattern operand type
            if field == 'pattern':
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Pattern, {mem_ref}, true));")
                code.append(f"{ind}result.operands.back().pattern = pattern_from_value({mem_ref});")
            else:
                # Generic option/prefetch
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, {mem_ref}, false));")

        return code

    def _generate_undef_checks(self, encoding_info: Dict, member_name: str, indent: int = 2) -> List[str]:
        """Parse decode_ps for 'if FIELD == VALUE then EndOfDecode(Decode_UNDEF)' and emit early returns."""
        import re
        decode_ps = encoding_info.get('decode_ps', '')
        if not decode_ps:
            return []

        ind = "    " * indent
        code = []

        # Build set of available (non-fixed) field names for this encoding
        field_names = set()
        for f in encoding_info.get('field_list', []):
            if not f['is_fixed']:
                field_names.add(f['original_name'])

        # Build map of fixed field values (original_name → binary string)
        fixed_vals = {}
        for f in encoding_info.get('field_list', []):
            if f['is_fixed'] and 'fixed' in f:
                fixed_vals[f['original_name']] = f['fixed']

        def _is_guarded_by_false_condition(match_pos):
            """Check if a UNDEF at match_pos is inside an outer 'if' whose condition
            is provably false given the encoding's fixed bits.
            E.g., 'if cmode::op == '11111' then ... if Q == '0' then UNDEF'
            where op is fixed to 0, so cmode::op can never be '11111'."""
            text_before = decode_ps[:match_pos]
            # Find enclosing 'if EXPR then' blocks
            for outer in re.finditer(r"if\s+([\w:]+)\s*(==|!=)\s*'([01]+)'\s+then", text_before):
                outer_end = outer.end()
                # Check if UNDEF is still inside this if block (not past its 'end;')
                remaining = decode_ps[outer_end:match_pos]
                depth = 1
                for nested in re.finditer(r'\bif\b.*?\bthen\b|\bend;', remaining):
                    tok = nested.group()
                    if 'then' in tok and tok.strip().startswith('if'):
                        depth += 1
                    elif 'end;' in tok:
                        depth -= 1
                        if depth <= 0:
                            break
                if depth <= 0:
                    continue  # Outer if was closed before our UNDEF

                # UNDEF is inside this outer if — check if condition is provably false
                cond_expr = outer.group(1)   # e.g., 'cmode::op' or 'Q'
                cond_op = outer.group(2)     # '==' or '!='
                cond_bits = outer.group(3)   # e.g., '11111'

                # Handle concatenated fields (split on '::')
                parts = cond_expr.split('::')
                concat_bits = ''
                all_fixed = True
                for part in parts:
                    if part in fixed_vals:
                        concat_bits += fixed_vals[part]
                    else:
                        all_fixed = False
                        break

                if all_fixed:
                    if cond_op == '==' and concat_bits != cond_bits:
                        return True   # Outer condition is always false
                    if cond_op == '!=' and concat_bits == cond_bits:
                        return True   # Outer condition is always false
            return False

        # Match simple: if FIELD == 'BITS' then EndOfDecode(Decode_UNDEF); end;
        for m in re.finditer(r"if\s+(\w+)\s*==\s*'([01]+)'\s+then\s+EndOfDecode\(Decode_UNDEF\)", decode_ps):
            field, bits = m.group(1), m.group(2)
            if field in field_names:
                if _is_guarded_by_false_condition(m.start()):
                    continue  # Skip — outer condition is always false for this encoding
                val = int(bits, 2)
                code.append(f"{ind}if (enc.{member_name}.{field} == {val}u) return std::nullopt;")

        # Match simple: if FIELD != 'BITS' then EndOfDecode(Decode_UNDEF); end;
        # (equivalent to: only BITS is valid)
        for m in re.finditer(r"if\s+(\w+)\s*!=\s*'([01]+)'\s+then\s+EndOfDecode\(Decode_UNDEF\)", decode_ps):
            field, bits = m.group(1), m.group(2)
            if field in field_names:
                if _is_guarded_by_false_condition(m.start()):
                    continue
                val = int(bits, 2)
                code.append(f"{ind}if (enc.{member_name}.{field} != {val}u) return std::nullopt;")

        # Match: if sf == '0' && N != '0' (and similar two-field AND conditions)
        for m in re.finditer(r"if\s+(\w+)\s*(==|!=)\s*'([01]+)'\s*&&\s*(\w+)\s*(==|!=)\s*'([01]+)'\s+then\s+EndOfDecode\(Decode_UNDEF\)", decode_ps):
            f1, op1, b1, f2, op2, b2 = m.group(1), m.group(2), m.group(3), m.group(4), m.group(5), m.group(6)
            if f1 in field_names and f2 in field_names:
                if _is_guarded_by_false_condition(m.start()):
                    continue
                v1, v2 = int(b1, 2), int(b2, 2)
                c1 = f"enc.{member_name}.{f1} {'==' if op1 == '==' else '!='} {v1}u"
                c2 = f"enc.{member_name}.{f2} {'==' if op2 == '==' else '!='} {v2}u"
                code.append(f"{ind}if ({c1} && {c2}) return std::nullopt;")

        return code

    def _generate_operand_extraction_v2(self, class_name: str, encoding_info: Dict, indent: int = 2) -> Optional[List[str]]:
        """XML-driven operand extraction. Returns None to signal fallback to heuristic path.

        This function implements the 'perfect generator' approach: it uses the
        symbol_map (from <explanations>) and decode_ps (from <pstext section=Decode>)
        stored in encoding_info to derive operand extraction code directly from XML,
        without any instruction-specific heuristics.
        """
        import re

        symbol_map = encoding_info.get('symbol_map', {})
        decode_ps = encoding_info.get('decode_ps', '')
        asm_template = encoding_info.get('asm_template', '')

        # Need symbol map to proceed
        if not symbol_map:
            return None

        # Reject SVE/SME/SIMD — handled by existing specialised code
        encoding_name = encoding_info.get('encoding_name', '').lower()
        if any(x in encoding_name for x in ['_z_', '_p_', 'sve', 'sme', 'mortlach',
                                              'asimd', 'float', 'fpsimd', 'advsimd',
                                              'asimdsame', 'asimdelem', 'asimdshf',
                                              'asimddiff', 'asimdmiscfp', 'asimdmisc',
                                              'asisdelem', 'miscbranch']):
            return None

        # Reject LDP/STP and complex load/store pairs
        if any(x in encoding_name for x in ['ldstpair', 'ldstnapair']):
            return None

        # Reject tag memory instructions (STG/ST2G/STZG/STZ2G/LDG) — imm9 needs ×16 scaling
        if 'ldsttags' in encoding_name:
            return None

        mnemonic = encoding_info['mnemonic'] or 'UNKNOWN'

        # SYS alias encodings: use decode_sys_alias() — reject v2 so heuristic handles it
        _sys_alias_enc = {
            'tlbi_sys_cr_systeminstrs', 'dc_sys_cr_systeminstrs',
            'at_sys_cr_systeminstrs', 'ic_sys_cr_systeminstrs',
            'gic_sys_cr_systeminstrs', 'brb_sys_cr_systeminstrs',
            'cfp_sys_cr_systeminstrs', 'apas_sys_cr_systeminstrs',
            'cpp_sys_cr_systeminstrs', 'dvp_sys_cr_systeminstrs',
        }
        if encoding_name in _sys_alias_enc:
            return None

        # Reject RET — has implicit default register (X30) that v2 doesn't handle
        if mnemonic == 'RET':
            return None

        # Reject templates with | (alternatives pattern like (<option>|#<imm>))
        # but NOT |SP in register names like <Xn|SP>
        if '|' in asm_template:
            import re as _re
            stripped = _re.sub(r'<[^>]+>', 'X', asm_template)
            if '|' in stripped:
                return None
        struct_name = encoding_info['struct_name']
        member_name = self._struct_to_member_name(struct_name)
        union_name = f"{self._sanitize_struct_name(class_name)}Encoding"

        # Build field width map for sign extension
        field_map = {}
        for f in encoding_info.get('field_list', []):
            field_map[f['original_name']] = f

        decode_ops = self._parse_asl_decode_ops(decode_ps)

        # Classify all symbols — fail if any is unclassifiable or has a sub-field ref
        classified = {}
        for sym_text, sym_info in symbol_map.items():
            field_name = sym_info.get('field', '')
            # Reject bit-range sub-field references like 'op2[1:0]' or 'op2[0]'
            if '[' in field_name or ':' in field_name:
                return None
            result = self._classify_symbol(sym_text, sym_info, decode_ops)
            if result is None:
                return None
            classified[sym_text] = result

        # Reject if any classified type needs special handling we don't support yet
        for sym_text, (op_type, field, extras) in classified.items():
            if op_type in ('extend_table', 'system'):
                return None

        # Reject when two symbols map to the SAME field (DMB <option>|<imm> pattern)
        # This means the template has alternatives (A|B) which we can't handle generically
        seen_fields = {}
        for sym_text, (op_type, field, extras) in classified.items():
            if field in seen_fields:
                return None
            seen_fields[field] = sym_text

        # Classify the <cond> token as condition_table if it has EQ/NE/etc. in its value table
        for sym_text, sym_info in symbol_map.items():
            vt = sym_info.get('value_table', {})
            if any(v in ('EQ', 'NE', 'CS', 'MI', 'PL', 'VS', 'HI', 'GE', 'GT', 'LE', 'AL')
                   for v in vt.values()):
                field_name = sym_info.get('field', '')
                classified[sym_text] = ('condition_table', field_name, {})

        # Parse template for ordered token list
        template_tokens = self._parse_template_for_v2(asm_template, symbol_map)
        if template_tokens is None:
            return None

        # Detect memory bracket pattern — check if any token is in_mem
        has_mem = any(t['in_mem'] for t in template_tokens)

        # For memory instructions: only handle simple [Xn|SP] base + immediate offset patterns
        # Count memory registers vs non-memory
        mem_reg_tokens = [t for t in template_tokens
                          if t['in_mem'] and classified.get(t['sym'], (None,))[0] in
                          ('reg64', 'reg32', 'reg_sp64', 'reg_sp32')]

        # Only handle: no-memory, or simple [Rn] (base only), or [Rn, #imm] (base+offset)
        # For register-offset [Rn, Rm] or more complex → fall back
        if has_mem and len(mem_reg_tokens) > 1:
            return None

        # Build the code
        ind = "    " * indent
        code = []
        code.append(f"{ind}Instruction result(Mnemonic::{mnemonic}, insn);")
        code.append(f"{ind}{union_name} enc = {{}};")
        code.append(f"{ind}enc.raw = insn;")
        code.extend(self._generate_undef_checks(encoding_info, member_name, indent))

        # Find condition_table symbols NOT in template tokens (they're part of mnemonic suffix)
        token_syms = {t['sym'] for t in template_tokens}
        for sym_text, (op_type, field, extras) in classified.items():
            if op_type == 'condition_table' and sym_text not in token_syms:
                mem_ref = f"enc.{member_name}.{field}"
                code.append(f"{ind}result.condition = static_cast<Condition>({mem_ref});")

        # Collect memory tokens separately to emit as a combined operand
        mem_base_tok = None   # (op_type, field, mem_ref, is_sp)
        mem_imm_tok = None    # (op_type, field, mem_ref, is_optional)
        mem_emitted = False   # True once the memory operand has been flushed
        saw_mem = False       # True once we've seen any in_mem token

        def flush_mem_operand():
            """Emit the collected memory operand into code; returns True on success."""
            nonlocal mem_emitted
            if mem_emitted or mem_base_tok is None:
                return True
            _, base_field, base_ref, is_sp = mem_base_tok
            sp_suffix = " op.is_sp = true;" if is_sp else ""
            # (memory emission code is below — replicated from end-of-loop handler)
            return False  # Signal to caller to use the regular emission block

        for token in template_tokens:
            sym_text = token['sym']
            is_optional = token['optional']
            in_mem = token['in_mem']

            if sym_text not in classified:
                return None

            op_type, field, extras = classified[sym_text]
            mem_ref = f"enc.{member_name}.{field}"

            if in_mem:
                saw_mem = True
                if op_type in ('reg64', 'reg32', 'reg_sp64', 'reg_sp32'):
                    is_sp = op_type in ('reg_sp64', 'reg_sp32')
                    mem_base_tok = (op_type, field, mem_ref, is_sp)
                elif op_type in ('imm_unsigned', 'imm_signed'):
                    mem_imm_tok = (op_type, field, mem_ref, is_optional)
                else:
                    return None  # Unexpected memory token type
                continue  # Will emit combined below

            # If we've finished collecting memory tokens (saw_mem=True and now not in_mem),
            # flush the memory operand before emitting this non-memory operand.
            # This handles post-index: LDR Wt, [Xn|SP], #simm → emit [Xn] before #simm.
            if saw_mem and not mem_emitted and mem_base_tok is not None:
                mem_emitted = True
                # (emit combined memory operand inline — same logic as after-loop block)
                _b_type, _b_field, _b_ref, _b_sp = mem_base_tok
                _sp_sfx = " _op.is_sp = true;" if _b_sp else ""
                if mem_imm_tok is not None:
                    _imm_type, _imm_field, _imm_ref, _imm_opt = mem_imm_tok
                    _fw = field_map.get(_imm_field, {}).get('width', 0)
                    _size_field = field_map.get('size', {})
                    _size_fixed = _size_field.get('fixed')
                    if _imm_type == 'imm_signed':
                        _is_signed = field_map.get(_imm_field, {}).get('is_signed', False)
                        if _fw > 0 and not _is_signed:
                            code.append(f"{ind}{{ int32_t _soff = static_cast<int32_t>(({_imm_ref} ^ (1u << {_fw-1})) - (1u << {_fw-1}));")
                            code.append(f"{ind}    if (_soff == 0) result.operands.push_back(Operand(OperandType::MemoryBase, {_b_ref}, (int32_t)0));")
                            code.append(f"{ind}    else result.operands.push_back(Operand(OperandType::MemoryOffset, {_b_ref}, _soff));{_sp_sfx} }}")
                        else:
                            code.append(f"{ind}{{ int32_t _soff = (int32_t){_imm_ref};")
                            code.append(f"{ind}    if (_soff == 0) result.operands.push_back(Operand(OperandType::MemoryBase, {_b_ref}, (int32_t)0));")
                            code.append(f"{ind}    else result.operands.push_back(Operand(OperandType::MemoryOffset, {_b_ref}, _soff)); }}")
                    else:
                        if _size_fixed is not None:
                            _scale = int(_size_fixed, 2)
                            if _scale > 0:
                                _scaled = f"((int32_t)((uint32_t){_imm_ref} << {_scale}))"
                            else:
                                _scaled = f"(int32_t){_imm_ref}"
                        elif 'size' in field_map and not field_map['size'].get('is_fixed', True):
                            _sr = f"enc.{member_name}.size"
                            _scaled = f"((int32_t)((uint32_t){_imm_ref} << {_sr}))"
                        else:
                            _scaled = f"(int32_t){_imm_ref}"
                        if _imm_opt:
                            code.append(f"{ind}if ({_imm_ref} == 0) result.operands.push_back(Operand(OperandType::MemoryBase, {_b_ref}, (int32_t)0));")
                            code.append(f"{ind}else result.operands.push_back(Operand(OperandType::MemoryOffset, {_b_ref}, {_scaled}));")
                        else:
                            code.append(f"{ind}{{ int32_t _uoff = {_scaled};")
                            code.append(f"{ind}    if (_uoff == 0) result.operands.push_back(Operand(OperandType::MemoryBase, {_b_ref}, (int32_t)0));")
                            code.append(f"{ind}    else result.operands.push_back(Operand(OperandType::MemoryOffset, {_b_ref}, _uoff)); }}")
                else:
                    if _b_sp:
                        code.append(f"{ind}{{ Operand _op(OperandType::MemoryBase, {_b_ref}, (int32_t)0);{_sp_sfx} result.operands.push_back(_op); }}")
                    else:
                        code.append(f"{ind}result.operands.push_back(Operand(OperandType::MemoryBase, {_b_ref}, (int32_t)0));")

            lines = self._emit_operand_v2(ind, op_type, field, mem_ref,
                                           is_optional, in_mem, extras, field_map)
            if not lines:
                return None
            code.extend(lines)

        # Emit combined memory operand (uses correct (t, base, int32_t off) constructor)
        # Only if not already emitted inline (post-index case handled in loop above)
        if mem_base_tok is not None and not mem_emitted:
            _, base_field, base_ref, is_sp = mem_base_tok
            sp_suffix = " op.is_sp = true;" if is_sp else ""
            if mem_imm_tok is None:
                # [Rn] — base only
                if is_sp:
                    code.append(f"{ind}{{ Operand op(OperandType::MemoryBase, {base_ref}, (int32_t)0);{sp_suffix} result.operands.push_back(op); }}")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::MemoryBase, {base_ref}, (int32_t)0));")
            else:
                imm_type, imm_field, imm_ref, imm_optional = mem_imm_tok
                fw = field_map.get(imm_field, {}).get('width', 0)
                if imm_type == 'imm_signed' and fw > 0:
                    sign_bit = fw - 1
                    # Check if struct field is already declared as signed (int32_t bitfield)
                    if self._is_signed_field(imm_field):
                        soff_expr = f"(int32_t)({imm_ref})"
                    else:
                        soff_expr = f"(int32_t)(({imm_ref} ^ (1u << {sign_bit})) - (1u << {sign_bit}))"
                    if is_sp:
                        code.append(f"{ind}{{ int32_t soff = {soff_expr}; Operand op(OperandType::MemoryOffset, {base_ref}, soff);{sp_suffix} result.operands.push_back(op); }}")
                    else:
                        code.append(f"{ind}{{ int32_t soff = {soff_expr}; result.operands.push_back(Operand(OperandType::MemoryOffset, {base_ref}, soff)); }}")
                else:
                    # Unsigned offset — may need scaling by access size (imm12 * size_bytes)
                    # Determine scale from 'size' field: scale_shift = UInt(size) (ARM convention)
                    size_field = field_map.get('size', {})
                    size_fixed = size_field.get('fixed')  # binary string like '10' for word
                    if size_fixed is not None:
                        scale_shift = int(size_fixed, 2)  # e.g. '10' -> 2 -> imm12 << 2
                        if scale_shift > 0:
                            scaled_imm = f"((int32_t)((uint32_t){imm_ref} << {scale_shift}))"
                        else:
                            scaled_imm = f"(int32_t){imm_ref}"
                    elif 'size' in field_map and not field_map['size'].get('is_fixed', True):
                        # Variable size field — compute scale at runtime
                        size_ref = f"enc.{member_name}.size"
                        scaled_imm = f"((int32_t)((uint32_t){imm_ref} << {size_ref}))"
                    else:
                        scaled_imm = f"(int32_t){imm_ref}"  # No scaling (byte access)
                    if imm_optional:
                        if is_sp:
                            code.append(f"{ind}if ({imm_ref} != 0) {{ Operand op(OperandType::MemoryOffset, {base_ref}, {scaled_imm});{sp_suffix} result.operands.push_back(op); }}")
                            code.append(f"{ind}else {{ Operand op(OperandType::MemoryBase, {base_ref}, (int32_t)0);{sp_suffix} result.operands.push_back(op); }}")
                        else:
                            code.append(f"{ind}if ({imm_ref} != 0) result.operands.push_back(Operand(OperandType::MemoryOffset, {base_ref}, {scaled_imm}));")
                            code.append(f"{ind}else result.operands.push_back(Operand(OperandType::MemoryBase, {base_ref}, (int32_t)0));")
                    else:
                        if is_sp:
                            code.append(f"{ind}{{ Operand op(OperandType::MemoryOffset, {base_ref}, {scaled_imm});{sp_suffix} result.operands.push_back(op); }}")
                        else:
                            code.append(f"{ind}result.operands.push_back(Operand(OperandType::MemoryOffset, {base_ref}, {scaled_imm}));")

        code.append(f"{ind}return result;")
        return code

    def _generate_operand_extraction(self, class_name: str, encoding_info: Dict, indent: int = 2) -> List[str]:
        """Generate code to extract operands from raw instruction using struct fields."""

        # Try XML-driven path first (Phase 2 — perfect generator)
        v2_code = self._generate_operand_extraction_v2(class_name, encoding_info, indent)
        if v2_code is not None:
            return v2_code

        code = []
        ind = "    " * indent

        # Get struct information
        mnemonic = encoding_info['mnemonic'] or 'UNKNOWN'
        struct_name = encoding_info['struct_name']
        encoding_name = encoding_info.get('encoding_name', '').lower()
        member_name = self._struct_to_member_name(struct_name)
        union_name = f"{self._sanitize_struct_name(class_name)}Encoding"

        # Create Instruction object
        code.append(f"{ind}Instruction result(Mnemonic::{mnemonic}, insn);")

        # Build field map
        field_map = {}
        has_sf = False
        for field in encoding_info.get('field_list', []):
            field_map[field['original_name']] = field
            if field['original_name'] == 'sf' and not field['is_fixed']:
                has_sf = True

        # Determine instruction type for special handling
        is_branch = mnemonic in ['B', 'BL', 'CBZ', 'CBNZ', 'TBZ', 'TBNZ', 'BC', 'RETAASPPC', 'RETABSPPC']
        is_ret = mnemonic == 'RET'
        is_hint = mnemonic == 'HINT'
        is_msr_pstate = 'pstate' in encoding_name and mnemonic == 'MSR' and 'si' in encoding_name
        is_movz = mnemonic == 'MOVZ'
        is_movn = mnemonic == 'MOVN'
        is_movk = mnemonic == 'MOVK'
        is_add_sub = mnemonic in ['ADD', 'ADDS', 'SUB', 'SUBS']
        is_ldp_stp = 'ldstpair' in encoding_name or 'ldstnapair' in encoding_name or 'ldp' in encoding_name or 'stp' in encoding_name or 'ldnp' in encoding_name or 'stnp' in encoding_name

        # Determine if this is a load/store with memory addressing
        is_load_store = any(x in encoding_name for x in ['ldst', 'ldap', 'stl', 'ldur', 'stur',
                                                          'ldr_', 'str_', 'ldnp', 'stnp', 'ldtr', 'sttr',
                                                          'ldrb', 'strb', 'ldrh', 'strh',
                                                          'comswap', 'memop'])
        is_load_store = is_load_store and not is_ldp_stp  # Handle LDP/STP separately

        # Determine addressing mode
        addr_mode = None
        if is_load_store:
            if '_immpost' in encoding_name or '_post' in encoding_name:
                addr_mode = 'post_index'
            elif '_immpre' in encoding_name or '_pre' in encoding_name:
                addr_mode = 'pre_index'
            elif '_regoff' in encoding_name:
                addr_mode = 'reg_offset'
            else:
                addr_mode = 'offset'

        # Special case: HINT aliases - complete list from ARM64 XML
        if is_hint:
            code.append(f"{ind}// HINT instruction - decode to alias based on CRm:op2")
            code.append(f"{ind}uint32_t CRm = (insn >> 8) & 0xF;")
            code.append(f"{ind}uint32_t op2 = (insn >> 5) & 0x7;")
            code.append(f"{ind}uint32_t imm7 = (CRm << 3) | op2;")
            code.append(f"{ind}switch (imm7) {{")
            code.append(f"{ind}    case 0: result.mnemonic = Mnemonic::NOP; break;")
            code.append(f"{ind}    case 1: result.mnemonic = Mnemonic::YIELD; break;")
            code.append(f"{ind}    case 2: result.mnemonic = Mnemonic::WFE; break;")
            code.append(f"{ind}    case 3: result.mnemonic = Mnemonic::WFI; break;")
            code.append(f"{ind}    case 4: result.mnemonic = Mnemonic::SEV; break;")
            code.append(f"{ind}    case 5: result.mnemonic = Mnemonic::SEVL; break;")
            code.append(f"{ind}    case 6: result.mnemonic = Mnemonic::DGH; break;")
            code.append(f"{ind}    case 7: result.mnemonic = Mnemonic::XPACLRI; break;")
            code.append(f"{ind}    case 8: result.mnemonic = Mnemonic::PACIA1716; break;")
            code.append(f"{ind}    case 10: result.mnemonic = Mnemonic::PACIB1716; break;")
            code.append(f"{ind}    case 12: result.mnemonic = Mnemonic::AUTIA1716; break;")
            code.append(f"{ind}    case 14: result.mnemonic = Mnemonic::AUTIB1716; break;")
            code.append(f"{ind}    case 16: result.mnemonic = Mnemonic::ESB; break;")
            code.append(f"{ind}    case 17: result.mnemonic = Mnemonic::PSB; result.operands.push_back(Operand(OperandType::FixedSym, 0, false)); break;  // csync")
            code.append(f"{ind}    case 18: result.mnemonic = Mnemonic::TSB; result.operands.push_back(Operand(OperandType::FixedSym, 0, false)); break;  // csync")
            code.append(f"{ind}    case 19: result.mnemonic = Mnemonic::GCSB; result.operands.push_back(Operand(OperandType::FixedSym, 1, false)); break; // dsync")
            code.append(f"{ind}    case 20: result.mnemonic = Mnemonic::CSDB; break;")
            code.append(f"{ind}    case 22: result.mnemonic = Mnemonic::CLRBHB; break;")
            code.append(f"{ind}    case 24: result.mnemonic = Mnemonic::PACIAZ; break;")
            code.append(f"{ind}    case 25: result.mnemonic = Mnemonic::PACIASP; break;")
            code.append(f"{ind}    case 26: result.mnemonic = Mnemonic::PACIBZ; break;")
            code.append(f"{ind}    case 27: result.mnemonic = Mnemonic::PACIBSP; break;")
            code.append(f"{ind}    case 28: result.mnemonic = Mnemonic::AUTIAZ; break;")
            code.append(f"{ind}    case 29: result.mnemonic = Mnemonic::AUTIASP; break;")
            code.append(f"{ind}    case 30: result.mnemonic = Mnemonic::AUTIBZ; break;")
            code.append(f"{ind}    case 31: result.mnemonic = Mnemonic::AUTIBSP; break;")
            code.append(f"{ind}    default: break; // Keep HINT mnemonic")
            code.append(f"{ind}}}")
            code.append(f"{ind}return result;")
            return code

        # Special case: RET — only show register when Rn != X30 (X30 is default)
        if is_ret:
            _rn_field = field_map.get('Rn', {}).get('name', 'Rn')
            code.append(f"{ind}{union_name} enc = {{}}; enc.raw = insn;")
            code.append(f"{ind}if (enc.{member_name}.{_rn_field} != 30)")
            code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{_rn_field}, true));")
            code.append(f"{ind}return result;")
            return code

        # Special case: barrier hint instructions with fixed symbolic operands
        if mnemonic in ('PSB', 'TSB'):
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::FixedSym, 0u, false)); // csync")
            code.append(f"{ind}return result;")
            return code
        if mnemonic == 'GCSB':
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::FixedSym, 1u, false)); // dsync")
            code.append(f"{ind}return result;")
            return code

        # Special case: SYS instruction aliases (TLBI/DC/AT/IC/GIC/BRB/CFP/APAS)
        _sys_alias_encodings = {
            'tlbi_sys_cr_systeminstrs', 'dc_sys_cr_systeminstrs',
            'at_sys_cr_systeminstrs', 'ic_sys_cr_systeminstrs',
            'gic_sys_cr_systeminstrs', 'brb_sys_cr_systeminstrs',
            'cfp_sys_cr_systeminstrs', 'apas_sys_cr_systeminstrs',
            'cpp_sys_cr_systeminstrs', 'dvp_sys_cr_systeminstrs',
        }
        is_sys_alias = encoding_name in _sys_alias_encodings
        if is_sys_alias:
            code.append(f"#if !defined(VEDA64_NO_STRINGS) && !defined(VEDA64_NO_MNEMONIC_OPERANDS)")
            code.append(f"{ind}if (decode_sys_alias(insn, result)) return result;")
            code.append(f"#endif")
            code.append(f"{ind}// Fallback: unknown SYS alias - emit raw fields")
            code.append(f"{ind}{{")
            code.append(f"{ind}    uint32_t _op1 = (insn >> 16) & 7;")
            code.append(f"{ind}    uint32_t _CRn = (insn >> 12) & 0xF;")
            code.append(f"{ind}    uint32_t _CRm = (insn >> 8) & 0xF;")
            code.append(f"{ind}    uint32_t _op2 = (insn >> 5) & 7;")
            code.append(f"{ind}    uint32_t _Rt  = insn & 0x1F;")
            code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Immediate, _op1, false));")
            code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Immediate, _CRn, false));")
            code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Immediate, _CRm, false));")
            code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Immediate, _op2, false));")
            code.append(f"{ind}    if (_Rt != 31)")
            code.append(f"{ind}        result.operands.push_back(Operand(OperandType::Register, _Rt, true));")
            code.append(f"{ind}}}")
            code.append(f"{ind}return result;")
            return code

        # Special case: MSR (immediate) - PSTATE field write
        if is_msr_pstate:
            code.append(f"{ind}{{")
            code.append(f"{ind}    uint32_t _op1 = (insn >> 16) & 7;")
            code.append(f"{ind}    uint32_t _CRm = (insn >> 8) & 0xF;")
            code.append(f"{ind}    uint32_t _op2 = (insn >> 5) & 7;")
            code.append(f"{ind}    uint32_t _pf_val = (_op1 << 7) | (_CRm << 3) | _op2;")
            code.append(f"{ind}    result.operands.push_back(Operand(OperandType::PstateField, _pf_val, false));")
            code.append(f"{ind}    result.operands.back().pstate = pstate_from_value(_pf_val);")
            code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Immediate, _CRm, false));")
            code.append(f"{ind}    return result;")
            code.append(f"{ind}}}")

        # Decode struct for field extraction (after early returns that don't need it)
        code.append(f"{ind}{union_name} enc = {{}};")
        code.append(f"{ind}enc.raw = insn;")
        code.extend(self._generate_undef_checks(encoding_info, member_name, indent))

        # Special case: LDP/STP (load/store pair) - only if required fields exist
        if is_ldp_stp and 'Rt' in field_map and 'Rt2' in field_map and 'Rn' in field_map:
            rt_field = field_map['Rt']['name']
            rt2_field = field_map['Rt2']['name']
            rn_field = field_map['Rn']['name']
            imm_field = None
            for imm_name in ['imm7', 'simm7', 'imm']:
                if imm_name in field_map:
                    imm_field = field_map[imm_name]['name']
                    break

            # Determine register type from encoding name and opc field
            # Check for SIMD/FP pair: _Q_ (128-bit), _D_ (64-bit), _S_ (32-bit)
            is_simd_q = '_q_' in encoding_name or '_Q_' in encoding_name
            is_simd_d = '_d_' in encoding_name and ('ldstpair' in encoding_name or 'ldstnapair' in encoding_name)
            is_simd_s = '_s_' in encoding_name and ('ldstpair' in encoding_name or 'ldstnapair' in encoding_name)

            if is_simd_q:
                # 128-bit Q registers (SIMD), scale=16
                code.append(f"{ind}int scale = 16;")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rt_field}, false); op.arrangement = Arrangement::Q; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rt2_field}, false); op.arrangement = Arrangement::Q; result.operands.push_back(op); }}")
            elif is_simd_d:
                # 64-bit D registers (SIMD), scale=8
                code.append(f"{ind}int scale = 8;")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rt_field}, false); op.arrangement = Arrangement::D; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rt2_field}, false); op.arrangement = Arrangement::D; result.operands.push_back(op); }}")
            elif is_simd_s:
                # 32-bit S registers (SIMD), scale=4
                code.append(f"{ind}int scale = 4;")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rt_field}, false); op.arrangement = Arrangement::S; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rt2_field}, false); op.arrangement = Arrangement::S; result.operands.push_back(op); }}")
            elif 'opc' in field_map and not field_map['opc']['is_fixed']:
                opc_field = field_map['opc']['name']
                code.append(f"{ind}bool is_64bit = (enc.{member_name}.{opc_field} == 2);")
                code.append(f"{ind}int scale = is_64bit ? 8 : 4;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, is_64bit));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt2_field}, is_64bit));")
            else:
                # Fallback: check encoding name for integer size
                is_64bit_val = '64' in encoding_name or '_d' in encoding_name
                # STGP: tag granule pair store, scale=16
                if mnemonic == 'STGP':
                    scale = 16
                # LDPSW: 32-bit signed word pair load, scale=4
                elif mnemonic == 'LDPSW':
                    scale = 4
                else:
                    scale = 8 if is_64bit_val else 4
                code.append(f"{ind}int scale = {scale};")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, {str(is_64bit_val).lower()}));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt2_field}, {str(is_64bit_val).lower()}));")

            # Memory operand with proper scaling (imm7 is 7-bit signed)
            if '_post' in encoding_name:
                if imm_field:
                    code.append(f"{ind}int32_t imm = (static_cast<int32_t>(enc.{member_name}.{imm_field}) << 25) >> 25;")
                    code.append(f"{ind}result.operands.push_back(Operand::memory_post_index(enc.{member_name}.{rn_field}, imm * scale));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_post_index(enc.{member_name}.{rn_field}, 0));")
            elif '_pre' in encoding_name:
                if imm_field:
                    code.append(f"{ind}int32_t imm = (static_cast<int32_t>(enc.{member_name}.{imm_field}) << 25) >> 25;")
                    code.append(f"{ind}result.operands.push_back(Operand::memory_pre_index(enc.{member_name}.{rn_field}, imm * scale));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_pre_index(enc.{member_name}.{rn_field}, 0));")
            else:
                if imm_field:
                    code.append(f"{ind}int32_t imm = (static_cast<int32_t>(enc.{member_name}.{imm_field}) << 25) >> 25;")
                    code.append(f"{ind}result.operands.push_back(Operand::memory_offset(enc.{member_name}.{rn_field}, imm * scale));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")

            code.append(f"{ind}return result;")
            return code

        # Special case: ADR/ADRP - combine immhi and immlo into label operand
        if mnemonic in ['ADR', 'ADRP'] and 'immhi' in field_map and 'immlo' in field_map and 'Rd' in field_map:
            rd_field = field_map['Rd']['name']
            immhi_field = field_map['immhi']['name']
            immlo_field = field_map['immlo']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_field}, true));")
            # Combine immhi:immlo into 21-bit signed offset
            code.append(f"{ind}int32_t imm21 = static_cast<int32_t>((enc.{member_name}.{immhi_field} << 2) | (enc.{member_name}.{immlo_field} & 0x3));")
            code.append(f"{ind}if (imm21 & 0x100000) imm21 |= static_cast<int32_t>(0xFFE00000);")
            if mnemonic == 'ADRP':
                # ADRP: offset is imm21 << 12 (page-aligned), can be up to ±4GB (33 bits)
                code.append(f"{ind}int64_t offset = static_cast<int64_t>(imm21) << 12;")
                code.append(f"{ind}Operand op(OperandType::Relative, static_cast<uint32_t>(offset & 0xFFFFFFFF), true);")
                code.append(f"{ind}op.imm64 = static_cast<uint64_t>(offset);")
                code.append(f"{ind}result.operands.push_back(op);")
            else:
                # ADR: offset is imm21 directly (fits in 32 bits)
                code.append(f"{ind}int32_t offset = imm21;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));")

            code.append(f"{ind}return result;")
            return code

        # Special case: CLREX - CRm operand is optional, defaulting to 15 (omit when CRm==15)
        if mnemonic == 'CLREX' and 'CRm' in field_map and not field_map['CRm']['is_fixed']:
            crm_field = field_map['CRm']['name']
            code.append(f"{ind}if (enc.{member_name}.{crm_field} != 15) result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{crm_field}, true));")
            code.append(f"{ind}return result;")
            return code

        # Special case: Barrier instructions (DMB, DSB, ISB) - extract CRm as Barrier operand
        if mnemonic in ['DMB', 'DSB', 'ISB'] and 'CRm' in field_map and not field_map['CRm']['is_fixed']:
            crm_field = field_map['CRm']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Barrier, enc.{member_name}.{crm_field}, true));")
            code.append(f"{ind}result.operands.back().barrier = barrier_from_value(enc.{member_name}.{crm_field});")
            code.append(f"{ind}return result;")
            return code

        # Special case: Branch instructions - only if required fields exist
        if is_branch:
            if (mnemonic == 'BL' or mnemonic == 'B') and 'imm26' in field_map:
                imm_field = field_map['imm26']['name']
                # Sign-extend 26-bit immediate and multiply by 4
                code.append(f"{ind}int32_t offset = static_cast<int32_t>(enc.{member_name}.{imm_field} << 6) >> 6;")
                code.append(f"{ind}offset *= 4;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));")
                code.append(f"{ind}return result;")
                return code
            elif mnemonic in ['B', 'BC'] and 'imm19' in field_map:
                # Conditional branch B.cond - set condition on instruction, then offset
                if 'cond' in field_map and not field_map['cond']['is_fixed']:
                    cond_field = field_map['cond']['name']
                    code.append(f"{ind}result.condition = static_cast<Condition>(enc.{member_name}.{cond_field});")
                imm_field = field_map['imm19']['name']
                # Sign-extend 19-bit immediate and multiply by 4
                code.append(f"{ind}int32_t offset = static_cast<int32_t>(enc.{member_name}.{imm_field} << 13) >> 13;")
                code.append(f"{ind}offset *= 4;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));")
                code.append(f"{ind}return result;")
                return code
            elif mnemonic in ['CBZ', 'CBNZ'] and 'Rt' in field_map and 'imm19' in field_map:
                rt_field = field_map['Rt']['name']
                imm_field = field_map['imm19']['name']
                # Register operand with proper size
                if has_sf and 'sf' in field_map:
                    sf_field = field_map['sf']['name']
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, static_cast<bool>(enc.{member_name}.{sf_field})));")
                else:
                    is_64 = '_64' in encoding_name and '_32' not in encoding_name
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, {str(is_64).lower()}));")
                # Sign-extend 19-bit immediate and multiply by 4
                code.append(f"{ind}int32_t offset = static_cast<int32_t>(enc.{member_name}.{imm_field} << 13) >> 13;")
                code.append(f"{ind}offset *= 4;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));")
                code.append(f"{ind}return result;")
                return code
            elif mnemonic in ['TBZ', 'TBNZ'] and 'Rt' in field_map and 'imm14' in field_map and 'b5' in field_map and 'b40' in field_map:
                rt_field = field_map['Rt']['name']
                imm_field = field_map['imm14']['name']
                b5_field = field_map['b5']['name']
                b40_field = field_map['b40']['name']
                # b5 determines register width: b5=1 → X register (64-bit), b5=0 → W register (32-bit)
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, static_cast<bool>(enc.{member_name}.{b5_field})));")
                # Bit number (6-bit value from b5:b40)
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (enc.{member_name}.{b5_field} << 5) | enc.{member_name}.{b40_field}, true));")
                # Sign-extend 14-bit immediate and multiply by 4
                code.append(f"{ind}int32_t offset = static_cast<int32_t>(enc.{member_name}.{imm_field} << 18) >> 18;")
                code.append(f"{ind}offset *= 4;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));")
                code.append(f"{ind}return result;")
                return code
            # RETAASPPC/RETABSPPC: label = PC - ZeroExtend(imm16:'00')
            # imm16 is unsigned, offset is negative, scaled by 4
            elif mnemonic in ['RETAASPPC', 'RETABSPPC'] and 'imm16' in field_map:
                imm_field = field_map['imm16']['name']
                code.append(f"{ind}int32_t offset = -(int32_t)(enc.{member_name}.{imm_field} * 4u);")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));")
                code.append(f"{ind}return result;")
                return code
            # Fall through to default if required fields not found

        # Special case: LDR/LDRSW/PRFM literal: Rt + imm19 PC-relative offset
        if mnemonic in ['LDR', 'LDRSW', 'PRFM'] and 'Rt' in field_map and 'imm19' in field_map and 'Rn' not in field_map:
            rt_field = field_map['Rt']['name']
            imm_field = field_map['imm19']['name']
            # Check for SIMD/FP literal load (LDR_S_loadlit, LDR_D_loadlit, LDR_Q_loadlit)
            fp_lit_arr = None
            if 'loadlit' in encoding_name:
                if '_s_' in encoding_name:
                    fp_lit_arr = 'Arrangement::S'
                elif '_d_' in encoding_name:
                    fp_lit_arr = 'Arrangement::D'
                elif '_q_' in encoding_name:
                    fp_lit_arr = 'Arrangement::Q'
            if fp_lit_arr:
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rt_field}, false); op.arrangement = {fp_lit_arr}; result.operands.push_back(op); }}")
            elif mnemonic == 'PRFM':
                # PRFM literal: Rt is prefetch operation, not a register
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Prefetch, enc.{member_name}.{rt_field}, true));")
                code.append(f"{ind}result.operands.back().prefetch = prefetch_from_value(enc.{member_name}.{rt_field});")
            elif has_sf and 'sf' in field_map:
                sf_field = field_map['sf']['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, static_cast<bool>(enc.{member_name}.{sf_field})));")
            else:
                is_64 = '_64' in encoding_name and '_32' not in encoding_name
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, {str(is_64).lower()}));")
            # Sign-extend 19-bit immediate and multiply by 4
            code.append(f"{ind}int32_t offset = static_cast<int32_t>(enc.{member_name}.{imm_field} << 13) >> 13;")
            code.append(f"{ind}offset *= 4;")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));")
            code.append(f"{ind}return result;")
            return code

        # Special case: MOVZ/MOVN/MOVK - only if required fields exist
        if (is_movz or is_movn or is_movk) and 'Rd' in field_map and 'imm16' in field_map:
            rd_field = field_map['Rd']['name']
            imm_field = field_map['imm16']['name']

            if has_sf and 'sf' in field_map:
                sf_field = field_map['sf']['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_field}, static_cast<bool>(enc.{member_name}.{sf_field})));")
            else:
                # Determine is_64bit from encoding name (_32 means 32-bit, _64 means 64-bit)
                is_64 = '_64' in encoding_name and '_32' not in encoding_name
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_field}, {str(is_64).lower()}));")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{imm_field}, true));")
            # Only show shift if non-zero
            if 'hw' in field_map:
                hw_field = field_map['hw']['name']
                code.append(f"{ind}if (enc.{member_name}.{hw_field} != 0) {{")
                code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Shift, enc.{member_name}.{hw_field} * 16, true));")
                code.append(f"{ind}}}")

            code.append(f"{ind}return result;")
            return code

        # Special case: ADD/SUB with immediate - only if required fields exist
        if is_add_sub and 'imm' in encoding_name and 'Rd' in field_map and 'Rn' in field_map and 'imm12' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            imm_field = field_map['imm12']['name']

            # ADD/SUB immediate: Rd and Rn use SP context (reg 31 = SP, not XZR)
            if has_sf and 'sf' in field_map:
                sf_field = field_map['sf']['name']
                code.append(f"{ind}{{ Operand op(OperandType::Register, enc.{member_name}.{rd_field}, static_cast<bool>(enc.{member_name}.{sf_field})); op.is_sp = true; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::Register, enc.{member_name}.{rn_field}, static_cast<bool>(enc.{member_name}.{sf_field})); op.is_sp = true; result.operands.push_back(op); }}")
            else:
                is_64 = '_64' in encoding_name and '_32' not in encoding_name
                code.append(f"{ind}{{ Operand op(OperandType::Register, enc.{member_name}.{rd_field}, {str(is_64).lower()}); op.is_sp = true; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::Register, enc.{member_name}.{rn_field}, {str(is_64).lower()}); op.is_sp = true; result.operands.push_back(op); }}")

            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{imm_field}, true));")
            # Only show shift if non-zero
            if 'sh' in field_map:
                sh_field = field_map['sh']['name']
                code.append(f"{ind}if (enc.{member_name}.{sh_field} != 0) {{")
                code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Shift, 12, true));")
                code.append(f"{ind}}}")

            code.append(f"{ind}return result;")
            return code

        # Special case: Logical immediate (ORR, AND, EOR, ANDS with log_imm)
        is_log_imm = mnemonic in ['ORR', 'AND', 'EOR', 'ANDS'] and 'log_imm' in encoding_name
        if is_log_imm and 'Rd' in field_map and 'Rn' in field_map and 'imms' in field_map and 'immr' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            imms_field = field_map['imms']['name']
            immr_field = field_map['immr']['name']
            n_field = field_map['N']['name'] if 'N' in field_map else None

            # Determine register width
            if has_sf and 'sf' in field_map:
                sf_field = field_map['sf']['name']
                code.append(f"{ind}bool is_64bit = static_cast<bool>(enc.{member_name}.{sf_field});")
            else:
                # Check for 64-bit encoding: _64_ or _64S_ etc.
                is_64 = '_64' in encoding_name and '_32' not in encoding_name
                code.append(f"{ind}bool is_64bit = {str(is_64).lower()};")

            # Rd uses SP context for ORR/AND/EOR (not ANDS), Rn uses SP context for none
            rd_is_sp = mnemonic in ['ORR', 'AND', 'EOR']  # Rd can be SP for non-S variants
            if rd_is_sp:
                code.append(f"{ind}{{ Operand op(OperandType::Register, enc.{member_name}.{rd_field}, is_64bit); op.is_sp = true; result.operands.push_back(op); }}")
            else:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_field}, is_64bit));")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rn_field}, is_64bit));")

            # Decode the logical immediate using DecodeBitMasks
            if n_field:
                code.append(f"{ind}uint64_t imm_val = decode_bit_masks(enc.{member_name}.{n_field}, enc.{member_name}.{imms_field}, enc.{member_name}.{immr_field}, is_64bit);")
            else:
                code.append(f"{ind}uint64_t imm_val = decode_bit_masks(0, enc.{member_name}.{imms_field}, enc.{member_name}.{immr_field}, is_64bit);")
            code.append(f"{ind}{{ Operand op(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit); op.imm64 = imm_val; result.operands.push_back(op); }}")

            code.append(f"{ind}return result;")
            return code

        # Special case: PRFM/PRFUM - Rt is prfop (prefetch operation), not a register
        if mnemonic in ['PRFM', 'PRFUM'] and 'Rt' in field_map and 'Rn' in field_map:
            rt_field = field_map['Rt']['name']
            rn_field = field_map['Rn']['name']
            # Prefetch operation from Rt field
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Prefetch, enc.{member_name}.{rt_field}, true));")
            code.append(f"{ind}result.operands.back().prefetch = prefetch_from_value(enc.{member_name}.{rt_field});")

            if addr_mode == 'reg_offset' and 'Rm' in field_map:
                rm_field = field_map['Rm']['name']
                if 'option' in field_map and not field_map['option']['is_fixed']:
                    option_field = field_map['option']['name']
                    s_field = field_map['S']['name'] if 'S' in field_map and not field_map['S']['is_fixed'] else None
                    if s_field:
                        code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}, enc.{member_name}.{option_field}, enc.{member_name}.{s_field} ? 3 : 0));")
                    else:
                        code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}, enc.{member_name}.{option_field}, 0));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}));")
            elif 'imm19' in field_map:
                # Literal form - PC-relative
                imm_field = field_map['imm19']['name']
                code.append(f"{ind}int32_t offset = static_cast<int32_t>(enc.{member_name}.{imm_field} << 13) >> 13;")
                code.append(f"{ind}offset *= 4;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));")
            else:
                # Offset form
                imm_field = None
                for imm_name in ['imm12', 'imm9', 'simm9']:
                    if imm_name in field_map:
                        imm_field = field_map[imm_name]['name']
                        break
                if imm_field:
                    if mnemonic == 'PRFUM' or 'imm9' in field_map or 'simm9' in field_map:
                        # PRFUM / unscaled: signed imm9, no scaling
                        code.append(f"{ind}int32_t imm = static_cast<int32_t>(enc.{member_name}.{imm_field} << 23) >> 23;")
                    else:
                        # PRFM unsigned offset: scale by 8
                        code.append(f"{ind}int32_t imm = enc.{member_name}.{imm_field} * 8;")
                    code.append(f"{ind}result.operands.push_back(Operand::memory_offset(enc.{member_name}.{rn_field}, imm));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")

            code.append(f"{ind}return result;")
            return code

        # Special case: Memory tagging loads/stores (STG, ST2G, STZG, STZ2G, LDG, LDGM, STGM)
        # Encoding: ldsttags - uses Xt (64-bit GP, can be SP for stores), Xn (base), imm9 (scaled ×16)
        if is_load_store and 'ldsttags' in encoding_name and 'Rt' in field_map and 'Rn' in field_map:
            rt_field = field_map['Rt']['name']
            rn_field = field_map['Rn']['name']
            # Rt can be SP for store tags (STG/ST2G/STZG/STZ2G)
            rt_can_sp = mnemonic in ['STG', 'ST2G', 'STZG', 'STZ2G']
            if rt_can_sp:
                code.append(f"{ind}{{ Operand op(OperandType::Register, enc.{member_name}.{rt_field}, true); op.is_sp = true; result.operands.push_back(op); }}")
            else:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, true));")
            # Memory operand: [Xn|SP, #simm9*16] or [Xn|SP] for bulk variants
            imm_field = None
            for imm_name in ['imm9', 'simm9']:
                if imm_name in field_map:
                    imm_field = field_map[imm_name]['name']
                    break
            if imm_field:
                # Determine addressing mode from encoding name
                is_post = 'post' in encoding_name
                is_pre = 'pre' in encoding_name
                code.append(f"{ind}int32_t imm = (static_cast<int32_t>(enc.{member_name}.{imm_field} << 23) >> 23) * 16;")
                if is_post:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_post_index(enc.{member_name}.{rn_field}, imm));")
                elif is_pre:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_pre_index(enc.{member_name}.{rn_field}, imm));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_offset(enc.{member_name}.{rn_field}, imm));")
            else:
                code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")
            code.append(f"{ind}return result;")
            return code

        # Special case: PAC loads (LDRAA / LDRAB) — imm9 scaled by 8, writeback variant uses pre-index
        if is_load_store and 'ldst_pac' in encoding_name and 'Rt' in field_map and 'Rn' in field_map and 'imm9' in field_map:
            rt_field = field_map['Rt']['name']
            rn_field = field_map['Rn']['name']
            imm9_field = field_map['imm9']['name']
            s_field = field_map['S']['name'] if 'S' in field_map and not field_map['S']['is_fixed'] else None
            is_writeback = '64w' in encoding_name.lower()
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, true));")
            if s_field:
                # LDRAA/LDRAB: offset = SignExtend(S:imm9, 10) * 8 (S is MSB of 10-bit signed value)
                code.append(f"{ind}uint32_t _raw10 = (enc.{member_name}.{s_field} << 9) | (enc.{member_name}.{imm9_field} & 0x1FFu);")
                code.append(f"{ind}int32_t imm = static_cast<int32_t>((_raw10 ^ (1u << 9)) - (1u << 9)) * 8;")
            else:
                code.append(f"{ind}int32_t imm = enc.{member_name}.{imm9_field} * 8;  // sign-extended (imm9 is int32_t) and scaled")
            if is_writeback:
                code.append(f"{ind}result.operands.push_back(Operand::memory_pre_index(enc.{member_name}.{rn_field}, imm));")
            else:
                code.append(f"{ind}if (imm == 0) result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")
                code.append(f"{ind}else result.operands.push_back(Operand::memory_offset(enc.{member_name}.{rn_field}, imm));")
            code.append(f"{ind}return result;")
            return code

        # Special case: Load/store exclusive, ordered, and atomic operations
        # Covers: LDAR/STLR, LDXR/STXR, LDAXR/STLXR, LDLAR/STLLR, CAS, LDADD, LDCLR, LDSET, LDEOR, SWP, LDAPR
        excl_ord_names = ['ldstord', 'ldstexcl', 'comswap', 'memop']
        if is_load_store and 'Rt' in field_map and 'Rn' in field_map and any(x in encoding_name for x in excl_ord_names):
            rt_field = field_map['Rt']['name']
            rn_field = field_map['Rn']['name']
            has_rs = 'Rs' in field_map and not field_map['Rs']['is_fixed']
            has_rt2 = 'Rt2' in field_map and not field_map['Rt2']['is_fixed']

            # Register width: 64 in name → X, otherwise W
            # Exclusive/ordered use patterns like sl64, sr64, lr64 (not _64_)
            is_64 = '64' in encoding_name and '32' not in encoding_name
            code.append(f"{ind}bool is_64bit = {str(is_64).lower()};")

            # Exclusive stores: Rs is status register (always W32)
            is_excl_store = 'stxr' in encoding_name or 'stlxr' in encoding_name or 'stxp' in encoding_name or 'stlxp' in encoding_name
            # CASP/CASPA/CASPAL/CASPL: paired registers Rs, Rs+1, Rt, Rt+1
            is_casp = mnemonic in ['CASP', 'CASPA', 'CASPAL', 'CASPL',
                                   'CASPT', 'CASPAT', 'CASPALT', 'CASPLT']
            # Operand order: [Rs, [Rs+1,]] Rt [, Rt+1] [, Rt2], [Xn|SP]
            if has_rs:
                rs_field = field_map['Rs']['name']
                rs_64 = 'false' if is_excl_store else 'is_64bit'
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rs_field}, {rs_64}));")
                if is_casp:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, (enc.{member_name}.{rs_field} + 1) & 31, is_64bit));")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, is_64bit));")
            if is_casp:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, (enc.{member_name}.{rt_field} + 1) & 31, is_64bit));")
            if has_rt2:
                rt2_field = field_map['Rt2']['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt2_field}, is_64bit));")
            code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")

            code.append(f"{ind}return result;")
            return code

        # Special case: LDAPUR/STLUR (load-acquire/store-release unscaled) - ldapstl_unscaled encoding
        if is_load_store and 'ldapstl' in encoding_name and 'Rt' in field_map and 'Rn' in field_map:
            rt_field = field_map['Rt']['name']
            rn_field = field_map['Rn']['name']
            # Register width from encoding name: _64_ = X, _32_ = W
            rt_is_64 = '_64_' in encoding_name
            # SIMD&FP variant uses FP register (Bt/Ht/St/Dt/Qt) instead of GP register
            if 'simd' in encoding_name:
                import re as _re_fp
                _asm_tmpl = encoding_info.get('asm_template', '')
                _fp_m = _re_fp.search(r'<([BHSDQ])t(?:\d+)?>', _asm_tmpl)
                if _fp_m:
                    _fp_arr = _fp_m.group(1).lower()
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rt_field}, false); op.arrangement = {_CHAR_TO_ARR[_fp_arr]}; result.operands.push_back(op); }}")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, {str(rt_is_64).lower()}));")
            else:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, {str(rt_is_64).lower()}));")
            # Memory operand: [Xn|SP, #simm9]
            imm_field = None
            for imm_name in ['imm9', 'simm9']:
                if imm_name in field_map:
                    imm_field = field_map[imm_name]['name']
                    break
            if imm_field:
                code.append(f"{ind}int32_t imm = static_cast<int32_t>(enc.{member_name}.{imm_field} << 23) >> 23;")
                code.append(f"{ind}result.operands.push_back(Operand::memory_offset(enc.{member_name}.{rn_field}, imm));")
            else:
                code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")
            code.append(f"{ind}return result;")
            return code

        # Special case: Load/store byte/half (and unprivileged variants) - only if required fields exist
        byte_half_names = ['ldrb', 'strb', 'ldrh', 'strh', 'ldrsb', 'ldrsh',
                          'ldurb', 'sturb', 'ldurh', 'sturh', 'ldursb', 'ldursh',
                          'ldtrb', 'sttrb', 'ldtrh', 'sttrh', 'ldtrsb', 'ldtrsh',
                          '32b_', '32h_']
        if is_load_store and 'Rt' in field_map and 'Rn' in field_map and any(x in encoding_name for x in byte_half_names):
            rt_field = field_map['Rt']['name']
            rn_field = field_map['Rn']['name']
            imm_field = None
            for imm_name in ['imm12', 'imm9', 'simm9', 'imm']:
                if imm_name in field_map:
                    imm_field = field_map[imm_name]['name']
                    break

            # Signed variants (LDRSB, LDRSH) can target 64-bit X registers
            is_signed = any(x in encoding_name for x in ['ldrsb', 'ldrsh', 'ldursb', 'ldursh', 'ldtrsb', 'ldtrsh'])
            if is_signed:
                rt_is_64 = '_64' in encoding_name and '_32' not in encoding_name
            else:
                rt_is_64 = False
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, {str(rt_is_64).lower()}));")

            # Determine scale for unsigned offset: halfword = 2, byte = 1
            is_halfword = any(x in encoding_name for x in ['ldrh', 'strh', 'ldrsh', 'ldurh', 'sturh', 'ldursh', 'ldtrh', 'sttrh', 'ldtrsh', '32h_'])
            is_unscaled = any(x in encoding_name for x in ['ldur', 'stur', 'ldtr', 'sttr'])
            scale_factor = 2 if is_halfword and not is_unscaled else 1
            # Shift amount for register offset: log2(scale) - halfword=1, byte=0
            reg_shift_amount = 1 if is_halfword else 0

            # Memory operand (imm9 is 9-bit signed for pre/post/unscaled, imm12 is unsigned for offset)
            if addr_mode == 'reg_offset' and 'Rm' in field_map:
                rm_field = field_map['Rm']['name']
                if 'option' in field_map and not field_map['option']['is_fixed']:
                    option_field = field_map['option']['name']
                    s_field = field_map['S']['name'] if 'S' in field_map and not field_map['S']['is_fixed'] else None
                    if s_field:
                        code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}, enc.{member_name}.{option_field}, enc.{member_name}.{s_field} ? {reg_shift_amount} : 0));")
                    else:
                        code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}, enc.{member_name}.{option_field}));")
                else:
                    # LSL variant (option=0b011 fixed, just Rm)
                    s_field = field_map['S']['name'] if 'S' in field_map and not field_map['S']['is_fixed'] else None
                    if s_field:
                        code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}, 3, enc.{member_name}.{s_field} ? {reg_shift_amount} : 0));")
                    else:
                        code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}));")
            elif addr_mode == 'post_index':
                if imm_field:
                    code.append(f"{ind}int32_t imm = (static_cast<int32_t>(enc.{member_name}.{imm_field}) << 23) >> 23;")
                    code.append(f"{ind}result.operands.push_back(Operand::memory_post_index(enc.{member_name}.{rn_field}, imm));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_post_index(enc.{member_name}.{rn_field}, 0));")
            elif addr_mode == 'pre_index':
                if imm_field:
                    code.append(f"{ind}int32_t imm = (static_cast<int32_t>(enc.{member_name}.{imm_field}) << 23) >> 23;")
                    code.append(f"{ind}result.operands.push_back(Operand::memory_pre_index(enc.{member_name}.{rn_field}, imm));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_pre_index(enc.{member_name}.{rn_field}, 0));")
            else:
                if imm_field and is_unscaled:
                    # Unscaled: imm9 is signed, no scaling
                    code.append(f"{ind}int32_t imm = (static_cast<int32_t>(enc.{member_name}.{imm_field}) << 23) >> 23;")
                    code.append(f"{ind}result.operands.push_back(Operand::memory_offset(enc.{member_name}.{rn_field}, imm));")
                elif imm_field:
                    if scale_factor > 1:
                        code.append(f"{ind}result.operands.push_back(Operand::memory_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{imm_field} * {scale_factor}));")
                    else:
                        code.append(f"{ind}result.operands.push_back(Operand::memory_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{imm_field}));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")

            code.append(f"{ind}return result;")
            return code

        # Special case: General load/store (LDR, STR, LDRSW 32/64-bit) - only if required fields exist
        if is_load_store and mnemonic in ['LDR', 'STR', 'LDUR', 'STUR', 'LDTR', 'STTR', 'LDRSW', 'LDURSW', 'LDTRSW',
                'LDRSH', 'LDRSB', 'LDRH', 'LDRB', 'STRH', 'STRB',
                'LDURSH', 'LDURSB', 'LDURH', 'LDURB', 'STURH', 'STURB',
                'LDTRSH', 'LDTRSB', 'LDTRH', 'LDTRB', 'STTRH', 'STTRB',
                'PRFUM'] and 'Rt' in field_map and 'Rn' in field_map:
            rt_field = field_map['Rt']['name']
            rn_field = field_map['Rn']['name']
            imm_field = None
            for imm_name in ['imm12', 'imm9', 'simm9', 'imm']:
                if imm_name in field_map:
                    imm_field = field_map[imm_name]['name']
                    break

            # Check if we need scale (only for unsigned offset with imm_field)
            needs_scale = addr_mode not in ['post_index', 'pre_index'] and imm_field is not None

            # Detect SIMD/FP register variants from encoding name (_Q_, _D_, _S_, _H_, _B_)
            simd_reg_type = None
            enc_upper = encoding_name.upper()
            for suffix, scale_val, reg_char in [('_Q_', 16, 'q'), ('_D_', 8, 'd'), ('_S_', 4, 's'), ('_H_', 2, 'h'), ('_B_', 1, 'b')]:
                if suffix in enc_upper:
                    simd_reg_type = (scale_val, reg_char)
                    break

            if simd_reg_type:
                simd_scale, simd_char = simd_reg_type
                code.append(f"{ind}// SIMD/FP {simd_char.upper()} register variant (scale={simd_scale})")
                if needs_scale:
                    code.append(f"{ind}int scale = {simd_scale};")
                # Q uses is_64bit=true (gives q prefix), D/S/H/B use arrangement as scalar prefix
                if simd_char == 'q':
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::VectorRegister, enc.{member_name}.{rt_field}, true));")
                else:
                    code.append(f"{ind}{{")
                    code.append(f'{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{rt_field}, false);')
                    code.append(f'{ind}    op.arrangement = {_CHAR_TO_ARR[simd_char]};')
                    code.append(f"{ind}    result.operands.push_back(op);")
                    code.append(f"{ind}}}")
            else:
                # Determine register size from encoding name or 'size' field
                if 'size' in field_map and not field_map['size']['is_fixed']:
                    size_field = field_map['size']['name']
                    code.append(f"{ind}bool is_64bit = (enc.{member_name}.{size_field} & 1) == 1;")
                    if needs_scale:
                        code.append(f"{ind}int scale = is_64bit ? 8 : 4;")
                elif '64' in encoding_name:
                    code.append(f"{ind}bool is_64bit = true;")
                    if needs_scale:
                        # LDRSW loads 32-bit words (scale=4), LDRSB/LDRSH sign-extend to 64-bit
                        if mnemonic in ['LDRSW', 'LDRSH', 'LDTRSH']:
                            ldrsw_scale = 4 if mnemonic == 'LDRSW' else 2
                        elif mnemonic in ['LDRSB', 'LDTRSB']:
                            ldrsw_scale = 1
                        else:
                            ldrsw_scale = 8
                        code.append(f"{ind}int scale = {ldrsw_scale};")
                else:
                    code.append(f"{ind}bool is_64bit = false;")
                    if needs_scale:
                        # Byte/halfword variants: LDRB/STRB=1, LDRH/STRH/LDRSH=2, default=4
                        if mnemonic in ['LDRB', 'STRB', 'LDRSB', 'LDTRB', 'STTRB', 'LDURB', 'STURB', 'LDTRSB', 'LDURSB']:
                            code.append(f"{ind}int scale = 1;")
                        elif mnemonic in ['LDRH', 'STRH', 'LDRSH', 'LDTRH', 'STTRH', 'LDURH', 'STURH', 'LDTRSH', 'LDURSH']:
                            code.append(f"{ind}int scale = 2;")
                        else:
                            code.append(f"{ind}int scale = 4;")

                # PRFUM uses prefetch operand instead of register
                if mnemonic == 'PRFUM':
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Prefetch, enc.{member_name}.{rt_field}, true));")
                    code.append(f"{ind}result.operands.back().prefetch = prefetch_from_value(enc.{member_name}.{rt_field});")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, is_64bit));")

            # Check if this is an unscaled load/store (LDUR/STUR/LDTR/STTR use signed imm9, no scaling)
            is_unscaled = mnemonic in ['LDUR', 'STUR', 'LDTR', 'STTR', 'LDURSW', 'LDTRSW',
                'LDURSH', 'LDURSB', 'LDURH', 'LDURB', 'STURH', 'STURB',
                'LDTRSH', 'LDTRSB', 'LDTRH', 'LDTRB', 'STTRH', 'STTRB',
                'PRFUM']

            # Compute shift amount for register-offset addressing (log2 of byte size)
            scale_to_shift = {1: 0, 2: 1, 4: 2, 8: 3, 16: 4}
            if simd_reg_type:
                reg_offset_shift = scale_to_shift.get(simd_reg_type[0], 0)
            elif mnemonic == 'LDRSW':
                reg_offset_shift = 2  # LDRSW loads 32-bit word (scale=4)
            elif '64' in encoding_name:
                reg_offset_shift = 3
            else:
                reg_offset_shift = 2

            # Memory operand with scaling for imm12 (unsigned offset)
            if addr_mode == 'reg_offset' and 'Rm' in field_map:
                rm_field = field_map['Rm']['name']
                if 'option' in field_map and not field_map['option']['is_fixed']:
                    option_field = field_map['option']['name']
                    s_field = field_map['S']['name'] if 'S' in field_map and not field_map['S']['is_fixed'] else None
                    if s_field:
                        code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}, enc.{member_name}.{option_field}, enc.{member_name}.{s_field} ? {reg_offset_shift} : 0));")
                    else:
                        code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}, enc.{member_name}.{option_field}));")
                else:
                    # LSL variant (option=0b011 fixed, just Rm)
                    s_field = field_map['S']['name'] if 'S' in field_map and not field_map['S']['is_fixed'] else None
                    if s_field:
                        code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}, 3, enc.{member_name}.{s_field} ? {reg_offset_shift} : 0));")
                    else:
                        code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}));")
            elif addr_mode == 'post_index':
                if imm_field:
                    code.append(f"{ind}int32_t imm = (static_cast<int32_t>(enc.{member_name}.{imm_field}) << 23) >> 23;")
                    code.append(f"{ind}result.operands.push_back(Operand::memory_post_index(enc.{member_name}.{rn_field}, imm));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_post_index(enc.{member_name}.{rn_field}, 0));")
            elif addr_mode == 'pre_index':
                if imm_field:
                    code.append(f"{ind}int32_t imm = (static_cast<int32_t>(enc.{member_name}.{imm_field}) << 23) >> 23;")
                    code.append(f"{ind}result.operands.push_back(Operand::memory_pre_index(enc.{member_name}.{rn_field}, imm));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_pre_index(enc.{member_name}.{rn_field}, 0));")
            else:
                if imm_field and is_unscaled:
                    # Unscaled: imm9 is signed, no scaling
                    code.append(f"{ind}int32_t imm = (static_cast<int32_t>(enc.{member_name}.{imm_field}) << 23) >> 23;")
                    code.append(f"{ind}result.operands.push_back(Operand::memory_offset(enc.{member_name}.{rn_field}, imm));")
                elif imm_field:
                    # Unsigned offset - needs to be scaled
                    code.append(f"{ind}result.operands.push_back(Operand::memory_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{imm_field} * scale));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")

            code.append(f"{ind}return result;")
            return code

        # Special case: BRK - only if required fields exist
        if mnemonic == 'BRK' and 'imm16' in field_map:
            imm_field = field_map['imm16']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{imm_field}, true));")
            code.append(f"{ind}return result;")
            return code

        # Special case: ADD/SUB extended register (addsub_ext)
        # Rn=31 means SP, Rm width depends on option, option+imm3 combine as extend
        is_addsub_ext = 'addsub_ext' in encoding_name
        if is_addsub_ext and 'Rn' in field_map and 'Rm' in field_map:
            # Determine register size
            if 'sf' in field_map and not field_map['sf']['is_fixed']:
                sf_field = field_map['sf']['name']
                code.append(f"{ind}bool is_64bit = enc.{member_name}.{sf_field};")
            elif '64' in encoding_name:
                code.append(f"{ind}bool is_64bit = true;")
            else:
                code.append(f"{ind}bool is_64bit = false;")

            # Rd (if not fixed — CMP/CMN have Rd=11111)
            # Rd=31 means SP in extended register form (not XZR)
            if 'Rd' in field_map and not field_map['Rd']['is_fixed']:
                rd_field = field_map['Rd']['name']
                code.append(f"{ind}{{ Operand op(OperandType::Register, enc.{member_name}.{rd_field}, is_64bit); op.is_sp = true; result.operands.push_back(op); }}")

            # Rn: register 31 = SP (not XZR) for addsub_ext
            rn_field = field_map['Rn']['name']
            code.append(f"{ind}{{ Operand op(OperandType::Register, enc.{member_name}.{rn_field}, is_64bit); op.is_sp = true; result.operands.push_back(op); }}")

            # Rm: width depends on option for 64-bit (option[1:0]==11 → Xm, else Wm)
            rm_field = field_map['Rm']['name']
            option_field = field_map['option']['name'] if 'option' in field_map and not field_map['option']['is_fixed'] else None
            if option_field:
                code.append(f"{ind}uint32_t option = enc.{member_name}.{option_field};")
                code.append(f"{ind}bool rm_is_64 = is_64bit && ((option & 3) == 3);")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rm_field}, rm_is_64));")
            else:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rm_field}, is_64bit));")

            # Extend + shift: combine option and imm3
            imm3_field = field_map['imm3']['name'] if 'imm3' in field_map and not field_map['imm3']['is_fixed'] else None
            if option_field and imm3_field:
                code.append(f"{ind}uint32_t imm3 = enc.{member_name}.{imm3_field};")
                # Suppress default extend only when Rn=31 (SP): option=3 (LSL) with imm3=0 for 64-bit, option=2 (UXTW=LSL) with imm3=0 for 32-bit
                code.append(f"{ind}uint32_t _rn = enc.{member_name}.{rn_field};")
                code.append(f"{ind}bool is_default = (is_64bit ? (option == 3 && _rn == 31) : (option == 2 && _rn == 31)) && imm3 == 0;")
                code.append(f"{ind}if (!is_default) {{")
                code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));")
                code.append(f"{ind}}}")
            elif option_field:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Extend, option, is_64bit));")

            code.append(f"{ind}return result;")
            return code

        # Special case: MRS/MSR system register move
        if mnemonic in ['MRS', 'MSR'] and 'Rt' in field_map and 'o0' in field_map:
            rt_field = field_map['Rt']['name']
            o0_field = field_map['o0']['name']
            op1_field = field_map['op1']['name']
            crn_field = field_map['CRn']['name']
            crm_field = field_map['CRm']['name']
            op2_field = field_map['op2']['name']
            # Common: compute sysreg packed value and enum
            code.append(f"{ind}uint32_t sysreg = (enc.{member_name}.{o0_field} << 14) | (enc.{member_name}.{op1_field} << 11) | (enc.{member_name}.{crn_field} << 7) | (enc.{member_name}.{crm_field} << 3) | enc.{member_name}.{op2_field};")
            code.append(f"{ind}Operand sysreg_op(OperandType::SystemRegister, sysreg, true);")
            code.append(f"{ind}sysreg_op.sysreg = sysreg_from_encoding(2 + enc.{member_name}.{o0_field}, enc.{member_name}.{op1_field}, enc.{member_name}.{crn_field}, enc.{member_name}.{crm_field}, enc.{member_name}.{op2_field});")
            if mnemonic == 'MRS':
                # MRS: Xt, <sysreg> — always 64-bit
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, true));")
                code.append(f"{ind}result.operands.push_back(sysreg_op);")
            else:
                # MSR: <sysreg>, Xt — always 64-bit
                code.append(f"{ind}result.operands.push_back(sysreg_op);")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, true));")
            code.append(f"{ind}return result;")
            return code

        # Generic operand extraction for all other instructions
        # Extract register operands in order: Rd, Rn, Rm, Ra, Rt, Rs, Rt2

        # Map from register field names to their letter designation
        reg_mapping = {
            'Rd': 'd',
            'Rn': 'n',
            'Rm': 'm',
            'Ra': 'a',
            'Rt': 't',
            'Rs': 's',
            'Rt2': 't2',
        }

        # Check if there are any register operands that need is_64bit
        has_reg_operands = any(reg_name in field_map and not field_map[reg_name]['is_fixed']
                              for reg_name in ['Rd', 'Rn', 'Rm', 'Ra', 'Rt', 'Rs', 'Rt2', 'Rdn'])

        # Only determine register size if there are register operands
        if has_reg_operands:
            if 'sf' in field_map and not field_map['sf']['is_fixed']:
                sf_field = field_map['sf']['name']
                code.append(f"{ind}bool is_64bit = enc.{member_name}.{sf_field};")
            elif 'sf' in field_map and field_map['sf']['is_fixed'] and field_map['sf']['fixed']:
                sf_val = int(field_map['sf']['fixed'], 2)
                code.append(f"{ind}bool is_64bit = {str(bool(sf_val)).lower()};")
            elif '_64_' in encoding_name or encoding_name.endswith('_64') or ('64' in encoding_name and '32' not in encoding_name):
                code.append(f"{ind}bool is_64bit = true;")
            elif mnemonic in ['ADR', 'ADRP'] or 'pcreladdr' in encoding_name:
                # ADR/ADRP always produce 64-bit X registers
                code.append(f"{ind}bool is_64bit = true;")
            elif _re_module.search(r'<X[dnmta]', encoding_info.get('asm_template', '')):
                # Template explicitly uses X-register prefix (e.g., <Xdn>, <Xd>)
                code.append(f"{ind}bool is_64bit = true;")
            else:
                code.append(f"{ind}bool is_64bit = false;")

        # Special case: FMOV float2int - mixed GPR and FP register operands
        is_fmov_float2int = mnemonic == 'FMOV' and 'float2int' in encoding_name
        if is_fmov_float2int and 'Rd' in field_map and 'Rn' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            # Parse encoding name to determine direction and FP type
            # Format: FMOV_<part>_float2int where <part> is like 64D, D64, 32S, S32, etc.
            enc_parts = encoding_name.upper().split('_')
            # Find the part between FMOV and FLOAT2INT
            part = enc_parts[1] if len(enc_parts) >= 3 else ''

            # Determine FP scalar type from the letters in part
            fp_char = 'd'  # default
            if 'S' in part and 'X' not in part:
                fp_char = 's'
            elif 'H' in part:
                fp_char = 'h'
            elif 'D' in part:
                fp_char = 'd'

            # Direction: if first char is digit → FP-to-GPR (Rd=GPR, Rn=FP)
            fp_to_gpr = part and part[0].isdigit()  # 64D, 32S, 32H, 64H, 64VX

            if fp_to_gpr:
                # Rd is GPR, Rn is FP scalar
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_field}, is_64bit));")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = {_CHAR_TO_ARR[fp_char]}; result.operands.push_back(op); }}")
            else:
                # Rd is FP scalar, Rn is GPR
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = {_CHAR_TO_ARR[fp_char]}; result.operands.push_back(op); }}")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rn_field}, is_64bit));")

            code.append(f"{ind}return result;")
            return code

        # Special case: SCVTF/UCVTF/FCVTZS/FCVTZU fixed-point conversion (float2fix encoding)
        # These have mixed FP and GPR register operands, and scale → fbits = 64 - scale
        is_float2fix = 'float2fix' in encoding_name and 'Rd' in field_map and 'Rn' in field_map and 'scale' in field_map and 'ftype' in field_map
        if is_float2fix:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            scale_field = field_map['scale']['name']
            ftype_field = field_map['ftype']['name']
            sf_field = field_map['sf']['name'] if 'sf' in field_map and not field_map['sf']['is_fixed'] else None

            # Determine GPR width from sf or encoding name
            if sf_field:
                code.append(f"{ind}bool gpr_is_64 = enc.{member_name}.{sf_field};")
            elif '64' in encoding_name:
                code.append(f"{ind}bool gpr_is_64 = true;")
            else:
                code.append(f"{ind}bool gpr_is_64 = false;")

            # FP scalar type from ftype: 0=S, 1=D, 3=H
            code.append(f'{ind}Arrangement fp_arr = Arrangement::S;')
            code.append(f"{ind}switch (enc.{member_name}.{ftype_field}) {{")
            code.append(f'{ind}    case 0: fp_arr = Arrangement::S; break;')
            code.append(f'{ind}    case 1: fp_arr = Arrangement::D; break;')
            code.append(f'{ind}    case 3: fp_arr = Arrangement::H; break;')
            code.append(f"{ind}    default: break;")
            code.append(f"{ind}}}")

            # SCVTF/UCVTF: Rd=FP, Rn=GPR; FCVTZS/FCVTZU: Rd=GPR, Rn=FP
            is_to_fp = mnemonic in ['SCVTF', 'UCVTF']
            if is_to_fp:
                # Rd is FP scalar
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = fp_arr; result.operands.push_back(op); }}")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rn_field}, gpr_is_64));")
            else:
                # Rd is GPR
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_field}, gpr_is_64));")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = fp_arr; result.operands.push_back(op); }}")

            # fbits = 64 - scale
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, 64 - enc.{member_name}.{scale_field}, true));")
            code.append(f"{ind}return result;")
            return code

        # Special case: DUP general - Rd is vector with arrangement, Rn is GPR
        if mnemonic == 'DUP' and 'Rd' in field_map and 'Rn' in field_map and 'imm5' in field_map and 'dr_r' in encoding_name:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            imm5_field = field_map['imm5']['name']
            q_field = field_map['Q']['name'] if 'Q' in field_map else None

            # Arrangement from imm5 lowest set bit and Q:
            # imm5[0]=1 → B (8b/16b), imm5[1:0]=10 → H (4h/8h), imm5[2:0]=100 → S (2s/4s), imm5[3:0]=1000 → D (1d/2d)
            if q_field:
                code.append(f"{ind}Arrangement _dup_arr = Arrangement::None;")
                code.append(f"{ind}uint32_t _imm5 = enc.{member_name}.{imm5_field};")
                code.append(f"{ind}bool _q = enc.{member_name}.{q_field};")
                code.append(f"{ind}if (_imm5 & 1) _dup_arr = _q ? Arrangement::B16 : Arrangement::B8;")
                code.append(f"{ind}else if (_imm5 & 2) _dup_arr = _q ? Arrangement::H8 : Arrangement::H4;")
                code.append(f"{ind}else if (_imm5 & 4) _dup_arr = _q ? Arrangement::S4 : Arrangement::S2;")
                code.append(f"{ind}else _dup_arr = _q ? Arrangement::D2 : Arrangement::D1;")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _dup_arr; result.operands.push_back(op); }}")
                # Rn: GPR, width depends on element size (B/H/S → W, D → X)
                code.append(f"{ind}bool _rn_64 = !(_imm5 & 0x7);")  # only D elements → X register
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rn_field}, _rn_64));")
                code.append(f"{ind}return result;")
                return code

        # Special case: INS (GPR→vector element) — decode imm5 for element size and index
        if mnemonic == 'INS' and 'ir_r' in encoding_name and 'Rd' in field_map and 'Rn' in field_map and 'imm5' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            imm5_field = field_map['imm5']['name']
            code.append(f"{ind}uint32_t _imm5 = enc.{member_name}.{imm5_field};")
            code.append(f"{ind}{{")
            code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false);")
            code.append(f"{ind}    uint32_t idx = 0;")
            code.append(f'{ind}    if (_imm5 & 1) {{ op.arrangement = Arrangement::B; idx = _imm5 >> 1; }}')
            code.append(f'{ind}    else if (_imm5 & 2) {{ op.arrangement = Arrangement::H; idx = _imm5 >> 2; }}')
            code.append(f'{ind}    else if (_imm5 & 4) {{ op.arrangement = Arrangement::S; idx = _imm5 >> 3; }}')
            code.append(f'{ind}    else if (_imm5 & 8) {{ op.arrangement = Arrangement::D; idx = _imm5 >> 4; }}')
            code.append(f"{ind}    op.index = idx;")
            code.append(f"{ind}    op.has_index = true;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            # Source is GPR: B/H/S → W register, D → X register
            code.append(f"{ind}bool _rn_64 = !(_imm5 & 0x7);")  # D elements → X register
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rn_field}, _rn_64));")
            code.append(f"{ind}return result;")
            return code

        # Special case: INS (vector→vector element) — decode imm5 and imm4 for element indices
        if mnemonic == 'INS' and 'iv_v' in encoding_name and 'Rd' in field_map and 'Rn' in field_map and 'imm5' in field_map and 'imm4' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            imm5_field = field_map['imm5']['name']
            imm4_field = field_map['imm4']['name']
            code.append(f"{ind}uint32_t _imm5 = enc.{member_name}.{imm5_field};")
            code.append(f"{ind}uint32_t _imm4 = enc.{member_name}.{imm4_field};")
            # Destination element
            code.append(f"{ind}{{")
            code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false);")
            code.append(f"{ind}    uint32_t idx = 0;")
            code.append(f'{ind}    if (_imm5 & 1) {{ op.arrangement = Arrangement::B; idx = _imm5 >> 1; }}')
            code.append(f'{ind}    else if (_imm5 & 2) {{ op.arrangement = Arrangement::H; idx = _imm5 >> 2; }}')
            code.append(f'{ind}    else if (_imm5 & 4) {{ op.arrangement = Arrangement::S; idx = _imm5 >> 3; }}')
            code.append(f'{ind}    else if (_imm5 & 8) {{ op.arrangement = Arrangement::D; idx = _imm5 >> 4; }}')
            code.append(f"{ind}    op.index = idx;")
            code.append(f"{ind}    op.has_index = true;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            # Source element
            code.append(f"{ind}{{")
            code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false);")
            code.append(f"{ind}    uint32_t idx2 = 0;")
            code.append(f'{ind}    if (_imm5 & 1) {{ op.arrangement = Arrangement::B; idx2 = _imm4; }}')
            code.append(f'{ind}    else if (_imm5 & 2) {{ op.arrangement = Arrangement::H; idx2 = _imm4 >> 1; }}')
            code.append(f'{ind}    else if (_imm5 & 4) {{ op.arrangement = Arrangement::S; idx2 = _imm4 >> 2; }}')
            code.append(f'{ind}    else if (_imm5 & 8) {{ op.arrangement = Arrangement::D; idx2 = _imm4 >> 3; }}')
            code.append(f"{ind}    op.index = idx2;")
            code.append(f"{ind}    op.has_index = true;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            code.append(f"{ind}return result;")
            return code

        # Special case: DUP scalar (asisdone_only) — Rd is scalar, Vn.Ts[index]
        if mnemonic == 'DUP' and 'asisdone' in encoding_name and 'Rd' in field_map and 'Rn' in field_map and 'imm5' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            imm5_field = field_map['imm5']['name']
            code.append(f"{ind}uint32_t _imm5 = enc.{member_name}.{imm5_field};")
            # Destination: scalar register (B/H/S/D prefix based on element size)
            code.append(f"{ind}{{")
            code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false);")
            code.append(f'{ind}    if (_imm5 & 1) op.arrangement = Arrangement::B;')
            code.append(f'{ind}    else if (_imm5 & 2) op.arrangement = Arrangement::H;')
            code.append(f'{ind}    else if (_imm5 & 4) op.arrangement = Arrangement::S;')
            code.append(f'{ind}    else op.arrangement = Arrangement::D;')
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            # Source: Vn.Ts[index]
            code.append(f"{ind}{{")
            code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false);")
            code.append(f"{ind}    uint32_t idx = 0;")
            code.append(f'{ind}    if (_imm5 & 1) {{ op.arrangement = Arrangement::B; idx = _imm5 >> 1; }}')
            code.append(f'{ind}    else if (_imm5 & 2) {{ op.arrangement = Arrangement::H; idx = _imm5 >> 2; }}')
            code.append(f'{ind}    else if (_imm5 & 4) {{ op.arrangement = Arrangement::S; idx = _imm5 >> 3; }}')
            code.append(f'{ind}    else if (_imm5 & 8) {{ op.arrangement = Arrangement::D; idx = _imm5 >> 4; }}')
            code.append(f"{ind}    op.index = idx;")
            code.append(f"{ind}    op.has_index = true;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            code.append(f"{ind}return result;")
            return code

        # Special case: DUP vector element (asimdins_DV_v) — Rd is vector with arrangement, Rn.Ts[index]
        if mnemonic == 'DUP' and 'dv_v' in encoding_name and 'Rd' in field_map and 'Rn' in field_map and 'imm5' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            imm5_field = field_map['imm5']['name']
            q_field = field_map['Q']['name'] if 'Q' in field_map else None
            code.append(f"{ind}uint32_t _imm5 = enc.{member_name}.{imm5_field};")
            # Destination: vector with arrangement from Q and imm5
            if q_field:
                code.append(f"{ind}bool _q = enc.{member_name}.{q_field};")
                code.append(f"{ind}Arrangement _dup_arr = Arrangement::None;")
                code.append(f"{ind}if (_imm5 & 1) _dup_arr = _q ? Arrangement::B16 : Arrangement::B8;")
                code.append(f"{ind}else if (_imm5 & 2) _dup_arr = _q ? Arrangement::H8 : Arrangement::H4;")
                code.append(f"{ind}else if (_imm5 & 4) _dup_arr = _q ? Arrangement::S4 : Arrangement::S2;")
                code.append(f"{ind}else _dup_arr = Arrangement::D2;")  # D only valid with Q=1
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _dup_arr; result.operands.push_back(op); }}")
            # Source: Vn.Ts[index]
            code.append(f"{ind}{{")
            code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false);")
            code.append(f"{ind}    uint32_t idx = 0;")
            code.append(f'{ind}    if (_imm5 & 1) {{ op.arrangement = Arrangement::B; idx = _imm5 >> 1; }}')
            code.append(f'{ind}    else if (_imm5 & 2) {{ op.arrangement = Arrangement::H; idx = _imm5 >> 2; }}')
            code.append(f'{ind}    else if (_imm5 & 4) {{ op.arrangement = Arrangement::S; idx = _imm5 >> 3; }}')
            code.append(f'{ind}    else if (_imm5 & 8) {{ op.arrangement = Arrangement::D; idx = _imm5 >> 4; }}')
            code.append(f"{ind}    op.index = idx;")
            code.append(f"{ind}    op.has_index = true;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            code.append(f"{ind}return result;")
            return code

        # Special case: LUTI4 — lookup table with 4-bit indices
        # L5 (byte): LUTI4 <Vd>.16B, { <Vn>.16B }, <Vm>[<index>]  — len[1] is index (1 bit)
        # L7 (halfword): LUTI4 <Vd>.8H, { <Vn1>.8H, <Vn2>.8H }, <Vm>[<index>]  — len is index (2 bits)
        if mnemonic == 'LUTI4' and 'asimdtbl' in encoding_name and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            rm_field = field_map['Rm']['name']
            len_field = field_map['len']['name'] if 'len' in field_map else None
            _enc_lc = encoding_name.lower()
            if '_l5' in _enc_lc:
                # Byte variant: Vd.16B, { Vn.16B }, Vm[index]
                # len field is partial (x1), index = len[1] (bit 14)
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = Arrangement::B16; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegisterList, enc.{member_name}.{rn_field}, false); op.arrangement = Arrangement::B16; op.index = 1; result.operands.push_back(op); }}")
                if len_field:
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_field}, false); op.has_index = true; op.index = (enc.{member_name}.{len_field} >> 1); result.operands.push_back(op); }}")
                else:
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_field}, false); result.operands.push_back(op); }}")
            else:
                # Halfword variant: Vd.8H, { Vn1.8H, Vn2.8H }, Vm[index]
                # len field = index (2 bits)
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = Arrangement::H8; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegisterList, enc.{member_name}.{rn_field}, false); op.arrangement = Arrangement::H8; op.index = 2; result.operands.push_back(op); }}")
                if len_field:
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_field}, false); op.has_index = true; op.index = enc.{member_name}.{len_field}; result.operands.push_back(op); }}")
                else:
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_field}, false); result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: TBL/TBX — byte arrangement, Rn is register list
        if mnemonic in ['TBL', 'TBX'] and 'asimdtbl' in encoding_name and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            rm_field = field_map['Rm']['name']
            q_field = field_map['Q']['name'] if 'Q' in field_map else None
            # Get number of table registers from 'len' field or encoding name
            num_regs = 1
            if 'L2_2' in encoding_name or 'l2_2' in encoding_name:
                num_regs = 2
            elif 'L3_3' in encoding_name or 'l3_3' in encoding_name:
                num_regs = 3
            elif 'L4_4' in encoding_name or 'l4_4' in encoding_name:
                num_regs = 4
            # Rd: vector with Q-dependent arrangement (8b/16b)
            if q_field:
                code.append(f'{ind}Arrangement _tbl_arr = enc.{member_name}.{q_field} ? Arrangement::B16 : Arrangement::B8;')
            else:
                code.append(f'{ind}Arrangement _tbl_arr = Arrangement::B16;')
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _tbl_arr; result.operands.push_back(op); }}")
            # Rn: vector register list with .16b arrangement (always 16b regardless of Q)
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegisterList, enc.{member_name}.{rn_field}, false); op.arrangement = Arrangement::B16; op.index = {num_regs}; result.operands.push_back(op); }}")
            # Rm: vector with Q-dependent arrangement
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_field}, false); op.arrangement = _tbl_arr; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: SIMD structure loads/stores (LD1-4/ST1-4 with asisdlse/asisdlsep encodings)
        is_simd_struct = mnemonic in ['LD1', 'LD2', 'LD3', 'LD4', 'ST1', 'ST2', 'ST3', 'ST4'] and ('asisdlse' in encoding_name)
        if is_simd_struct and 'Rt' in field_map and 'Rn' in field_map:
            rt_field = field_map['Rt']['name']
            rn_field = field_map['Rn']['name']

            # Determine number of registers from encoding name
            # LD1: R1_1v/R2_2v/R3_3v/R4_4v or I1_i1/R1_r1 etc.
            # LD2/LD3/LD4: always use their mnemonic count
            num_regs = 1
            if mnemonic in ['LD2', 'ST2']:
                num_regs = 2
            elif mnemonic in ['LD3', 'ST3']:
                num_regs = 3
            elif mnemonic in ['LD4', 'ST4']:
                num_regs = 4
            else:
                # LD1/ST1: parse from encoding name (R1_1v, R2_2v, R3_3v, R4_4v, I1/I2/I3/I4, etc.)
                import re as _re
                m = _re.search(r'[ri](\d)', encoding_name)
                if m:
                    num_regs = int(m.group(1))

            # Arrangement from Q and size fields
            if 'Q' in field_map and 'size' in field_map:
                q_field = field_map['Q']['name']
                size_field = field_map['size']['name']
                q_fixed = field_map['Q']['is_fixed']
                size_fixed = field_map['size']['is_fixed']

                if not q_fixed and not size_fixed:
                    code.append(f"{ind}Arrangement _arr = Arrangement::None;")
                    code.append(f"{ind}{{")
                    code.append(f'{ind}    static const Arrangement arrs[2][4] = {{')
                    code.append(f'{ind}        {{Arrangement::B8, Arrangement::H4, Arrangement::S2, Arrangement::D1}},')
                    code.append(f'{ind}        {{Arrangement::B16, Arrangement::H8, Arrangement::S4, Arrangement::D2}}')
                    code.append(f'{ind}    }};')
                    code.append(f"{ind}    _arr = arrs[enc.{member_name}.{q_field}][enc.{member_name}.{size_field}];")
                    code.append(f"{ind}}}")
                elif q_fixed and not size_fixed:
                    q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                    arrs = [["Arrangement::B8", "Arrangement::H4", "Arrangement::S2", "Arrangement::D1"], ["Arrangement::B16", "Arrangement::H8", "Arrangement::S4", "Arrangement::D2"]]
                    code.append(f"{ind}Arrangement _arr = Arrangement::None;")
                    arr_list = arrs[q_val]
                    code.append(f'{ind}{{ static const Arrangement arrs[] = {{{arr_list[0]}, {arr_list[1]}, {arr_list[2]}, {arr_list[3]}}}; _arr = arrs[enc.{member_name}.{size_field}]; }}')
                elif not q_fixed and size_fixed:
                    size_val = int(field_map['size']['fixed'], 2) if field_map['size']['fixed'] else 0
                    arrs = {0: ["Arrangement::B8", "Arrangement::B16"], 1: ["Arrangement::H4", "Arrangement::H8"], 2: ["Arrangement::S2", "Arrangement::S4"], 3: ["Arrangement::D1", "Arrangement::D2"]}
                    code.append(f"{ind}Arrangement _arr = enc.{member_name}.{q_field} ? {arrs[size_val][1]} : {arrs[size_val][0]};")
                else:
                    q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                    size_val = int(field_map['size']['fixed'], 2) if field_map['size']['fixed'] else 0
                    arrs = [["Arrangement::B8", "Arrangement::H4", "Arrangement::S2", "Arrangement::D1"], ["Arrangement::B16", "Arrangement::H8", "Arrangement::S4", "Arrangement::D2"]]
                    code.append(f'{ind}Arrangement _arr = {arrs[q_val][size_val]};')
            else:
                code.append(f'{ind}Arrangement _arr = Arrangement::None;')

            # Vector register list operand: { Vt.T, V(t+1).T, ... }
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegisterList, enc.{member_name}.{rt_field}, false);")
            code.append(f"{ind}  op.index = {num_regs}; op.arrangement = _arr; result.operands.push_back(op); }}")

            # Memory base operand: [Xn|SP]
            is_post_index = 'asisdlsep' in encoding_name
            if is_post_index and 'Rm' in field_map and not field_map['Rm']['is_fixed']:
                rm_field = field_map['Rm']['name']
                # Post-index with register: [Xn], Xm
                code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rm_field}, true));")
            elif is_post_index:
                # Post-index with immediate: [Xn], #imm
                # Immediate = num_regs * (Q ? 16 : 8) for LD1/ST1
                # For LD2-4/ST2-4: num_regs * (Q ? 16 : 8)
                if 'Q' in field_map and not field_map['Q']['is_fixed']:
                    q_field = field_map['Q']['name']
                    code.append(f"{ind}int32_t _post_imm = enc.{member_name}.{q_field} ? {num_regs * 16} : {num_regs * 8};")
                elif 'Q' in field_map:
                    q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                    post_imm = num_regs * 16 if q_val else num_regs * 8
                    code.append(f"{ind}int32_t _post_imm = {post_imm};")
                else:
                    code.append(f"{ind}int32_t _post_imm = {num_regs * 8};")
                code.append(f"{ind}result.operands.push_back(Operand::memory_post_index(enc.{member_name}.{rn_field}, _post_imm));")
            else:
                # No post-index: [Xn]
                code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")

            code.append(f"{ind}return result;")
            return code

        # Special case: SIMD single-structure loads/stores (asisdlso/asisdlsop)
        # These use per-lane indexing: { Vt.B, Vt2.B, ... }[idx], [Xn], ...
        is_simd_single = mnemonic in ['LD1', 'LD2', 'LD3', 'LD4', 'ST1', 'ST2', 'ST3', 'ST4', 'LDAP1', 'STL1'] and ('asisdlso' in encoding_name) and 'Rt' in field_map and 'Rn' in field_map
        if is_simd_single:
            rt_field = field_map['Rt']['name']
            rn_field = field_map['Rn']['name']

            # Element size from encoding name suffix
            enc_lower = encoding_name.lower()
            if '_b' in enc_lower.split('_')[-1] or enc_lower.endswith('b'):
                elem_arr = 'b'
            elif '_h' in enc_lower.split('_')[-1] or enc_lower.endswith('h'):
                elem_arr = 'h'
            elif '_s' in enc_lower.split('_')[-1] or enc_lower.endswith('s'):
                elem_arr = 's'
            elif '_d' in enc_lower.split('_')[-1] or enc_lower.endswith('d'):
                elem_arr = 'd'
            else:
                elem_arr = 'b'  # fallback

            # Number of registers
            num_regs = 1
            if mnemonic in ['LD2', 'ST2']:
                num_regs = 2
            elif mnemonic in ['LD3', 'ST3']:
                num_regs = 3
            elif mnemonic in ['LD4', 'ST4']:
                num_regs = 4

            # Element index from Q/S/size fields depending on element size
            has_q = 'Q' in field_map and not field_map['Q']['is_fixed']
            has_s = 'S' in field_map and not field_map['S']['is_fixed']
            has_size = 'size' in field_map and not field_map['size']['is_fixed']
            q_f = field_map['Q']['name'] if has_q else None
            s_f = field_map['S']['name'] if has_s else None
            size_f = field_map['size']['name'] if has_size else None

            code.append(f"{ind}uint32_t _elem_idx = 0;")
            if elem_arr == 'b' and has_q and has_s and has_size:
                code.append(f"{ind}_elem_idx = (enc.{member_name}.{q_f} << 3) | (enc.{member_name}.{s_f} << 2) | enc.{member_name}.{size_f};")
            elif elem_arr == 'h' and has_q and has_s and has_size:
                code.append(f"{ind}_elem_idx = (enc.{member_name}.{q_f} << 2) | (enc.{member_name}.{s_f} << 1) | (enc.{member_name}.{size_f} >> 1);")
            elif elem_arr == 's' and has_q and has_s:
                code.append(f"{ind}_elem_idx = (enc.{member_name}.{q_f} << 1) | enc.{member_name}.{s_f};")
            elif elem_arr == 'd' and has_q:
                code.append(f"{ind}_elem_idx = enc.{member_name}.{q_f};")

            # Vector register list with index
            code.append(f"{ind}{{")
            code.append(f"{ind}    Operand op(OperandType::VectorRegisterList, enc.{member_name}.{rt_field}, false);")
            code.append(f"{ind}    op.index = {num_regs};")
            code.append(f'{ind}    op.arrangement = {_CHAR_TO_ARR[elem_arr]};')
            code.append(f"{ind}    op.has_index = true;")
            code.append(f"{ind}    op.amount = _elem_idx;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")

            # Memory operand
            is_post_index = 'asisdlsop' in encoding_name
            if is_post_index and 'Rm' in field_map and not field_map['Rm']['is_fixed']:
                rm_field = field_map['Rm']['name']
                code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rm_field}, true));")
            elif is_post_index:
                # Post-index immediate depends on element size and num_regs
                elem_sizes = {'b': 1, 'h': 2, 's': 4, 'd': 8}
                post_imm = elem_sizes.get(elem_arr, 1) * num_regs
                code.append(f"{ind}result.operands.push_back(Operand::memory_post_index(enc.{member_name}.{rn_field}, {post_imm}));")
            else:
                code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")

            code.append(f"{ind}return result;")
            return code

        # Special case: SIMD replicate loads (LD1R/LD2R/LD3R/LD4R with asisdlso/asisdlsop)
        # Format: LD1R { Vt.T }, [Xn|SP] or with post-index
        is_simd_replicate = mnemonic in ['LD1R', 'LD2R', 'LD3R', 'LD4R'] and ('asisdlso' in encoding_name) and 'Rt' in field_map and 'Rn' in field_map
        if is_simd_replicate:
            rt_field = field_map['Rt']['name']
            rn_field = field_map['Rn']['name']
            num_regs = {'LD1R': 1, 'LD2R': 2, 'LD3R': 3, 'LD4R': 4}[mnemonic]

            # Arrangement from Q and size fields
            has_q = 'Q' in field_map and not field_map['Q']['is_fixed']
            has_size = 'size' in field_map and not field_map['size']['is_fixed']
            q_f = field_map['Q']['name'] if has_q else None
            size_f = field_map['size']['name'] if has_size else None

            if has_q and has_size:
                code.append(f"{ind}static const Arrangement _rep_arrs[2][4] = {{")
                code.append(f'{ind}    {{Arrangement::B8, Arrangement::H4, Arrangement::S2, Arrangement::D1}},')
                code.append(f'{ind}    {{Arrangement::B16, Arrangement::H8, Arrangement::S4, Arrangement::D2}}')
                code.append(f"{ind}}};")
                code.append(f"{ind}Arrangement _rep_arr = _rep_arrs[enc.{member_name}.{q_f}][enc.{member_name}.{size_f}];")
            elif has_size:
                q_val = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['fixed'] else 0
                arrs = [["Arrangement::B8", "Arrangement::H4", "Arrangement::S2", "Arrangement::D1"], ["Arrangement::B16", "Arrangement::H8", "Arrangement::S4", "Arrangement::D2"]]
                code.append(f'{ind}static const Arrangement _rep_arrs[] = {{{arrs[q_val][0]}, {arrs[q_val][1]}, {arrs[q_val][2]}, {arrs[q_val][3]}}};')
                code.append(f"{ind}Arrangement _rep_arr = _rep_arrs[enc.{member_name}.{size_f}];")
            else:
                code.append(f'{ind}Arrangement _rep_arr = Arrangement::B8;  // fallback')

            # Vector register list (no element index)
            code.append(f"{ind}{{")
            code.append(f"{ind}    Operand op(OperandType::VectorRegisterList, enc.{member_name}.{rt_field}, false);")
            code.append(f"{ind}    op.index = {num_regs};")
            code.append(f"{ind}    op.arrangement = _rep_arr;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")

            # Memory operand
            is_post_index = 'asisdlsop' in encoding_name
            if is_post_index and 'Rm' in field_map and not field_map['Rm']['is_fixed']:
                rm_field = field_map['Rm']['name']
                code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rm_field}, true));")
            elif is_post_index:
                # Post-index immediate: element_size * num_regs
                code.append(f"{ind}{{")
                code.append(f"{ind}    static const uint32_t _elem_sizes[] = {{1, 2, 4, 8}};")
                if has_size:
                    code.append(f"{ind}    uint32_t _post_imm = _elem_sizes[enc.{member_name}.{size_f}] * {num_regs};")
                else:
                    code.append(f"{ind}    uint32_t _post_imm = {num_regs};  // byte")
                code.append(f"{ind}    result.operands.push_back(Operand::memory_post_index(enc.{member_name}.{rn_field}, _post_imm));")
                code.append(f"{ind}}}")
            else:
                code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")

            code.append(f"{ind}return result;")
            return code

        # Special case: SIMD/scalar shift-by-immediate (asimdshf/asisdshf) — arrangement from immh, shift from immh:immb
        is_shift_by_imm = ('asimdshf' in encoding_name or 'asisdshf' in encoding_name) \
                          and 'Rd' in field_map and 'Rn' in field_map and 'immh' in field_map
        if is_shift_by_imm:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            immh_field = field_map['immh']['name']
            immb_field = field_map['immb']['name'] if 'immb' in field_map else None
            has_q = 'Q' in field_map and not field_map['Q']['is_fixed']
            q_field = field_map['Q']['name'] if has_q else None
            q_fixed_val = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['is_fixed'] and field_map['Q']['fixed'] else 0

            # Scalar shift-by-immediate (asisdshf): no Q field at all — emit scalar FP registers
            is_scalar_shf = 'Q' not in field_map
            if is_scalar_shf:
                is_fp_convert = any(m in mnemonic for m in ['FCVT', 'SCVTF', 'UCVTF'])
                code.append(f"{ind}uint32_t _immh = enc.{member_name}.{immh_field};")
                if immb_field:
                    code.append(f"{ind}uint32_t _immb = enc.{member_name}.{immb_field};")
                else:
                    code.append(f"{ind}uint32_t _immb = 0;")
                code.append(f"{ind}uint32_t _immhb = (_immh << 3) | _immb;")
                code.append(f"{ind}int _esize = 0; Arrangement _fp_arr = Arrangement::None;")
                code.append(f"{ind}if (_immh & 0x8) {{ _esize = 64; _fp_arr = Arrangement::D; }}")
                code.append(f"{ind}else if (_immh & 0x4) {{ _esize = 32; _fp_arr = Arrangement::S; }}")
                code.append(f"{ind}else if (_immh & 0x2) {{ _esize = 16; _fp_arr = Arrangement::H; }}")
                code.append(f"{ind}else if (_immh & 0x1) {{ _esize = 8; _fp_arr = Arrangement::B; }}")
                # Scalar narrowing: Rd = narrow arrangement, Rn = wider arrangement
                scalar_narrow_ops = ['SQRSHRN', 'SQSHRN', 'UQRSHRN', 'UQSHRN', 'SQRSHRUN', 'SQSHRUN']
                is_scalar_narrow = mnemonic in scalar_narrow_ops
                if is_scalar_narrow:
                    code.append(f"{ind}Arrangement _narrow_arr = _fp_arr;")
                    code.append(f"{ind}Arrangement _wide_arr = Arrangement::None;")
                    code.append(f"{ind}if (_esize == 8) _wide_arr = Arrangement::H;")
                    code.append(f"{ind}else if (_esize == 16) _wide_arr = Arrangement::S;")
                    code.append(f"{ind}else if (_esize == 32) _wide_arr = Arrangement::D;")
                    code.append(f"{ind}else _wide_arr = Arrangement::D;")
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _narrow_arr; result.operands.push_back(op); }}")
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = _wide_arr; result.operands.push_back(op); }}")
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (_esize * 2) - (int)_immhb, true));")
                else:
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _fp_arr; result.operands.push_back(op); }}")
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = _fp_arr; result.operands.push_back(op); }}")
                    if is_fp_convert:
                        code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (_esize * 2) - (int)_immhb, true));  // fbits")
                    else:
                        code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (int)_immhb - _esize, true));  // shift left")
                code.append(f"{ind}return result;")
                return code

            # Determine if this is narrowing (SHRN, RSHRN, SQSHRN, etc.) or widening (SSHLL, USHLL)
            narrowing_ops = ['SHRN', 'RSHRN', 'SQSHRN', 'UQSHRN', 'SQRSHRN', 'UQRSHRN', 'SQSHRUN', 'SQRSHRUN', 'XTN']
            widening_ops = ['SSHLL', 'USHLL']
            is_narrowing = mnemonic in narrowing_ops
            is_widening = mnemonic in widening_ops

            # immh determines element size: highest set bit position
            # immh=0001 → 8-bit, immh=001x → 16-bit, immh=01xx → 32-bit, immh=1xxx → 64-bit
            # Arrangement: Q=0 → 8b/4h/2s, Q=1 → 16b/8h/4s (narrowing dest uses Q for narrow side)
            code.append(f"{ind}uint32_t _immh = enc.{member_name}.{immh_field};")
            if immb_field:
                code.append(f"{ind}uint32_t _immb = enc.{member_name}.{immb_field};")
            else:
                code.append(f"{ind}uint32_t _immb = 0;")
            code.append(f"{ind}uint32_t _immhb = (_immh << 3) | _immb;")

            # Compute element size from immh
            code.append(f"{ind}int _esize = 0;")
            code.append(f"{ind}Arrangement _narrow_arr = Arrangement::None;")
            code.append(f"{ind}Arrangement _wide_arr = Arrangement::None;")
            code.append(f"{ind}Arrangement _same_arr = Arrangement::None;")
            code.append(f"{ind}uint32_t _shift = 0;")
            if has_q:
                code.append(f"{ind}uint32_t _q = enc.{member_name}.{q_field};")
            else:
                code.append(f"{ind}uint32_t _q = {q_fixed_val};")

            # Determine arrangement and shift based on immh
            code.append(f"{ind}if (_immh & 0x8) {{ _esize = 64; _narrow_arr = _q ? Arrangement::S4 : Arrangement::S2; _wide_arr = Arrangement::D2; _same_arr = _q ? Arrangement::D2 : Arrangement::D1; }}")
            code.append(f"{ind}else if (_immh & 0x4) {{ _esize = 32; _narrow_arr = _q ? Arrangement::H8 : Arrangement::H4; _wide_arr = _q ? Arrangement::S4 : Arrangement::S2; _same_arr = _q ? Arrangement::S4 : Arrangement::S2; }}")
            code.append(f"{ind}else if (_immh & 0x2) {{ _esize = 16; _narrow_arr = _q ? Arrangement::B16 : Arrangement::B8; _wide_arr = _q ? Arrangement::H8 : Arrangement::H4; _same_arr = _q ? Arrangement::H8 : Arrangement::H4; }}")
            code.append(f"{ind}else if (_immh & 0x1) {{ _esize = 8; _narrow_arr = _q ? Arrangement::B16 : Arrangement::B8; _wide_arr = _q ? Arrangement::H8 : Arrangement::H4; _same_arr = _q ? Arrangement::B16 : Arrangement::B8; }}")

            if is_narrowing:
                # Narrowing: Rd = narrow arrangement, Rn = wide arrangement (always 8h/4s/2d)
                # Shift amount: (esize * 2) - immhb  (right shift from wider element)
                code.append(f"{ind}_shift = (_esize * 2) - _immhb;")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _narrow_arr; result.operands.push_back(op); }}")
                # Wide source arrangement: 8h for 8-bit, 4s for 16-bit, 2d for 32-bit
                code.append(f"{ind}Arrangement _src_arr = Arrangement::None;")
                code.append(f"{ind}if (_esize == 8) _src_arr = Arrangement::H8;")
                code.append(f"{ind}else if (_esize == 16) _src_arr = Arrangement::S4;")
                code.append(f"{ind}else if (_esize == 32) _src_arr = Arrangement::D2;")
                code.append(f"{ind}else _src_arr = Arrangement::D2;")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = _src_arr; result.operands.push_back(op); }}")
            elif is_widening:
                # Widening: Rd = double-width arrangement, Rn = source arrangement at _esize
                # Shift amount: immhb - esize (left shift)
                code.append(f"{ind}_shift = _immhb - _esize;")
                # Destination: always double-width (8h for 8-bit src, 4s for 16-bit src, 2d for 32-bit src)
                code.append(f"{ind}Arrangement _dst_arr = Arrangement::None;")
                code.append(f"{ind}if (_esize == 8) _dst_arr = Arrangement::H8;")
                code.append(f"{ind}else if (_esize == 16) _dst_arr = Arrangement::S4;")
                code.append(f"{ind}else if (_esize == 32) _dst_arr = Arrangement::D2;")
                code.append(f"{ind}else _dst_arr = Arrangement::D2;")
                # Source: same element size as _esize, count depends on Q
                code.append(f"{ind}Arrangement _widen_src_arr = Arrangement::None;")
                code.append(f"{ind}if (_esize == 8) _widen_src_arr = _q ? Arrangement::B16 : Arrangement::B8;")
                code.append(f"{ind}else if (_esize == 16) _widen_src_arr = _q ? Arrangement::H8 : Arrangement::H4;")
                code.append(f"{ind}else if (_esize == 32) _widen_src_arr = _q ? Arrangement::S4 : Arrangement::S2;")
                code.append(f"{ind}else _widen_src_arr = _q ? Arrangement::D2 : Arrangement::D1;")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _dst_arr; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = _widen_src_arr; result.operands.push_back(op); }}")
            else:
                # Same-width: both Rd and Rn use same arrangement
                # Right shift: shift = (esize * 2) - immhb for SSHR/USHR/SSRA/USRA/SRSHR/URSHR/SRSRA/URSRA
                # Left shift: shift = immhb - esize for SHL/SQSHL/UQSHL/SQSHLU/SLI/SRI
                left_shift_ops = ['SHL', 'SQSHL', 'UQSHL', 'SQSHLU', 'SLI']
                if mnemonic in left_shift_ops:
                    code.append(f"{ind}_shift = _immhb - _esize;")
                else:
                    code.append(f"{ind}_shift = (_esize * 2) - _immhb;")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _same_arr; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = _same_arr; result.operands.push_back(op); }}")

            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, _shift, true));")
            code.append(f"{ind}return result;")
            return code

        # Special case: FCMLA indexed element (FCMLA_advsimd_elt)
        # Template: FCMLA <Vd>.<T>, <Vn>.<T>, <Vm>.<Ts>[<index>], #<rotate>
        # m = UInt(M::Rm) always (M is always part of register, not index)
        # size=01 (FP16): T=.4h/.8h, Ts=.h, index=H::L (2-bit)
        # size=10 (FP32): T=.2s/.4s, Ts=.s, index=H (1-bit)
        # rot field: 0→#0, 1→#90, 2→#180, 3→#270
        is_fcmla_elt = mnemonic == 'FCMLA' and 'advsimd_elt' in encoding_name.lower() and \
                       'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_fcmla_elt:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            q_var = 'Q' in field_map and not field_map['Q']['is_fixed']
            q_field_n = field_map['Q']['name'] if q_var else None
            size_f = field_map['size']['name'] if 'size' in field_map and not field_map['size']['is_fixed'] else None
            m_f = field_map['M']['name'] if 'M' in field_map and not field_map['M']['is_fixed'] else None
            h_f = field_map['H']['name'] if 'H' in field_map and not field_map['H']['is_fixed'] else None
            l_f = field_map['L']['name'] if 'L' in field_map and not field_map['L']['is_fixed'] else None
            rot_f = field_map['rot']['name'] if 'rot' in field_map and not field_map['rot']['is_fixed'] else None
            # Vector arrangement from Q and size
            if q_var and size_f:
                code.append(f"{ind}static const Arrangement _fcmla_arrs[2][4] = {{{{Arrangement::B8,Arrangement::H4,Arrangement::S2,Arrangement::D1}},{{Arrangement::B16,Arrangement::H8,Arrangement::S4,Arrangement::D2}}}};")
                code.append(f"{ind}Arrangement _arr = _fcmla_arrs[enc.{member_name}.{q_field_n}][enc.{member_name}.{size_f}];")
            else:
                code.append(f'{ind}Arrangement _arr = Arrangement::H8;  // fallback')
            # Rd and Rn use the same arrangement T
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = _arr; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = _arr; result.operands.push_back(op); }}")
            # Vm: register = M::Rm (always), scalar arrangement Ts, index from H/L or H
            code.append(f"{ind}{{")
            if m_f:
                code.append(f"{ind}    uint32_t _vm_reg = (enc.{member_name}.{m_f} << 4) | enc.{member_name}.{rm_f};")
            else:
                code.append(f"{ind}    uint32_t _vm_reg = enc.{member_name}.{rm_f};")
            # Scalar type: h for size=01, s for size=10
            if size_f:
                code.append(f"{ind}    Arrangement _ts = (enc.{member_name}.{size_f} == 1) ? Arrangement::H : Arrangement::S;")
            else:
                code.append(f'{ind}    Arrangement _ts = Arrangement::H;')
            # index: H:L for size=01 (2-bit), H for size=10 (1-bit)
            code.append(f"{ind}    uint32_t _idx = 0;")
            if h_f and l_f and size_f:
                code.append(f"{ind}    if (enc.{member_name}.{size_f} == 1) _idx = (enc.{member_name}.{h_f} << 1) | enc.{member_name}.{l_f};")
                code.append(f"{ind}    else _idx = enc.{member_name}.{h_f};")
            elif h_f and l_f:
                code.append(f"{ind}    _idx = (enc.{member_name}.{h_f} << 1) | enc.{member_name}.{l_f};")
            elif h_f:
                code.append(f"{ind}    _idx = enc.{member_name}.{h_f};")
            code.append(f"{ind}    Operand op(OperandType::VectorRegister, _vm_reg, false);")
            code.append(f"{ind}    op.arrangement = _ts;")
            code.append(f"{ind}    op.index = _idx;")
            code.append(f"{ind}    op.has_index = true;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            # Rotation immediate: 0→0, 1→90, 2→180, 3→270
            if rot_f:
                code.append(f"{ind}{{")
                code.append(f"{ind}    static const int32_t _rot_vals[] = {{0, 90, 180, 270}};")
                code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Immediate, _rot_vals[enc.{member_name}.{rot_f}], true));")
                code.append(f"{ind}    result.operands.back().prefer_decimal = true;")
                code.append(f"{ind}}}")
            code.append(f"{ind}return result;")
            return code

        # Special case: SIMD by-element (asimdelem) — Rm has element index from H/L/M fields
        is_asimdelem = ('asimdelem' in encoding_name or 'asisdelem' in encoding_name) and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_asimdelem:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            rm_field = field_map['Rm']['name']
            _enc_lc = encoding_name.lower()
            is_scalar_elem = 'asisdelem' in encoding_name

            # Special case: Scalar by-element (asisdelem) — Rd/Rn are scalar FP regs
            # RH_H: halfword scalar, index=H:L:M (3-bit), Rm=4-bit
            # R_SD: single/double scalar, index depends on sz
            if is_scalar_elem:
                has_h = 'H' in field_map and not field_map['H']['is_fixed']
                has_l = 'L' in field_map and not field_map['L']['is_fixed']
                has_m = 'M' in field_map and not field_map['M']['is_fixed']
                h_f = field_map['H']['name'] if has_h else None
                l_f = field_map['L']['name'] if has_l else None
                m_f = field_map['M']['name'] if has_m else None
                if '_rh_h' in _enc_lc:
                    # FP16 scalar: Hd, Hn, Vm.H[H:L:M]
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = Arrangement::H; result.operands.push_back(op); }}")
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = Arrangement::H; result.operands.push_back(op); }}")
                    code.append(f"{ind}{{")
                    code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_field}, false);")
                    code.append(f"{ind}    op.arrangement = Arrangement::H;")
                    if h_f and l_f and m_f:
                        code.append(f"{ind}    op.index = (enc.{member_name}.{h_f} << 2) | (enc.{member_name}.{l_f} << 1) | enc.{member_name}.{m_f};")
                    else:
                        code.append(f"{ind}    op.index = 0;")
                    code.append(f"{ind}    op.has_index = true;")
                    code.append(f"{ind}    result.operands.push_back(op);")
                    code.append(f"{ind}}}")
                else:
                    # Single/Double scalar: <V><d>, <V><n>, <Vm>.<Ts>[<index>]
                    # sz field determines precision: 0→S, 1→D
                    sz_f = field_map['sz']['name'] if 'sz' in field_map and not field_map['sz']['is_fixed'] else None
                    if sz_f:
                        code.append(f"{ind}Arrangement _sc_arr = enc.{member_name}.{sz_f} ? Arrangement::D : Arrangement::S;")
                    else:
                        sz_val = int(field_map['sz']['fixed'], 2) if 'sz' in field_map and field_map['sz']['fixed'] else 0
                        code.append(f"{ind}Arrangement _sc_arr = {'Arrangement::D' if sz_val else 'Arrangement::S'};")
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _sc_arr; result.operands.push_back(op); }}")
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = _sc_arr; result.operands.push_back(op); }}")
                    code.append(f"{ind}{{")
                    if has_m:
                        code.append(f"{ind}    uint32_t _rm_reg = enc.{member_name}.{rm_field};")
                        code.append(f"{ind}    Arrangement _el_arr = _sc_arr;")
                        if sz_f:
                            code.append(f"{ind}    if (!enc.{member_name}.{sz_f}) _rm_reg |= (enc.{member_name}.{m_f} << 4);  // S: M extends Rm")
                        else:
                            if sz_val == 0:
                                code.append(f"{ind}    _rm_reg |= (enc.{member_name}.{m_f} << 4);  // S: M extends Rm")
                        code.append(f"{ind}    Operand op(OperandType::VectorRegister, _rm_reg, false);")
                        code.append(f"{ind}    op.arrangement = _el_arr;")
                    else:
                        code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_field}, false);")
                        code.append(f"{ind}    op.arrangement = _sc_arr;")
                    # Index: sz=0(S) → H:L (2-bit), sz=1(D) → H (1-bit)
                    if h_f and has_l:
                        if sz_f:
                            code.append(f"{ind}    op.index = enc.{member_name}.{sz_f} ? enc.{member_name}.{h_f} : ((enc.{member_name}.{h_f} << 1) | enc.{member_name}.{l_f});")
                        else:
                            if sz_val == 0:
                                code.append(f"{ind}    op.index = (enc.{member_name}.{h_f} << 1) | enc.{member_name}.{l_f};")
                            else:
                                code.append(f"{ind}    op.index = enc.{member_name}.{h_f};")
                    elif h_f:
                        code.append(f"{ind}    op.index = enc.{member_name}.{h_f};")
                    else:
                        code.append(f"{ind}    op.index = 0;")
                    code.append(f"{ind}    op.has_index = true;")
                    code.append(f"{ind}    result.operands.push_back(op);")
                    code.append(f"{ind}}}")
                code.append(f"{ind}return result;")
                return code

            # Special case: FMLALB/FMLALT asimdelem_H (FP8 by-element)
            # Template: FMLALB <Vd>.8H, <Vn>.16B, <Vm>.B[H:L:M:Rm[3]]
            # Vm register = Rm[2:0] (v0-v7), index = H:L:M:Rm[3] (4-bit, 0-15)
            if 'fmlalb_asimdelem_h' in _enc_lc or 'fmlalt_asimdelem_h' in _enc_lc:
                _h_f = field_map['H']['name'] if 'H' in field_map else None
                _l_f = field_map['L']['name'] if 'L' in field_map else None
                _m_f = field_map['M']['name'] if 'M' in field_map else None
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = Arrangement::H8; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = Arrangement::B16; result.operands.push_back(op); }}")
                code.append(f"{ind}{{")
                code.append(f"{ind}    // FP8 by-element: Vm=Rm[2:0] (v0-v7), index=H:L:M:Rm[3] (4-bit)")
                code.append(f"{ind}    uint32_t _rm_val = enc.{member_name}.{rm_field};")
                code.append(f"{ind}    uint32_t _vm_reg = _rm_val & 0x7;  // Rm[2:0]")
                if _h_f and _l_f and _m_f:
                    code.append(f"{ind}    uint32_t _idx = (enc.{member_name}.{_h_f} << 3) | (enc.{member_name}.{_l_f} << 2) | (enc.{member_name}.{_m_f} << 1) | ((_rm_val >> 3) & 1);")
                else:
                    code.append(f"{ind}    uint32_t _idx = 0;")
                code.append(f"{ind}    Operand op(OperandType::VectorRegister, _vm_reg, false);")
                code.append(f"{ind}    op.arrangement = Arrangement::B;")
                code.append(f"{ind}    op.index = _idx;")
                code.append(f"{ind}    op.has_index = true;")
                code.append(f"{ind}    result.operands.push_back(op);")
                code.append(f"{ind}}}")
                code.append(f"{ind}return result;")
                return code

            # Special case: BFMLAL asimdelem_F (BF16 by-element)
            # Template: BFMLAL<bt> <Vd>.4S, <Vn>.8H, <Vm>.H[H:L:M]
            # Q=0 → BFMLALB, Q=1 → BFMLALT; Vm = full 4-bit Rm (v0-v15), index = H:L:M (3-bit)
            if 'bfmlal_asimdelem_f' in _enc_lc:
                _q_f = field_map['Q']['name'] if 'Q' in field_map and not field_map['Q']['is_fixed'] else None
                _h_f = field_map['H']['name'] if 'H' in field_map else None
                _l_f = field_map['L']['name'] if 'L' in field_map else None
                _m_f = field_map['M']['name'] if 'M' in field_map else None
                if _q_f:
                    code.append(f"{ind}result.mnemonic = enc.{member_name}.{_q_f} ? Mnemonic::BFMLALT : Mnemonic::BFMLALB;")
                else:
                    # Q is fixed: check value
                    _q_v = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['fixed'] else 0
                    code.append(f"{ind}result.mnemonic = Mnemonic::{'BFMLALT' if _q_v else 'BFMLALB'};")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = Arrangement::H8; result.operands.push_back(op); }}")
                code.append(f"{ind}{{")
                code.append(f"{ind}    // BF16 by-element: Vm=Rm (v0-v15, no M extension), index=H:L:M (3-bit)")
                if _h_f and _l_f and _m_f:
                    code.append(f"{ind}    uint32_t _idx = (enc.{member_name}.{_h_f} << 2) | (enc.{member_name}.{_l_f} << 1) | enc.{member_name}.{_m_f};")
                else:
                    code.append(f"{ind}    uint32_t _idx = 0;")
                code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_field}, false);")
                code.append(f"{ind}    op.arrangement = Arrangement::H;")
                code.append(f"{ind}    op.index = _idx;")
                code.append(f"{ind}    op.has_index = true;")
                code.append(f"{ind}    result.operands.push_back(op);")
                code.append(f"{ind}}}")
                code.append(f"{ind}return result;")
                return code

            # Special case: FMLALLBB/FMLALLBT/FMLALLTB/FMLALLTT by-element (asimdelem_J)
            # FP8→FP32: dest=.4s, src=.16b, Rm=.b[index from H:L:M:Rm[3]]
            if mnemonic in ['FMLALLBB', 'FMLALLBT', 'FMLALLTB', 'FMLALLTT'] and 'asimdelem_j' in _enc_lc:
                _h_f = field_map['H']['name'] if 'H' in field_map and not field_map['H']['is_fixed'] else None
                _l_f = field_map['L']['name'] if 'L' in field_map and not field_map['L']['is_fixed'] else None
                _m_f = field_map['M']['name'] if 'M' in field_map and not field_map['M']['is_fixed'] else None
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = Arrangement::B16; result.operands.push_back(op); }}")
                code.append(f"{ind}{{")
                code.append(f"{ind}    uint32_t _rm_val = enc.{member_name}.{rm_field};")
                code.append(f"{ind}    uint32_t _vm_reg = _rm_val & 0x7;  // Rm[2:0]")
                if _h_f and _l_f and _m_f:
                    code.append(f"{ind}    uint32_t _idx = (enc.{member_name}.{_h_f} << 3) | (enc.{member_name}.{_l_f} << 2) | (enc.{member_name}.{_m_f} << 1) | ((_rm_val >> 3) & 1);")
                else:
                    code.append(f"{ind}    uint32_t _idx = 0;")
                code.append(f"{ind}    Operand op(OperandType::VectorRegister, _vm_reg, false);")
                code.append(f"{ind}    op.arrangement = Arrangement::B;")
                code.append(f"{ind}    op.index = _idx; op.has_index = true;")
                code.append(f"{ind}    result.operands.push_back(op);")
                code.append(f"{ind}}}")
                code.append(f"{ind}return result;")
                return code

            # Special case: SUDOT/USDOT by-element (asimdelem_D)
            # dot product: dest=.2s/.4s (Q-dep), src=.8b, Rm=.4b[index]
            if mnemonic in ['SUDOT', 'USDOT'] and 'asimdelem_d' in _enc_lc:
                _q_f = field_map['Q']['name'] if 'Q' in field_map and not field_map['Q']['is_fixed'] else None
                _h_f = field_map['H']['name'] if 'H' in field_map and not field_map['H']['is_fixed'] else None
                _l_f = field_map['L']['name'] if 'L' in field_map and not field_map['L']['is_fixed'] else None
                if _q_f:
                    code.append(f"{ind}Arrangement _dst = enc.{member_name}.{_q_f} ? Arrangement::S4 : Arrangement::S2;")
                else:
                    _q_val = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['fixed'] else 0
                    code.append(f'{ind}Arrangement _dst = {"Arrangement::S4" if _q_val else "Arrangement::S2"};')
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _dst; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = Arrangement::B8; result.operands.push_back(op); }}")
                idx_expr = '0u'
                if _h_f and _l_f:
                    idx_expr = f"(enc.{member_name}.{_h_f} << 1) | enc.{member_name}.{_l_f}"
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_field}, false); op.arrangement = Arrangement::B4; op.index = {idx_expr}; op.has_index = true; result.operands.push_back(op); }}")
                code.append(f"{ind}return result;")
                return code

            # Compute arrangement from Q and size
            has_q = 'Q' in field_map
            has_size = 'size' in field_map
            q_fixed = field_map['Q']['is_fixed'] if has_q else True
            q_field = field_map['Q']['name'] if has_q and not q_fixed else None
            if has_q and has_size:
                size_fixed = field_map['size']['is_fixed']
                size_field = field_map['size']['name'] if not size_fixed else None

                if not q_fixed and not size_fixed:
                    code.append(f"{ind}Arrangement _simd_arr = Arrangement::None;")
                    code.append(f"{ind}{{")
                    code.append(f'{ind}    static const Arrangement arrs[2][4] = {{')
                    code.append(f'{ind}        {{Arrangement::B8, Arrangement::H4, Arrangement::S2, Arrangement::D1}},')
                    code.append(f'{ind}        {{Arrangement::B16, Arrangement::H8, Arrangement::S4, Arrangement::D2}}')
                    code.append(f'{ind}    }};')
                    code.append(f"{ind}    _simd_arr = arrs[enc.{member_name}.{q_field}][enc.{member_name}.{size_field}];")
                    code.append(f"{ind}}}")
                    code.append(f"{ind}uint32_t _sz = enc.{member_name}.{size_field};")
                elif q_fixed and not size_fixed:
                    q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                    arrs = [["Arrangement::B8", "Arrangement::H4", "Arrangement::S2", "Arrangement::D1"], ["Arrangement::B16", "Arrangement::H8", "Arrangement::S4", "Arrangement::D2"]]
                    arr_list = arrs[q_val]
                    code.append(f'{ind}static const Arrangement _elem_arrs[] = {{{arr_list[0]}, {arr_list[1]}, {arr_list[2]}, {arr_list[3]}}};')
                    code.append(f"{ind}Arrangement _simd_arr = _elem_arrs[enc.{member_name}.{size_field}];")
                    code.append(f"{ind}uint32_t _sz = enc.{member_name}.{size_field};")
                elif not q_fixed and size_fixed:
                    size_val = int(field_map['size']['fixed'], 2) if field_map['size']['fixed'] else 0
                    arrs = {0: ["Arrangement::B8", "Arrangement::B16"], 1: ["Arrangement::H4", "Arrangement::H8"], 2: ["Arrangement::S2", "Arrangement::S4"], 3: ["Arrangement::D1", "Arrangement::D2"]}
                    code.append(f"{ind}Arrangement _simd_arr = enc.{member_name}.{q_field} ? {arrs[size_val][1]} : {arrs[size_val][0]};")
                    code.append(f"{ind}uint32_t _sz = {size_val};")
                else:
                    q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                    size_val = int(field_map['size']['fixed'], 2) if field_map['size']['fixed'] else 0
                    arrs = [["Arrangement::B8", "Arrangement::H4", "Arrangement::S2", "Arrangement::D1"], ["Arrangement::B16", "Arrangement::H8", "Arrangement::S4", "Arrangement::D2"]]
                    code.append(f'{ind}Arrangement _simd_arr = {arrs[q_val][size_val]};')
                    code.append(f"{ind}uint32_t _sz = {size_val};")
            else:
                # No 2-bit size field — check for 1-bit sz (FP precision selector)
                if 'sz' in field_map and has_q:
                    sz_fixed = field_map['sz']['is_fixed']
                    sz_field_name = field_map['sz']['name']
                    if not sz_fixed:
                        # Variable sz: sz=0→single(.2s/.4s), sz=1→double(.1d/.2d)
                        code.append(f"{ind}Arrangement _simd_arr = Arrangement::None;")
                        code.append(f'{ind}static const Arrangement _fp_arrs[2][2] = {{{{Arrangement::S2,Arrangement::S4}},{{Arrangement::D1,Arrangement::D2}}}};')
                        if q_field:
                            code.append(f"{ind}_simd_arr = _fp_arrs[enc.{member_name}.{sz_field_name}][enc.{member_name}.{q_field}];")
                        else:
                            q_fv = int(field_map['Q']['fixed'], 2) if q_fixed and field_map['Q']['fixed'] else 0
                            code.append(f"{ind}_simd_arr = _fp_arrs[enc.{member_name}.{sz_field_name}][{q_fv}];")
                        code.append(f"{ind}uint32_t _sz = enc.{member_name}.{sz_field_name} + 2;  // 0→single(2), 1→double(3)")
                    else:
                        # Fixed sz: sz=0→H→S widening (_sz=1/halfword), sz=1→S→D (_sz=2/single)
                        sz_val = int(field_map['sz']['fixed'], 2) if field_map['sz']['fixed'] else 0
                        _sz_idx = sz_val + 1  # 0→1(half→single widening), 1→2(single→double widening)
                        src_arrs = [["Arrangement::H2", "Arrangement::H4"], ["Arrangement::S2", "Arrangement::S4"]]
                        if q_field:
                            code.append(f'{ind}Arrangement _simd_arr = enc.{member_name}.{q_field} ? {src_arrs[sz_val][1]} : {src_arrs[sz_val][0]};')
                        else:
                            q_fv = int(field_map['Q']['fixed'], 2) if q_fixed and field_map['Q']['fixed'] else 0
                            code.append(f'{ind}Arrangement _simd_arr = "{src_arrs[sz_val][q_fv]}";')
                        code.append(f"{ind}uint32_t _sz = {_sz_idx};")
                else:
                    code.append(f'{ind}Arrangement _simd_arr = Arrangement::None;')
                    code.append(f"{ind}uint32_t _sz = 0;")

            # Override arrangement for FP16 by-element encodings (size=0 but halfword elements)
            enc_lower_arr = encoding_name.lower()
            if '_rh_h' in enc_lower_arr and has_size and size_fixed:
                size_val_check = int(field_map['size']['fixed'], 2) if field_map['size']['fixed'] else -1
                if size_val_check == 0:
                    if has_q and not q_fixed:
                        code.append(f'{ind}_simd_arr = enc.{member_name}.{q_field} ? Arrangement::H8 : Arrangement::H4;')
                        code.append(f"{ind}_sz = 1;")  # halfword
                    elif has_q and q_fixed:
                        q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                        code.append(f'{ind}_simd_arr = {["Arrangement::H4", "Arrangement::H8"][q_val]};')
                        code.append(f"{ind}_sz = 1;")

            # Dot product ops: Rn uses byte arrangement, Rm uses grouped-byte arrangement
            dot_product_ops = ['SDOT', 'UDOT', 'USDOT', 'SUDOT', 'BFDOT', 'FDOT']
            is_dot_product = mnemonic in dot_product_ops

            # Rd and Rn use vector arrangement
            if is_dot_product:
                # Dot products: Rd is always result size (.2s/.4s for 8-bit dot, .4h/.8h for 16-bit FDOT)
                # FDOT (8-bit float): size=0, result is .2s/.4s
                # BFDOT (bf16): size=2, result is .2s/.4s
                # SDOT/UDOT (int8): size=2, result is .2s/.4s
                if mnemonic in ['FDOT']:
                    # FDOT_asimdelem_G: FP8→FP16 (2-way), size=1, dest=.4h/.8h, Rm=.2B[idx]
                    # FDOT_asimdelem_D: FP8→FP32 (4-way), size=0, dest=.2s/.4s, Rm=.4B[idx]
                    # FDOT_asimdelem_FP16FP32: FP16→FP32, size=1, dest=.2s/.4s, Rm=.2H[idx]
                    if 'asimdelem_g' in encoding_name.lower():
                        # FP8→FP16: dest is half-precision vector
                        if has_q and not q_fixed:
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = enc.{member_name}.{q_field} ? Arrangement::H8 : Arrangement::H4; result.operands.push_back(op); }}")
                        else:
                            q_val = int(field_map['Q']['fixed'], 2) if has_q and field_map['Q']['fixed'] else 0
                            _q_arr = [_STR_TO_ARR['4h'], _STR_TO_ARR['8h']][q_val]
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = {_q_arr}; result.operands.push_back(op); }}")
                    else:
                        # FP8→FP32 and FP16→FP32: dest is single-precision vector
                        if has_q and not q_fixed:
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = enc.{member_name}.{q_field} ? Arrangement::S4 : Arrangement::S2; result.operands.push_back(op); }}")
                        else:
                            q_val = int(field_map['Q']['fixed'], 2) if has_q and field_map['Q']['fixed'] else 0
                            _q_arr = [_STR_TO_ARR['2s'], _STR_TO_ARR['4s']][q_val]
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = {_q_arr}; result.operands.push_back(op); }}")
                elif mnemonic in ['BFDOT']:
                    if has_q and not q_fixed:
                        code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = enc.{member_name}.{q_field} ? Arrangement::S4 : Arrangement::S2; result.operands.push_back(op); }}")
                    else:
                        q_val = int(field_map['Q']['fixed'], 2) if has_q and field_map['Q']['fixed'] else 0
                        _q_arr = [_STR_TO_ARR['2s'], _STR_TO_ARR['4s']][q_val]
                        code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = {_q_arr}; result.operands.push_back(op); }}")
                else:
                    # SDOT/UDOT/USDOT/SUDOT: size=2 so _simd_arr is already correct (.2s/.4s)
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _simd_arr; result.operands.push_back(op); }}")
                # Dot products: Rn arrangement depends on source element type
                # BFDOT: BF16 source → .4h/.8h; FDOT_FP16FP32: FP16 source → .4h/.8h
                # FDOT (FP8): byte source → .8b/.16b; SDOT/UDOT: byte source → .8b/.16b
                if mnemonic in ['BFDOT'] or (mnemonic == 'FDOT' and 'fp16fp32' in encoding_name.lower()):
                    rn_arr_q0, rn_arr_q1 = "Arrangement::H4", "Arrangement::H8"
                else:
                    rn_arr_q0, rn_arr_q1 = "Arrangement::B8", "Arrangement::B16"
                if has_q and not q_fixed:
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = enc.{member_name}.{q_field} ? {rn_arr_q1} : {rn_arr_q0}; result.operands.push_back(op); }}")
                elif has_q and q_fixed:
                    q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                    rn_arr = rn_arr_q1 if q_val else rn_arr_q0
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = {rn_arr}; result.operands.push_back(op); }}")
                else:
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = {rn_arr_q0}; result.operands.push_back(op); }}")
            else:
                # Widening by-element ops: destination is one size wider than source
                widening_elem_ops = ['SQDMLSL', 'SQDMLAL', 'SMLAL', 'SMLSL', 'UMLAL', 'UMLSL',
                                     'SMULL', 'UMULL', 'SQDMULL', 'PMULL', 'FMLAL', 'FMLSL',
                                     'SQDMLSL2', 'SQDMLAL2', 'SMLAL2', 'SMLSL2', 'UMLAL2', 'UMLSL2',
                                     'SMULL2', 'UMULL2', 'SQDMULL2', 'PMULL2', 'FMLAL2', 'FMLSL2']
                is_widening_elem = mnemonic in widening_elem_ops
                if is_widening_elem:
                    # Rd: one size wider. Most widening ops always use full 128-bit dest,
                    # but FMLAL/FMLSL (FP16→FP32) use Q-dependent dest (.2s/.4s)
                    _fmlal_q_dep = mnemonic in ['FMLAL', 'FMLSL', 'FMLAL2', 'FMLSL2']
                    code.append(f'{ind}Arrangement _wide_arr = _simd_arr;')
                    if _fmlal_q_dep and 'Q' in field_map and not field_map['Q']['is_fixed']:
                        _q_f = field_map['Q']['name']
                        code.append(f'{ind}switch (_sz) {{')
                        code.append(f'{ind}    case 1: _wide_arr = enc.{member_name}.{_q_f} ? Arrangement::S4 : Arrangement::S2; break;')
                        code.append(f'{ind}    case 2: _wide_arr = enc.{member_name}.{_q_f} ? Arrangement::D2 : Arrangement::D1; break;')
                        code.append(f'{ind}    default: break;')
                        code.append(f'{ind}}}')
                    else:
                        code.append(f'{ind}switch (_sz) {{')
                        code.append(f'{ind}    case 1: _wide_arr = Arrangement::S4; break;  // H→S (always 4 elements)')
                        code.append(f'{ind}    case 2: _wide_arr = Arrangement::D2; break;  // S→D (always 2 elements)')
                        code.append(f'{ind}    default: break;')
                        code.append(f'{ind}}}')
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _wide_arr; result.operands.push_back(op); }}")
                else:
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = _simd_arr; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = _simd_arr; result.operands.push_back(op); }}")

            # Rm with element index: scalar arrangement + index from H/L/M
            has_h = 'H' in field_map and not field_map['H']['is_fixed']
            has_l = 'L' in field_map and not field_map['L']['is_fixed']
            has_m = 'M' in field_map and not field_map['M']['is_fixed']
            h_f = field_map['H']['name'] if has_h else None
            l_f = field_map['L']['name'] if has_l else None
            m_f = field_map['M']['name'] if has_m else None

            code.append(f"{ind}{{")
            # Determine if M bit is part of Rm register (M:Rm) or part of index
            # Standard: size>=2 → M is Rm[4]; size=1 → M is index bit
            # Special: FDOT_asimdelem_D has size=0 but M:Rm per ARM spec
            # Special: BFDOT_asimdelem_E has size=1 but M:Rm per ARM spec (BF16 elements)
            enc_lower = encoding_name.lower()
            fdot_m_is_rm = (mnemonic == 'FDOT' and 'asimdelem_d' in enc_lower) or \
                           (mnemonic == 'FDOT' and 'fp16fp32' in enc_lower) or \
                           (mnemonic == 'BFDOT')
            if has_m:
                code.append(f"{ind}    uint32_t _rm_reg = enc.{member_name}.{rm_field};")
                if fdot_m_is_rm:
                    # M is always part of register number for these encodings
                    code.append(f"{ind}    _rm_reg |= (enc.{member_name}.{m_f} << 4);")
                else:
                    code.append(f"{ind}    if (_sz >= 2) _rm_reg |= (enc.{member_name}.{m_f} << 4);")
                code.append(f"{ind}    Operand op(OperandType::VectorRegister, _rm_reg, false);")
            else:
                code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_field}, false);")
            code.append(f"{ind}    uint32_t _idx = 0;")
            # Element index depends on size:
            # size=1 (H): Rm=Rm[3:0], index=H:L:M (3 bits)
            # size=2 (S): Rm=M:Rm[3:0], index=H:L (2 bits)
            # size=3 (D): Rm=M:Rm[3:0], index=H (1 bit)
            if has_h and has_l and has_m:
                code.append(f'{ind}    static const Arrangement _elem_scalar[] = {{Arrangement::B, Arrangement::H, Arrangement::S, Arrangement::D}};')
                code.append(f"{ind}    op.arrangement = _elem_scalar[_sz];")
                if fdot_m_is_rm:
                    # M is part of Rm, so index is always H:L (2 bits)
                    code.append(f"{ind}    _idx = (enc.{member_name}.{h_f} << 1) | enc.{member_name}.{l_f};")
                else:
                    code.append(f"{ind}    if (_sz == 1) _idx = (enc.{member_name}.{h_f} << 2) | (enc.{member_name}.{l_f} << 1) | enc.{member_name}.{m_f};")
                    code.append(f"{ind}    else if (_sz == 2) _idx = (enc.{member_name}.{h_f} << 1) | enc.{member_name}.{l_f};")
                    code.append(f"{ind}    else if (_sz == 3) _idx = enc.{member_name}.{h_f};")
            elif has_h and has_l:
                code.append(f'{ind}    static const Arrangement _elem_scalar[] = {{Arrangement::B, Arrangement::H, Arrangement::S, Arrangement::D}};')
                code.append(f"{ind}    op.arrangement = _elem_scalar[_sz];")
                code.append(f"{ind}    _idx = (enc.{member_name}.{h_f} << 1) | enc.{member_name}.{l_f};")
            elif has_h:
                code.append(f'{ind}    op.arrangement = Arrangement::D;')
                code.append(f"{ind}    _idx = enc.{member_name}.{h_f};")
            else:
                code.append(f'{ind}    static const Arrangement _elem_scalar[] = {{Arrangement::B, Arrangement::H, Arrangement::S, Arrangement::D}};')
                code.append(f"{ind}    op.arrangement = _elem_scalar[_sz];")

            # Override arrangement for dot product Rm: use grouped element arrangement
            if is_dot_product:
                # FDOT_asimdelem_D (FP8→FP32, 4-way): Rm.4B[idx]
                # FDOT_asimdelem_G (FP8→FP16, 2-way): Rm.2B[idx]
                # FDOT_asimdelem_FP16FP32 (FP16→FP32): Rm.2H[idx]
                # BFDOT: Rm.2H[idx]
                # SDOT/UDOT/USDOT/SUDOT: Rm.4B[idx]
                if mnemonic == 'FDOT':
                    if 'asimdelem_g' in encoding_name.lower():
                        code.append(f'{ind}    op.arrangement = Arrangement::B2;')
                    elif 'fp16fp32' in encoding_name.lower():
                        code.append(f'{ind}    op.arrangement = Arrangement::H2;')
                    else:
                        code.append(f'{ind}    op.arrangement = Arrangement::B4;')
                elif mnemonic == 'BFDOT':
                    code.append(f'{ind}    op.arrangement = Arrangement::H2;')
                else:
                    code.append(f'{ind}    op.arrangement = Arrangement::B4;')

            code.append(f"{ind}    op.index = _idx;")
            code.append(f"{ind}    op.has_index = true;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            code.append(f"{ind}return result;")
            return code

        # Special case: FCVTL/FCVTL2 — widening FP conversion (sz gives dest size, Q selects half)
        # Dest is always widened (4s for sz=0, 2d for sz=1); source depends on Q (lower/upper half)
        is_fcvtl = mnemonic in ['FCVTL', 'FCVTL2'] and 'sz' in field_map and 'Rd' in field_map and 'Rn' in field_map
        if is_fcvtl:
            sz_f = field_map['sz']['name']
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            sz_is_fixed = field_map['sz']['is_fixed']
            q_var = 'Q' in field_map and not field_map['Q']['is_fixed']
            q_field_n = field_map['Q']['name'] if q_var else None
            q_fixed_v = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['is_fixed'] and field_map['Q']['fixed'] else 0
            if not sz_is_fixed:
                code.append(f"{ind}uint32_t _sz_v = enc.{member_name}.{sz_f};")
                code.append(f'{ind}Arrangement _dst_arr = _sz_v ? Arrangement::D2 : Arrangement::S4;')
                if q_var:
                    # src: [["4h","8h"],["2s","4s"]][sz][Q]
                    code.append(f'{ind}static const Arrangement _fcvtl_src[2][2] = {{{{Arrangement::H4,Arrangement::H8}},{{Arrangement::S2,Arrangement::S4}}}};')
                    code.append(f"{ind}Arrangement _src_arr = _fcvtl_src[_sz_v][enc.{member_name}.{q_field_n}];")
                else:
                    src_arrs = [["Arrangement::H4", "Arrangement::H8"], ["Arrangement::S2", "Arrangement::S4"]]
                    code.append(f'{ind}Arrangement _src_arr = _sz_v ? {src_arrs[1][q_fixed_v]} : {src_arrs[0][q_fixed_v]};')
            else:
                sz_val = int(field_map['sz']['fixed'], 2) if field_map['sz']['fixed'] else 0
                src_arrs = [["Arrangement::H4", "Arrangement::H8"], ["Arrangement::S2", "Arrangement::S4"]]
                code.append(f'{ind}Arrangement _dst_arr = {("Arrangement::D2" if sz_val else "Arrangement::S4")};')
                if q_var:
                    code.append(f"{ind}Arrangement _src_arr = enc.{member_name}.{q_field_n} ? {src_arrs[sz_val][1]} : {src_arrs[sz_val][0]};")
                else:
                    code.append(f'{ind}Arrangement _src_arr = "{src_arrs[sz_val][q_fixed_v]}";')
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = _dst_arr; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = _src_arr; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: FCVTXN/FCVTXN2 — narrowing FP conversion (fixed esize=32)
        # Vector form: dest=.2s/.4s (Q-dependent), source always .2d
        # Q=0 → FCVTXN (lower 2 lanes), Q=1 → FCVTXN2 (upper 2 lanes)
        is_fcvtxn = mnemonic == 'FCVTXN' and 'asimdmisc' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map
        if is_fcvtxn:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            q_var = 'Q' in field_map and not field_map['Q']['is_fixed']
            q_field_n = field_map['Q']['name'] if q_var else None
            q_fixed_v = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['is_fixed'] and field_map['Q']['fixed'] else 0
            if q_var:
                code.append(f"{ind}Arrangement _dst_arr = enc.{member_name}.{q_field_n} ? Arrangement::S4 : Arrangement::S2;")
            else:
                code.append(f'{ind}Arrangement _dst_arr = {("Arrangement::S4" if q_fixed_v else "Arrangement::S2")};')
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = _dst_arr; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::D2; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: FCVTN (asimdmisc_N) — narrowing FP conversion (FP32→FP16 or FP64→FP32)
        # dest=.4h/.8h or .2s/.4s (Q-dependent), source=.4s or .2d (size-dependent)
        is_fcvtn_misc = mnemonic == 'FCVTN' and 'asimdmisc' in encoding_name.lower() and 'asimdsame2' not in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map
        if is_fcvtn_misc:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            q_var = 'Q' in field_map and not field_map['Q']['is_fixed']
            q_field_n = field_map['Q']['name'] if q_var else None
            q_fixed_v = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['is_fixed'] and field_map['Q']['fixed'] else 0
            sz_var = 'sz' in field_map and not field_map['sz']['is_fixed']
            size_var = 'size' in field_map and not field_map['size']['is_fixed']
            if sz_var:
                sz_f = field_map['sz']['name']
                # sz=0: FP32→FP16 (dest=.4h/.8h, src=.4s)  sz=1: FP64→FP32 (dest=.2s/.4s, src=.2d)
                if q_var:
                    code.append(f"{ind}Arrangement _dst_arr = enc.{member_name}.{sz_f} ? (enc.{member_name}.{q_field_n} ? Arrangement::S4 : Arrangement::S2) : (enc.{member_name}.{q_field_n} ? Arrangement::H8 : Arrangement::H4);")
                else:
                    code.append(f"{ind}Arrangement _dst_arr = enc.{member_name}.{sz_f} ? {'Arrangement::S4' if q_fixed_v else 'Arrangement::S2'} : {'Arrangement::H8' if q_fixed_v else 'Arrangement::H4'};")
                code.append(f"{ind}Arrangement _src_arr = enc.{member_name}.{sz_f} ? Arrangement::D2 : Arrangement::S4;")
            elif size_var:
                size_f = field_map['size']['name']
                if q_var:
                    code.append(f"{ind}Arrangement _dst_arr = (enc.{member_name}.{size_f} & 1) ? (enc.{member_name}.{q_field_n} ? Arrangement::S4 : Arrangement::S2) : (enc.{member_name}.{q_field_n} ? Arrangement::H8 : Arrangement::H4);")
                else:
                    code.append(f"{ind}Arrangement _dst_arr = (enc.{member_name}.{size_f} & 1) ? {'Arrangement::S4' if q_fixed_v else 'Arrangement::S2'} : {'Arrangement::H8' if q_fixed_v else 'Arrangement::H4'};")
                code.append(f"{ind}Arrangement _src_arr = (enc.{member_name}.{size_f} & 1) ? Arrangement::D2 : Arrangement::S4;")
            else:
                # Fixed size — assume FP32→FP16
                code.append(f'{ind}Arrangement _dst_arr = {"Arrangement::H8" if q_fixed_v else "Arrangement::H4"};')
                code.append(f'{ind}Arrangement _src_arr = Arrangement::S4;')
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = _dst_arr; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = _src_arr; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: BFCVTN (asimdmisc) — BF16 narrowing, always FP32→BF16
        # dest=.4h(Q=0)/.8h(Q=1), src always .4s
        is_bfcvtn = mnemonic == 'BFCVTN' and 'asimdmisc' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map
        if is_bfcvtn:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            q_var = 'Q' in field_map and not field_map['Q']['is_fixed']
            q_field_n = field_map['Q']['name'] if q_var else None
            q_fixed_v = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['is_fixed'] and field_map['Q']['fixed'] else 0
            if q_var:
                code.append(f"{ind}Arrangement _dst_arr = enc.{member_name}.{q_field_n} ? Arrangement::H8 : Arrangement::H4;")
            else:
                code.append(f'{ind}Arrangement _dst_arr = {"Arrangement::H8" if q_fixed_v else "Arrangement::H4"};')
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = _dst_arr; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: F1CVTL/F2CVTL/BF1CVTL/BF2CVTL (asimdmisc_V) — FP8→FP16 widening
        # dest always .8h, src always .8b
        is_fp8_widen = mnemonic in ['F1CVTL', 'F2CVTL', 'BF1CVTL', 'BF2CVTL'] and 'asimdmisc' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map
        if is_fp8_widen:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::H8; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::B8; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: FMLAL/FMLSL/FMLAL2/FMLSL2 (asimdsame_F) — FP16 multiply-add/sub
        # dest=.2s(Q=0)/.4s(Q=1), src always .2h(Q=0)/.4h(Q=1)
        is_fmlal_same = mnemonic in ['FMLAL', 'FMLSL', 'FMLAL2', 'FMLSL2'] and 'asimdsame_f' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_fmlal_same:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            q_var = 'Q' in field_map and not field_map['Q']['is_fixed']
            q_field_n = field_map['Q']['name'] if q_var else None
            q_fixed_v = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['is_fixed'] and field_map['Q']['fixed'] else 0
            if q_var:
                code.append(f"{ind}Arrangement _dst = enc.{member_name}.{q_field_n} ? Arrangement::S4 : Arrangement::S2;")
                code.append(f"{ind}Arrangement _src = enc.{member_name}.{q_field_n} ? Arrangement::H4 : Arrangement::H2;")
            else:
                code.append(f'{ind}Arrangement _dst = {"Arrangement::S4" if q_fixed_v else "Arrangement::S2"};')
                code.append(f'{ind}Arrangement _src = {"Arrangement::H4" if q_fixed_v else "Arrangement::H2"};')
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = _dst; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = _src; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = _src; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: FMLAL/FMLSL elem (asimdelem_LH) — FP16 indexed, dest always .2s(Q=0)/.4s(Q=1) not wider
        is_fmlal_elem_lh = mnemonic in ['FMLAL', 'FMLSL', 'FMLAL2', 'FMLSL2'] and 'asimdelem_lh' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_fmlal_elem_lh:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            q_var = 'Q' in field_map and not field_map['Q']['is_fixed']
            q_field_n = field_map['Q']['name'] if q_var else None
            q_fixed_v = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['is_fixed'] and field_map['Q']['fixed'] else 0
            h_f = field_map['H']['name'] if 'H' in field_map and not field_map['H']['is_fixed'] else None
            l_f = field_map['L']['name'] if 'L' in field_map and not field_map['L']['is_fixed'] else None
            m_f = field_map['M']['name'] if 'M' in field_map and not field_map['M']['is_fixed'] else None
            if q_var:
                code.append(f"{ind}Arrangement _dst = enc.{member_name}.{q_field_n} ? Arrangement::S4 : Arrangement::S2;")
                code.append(f"{ind}Arrangement _src = enc.{member_name}.{q_field_n} ? Arrangement::H4 : Arrangement::H2;")
            else:
                code.append(f'{ind}Arrangement _dst = {"Arrangement::S4" if q_fixed_v else "Arrangement::S2"};')
                code.append(f'{ind}Arrangement _src = {"Arrangement::H4" if q_fixed_v else "Arrangement::H2"};')
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = _dst; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = _src; result.operands.push_back(op); }}")
            # Rm with .h index: H:L:M = 3-bit index
            idx_expr = '0u'
            if h_f and l_f and m_f:
                idx_expr = f"(enc.{member_name}.{h_f} << 2) | (enc.{member_name}.{l_f} << 1) | enc.{member_name}.{m_f}"
            elif h_f and l_f:
                idx_expr = f"(enc.{member_name}.{h_f} << 1) | enc.{member_name}.{l_f}"
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = Arrangement::H; op.index = {idx_expr}; op.has_index = true; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: BFMLAL/BFMLALB/BFMLALT (asimdsame2_F_) — BF16 multiply-add
        # dest=.4s(always Q=1 from encoding), src=.8h(Q=1)
        is_bfmlal = mnemonic in ['BFMLAL', 'BFMLALB', 'BFMLALT'] and 'asimdsame2' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_bfmlal:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::H8; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = Arrangement::H8; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: BFMMLA/SMMLA/UMMLA/USMMLA (asimdsame2) — BF16 uses .8h src, int uses .16b src
        # Note: BFMMLA src=.8h not .16b, regular *MMLA handled by SDOT/UDOT path
        is_bfmmla = mnemonic == 'BFMMLA' and 'asimdsame2' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_bfmmla:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::H8; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = Arrangement::H8; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: FMLALB/FMLALT (asimdsame2_J) — FP8→FP16 multiply-add
        # dest=.8h, src=.16b (Q=1)
        is_fmlalb_fp8 = mnemonic in ['FMLALB', 'FMLALT'] and 'asimdsame2_j' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_fmlalb_fp8:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::H8; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::B16; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = Arrangement::B16; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: FMLALLBB/FMLALLBT/FMLALLTB/FMLALLTT (asimdsame2_G) — FP8→FP32 multiply-add long
        # dest=.4s, src=.16b (always Q=1)
        is_fmlall_fp8 = mnemonic in ['FMLALLBB', 'FMLALLBT', 'FMLALLTB', 'FMLALLTT'] and 'asimdsame2_g' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_fmlall_fp8:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::B16; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = Arrangement::B16; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: FMLALLBB/etc. by-element (asimdelem_J) — FP8→FP32 indexed
        # dest=.4s, src=.16b, Rm=.b[index]
        is_fmlall_elem = mnemonic in ['FMLALLBB', 'FMLALLBT', 'FMLALLTB', 'FMLALLTT'] and 'asimdelem_j' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_fmlall_elem:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            h_f = field_map['H']['name'] if 'H' in field_map and not field_map['H']['is_fixed'] else None
            l_f = field_map['L']['name'] if 'L' in field_map and not field_map['L']['is_fixed'] else None
            m_f = field_map['M']['name'] if 'M' in field_map and not field_map['M']['is_fixed'] else None
            idx_expr = '0u'
            if h_f and l_f and m_f:
                idx_expr = f"(enc.{member_name}.{h_f} << 2) | (enc.{member_name}.{l_f} << 1) | enc.{member_name}.{m_f}"
            elif h_f and l_f:
                idx_expr = f"(enc.{member_name}.{h_f} << 1) | enc.{member_name}.{l_f}"
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::B16; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = Arrangement::B; op.index = {idx_expr}; op.has_index = true; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: SM3PARTW1/SM3PARTW2 (cryptosha512_3) — always .4s
        is_sm3partw = mnemonic in ['SM3PARTW1', 'SM3PARTW2'] and 'cryptosha512' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_sm3partw:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: SM3SS1 (crypto4) — always .4s, 4 operands
        is_sm3ss1 = mnemonic == 'SM3SS1' and 'crypto4' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map and 'Ra' in field_map
        if is_sm3ss1:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            ra_f = field_map['Ra']['name']
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{ra_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: SM3TT1A/SM3TT1B/SM3TT2A/SM3TT2B (crypto3_imm2) — .4s regs + .s[index]
        is_sm3tt = mnemonic in ['SM3TT1A', 'SM3TT1B', 'SM3TT2A', 'SM3TT2B'] and 'crypto3_imm2' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_sm3tt:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            imm2_f = field_map['imm2']['name'] if 'imm2' in field_map and not field_map['imm2']['is_fixed'] else None
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            if imm2_f:
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = Arrangement::S; op.index = enc.{member_name}.{imm2_f}; op.has_index = true; result.operands.push_back(op); }}")
            else:
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: FDOT (asimdsame2_D) — FP8×FP8→FP16 dot product
        # dest=.4h(Q=0)/.8h(Q=1), src=.8b(Q=0)/.16b(Q=1)
        is_fdot_d = mnemonic == 'FDOT' and 'asimdsame2_d' in encoding_name.lower() and 'asimdsame2_dd' not in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_fdot_d:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            q_var = 'Q' in field_map and not field_map['Q']['is_fixed']
            q_field_n = field_map['Q']['name'] if q_var else None
            q_fixed_v = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['is_fixed'] and field_map['Q']['fixed'] else 0
            if q_var:
                code.append(f"{ind}Arrangement _dst = enc.{member_name}.{q_field_n} ? Arrangement::H8 : Arrangement::H4;")
                code.append(f"{ind}Arrangement _src = enc.{member_name}.{q_field_n} ? Arrangement::B16 : Arrangement::B8;")
            else:
                code.append(f'{ind}Arrangement _dst = {"Arrangement::H8" if q_fixed_v else "Arrangement::H4"};')
                code.append(f'{ind}Arrangement _src = {"Arrangement::B16" if q_fixed_v else "Arrangement::B8"};')
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = _dst; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = _src; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = _src; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: FDOT (asimdsame2_DD) — FP8×FP8→FP32 dot product
        # dest=.2s(Q=0)/.4s(Q=1), src=.8b(Q=0)/.16b(Q=1)
        is_fdot_dd = mnemonic == 'FDOT' and 'asimdsame2_dd' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_fdot_dd:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            q_var = 'Q' in field_map and not field_map['Q']['is_fixed']
            q_field_n = field_map['Q']['name'] if q_var else None
            q_fixed_v = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['is_fixed'] and field_map['Q']['fixed'] else 0
            if q_var:
                code.append(f"{ind}Arrangement _dst = enc.{member_name}.{q_field_n} ? Arrangement::S4 : Arrangement::S2;")
                code.append(f"{ind}Arrangement _src = enc.{member_name}.{q_field_n} ? Arrangement::B16 : Arrangement::B8;")
            else:
                code.append(f'{ind}Arrangement _dst = {"Arrangement::S4" if q_fixed_v else "Arrangement::S2"};')
                code.append(f'{ind}Arrangement _src = {"Arrangement::B16" if q_fixed_v else "Arrangement::B8"};')
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = _dst; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = _src; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = _src; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: SHLL (asimdmisc_S) — widening shift with implicit shift amount = esize
        # dest is wider arrangement, src is Q-dependent, shift = element size
        is_shll = mnemonic == 'SHLL' and 'asimdmisc' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map
        if is_shll:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            q_var = 'Q' in field_map and not field_map['Q']['is_fixed']
            q_field_n = field_map['Q']['name'] if q_var else None
            q_fixed_v = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['is_fixed'] and field_map['Q']['fixed'] else 0
            size_var = 'size' in field_map and not field_map['size']['is_fixed']
            size_f = field_map['size']['name'] if size_var else None
            if size_var:
                # size=0: 8→16 (dst=.8h, src=.8b/.16b), size=1: 16→32 (dst=.4s, src=.4h/.8h), size=2: 32→64 (dst=.2d, src=.2s/.4s)
                code.append(f"{ind}static const Arrangement _shll_dst[] = {{Arrangement::H8, Arrangement::S4, Arrangement::D2}};")
                if q_var:
                    code.append(f'{ind}static const Arrangement _shll_src[2][3] = {{{{Arrangement::B8, Arrangement::H4, Arrangement::S2}},{{Arrangement::B16, Arrangement::H8, Arrangement::S4}}}};')
                    code.append(f"{ind}Arrangement _dst = _shll_dst[enc.{member_name}.{size_f}];")
                    code.append(f"{ind}Arrangement _src = _shll_src[enc.{member_name}.{q_field_n}][enc.{member_name}.{size_f}];")
                else:
                    src_arrs = [["Arrangement::B8", "Arrangement::H4", "Arrangement::S2"], ["Arrangement::B16", "Arrangement::H8", "Arrangement::S4"]]
                    code.append(f"{ind}Arrangement _dst = _shll_dst[enc.{member_name}.{size_f}];")
                    code.append(f"{ind}static const Arrangement _shll_src_a[] = {{{src_arrs[q_fixed_v][0]},{src_arrs[q_fixed_v][1]},{src_arrs[q_fixed_v][2]}}};")
                    code.append(f"{ind}Arrangement _src = _shll_src_a[enc.{member_name}.{size_f}];")
                code.append(f"{ind}static const int _shll_shift[] = {{8, 16, 32}};")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = _dst; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = _src; result.operands.push_back(op); }}")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, _shll_shift[enc.{member_name}.{size_f}], true));")
            else:
                # Fallback: assume size=0 (8→16)
                src_arr = 'Arrangement::B16' if q_fixed_v else 'Arrangement::B8'
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::H8; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = {src_arr}; result.operands.push_back(op); }}")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, 8, true));")
            code.append(f"{ind}return result;")
            return code

        # Special case: FCVTN (asimdsame2) — 2-source FP narrowing (FP16→FP8 etc.)
        # FCVTN_asimdsame2_H: dest=.8b, src=.4h/.4h (FP16→FP8)
        # FCVTN_asimdsame2_D: dest=.8b(Q=0), src=.4h(Q=0)  → actually 4h→8b
        is_fcvtn_same2 = mnemonic == 'FCVTN' and 'asimdsame2' in encoding_name.lower() and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map
        if is_fcvtn_same2:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            rm_f = field_map['Rm']['name']
            _enc_lc = encoding_name.lower()
            if '_h' in _enc_lc:
                # FP32→FP16 narrowing: dest=.8b, src=.4s (FP32→FP8 via 2 sources?)
                # Actually FCVTN asimdsame2_H: FP16×FP16→FP8: dest=.8b, src=.4h, .4h
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::B8; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = Arrangement::S4; result.operands.push_back(op); }}")
            else:
                # FCVTN asimdsame2_D: FP16→FP8: dest=.8b, src=.4h, .4h
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::B8; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::H4; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rm_f}, false); op.arrangement = Arrangement::H4; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Extract all GPR register operands - pass is_64bit as third parameter
        # Special case: For advsimd/simd_dp classes, Rd/Rn/Rm might actually be vector registers
        # Detect based on encoding name pattern: asimd* = vector, crypto* = vector
        # Scalar FP (float*) and FP<->integer (float2int, floatfix) use GPR/scalar FP
        encoding_name_lower = encoding_name.lower()
        _advsimd_patterns = ['asimd', 'asisdpair', 'asisdone', 'asisdlse', 'crypto', 'asisdmiscfp16',
                             'asimdmisc', 'asimdsame']
        is_advsimd_vector = (class_name in ['advsimd', 'simd_dp'] and
            any(pat in encoding_name_lower for pat in _advsimd_patterns))
        
        # Determine SIMD arrangement from Q and size fields
        simd_arrangement = None
        # Bitwise logic ops always use byte arrangement (size field is ignored for arrangement)
        bitwise_logic_ops = ['ORR', 'AND', 'BIC', 'BIT', 'BIF', 'BSL', 'EOR', 'ORN', 'NOT']
        # EXT/RBIT always uses byte arrangement, same as bitwise ops
        byte_arr_ops = ['EXT', 'RBIT']
        is_bitwise_logic = (mnemonic in bitwise_logic_ops and 'asimdsame' in encoding_name) or mnemonic in byte_arr_ops
        if is_advsimd_vector and is_bitwise_logic and 'Q' in field_map:
            q_field = field_map['Q']['name']
            q_is_fixed = field_map['Q']['is_fixed']
            if q_is_fixed:
                q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                simd_arrangement = 'static'
                static_arr = "Arrangement::B16" if q_val else "Arrangement::B8"
                # Will be used directly as string
            else:
                simd_arrangement = 'runtime'
                code.append(f"{ind}Arrangement _simd_arr = enc.{member_name}.{q_field} ? Arrangement::B16 : Arrangement::B8;")
        elif is_advsimd_vector and 'Q' in field_map and 'size' in field_map:
            q_field = field_map['Q']['name']
            size_field_name = field_map['size']['name']
            q_is_fixed = field_map['Q']['is_fixed']
            size_is_fixed = field_map['size']['is_fixed']

            if not q_is_fixed and not size_is_fixed:
                # Both Q and size are variable — compute arrangement at runtime
                simd_arrangement = 'runtime'
                code.append(f"{ind}Arrangement _simd_arr = Arrangement::None;")
                code.append(f"{ind}{{")
                code.append(f"{ind}    static const Arrangement arrs[2][4] = {{")
                code.append(f'{ind}        {{Arrangement::B8, Arrangement::H4, Arrangement::S2, Arrangement::D1}},')
                code.append(f'{ind}        {{Arrangement::B16, Arrangement::H8, Arrangement::S4, Arrangement::D2}}')
                code.append(f"{ind}    }};")
                code.append(f"{ind}    _simd_arr = arrs[enc.{member_name}.{q_field}][enc.{member_name}.{size_field_name}];")
                code.append(f"{ind}}}")
            elif q_is_fixed and not size_is_fixed:
                # Q is fixed, size varies
                q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                arrs = [["Arrangement::B8", "Arrangement::H4", "Arrangement::S2", "Arrangement::D1"], ["Arrangement::B16", "Arrangement::H8", "Arrangement::S4", "Arrangement::D2"]]
                simd_arrangement = 'runtime'
                code.append(f"{ind}Arrangement _simd_arr = Arrangement::None;")
                code.append(f"{ind}{{")
                arr_list = arrs[q_val]
                code.append(f'{ind}    static const Arrangement arrs[] = {{{arr_list[0]}, {arr_list[1]}, {arr_list[2]}, {arr_list[3]}}};')
                code.append(f"{ind}    _simd_arr = arrs[enc.{member_name}.{size_field_name}];")
                code.append(f"{ind}}}")
            elif not q_is_fixed and size_is_fixed:
                # Size is fixed, Q varies
                size_val = int(field_map['size']['fixed'], 2) if field_map['size']['fixed'] else 0
                arrs = {0: ["Arrangement::B8", "Arrangement::B16"], 1: ["Arrangement::H4", "Arrangement::H8"], 2: ["Arrangement::S2", "Arrangement::S4"], 3: ["Arrangement::D1", "Arrangement::D2"]}
                simd_arrangement = 'runtime'
                code.append(f"{ind}Arrangement _simd_arr = enc.{member_name}.{q_field} ? {arrs[size_val][1]} : {arrs[size_val][0]};")
            else:
                # Both Q and size are fixed
                q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                size_val = int(field_map['size']['fixed'], 2) if field_map['size']['fixed'] else 0
                all_arrs = [["Arrangement::B8", "Arrangement::H4", "Arrangement::S2", "Arrangement::D1"], ["Arrangement::B16", "Arrangement::H8", "Arrangement::S4", "Arrangement::D2"]]
                simd_arrangement = 'static'
                static_arr = all_arrs[q_val][size_val]
        elif is_advsimd_vector and 'Q' in field_map and 'sz' in field_map and 'size' not in field_map:
            # FP vector ops: sz=0→single(.2s/.4s), sz=1→double(.1d/.2d)
            q_field = field_map['Q']['name']
            sz_field = field_map['sz']['name']
            q_is_fixed = field_map['Q']['is_fixed']
            sz_is_fixed = field_map['sz']['is_fixed']
            fp_arrs_2d = [["Arrangement::S2", "Arrangement::S4"], ["Arrangement::D1", "Arrangement::D2"]]
            if not q_is_fixed and not sz_is_fixed:
                simd_arrangement = 'runtime'
                code.append(f"{ind}Arrangement _simd_arr = Arrangement::None;")
                code.append(f"{ind}{{")
                code.append(f'{ind}    static const Arrangement _fp_arrs[2][2] = {{{{Arrangement::S2, Arrangement::S4}}, {{Arrangement::D1, Arrangement::D2}}}};')
                code.append(f"{ind}    _simd_arr = _fp_arrs[enc.{member_name}.{sz_field}][enc.{member_name}.{q_field}];")
                code.append(f"{ind}}}")
            elif sz_is_fixed and not q_is_fixed:
                sz_val = int(field_map['sz']['fixed'], 2) if field_map['sz']['fixed'] else 0
                simd_arrangement = 'runtime'
                code.append(f"{ind}Arrangement _simd_arr = enc.{member_name}.{q_field} ? {fp_arrs_2d[sz_val][1]} : {fp_arrs_2d[sz_val][0]};")
            elif not sz_is_fixed and q_is_fixed:
                q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                simd_arrangement = 'runtime'
                code.append(f"{ind}Arrangement _simd_arr = Arrangement::None;")
                code.append(f"{ind}{{")
                code.append(f'{ind}    static const Arrangement _fp_arrs[] = {{{fp_arrs_2d[0][q_val]}, {fp_arrs_2d[1][q_val]}}};')
                code.append(f"{ind}    _simd_arr = _fp_arrs[enc.{member_name}.{sz_field}];")
                code.append(f"{ind}}}")
            else:
                sz_val = int(field_map['sz']['fixed'], 2) if field_map['sz']['fixed'] else 0
                q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                simd_arrangement = 'static'
                static_arr = fp_arrs_2d[sz_val][q_val]

        # FP16 SIMD-same/misc: Q but no size/sz → halfword arrangement
        if is_advsimd_vector and simd_arrangement is None and 'Q' in field_map and 'fp16' in encoding_name_lower:
            q_field = field_map['Q']['name']
            q_is_fixed = field_map['Q']['is_fixed']
            if q_is_fixed:
                q_val = int(field_map['Q']['fixed'], 2) if field_map['Q']['fixed'] else 0
                simd_arrangement = 'static'
                static_arr = "Arrangement::H8" if q_val else "Arrangement::H4"
            else:
                simd_arrangement = 'runtime'
                code.append(f"{ind}Arrangement _simd_arr = enc.{member_name}.{q_field} ? Arrangement::H8 : Arrangement::H4;")

        # Crypto instructions without Q/size fields: fixed arrangement from encoding name
        if is_advsimd_vector and simd_arrangement is None:
            enc_lower = encoding_name.lower()
            if 'crypto4' in enc_lower:
                # BCAX, EOR3, SM3SS1: all .16b
                simd_arrangement = 'static'
                static_arr = 'Arrangement::B16'
            elif 'crypto3_imm6' in enc_lower:
                # XAR: .2d
                simd_arrangement = 'static'
                static_arr = 'Arrangement::D2'
            elif 'cryptosha512_3' in enc_lower:
                # SHA512H, SHA512H2, SHA512SU1, RAX1: .2d; SM4EKEY: .4s
                simd_arrangement = 'static'
                static_arr = 'Arrangement::S4' if mnemonic.startswith('SM4') else 'Arrangement::D2'
            elif 'cryptosha512_2' in enc_lower:
                # SM4E: .4s; SHA512SU0: .2d
                simd_arrangement = 'static'
                static_arr = 'Arrangement::S4' if mnemonic.startswith('SM4') else 'Arrangement::D2'
            elif 'cryptosha3' in enc_lower:
                # SHA256H, SHA256H2, SHA256SU1: .4s
                simd_arrangement = 'static'
                static_arr = 'Arrangement::S4'
            elif 'cryptosha2' in enc_lower:
                # SHA1C, SHA1M, SHA1P, SHA1SU0, SHA1SU1, SHA256SU0: .4s
                # SHA1H: scalar (s-register), skip vector arrangement
                if mnemonic != 'SHA1H':
                    simd_arrangement = 'static'
                    static_arr = 'Arrangement::S4'
            elif 'crypto_aes' in enc_lower or 'cryptoaes' in enc_lower:
                # AESE, AESD, AESMC, AESIMC: .16b
                simd_arrangement = 'static'
                static_arr = 'Arrangement::B16'

        # ADDG/SUBG: imm6 is tag granule offset (×16), Rd/Rn can be SP
        if mnemonic in ['ADDG', 'SUBG'] and 'imm6' in field_map and 'imm4' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            imm6_field = field_map['imm6']['name']
            imm4_field = field_map['imm4']['name']
            code.append(f"{ind}{{ Operand op(OperandType::Register, enc.{member_name}.{rd_field}, true); op.is_sp = true; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::Register, enc.{member_name}.{rn_field}, true); op.is_sp = true; result.operands.push_back(op); }}")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{imm6_field} * 16, true));")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{imm4_field}, true));")
            code.append(f"{ind}return result;")
            return code

        # Mixed-width instructions: Rd/Ra are 64-bit, Rn/Rm are 32-bit
        is_mixed_width = mnemonic in ['SMADDL', 'SMSUBL', 'UMADDL', 'UMSUBL'] and not is_advsimd_vector
        if is_mixed_width and 'Rd' in field_map and 'Rn' in field_map and 'Rm' in field_map:
            for reg_name in ['Rd', 'Rn', 'Rm', 'Ra']:
                if reg_name in field_map and not field_map[reg_name]['is_fixed']:
                    field_cpp_name = field_map[reg_name]['name']
                    rw = 'true' if reg_name in ('Rd', 'Ra') else 'false'
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{field_cpp_name}, {rw}));")
            code.append(f"{ind}return result;")
            return code

        # Special case: UMOV/SMOV — Rd is GPR, Vn uses arrangement from imm5
        if mnemonic in ['UMOV', 'SMOV'] and 'Rd' in field_map and 'Rn' in field_map and 'imm5' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            imm5_field = field_map['imm5']['name']
            # For X_x variant (64-bit): Rd is Xd, element is .d
            # For W_w variant (32-bit): Rd is Wd, element determined by imm5
            is_x = '_x_' in encoding_name or encoding_name.endswith('_x')
            rd_64 = 'true' if is_x else 'false'
            code.append(f"{ind}uint32_t _imm5 = enc.{member_name}.{imm5_field};")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_field}, {rd_64}));")
            code.append(f"{ind}{{")
            code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false);")
            code.append(f"{ind}    uint32_t idx = 0;")
            code.append(f'{ind}    if (_imm5 & 1) {{ op.arrangement = Arrangement::B; idx = _imm5 >> 1; }}')
            code.append(f'{ind}    else if (_imm5 & 2) {{ op.arrangement = Arrangement::H; idx = _imm5 >> 2; }}')
            code.append(f'{ind}    else if (_imm5 & 4) {{ op.arrangement = Arrangement::S; idx = _imm5 >> 3; }}')
            code.append(f'{ind}    else if (_imm5 & 8) {{ op.arrangement = Arrangement::D; idx = _imm5 >> 4; }}')
            code.append(f"{ind}    op.index = idx;")
            code.append(f"{ind}    op.has_index = true;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            code.append(f"{ind}return result;")
            return code

        # Special case: float2int instructions (SCVTF, UCVTF, FCVTZS, FCVTZU, FMOV GP↔FP)
        # These have mixed register types: one FP and one GP register
        # Encoding name pattern: SCVTF_D32 → Rd=D-FP, Rn=W-GP; FCVTZS_32D → Rd=W-GP, Rn=D-FP
        if 'float2int' in encoding_name and 'Rd' in field_map and 'Rn' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            enc_parts = encoding_name.split('_')
            # Second part is like 'd32', 's64', '32d', '64s', etc.
            fp_gp_part = enc_parts[1] if len(enc_parts) >= 2 else ''
            # Determine which reg is FP and which is GP, and their sizes
            import re as _re
            # Pattern: letter then digits = FP first (Rd=FP, Rn=GP)
            # Pattern: digits then letter = GP first (Rd=GP, Rn=FP)
            fp_first = _re.match(r'^([dshb])(\d+)$', fp_gp_part)
            gp_first = _re.match(r'^(\d+)([dshb])$', fp_gp_part)
            if fp_first:
                fp_char = fp_first.group(1)
                gp_bits = fp_first.group(2)
                gp_64 = '64' in gp_bits
                # Rd = FP, Rn = GP
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = {_CHAR_TO_ARR[fp_char]}; result.operands.push_back(op); }}")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rn_field}, {str(gp_64).lower()}));")
            elif gp_first:
                gp_bits = gp_first.group(1)
                fp_char = gp_first.group(2)
                gp_64 = '64' in gp_bits
                # Rd = GP, Rn = FP
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_field}, {str(gp_64).lower()}));")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = {_CHAR_TO_ARR[fp_char]}; result.operands.push_back(op); }}")
            else:
                # Fallback: both as GP registers with best guess
                is_64 = '64' in encoding_name and '32' not in encoding_name
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_field}, {str(is_64).lower()}));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rn_field}, {str(is_64).lower()}));")
            code.append(f"{ind}return result;")
            return code

        # Special case: float2fix instructions (SCVTF, UCVTF, FCVTZS, FCVTZU with fixed-point scale)
        # Template: SCVTF <Sd>, <Wn>, #<fbits>  or  FCVTZS <Wd>, <Dn>, #<fbits>
        # Encoding name: scvtf_s32_float2fix, fcvtzs_32d_float2fix, etc.
        if 'float2fix' in encoding_name and 'Rd' in field_map and 'Rn' in field_map and 'scale' in field_map:
            rd_field = field_map['Rd']['name']
            rn_field = field_map['Rn']['name']
            scale_field = field_map['scale']['name']
            enc_parts = encoding_name.split('_')
            # Second part is like 's32', 'd64', '32s', '64d', 'h32', etc.
            fp_gp_part = enc_parts[1] if len(enc_parts) >= 2 else ''
            import re as _re
            fp_first = _re.match(r'^([dsh])(\d+)$', fp_gp_part)
            gp_first = _re.match(r'^(\d+)([dsh])$', fp_gp_part)
            if fp_first:
                fp_char = fp_first.group(1)
                gp_bits = fp_first.group(2)
                gp_64 = '64' in gp_bits
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field}, false); op.arrangement = {_CHAR_TO_ARR[fp_char]}; result.operands.push_back(op); }}")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rn_field}, {str(gp_64).lower()}));")
            elif gp_first:
                gp_bits = gp_first.group(1)
                fp_char = gp_first.group(2)
                gp_64 = '64' in gp_bits
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_field}, {str(gp_64).lower()}));")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field}, false); op.arrangement = {_CHAR_TO_ARR[fp_char]}; result.operands.push_back(op); }}")
            else:
                is_64 = '64' in encoding_name
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_field}, {str(is_64).lower()}));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rn_field}, {str(is_64).lower()}));")
            # fbits = 64 - scale
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, 64 - enc.{member_name}.{scale_field}, true));")
            code.append(f"{ind}return result;")
            return code

        # Special case: asisdpair (Advanced SIMD scalar pairwise)
        # Template: ADDP D<d>, <Vn>.2D  /  FADDP H<d>, <Vn>.2H  /  FADDP <V><d>, <Vn>.<T>
        # Rd is always a scalar FP register; Rn is always a vector with the corresponding 2x arrangement.
        if 'asisdpair' in encoding_name and 'Rd' in field_map and 'Rn' in field_map:
            rd_field_cpp = field_map['Rd']['name']
            rn_field_cpp = field_map['Rn']['name']
            enc_lc = encoding_name.lower()
            if enc_lc.endswith('_h'):
                # Fixed H: Rd=h, Rn=2h
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field_cpp}, false); op.arrangement = Arrangement::H; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field_cpp}, false); op.arrangement = Arrangement::H2; result.operands.push_back(op); }}")
            elif enc_lc.endswith('_sd') and 'sz' in field_map and not field_map['sz']['is_fixed']:
                # Variable sz: 0=S/2s, 1=D/2d
                sz_cpp = field_map['sz']['name']
                code.append(f"{ind}Arrangement _sc_arr = enc.{member_name}.{sz_cpp} ? Arrangement::D : Arrangement::S;")
                code.append(f"{ind}Arrangement _vec_arr = enc.{member_name}.{sz_cpp} ? Arrangement::D2 : Arrangement::S2;")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field_cpp}, false); op.arrangement = _sc_arr; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field_cpp}, false); op.arrangement = _vec_arr; result.operands.push_back(op); }}")
            else:
                # Fixed size (ADDP_asisdpair_only: size=11 → D/2d)
                size_val = int(field_map.get('size', {}).get('fixed', '11'), 2) if field_map.get('size', {}).get('is_fixed', True) else 3
                _sc_map = {0: 'Arrangement::B', 1: 'Arrangement::H', 2: 'Arrangement::S', 3: 'Arrangement::D'}
                _vec_map = {0: 'Arrangement::B8', 1: 'Arrangement::H2', 2: 'Arrangement::S2', 3: 'Arrangement::D2'}
                sc_arr = _sc_map.get(size_val, 'Arrangement::D')
                vec_arr = _vec_map.get(size_val, 'Arrangement::D2')
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_field_cpp}, false); op.arrangement = {sc_arr}; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_field_cpp}, false); op.arrangement = {vec_arr}; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Detect scalar FP: encoding name contains 'float' (floatdp1, floatdp2, floatdp3, floatcmp, floatsel)
        # These use s/d/h register naming based on precision in encoding name
        scalar_fp_arr = None
        # FCMP/FCMPE zero variants: _SZ_, _DZ_, _HZ_ → compare against #0.0
        is_fp_cmp_zero = False
        if 'float' in encoding_name:
            if '_d_' in encoding_name or '_dz_' in encoding_name or encoding_name.startswith('d_'):
                scalar_fp_arr = 'Arrangement::D'
            elif '_s_' in encoding_name or '_sz_' in encoding_name or encoding_name.startswith('s_'):
                scalar_fp_arr = 'Arrangement::S'
            elif '_h_' in encoding_name or '_hz_' in encoding_name or encoding_name.startswith('h_'):
                scalar_fp_arr = 'Arrangement::H'
            if '_dz_' in encoding_name or '_sz_' in encoding_name or '_hz_' in encoding_name:
                is_fp_cmp_zero = True
        # asisdmisc/asimdmisc _FZ suffix: compare-vs-zero (FCMEQ, FCMGE, FCMGT, FCMLE, FCMLT)
        if '_fz' in encoding_name and ('asisdmisc' in encoding_name or 'asimdmisc' in encoding_name):
            is_fp_cmp_zero = True
        # BFCVT: BFloat16 convert single→half — Rd=H, Rn=S
        if mnemonic == 'BFCVT' and 'float' in encoding_name:
            fcvt_rd_arr = 'Arrangement::H'
            fcvt_rn_arr = 'Arrangement::S'
            scalar_fp_arr = 'Arrangement::H'  # fallback
        # SHA1H is a scalar crypto op: SHA1H Sd, Sn
        if mnemonic == 'SHA1H':
            scalar_fp_arr = 'Arrangement::S'
        # Special case: Scalar narrowing misc (SQXTN, UQXTN, SQXTUN, FCVTXN scalar)
        # Rd = narrow arrangement, Rn = wide arrangement (one step up)
        _scalar_narrow_misc = ['SQXTN', 'UQXTN', 'SQXTUN', 'FCVTXN', 'XTN']
        if mnemonic in _scalar_narrow_misc and 'asisdmisc' in encoding_name_lower and 'Rd' in field_map and 'Rn' in field_map:
            rd_f = field_map['Rd']['name']
            rn_f = field_map['Rn']['name']
            if mnemonic != 'FCVTXN' and 'size' in field_map and not field_map['size']['is_fixed']:
                size_f = field_map['size']['name']
                code.append(f"{ind}static const Arrangement _narrow_arr[] = {{Arrangement::B, Arrangement::H, Arrangement::S, Arrangement::D}};")
                code.append(f"{ind}static const Arrangement _wide_arr[] = {{Arrangement::H, Arrangement::S, Arrangement::D, Arrangement::D}};")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = _narrow_arr[enc.{member_name}.{size_f}]; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = _wide_arr[enc.{member_name}.{size_f}]; result.operands.push_back(op); }}")
            elif mnemonic != 'FCVTXN' and 'size' in field_map and field_map['size']['is_fixed']:
                _sz_val = int(field_map['size']['fixed'], 2) if field_map['size']['fixed'] else 0
                _narrow_map = {0: 'Arrangement::B', 1: 'Arrangement::H', 2: 'Arrangement::S', 3: 'Arrangement::D'}
                _wide_map = {0: 'Arrangement::H', 1: 'Arrangement::S', 2: 'Arrangement::D', 3: 'Arrangement::D'}
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = {_narrow_map[_sz_val]}; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = {_wide_map[_sz_val]}; result.operands.push_back(op); }}")
            else:
                # FCVTXN has no size field, always FP64→FP32
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rd_f}, false); op.arrangement = Arrangement::S; result.operands.push_back(op); }}")
                code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{rn_f}, false); op.arrangement = Arrangement::D; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Detect scalar SIMD: asisdmisc, asisdsame, asisdsamefp16, asisddiff
        # These use scalar FP register names (D<d>, H<d>, etc.) not GP registers
        _scalar_simd_pats = ['asisdmisc', 'asisdsame', 'asisdsamefp16', 'asisddiff']
        if not scalar_fp_arr and any(pat in encoding_name_lower for pat in _scalar_simd_pats):
            import re as _re_ssimd
            _asm_tmpl_s = encoding_info.get('asm_template', '')
            # FP16 variants always use half-precision
            if 'fp16' in encoding_name_lower:
                scalar_fp_arr = 'Arrangement::H'
            # Match explicit scalar prefix like "<Hd>" or "<Dd>" in template
            elif _re_ssimd.search(r'<([BHSDQ])[dnm]>', _asm_tmpl_s):
                _ssimd_m = _re_ssimd.search(r'<([BHSDQ])[dnm]>', _asm_tmpl_s)
                scalar_fp_arr = _CHAR_TO_ARR[_ssimd_m.group(1).lower()]
            # Check sz field (asisdsame uses sz: 0→S, 1→D)
            elif 'sz' in field_map and field_map['sz']['is_fixed'] and field_map['sz'].get('fixed'):
                _sz_val = int(field_map['sz']['fixed'], 2)
                _sz_arr_map = {0: 'Arrangement::S', 1: 'Arrangement::D'}
                scalar_fp_arr = _sz_arr_map.get(_sz_val, 'Arrangement::D')
            elif 'sz' in field_map and not field_map['sz']['is_fixed']:
                # Runtime sz field — need dynamic arrangement
                scalar_fp_arr = 'DYNAMIC_SZ'
            elif 'size' in field_map and field_map['size']['is_fixed'] and field_map['size'].get('fixed'):
                _sz_val = int(field_map['size']['fixed'], 2)
                _sz_arr_map = {0: 'Arrangement::B', 1: 'Arrangement::H', 2: 'Arrangement::S', 3: 'Arrangement::D'}
                scalar_fp_arr = _sz_arr_map.get(_sz_val, 'Arrangement::D')
            elif 'size' in field_map and not field_map['size']['is_fixed']:
                scalar_fp_arr = 'DYNAMIC_SIZE'
        # Detect scalar FP register from asm_template (for SIMD LD/ST, e.g. _ldapstl_simd)
        if not scalar_fp_arr:
            import re as _re_fp
            _asm_tmpl = encoding_info.get('asm_template', '')
            _fp_m = _re_fp.search(r'<([BHSDQ])t(?:\d+)?>', _asm_tmpl)
            if _fp_m:
                scalar_fp_arr = _CHAR_TO_ARR[_fp_m.group(1).lower()]

        # FCVT between precisions: Rd and Rn use different scalar FP types
        # Encoding name: FCVT_<dst><src>_floatdp1 (e.g., FCVT_SH = single→half, FCVT_DS = double→single)
        fcvt_rd_arr = None
        fcvt_rn_arr = None
        # BFCVT: BFloat16 convert single→half — Rd=H, Rn=S (re-apply after reset)
        if mnemonic == 'BFCVT' and 'float' in encoding_name:
            fcvt_rd_arr = 'Arrangement::H'
            fcvt_rn_arr = 'Arrangement::S'
        if mnemonic == 'FCVT' and 'float' in encoding_name:
            enc_upper = encoding_name.upper()
            # Extract the two-character code after FCVT_
            if 'FCVT_' in enc_upper:
                code_part = enc_upper.split('FCVT_')[1][:2]
                type_map = {'S': 'Arrangement::S', 'D': 'Arrangement::D', 'H': 'Arrangement::H'}
                if len(code_part) == 2 and code_part[0] in type_map and code_part[1] in type_map:
                    fcvt_rd_arr = type_map[code_part[0]]
                    fcvt_rn_arr = type_map[code_part[1]]

        # Pre-compute SVE memory base registers: GP registers that appear inside simple
        # (non-complex) memory brackets in the template (e.g. [<Xn|SP>{, #<imm4>, MUL VL}])
        # These are skipped in the GP register loop and emitted as memory operands later.
        # Also initialize tracking sets for SVE memory template processing.
        sve_z_names_pre = {'Zd', 'Zn', 'Zm', 'Za', 'Zk', 'Zt', 'Zda', 'Zdn'}
        sve_p_names_pre = {'Pd', 'Pn', 'Pm', 'Pg', 'Pt', 'Pv', 'Pdm', 'Pdn', 'PNd', 'PNn', 'PNg', 'PNv'}
        _has_sve_regs_pre = any(rn in field_map and not field_map[rn]['is_fixed'] for rn in sve_z_names_pre)
        _has_pred_regs_pre = any(rn in field_map and not field_map[rn]['is_fixed'] for rn in sve_p_names_pre)
        _asm_template_pre = encoding_info.get('asm_template', '')
        _template_ops_pre = self._parse_template_operands(_asm_template_pre) if _asm_template_pre else []
        sve_mem_base_regs = set()
        consumed_imm_fields = set()
        emitted_fields_pre = set()
        if (_has_sve_regs_pre or _has_pred_regs_pre) and _template_ops_pre:
            for _top in _template_ops_pre:
                if _top.get('in_mem_bracket') and not _top.get('complex_mem'):
                    _f = _top.get('field', '')
                    if _f in ('Xn', 'Xt', 'XnSP') or _f.startswith('X'):
                        if 'Rn' in field_map and not field_map['Rn']['is_fixed']:
                            sve_mem_base_regs.add('Rn')
                        elif 'Rt' in field_map and not field_map['Rt']['is_fixed']:
                            sve_mem_base_regs.add('Rt')
            # Also handle complex [Xn, Xm] GP+GP brackets (e.g. prfb/prfh/prfw/prfd_i_p_br_s)
            _cx_fields = [_top.get('field', '') for _top in _template_ops_pre
                          if _top.get('in_mem_bracket') and _top.get('complex_mem')]
            _cx_gp = [f for f in _cx_fields if f.startswith('X')]
            _cx_sve = [f for f in _cx_fields if f.startswith('Z') or f.startswith('P')]
            if len(_cx_gp) >= 2 and not _cx_sve:
                if 'Rn' in field_map and not field_map['Rn']['is_fixed']:
                    sve_mem_base_regs.add('Rn')
                if 'Rm' in field_map and not field_map['Rm']['is_fixed']:
                    sve_mem_base_regs.add('Rm')
            elif len(_cx_gp) >= 1 and len(_cx_sve) >= 1:
                # GP+SVE-Z complex bracket e.g. [Xn, Zm.D, lsl #N] or [Xn, Zm.S]
                if 'Rn' in field_map and not field_map['Rn']['is_fixed']:
                    sve_mem_base_regs.add('Rn')
                elif 'Rt' in field_map and not field_map['Rt']['is_fixed']:
                    sve_mem_base_regs.add('Rt')

        # Special case: SME ZA LD/ST register-register pattern (za_p_rrr_)
        # Format: {zaXv/h.T[wRs+12, offs]}, Pg/Z, [Xn{, Xm, lsl #scale}]
        if 'za_p_rrr_' in encoding_name and 'Rn' in field_map and 'Pg' in field_map and 'Rs' in field_map:
            rn_field = field_map['Rn']['name']
            pg_field = field_map['Pg']['name']
            rs_field = field_map['Rs']['name']
            rm_field = field_map['Rm']['name'] if 'Rm' in field_map and not field_map['Rm']['is_fixed'] else None
            v_field = field_map['V']['name'] if 'V' in field_map and not field_map['V']['is_fixed'] else None
            # Determine element type and LSL scale from encoding name (and msz if available)
            _en = encoding_name.lower()
            if '1b' in _en or '_b_' in _en:
                _arr, _lsl = 'Arrangement::B', 0
            elif '1h' in _en or '_h_' in _en:
                _arr, _lsl = 'Arrangement::H', 1
            elif '1w' in _en or '_w_' in _en:
                _arr, _lsl = 'Arrangement::S', 2
            elif '1d' in _en or '_d_' in _en:
                _arr, _lsl = 'Arrangement::D', 3
            elif '1q' in _en or '_q_' in _en:
                _arr, _lsl = 'Arrangement::Q', 4
            else:
                _arr, _lsl = 'Arrangement::B', 0
            # Determine tile number and offset from field_map bits[3:0]:
            # B: off4 (4 bits, tile=0); H: ZAt(1b)+off3(3b); S: ZAt(2b)+off2(2b); D: ZAt(3b)+o1(1b); Q: ZAt(4b)
            _tile_field = None
            _offs_field = None
            for _f in ['ZAt', 'ZAd', 'ZAn']:
                if _f in field_map and not field_map[_f]['is_fixed']:
                    _tile_field = field_map[_f]['name']
                    break
            for _f in ['off4', 'off3', 'off2', 'o1']:
                if _f in field_map and not field_map[_f]['is_fixed']:
                    _offs_field = field_map[_f]['name']
                    break
            is_load = mnemonic.upper().startswith('LD')
            # Emit ZA tile slice operand
            code.append(f"{ind}{{")
            if _tile_field:
                code.append(f"{ind}    uint32_t _tile = enc.{member_name}.{_tile_field};")
            else:
                code.append(f"{ind}    uint32_t _tile = 0;  // B-element: always ZA0")
            if _offs_field:
                code.append(f"{ind}    uint32_t _offs = enc.{member_name}.{_offs_field};")
            else:
                code.append(f"{ind}    uint32_t _offs = 0;")
            code.append(f"{ind}    Operand op(OperandType::SMETileRegister, _tile, false);")
            code.append(f"{ind}    op.arrangement = {_arr};")
            code.append(f"{ind}    op.has_index = true;")
            if v_field:
                code.append(f"{ind}    op.is_sp = enc.{member_name}.{v_field} != 0;")
            else:
                code.append(f"{ind}    op.is_sp = false;")
            code.append(f"{ind}    op.index = 12 + enc.{member_name}.{rs_field};")
            code.append(f"{ind}    op.amount = _offs;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            # Emit predicate
            if is_load:
                code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{pg_field}, false); op.arrangement = Arrangement::None; op.is_sp = true; result.operands.push_back(op); }}")
            else:
                code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{pg_field}, true); op.arrangement = Arrangement::None; result.operands.push_back(op); }}")
            # Emit memory operand
            if rm_field:
                if _lsl > 0:
                    code.append(f"{ind}if (enc.{member_name}.{rm_field} == 31)")
                    code.append(f"{ind}    result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")
                    code.append(f"{ind}else")
                    code.append(f"{ind}    result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}, 3, {_lsl}));")
                else:
                    # B-element: no LSL
                    code.append(f"{ind}if (enc.{member_name}.{rm_field} == 31)")
                    code.append(f"{ind}    result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")
                    code.append(f"{ind}else")
                    code.append(f"{ind}    result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field}, enc.{member_name}.{rm_field}));")
            else:
                code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field}));")
            code.append(f"{ind}return result;")
            return code

        # Special case: ZA accumulator range format: ZA.T[Wv, start:end], Zn..., Zm...
        # Detected by: ASM template first operand is ZA.T (no tile number) with range offs1:offs4/offs2
        # Affected: smlall/smlsll/umlall/umlsll/smlal/smlsl/umlal/umlsl/fmlal/bfmlal etc. _za_zzi_/_za_zzv_
        _asm_tmpl = encoding_info.get('asm_template', '')
        import re as _re
        _has_za_range = (
            'Rv' in field_map and not field_map['Rv']['is_fixed'] and
            _re.search(r'\bZA\.(?:[BHSDQ]|<T\w*>)\[<Wv>', _asm_tmpl) is not None and
            '<offs1>:' in _asm_tmpl
        )
        if _has_za_range:
            rv_field = field_map['Rv']['name']
            # Determine element size from template
            _za_arr_match = _re.search(r'\bZA\.([BHSDQ])\[', _asm_tmpl)
            if _za_arr_match:
                _za_arr = _CHAR_TO_ARR[_za_arr_match.group(1).lower()]
                _za_arr_is_variable = False
            elif _re.search(r'\bZA\.<T\w*>\[', _asm_tmpl):
                # Variable arrangement from sz/size field — resolve at runtime
                _za_arr = None  # will use _sve_arr
                _za_arr_is_variable = True
            else:
                _za_arr = 'Arrangement::D'
                _za_arr_is_variable = False
            # Determine offset field and group size (range width from template)
            _off_field = None
            # Detect range width from template: <offs1>:<offs2> = 2-wide, <offs1>:<offs4> = 4-wide
            if '<offs1>:<offs4>' in _asm_tmpl:
                _off_m = 4
            else:
                _off_m = 2  # <offs1>:<offs2> = 2-wide range
            for _f, _m in [('off2', _off_m), ('off3', _off_m), ('o1', _off_m), ('off1', _off_m)]:
                if _f in field_map and not field_map[_f]['is_fixed']:
                    _off_field = field_map[_f]['name']
                    _off_m = _m
                    break
            # Build: first emit ZA range, then SVE registers (in template order: Zn, Zm etc.)
            # Find SVE source registers from field_map
            _zn_entries = []
            for _fn in ['Zn', 'Zn1', 'Zm', 'Zm1']:
                if _fn in field_map and not field_map[_fn]['is_fixed']:
                    _zn_entries.append((_fn, field_map[_fn]['name']))
            # Determine arrangement for SVE sources from template
            _src_arr_match = _re.search(r'<Zn\d?>\.([BHSDQ])', _asm_tmpl)
            if _src_arr_match:
                _src_arr = _CHAR_TO_ARR[_src_arr_match.group(1).lower()]
            elif _re.search(r'<Zn\d?>\.<Tb>', _asm_tmpl):
                _src_arr = '_sve_arr_narrow'  # variable narrowed arrangement at runtime
            else:
                _src_arr = 'Arrangement::H'
            # Emit _sve_arr / _sve_arr_narrow declarations if arrangement is variable
            if _za_arr_is_variable or _src_arr == '_sve_arr_narrow':
                # Find the size field (sz or size)
                _sz_field = None
                for _szf in ['sz', 'size']:
                    if _szf in field_map and not field_map[_szf]['is_fixed']:
                        _sz_field = field_map[_szf]['name']
                        _sz_width = field_map[_szf].get('width', 1)
                        break
                if _sz_field:
                    if _sz_width == 1:
                        code.append(f"{ind}Arrangement _sve_arr = enc.{member_name}.{_sz_field} ? Arrangement::D : Arrangement::S;")
                        # SME ZA <Tb> = 2 steps narrower (widening dot/multiply-add)
                        code.append(f"{ind}Arrangement _sve_arr_narrow = enc.{member_name}.{_sz_field} ? Arrangement::H : Arrangement::B;")
                    else:
                        code.append(f"{ind}Arrangement _sve_arr = Arrangement::None;")
                        code.append(f"{ind}switch (enc.{member_name}.{_sz_field}) {{")
                        code.append(f"{ind}    case 0: _sve_arr = Arrangement::B; break; case 1: _sve_arr = Arrangement::H; break;")
                        code.append(f"{ind}    case 2: _sve_arr = Arrangement::S; break; case 3: _sve_arr = Arrangement::D; break;")
                        code.append(f"{ind}}}")
                        code.append(f"{ind}Arrangement _sve_arr_narrow = Arrangement::None;")
                        code.append(f"{ind}switch (enc.{member_name}.{_sz_field}) {{")
                        code.append(f"{ind}    case 2: _sve_arr_narrow = Arrangement::B; break; case 3: _sve_arr_narrow = Arrangement::H; break;")
                        code.append(f"{ind}}}")
                else:
                    code.append(f"{ind}Arrangement _sve_arr = Arrangement::S;")
                    code.append(f"{ind}Arrangement _sve_arr_narrow = Arrangement::B;")
            # Emit ZA range operand
            code.append(f"{ind}{{")
            if _off_field:
                code.append(f"{ind}    uint32_t _off = enc.{member_name}.{_off_field};")
            else:
                code.append(f"{ind}    uint32_t _off = 0;")
            code.append(f"{ind}    uint32_t _m = {_off_m};")
            code.append(f"{ind}    uint32_t _start = _off * _m;")
            code.append(f"{ind}    uint32_t _end = _start + _m - 1;")
            code.append(f"{ind}    Operand op(OperandType::SMETileRegister, 0, false);")
            if _za_arr_is_variable:
                code.append(f"{ind}    op.arrangement = _sve_arr;")
            else:
                code.append(f"{ind}    op.arrangement = {_za_arr};")
            code.append(f"{ind}    op.has_index = true;")
            # Check if VGx is also present in the template
            _range_vgx_m = _re.search(r'(?:\{, |\b)VGx(\d+)', _asm_tmpl)
            if _range_vgx_m:
                _range_vgx = int(_range_vgx_m.group(1))
                code.append(f"{ind}    op.extend = 3;  // range + VGx mode")
                code.append(f"{ind}    op.index = enc.{member_name}.{rv_field} + 8;")
                code.append(f"{ind}    op.amount = _start;")
                code.append(f"{ind}    op.offset = (int32_t)((_end & 0xFFFF) | ({_range_vgx} << 16));")
            else:
                code.append(f"{ind}    op.extend = 1;  // range mode")
                code.append(f"{ind}    op.index = enc.{member_name}.{rv_field} + 8;")
                code.append(f"{ind}    op.amount = _start;")
                code.append(f"{ind}    op.offset = (int32_t)_end;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            # Emit SVE source registers using index expressions from template
            # Process remaining operands via template
            _za_list_emitted = set()
            for _top in _template_ops_pre:
                _f = _top.get('field', '')
                if _f in ('Zn', 'Zn1', 'Zda', 'Zdn'):
                    _base_key = _re.match(r'^(Zn|Zda|Zdn)', _f).group(1) if _re.match(r'^(Zn|Zda|Zdn)', _f) else _f
                    if _base_key in _za_list_emitted:
                        continue
                    _lookup = _f if _f in field_map else _base_key
                    if _lookup in field_map and not field_map[_lookup]['is_fixed']:
                        _fn = field_map[_lookup]['name']
                        _arr = _STR_TO_ARR.get(_top.get('arrangement', ''), _src_arr)
                        _is_list = _top.get('is_list', False)
                        _cnt = 1
                        if _is_list:
                            _cnt_m = _re.search(r'<Zn1>.*<Zn(\d+)>', _asm_tmpl)
                            if _cnt_m: _cnt = int(_cnt_m.group(1))
                        # Scale register value for narrowed fields (pairs/quads)
                        import math as _math2
                        _fw = field_map[_lookup].get('width', 5)
                        _scale = ''
                        if _cnt > 1 and _fw < 5 and (_cnt & (_cnt - 1)) == 0:
                            _lc = int(_math2.log2(_cnt))
                            if _fw + _lc == 5:
                                _scale = f' * {_cnt}'
                        if _cnt > 1:
                            code.append(f"{ind}{{ Operand op(OperandType::SVERegisterList, enc.{member_name}.{_fn}{_scale}, true); op.arrangement = {_arr or _src_arr}; op.index = {_cnt}; result.operands.push_back(op); }}")
                        else:
                            code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{_fn}, true); op.arrangement = {_arr or _src_arr}; result.operands.push_back(op); }}")
                        _za_list_emitted.add(_base_key)
                elif _f in ('Zm', 'Zm1'):
                    if 'Zm' in _za_list_emitted:
                        continue
                    _lookup = _f if _f in field_map else 'Zm'
                    if _lookup in field_map and not field_map[_lookup]['is_fixed']:
                        _fn = field_map[_lookup]['name']
                        _arr = _STR_TO_ARR.get(_top.get('arrangement', ''), _src_arr)
                        _is_list = _top.get('is_list', False)
                        _cnt = 1
                        if _is_list:
                            _cnt_m = _re.search(r'<Zm1>.*<Zm(\d+)>', _asm_tmpl)
                            if _cnt_m: _cnt = int(_cnt_m.group(1))
                        _has_idx = _top.get('has_elem_index', False)
                        _idx_expr = self._generate_sve_index_expr(field_map, member_name, encoding_name)
                        # Scale register value for narrowed fields (pairs/quads)
                        import math as _math3
                        _fw = field_map[_lookup].get('width', 5)
                        _scale = ''
                        if _cnt > 1 and _fw < 5 and (_cnt & (_cnt - 1)) == 0:
                            _lc = int(_math3.log2(_cnt))
                            if _fw + _lc == 5:
                                _scale = f' * {_cnt}'
                        if _cnt > 1:
                            code.append(f"{ind}{{ Operand op(OperandType::SVERegisterList, enc.{member_name}.{_fn}{_scale}, true); op.arrangement = {_arr or _src_arr}; op.index = {_cnt}; result.operands.push_back(op); }}")
                        elif _has_idx and _idx_expr:
                            code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{_fn}, true); op.arrangement = {_arr or _src_arr}; {_idx_expr} result.operands.push_back(op); }}")
                        else:
                            code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{_fn}, true); op.arrangement = {_arr or _src_arr}; result.operands.push_back(op); }}")
                        _za_list_emitted.add('Zm')
            code.append(f"{ind}return result;")
            return code

        # Special case: ZA accumulator VGx format: ZA.T[Wv, offs{, VGxN}], Zn..., Zm...
        # Detected by: ASM template first operand is ZA.T with {, VGx2} or {, VGx4}
        # Affected: usdot/sudot/bfdot/fmopa etc. _za_zzv_/_za_zzw_ with VGx qualifier
        _has_za_vgx = (
            not _has_za_range and
            'Rv' in field_map and not field_map['Rv']['is_fixed'] and
            _re.search(r'\bZA\.(?:[BHSDQ]|<T\w*>)\[<Wv>', _asm_tmpl) is not None and
            ('VGx' in _asm_tmpl) and
            not (mnemonic in ('MOVA', 'MOVAZ', 'ZERO') and _re.search(r'(mz[24]_za|za[24]_z|z_rza|mz_za[24]|za[0-9]*_ri)', encoding_name))
        )
        if _has_za_vgx:
            rv_field = field_map['Rv']['name']
            # Determine element size from template
            _za_arr_match = _re.search(r'\bZA\.([BHSDQ])\[', _asm_tmpl)
            if _za_arr_match:
                _za_arr = _CHAR_TO_ARR[_za_arr_match.group(1).lower()]
                _za_arr_is_variable_vgx = False
            elif _re.search(r'\bZA\.<T\w*>\[', _asm_tmpl):
                _za_arr = '_sve_arr'
                _za_arr_is_variable_vgx = True
            else:
                _za_arr = 'Arrangement::S'
                _za_arr_is_variable_vgx = False
            # Determine VGx count from template
            _vgx_m = _re.search(r'VGx(\d+)', _asm_tmpl)
            _vgx = int(_vgx_m.group(1)) if _vgx_m else 2
            # Determine offset field
            _off_field = None
            for _f in ['off3', 'off2', 'off1']:
                if _f in field_map and not field_map[_f]['is_fixed']:
                    _off_field = field_map[_f]['name']
                    break
            # Determine arrangement for SVE sources from template
            _src_arr_m = _re.search(r'<Zn\d?>\.([BHSDQ])', _asm_tmpl)
            if _src_arr_m:
                _src_arr = _CHAR_TO_ARR[_src_arr_m.group(1).lower()]
            elif _re.search(r'<Zn\d?>\.<Tb>', _asm_tmpl):
                _src_arr = '_sve_arr_narrow'
            else:
                _src_arr = 'Arrangement::B'
            # Emit _sve_arr / _sve_arr_narrow declarations if arrangement is variable
            if _za_arr_is_variable_vgx or _src_arr == '_sve_arr_narrow':
                _sz_field_vgx = None
                for _szf in ['sz', 'size']:
                    if _szf in field_map and not field_map[_szf]['is_fixed']:
                        _sz_field_vgx = field_map[_szf]['name']
                        _sz_width_vgx = field_map[_szf].get('width', 1)
                        break
                if _sz_field_vgx:
                    if _sz_width_vgx == 1:
                        code.append(f"{ind}Arrangement _sve_arr = enc.{member_name}.{_sz_field_vgx} ? Arrangement::D : Arrangement::S;")
                        # SME ZA <Tb> = 2 steps narrower (widening dot/multiply-add)
                        code.append(f"{ind}Arrangement _sve_arr_narrow = enc.{member_name}.{_sz_field_vgx} ? Arrangement::H : Arrangement::B;")
                    else:
                        code.append(f"{ind}Arrangement _sve_arr = Arrangement::None;")
                        code.append(f"{ind}switch (enc.{member_name}.{_sz_field_vgx}) {{")
                        code.append(f"{ind}    case 0: _sve_arr = Arrangement::B; break; case 1: _sve_arr = Arrangement::H; break;")
                        code.append(f"{ind}    case 2: _sve_arr = Arrangement::S; break; case 3: _sve_arr = Arrangement::D; break;")
                        code.append(f"{ind}}}")
                        code.append(f"{ind}Arrangement _sve_arr_narrow = Arrangement::None;")
                        code.append(f"{ind}switch (enc.{member_name}.{_sz_field_vgx}) {{")
                        code.append(f"{ind}    case 2: _sve_arr_narrow = Arrangement::B; break; case 3: _sve_arr_narrow = Arrangement::H; break;")
                        code.append(f"{ind}}}")
                else:
                    code.append(f"{ind}Arrangement _sve_arr = Arrangement::S;")
                    code.append(f"{ind}Arrangement _sve_arr_narrow = Arrangement::B;")
            # Emit ZA VGx accumulator operand first
            code.append(f"{ind}{{")
            if _off_field:
                code.append(f"{ind}    uint32_t _off = enc.{member_name}.{_off_field};")
            else:
                code.append(f"{ind}    uint32_t _off = 0;")
            code.append(f"{ind}    Operand op(OperandType::SMETileRegister, 0, false);")
            code.append(f"{ind}    op.arrangement = {_za_arr};")
            code.append(f"{ind}    op.has_index = true;")
            code.append(f"{ind}    op.extend = 2;  // VGx mode")
            code.append(f"{ind}    op.index = enc.{member_name}.{rv_field} + 8;")
            code.append(f"{ind}    op.amount = _off;")
            code.append(f"{ind}    op.offset = {_vgx};  // VGx count")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            # Emit SVE source registers in template order.
            # Use base-stripping for list groups: Zn1/Zn2 → base 'Zn' in field_map
            _vgx_list_emitted = set()
            for _top in _template_ops_pre:
                _f = _top.get('field', '')
                _is_zn = _re.match(r'^(Zn|Zda|Zdn)(\d*)$', _f)
                _is_zm = _re.match(r'^(Zm)(\d*)$', _f)
                if _is_zn:
                    _base = _is_zn.group(1)  # 'Zn', 'Zda', 'Zdn'
                    _digit = int(_is_zn.group(2)) if _is_zn.group(2) else 0
                    # Skip non-first list elements (Zn2, Zn3, etc.)
                    if _digit > 1:
                        continue
                    # Skip if already emitted (dedup)
                    if _base in _vgx_list_emitted:
                        continue
                    _lookup = _base
                    if _lookup not in field_map and _f in field_map:
                        _lookup = _f
                    if _lookup not in field_map or field_map[_lookup]['is_fixed']:
                        continue
                    _vgx_list_emitted.add(_base)
                    _fn = field_map[_lookup]['name']
                    _top_arr = _top.get('arrangement', '')
                    if _top_arr and _top_arr.startswith('T') and len(_top_arr) >= 2 and _top_arr[1:2] == 'b':
                        _arr = '_sve_arr_narrow'
                    elif _top_arr and _top_arr.startswith('T'):
                        _arr = '_sve_arr'
                    else:
                        _arr = _STR_TO_ARR.get(_top_arr, _src_arr)
                    _is_list = _top.get('is_list', False)
                    _cnt = 1
                    if _is_list:
                        _cnt_m = _re.search(r'<' + _re.escape(_base) + r'1>.*<' + _re.escape(_base) + r'(\d+)>', _asm_tmpl)
                        if _cnt_m: _cnt = int(_cnt_m.group(1))
                    # Scale register number: field_width + log2(cnt) == 5 means narrowed field
                    import math as _math_vgx1
                    _fw_zn = field_map[_lookup].get('width', 5)
                    _scale_zn = ''
                    if _cnt > 1 and _fw_zn < 5 and (_cnt & (_cnt - 1)) == 0:
                        _lc = int(_math_vgx1.log2(_cnt))
                        if _fw_zn + _lc == 5:
                            _scale_zn = f' * {_cnt}'
                    if _cnt > 1:
                        code.append(f"{ind}{{ Operand op(OperandType::SVERegisterList, enc.{member_name}.{_fn}{_scale_zn}, true); op.arrangement = {_arr or _src_arr}; op.index = {_cnt}; result.operands.push_back(op); }}")
                    else:
                        code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{_fn}, true); op.arrangement = {_arr or _src_arr}; result.operands.push_back(op); }}")
                elif _is_zm:
                    _base = _is_zm.group(1)  # 'Zm'
                    _digit = int(_is_zm.group(2)) if _is_zm.group(2) else 0
                    if _digit > 1:
                        continue
                    if _base in _vgx_list_emitted:
                        continue
                    _lookup = _base
                    if _lookup not in field_map or field_map[_lookup]['is_fixed']:
                        continue
                    _vgx_list_emitted.add(_base)
                    _fn = field_map[_lookup]['name']
                    _top_arr_zm = _top.get('arrangement', '')
                    if _top_arr_zm and _top_arr_zm.startswith('T') and len(_top_arr_zm) >= 2 and _top_arr_zm[1:2] == 'b':
                        _arr = '_sve_arr_narrow'
                    elif _top_arr_zm and _top_arr_zm.startswith('T'):
                        _arr = '_sve_arr'
                    else:
                        _arr = _STR_TO_ARR.get(_top_arr_zm, _src_arr)
                    _is_list = _top.get('is_list', False)
                    _cnt = 1
                    if _is_list:
                        _cnt_m = _re.search(r'<Zm1>.*<Zm(\d+)>', _asm_tmpl)
                        if _cnt_m: _cnt = int(_cnt_m.group(1))
                    _has_idx = _top.get('has_elem_index', False)
                    _idx_expr = self._generate_sve_index_expr(field_map, member_name, encoding_name)
                    # Scale register number for narrowed fields
                    import math as _math_vgx2
                    _fw_zm = field_map[_lookup].get('width', 5)
                    _scale_zm = ''
                    if _cnt > 1 and _fw_zm < 5 and (_cnt & (_cnt - 1)) == 0:
                        _lc = int(_math_vgx2.log2(_cnt))
                        if _fw_zm + _lc == 5:
                            _scale_zm = f' * {_cnt}'
                    if _cnt > 1:
                        code.append(f"{ind}{{ Operand op(OperandType::SVERegisterList, enc.{member_name}.{_fn}{_scale_zm}, true); op.arrangement = {_arr or _src_arr}; op.index = {_cnt}; result.operands.push_back(op); }}")
                    elif _has_idx and _idx_expr:
                        code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{_fn}, true); op.arrangement = {_arr or _src_arr}; {_idx_expr} result.operands.push_back(op); }}")
                    else:
                        code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{_fn}, true); op.arrangement = {_arr or _src_arr}; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: MOVA ZA tile slice → Z vector (z_p_rza_ encoding)
        # Format: Zd.T, Pg/M, ZAtileHV.T[Ws, offs]
        # Template: MOVA <Zd>.T, <Pg>/M, ZA0<HV>.T[<Ws>, <offs>] or MOVA <Zd>.T, <Pg>/M, <ZAn><HV>.T[<Ws>, <offs>]
        if ('z_p_rza_' in encoding_name and 'Zd' in field_map and not field_map['Zd']['is_fixed']
                and 'Rs' in field_map and not field_map['Rs']['is_fixed']
                and 'Pg' in field_map and not field_map['Pg']['is_fixed']):
            zd_field = field_map['Zd']['name']
            pg_field = field_map['Pg']['name']
            rs_field = field_map['Rs']['name']
            v_field = field_map['V']['name'] if 'V' in field_map and not field_map['V']['is_fixed'] else None
            _en = encoding_name.lower()
            if '_b' in _en: _arr = 'Arrangement::B'
            elif '_h' in _en: _arr = 'Arrangement::H'
            elif '_w' in _en: _arr = 'Arrangement::S'
            elif '_d' in _en: _arr = 'Arrangement::D'
            elif '_q' in _en: _arr = 'Arrangement::Q'
            else: _arr = 'Arrangement::B'
            # Find tile and offset fields
            _tile_field = None
            _offs_field = None
            for _f in ['ZAn', 'ZAt', 'ZAd']:
                if _f in field_map and not field_map[_f]['is_fixed']:
                    _tile_field = field_map[_f]['name']
                    break
            for _f in ['off4', 'off3', 'off2', 'o1']:
                if _f in field_map and not field_map[_f]['is_fixed']:
                    _offs_field = field_map[_f]['name']
                    break
            # Emit: SVERegister(Zd), PredicateRegister(Pg/M), SMETileRegister(ZA slice)
            code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{zd_field}, true); op.arrangement = {_arr}; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{pg_field}, true); op.arrangement = Arrangement::None; op.is_sp = true; result.operands.push_back(op); }}")
            code.append(f"{ind}{{")
            if _tile_field:
                code.append(f"{ind}    uint32_t _tile = enc.{member_name}.{_tile_field};")
            else:
                code.append(f"{ind}    uint32_t _tile = 0;  // B-element: always ZA0")
            if _offs_field:
                code.append(f"{ind}    uint32_t _offs = enc.{member_name}.{_offs_field};")
            else:
                code.append(f"{ind}    uint32_t _offs = 0;")
            code.append(f"{ind}    Operand op(OperandType::SMETileRegister, _tile, false);")
            code.append(f"{ind}    op.arrangement = {_arr};")
            code.append(f"{ind}    op.has_index = true;")
            if v_field:
                code.append(f"{ind}    op.is_sp = enc.{member_name}.{v_field} != 0;")
            else:
                code.append(f"{ind}    op.is_sp = false;")
            code.append(f"{ind}    op.index = 12 + enc.{member_name}.{rs_field};")
            code.append(f"{ind}    op.amount = _offs;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            code.append(f"{ind}return result;")
            return code

        # Special case: MOVA Z vector → ZA tile slice (za_p_rz_ or za_p_prz_ encoding)
        # Format: ZAtileHV.T[Ws, offs], Pg/M, Zn.T
        # Template: MOV/MOVA ZA0<HV>.T[<Ws>, <offs>], <Pg>/M, <Zn>.T
        if (('za_p_rz_' in encoding_name or 'za_p_prz_' in encoding_name)
                and 'Zn' in field_map and not field_map['Zn']['is_fixed']
                and 'Rs' in field_map and not field_map['Rs']['is_fixed']
                and 'Pg' in field_map and not field_map['Pg']['is_fixed']):
            zn_field = field_map['Zn']['name']
            pg_field = field_map['Pg']['name']
            rs_field = field_map['Rs']['name']
            v_field = field_map['V']['name'] if 'V' in field_map and not field_map['V']['is_fixed'] else None
            _en = encoding_name.lower()
            if '_b' in _en: _arr = 'Arrangement::B'
            elif '_h' in _en: _arr = 'Arrangement::H'
            elif '_w' in _en: _arr = 'Arrangement::S'
            elif '_d' in _en: _arr = 'Arrangement::D'
            elif '_q' in _en: _arr = 'Arrangement::Q'
            else: _arr = 'Arrangement::B'
            _tile_field = None
            _offs_field = None
            for _f in ['ZAd', 'ZAt', 'ZAn']:
                if _f in field_map and not field_map[_f]['is_fixed']:
                    _tile_field = field_map[_f]['name']
                    break
            for _f in ['off4', 'off3', 'off2', 'o1']:
                if _f in field_map and not field_map[_f]['is_fixed']:
                    _offs_field = field_map[_f]['name']
                    break
            # Emit: SMETileRegister(ZA slice), PredicateRegister(Pg/M), SVERegister(Zn)
            code.append(f"{ind}{{")
            if _tile_field:
                code.append(f"{ind}    uint32_t _tile = enc.{member_name}.{_tile_field};")
            else:
                code.append(f"{ind}    uint32_t _tile = 0;")
            if _offs_field:
                code.append(f"{ind}    uint32_t _offs = enc.{member_name}.{_offs_field};")
            else:
                code.append(f"{ind}    uint32_t _offs = 0;")
            code.append(f"{ind}    Operand op(OperandType::SMETileRegister, _tile, false);")
            code.append(f"{ind}    op.arrangement = {_arr};")
            code.append(f"{ind}    op.has_index = true;")
            if v_field:
                code.append(f"{ind}    op.is_sp = enc.{member_name}.{v_field} != 0;")
            else:
                code.append(f"{ind}    op.is_sp = false;")
            code.append(f"{ind}    op.index = 12 + enc.{member_name}.{rs_field};")
            code.append(f"{ind}    op.amount = _offs;")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{pg_field}, true); op.arrangement = Arrangement::None; op.is_sp = true; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{zn_field}, true); op.arrangement = {_arr}; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Special case: SME outer product / simple accumulator ops with ZAda as first operand
        # Template: SUMOPA <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.B, <Zm>.B
        # Must emit ZAda first with correct arrangement, before predicates and Z registers
        _za_first_emitted = False
        if _template_ops_pre:
            _first_field = _template_ops_pre[0].get('field', '')
            if _first_field in ('ZAda', 'ZAd') and _first_field in field_map and not field_map[_first_field]['is_fixed']:
                _za_cpp = field_map[_first_field]['name']
                _za_first_arr = _template_ops_pre[0].get('arrangement', '')
                if _za_first_arr and _za_first_arr in _STR_TO_ARR:
                    _za_first_arr_expr = _STR_TO_ARR[_za_first_arr]
                else:
                    # Default to S for outer product ops
                    _za_first_arr_expr = 'Arrangement::S'
                code.append(f"{ind}{{ Operand op(OperandType::SMETileRegister, enc.{member_name}.{_za_cpp}, true); op.arrangement = {_za_first_arr_expr}; result.operands.push_back(op); }}")
                _za_first_emitted = True

        # Pre-compute: which GP registers appear in the SVE/predicate template (will be emitted in template order)
        # Mapping from template token names (Xn, Xm, Wn...) to field_map keys (Rn, Rm...)
        _gp_tok_to_field = {
            'Xn': 'Rn', 'Xm': 'Rm', 'Xd': 'Rd', 'Xt': 'Rt', 'Xs': 'Rs',
            'Wn': 'Rn', 'Wm': 'Rm', 'Wd': 'Rd', 'Wt': 'Rt',
            'XnSP': 'Rn', 'XdSP': 'Rd', 'XnOrXZR': 'Rn',
            'Xdn': 'Rdn', 'Wdn': 'Rdn', 'Xda': 'Rda', 'Wda': 'Rda',
            # Merged <R><dn> → Rdn etc. for destructive GP operands in SVE templates
            'Rdn': 'Rdn', 'Rda': 'Rda', 'Rn': 'Rn', 'Rm': 'Rm', 'Rd': 'Rd',
        }
        _gp_tok_is_64 = {
            'Xn': True, 'Xm': True, 'Xd': True, 'Xt': True, 'Xs': True,
            'Wn': False, 'Wm': False, 'Wd': False, 'Wt': False,
            'XnSP': True, 'XdSP': True, 'XnOrXZR': True,
            'Xdn': True, 'Wdn': False, 'Xda': True, 'Wda': False,
            'Rdn': False, 'Rda': False, 'Rn': False, 'Rm': False, 'Rd': False,  # width determined by R prefix
        }
        _sve_has_pred_or_z = any(rn in field_map and not field_map[rn]['is_fixed'] for rn in
            ('Zd','Zn','Zm','Za','Zk','Zt','Zda','Zdn','Pd','Pn','Pm','Pg','Pt','Pv'))
        _tmpl_for_gp = self._parse_template_operands(encoding_info.get('asm_template','')) if _sve_has_pred_or_z else []
        _gp_in_sve_template = set()  # field_map keys (Rn, Rm) handled in SVE template order
        for _top in _tmpl_for_gp:
            _tf = _top.get('field','')
            if _tf in _gp_tok_to_field and not _top.get('in_mem_bracket', False):
                _gp_in_sve_template.add(_gp_tok_to_field[_tf])

        for reg_name in ['Rd', 'Rn', 'Rm', 'Ra', 'Rt', 'Rs', 'Rt2', 'Rdn']:
            if reg_name in field_map and not field_map[reg_name]['is_fixed']:
                field_cpp_name = field_map[reg_name]['name']
                # Skip GP registers that are SVE memory bases (emitted later in SVE template loop)
                if reg_name in sve_mem_base_regs:
                    continue
                # Skip GP registers that appear in SVE/predicate template (emitted in template order)
                if reg_name in _gp_in_sve_template:
                    continue
                # Skip Rm for FCMP/FCMPE zero variants (replaced by #0.0 below)
                if scalar_fp_arr and is_fp_cmp_zero and reg_name == 'Rm':
                    continue
                # FCVT: Rd and Rn use different FP types
                if fcvt_rd_arr and reg_name == 'Rd':
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = {fcvt_rd_arr}; result.operands.push_back(op); }}")
                    continue
                elif fcvt_rn_arr and reg_name == 'Rn':
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = {fcvt_rn_arr}; result.operands.push_back(op); }}")
                    continue
                # Scalar FP: use arrangement from encoding name (s/d/h)
                elif scalar_fp_arr == 'DYNAMIC_SZ':
                    # sz field: 0→S, 1→D
                    sz_f = field_map['sz']['name']
                    code.append(f"{ind}{{ static const Arrangement _sc[] = {{Arrangement::S, Arrangement::D}};")
                    code.append(f"{ind}  Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = _sc[enc.{member_name}.{sz_f}]; result.operands.push_back(op); }}")
                elif scalar_fp_arr == 'DYNAMIC_SIZE':
                    # size field: 0→B, 1→H, 2→S, 3→D
                    size_f = field_map['size']['name']
                    code.append(f"{ind}{{ static const Arrangement _sc[] = {{Arrangement::B, Arrangement::H, Arrangement::S, Arrangement::D}};")
                    code.append(f"{ind}  Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = _sc[enc.{member_name}.{size_f}]; result.operands.push_back(op); }}")
                elif scalar_fp_arr:
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = {scalar_fp_arr}; result.operands.push_back(op); }}")
                elif is_advsimd_vector:
                    # Across-lane reduction: Rd is scalar of appropriate width
                    if mnemonic in ['UADDLV', 'SADDLV'] and reg_name == 'Rd' and 'size' in field_map and not field_map['size']['is_fixed']:
                        size_f = field_map['size']['name']
                        # Widening: size 0(B)→h, 1(H)→s, 2(S)→d
                        code.append(f"{ind}{{")
                        code.append(f'{ind}    static const Arrangement _scalar_arr[] = {{Arrangement::H, Arrangement::S, Arrangement::D, Arrangement::D}};')
                        code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false);")
                        code.append(f"{ind}    op.arrangement = _scalar_arr[enc.{member_name}.{size_f}];")
                        code.append(f"{ind}    result.operands.push_back(op);")
                        code.append(f"{ind}}}")
                    elif mnemonic in ['ADDV', 'UMINV', 'UMAXV', 'SMINV', 'SMAXV', 'FMAXV', 'FMINV', 'FMAXNMV', 'FMINNMV'] and reg_name == 'Rd' and 'size' in field_map and not field_map['size']['is_fixed']:
                        size_f = field_map['size']['name']
                        # Non-widening: size 0→b, 1→h, 2→s
                        code.append(f"{ind}{{")
                        code.append(f'{ind}    static const Arrangement _scalar_arr[] = {{Arrangement::B, Arrangement::H, Arrangement::S, Arrangement::D}};')
                        code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false);")
                        code.append(f"{ind}    op.arrangement = _scalar_arr[enc.{member_name}.{size_f}];")
                        code.append(f"{ind}    result.operands.push_back(op);")
                        code.append(f"{ind}}}")
                    elif mnemonic in ['FMAXV', 'FMINV', 'FMAXNMV', 'FMINNMV'] and reg_name == 'Rd' and 'asimdall' in encoding_name_lower:
                        # FP across-lane reductions: scalar dest regardless of vector source
                        if 'size' in field_map and field_map['size']['is_fixed']:
                            _sz_val = int(field_map['size']['fixed'], 2) if field_map['size']['fixed'] else 0
                            _arr_map = {0: 'Arrangement::B', 1: 'Arrangement::H', 2: 'Arrangement::S', 3: 'Arrangement::D'}
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = {_arr_map[_sz_val]}; result.operands.push_back(op); }}")
                        elif 'sz' in field_map and not field_map['sz']['is_fixed']:
                            sz_f = field_map['sz']['name']
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = enc.{member_name}.{sz_f} ? Arrangement::D : Arrangement::S; result.operands.push_back(op); }}")
                        elif 'sz' in field_map and field_map['sz']['is_fixed']:
                            _sz_val = int(field_map['sz']['fixed'], 2) if field_map['sz']['fixed'] else 0
                            _arr = 'Arrangement::D' if _sz_val else 'Arrangement::S'
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = {_arr}; result.operands.push_back(op); }}")
                        elif '_only_h' in encoding_name_lower:
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = Arrangement::H; result.operands.push_back(op); }}")
                        else:
                            # Fallback: use generic arrangement
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = _simd_arr; result.operands.push_back(op); }}")
                    elif mnemonic in ['SDOT', 'UDOT', 'USDOT', 'SUDOT', 'BFDOT', 'SMMLA', 'UMMLA', 'USMMLA', 'BFMMLA'] and reg_name == 'Rd':
                        # Dot product / matrix multiply: Rd uses RESULT arrangement (.2s/.4s)
                        # regardless of source element size
                        if 'Q' in field_map and not field_map['Q']['is_fixed']:
                            q_f = field_map['Q']['name']
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = enc.{member_name}.{q_f} ? Arrangement::S4 : Arrangement::S2; result.operands.push_back(op); }}")
                        else:
                            q_val = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['fixed'] else 0
                            arr = "Arrangement::S4" if q_val else "Arrangement::S2"
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = {arr}; result.operands.push_back(op); }}")
                    elif mnemonic in ['SDOT', 'UDOT', 'USDOT', 'SUDOT', 'SMMLA', 'UMMLA', 'USMMLA', 'BFMMLA'] and reg_name in ('Rn', 'Rm'):
                        # Integer dot product / matrix multiply sources: always byte arrangement
                        if 'Q' in field_map and not field_map['Q']['is_fixed']:
                            q_f = field_map['Q']['name']
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = enc.{member_name}.{q_f} ? Arrangement::B16 : Arrangement::B8; result.operands.push_back(op); }}")
                        else:
                            q_val = int(field_map['Q']['fixed'], 2) if 'Q' in field_map and field_map['Q']['fixed'] else 0
                            arr = "Arrangement::B16" if q_val else "Arrangement::B8"
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = {arr}; result.operands.push_back(op); }}")
                    elif mnemonic == 'PMULL' and reg_name == 'Rd':
                        # PMULL destination: size=0 → .8h (8-bit poly), size=3 → .1q (64-bit poly)
                        if 'size' in field_map and not field_map['size']['is_fixed']:
                            size_f = field_map['size']['name']
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = (enc.{member_name}.{size_f} == 3) ? Arrangement::Q1 : Arrangement::H8; result.operands.push_back(op); }}")
                        else:
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = Arrangement::Q1; result.operands.push_back(op); }}")
                    elif mnemonic in ['SADDLP', 'UADDLP', 'SADALP', 'UADALP'] and reg_name == 'Rd' and simd_arrangement == 'runtime':
                        # Pairwise long accumulate: Rd uses next wider arrangement than Rn
                        code.append(f"{ind}{{")
                        code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false);")
                        if 'size' in field_map and not field_map['size']['is_fixed']:
                            size_f = field_map['size']['name']
                            if 'Q' in field_map and not field_map['Q']['is_fixed']:
                                q_f = field_map['Q']['name']
                                code.append(f'{ind}    static const Arrangement _plong_arrs[2][4] = {{{{Arrangement::H4, Arrangement::S2, Arrangement::D1, Arrangement::D1}}, {{Arrangement::H8, Arrangement::S4, Arrangement::D2, Arrangement::D2}}}};')
                                code.append(f"{ind}    op.arrangement = _plong_arrs[enc.{member_name}.{q_f}][enc.{member_name}.{size_f}];")
                            else:
                                code.append(f'{ind}    static const Arrangement _plong_arrs[] = {{Arrangement::H8, Arrangement::S4, Arrangement::D2, Arrangement::D2}};')
                                code.append(f"{ind}    op.arrangement = _plong_arrs[enc.{member_name}.{size_f}];")
                        else:
                            code.append(f"{ind}    op.arrangement = _simd_arr;  // fallback")
                        code.append(f"{ind}    result.operands.push_back(op);")
                        code.append(f"{ind}}}")
                    elif mnemonic in ['ADDHN', 'SUBHN', 'RADDHN', 'RSUBHN'] and reg_name in ('Rn', 'Rm') and simd_arrangement == 'runtime':
                        # Narrowing ops: Rn/Rm (sources) use the WIDE arrangement (one step up from dest)
                        # dest uses _simd_arr (Q+size → narrow result), sources are always wide (size-indexed)
                        code.append(f"{ind}{{")
                        code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false);")
                        if 'size' in field_map and not field_map['size']['is_fixed']:
                            size_f = field_map['size']['name']
                            code.append(f'{ind}    static const Arrangement _wide_arrs[] = {{Arrangement::H8, Arrangement::S4, Arrangement::D2, Arrangement::D2}};')
                            code.append(f"{ind}    op.arrangement = _wide_arrs[enc.{member_name}.{size_f}];")
                        else:
                            code.append(f"{ind}    op.arrangement = _simd_arr;  // fallback")
                        code.append(f"{ind}    result.operands.push_back(op);")
                        code.append(f"{ind}}}")
                    elif mnemonic in ['SMLAL', 'SMLSL', 'UMLAL', 'UMLSL', 'SMULL', 'UMULL', 'SQDMLAL', 'SQDMLSL', 'SQDMULL', 'SABAL', 'UABAL', 'SABDL', 'UABDL', 'SADDL', 'UADDL', 'SSUBL', 'USUBL', 'SSHLL', 'USHLL', 'SADDW', 'UADDW', 'SSUBW', 'USUBW'] and (reg_name == 'Rd' or (reg_name == 'Rn' and mnemonic in ['SADDW', 'UADDW', 'SSUBW', 'USUBW'])) and simd_arrangement == 'runtime':
                        # Widening: Rd uses next wider arrangement
                        # Source arr is set via _simd_arr; Rd needs wider version
                        code.append(f"{ind}{{")
                        code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false);")
                        if 'size' in field_map and not field_map['size']['is_fixed']:
                            size_f = field_map['size']['name']
                            if 'Q' in field_map and not field_map['Q']['is_fixed']:
                                q_f = field_map['Q']['name']
                                code.append(f'{ind}    static const Arrangement _wide_arrs[][2] = {{{{Arrangement::H8, Arrangement::H8}}, {{Arrangement::S4, Arrangement::S4}}, {{Arrangement::D2, Arrangement::D2}}}};')
                                code.append(f"{ind}    op.arrangement = _wide_arrs[enc.{member_name}.{size_f}][0];")
                            else:
                                code.append(f'{ind}    static const Arrangement _wide_arrs[] = {{Arrangement::H8, Arrangement::S4, Arrangement::D2, Arrangement::D2}};')
                                code.append(f"{ind}    op.arrangement = _wide_arrs[enc.{member_name}.{size_f}];")
                        else:
                            code.append(f"{ind}    op.arrangement = _simd_arr;  // fallback")
                        code.append(f"{ind}    result.operands.push_back(op);")
                        code.append(f"{ind}}}")
                    elif mnemonic in ['XTN', 'SQXTN', 'UQXTN', 'SQXTUN'] and reg_name == 'Rn' and simd_arrangement == 'runtime':
                        # Narrowing ops: Rn (source) uses wide arrangement, indexed by size only
                        # (source is always the full 128-bit register regardless of Q)
                        # size=0→"8h", size=1→"4s", size=2→"2d"
                        code.append(f"{ind}{{")
                        code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false);")
                        if 'size' in field_map and not field_map['size']['is_fixed']:
                            size_f = field_map['size']['name']
                            code.append(f'{ind}    static const Arrangement _narrow_src[] = {{Arrangement::H8, Arrangement::S4, Arrangement::D2, Arrangement::D2}};')
                            code.append(f"{ind}    op.arrangement = _narrow_src[enc.{member_name}.{size_f}];")
                        else:
                            code.append(f"{ind}    op.arrangement = _simd_arr;  // fallback")
                        code.append(f"{ind}    result.operands.push_back(op);")
                        code.append(f"{ind}}}")
                    elif (mnemonic in ['MOVI', 'MVNI'] or (mnemonic == 'FMOV' and 'asimdimm' in encoding_name)) and reg_name == 'Rd':
                        # MOVI/MVNI/FMOV-vector need arrangement from Q and cmode fields
                        code.append(f"{ind}{{")
                        code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false);")
                        code.append(f"{ind}    op.arrangement = get_movi_arrangement(insn);")
                        code.append(f"{ind}    result.operands.push_back(op);")
                        code.append(f"{ind}}}")
                    elif mnemonic in ['FMAXV', 'FMINV', 'FMAXNMV', 'FMINNMV'] and reg_name == 'Rn' and '_only_h' in encoding_name_lower:
                        # FP16 reduce-across: source vector is .4h (Q=0) or .8h (Q=1)
                        if 'Q' in field_map and not field_map['Q']['is_fixed']:
                            q_f = field_map['Q']['name']
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = enc.{member_name}.{q_f} ? Arrangement::H8 : Arrangement::H4; result.operands.push_back(op); }}")
                        else:
                            code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = Arrangement::H4; result.operands.push_back(op); }}")
                    elif mnemonic in ['SHA256H', 'SHA256H2', 'SHA512H', 'SHA512H2'] and reg_name in ('Rd', 'Rn'):
                        # SHA hash: Rd and Rn are Q registers (128-bit scalar)
                        code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = Arrangement::Q; result.operands.push_back(op); }}")
                    elif mnemonic in ['SHA1C', 'SHA1M', 'SHA1P'] and reg_name == 'Rd':
                        # SHA1 hash: Rd is Q register
                        code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = Arrangement::Q; result.operands.push_back(op); }}")
                    elif mnemonic in ['SHA1C', 'SHA1M', 'SHA1P'] and reg_name == 'Rn':
                        # SHA1 hash: Rn is S register (32-bit scalar)
                        code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = Arrangement::S; result.operands.push_back(op); }}")
                    elif simd_arrangement == 'static':
                        code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = {static_arr}; result.operands.push_back(op); }}")
                    elif simd_arrangement == 'runtime':
                        code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = _simd_arr; result.operands.push_back(op); }}")
                    else:
                        code.append(f"{ind}result.operands.push_back(Operand(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false));")
                else:
                    # CRC32 instructions: Rd/Rn are always 32-bit, only Rm uses sf-dependent width
                    if mnemonic.startswith('CRC32') and reg_name in ('Rd', 'Rn'):
                        code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{field_cpp_name}, false));")
                    else:
                        code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{field_cpp_name}, is_64bit));")

        # Add implicit #0 for SIMD compare-to-zero forms (encoding names ending in _z, non-SVE)
        _needs_sve_zero = False
        if mnemonic in ['CMEQ', 'CMGE', 'CMGT', 'CMLE', 'CMLT', 'FCMEQ', 'FCMGE', 'FCMGT', 'FCMLE', 'FCMLT'] and (encoding_name.endswith('_z') or encoding_name.endswith('_z0_')):
            is_sve_zero = encoding_name.endswith('_z0_')
            if is_sve_zero:
                # SVE zero-compare: add #0.0 AFTER SVE registers (deferred)
                _needs_sve_zero = True
            elif mnemonic.startswith('F'):
                code.append(f"{ind}{{ Operand op(OperandType::FloatImmediate, 0, true); op.imm64 = UINT64_MAX; result.operands.push_back(op); }}")
            else:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, 0, true));")

        # Add #0.0 for FCMP/FCMPE zero variants (use imm64=UINT64_MAX as literal-zero sentinel)
        if is_fp_cmp_zero:
            code.append(f"{ind}{{ Operand op(OperandType::FloatImmediate, 0, true); op.imm64 = UINT64_MAX; result.operands.push_back(op); }}")

        # SVE/SME operand extraction using template-based ordering
        sve_index_consumed = False  # True if index fields (i3h:i3l etc.) were used as element index
        has_tsz_size = False  # True if tszh:tszl fields determine element size (SVE shift-by-imm)
        sve_z_names = {'Zd', 'Zn', 'Zm', 'Za', 'Zk', 'Zt', 'Zda', 'Zdn'}
        sve_p_names = {'Pd', 'Pn', 'Pm', 'Pg', 'Pt', 'Pv', 'Pdm', 'Pdn', 'PNd', 'PNn', 'PNg', 'PNv'}
        has_sve_regs = any(rn in field_map and not field_map[rn]['is_fixed'] for rn in sve_z_names)
        has_pred_regs = any(rn in field_map and not field_map[rn]['is_fixed'] for rn in sve_p_names)

        asm_template = encoding_info.get('asm_template', '')
        template_ops = self._parse_template_operands(asm_template) if asm_template else []

        # --- Special cases for specific SVE encoding patterns ---

        # PSEL: Predicate select (psel_p_ppi_)
        # Template: PSEL <Pd>, <Pn>, <Pm>.<T>[<Wv>, <imm>]
        # Pd and Pn have NO arrangement; Pm has arrangement from LOWEST set bit of tszh:tszl + [Wv, i1]
        if encoding_name == 'psel_p_ppi_' and 'Pd' in field_map and 'Pn' in field_map and 'Pm' in field_map:
            pd_cpp = field_map['Pd']['name']
            pn_cpp = field_map['Pn']['name']
            pm_cpp = field_map['Pm']['name']
            tszh_cpp = field_map['tszh']['name'] if 'tszh' in field_map else None
            tszl_cpp = field_map['tszl']['name'] if 'tszl' in field_map else None
            tszl_w = field_map['tszl'].get('width', 3) if 'tszl' in field_map else 3
            rv_cpp = field_map['Rv']['name'] if 'Rv' in field_map else None
            i1_cpp = field_map['i1']['name'] if 'i1' in field_map else None
            if tszh_cpp and tszl_cpp and rv_cpp and i1_cpp:
                code.append(f"{ind}result.operands.clear();  // PSEL special case: discard generic operands")
                code.append(f"{ind}// PSEL: Pd/Pn have no arrangement; Pm has <T>[Wv, i1]")
                code.append(f"{ind}// Arrangement from LOWEST set bit of tszh:tszl")
                code.append(f"{ind}uint32_t _tsize = (enc.{member_name}.{tszh_cpp} << {tszl_w}) | enc.{member_name}.{tszl_cpp};")
                code.append(f"{ind}Arrangement _sve_arr = Arrangement::None;")
                code.append(f"{ind}if (_tsize & 1) _sve_arr = Arrangement::B; else if (_tsize & 2) _sve_arr = Arrangement::H; else if (_tsize & 4) _sve_arr = Arrangement::S; else if (_tsize & 8) _sve_arr = Arrangement::D;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::PredicateRegister, enc.{member_name}.{pd_cpp}, true));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::PredicateRegister, enc.{member_name}.{pn_cpp}, true));")
                code.append(f"{ind}uint32_t _imm5 = (enc.{member_name}.{i1_cpp} << 4) | (enc.{member_name}.{tszh_cpp} << {tszl_w}) | enc.{member_name}.{tszl_cpp};")
                code.append(f"{ind}uint32_t _psel_idx = (_tsize & 1) ? (_imm5 >> 1) : (_tsize & 2) ? (_imm5 >> 2) : (_tsize & 4) ? (_imm5 >> 3) : (_imm5 >> 4);")
                code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{pm_cpp}, true); op.arrangement = _sve_arr; op.has_index = true; op.index = _psel_idx; op.index_reg = enc.{member_name}.{rv_cpp} + 12; result.operands.push_back(op); }}")
                code.append(f"{ind}return result;")
                return code

        # PEXT single (pext_pn_rr_): PEXT <Pd>.<T>, <PNn>[<imm>]
        # PNn index (imm2) stored as has_index in PNn operand (not separate Immediate)
        if encoding_name == 'pext_pn_rr_' and 'Pd' in field_map and 'PNn' in field_map:
            pd_cpp = field_map['Pd']['name']
            pnn_cpp = field_map['PNn']['name']
            imm2_cpp = field_map['imm2']['name'] if 'imm2' in field_map else None
            size_cpp = field_map['size']['name'] if 'size' in field_map and not field_map['size']['is_fixed'] else None
            if size_cpp:
                code.append(f"{ind}result.operands.clear();  // PEXT pn_rr special case")
                code.append(f"{ind}Arrangement _sve_arr = Arrangement::None;")
                code.append(f"{ind}switch (enc.{member_name}.{size_cpp}) {{")
                code.append(f"{ind}    case 0: _sve_arr = Arrangement::B; break; case 1: _sve_arr = Arrangement::H; break;")
                code.append(f"{ind}    case 2: _sve_arr = Arrangement::S; break; case 3: _sve_arr = Arrangement::D; break;")
                code.append(f"{ind}}}")
                code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{pd_cpp}, true); op.arrangement = _sve_arr; result.operands.push_back(op); }}")
                if imm2_cpp:
                    code.append(f"{ind}{{ Operand op(OperandType::PredicateNRegister, enc.{member_name}.{pnn_cpp} | 8u, true); op.has_index = true; op.index = enc.{member_name}.{imm2_cpp}; result.operands.push_back(op); }}")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::PredicateNRegister, enc.{member_name}.{pnn_cpp} | 8u, true));")
                code.append(f"{ind}return result;")
                return code

        # PEXT pair (pext_pp_rr_): PEXT { <Pd1>.<T>, <Pd2>.<T> }, <PNn>[<imm>]
        # Pd is 4-bit encoding Pd1; Pd2=Pd1+1; PNn index in brackets
        if encoding_name == 'pext_pp_rr_' and 'Pd' in field_map and 'PNn' in field_map:
            pd_cpp = field_map['Pd']['name']
            pnn_cpp = field_map['PNn']['name']
            i1_cpp = field_map['i1']['name'] if 'i1' in field_map else None
            size_cpp = field_map['size']['name'] if 'size' in field_map and not field_map['size']['is_fixed'] else None
            if size_cpp:
                code.append(f"{ind}result.operands.clear();  // PEXT pp_rr special case")
                code.append(f"{ind}Arrangement _sve_arr = Arrangement::None;")
                code.append(f"{ind}switch (enc.{member_name}.{size_cpp}) {{")
                code.append(f"{ind}    case 0: _sve_arr = Arrangement::B; break; case 1: _sve_arr = Arrangement::H; break;")
                code.append(f"{ind}    case 2: _sve_arr = Arrangement::S; break; case 3: _sve_arr = Arrangement::D; break;")
                code.append(f"{ind}}}")
                code.append(f"{ind}uint32_t _pd1 = enc.{member_name}.{pd_cpp};  // 4-bit Pd1, Pd2=Pd1+1")
                code.append(f"{ind}{{ Operand op(OperandType::PredicateRegisterList, _pd1, true); op.arrangement = _sve_arr; op.index = 2; result.operands.push_back(op); }}")
                if i1_cpp:
                    code.append(f"{ind}{{ Operand op(OperandType::PredicateNRegister, enc.{member_name}.{pnn_cpp} | 8u, true); op.has_index = true; op.index = enc.{member_name}.{i1_cpp}; result.operands.push_back(op); }}")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::PredicateNRegister, enc.{member_name}.{pnn_cpp} | 8u, true));")
                code.append(f"{ind}return result;")
                return code

        # MOVA/MOVAZ: ZA tile access with H/V + Ws + offset range
        import re as _re_mova
        _mova_m = _re_mova.search(r'(mov(?:az?)?|zero)_(mz[24]_za|za[24]_z|z_rza|mz_za[24]|za[0-9]*_ri)_([bhwdq]?)(\d*)', encoding_name)
        if _mova_m and mnemonic in ('MOVA', 'MOVAZ', 'ZERO'):
            _prefix = _mova_m.group(2)  # mz2_za, za2_z, z_rza, mz_za2, za1_ri
            _arr_ch = _mova_m.group(3)  # b, h, w(=s), d
            _arr_map = {'b': ('Arrangement::B', 0), 'h': ('Arrangement::H', 1), 'w': ('Arrangement::S', 2), 'd': ('Arrangement::D', 3), 'q': ('Arrangement::Q', 4)}
            _arr_str, _arr_idx = _arr_map.get(_arr_ch, ('Arrangement::D', 3))
            # Determine fields
            _has_V = 'V' in field_map and not field_map['V']['is_fixed']
            _has_Rs = 'Rs' in field_map and not field_map['Rs']['is_fixed']
            _has_Rv = 'Rv' in field_map and not field_map['Rv']['is_fixed']
            _rs_field = field_map.get('Rs', field_map.get('Rv', {})).get('name', 'Rs')
            # Offset field
            _off_field = None
            for fn in ['off3', 'off2', 'off1', 'off4', 'o1']:
                if fn in field_map and not field_map[fn]['is_fixed']:
                    _off_field = fn
                    break
            # ZA tile number field
            _tile_field = None
            for fn in ['ZAn', 'ZAd', 'ZAda']:
                if fn in field_map and not field_map[fn]['is_fixed']:
                    _tile_field = fn
                    break
            # Z register fields
            _zd_field = field_map.get('Zd', {}).get('name')
            _zn_field = field_map.get('Zn', {}).get('name')
            # Determine group size and offset multiplier
            _is_mz_za = _prefix.startswith('mz_za')  # mz_za2, mz_za4
            _is_mz2 = _prefix.startswith('mz2')     # mz2_za
            _is_mz4 = _prefix.startswith('mz4')     # mz4_za
            _is_za2 = _prefix.startswith('za2')      # za2_z
            _is_za4 = _prefix.startswith('za4')      # za4_z
            _is_za1 = _prefix.startswith('za1') or (_prefix.endswith('_ri') and not _is_za2 and not _is_za4)
            _is_z_rza = _prefix == 'z_rza'
            # Direction: mz2_za, mz4_za, z_rza, mz_za2, mz_za4 → ZA to Z (output = Z regs)
            # za2_z, za4_z → Z to ZA (output = ZA tile)
            _is_za_to_z = _is_mz2 or _is_mz4 or _is_z_rza or _is_mz_za  # ZA → Z direction
            _is_z_to_za = _is_za2 or _is_za4 or _is_za1  # Z → ZA direction

            if (_has_Rs or _has_Rv):
                code.append(f"{ind}result.operands.clear();  // MOVA/MOVAZ/ZERO ZA tile access")
                # Compute group size for register list
                _suffix_num = int(_mova_m.group(4)) if _mova_m.group(4) else 1
                if _is_mz2 or _is_za2:
                    _grp_sz = 2
                elif _is_mz4 or _is_za4:
                    _grp_sz = 4
                elif _is_mz_za:
                    # mz_za2 or mz_za4 — extract from prefix
                    if '4' in _prefix: _grp_sz = 4
                    elif '2' in _prefix: _grp_sz = 2
                    else: _grp_sz = 1
                else:
                    _grp_sz = _suffix_num  # from encoding name suffix

                # Compute tile number
                _tile_expr = '0'
                if _tile_field:
                    _tile_expr = f"enc.{member_name}.{_tile_field}"

                # Compute Ws (Rs + 12 or Rv + 8)
                _ws_base = 12 if _has_Rs else 8
                _ws_expr = f"enc.{member_name}.{_rs_field} + {_ws_base}"

                # Compute offset range
                _off_cpp = f"enc.{member_name}.{_off_field}" if _off_field else '0u'
                if _grp_sz == 2:
                    _start_expr = f"({_off_cpp} * 2)"
                    _end_expr = f"({_off_cpp} * 2 + 1)"
                elif _grp_sz == 4:
                    _start_expr = f"({_off_cpp} * 4)"
                    _end_expr = f"({_off_cpp} * 4 + 3)"
                else:
                    _start_expr = _off_cpp
                    _end_expr = _off_cpp

                # Emit Z register operand(s) first (for ZA→Z direction)
                if _is_za_to_z and not _is_z_rza:
                    if _zd_field:
                        _zd_mul = _grp_sz if _grp_sz > 1 else 1
                        _zd_expr = f"enc.{member_name}.{_zd_field}{f' * {_zd_mul}' if _zd_mul > 1 else ''}"
                        code.append(f"{ind}{{ Operand op(OperandType::SVERegisterList, {_zd_expr}, true); op.arrangement = {_arr_str}; op.index = {_grp_sz}; result.operands.push_back(op); }}")
                elif _is_z_rza:
                    if _zd_field:
                        code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{_zd_field}, true); op.arrangement = {_arr_str}; result.operands.push_back(op); }}")

                # Emit ZA tile access operand (extend=4 for MOVA-style)
                if _has_V:
                    _v_expr = f"enc.{member_name}.{field_map['V']['name']}"
                    code.append(f"{ind}{{")
                    code.append(f"{ind}    Operand op(OperandType::SMETileRegister, {_tile_expr}, false);")
                    code.append(f"{ind}    op.is_sp = ({_v_expr} != 0);  // V=1 → vertical")
                    code.append(f"{ind}    op.arrangement = {_arr_str};")
                    code.append(f"{ind}    op.has_index = true;")
                    code.append(f"{ind}    op.index = {_ws_expr};")
                    code.append(f"{ind}    op.amount = {_start_expr};")
                    code.append(f"{ind}    op.offset = {_end_expr};")
                    code.append(f"{ind}    op.extend = 4;")
                    code.append(f"{ind}    result.operands.push_back(op);")
                    code.append(f"{ind}}}")
                elif (_is_z_to_za or '_ri' in _prefix) and _grp_sz > 1 and not _is_za1:
                    # No V field, range + VGx — extend=3: za.T[wN, start:end, vgxN]
                    code.append(f"{ind}{{")
                    code.append(f"{ind}    Operand op(OperandType::SMETileRegister, 0, false);")
                    code.append(f"{ind}    op.arrangement = {_arr_str};")
                    code.append(f"{ind}    op.has_index = true;")
                    code.append(f"{ind}    op.extend = 3;  // range + VGx mode")
                    code.append(f"{ind}    op.index = {_ws_expr};")
                    code.append(f"{ind}    op.amount = {_start_expr};")
                    code.append(f"{ind}    op.offset = ({_grp_sz} << 16) | (uint32_t)({_end_expr});  // VGx in high 16, range_end in low 16")
                    code.append(f"{ind}    result.operands.push_back(op);")
                    code.append(f"{ind}}}")
                else:
                    # No V field, no range — VGx mode za.T[wN, offs, vgxN]
                    code.append(f"{ind}{{")
                    code.append(f"{ind}    Operand op(OperandType::SMETileRegister, 0, false);")
                    code.append(f"{ind}    op.arrangement = {_arr_str};")
                    code.append(f"{ind}    op.has_index = true;")
                    code.append(f"{ind}    op.extend = 2;  // VGx mode")
                    code.append(f"{ind}    op.index = {_ws_expr};")
                    code.append(f"{ind}    op.amount = {_off_cpp};  // raw offset (not scaled)")
                    code.append(f"{ind}    op.offset = {_grp_sz};  // VGx count")
                    code.append(f"{ind}    result.operands.push_back(op);")
                    code.append(f"{ind}}}")

                # Emit Z register operand(s) after ZA (for Z→ZA direction)
                if _is_z_to_za:
                    _zn = _zn_field or _zd_field
                    if _zn:
                        _zn_mul = _grp_sz if _grp_sz > 1 else 1
                        _zn_expr = f"enc.{member_name}.{_zn}{f' * {_zn_mul}' if _zn_mul > 1 else ''}"
                        code.append(f"{ind}{{ Operand op(OperandType::SVERegisterList, {_zn_expr}, true); op.arrangement = {_arr_str}; op.index = {_grp_sz}; result.operands.push_back(op); }}")

                code.append(f"{ind}return result;")
                return code

        # ZERO { ZT0 }: emit SMEZTRegister
        if mnemonic == 'ZERO' and encoding_name == 'zero_zt_i_':
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::SMEZTRegister, 0u, true));")
            code.append(f"{ind}return result;")
            return code

        # LDR/STR ZA: ldr/str za[w<12+Rv>, off4], [Xn]
        if mnemonic in ('LDR', 'STR') and encoding_name in ('ldr_za_ri_', 'str_za_ri_'):
            rv_f = field_map.get('Rv', {}).get('name', 'Rv')
            rn_f = field_map.get('Rn', {}).get('name', 'Rn')
            off_f = field_map.get('off4', {}).get('name', 'off4')
            code.append(f"{ind}result.operands.clear();")
            code.append(f"{ind}{{")
            code.append(f"{ind}    Operand op(OperandType::SMETileRegister, 0u, false);")
            code.append(f"{ind}    op.has_index = true;")
            code.append(f"{ind}    op.extend = 5;  // LDR/STR ZA format")
            code.append(f"{ind}    op.index = enc.{member_name}.{rv_f} + 12;")
            code.append(f"{ind}    op.amount = enc.{member_name}.{off_f};")
            code.append(f"{ind}    result.operands.push_back(op);")
            code.append(f"{ind}}}")
            code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_f}));")
            code.append(f"{ind}return result;")
            return code

        # MOVT: movt Xt, zt0[off3] / movt zt0[off3], Xt
        if mnemonic == 'MOVT' and encoding_name in ('movt_r_zt_', 'movt_zt_r_'):
            rt_f = field_map.get('Rt', {}).get('name', 'Rt')
            off_f = field_map.get('off3', {}).get('name', 'off3')
            code.append(f"{ind}result.operands.clear();")
            if encoding_name == 'movt_r_zt_':
                # movt Xt, zt0[off3]
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_f}, true));")
                code.append(f"{ind}{{ Operand op(OperandType::SMEZTRegister, 0u, true); op.has_index = true; op.index = enc.{member_name}.{off_f}; result.operands.push_back(op); }}")
            else:
                # movt zt0[off3], Xt
                code.append(f"{ind}{{ Operand op(OperandType::SMEZTRegister, 0u, true); op.has_index = true; op.index = enc.{member_name}.{off_f}; result.operands.push_back(op); }}")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_f}, true));")
            code.append(f"{ind}return result;")
            return code

        # SYS: sys #op1, cCRn, cCRm, #op2, Xt
        if mnemonic == 'SYS' and encoding_name == 'sys_cr_systeminstrs':
            code.append(f"{ind}result.operands.clear();")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.op1, false));")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.CRn, false));")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.CRm, false));")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.op2, false));")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.Rt, true));")
            code.append(f"{ind}return result;")
            return code

        # SYSL: sysl Xt, #op1, cCRn, cCRm, #op2
        if mnemonic == 'SYSL' and encoding_name == 'sysl_rc_systeminstrs':
            code.append(f"{ind}result.operands.clear();")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.Rt, true));")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.op1, false));")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.CRn, false));")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.CRm, false));")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.op2, false));")
            code.append(f"{ind}return result;")
            return code

        # LDR/STR ZT: ldr/str zt0, [Xn]
        if mnemonic in ('LDR', 'STR') and encoding_name in ('ldr_zt_br_', 'str_zt_br_'):
            rn_f = field_map.get('Rn', {}).get('name', 'Rn')
            code.append(f"{ind}result.operands.clear();")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::SMEZTRegister, 0u, true));")
            code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_f}));")
            code.append(f"{ind}return result;")
            return code

        # ZERO { mask }: emit ZA tile mask as list of ZA tiles
        if mnemonic == 'ZERO' and encoding_name == 'zero_za_i_':
            # The imm8 field is a bitmask of which ZA tiles to zero
            imm_field = None
            for fn in ('imm8', 'imm', 'opc'):
                if fn in field_map and not field_map[fn]['is_fixed']:
                    imm_field = field_map[fn]['name']
                    break
            if imm_field:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{imm_field}, true));")
            code.append(f"{ind}return result;")
            return code

        # PMOV: Z register with optional index (NOT a register list)
        if mnemonic == 'PMOV' and encoding_name.startswith('pmov_'):
            is_z_to_p = 'pmov_p_zi' in encoding_name
            arr_map = {'b': 'Arrangement::B', 'h': 'Arrangement::H', 's': 'Arrangement::S', 'd': 'Arrangement::D'}
            suffix = encoding_name.rsplit('_', 1)[-1]
            arr = arr_map.get(suffix, 'Arrangement::None')
            # Build index from split i3h:i3l / i2h:i2l / i2 / i1
            def _pmov_idx_expr():
                for hi, lo, lo_w in [('i3h', 'i3l', 2), ('i2h', 'i2l', 1)]:
                    if hi in field_map and not field_map[hi]['is_fixed'] and lo in field_map and not field_map[lo]['is_fixed']:
                        return f"(enc.{member_name}.{hi} << {lo_w}) | enc.{member_name}.{lo}"
                for iname in ['i2', 'i1']:
                    if iname in field_map and not field_map[iname]['is_fixed']:
                        return f"enc.{member_name}.{iname}"
                return None
            idx = _pmov_idx_expr()
            code.append(f"{ind}result.operands.clear();  // PMOV special case")
            if is_z_to_p and 'Pd' in field_map and 'Zn' in field_map:
                code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{field_map['Pd']['name']}, true); op.arrangement = {arr}; result.operands.push_back(op); }}")
                if idx:
                    code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{field_map['Zn']['name']}, true); op.has_index = true; op.index = {idx}; result.operands.push_back(op); }}")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::SVERegister, enc.{member_name}.{field_map['Zn']['name']}, true));")
            elif not is_z_to_p and 'Zd' in field_map and 'Pn' in field_map:
                if idx:
                    code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{field_map['Zd']['name']}, true); op.has_index = true; op.index = {idx}; result.operands.push_back(op); }}")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::SVERegister, enc.{member_name}.{field_map['Zd']['name']}, true));")
                code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{field_map['Pn']['name']}, true); op.arrangement = {arr}; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # CNTP pn form: <Xd>, <PNn>.<T>, <vl>
        if encoding_name == 'cntp_r_pn_' and 'PNn' in field_map and 'Rd' in field_map:
            rd_cpp = field_map['Rd']['name']
            pnn_cpp = field_map['PNn']['name']
            pnn_width = field_map['PNn'].get('width', 4)
            # PNn is 4-bit (0-15) → direct mapping; 3-bit (0-7) → needs |8u offset
            pnn_offset = '| 8u' if pnn_width <= 3 else ''
            vl_cpp = field_map['vl']['name'] if 'vl' in field_map and not field_map['vl']['is_fixed'] else None
            size_cpp = field_map['size']['name'] if 'size' in field_map and not field_map['size']['is_fixed'] else None
            code.append(f"{ind}result.operands.clear();  // CNTP pn special case")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_cpp}, true));")
            if size_cpp:
                code.append(f"{ind}Arrangement _sve_arr = Arrangement::None;")
                code.append(f"{ind}switch (enc.{member_name}.{size_cpp}) {{")
                code.append(f"{ind}    case 0: _sve_arr = Arrangement::B; break; case 1: _sve_arr = Arrangement::H; break;")
                code.append(f"{ind}    case 2: _sve_arr = Arrangement::S; break; case 3: _sve_arr = Arrangement::D; break;")
                code.append(f"{ind}}}")
                code.append(f"{ind}{{ Operand op(OperandType::PredicateNRegister, enc.{member_name}.{pnn_cpp} {pnn_offset}, true); op.arrangement = _sve_arr; result.operands.push_back(op); }}")
            else:
                code.append(f"{ind}{{ Operand op(OperandType::PredicateNRegister, enc.{member_name}.{pnn_cpp} {pnn_offset}, true); result.operands.push_back(op); }}")
            if vl_cpp:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::SVEVLxImm, enc.{member_name}.{vl_cpp} ? 4u : 2u, true));")
            code.append(f"{ind}return result;")
            return code

        # WHILE* pn_rr forms: <PNd>.<T>, <Xn>, <Xm>, <vl>
        # (whilele_pn_rr_, whilehs_pn_rr_, whilehi_pn_rr_, whilelo_pn_rr_, whilelt_pn_rr_, whilege_pn_rr_)
        _while_pn_rr_encs = {'whilele_pn_rr_', 'whilehs_pn_rr_', 'whilehi_pn_rr_', 'whilelo_pn_rr_', 'whilelt_pn_rr_', 'whilege_pn_rr_', 'whilegt_pn_rr_', 'whilels_pn_rr_'}
        if encoding_name in _while_pn_rr_encs and 'PNd' in field_map and 'Rn' in field_map and 'Rm' in field_map:
            pnd_cpp = field_map['PNd']['name']
            rn_cpp = field_map['Rn']['name']
            rm_cpp = field_map['Rm']['name']
            vl_cpp = field_map['vl']['name'] if 'vl' in field_map and not field_map['vl']['is_fixed'] else None
            size_cpp = field_map['size']['name'] if 'size' in field_map and not field_map['size']['is_fixed'] else None
            if size_cpp:
                code.append(f"{ind}result.operands.clear();  // WHILE pn_rr special case")
                code.append(f"{ind}Arrangement _sve_arr = Arrangement::None;")
                code.append(f"{ind}switch (enc.{member_name}.{size_cpp}) {{")
                code.append(f"{ind}    case 0: _sve_arr = Arrangement::B; break; case 1: _sve_arr = Arrangement::H; break;")
                code.append(f"{ind}    case 2: _sve_arr = Arrangement::S; break; case 3: _sve_arr = Arrangement::D; break;")
                code.append(f"{ind}}}")
                code.append(f"{ind}{{ Operand op(OperandType::PredicateNRegister, enc.{member_name}.{pnd_cpp} | 8u, true); op.arrangement = _sve_arr; result.operands.push_back(op); }}")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rn_cpp}, true));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rm_cpp}, true));")
                if vl_cpp:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::SVEVLxImm, enc.{member_name}.{vl_cpp} ? 4u : 2u, true));")
                code.append(f"{ind}return result;")
                return code

        # WHILE* pp_rr forms: { <Pd1>.<T>, <Pd2>.<T> }, <Xn>, <Xm>
        # (whilele_pp_rr_, whilehs_pp_rr_, whilehi_pp_rr_, whilelo_pp_rr_, whilelt_pp_rr_, whilege_pp_rr_)
        _while_pp_rr_encs = {'whilele_pp_rr_', 'whilehs_pp_rr_', 'whilehi_pp_rr_', 'whilelo_pp_rr_', 'whilelt_pp_rr_', 'whilege_pp_rr_', 'whilegt_pp_rr_', 'whilels_pp_rr_'}
        if encoding_name in _while_pp_rr_encs and 'Pd' in field_map and 'Rn' in field_map and 'Rm' in field_map:
            pd_cpp = field_map['Pd']['name']
            rn_cpp = field_map['Rn']['name']
            rm_cpp = field_map['Rm']['name']
            size_cpp = field_map['size']['name'] if 'size' in field_map and not field_map['size']['is_fixed'] else None
            if size_cpp:
                code.append(f"{ind}result.operands.clear();  // WHILE pp_rr special case")
                code.append(f"{ind}Arrangement _sve_arr = Arrangement::None;")
                code.append(f"{ind}switch (enc.{member_name}.{size_cpp}) {{")
                code.append(f"{ind}    case 0: _sve_arr = Arrangement::B; break; case 1: _sve_arr = Arrangement::H; break;")
                code.append(f"{ind}    case 2: _sve_arr = Arrangement::S; break; case 3: _sve_arr = Arrangement::D; break;")
                code.append(f"{ind}}}")
                code.append(f"{ind}uint32_t _pd1 = enc.{member_name}.{pd_cpp} * 2;  // 3-bit field encodes pair index")
                code.append(f"{ind}{{ Operand op(OperandType::PredicateRegisterList, _pd1, true); op.arrangement = _sve_arr; op.index = 2; result.operands.push_back(op); }}")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rn_cpp}, true));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rm_cpp}, true));")
                code.append(f"{ind}return result;")
                return code

        # Special case: SQCVT/UQCVT/SQCVTN/UQCVTN/SQCVTU/SQCVTUN multi-vector narrowing
        # dest <Zd>.<T> is 2-steps narrow, source { <Zn>.<Tb> } is the standard arrangement
        _cvt_narrow_mnemonics = {'SQCVT', 'UQCVT', 'SQCVTN', 'UQCVTN', 'SQCVTU', 'SQCVTUN'}
        if mnemonic in _cvt_narrow_mnemonics and '_z_mz' in encoding_name and 'Zd' in field_map and 'Zn' in field_map:
            zd_f = field_map['Zd']['name']
            zn_f = field_map['Zn']['name']
            # sz field: 0→{B dest, S src}, 1→{H dest, D src}
            sz_f = field_map['sz']['name'] if 'sz' in field_map and not field_map['sz']['is_fixed'] else None
            # Determine list count from encoding name
            _list_count = 4 if '_mz4' in encoding_name else 2
            _zn_mul = _list_count  # Zn field multiplied by list count
            if sz_f:
                code.append(f"{ind}Arrangement _dst_arr = enc.{member_name}.{sz_f} ? Arrangement::H : Arrangement::B;")
                code.append(f"{ind}Arrangement _src_arr = enc.{member_name}.{sz_f} ? Arrangement::D : Arrangement::S;")
            else:
                sz_val = int(field_map['sz']['fixed'], 2) if 'sz' in field_map and field_map['sz']['fixed'] else 0
                _dst_arr = 'Arrangement::H' if sz_val else 'Arrangement::B'
                _src_arr = 'Arrangement::D' if sz_val else 'Arrangement::S'
                code.append(f"{ind}Arrangement _dst_arr = {_dst_arr};")
                code.append(f"{ind}Arrangement _src_arr = {_src_arr};")
            code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{zd_f}, true); op.arrangement = _dst_arr; result.operands.push_back(op); }}")
            code.append(f"{ind}{{ Operand op(OperandType::SVERegisterList, enc.{member_name}.{zn_f} * {_zn_mul}u, true); op.arrangement = _src_arr; op.index = {_list_count}; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        if (has_sve_regs or has_pred_regs) and template_ops:
            # Use template-based ordering for SVE/SME instructions
            has_sve_size = False
            sve_size_field = None
            has_tsz_size = False
            for sz_name in ['size', 'sz']:
                if sz_name in field_map and not field_map[sz_name]['is_fixed']:
                    has_sve_size = True
                    sve_size_field = field_map[sz_name]['name']
                    break

            # Check for tszh:tszl encoding (SVE shift-by-immediate instructions)
            if not has_sve_size and 'tszh' in field_map and 'tszl' in field_map and not field_map['tszh']['is_fixed'] and not field_map['tszl']['is_fixed']:
                has_tsz_size = True
                tszh_name = field_map['tszh']['name']
                tszl_name = field_map['tszl']['name']
                tszl_width = field_map['tszl'].get('width', 2)
                imm3_name = field_map['imm3']['name'] if 'imm3' in field_map and not field_map['imm3']['is_fixed'] else None

            # Check if any template operand uses Tb (narrower arrangement)
            needs_narrow = any(top.get('arrangement') == 'Tb' for top in template_ops)
            # Narrowing instructions: destination T = narrow (half-width), source Tb = wide
            # Examples: ADDHNB/T, RADDHNB/T, SUBHNB/T, RSUBHNB/T, SHRN*, RSHRN*, SQSHRN*, UQSHRN*
            # For these, T and Tb roles are swapped vs widening instructions
            _mn_up = mnemonic.upper()
            is_narrowing = (needs_narrow and (
                _mn_up.endswith('HNB') or _mn_up.endswith('HNT') or
                'SHRN' in _mn_up
            ))

            if has_tsz_size:
                # Arrangement from tszh:tszl highest set bit
                code.append(f'{ind}uint32_t _tsize = (enc.{member_name}.{tszh_name} << {tszl_width}) | enc.{member_name}.{tszl_name};')
                code.append(f'{ind}Arrangement _sve_arr = Arrangement::None;')
                code.append(f'{ind}uint32_t _esize = 0;')
                code.append(f'{ind}if (_tsize & 8) {{ _sve_arr = Arrangement::D; _esize = 64; }}')
                code.append(f'{ind}else if (_tsize & 4) {{ _sve_arr = Arrangement::S; _esize = 32; }}')
                code.append(f'{ind}else if (_tsize & 2) {{ _sve_arr = Arrangement::H; _esize = 16; }}')
                code.append(f'{ind}else if (_tsize & 1) {{ _sve_arr = Arrangement::B; _esize = 8; }}')
                if imm3_name:
                    code.append(f'{ind}uint32_t _tsz_imm = (_tsize << 3) | enc.{member_name}.{imm3_name};')
                    code.append(f'{ind}uint32_t _shift_right = (2 * _esize) - _tsz_imm;')
                    code.append(f'{ind}uint32_t _shift_left = _tsz_imm - _esize;')
                has_sve_size = True  # So arr_expr uses _sve_arr
                if needs_narrow:
                    # For tszh:tszl, <Tb> means one step WIDER than <T> (opposite of size-based)
                    code.append(f'{ind}Arrangement _sve_arr_narrow = Arrangement::None;')
                    code.append(f'{ind}if (_tsize & 4) {{ _sve_arr_narrow = Arrangement::D; }}')
                    code.append(f'{ind}else if (_tsize & 2) {{ _sve_arr_narrow = Arrangement::S; }}')
                    code.append(f'{ind}else if (_tsize & 1) {{ _sve_arr_narrow = Arrangement::H; }}')

            elif has_sve_size:
                sz_width = field_map[list(filter(lambda n: n in field_map and not field_map[n]['is_fixed'], ['size', 'sz']))[0]].get('width', 1)
                if sz_width == 2:
                    code.append(f'{ind}Arrangement _sve_arr = Arrangement::None;')
                    code.append(f'{ind}switch (enc.{member_name}.{sve_size_field}) {{')
                    code.append(f'{ind}    case 0: _sve_arr = Arrangement::B; break;')
                    code.append(f'{ind}    case 1: _sve_arr = Arrangement::H; break;')
                    code.append(f'{ind}    case 2: _sve_arr = Arrangement::S; break;')
                    code.append(f'{ind}    case 3: _sve_arr = Arrangement::D; break;')
                    code.append(f'{ind}}}')
                    if needs_narrow:
                        # Check if this is a dot product instruction (2-step narrow: Tb uses size[0])
                        is_dot_narrow = mnemonic.upper() in ('SDOT', 'UDOT', 'USDOT', 'SUDOT')
                        if is_dot_narrow and sz_width == 2:
                            # Dot product Tb: size[0] → {0: B, 1: H}
                            code.append(f'{ind}Arrangement _sve_arr_narrow = (enc.{member_name}.{sve_size_field} & 1) ? Arrangement::H : Arrangement::B;')
                        else:
                            code.append(f'{ind}// Narrow arrangement: one step smaller than _sve_arr')
                            code.append(f'{ind}Arrangement _sve_arr_narrow = Arrangement::None;')
                            code.append(f'{ind}switch (enc.{member_name}.{sve_size_field}) {{')
                            code.append(f'{ind}    case 1: _sve_arr_narrow = Arrangement::B; break;')
                            code.append(f'{ind}    case 2: _sve_arr_narrow = Arrangement::H; break;')
                            code.append(f'{ind}    case 3: _sve_arr_narrow = Arrangement::S; break;')
                            code.append(f'{ind}}}')
                elif sz_width == 1:
                    code.append(f'{ind}Arrangement _sve_arr = enc.{member_name}.{sve_size_field} ? Arrangement::D : Arrangement::S;')
                    if needs_narrow:
                        code.append(f'{ind}Arrangement _sve_arr_narrow = enc.{member_name}.{sve_size_field} ? Arrangement::S : Arrangement::H;')

            # QV reductions: full 128-bit vector arrangement for dest
            _is_qv_mnemonic = mnemonic.upper().endswith('QV')
            if _is_qv_mnemonic and has_sve_size and sve_size_field:
                code.append(f'{ind}static const Arrangement _qv_arr_tbl[] = {{Arrangement::B16, Arrangement::H8, Arrangement::S4, Arrangement::D2}};')
                code.append(f'{ind}Arrangement _qv_arr = _qv_arr_tbl[enc.{member_name}.{sve_size_field} & 3];')

            # Emit SVE/predicate operands in template order
            emitted_fields = set()
            _simd_v_emitted = emitted_fields  # shared reference so fallback can check
            # Count how many times each field appears in template (for destructive ops like NBSL)
            from collections import Counter
            field_template_count = Counter(top['field'] for top in template_ops)
            field_emit_count = Counter()
            # Pre-scan for register lists: { Zn1.B, Zn2.B } → SVERegisterList
            # Collect list groups (consecutive is_list ops mapping to same base field)
            # Track distinct register numbers and separate occurrences for destructive ops
            list_groups = {}  # base_field → list of template indices (first occurrence only)
            _list_reg_nums = {}  # base_field → set of register numbers (e.g. {1, 2})
            _list_total_count = {}  # base_field → total appearances in template
            for i, top in enumerate(template_ops):
                if top.get('is_list'):
                    field = top['field']
                    import re as _re
                    base_match = _re.match(r'^(Z\w+?)(\d+)$', field)
                    if base_match:
                        base = base_match.group(1)
                        reg_num = int(base_match.group(2))
                        if base not in _list_reg_nums:
                            _list_reg_nums[base] = set()
                            list_groups[base] = []
                            _list_total_count[base] = 0
                        _list_total_count[base] += 1
                        if reg_num not in _list_reg_nums[base]:
                            _list_reg_nums[base].add(reg_num)
                            list_groups[base].append(i)
            # For destructive ops (_mz_ etc.), the list appears multiple times in template
            # _list_repeat_count: how many times the list should be emitted
            _list_repeat_count = {}
            for base, nums in _list_reg_nums.items():
                total = _list_total_count[base]
                distinct = len(nums)
                _list_repeat_count[base] = total // distinct if distinct > 0 else 1
            # Fields that are part of a list group (will be emitted as SVERegisterList)
            list_emitted = {}  # base → emit count so far

            for top_idx, top in enumerate(template_ops):
                field = top['field']
                arr = top.get('arrangement')
                qual = top.get('qualifier')
                field_emit_count[field] += 1
                # Skip if field already emitted its expected number of times
                if field_emit_count[field] > field_template_count[field]:
                    continue

                # Handle literal ZT0 register operand (SME lookup table)
                if top.get('type') == 'zt0':
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::SMEZTRegister, 0u, true));")
                    continue

                # Check if this is part of a register list group
                import re as _re
                base_match = _re.match(r'^(Z\w+?)(\d+)$', field)
                if base_match and base_match.group(1) in list_groups:
                    base = base_match.group(1)
                    group_indices = list_groups[base]
                    _emit_times = list_emitted.get(base, 0)
                    _max_emits = _list_repeat_count.get(base, 1)
                    if _emit_times >= _max_emits:
                        continue  # Already emitted all occurrences
                    # Only emit on first element of each group occurrence
                    reg_num = int(base_match.group(2))
                    if reg_num != min(_list_reg_nums.get(base, {1})):
                        continue  # Skip non-first elements of list
                    # Emit as SVERegisterList
                    list_emitted[base] = _emit_times + 1
                    # Count: use range (max-min+1) for contiguous ranges like Zdn1-Zdn4
                    _nums = _list_reg_nums.get(base, set())
                    count = max(_nums) - min(_nums) + 1 if _nums else 1
                    if base in field_map and not field_map[base]['is_fixed']:
                        field_cpp_name = field_map[base]['name']
                    else:
                        if base not in field_map:
                            continue
                        field_cpp_name = field_map[base]['name']
                    if arr and arr not in ('T', 'Tb', 'Ts'):
                        arr_expr = _STR_TO_ARR.get(arr, 'Arrangement::None')
                    elif has_sve_size:
                        arr_expr = '_sve_arr'
                    else:
                        arr_expr = 'Arrangement::None'
                    import math as _math
                    _field_width = field_map[base].get('width', 5) if base in field_map else 5
                    _is_pow2_count = count > 1 and (count & (count - 1)) == 0
                    _is_strided = '_mzx_' in encoding_name.lower()
                    # Also detect LUTI mz2/mz4 stride from encoding name suffix
                    import re as _re_luti_stride
                    _luti_stride_m = _re_luti_stride.search(r'_mz(\d+)_\w+_(\d+)$', encoding_name.lower())
                    stride_val = 1
                    if _luti_stride_m and not _is_strided:
                        _luti_count = int(_luti_stride_m.group(1))
                        _luti_stride = int(_luti_stride_m.group(2))
                        if _luti_count == count and _luti_stride > 1:
                            stride_val = _luti_stride
                    if _is_strided and _is_pow2_count:
                        import re as _re_stride
                        _stride_match = _re_stride.search(r'(\d+)x(\d+)', encoding_name.lower())
                        if _stride_match:
                            _nreg = int(_stride_match.group(1))
                            stride_val = int(_stride_match.group(2))
                            _shift_bits = int(_math.log2(stride_val)) if stride_val > 1 else 0
                            if 'T' in field_map and not field_map['T']['is_fixed']:
                                t_cpp = field_map['T']['name']
                                reg_expr = f"(enc.{member_name}.{t_cpp} << 4) | enc.{member_name}.{field_cpp_name}"
                            else:
                                reg_expr = f"enc.{member_name}.{field_cpp_name}"
                        else:
                            reg_expr = f"enc.{member_name}.{field_cpp_name}"
                    elif _field_width < 5 and _is_pow2_count:
                        _log2_count = int(_math.log2(count))
                        if _field_width + _log2_count == 5:
                            reg_expr = f"enc.{member_name}.{field_cpp_name} * {count}"
                        else:
                            reg_expr = f"enc.{member_name}.{field_cpp_name}"
                    else:
                        reg_expr = f"enc.{member_name}.{field_cpp_name}"
                    if stride_val > 1:
                        code.append(f"{ind}{{ Operand op(OperandType::SVERegisterList, {reg_expr}, true); op.arrangement = {arr_expr}; op.index = {count}; op.offset = {stride_val}; result.operands.push_back(op); }}")
                    else:
                        code.append(f"{ind}{{ Operand op(OperandType::SVERegisterList, {reg_expr}, true); op.arrangement = {arr_expr}; op.index = {count}; result.operands.push_back(op); }}")
                    emitted_fields.add(base)
                    continue

                # --- Handle SIMD scalar register names (Dd, Sd, Qd etc.) from SVE reduction templates ---
                # Templates like SADDV <Dd>, <Pg>, <Zn>.<T> use Dd/Sd/Qd which map to Vd in field_map
                _simd_scalar_map = {
                    'Dd': ('Vd', 'Arrangement::D'), 'Sd': ('Vd', 'Arrangement::S'), 'Qd': ('Vd', 'Arrangement::Q'), 'Hd': ('Vd', 'Arrangement::H'), 'Bd': ('Vd', 'Arrangement::B'),
                    'Dn': ('Vn', 'Arrangement::D'), 'Sn': ('Vn', 'Arrangement::S'), 'Qn': ('Vn', 'Arrangement::Q'), 'Hn': ('Vn', 'Arrangement::H'), 'Bn': ('Vn', 'Arrangement::B'),
                    'Dm': ('Vm', 'Arrangement::D'), 'Sm': ('Vm', 'Arrangement::S'), 'Qm': ('Vm', 'Arrangement::Q'), 'Hm': ('Vm', 'Arrangement::H'), 'Bm': ('Vm', 'Arrangement::B'),
                }
                if field in _simd_scalar_map:
                    actual_field, scalar_arr = _simd_scalar_map[field]
                    if actual_field in field_map and not field_map[actual_field]['is_fixed'] and actual_field not in emitted_fields:
                        actual_cpp = field_map[actual_field]['name']
                        # Use false for is_64bit so format_vector_register uses arrangement-based prefix (d/s/etc.)
                        code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{actual_cpp}, false); op.arrangement = {scalar_arr}; result.operands.push_back(op); }}")
                        emitted_fields.add(actual_field)
                    continue

                # --- Handle size-dependent scalar <V><d> / <V><n> / <V><m> from merged template ---
                # Template <V><d> → field='Vd', arrangement depends on size field (_sve_arr)
                _v_scalar_map = {'Vd': 'Vd', 'Vn': 'Vn', 'Vm': 'Vm', 'Vdn': 'Vdn', 'Vda': 'Vda', 'Vt': 'Vt'}
                if field in _v_scalar_map:
                    actual_field = _v_scalar_map[field]
                    if actual_field in field_map and not field_map[actual_field]['is_fixed'] and actual_field not in emitted_fields:
                        actual_cpp = field_map[actual_field]['name']
                        # QV reductions: dest is full 128-bit vector (B16/H8/S4/D2) not scalar
                        if _is_qv_mnemonic and has_sve_size and sve_size_field:
                            arr_expr = '_qv_arr'
                        else:
                            arr_expr = '_sve_arr' if has_sve_size else 'Arrangement::None'
                        code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{actual_cpp}, false); op.arrangement = {arr_expr}; result.operands.push_back(op); }}")
                        emitted_fields.add(actual_field)
                    continue

                # --- Handle GP register inside simple memory bracket [Xn{, #imm}] ---
                # This covers SVE LD/ST contiguous (_z_p_bi_) and replicate (_z_p_ri_) patterns.
                if top.get('in_mem_bracket') and not top.get('complex_mem') and field in ('Xn', 'Xt', 'XnSP') or (
                        top.get('in_mem_bracket') and not top.get('complex_mem') and field.startswith('X') and field not in sve_z_names):
                    rn_key = 'Rn' if 'Rn' in field_map and not field_map['Rn']['is_fixed'] else \
                             ('Rt' if 'Rt' in field_map and not field_map['Rt']['is_fixed'] else None)
                    if rn_key:
                        rn_field_cpp = field_map[rn_key]['name']
                        mem_imm = top.get('mem_imm_field')
                        is_mul_vl = top.get('mul_vl', False)
                        # Resolve template imm name to actual field_map key
                        # (e.g. template uses '<imm>' but field_map has 'imm4', 'imm6', etc.)
                        if mem_imm and mem_imm not in field_map:
                            for _k in field_map:
                                if _k.startswith('imm') and not field_map[_k]['is_fixed']:
                                    mem_imm = _k
                                    break
                        if mem_imm and mem_imm in field_map and not field_map[mem_imm]['is_fixed']:
                            imm_field_cpp = field_map[mem_imm]['name']
                            if is_mul_vl:
                                import re as _re2
                                # num_struct = number of registers in the list group (for MUL VL scaling)
                                # Fall back to mnemonic digit for ld2/st3 etc. structure loads
                                _nreg_from_groups = max((len(v) for v in list_groups.values()), default=0) if list_groups else 0
                                if _nreg_from_groups > 1:
                                    num_struct = _nreg_from_groups
                                else:
                                    ns_match = _re2.match(r'^(?:ld|st|ldff|stnt|ldnf)(\d)', mnemonic.lower())
                                    num_struct = int(ns_match.group(1)) if ns_match else 1
                                # Check for split imm9h+imm9l (SVE predicate/vector LDR/STR)
                                if ('imm9h' in field_map and not field_map['imm9h']['is_fixed'] and
                                        'imm9l' in field_map and not field_map['imm9l']['is_fixed']):
                                    imm9h_f = field_map['imm9h']['name']
                                    imm9l_f = field_map['imm9l']['name']
                                    imm9l_w = field_map['imm9l']['width']
                                    total_bits = field_map['imm9h']['width'] + imm9l_w
                                    code.append(f"{ind}{{")
                                    code.append(f"{ind}    uint32_t _raw9 = (enc.{member_name}.{imm9h_f} << {imm9l_w}) | enc.{member_name}.{imm9l_f};")
                                    code.append(f"{ind}    int32_t _imm = static_cast<int32_t>(_raw9 << {32-total_bits}) >> {32-total_bits};")
                                    code.append(f"{ind}    _imm *= {num_struct};")
                                    code.append(f"{ind}    if (_imm == 0) result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field_cpp}));")
                                    code.append(f"{ind}    else result.operands.push_back(Operand(OperandType::MemoryOffsetMulVL, enc.{member_name}.{rn_field_cpp}, _imm));")
                                    code.append(f"{ind}}}")
                                    consumed_imm_fields.add('imm9h')
                                    consumed_imm_fields.add('imm9l')
                                else:
                                    imm_bits = field_map[mem_imm].get('width', 4)
                                    code.append(f"{ind}{{")
                                    code.append(f"{ind}    int32_t _imm = static_cast<int32_t>(enc.{member_name}.{imm_field_cpp} << {32-imm_bits}) >> {32-imm_bits};")
                                    code.append(f"{ind}    _imm *= {num_struct};")
                                    code.append(f"{ind}    if (_imm == 0) result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field_cpp}));")
                                    code.append(f"{ind}    else result.operands.push_back(Operand(OperandType::MemoryOffsetMulVL, enc.{member_name}.{rn_field_cpp}, _imm));")
                                    code.append(f"{ind}}}")
                            else:
                                # Replicate load: scale imm by element size (from mnemonic suffix)
                                # LD1RQ*/LD1RO* use fixed 16/32 byte quadword/octaword scaling
                                _m = mnemonic.upper()
                                if 'LD1RQ' in _m: _esz = 16
                                elif 'LD1RO' in _m: _esz = 32
                                elif _m.endswith('SB'): _esz = 1
                                elif _m.endswith('SH'): _esz = 2
                                elif _m.endswith('SW'): _esz = 4
                                elif _m.endswith('B'): _esz = 1
                                elif _m.endswith('H'): _esz = 2
                                elif _m.endswith('W'): _esz = 4
                                elif _m.endswith('D'): _esz = 8
                                elif _m.endswith('Q'): _esz = 16
                                else: _esz = 1
                                code.append(f"{ind}{{")
                                code.append(f"{ind}    int32_t _imm = (int32_t)enc.{member_name}.{imm_field_cpp} * {_esz};")
                                code.append(f"{ind}    if (_imm == 0) result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field_cpp}));")
                                code.append(f"{ind}    else result.operands.push_back(Operand::memory_offset(enc.{member_name}.{rn_field_cpp}, _imm));")
                                code.append(f"{ind}}}")
                            consumed_imm_fields.add(mem_imm)
                        else:
                            code.append(f"{ind}result.operands.push_back(Operand::memory_base(enc.{member_name}.{rn_field_cpp}));")
                        emitted_fields.add(rn_key)
                    continue

                # --- Handle GP+GP or GP+SVE-Z complex memory bracket ---
                # [Xn, Xm] for prfb/prfh/prfw/prfd, [Xn, Zm.T{, lsl #N}] for SVE gather/scatter
                if (top.get('in_mem_bracket') and top.get('complex_mem') and
                        field.startswith('X') and field not in sve_z_names and field not in sve_p_names):
                    rn_key = ('Rn' if 'Rn' in field_map and not field_map['Rn']['is_fixed'] else
                              ('Rt' if 'Rt' in field_map and not field_map['Rt']['is_fixed'] else None))
                    rm_key = ('Rm' if 'Rm' in field_map and not field_map['Rm']['is_fixed'] else None)
                    if rn_key and rm_key and rn_key not in emitted_fields:
                        # GP+GP bracket: emit memory_reg_offset(Rn, Rm) with 64-bit registers
                        rn_field_cpp = field_map[rn_key]['name']
                        rm_field_cpp = field_map[rm_key]['name']
                        # Check for fixed LSL #N in template (e.g. ST4Q [Xn, Xm, LSL #4])
                        _lsl_m = _re.search(r'\[.*,\s*LSL\s+#(\d+)\]', asm_template, _re.IGNORECASE)
                        _fixed_lsl = int(_lsl_m.group(1)) if _lsl_m else 0
                        # Infer shift from element size for SVE loads/stores if not explicit in template
                        if _fixed_lsl == 0:
                            _mu = mnemonic.upper()
                            if _mu.endswith('D'): _fixed_lsl = 3
                            elif _mu.endswith('W') or _mu.endswith('SW'): _fixed_lsl = 2
                            elif _mu.endswith('H') or _mu.endswith('SH'): _fixed_lsl = 1
                        if _fixed_lsl > 0:
                            code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field_cpp}, enc.{member_name}.{rm_field_cpp}, 3, {_fixed_lsl}));")
                        else:
                            code.append(f"{ind}result.operands.push_back(Operand::memory_reg_offset(enc.{member_name}.{rn_field_cpp}, enc.{member_name}.{rm_field_cpp}));")
                        emitted_fields.add(rn_key)
                        emitted_fields.add(rm_key)
                    elif rn_key and not rm_key and rn_key not in emitted_fields:
                        # GP+SVE-Z bracket: [Xn, Zm.T{, lsl #N}]
                        _zm_key = None
                        _zm_arr_tmpl = None
                        for _t in template_ops:
                            _tf = _t.get('field', '')
                            if (_t.get('in_mem_bracket') and _t.get('complex_mem') and
                                    _tf in sve_z_names and _tf in field_map and
                                    not field_map[_tf]['is_fixed']):
                                _zm_key = _tf
                                _zm_arr_tmpl = _t.get('arrangement')
                                break
                        if _zm_key:
                            rn_field_cpp = field_map[rn_key]['name']
                            zm_field_cpp = field_map[_zm_key]['name']
                            # Determine lsl/extend from encoding name
                            _enc_lower = encoding_name.lower()
                            _lsl = 0
                            _xs_field = None  # 'xs' field: 0=uxtw(2), 1=sxtw(6)
                            _xs_shift = 0
                            if '_64_scaled' in _enc_lower:
                                _m = mnemonic.upper()
                                if _m.endswith('D'): _lsl = 3
                                elif _m.endswith('W') or _m.endswith('SW'): _lsl = 2
                                elif _m.endswith('SH'): _lsl = 1
                                elif _m.endswith('H'): _lsl = 1
                                else: _lsl = 0
                            elif '_x32_scaled' in _enc_lower or '_x32_unscaled' in _enc_lower:
                                # 32-bit index with sxtw/uxtw extend from 'xs' field
                                if 'xs' in field_map and not field_map['xs']['is_fixed']:
                                    _xs_field = field_map['xs']['name']
                                if '_x32_scaled' in _enc_lower:
                                    _m = mnemonic.upper()
                                    if _m.endswith('D'): _xs_shift = 3
                                    elif _m.endswith('W') or _m.endswith('SW'): _xs_shift = 2
                                    elif _m.endswith('SH'): _xs_shift = 1
                                    elif _m.endswith('H'): _xs_shift = 1
                                    else: _xs_shift = 0
                            # Z arrangement in memory bracket
                            if _zm_arr_tmpl and _zm_arr_tmpl not in ('T', 'Tb', 'Ts'):
                                _arr_e = _STR_TO_ARR.get(_zm_arr_tmpl)
                                _zm_arr_cpp = _arr_e if _arr_e else f'"{_zm_arr_tmpl}"'
                            elif has_sve_size:
                                _zm_arr_cpp = '_sve_arr'
                            else:
                                _zm_arr_cpp = 'Arrangement::None'
                            if _xs_field:
                                # xs=0 → uxtw(2), xs=1 → sxtw(6)
                                _ext_expr = f"(enc.{member_name}.{_xs_field} ? 6u : 2u)"
                                if _xs_shift > 0:
                                    code.append(f'{ind}{{ Operand op = Operand::memory_reg_offset(enc.{member_name}.{rn_field_cpp}, enc.{member_name}.{zm_field_cpp}, {_ext_expr}, {_xs_shift}); op.arrangement = {_zm_arr_cpp}; result.operands.push_back(op); }}')
                                else:
                                    code.append(f'{ind}{{ Operand op = Operand::memory_reg_offset(enc.{member_name}.{rn_field_cpp}, enc.{member_name}.{zm_field_cpp}, {_ext_expr}); op.arrangement = {_zm_arr_cpp}; result.operands.push_back(op); }}')
                            elif _lsl > 0:
                                code.append(f'{ind}{{ Operand op = Operand::memory_reg_offset(enc.{member_name}.{rn_field_cpp}, enc.{member_name}.{zm_field_cpp}, 3, {_lsl}); op.arrangement = {_zm_arr_cpp}; result.operands.push_back(op); }}')
                            else:
                                code.append(f'{ind}{{ Operand op = Operand::memory_reg_offset(enc.{member_name}.{rn_field_cpp}, enc.{member_name}.{zm_field_cpp}); op.arrangement = {_zm_arr_cpp}; result.operands.push_back(op); }}')
                            emitted_fields.add(rn_key)
                            emitted_fields.add(_zm_key)
                    continue  # Skip Xm/Zm (already consumed as part of memory operand)

                # --- Handle prfop in template order (SVE prefetch) ---
                if field == 'prfop' and 'prfop' in field_map and not field_map['prfop']['is_fixed']:
                    _prfop_cpp = field_map['prfop']['name']
                    _prfop_width = field_map['prfop'].get('width', 5)
                    if _prfop_width == 4:
                        # 4-bit SVE scatter/gather prfop: bit3=0→PLD, bit3=1→PST (no PLI)
                        # Map to 5-bit table: 0-7→PLD(0-7), 8-15→PST(16-23)
                        _prfop_val = f"(enc.{member_name}.{_prfop_cpp} < 8 ? enc.{member_name}.{_prfop_cpp} : (enc.{member_name}.{_prfop_cpp} & 7u) | 16u)"
                    else:
                        _prfop_val = f"enc.{member_name}.{_prfop_cpp}"
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Prefetch, {_prfop_val}, true));")
                    code.append(f"{ind}result.operands.back().prefetch = prefetch_from_value({_prfop_val});")
                    emitted_fields.add('prfop')
                    emitted_fields_pre.add('prfop')  # Mark for the standalone prfop handler below
                    continue

                # Handle register pair fields: Zn1→Zn, Zn2→Zn+1
                is_pair_second = False
                actual_field = field
                if field not in field_map and field.endswith('1') and field[:-1] in field_map:
                    actual_field = field[:-1]
                elif field not in field_map and field.endswith('2') and field[:-1] in field_map:
                    actual_field = field[:-1]
                    is_pair_second = True

                if actual_field not in field_map or field_map[actual_field]['is_fixed']:
                    # Handle GP register tokens like Xn→Rn (64-bit), Wn→Rn (32-bit) in SVE templates
                    if field in _gp_tok_to_field and not top.get('in_mem_bracket', False):
                        _gp_key = _gp_tok_to_field[field]
                        _gp_64 = _gp_tok_is_64[field]
                        if _gp_key in field_map and not field_map[_gp_key]['is_fixed'] and _gp_key not in emitted_fields:
                            _gp_cpp = field_map[_gp_key]['name']
                            # For generic <R> prefix (Rn/Rm/Rd), check sf field to determine X/W
                            if not _gp_64 and field in ('Rn', 'Rm', 'Rd', 'Rdn', 'Rda') and 'sf' in field_map and not field_map['sf']['is_fixed']:
                                _sf_cpp = field_map['sf']['name']
                                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{_gp_cpp}, (bool)enc.{member_name}.{_sf_cpp}));")
                            else:
                                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{_gp_cpp}, {str(_gp_64).lower()}));")
                            emitted_fields.add(_gp_key)
                    continue
                # Skip if already consumed as part of a complex memory operand (e.g. Zm in [Xn, Zm.T])
                # Allow re-emission for fields that appear multiple times in the template (e.g. NBSL Zdn)
                if actual_field in emitted_fields and field_template_count.get(actual_field, 0) <= 1:
                    continue
                field_cpp_name = field_map[actual_field]['name']
                emitted_fields.add(actual_field)

                # Register value expression (handles pair second: Zn+1)
                reg_val_expr = f"enc.{member_name}.{field_cpp_name}"
                if is_pair_second:
                    reg_val_expr = f"(enc.{member_name}.{field_cpp_name} + 1) % 32"

                if actual_field in sve_z_names:
                    # Compute arr_expr (shared by all branches)
                    def _arr_expr_for(arr_val):
                        if is_narrowing and has_sve_size:
                            # For narrowing instructions: T=destination(narrow), Tb=source(wide)
                            # tsz-based: _sve_arr=destination(T), _sve_arr_narrow=source-wider(Tb)
                            # size-based: _sve_arr=size-mapped=source(Tb), _sve_arr_narrow=dest(T)
                            if arr_val == 'Tb':
                                return '_sve_arr_narrow' if has_tsz_size else '_sve_arr'
                            elif arr_val == 'T':
                                return '_sve_arr' if has_tsz_size else '_sve_arr_narrow'
                        elif needs_narrow and has_sve_size and arr_val == 'Tb':
                            # Non-narrowing widening instructions (SMLSLB etc.): Tb→_sve_arr_narrow
                            return '_sve_arr_narrow'
                        if arr_val and arr_val not in ('T', 'Tb', 'Ts'):
                            return _STR_TO_ARR.get(arr_val, 'Arrangement::None')
                        elif has_sve_size:
                            return '_sve_arr'
                        return 'Arrangement::None'
                    arr_expr = _arr_expr_for(arr)

                    if top.get('in_mem_bracket') and not top.get('complex_mem'):
                        # SVE gather with Z base: [Zm.T, #imm*elem_size]
                        mem_imm = top.get('mem_imm_field')
                        # Resolve template imm name to actual field_map key
                        if mem_imm and mem_imm not in field_map:
                            for _k in field_map:
                                if _k.startswith('imm') and not field_map[_k]['is_fixed']:
                                    mem_imm = _k
                                    break
                        _m = mnemonic.upper()
                        if _m.endswith('SB'): _esz = 1
                        elif _m.endswith('SH'): _esz = 2
                        elif _m.endswith('SW'): _esz = 4
                        elif _m.endswith('B'): _esz = 1
                        elif _m.endswith('H'): _esz = 2
                        elif _m.endswith('W'): _esz = 4
                        elif _m.endswith('D'): _esz = 8
                        elif _m.endswith('Q'): _esz = 16
                        else: _esz = 1
                        if mem_imm and mem_imm in field_map and not field_map[mem_imm]['is_fixed']:
                            imm_field_cpp = field_map[mem_imm]['name']
                            code.append(f"{ind}{{")
                            code.append(f"{ind}    int32_t _imm = (int32_t)enc.{member_name}.{imm_field_cpp} * {_esz};")
                            code.append(f"{ind}    Operand op(OperandType::MemorySVEOffset, {reg_val_expr}, _imm);")
                            code.append(f"{ind}    op.arrangement = {arr_expr};")
                            code.append(f"{ind}    result.operands.push_back(op);")
                            code.append(f"{ind}}}")
                            consumed_imm_fields.add(mem_imm)
                        else:
                            code.append(f"{ind}{{ Operand op(OperandType::MemorySVEOffset, {reg_val_expr}, (int32_t)0); op.arrangement = {arr_expr}; result.operands.push_back(op); }}")
                    elif top.get('is_list') and not top.get('in_mem_bracket'):
                        # Single { Zt.T } (no numbered suffix) → SVERegisterList with count=1
                        if top.get('has_elem_index'):
                            idx_code = self._generate_sve_index_expr(field_map, member_name, encoding_name)
                            if idx_code:
                                code.append(f"{ind}{{ Operand op(OperandType::SVERegisterList, {reg_val_expr}, true); op.arrangement = {arr_expr}; op.index = 1; {idx_code} result.operands.push_back(op); }}")
                                sve_index_consumed = True
                            else:
                                code.append(f"{ind}{{ Operand op(OperandType::SVERegisterList, {reg_val_expr}, true); op.arrangement = {arr_expr}; op.index = 1; result.operands.push_back(op); }}")
                        else:
                            code.append(f"{ind}{{ Operand op(OperandType::SVERegisterList, {reg_val_expr}, true); op.arrangement = {arr_expr}; op.index = 1; result.operands.push_back(op); }}")
                    else:
                        # Normal SVERegister (also used for complex_mem Z registers)
                        if top.get('has_elem_index'):
                            # Indexed register: Zm.T[idx] — compute index from split fields
                            # If template has no explicit arrangement (arr=None), use nullptr (e.g., Zn[idx] in LUTI4)
                            idx_arr_expr = arr_expr if arr else 'Arrangement::None'
                            idx_code = self._generate_sve_index_expr(field_map, member_name, encoding_name)
                            if idx_code:
                                code.append(f"{ind}{{ Operand op(OperandType::SVERegister, {reg_val_expr}, true); op.arrangement = {idx_arr_expr}; {idx_code} result.operands.push_back(op); }}")
                                sve_index_consumed = True
                            else:
                                code.append(f"{ind}{{ Operand op(OperandType::SVERegister, {reg_val_expr}, true); op.arrangement = {idx_arr_expr}; result.operands.push_back(op); }}")
                        else:
                            code.append(f"{ind}{{ Operand op(OperandType::SVERegister, {reg_val_expr}, true); op.arrangement = {arr_expr}; result.operands.push_back(op); }}")
                elif field in sve_p_names:
                    # For predicates: only apply arrangement if template explicitly shows it
                    if arr and arr not in ('T', 'Tb', 'Ts'):
                        arr_expr = _STR_TO_ARR.get(arr, 'Arrangement::None')
                    elif arr and arr.startswith('T') and has_sve_size:
                        if arr == 'Tb' and is_narrowing:
                            arr_expr = '_sve_arr_narrow' if has_tsz_size else '_sve_arr'
                        elif arr == 'T' and is_narrowing and not has_tsz_size:
                            arr_expr = '_sve_arr_narrow'
                        else:
                            arr_expr = '_sve_arr'
                    elif arr is None and qual is None and has_sve_size and field not in ('Pg', 'Pv'):
                        # Data predicate without explicit arrangement: use size
                        # Governing predicates (Pg, Pv) never show an arrangement
                        arr_expr = '_sve_arr'
                    else:
                        arr_expr = 'Arrangement::None'
                    # PNg/PNd/PNn/PNv: predicate-as-counter registers (pn8-pn15)
                    # Encoded as 3-bit field, actual register = 8 | field_value (g = UInt('1'::PNg))
                    is_pn_reg = field.startswith('PN')
                    if is_pn_reg:
                        pn_val_expr = f"enc.{member_name}.{field_cpp_name} | 8u"
                        if qual == 'z':
                            code.append(f"{ind}{{ Operand op(OperandType::PredicateNRegister, {pn_val_expr}, false); op.is_sp = true; result.operands.push_back(op); }}")
                        elif qual == 'm':
                            code.append(f"{ind}{{ Operand op(OperandType::PredicateNRegister, {pn_val_expr}, true); op.is_sp = true; result.operands.push_back(op); }}")
                        else:
                            code.append(f"{ind}{{ Operand op(OperandType::PredicateNRegister, {pn_val_expr}, true); result.operands.push_back(op); }}")
                    elif qual == 'z':
                        code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = Arrangement::None; op.is_sp = true; result.operands.push_back(op); }}")
                    elif qual == 'm':
                        code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{field_cpp_name}, true); op.arrangement = Arrangement::None; op.is_sp = true; result.operands.push_back(op); }}")
                    elif qual == 'zm':
                        # Variable qualifier: M field determines /Z (M=0) or /M (M=1)
                        if 'M' in field_map and not field_map['M']['is_fixed']:
                            _m_field = field_map['M']['name']
                            code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{field_cpp_name}, enc.{member_name}.{_m_field} != 0); op.arrangement = Arrangement::None; op.is_sp = true; result.operands.push_back(op); }}")
                        else:
                            code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{field_cpp_name}, true); op.arrangement = Arrangement::None; op.is_sp = true; result.operands.push_back(op); }}")
                    else:
                        code.append(f"{ind}{{ Operand op(OperandType::PredicateRegister, enc.{member_name}.{field_cpp_name}, true); op.arrangement = {arr_expr}; result.operands.push_back(op); }}")
                elif actual_field in ('Rdn', 'Rda', 'Rd', 'Rn', 'Rm', 'Ra', 'Rt', 'Rs', 'Rt2'):
                    # GP register in SVE template (e.g., CLASTA <R><dn>, <Pg>, <R><dn>, <Zm>.<T>)
                    # Determine register width from 'sf' field or encoding size
                    # For SVE <R> prefix: size >= 2 → X (64-bit), else W (32-bit)
                    _gp_is_64 = 'is_64bit' if 'sf' in field_map and not field_map['sf']['is_fixed'] else 'true'
                    if 'sf' in field_map and field_map['sf']['is_fixed']:
                        _sf_val = int(field_map['sf']['fixed'], 2) if field_map['sf'].get('fixed') else 0
                        _gp_is_64 = 'true' if _sf_val else 'false'
                    elif 'size' in field_map and field_map['size']['is_fixed'] and field_map['size'].get('fixed'):
                        _sz_val = int(field_map['size']['fixed'], 2)
                        _gp_is_64 = 'true' if _sz_val == 3 else 'false'
                    elif 'size' in field_map and not field_map['size']['is_fixed']:
                        # Variable size: determine GP register width at runtime (size >= 2 → 64-bit)
                        _sz_cpp = field_map['size']['name']
                        _gp_is_64 = f'(enc.{member_name}.{_sz_cpp} >= 2)'
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{field_cpp_name}, {_gp_is_64}));")
                elif actual_field in ('Vdn', 'Vda', 'Vd', 'Vn', 'Vm'):
                    # SIMD scalar register in SVE template (e.g., CLASTA <V><dn>, <Pg>, <V><dn>, <Zm>.<T>)
                    # Arrangement determined by size field
                    _v_arr = 'Arrangement::None'
                    if has_sve_size:
                        _v_arr = '_sve_arr'
                    elif 'size' in field_map and field_map['size']['is_fixed'] and field_map['size'].get('fixed'):
                        _sz_val = int(field_map['size']['fixed'], 2)
                        _v_arr_map = {0: 'Arrangement::B', 1: 'Arrangement::H', 2: 'Arrangement::S', 3: 'Arrangement::D'}
                        _v_arr = _v_arr_map.get(_sz_val, 'Arrangement::D')
                    code.append(f"{ind}{{ Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false); op.arrangement = {_v_arr}; result.operands.push_back(op); }}")
                    _simd_v_emitted.add(actual_field)

            # Emit any remaining SVE/P fields not found in template
            # Compute fallback arrangement for Z regs not in template
            _fallback_arr_expr = 'Arrangement::None'
            if has_sve_size:
                _fallback_arr_expr = '_sve_arr'
            else:
                # Look for explicit fixed arrangement in template_ops (e.g. .D from MOV <Zd>.D)
                for _top in template_ops:
                    _tarr = _top.get('arrangement')
                    if _tarr and _tarr not in ('T', 'Tb', 'Ts'):
                        _fallback_arr_expr = _STR_TO_ARR.get(_tarr, "Arrangement::None")
                        break
            for reg_name in list(sve_z_names) + list(sve_p_names):
                if reg_name in field_map and not field_map[reg_name]['is_fixed'] and reg_name not in emitted_fields:
                    field_cpp_name = field_map[reg_name]['name']
                    if reg_name in sve_z_names:
                        code.append(f"{ind}{{ Operand op(OperandType::SVERegister, enc.{member_name}.{field_cpp_name}, true); op.arrangement = {_fallback_arr_expr}; result.operands.push_back(op); }}")
                    elif reg_name.startswith('PN'):
                        code.append(f"{ind}result.operands.push_back(Operand(OperandType::PredicateNRegister, enc.{member_name}.{field_cpp_name} | 8u, true));")
                    else:
                        code.append(f"{ind}result.operands.push_back(Operand(OperandType::PredicateRegister, enc.{member_name}.{field_cpp_name}, true));")
        else:
            _simd_v_emitted = set()  # no template-based V registers emitted
            # Non-SVE or no template: use original field-order extraction
            for reg_name in ['Zd', 'Zn', 'Zm', 'Za', 'Zk', 'Zt', 'Zda', 'Zdn']:
                if reg_name in field_map and not field_map[reg_name]['is_fixed']:
                    field_cpp_name = field_map[reg_name]['name']
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::SVERegister, enc.{member_name}.{field_cpp_name}, true));")
            for reg_name in ['Pd', 'Pn', 'Pm', 'Pg', 'Pt', 'Pv', 'Pdm', 'Pdn', 'PNd', 'PNn', 'PNg', 'PNv']:
                if reg_name in field_map and not field_map[reg_name]['is_fixed']:
                    field_cpp_name = field_map[reg_name]['name']
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::PredicateRegister, enc.{member_name}.{field_cpp_name}, true));")

        # Add deferred SVE compare-to-zero #0.0 AFTER sve registers are emitted
        if _needs_sve_zero:
            code.append(f"{ind}{{ Operand op(OperandType::FloatImmediate, 0, true); op.imm64 = UINT64_MAX; result.operands.push_back(op); }}")

        # Extract SIMD V register operands (skip if already emitted via SIMD scalar map in template_ops)
        for reg_name in ['Vd', 'Vdn', 'Vn', 'Vm']:
            if reg_name in field_map and not field_map[reg_name]['is_fixed'] and reg_name not in _simd_v_emitted:
                field_cpp_name = field_map[reg_name]['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, true));")

        # Extract SME ZA tile register operands (skip if already emitted as first operand)
        for reg_name in ['ZAd', 'ZAda', 'ZAn', 'ZAt']:
            if reg_name in field_map and not field_map[reg_name]['is_fixed']:
                if _za_first_emitted and reg_name in ('ZAd', 'ZAda'):
                    continue
                field_cpp_name = field_map[reg_name]['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::SMETileRegister, enc.{member_name}.{field_cpp_name}, true));")

        # Extract Rv index register (2-bit field encoding W8-W11)
        if 'Rv' in field_map and not field_map['Rv']['is_fixed']:
            rv_field = field_map['Rv']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rv_field} + 8, false));")

        # Combine split immediate fields before extracting individual immediates
        # i3h + i3l -> combined 3-bit index (skip if consumed as element index)
        if not sve_index_consumed and 'i3h' in field_map and not field_map['i3h']['is_fixed'] and 'i3l' in field_map and not field_map['i3l']['is_fixed']:
            i3h_field = field_map['i3h']['name']
            i3l_field = field_map['i3l']['name']
            i3l_width = field_map['i3l']['width']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (enc.{member_name}.{i3h_field} << {i3l_width}) | enc.{member_name}.{i3l_field}, true));")

        # i4h + i4l -> combined 4-bit index (skip if consumed as element index)
        if not sve_index_consumed and 'i4h' in field_map and not field_map['i4h']['is_fixed'] and 'i4l' in field_map and not field_map['i4l']['is_fixed']:
            i4h_field = field_map['i4h']['name']
            i4l_field = field_map['i4l']['name']
            i4l_width = field_map['i4l']['width']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (enc.{member_name}.{i4h_field} << {i4l_width}) | enc.{member_name}.{i4l_field}, true));")

        # i2h + i2l -> combined 2-bit index (skip if consumed as element index)
        if not sve_index_consumed and 'i2h' in field_map and not field_map['i2h']['is_fixed'] and 'i2l' in field_map and not field_map['i2l']['is_fixed']:
            i2h_field = field_map['i2h']['name']
            i2l_field = field_map['i2l']['name']
            i2l_width = field_map['i2l']['width']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (enc.{member_name}.{i2h_field} << {i2l_width}) | enc.{member_name}.{i2l_field}, true));")

        # imm9h + imm9l -> combined imm9 (SVE LDR/STR pred/vec)
        # Only emit if not already consumed by the memory operand handler above
        if ('imm9h' in field_map and not field_map['imm9h']['is_fixed'] and
                'imm9l' in field_map and not field_map['imm9l']['is_fixed'] and
                'imm9h' not in consumed_imm_fields and 'imm9l' not in consumed_imm_fields):
            imm9h_field = field_map['imm9h']['name']
            imm9l_field = field_map['imm9l']['name']
            imm9l_width = field_map['imm9l']['width']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (enc.{member_name}.{imm9h_field} << {imm9l_width}) | enc.{member_name}.{imm9l_field}, true));")

        # imm8h + imm8l -> combined imm8 (SVE EXT)
        if 'imm8h' in field_map and not field_map['imm8h']['is_fixed'] and 'imm8l' in field_map and not field_map['imm8l']['is_fixed']:
            imm8h_field = field_map['imm8h']['name']
            imm8l_field = field_map['imm8l']['name']
            imm8l_width = field_map['imm8l']['width']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (enc.{member_name}.{imm8h_field} << {imm8l_width}) | enc.{member_name}.{imm8l_field}, true));")

        # a,b,c,d,e,f,g,h -> combined imm8 for ADVSIMD BIC/MOVI/FMOV
        abcdefgh_fields = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
        if all(f in field_map and not field_map[f]['is_fixed'] for f in abcdefgh_fields):
            parts = []
            for bit_idx, f in enumerate(abcdefgh_fields):
                parts.append(f"(enc.{member_name}.{field_map[f]['name']} << {7 - bit_idx})")
            combined = ' | '.join(parts)
            # FMOV vector uses FloatImmediate; all other (MOVI/MVNI/BIC/ORR) use plain Immediate
            if mnemonic == 'FMOV':
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::FloatImmediate, {combined}, true));")
            elif mnemonic == 'MOVI':
                # For 64-bit forms (D or 2d arrangement), expand 8-bit immediate to 64-bit:
                # each bit of imm8 → full byte (0x00 or 0xff)
                code.append(f"{ind}{{")
                code.append(f"{ind}    uint32_t _imm8 = {combined};")
                code.append(f"{ind}    Operand _movi_op(OperandType::Immediate, _imm8, true);")
                code.append(f"{ind}    Arrangement _marr = get_movi_arrangement(insn);")
                code.append(f"{ind}    if (_marr != Arrangement::None && (_marr == Arrangement::D || _marr == Arrangement::D2)) {{")
                code.append(f"{ind}        uint64_t _imm64 = 0;")
                code.append(f"{ind}        for (int _i = 0; _i < 8; _i++) {{ if (_imm8 & (1u << _i)) _imm64 |= (0xFFULL << (_i * 8)); }}")
                code.append(f"{ind}        _movi_op.imm64 = _imm64;")
                code.append(f"{ind}    }}")
                code.append(f"{ind}    result.operands.push_back(_movi_op);")
                code.append(f"{ind}}}")
            else:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, {combined}, true));")
            # Add shift operand for MOVI/MVNI (LSL/MSL based on cmode) — must come after immediate
            if mnemonic in ['MOVI', 'MVNI']:
                code.append(f"{ind}{{")
                code.append(f"{ind}    int _movi_shift = get_movi_shift(insn);")
                code.append(f"{ind}    if (_movi_shift > 0) {{")
                code.append(f"{ind}        result.operands.push_back(Operand(OperandType::Shift, (0 << 8) | _movi_shift, true));  // LSL")
                code.append(f"{ind}    }} else if (_movi_shift < 0) {{")
                code.append(f"{ind}        result.operands.push_back(Operand(OperandType::Shift, (4 << 8) | (-_movi_shift), true));  // MSL")
                code.append(f"{ind}    }}")
                code.append(f"{ind}}}")

        # SVE logical immediate: imm13 encodes N:immr:imms, needs decode_bit_masks
        if 'imm13' in field_map and not field_map['imm13']['is_fixed'] and ('Zdn' in field_map or 'Zd' in field_map):
            imm13_cpp = field_map['imm13']['name']
            zdn_field = field_map.get('Zdn') or field_map.get('Zd')
            zdn_cpp = zdn_field['name']
            is_zdn = 'Zdn' in field_map  # Zdn appears twice (src=dst), Zd only once (DUPM)
            # Split imm13 into N(bit12), immr(bits11:6), imms(bits5:0)
            code.append(f"{ind}uint32_t _imm13 = enc.{member_name}.{imm13_cpp};")
            code.append(f"{ind}uint32_t _N = (_imm13 >> 12) & 1;")
            code.append(f"{ind}uint32_t _immr = (_imm13 >> 6) & 0x3f;")
            code.append(f"{ind}uint32_t _imms = _imm13 & 0x3f;")
            code.append(f"{ind}uint64_t _imm_val = decode_bit_masks(_N, _imms, _immr, true);")
            # Derive arrangement from element size
            code.append(f"{ind}Arrangement _sve_log_arr = Arrangement::None;")
            code.append(f"{ind}if (_N) {{ _sve_log_arr = Arrangement::D; }}")
            code.append(f"{ind}else if ((_imms & 0x20) == 0) {{ _sve_log_arr = Arrangement::S; }}")
            code.append(f"{ind}else if ((_imms & 0x30) == 0x20) {{ _sve_log_arr = Arrangement::H; }}")
            code.append(f"{ind}else if ((_imms & 0x38) == 0x30) {{ _sve_log_arr = Arrangement::B; }}")
            code.append(f"{ind}else {{ _sve_log_arr = Arrangement::D; }}")
            # Fix SVE register operands already pushed (with Arrangement::None) with correct arrangement
            code.append(f"{ind}for (auto& op : result.operands) {{ if (op.type == OperandType::SVERegister) op.arrangement = _sve_log_arr; }}")
            # Truncate immediate to element size for display
            code.append(f"{ind}if (_sve_log_arr == Arrangement::B) _imm_val &= 0xFF;")
            code.append(f"{ind}else if (_sve_log_arr == Arrangement::H) _imm_val &= 0xFFFF;")
            code.append(f"{ind}else if (_sve_log_arr == Arrangement::S) _imm_val &= 0xFFFFFFFF;")
            # Push decoded immediate
            code.append(f"{ind}{{ Operand op(OperandType::Immediate, static_cast<uint32_t>(_imm_val), true); op.imm64 = _imm_val; result.operands.push_back(op); }}")
            code.append(f"{ind}return result;")
            return code

        # Extract ALL immediate operands (don't break after first)
        imm_patterns = [
            ('imm12', 12, True),   # (name, bits, is_unsigned)
            ('imm16', 16, True),
            ('imm13', 13, True),   # SVE logical immediate
            ('imm6', 6, True),
            ('imm5', 5, True),
            ('imm5b', 5, True),    # Split imm5 variant
            ('imm8', 8, True),
            ('imm9', 9, False),    # Typically signed
            ('simm9', 9, False),   # Explicitly signed
            ('imm7', 7, False),    # Typically signed
            ('simm7', 7, False),   # Explicitly signed
            ('imm4', 4, True),     # SVE/SME index, barrier CRm
            ('imm3', 3, True),     # SVE/SME index
            ('imm2', 2, True),     # SVE/SME index
            ('immb', 6, True),     # SIMD shift amount
            ('immr', 6, True),     # Rotate/right-shift amount
            ('imms', 6, True),     # Bit width / shift amount
        ]

        # Check if shift field exists (imm6 is then the shift amount, not standalone)
        has_shift_field = 'shift' in field_map and not field_map['shift']['is_fixed']

        for imm_name, bits, is_unsigned in imm_patterns:
            if imm_name in field_map and not field_map[imm_name]['is_fixed']:
                # Skip imm6 when a shift field exists - it's the shift amount, not a standalone immediate
                if imm_name == 'imm6' and has_shift_field:
                    continue

                # Skip imm4 when SVE pattern is present - it's the MUL multiplier, handled after pattern
                if imm_name == 'imm4' and 'pattern' in field_map and not field_map['pattern']['is_fixed']:
                    continue

                # Multi-vector narrowing shift (_z_mz2_/_z_mz4_): imm encodes esize_dest - shift
                # _z_mz2_b: B dest from H source, shift = 8 - imm3
                # _z_mz2_: H dest from S source, shift = 16 - imm4
                if imm_name == 'imm3' and '_z_mz2_b' in encoding_name:
                    field_cpp_name = field_map[imm_name]['name']
                    if imm_name not in consumed_imm_fields:
                        code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, 8u - enc.{member_name}.{field_cpp_name}, true));")
                    continue
                if imm_name == 'imm4' and '_z_mz2_' in encoding_name and encoding_name.rstrip('_').endswith('mz2'):
                    field_cpp_name = field_map[imm_name]['name']
                    if imm_name not in consumed_imm_fields:
                        code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, 16u - enc.{member_name}.{field_cpp_name}, true));")
                    continue

                # For SVE shift-by-immediate: replace raw imm3 with computed shift amount
                if imm_name == 'imm3' and has_tsz_size:
                    # Determine shift direction from mnemonic
                    mnem_upper = mnemonic.upper()
                    is_left_shift = any(s in mnem_upper for s in ['SHLL', 'SLI'])
                    shift_var = '_shift_left' if is_left_shift else '_shift_right'
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, {shift_var}, true));")
                    continue

                field_cpp_name = field_map[imm_name]['name']

                # Skip imm fields that were consumed as SVE memory offsets in the template loop
                if imm_name in consumed_imm_fields:
                    continue

                # FMOV floatimm: imm8 is a VFP-encoded float, not a raw integer
                if imm_name == 'imm8' and 'floatimm' in encoding_name:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::FloatImmediate, enc.{member_name}.{field_cpp_name}, true));")
                    continue

                # CPY/FCPY signed imm8 with optional LSL#8 shift
                if imm_name == 'imm8' and mnemonic in ('CPY', 'FCPY') and 'sh' in field_map and not field_map['sh']['is_fixed']:
                    sh_cpp = field_map['sh']['name']
                    code.append(f"{ind}{{")
                    code.append(f"{ind}    int32_t _signed_imm8 = static_cast<int32_t>(enc.{member_name}.{field_cpp_name} << 24) >> 24;")
                    code.append(f"{ind}    if (enc.{member_name}.{sh_cpp}) _signed_imm8 <<= 8;")
                    code.append(f"{ind}    result.operands.push_back(Operand(OperandType::SignedImmediate, static_cast<uint32_t>(_signed_imm8), true));")
                    code.append(f"{ind}}}")
                    continue

                # SVE signed compare imm5: CMPEQ/CMPGE/CMPGT/CMPLE/CMPLT/CMPNE use signed 5-bit (-16..15)
                is_sve_signed_cmp = (imm_name == 'imm5' and mnemonic in ['CMPEQ', 'CMPGE', 'CMPGT', 'CMPLE', 'CMPLT', 'CMPNE']
                                     and any(rn in field_map for rn in ['Zn', 'Zm', 'Pd']))
                treat_as_signed = is_sve_signed_cmp or (not is_unsigned and self._is_signed_field(imm_name))
                if not treat_as_signed:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{field_cpp_name}, true));")
                else:
                    # Sign extend
                    code.append(f"{ind}{{")
                    code.append(f"{ind}    int32_t val = static_cast<int32_t>(enc.{member_name}.{field_cpp_name} << {32-bits}) >> {32-bits};")
                    code.append(f"{ind}    result.operands.push_back(Operand(OperandType::SignedImmediate, static_cast<uint32_t>(val), true));")
                    code.append(f"{ind}}}")

        # Extract SVE/SME offset fields
        for off_name in ['off4', 'off3', 'off2']:
            if off_name in field_map and not field_map[off_name]['is_fixed']:
                field_cpp_name = field_map[off_name]['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{field_cpp_name}, true));")

        # Extract SVE/SME split index fields (skip if already consumed as element index)
        for idx_name in ['i1', 'i2', 'i3', 'i4']:
            if idx_name in field_map and not field_map[idx_name]['is_fixed']:
                if sve_index_consumed:
                    continue  # Already emitted as element index in Zm[idx]
                field_cpp_name = field_map[idx_name]['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{field_cpp_name}, true));")

        # Handle shift operands (shift + amount) - use Shift operand type with value
        if 'shift' in field_map and not field_map['shift']['is_fixed']:
            shift_field = field_map['shift']['name']

            # Check for corresponding amount field
            amount_field = None
            for amt_name in ['imm6', 'imm5', 'imm4', 'imm3', 'imm2']:
                if amt_name in field_map and not field_map[amt_name]['is_fixed']:
                    amount_field = field_map[amt_name]['name']
                    break

            if amount_field:
                code.append(f"{ind}{{")
                code.append(f"{ind}    uint32_t shift_type = enc.{member_name}.{shift_field};")
                code.append(f"{ind}    uint32_t shift_amount = enc.{member_name}.{amount_field};")
                code.append(f"{ind}    // Only emit shift operand if non-zero (suppress LSL #0)")
                code.append(f"{ind}    if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {{")
                code.append(f"{ind}        result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));")
                code.append(f"{ind}    }}")
                code.append(f"{ind}}}")

        # Handle condition field (cond) — set on Instruction, not as operand
        if 'cond' in field_map and not field_map['cond']['is_fixed']:
            cond_field = field_map['cond']['name']
            code.append(f"{ind}result.condition = static_cast<Condition>(enc.{member_name}.{cond_field});")

        # Handle cc (condition code for CB instructions) — set on Instruction
        if 'cc' in field_map and not field_map['cc']['is_fixed']:
            cc_field = field_map['cc']['name']
            code.append(f"{ind}result.condition = static_cast<Condition>(enc.{member_name}.{cc_field});")

        # Handle SVE pattern operand (pow2, vl1..vl256, mul3, mul4, all)
        # Followed by optional MUL #N multiplier (imm4+1) when imm4 is present
        if 'pattern' in field_map and not field_map['pattern']['is_fixed']:
            pattern_field = field_map['pattern']['name']
            # Suppress ALL(31) when pattern is optional (template uses {, <pattern>} notation)
            # BUT: if imm4 is also present and non-zero, show 'all' explicitly (e.g. 'uqdecd x29, all, mul #0x10')
            _pat_optional = '{' in asm_template and 'pattern' in asm_template
            _has_imm4 = 'imm4' in field_map and not field_map['imm4']['is_fixed']
            if _has_imm4:
                imm4_field = field_map['imm4']['name']
            if _pat_optional and _has_imm4:
                # Show pattern if not ALL, OR if ALL with non-default mul (imm4 != 0)
                code.append(f"{ind}if (enc.{member_name}.{pattern_field} != 31 || enc.{member_name}.{imm4_field} != 0) {{")
                code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Pattern, enc.{member_name}.{pattern_field}, true));")
                code.append(f"{ind}    result.operands.back().pattern = pattern_from_value(enc.{member_name}.{pattern_field});")
                code.append(f"{ind}}}")
                code.append(f"{ind}if (enc.{member_name}.{imm4_field} != 0)")
                code.append(f"{ind}    result.operands.push_back(Operand(OperandType::SVEMulImm, enc.{member_name}.{imm4_field} + 1u, true));")
            elif _pat_optional:
                code.append(f"{ind}if (enc.{member_name}.{pattern_field} != 31) {{")
                code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Pattern, enc.{member_name}.{pattern_field}, true));")
                code.append(f"{ind}    result.operands.back().pattern = pattern_from_value(enc.{member_name}.{pattern_field});")
                code.append(f"{ind}}}")
                if _has_imm4:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::SVEMulImm, enc.{member_name}.{imm4_field} + 1u, true));")
            else:
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Pattern, enc.{member_name}.{pattern_field}, true));")
                code.append(f"{ind}result.operands.back().pattern = pattern_from_value(enc.{member_name}.{pattern_field});")
                if _has_imm4:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::SVEMulImm, enc.{member_name}.{imm4_field} + 1u, true));")

        # Handle prefetch operation (pldl1keep, pstl2strm, etc.)
        # Skip if already emitted in SVE template loop (e.g., SVE PRFB with Pg/[Xn,#imm,mul vl])
        if 'prfop' in field_map and not field_map['prfop']['is_fixed'] and 'prfop' not in emitted_fields_pre:
            prfop_field = field_map['prfop']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Prefetch, enc.{member_name}.{prfop_field}, true));")
            code.append(f"{ind}result.operands.back().prefetch = prefetch_from_value(enc.{member_name}.{prfop_field});")

        # Handle NZCV flags immediate (CCMN/CCMP)
        if 'nzcv' in field_map and not field_map['nzcv']['is_fixed']:
            nzcv_field = field_map['nzcv']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{nzcv_field}, true));")

        # Handle rotation amount (0/90/180/270 for complex multiply)
        if 'rot' in field_map and not field_map['rot']['is_fixed']:
            rot_field = field_map['rot']['name']
            rot_width = field_map['rot'].get('width', 2)
            if rot_width == 1:
                # 1-bit rot: 0→90°, 1→270° (CADD/SQCADD etc.)
                code.append(f"{ind}{{ Operand op(OperandType::Immediate, enc.{member_name}.{rot_field} * 180u + 90u, true); op.prefer_decimal = true; result.operands.push_back(op); }}")
            else:
                # 2-bit rot: 0→0°, 1→90°, 2→180°, 3→270°
                code.append(f"{ind}{{ Operand op(OperandType::Immediate, enc.{member_name}.{rot_field} * 90u, true); op.prefer_decimal = true; result.operands.push_back(op); }}")

        # Handle fixed-point scale (FCVT/SCVTF)
        if 'scale' in field_map and not field_map['scale']['is_fixed']:
            scale_field = field_map['scale']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{scale_field}, true));")

        # Handle RMIF mask operand
        if 'mask' in field_map and not field_map['mask']['is_fixed']:
            mask_field = field_map['mask']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{mask_field}, true));")

        # Handle extend type (option field for add/sub extended)
        if 'option' in field_map and not field_map['option']['is_fixed']:
            option_field = field_map['option']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Extend, enc.{member_name}.{option_field}, true));")

        # Encoding-specific fixups
        # CLASTA/CLASTB _v_p_z_: insert tied second operand (Vdn repeated after Pg)
        if encoding_name in ('clasta_v_p_z_', 'clastb_v_p_z_') and 'Vdn' in field_map:
            vdn_f = field_map['Vdn']['name']
            # Insert Vdn copy at position 2 (after Vdn[0] and Pg[1])
            code.append(f"{ind}if (result.operands.size() >= 2) {{")
            code.append(f"{ind}    Operand tied = result.operands[0]; // copy of Vdn")
            code.append(f"{ind}    result.operands.insert(result.operands.begin() + 2, tied);")
            code.append(f"{ind}}}")
        # SQDEC*/SQINC* _sx forms: need Xdn (64-bit) BEFORE Wdn (32-bit) — dual-register operand
        if ('_r_rs_sx' in encoding_name or '_r_p_r_sx' in encoding_name) and 'Rdn' in field_map:
            rdn_f = field_map['Rdn']['name']
            # Insert X register at position 0 (before the existing W register)
            code.append(f"{ind}result.operands.insert(result.operands.begin(), Operand(OperandType::Register, enc.{member_name}.{rdn_f}, true));")
        elif encoding_name == 'chkfeat_hf_hints':
            # CHKFEAT always uses X16
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, 16u, true));")
        elif encoding_name == 'addpt_64_addsub_pt' or encoding_name == 'subpt_64_addsub_pt':
            # ADDPT/SUBPT: imm3 should be LSL shift, fix the last operand
            code.append(f"{ind}if (!result.operands.empty() && result.operands.back().type == OperandType::Immediate) {{")
            code.append(f"{ind}    uint32_t _amt = result.operands.back().value;")
            code.append(f"{ind}    result.operands.pop_back();")
            code.append(f"{ind}    if (_amt != 0) result.operands.push_back(Operand(OperandType::Shift, (0u << 8) | _amt, true));")
            code.append(f"{ind}}}")

        code.append(f"{ind}return result;")
        return code

    def _struct_to_member_name(self, struct_name: str) -> str:
        """Convert struct name to union member name (lowercase with underscores)."""
        # Convert CamelCase to snake_case
        result = []
        for i, c in enumerate(struct_name):
            if c.isupper() and i > 0 and struct_name[i-1].islower():
                result.append('_')
            result.append(c.lower())
        return ''.join(result)

    def _is_binary_string(self, s: str) -> bool:
        """Check if string is a valid binary pattern (only 0s and 1s)."""
        if not s:
            return False
        return all(c in '01' for c in s)

    def _is_signed_field(self, field_name: str) -> bool:
        """Determine if a field should be signed based on its name."""
        # Explicit signed field names
        if field_name.startswith('simm'):
            return True

        # Branch offsets are signed
        if field_name in ['imm19', 'imm26', 'imm14']:
            return True

        # Load/store offsets are typically signed
        if field_name == 'imm9':
            return True

        # Address offsets
        if 'addr' in field_name.lower():
            return True

        # PC-relative addressing
        if field_name in ['immlo', 'immhi']:
            return True

        return False

    def _sanitize_namespace(self, name: str) -> str:
        """Sanitize name for use as C++ namespace."""
        # Replace hyphens and special chars with underscores
        name = name.replace('-', '_').replace(' ', '_')
        # Capitalize first letter to avoid reserved keywords
        if name:
            name = name[0].upper() + name[1:]
        # Prepend underscore if starts with digit
        if name and name[0].isdigit():
            name = '_' + name
        return name

    def _sanitize_field_name(self, name: str) -> str:
        """Sanitize field name for use as C++ identifier."""
        # Convert to lowercase and replace special chars
        name = name.replace('-', '_').replace('.', '_').replace('!', 'not').replace('=', 'eq')
        # Ensure it starts with a letter or underscore
        if name and name[0].isdigit():
            name = 'f_' + name
        # Replace any remaining invalid characters
        name = ''.join(c if c.isalnum() or c == '_' else '_' for c in name)
        return name if name else 'field'

    def _sanitize_function_name(self, name: str) -> str:
        """Sanitize name for use as C++ function name."""
        # Convert to lowercase and replace special chars
        name = name.replace('-', '_').replace('.', '_').lower()
        # Ensure it starts with a letter or underscore
        if name and name[0].isdigit():
            name = 'enc_' + name
        # Replace any remaining invalid characters
        name = ''.join(c if c.isalnum() or c == '_' else '_' for c in name)
        return name if name else 'encode'

    def _sanitize_struct_name(self, name: str) -> str:
        """Sanitize name for use as C++ struct name."""
        # Remove special characters and convert to CamelCase
        parts = name.replace('-', '_').replace('.', '_').split('_')
        # Capitalize first letter of each part
        result = ''.join(p.capitalize() if p else '' for p in parts)
        # Ensure it starts with a letter or underscore
        if result and result[0].isdigit():
            result = 'Enc_' + result
        return result if result else 'EncodingStruct'

    def generate_cmake_files(self, base_dir: Path, test_dir: Path):
        """Generate CMakeLists.txt files for building the library and tests."""
        # Generate root CMakeLists.txt
        self._generate_root_cmake(base_dir)

        # Generate test CMakeLists.txt
        self._generate_test_cmake(test_dir)

    def _generate_root_cmake(self, base_dir: Path):
        """Generate root CMakeLists.txt."""
        code = []

        code.append("cmake_minimum_required(VERSION 3.14)")
        code.append("project(veda64 VERSION 0.1.0 LANGUAGES CXX)")
        code.append("")
        code.append("# Set C++ standard")
        code.append("set(CMAKE_CXX_STANDARD 17)")
        code.append("set(CMAKE_CXX_STANDARD_REQUIRED ON)")
        code.append("set(CMAKE_CXX_EXTENSIONS OFF)")
        code.append("")
        code.append("# IDE folder grouping")
        code.append("set_property(GLOBAL PROPERTY USE_FOLDERS ON)")
        code.append("")
        code.append("# Option to reduce binary size and remove strings")
        code.append("option(VEDA64_NO_STRINGS \"Disable all string functions (to_string, mnemonic_to_string, status_to_string, dump_hook)\" OFF)")
        code.append("option(VEDA64_BUILD_TESTS \"Build test executables\" ON)")
        code.append("option(VEDA64_HOOK \"Enable inline hooking support (Windows only)\" ON)")
        code.append("option(VEDA64_PYTHON \"Build Python bindings via nanobind (requires vcpkg toolchain)\" ON)")
        code.append("")
        code.append("# Compiler warnings")
        code.append("if(MSVC)")
        code.append("    add_compile_options(/W4 /bigobj)")
        code.append("else()")
        code.append("    add_compile_options(-Wall -Wextra -Wpedantic)")
        code.append("endif()")
        code.append("")
        code.append("# Pass options as compile definitions")
        code.append("if(VEDA64_NO_STRINGS)")
        code.append("    add_compile_definitions(VEDA64_NO_STRINGS)")
        code.append("endif()")
        code.append("")
        code.append("# Collect all source and header files")
        code.append("file(GLOB_RECURSE VEDA64_SOURCES \"lib/*.cpp\")")
        code.append("file(GLOB_RECURSE VEDA64_HEADERS \"include/*.hpp\")")
        code.append("")
        code.append("# Hook support")
        code.append("if(NOT VEDA64_HOOK)")
        code.append("    list(REMOVE_ITEM VEDA64_SOURCES \"${CMAKE_CURRENT_SOURCE_DIR}/lib/hook.cpp\")")
        code.append("    add_compile_definitions(VEDA64_NO_HOOKS)")
        code.append("endif()")
        code.append("")
        code.append("# Create library")
        code.append("add_library(veda64 ${VEDA64_SOURCES} ${VEDA64_HEADERS})")
        code.append("target_include_directories(veda64 PUBLIC")
        code.append("    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
        code.append("    $<INSTALL_INTERFACE:include>")
        code.append(")")
        code.append("set_target_properties(veda64 PROPERTIES FOLDER \"lib\")")
        code.append("source_group(TREE \"${CMAKE_CURRENT_SOURCE_DIR}/lib\" PREFIX \"Source Files\" FILES ${VEDA64_SOURCES})")
        code.append("source_group(TREE \"${CMAKE_CURRENT_SOURCE_DIR}/include\" PREFIX \"Header Files\" FILES ${VEDA64_HEADERS})")
        code.append("")
        code.append("# Link ntdll for NT syscalls on Windows (only when hooks are enabled)")
        code.append("if(WIN32 AND VEDA64_HOOK)")
        code.append("    target_link_libraries(veda64 PUBLIC ntdll)")
        code.append("endif()")
        code.append("")
        code.append("# Tools")
        code.append("add_executable(veda64-disasm tools/veda64-disasm.cpp)")
        code.append("target_link_libraries(veda64-disasm PRIVATE veda64)")
        code.append("set_target_properties(veda64-disasm PROPERTIES FOLDER \"tools\")")
        code.append("")
        code.append("# Enable testing")
        code.append("if(VEDA64_BUILD_TESTS)")
        code.append("    enable_testing()")
        code.append("    add_subdirectory(test)")
        code.append("endif()")
        code.append("")
        code.append("# Python bindings via nanobind (use vcpkg toolchain to satisfy dependency)")
        code.append("if(VEDA64_PYTHON)")
        code.append("    find_package(Python 3 COMPONENTS Interpreter Development.Module REQUIRED)")
        code.append("    find_package(nanobind CONFIG REQUIRED)")
        code.append("    nanobind_add_module(veda64_py NB_STATIC python/veda64_py.cpp)")
        code.append("    target_link_libraries(veda64_py PRIVATE veda64)")
        code.append("    set_target_properties(veda64_py PROPERTIES FOLDER \"python\")")
        code.append("    install(TARGETS veda64_py LIBRARY DESTINATION python)")
        code.append("endif()")
        code.append("")
        code.append("# Installation")
        code.append("install(TARGETS veda64 veda64-disasm")
        code.append("    LIBRARY DESTINATION lib")
        code.append("    ARCHIVE DESTINATION lib")
        code.append("    RUNTIME DESTINATION bin")
        code.append(")")
        code.append("install(DIRECTORY include/ DESTINATION include)")
        code.append("")

        output_file = base_dir / "CMakeLists.txt"
        self._write_file(output_file, code)

    def _generate_test_cmake(self, test_dir: Path):
        """Generate test/CMakeLists.txt."""
        code = []

        code.append("# Test suite for veda64")
        code.append("")
        code.append("# Collect all test files")
        code.append("file(GLOB TEST_SOURCES \"test_*.cpp\")")
        code.append("")
        code.append("# Create test executables")
        code.append("foreach(test_src ${TEST_SOURCES})")
        code.append("    get_filename_component(test_name ${test_src} NAME_WE)")
        code.append("    add_executable(${test_name} ${test_src})")
        code.append("    target_link_libraries(${test_name} veda64)")
        code.append("    add_test(NAME ${test_name} COMMAND ${test_name})")
        code.append("    set_target_properties(${test_name} PROPERTIES FOLDER \"test\")")
        code.append("endforeach()")
        code.append("")

        output_file = test_dir / "CMakeLists.txt"
        self._write_file(output_file, code)

    def generate_python_bindings(self, base_dir: Path):
        """Generate python/veda64_py.cpp with nanobind bindings and vcpkg.json."""

        python_dir = base_dir / "python"
        python_dir.mkdir(exist_ok=True)

        # Collect sorted mnemonics (same logic as generate_header_files)
        mnemonics = set()
        for instr in self.instructions:
            if instr.mnemonic:
                mnemonics.add(instr.mnemonic)
            for encoding in instr.encodings:
                enc_mnem = encoding.docvars.get('mnemonic', '')
                if enc_mnem:
                    mnemonics.add(enc_mnem)
        hint_aliases = ['NOP', 'YIELD', 'WFE', 'WFI', 'SEV', 'SEVL', 'DGH', 'XPACLRI',
                        'PACIA1716', 'PACIB1716', 'AUTIA1716', 'AUTIB1716',
                        'ESB', 'PSB', 'TSB', 'GCSB', 'CSDB', 'CLRBHB',
                        'PACIAZ', 'PACIASP', 'PACIBZ', 'PACIBSP',
                        'AUTIAZ', 'AUTIASP', 'AUTIBZ', 'AUTIBSP']
        mnemonics.update(hint_aliases)
        mnemonics.update(['TLBI', 'DC', 'AT', 'IC', 'GIC', 'BRB', 'CFP', 'CPP', 'DVP', 'APAS'])
        sorted_mnemonics = sorted(mnemonics)

        operand_types = [
            'Register', 'VectorRegister', 'SVERegister', 'PredicateRegister',
            'PredicateNRegister', 'SMETileRegister', 'Immediate', 'SignedImmediate',
            'MemoryBase', 'MemoryOffset', 'MemoryPreIndex', 'MemoryPostIndex',
            'MemoryRegOffset', 'Label', 'Relative', 'SystemRegister', 'Shift',
            'Extend', 'Index', 'Pattern', 'Prefetch', 'Barrier', 'FloatImmediate',
            'VectorRegisterList', 'SVERegisterList', 'MemoryOffsetMulVL',
            'MemorySVEOffset', 'SMEZTRegister', 'PstateField', 'FixedSym', 'SysOp', 'SVEVLxImm', 'PredicateRegisterList', 'Unknown',
        ]
        conditions = ['EQ', 'NE', 'CS', 'CC', 'MI', 'PL', 'VS', 'VC',
                      'HI', 'LS', 'GE', 'LT', 'GT', 'LE', 'AL', 'NV']

        code = self._license_header()
        code.append("#include <nanobind/nanobind.h>")
        code.append("#include <nanobind/stl/optional.h>")
        code.append("#include <nanobind/stl/vector.h>")
        code.append("#include <nanobind/stl/string.h>")
        code.append("#include <veda64.hpp>")
        code.append("")
        code.append("namespace nb = nanobind;")
        code.append("using namespace nb::literals;")
        code.append("")
        code.append("NB_MODULE(veda64_py, m) {")
        code.append("    m.doc() = \"veda64 ARM64 disassembler Python bindings\";")
        code.append("")

        # Mnemonic enum
        code.append("    nb::enum_<veda64::Mnemonic>(m, \"Mnemonic\")")
        for mnem in sorted_mnemonics:
            code.append(f"        .value(\"{mnem}\", veda64::Mnemonic::{mnem})")
        code.append("        .value(\"UNKNOWN\", veda64::Mnemonic::UNKNOWN);")
        code.append("")

        # Condition enum
        code.append("    nb::enum_<veda64::Condition>(m, \"Condition\")")
        code.append("        .value(\"NONE\", veda64::Condition::None)")
        for cond in conditions:
            code.append(f"        .value(\"{cond}\", veda64::Condition::{cond})")
        code.append("        ;")
        code.append("")

        # OperandType enum
        code.append("    nb::enum_<veda64::OperandType>(m, \"OperandType\")")
        for ot in operand_types:
            code.append(f"        .value(\"{ot}\", veda64::OperandType::{ot})")
        code.append("        ;")
        code.append("")

        # Operand class
        code.append("    nb::class_<veda64::Operand>(m, \"Operand\")")
        code.append("        .def_ro(\"type\",       &veda64::Operand::type)")
        code.append("        .def_ro(\"value\",      &veda64::Operand::value)")
        code.append("        .def_ro(\"imm64\",      &veda64::Operand::imm64)")
        code.append("        .def_ro(\"is_64bit\",   &veda64::Operand::is_64bit)")
        code.append("        .def_ro(\"is_sp\",      &veda64::Operand::is_sp)")
        code.append("        .def_prop_ro(\"arrangement\", [](const veda64::Operand& op) -> nb::object {")
        code.append("            if (op.arrangement == veda64::Arrangement::None) return nb::none();")
        code.append("            return nb::str(veda64::Operand::arrangement_to_string(op.arrangement));")
        code.append("        })")
        code.append("        .def_ro(\"index\",      &veda64::Operand::index)")
        code.append("        .def_ro(\"has_index\",  &veda64::Operand::has_index)")
        code.append("        .def_ro(\"base_reg\",   &veda64::Operand::base_reg)")
        code.append("        .def_ro(\"offset\",     &veda64::Operand::offset)")
        code.append("        .def_ro(\"index_reg\",  &veda64::Operand::index_reg)")
        code.append("        .def_ro(\"extend\",     &veda64::Operand::extend)")
        code.append("        .def_ro(\"amount\",     &veda64::Operand::amount)")
        code.append("        .def(\"to_string\",     &veda64::Operand::to_string)")
        code.append("        .def(\"__repr__\",      &veda64::Operand::to_string)")
        code.append("        ;")
        code.append("")

        # Instruction class
        code.append("    nb::class_<veda64::Instruction>(m, \"Instruction\")")
        code.append("        .def_ro(\"mnemonic\",   &veda64::Instruction::mnemonic)")
        code.append("        .def_ro(\"condition\",  &veda64::Instruction::condition)")
        code.append("        .def_ro(\"raw_value\",  &veda64::Instruction::raw_value)")
        code.append("        .def_ro(\"operands\",   &veda64::Instruction::operands)")
        code.append("        .def(\"to_string\",     &veda64::Instruction::to_string)")
        code.append("        .def(\"__repr__\",      &veda64::Instruction::to_string)")
        code.append("        ;")
        code.append("")

        # Free functions
        code.append("    // Decode from raw 32-bit instruction word")
        code.append("    m.def(\"decode\", [](uint32_t insn) { return veda64::decode(insn); },")
        code.append("          \"insn\"_a, \"Decode a single ARM64 instruction from a uint32_t\");")
        code.append("")
        code.append("    // Decode from 4 little-endian bytes")
        code.append("    m.def(\"decode_bytes\", [](nb::bytes data) -> std::optional<veda64::Instruction> {")
        code.append("        if (data.size() < 4) return std::nullopt;")
        code.append("        return veda64::decode(reinterpret_cast<const uint8_t*>(data.data()));")
        code.append("    }, \"data\"_a, \"Decode a single ARM64 instruction from 4 little-endian bytes\");")
        code.append("")
        code.append("    // Convert raw 4 bytes to uint32 (little-endian)")
        code.append("    m.def(\"from_bytes\", [](nb::bytes data) -> uint32_t {")
        code.append("        if (data.size() < 4) return 0;")
        code.append("        return veda64::from_bytes(reinterpret_cast<const uint8_t*>(data.data()));")
        code.append("    }, \"data\"_a, \"Read a little-endian uint32_t from 4 bytes\");")
        code.append("")
        code.append("    m.def(\"mnemonic_to_string\", &veda64::mnemonic_to_string,")
        code.append("          \"mnem\"_a, \"Convert a Mnemonic enum value to its string representation\");")
        code.append("")
        code.append("    m.def(\"condition_to_string\", &veda64::condition_to_string,")
        code.append("          \"cond\"_a, \"Convert a Condition enum value to its string representation\");")
        code.append("")
        code.append("    // Version info")
        code.append("    m.attr(\"VERSION_MAJOR\") = veda64::VERSION_MAJOR;")
        code.append("    m.attr(\"VERSION_MINOR\") = veda64::VERSION_MINOR;")
        code.append("    m.attr(\"VERSION_PATCH\") = veda64::VERSION_PATCH;")
        code.append("}")
        code.append("")

        output_file = python_dir / "veda64_py.cpp"
        self._write_file(output_file, code)
        print(f"Generated {output_file}")

        # Generate vcpkg.json manifest
        # Note: the overlay port at vcpkg_overlay_ports/nanobind/ removes the
        # python3 vcpkg dependency so that CMake find_package(Python) uses the
        # system Python instead of letting vcpkg build Python from source.
        # Configure with:
        #   cmake -DCMAKE_TOOLCHAIN_FILE=/c/vcpkg/scripts/buildsystems/vcpkg.cmake
        #         -DVCPKG_OVERLAY_PORTS=vcpkg_overlay_ports
        #         -DVCPKG_TARGET_TRIPLET=arm64-windows ...
        vcpkg_json = [
            '{',
            '    "name": "veda64",',
            '    "version": "0.1.0",',
            '    "dependencies": [',
            '        "nanobind"',
            '    ]',
            '}',
            '',
        ]
        vcpkg_file = base_dir / "vcpkg.json"
        self._write_file(vcpkg_file, vcpkg_json)
        print(f"Generated {vcpkg_file}")

    def _predict_operand_types(self, instr: Instruction, encoding: InstructionEncoding) -> list:
        """Predict OperandType names for an encoding's operands using template analysis.

        Returns list of OperandType enum names (strings), or None if prediction is uncertain
        (e.g., aliases transform operands, complex special cases).
        """
        import re

        # Skip prediction for encodings that are likely aliased at all-zero variable bits
        # (mnemonic may change, operand count may differ)
        # Common alias-producing patterns: ORR→MOV, SUBS→CMP, SUB→NEG, etc.
        alias_mnemonics = {
            'ORR', 'SUBS', 'SUB', 'ADDS', 'AND', 'ANDS', 'BFM', 'UBFM', 'SBFM',
            'CSINC', 'CSINV', 'CSNEG', 'MOVN', 'MOVZ', 'ORN', 'HINT', 'SYS', 'SYSL',
            'EXTR', 'MADD', 'MSUB',
        }
        if instr.mnemonic in alias_mnemonics:
            return None

        template = encoding.asm_template
        if not template:
            return None

        parsed = self._parse_template_operands(template)
        if not parsed:
            return None

        # Memory operands: the entire bracket group is one operand in the decoded output
        # We need to collapse all bracket tokens into one memory operand type
        operand_types = []
        i = 0
        while i < len(parsed):
            op = parsed[i]
            field = op.get('field', '')
            field_lower = field.lower()

            # ZT0 literal
            if op.get('type') == 'zt0':
                operand_types.append('SMEZTRegister')
                i += 1
                continue

            # Memory bracket operand — collapse to single memory type
            if op.get('in_mem_bracket'):
                # Determine memory type from the template
                # Find the full bracket token in the original template
                mem_type = 'MemoryBase'  # default
                parts = template.strip().split(None, 1)
                if len(parts) >= 2:
                    rest = parts[1]
                    # Check for post-index: ], #imm or ], Xm
                    if re.search(r'\]\s*,\s*[#<]', rest):
                        mem_type = 'MemoryPostIndex'
                    elif ']!' in rest:
                        mem_type = 'MemoryPreIndex'
                    elif op.get('complex_mem'):
                        mem_type = 'MemoryRegOffset'
                    elif op.get('mul_vl'):
                        mem_type = 'MemoryOffsetMulVL'
                    elif op.get('mem_imm_field'):
                        mem_type = 'MemoryOffset'
                # Skip remaining bracket operands
                while i < len(parsed) and parsed[i].get('in_mem_bracket'):
                    i += 1
                operand_types.append(mem_type)
                continue

            # Register lists
            if op.get('is_list'):
                if field.startswith('Z') or field.startswith('z'):
                    operand_types.append('SVERegisterList')
                elif field.startswith('P') or field.startswith('p'):
                    operand_types.append('PredicateRegisterList')
                else:
                    operand_types.append('VectorRegisterList')
                # Skip remaining list members
                while i + 1 < len(parsed) and parsed[i + 1].get('is_list'):
                    i += 1
                i += 1
                continue

            # Immediate operands
            if op.get('type') == 'imm':
                # Use symbol_map to classify if available
                sym_key = f'<{field}>'
                sym_info = encoding.symbol_map.get(sym_key, {})
                if sym_info:
                    cls = self._classify_symbol(sym_key, sym_info, {})
                    if cls:
                        tag = cls[0]
                        if tag == 'imm_signed':
                            operand_types.append('SignedImmediate')
                        elif tag == 'label':
                            operand_types.append('Label')
                        elif tag == 'condition':
                            # Condition stored in result.condition, not as operand
                            i += 1
                            continue
                        elif tag == 'system':
                            operand_types.append('SystemRegister')
                        elif tag in ('shift_table', ):
                            operand_types.append('Shift')
                        elif tag in ('extend_table', ):
                            operand_types.append('Extend')
                        elif tag in ('barrier_table', ):
                            operand_types.append('Barrier')
                        elif tag in ('option_table', 'prefetch_table'):
                            operand_types.append('Immediate')
                        else:
                            operand_types.append('Immediate')
                    else:
                        operand_types.append('Immediate')
                else:
                    operand_types.append('Immediate')
                i += 1
                continue

            # Register operands by field name pattern
            if field.startswith('Z') or field.startswith('z'):
                operand_types.append('SVERegister')
            elif field.startswith('P') or field.startswith('p'):
                if field.startswith('PN') or field.startswith('pn'):
                    operand_types.append('PredicateNRegister')
                else:
                    operand_types.append('PredicateRegister')
            elif field.startswith('V') or field.startswith('v'):
                operand_types.append('VectorRegister')
            elif field.startswith('ZA') or field.startswith('za'):
                operand_types.append('SMETileRegister')
            elif re.match(r'^[XWRB][a-z]', field):
                # Xd, Wn, Rd, Rn, etc. → GP register
                operand_types.append('Register')
            else:
                # Unknown — can't predict reliably
                return None

            i += 1

        return operand_types if operand_types else None

    def _adjust_test_pattern_for_undef(self, pattern: int, fields: list, decode_ps: str) -> int:
        """Adjust test instruction pattern to avoid Decode_UNDEF conditions.

        When all variable bits are 0, some field values (e.g. size==00) trigger UNDEF.
        This sets those fields to the smallest valid value instead.
        """
        import re
        if not decode_ps:
            return pattern

        # Build field info: name → (lsb, width)
        field_info = {}
        for f in fields:
            name = f.get('original_name') or f.get('name', '')
            if name and not name.startswith('_') and not f.get('is_fixed', False):
                field_info[name] = (f['lobit'], f['width'])

        # Handle: if FIELD == 'BITS' then EndOfDecode(Decode_UNDEF)
        for m in re.finditer(r"if\s+(\w+)\s*==\s*'([01]+)'\s+then\s+EndOfDecode\(Decode_UNDEF\)", decode_ps):
            field, bits = m.group(1), m.group(2)
            if field not in field_info:
                continue
            lsb, width = field_info[field]
            undef_val = int(bits, 2)
            current_val = (pattern >> lsb) & ((1 << width) - 1)
            if current_val == undef_val:
                # Clear field and set to smallest non-UNDEF value
                mask = ((1 << width) - 1) << lsb
                pattern &= ~mask
                # Try values starting from undef_val+1, wrapping around
                for candidate in range(1, 1 << width):
                    test_val = (undef_val + candidate) & ((1 << width) - 1)
                    pattern |= (test_val << lsb)
                    break

        return pattern

    def generate_encoding_tests(self, test_dir: Path):
        """Generate per-encoding test files grouped by format group."""
        # Clean up old test files (remove stale generated files)
        for f in test_dir.iterdir():
            if f.is_file() and f.suffix == '.cpp' and f.name.startswith('test_'):
                f.unlink()

        # Collect all encodings grouped by format_group
        by_group = {}
        for instr in self.instructions:
            for encoding in instr.encodings:
                group = encoding.format_group or 'unknown'
                if group not in by_group:
                    by_group[group] = []
                by_group[group].append((instr, encoding))

        # Generate test file for each group
        for group, entries in sorted(by_group.items()):
            test_file = test_dir / f"test_{group}.cpp"
            self._generate_encoding_group_tests(group, entries, test_file)
            print(f"Generated test_{group}.cpp ({len(entries)} encodings)")

    def _generate_encoding_group_tests(self, group_name: str, entries: list, output_file: Path):
        """Generate test file for a format group with one test per encoding."""
        code = self._license_header()
        code.append("#include \"veda64.hpp\"")
        code.append("#include <cassert>")
        code.append("#include <iostream>")
        code.append("")
        code.append("using namespace veda64;")
        code.append("")

        test_funcs = []
        seen_names = set()

        for instr, encoding in entries:
            if not encoding.name:
                continue

            func_name = self._sanitize_function_name(encoding.name)
            if func_name in seen_names:
                continue
            seen_names.add(func_name)

            # Compute instruction value with fixed bits set, variable bits = 0
            _, fields, _, _, full_pattern, _ = self._generate_encoding_struct(instr, encoding)

            if full_pattern is None:
                continue

            # Adjust test pattern to avoid Decode_UNDEF conditions
            full_pattern = self._adjust_test_pattern_for_undef(
                full_pattern, fields, encoding.decode_ps)

            # Predict operand types
            predicted = self._predict_operand_types(instr, encoding)

            test_funcs.append(func_name)

            code.append(f"void test_{func_name}() {{")
            code.append(f"    uint32_t insn = 0x{full_pattern:08X}u;")
            code.append(f"    auto result = decode(insn);")
            code.append(f"    assert(result.has_value()); (void)result;")

            if instr.mnemonic and instr.mnemonic not in {
                'ORR', 'SUBS', 'SUB', 'ADDS', 'AND', 'ANDS', 'BFM', 'UBFM', 'SBFM',
                'CSINC', 'CSINV', 'CSNEG', 'MOVN', 'MOVZ', 'ORN', 'HINT', 'SYS', 'SYSL',
                'EXTR', 'MADD', 'MSUB',
            }:
                code.append(f"    assert(result->mnemonic == Mnemonic::{instr.mnemonic});")

            if predicted:
                code.append(f"    assert(result->operands.size() >= {len(predicted)});")
                for idx, op_type in enumerate(predicted):
                    code.append(f"    assert(result->operands[{idx}].type == OperandType::{op_type});")

            code.append(f"    std::cout << \"  {func_name}: \" << result->to_string() << std::endl;")
            code.append(f"}}")
            code.append("")

        # Generate main function
        code.append("int main() {")
        code.append(f"    std::cout << \"Running {group_name} encoding tests ({len(test_funcs)} encodings)...\" << std::endl;")
        code.append(f"    int failed = 0;")
        code.append("")

        for func_name in test_funcs:
            code.append(f"    try {{ test_{func_name}(); }} catch (...) {{ std::cerr << \"FAIL: {func_name}\" << std::endl; failed++; }}")

        code.append("")
        code.append(f"    std::cout << ({len(test_funcs)} - failed) << \" / {len(test_funcs)} passed\" << std::endl;")
        code.append(f"    return failed;")
        code.append("}")
        code.append("")

        self._write_file(output_file, code)

    def generate_undef_tests(self, test_dir: Path):
        """Generate test_undef.cpp: verify that Decode_UNDEF conditions return nullopt."""
        import re

        code = self._license_header()
        code.append("#include \"veda64.hpp\"")
        code.append("#include <cassert>")
        code.append("#include <iostream>")
        code.append("")
        code.append("using namespace veda64;")
        code.append("")

        test_funcs = []
        seen = set()

        for instr in self.instructions:
            for encoding in instr.encodings:
                if not encoding.name or not encoding.decode_ps:
                    continue

                # Get encoding struct info (needed below for field positions and fixed values)
                _, fields, _, _, full_pattern, _ = self._generate_encoding_struct(instr, encoding)
                if full_pattern is None:
                    continue

                # Build fixed field values for guard check
                _fixed_vals_undef = {}
                for f in fields:
                    if f.get('is_fixed') and 'fixed' in f:
                        _fixed_vals_undef[f.get('original_name', f.get('name', ''))] = f['fixed']

                def _undef_is_guarded(match_pos, ps_text):
                    """Check if UNDEF at match_pos is inside an outer if that's always false."""
                    text_before = ps_text[:match_pos]
                    for outer in re.finditer(r"if\s+([\w:]+)\s*(==|!=)\s*'([01]+)'\s+then", text_before):
                        remaining = ps_text[outer.end():match_pos]
                        depth = 1
                        for nested in re.finditer(r'\bif\b.*?\bthen\b|\bend;', remaining):
                            tok = nested.group()
                            if 'then' in tok and tok.strip().startswith('if'):
                                depth += 1
                            elif 'end;' in tok:
                                depth -= 1
                                if depth <= 0:
                                    break
                        if depth <= 0:
                            continue
                        parts = outer.group(1).split('::')
                        concat = ''
                        all_fixed = True
                        for part in parts:
                            if part in _fixed_vals_undef:
                                concat += _fixed_vals_undef[part]
                            else:
                                all_fixed = False
                                break
                        if all_fixed:
                            op = outer.group(2)
                            bits_val = outer.group(3)
                            if (op == '==' and concat != bits_val) or (op == '!=' and concat == bits_val):
                                return True
                    return False

                # Find simple UNDEF conditions: if FIELD == 'BITS' then EndOfDecode(Decode_UNDEF)
                undef_conditions = []
                for m in re.finditer(
                    r"if\s+(\w+)\s*==\s*'([01]+)'\s+then\s+EndOfDecode\(Decode_UNDEF\)",
                    encoding.decode_ps
                ):
                    if not _undef_is_guarded(m.start(), encoding.decode_ps):
                        undef_conditions.append((m.group(1), m.group(2)))

                if not undef_conditions:
                    continue

                # Build field info: name → (lsb, width)
                field_info = {}
                for f in fields:
                    name = f.get('original_name') or f.get('name', '')
                    if name and not f.get('is_fixed', False):
                        field_info[name] = (f['lobit'], f['width'])

                for field, bits in undef_conditions:
                    if field not in field_info:
                        continue

                    lsb, width = field_info[field]
                    undef_val = int(bits, 2)

                    # Build test instruction: base pattern with field set to UNDEF value
                    test_insn = full_pattern
                    mask = ((1 << width) - 1) << lsb
                    test_insn = (test_insn & ~mask) | (undef_val << lsb)

                    func_name = f"{self._sanitize_function_name(encoding.name)}_{field}_eq_{bits}"
                    if func_name in seen:
                        continue
                    seen.add(func_name)

                    test_funcs.append(func_name)
                    code.append(f"void test_{func_name}() {{")
                    code.append(f"    // {encoding.name}: {field}=='{bits}' should be UNDEFINED")
                    code.append(f"    uint32_t insn = 0x{test_insn:08X}u;")
                    code.append(f"    auto result = decode(insn);")
                    code.append(f"    assert(!result.has_value());")
                    code.append(f"}}")
                    code.append("")

        # main()
        code.append("int main() {")
        code.append(f"    std::cout << \"Running undef tests ({len(test_funcs)} cases)...\" << std::endl;")
        code.append(f"    int failed = 0;")
        code.append("")
        for func_name in test_funcs:
            code.append(f"    try {{ test_{func_name}(); }} catch (...) {{ std::cerr << \"FAIL: {func_name}\" << std::endl; failed++; }}")
        code.append("")
        code.append(f"    std::cout << ({len(test_funcs)} - failed) << \" / {len(test_funcs)} passed\" << std::endl;")
        code.append(f"    return failed;")
        code.append("}")
        code.append("")

        output_file = test_dir / "test_undef.cpp"
        self._write_file(output_file, code)
        print(f"Generated test_undef.cpp ({len(test_funcs)} undef cases)")

    def generate_disasm_tool(self, tools_dir: Path):
        """Generate the veda64-disasm tool."""
        tools_dir.mkdir(exist_ok=True)

        code = self._license_header()
        code.append("#include \"veda64.hpp\"")
        code.append("#include <iostream>")
        code.append("#include <cstdlib>")
        code.append("#include <cstring>")
        code.append("")
        code.append("using namespace veda64;")
        code.append("")
        code.append("// Byte swap for big-endian to little-endian conversion")
        code.append("inline uint32_t bswap32(uint32_t value) {")
        code.append("    return ((value & 0xFF000000u) >> 24) |")
        code.append("           ((value & 0x00FF0000u) >> 8)  |")
        code.append("           ((value & 0x0000FF00u) << 8)  |")
        code.append("           ((value & 0x000000FFu) << 24);")
        code.append("}")
        code.append("")
        code.append("// Parse a uint32_t from string")
        code.append("bool parse_instruction(const char* str, uint32_t& value) {")
        code.append("    char* endptr;")
        code.append("")
        code.append("    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {")
        code.append("        value = static_cast<uint32_t>(std::strtoul(str + 2, &endptr, 16));")
        code.append("    } else if (str[0] == '0' && (str[1] == 'b' || str[1] == 'B')) {")
        code.append("        value = static_cast<uint32_t>(std::strtoul(str + 2, &endptr, 2));")
        code.append("    } else {")
        code.append("        value = static_cast<uint32_t>(std::strtoul(str, &endptr, 0));")
        code.append("    }")
        code.append("")
        code.append("    return *endptr == '\\0';")
        code.append("}")
        code.append("")
        code.append("void print_usage(const char* progname) {")
        code.append("    std::cerr << \"Usage: \" << progname << \" [options] <instruction> [instruction...]\\n\";")
        code.append("    std::cerr << \"\\n\";")
        code.append("    std::cerr << \"Disassemble one or more ARM64 instructions.\\n\";")
        code.append("    std::cerr << \"\\n\";")
        code.append("    std::cerr << \"Options:\\n\";")
        code.append("    std::cerr << \"  -b, --big-endian  Input values are in big-endian byte order\\n\";")
        code.append("    std::cerr << \"  -h, --help        Show this help message\\n\";")
        code.append("    std::cerr << \"\\n\";")
        code.append("    std::cerr << \"Arguments:\\n\";")
        code.append("    std::cerr << \"  instruction       32-bit instruction value\\n\";")
        code.append("    std::cerr << \"                    (hex: 0x..., binary: 0b..., or decimal)\\n\";")
        code.append("    std::cerr << \"\\n\";")
        code.append("    std::cerr << \"Examples:\\n\";")
        code.append("    std::cerr << \"  \" << progname << \" 0xd503237f              # PACIBSP (little-endian)\\n\";")
        code.append("    std::cerr << \"  \" << progname << \" 0xd65f03c0              # RET (little-endian)\\n\";")
        code.append("    std::cerr << \"  \" << progname << \" -b 0x7f2303d5           # PACIBSP (big-endian)\\n\";")
        code.append("    std::cerr << \"  \" << progname << \" -b 0x7f2303d5 0xff2303d5  # Multiple (big-endian)\\n\";")
        code.append("}")
        code.append("")
        code.append("int main(int argc, char* argv[]) {")
        code.append("    if (argc < 2) {")
        code.append("        print_usage(argv[0]);")
        code.append("        return 1;")
        code.append("    }")
        code.append("")
        code.append("    bool big_endian = false;")
        code.append("    int start_idx = 1;")
        code.append("")
        code.append("    // Parse options")
        code.append("    while (start_idx < argc && argv[start_idx][0] == '-') {")
        code.append("        if (std::strcmp(argv[start_idx], \"-b\") == 0 || std::strcmp(argv[start_idx], \"--big-endian\") == 0) {")
        code.append("            big_endian = true;")
        code.append("            start_idx++;")
        code.append("        } else if (std::strcmp(argv[start_idx], \"-h\") == 0 || std::strcmp(argv[start_idx], \"--help\") == 0) {")
        code.append("            print_usage(argv[0]);")
        code.append("            return 0;")
        code.append("        } else {")
        code.append("            std::cerr << \"Error: Unknown option: \" << argv[start_idx] << \"\\n\\n\";")
        code.append("            print_usage(argv[0]);")
        code.append("            return 1;")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    if (start_idx >= argc) {")
        code.append("        std::cerr << \"Error: No instruction values provided\\n\\n\";")
        code.append("        print_usage(argv[0]);")
        code.append("        return 1;")
        code.append("    }")
        code.append("")
        code.append("    int errors = 0;")
        code.append("")
        code.append("    for (int i = start_idx; i < argc; i++) {")
        code.append("        uint32_t insn;")
        code.append("")
        code.append("        if (!parse_instruction(argv[i], insn)) {")
        code.append("            std::cerr << \"Error: Invalid instruction value: \" << argv[i] << \"\\n\";")
        code.append("            errors++;")
        code.append("            continue;")
        code.append("        }")
        code.append("")
        code.append("        // Convert from big-endian to little-endian if needed")
        code.append("        if (big_endian) {")
        code.append("            insn = bswap32(insn);")
        code.append("        }")
        code.append("")
        code.append("        auto result = decode(insn);")
        code.append("")
        code.append("        if (result) {")
        code.append("            std::cout << \"0x\" << std::hex << (big_endian ? bswap32(insn) : insn) << std::dec << \": \" << result->to_string() << \"\\n\";")
        code.append("        } else {")
        code.append("            std::cout << \"0x\" << std::hex << (big_endian ? bswap32(insn) : insn) << std::dec << \": <unknown>\\n\";")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    return errors > 0 ? 1 : 0;")
        code.append("}")
        code.append("")

        output_file = tools_dir / "veda64-disasm.cpp"
        self._write_file(output_file, code)
        print(f"Generated {output_file.name}")

    def generate_hook_files(self, include_dir: Path, lib_dir: Path):
        """Generate hook.cpp for Windows ARM64 API hooking."""
        self._generate_hook_implementation(lib_dir)

    def _generate_hook_implementation(self, lib_dir: Path):
        """Generate hook.cpp implementation file."""
        code = self._license_header()
        code.append("")
        code.append("#include \"veda64.hpp\"")
        code.append("")
        code.append("// Only compile when hooks are enabled")
        code.append("#if !defined(VEDA64_NO_HOOKS) && (defined(_WIN32) || defined(VEDA64_HOOK_SUPPORT))")
        code.append("")
        code.append("#include <Windows.h>")
        code.append("#include <vector>")
        code.append("#include <unordered_map>")
        code.append("#include <mutex>")
        code.append("#include <algorithm>")
        code.append("#include <cstring>")
        code.append("#include <cstdio>")
        code.append("")
        code.append("// ============================================================================")
        code.append("// NT API Definitions (minimal, avoiding winternl.h conflicts)")
        code.append("// ============================================================================")
        code.append("")
        code.append("// NT status codes")
        code.append("#ifndef STATUS_SUCCESS")
        code.append("#define STATUS_SUCCESS ((NTSTATUS)0x00000000L)")
        code.append("#endif")
        code.append("")
        code.append("#ifndef STATUS_INFO_LENGTH_MISMATCH")
        code.append("#define STATUS_INFO_LENGTH_MISMATCH ((NTSTATUS)0xC0000004L)")
        code.append("#endif")
        code.append("")
        code.append("// Pseudo handles")
        code.append("#ifndef NtCurrentProcess")
        code.append("#define NtCurrentProcess() ((HANDLE)(LONG_PTR)-1)")
        code.append("#endif")
        code.append("#ifndef NtCurrentThread")
        code.append("#define NtCurrentThread() ((HANDLE)(LONG_PTR)-2)")
        code.append("#endif")
        code.append("")
        code.append("// Local type definitions to avoid SDK conflicts")
        code.append("namespace veda64_nt {")
        code.append("")
        code.append("// Unicode string structure")
        code.append("struct UNICODE_STRING {")
        code.append("    USHORT Length;")
        code.append("    USHORT MaximumLength;")
        code.append("    PWSTR Buffer;")
        code.append("};")
        code.append("")
        code.append("// Client ID structure")
        code.append("struct CLIENT_ID {")
        code.append("    HANDLE UniqueProcess;")
        code.append("    HANDLE UniqueThread;")
        code.append("};")
        code.append("")
        code.append("// Object attributes")
        code.append("struct OBJECT_ATTRIBUTES {")
        code.append("    ULONG Length;")
        code.append("    HANDLE RootDirectory;")
        code.append("    void* ObjectName;  // PUNICODE_STRING")
        code.append("    ULONG Attributes;")
        code.append("    PVOID SecurityDescriptor;")
        code.append("    PVOID SecurityQualityOfService;")
        code.append("};")
        code.append("")
        code.append("// System basic information")
        code.append("struct SYSTEM_BASIC_INFORMATION {")
        code.append("    ULONG Reserved;")
        code.append("    ULONG TimerResolution;")
        code.append("    ULONG PageSize;")
        code.append("    ULONG NumberOfPhysicalPages;")
        code.append("    ULONG LowestPhysicalPageNumber;")
        code.append("    ULONG HighestPhysicalPageNumber;")
        code.append("    ULONG AllocationGranularity;")
        code.append("    ULONG_PTR MinimumUserModeAddress;")
        code.append("    ULONG_PTR MaximumUserModeAddress;")
        code.append("    ULONG_PTR ActiveProcessorsAffinityMask;")
        code.append("    ULONG NumberOfProcessors;")
        code.append("};")
        code.append("")
        code.append("// System thread information (within process info)")
        code.append("struct SYSTEM_THREAD_INFORMATION {")
        code.append("    LARGE_INTEGER KernelTime;")
        code.append("    LARGE_INTEGER UserTime;")
        code.append("    LARGE_INTEGER CreateTime;")
        code.append("    ULONG WaitTime;")
        code.append("    PVOID StartAddress;")
        code.append("    CLIENT_ID ClientId;")
        code.append("    LONG Priority;")
        code.append("    LONG BasePriority;")
        code.append("    ULONG ContextSwitches;")
        code.append("    ULONG ThreadState;")
        code.append("    ULONG WaitReason;")
        code.append("};")
        code.append("")
        code.append("// System process information")
        code.append("struct SYSTEM_PROCESS_INFORMATION {")
        code.append("    ULONG NextEntryOffset;")
        code.append("    ULONG NumberOfThreads;")
        code.append("    LARGE_INTEGER WorkingSetPrivateSize;")
        code.append("    ULONG HardFaultCount;")
        code.append("    ULONG NumberOfThreadsHighWatermark;")
        code.append("    ULONGLONG CycleTime;")
        code.append("    LARGE_INTEGER CreateTime;")
        code.append("    LARGE_INTEGER UserTime;")
        code.append("    LARGE_INTEGER KernelTime;")
        code.append("    UNICODE_STRING ImageName;")
        code.append("    LONG BasePriority;")
        code.append("    HANDLE UniqueProcessId;")
        code.append("    HANDLE InheritedFromUniqueProcessId;")
        code.append("    ULONG HandleCount;")
        code.append("    ULONG SessionId;")
        code.append("    ULONG_PTR UniqueProcessKey;")
        code.append("    SIZE_T PeakVirtualSize;")
        code.append("    SIZE_T VirtualSize;")
        code.append("    ULONG PageFaultCount;")
        code.append("    SIZE_T PeakWorkingSetSize;")
        code.append("    SIZE_T WorkingSetSize;")
        code.append("    SIZE_T QuotaPeakPagedPoolUsage;")
        code.append("    SIZE_T QuotaPagedPoolUsage;")
        code.append("    SIZE_T QuotaPeakNonPagedPoolUsage;")
        code.append("    SIZE_T QuotaNonPagedPoolUsage;")
        code.append("    SIZE_T PagefileUsage;")
        code.append("    SIZE_T PeakPagefileUsage;")
        code.append("    SIZE_T PrivatePageCount;")
        code.append("    LARGE_INTEGER ReadOperationCount;")
        code.append("    LARGE_INTEGER WriteOperationCount;")
        code.append("    LARGE_INTEGER OtherOperationCount;")
        code.append("    LARGE_INTEGER ReadTransferCount;")
        code.append("    LARGE_INTEGER WriteTransferCount;")
        code.append("    LARGE_INTEGER OtherTransferCount;")
        code.append("    SYSTEM_THREAD_INFORMATION Threads[1];")
        code.append("};")
        code.append("")
        code.append("// System information class values")
        code.append("constexpr ULONG SystemBasicInformation = 0;")
        code.append("constexpr ULONG SystemProcessInformation = 5;")
        code.append("")
        code.append("} // namespace veda64_nt")
        code.append("")
        code.append("// ============================================================================")
        code.append("// NT API Static Imports (linked against ntdll.lib)")
        code.append("// ============================================================================")
        code.append("")
        code.append("extern \"C\" {")
        code.append("")
        code.append("NTSYSAPI NTSTATUS NTAPI NtAllocateVirtualMemory(")
        code.append("    HANDLE ProcessHandle,")
        code.append("    PVOID* BaseAddress,")
        code.append("    ULONG_PTR ZeroBits,")
        code.append("    PSIZE_T RegionSize,")
        code.append("    ULONG AllocationType,")
        code.append("    ULONG Protect")
        code.append(");")
        code.append("")
        code.append("NTSYSAPI NTSTATUS NTAPI NtFreeVirtualMemory(")
        code.append("    HANDLE ProcessHandle,")
        code.append("    PVOID* BaseAddress,")
        code.append("    PSIZE_T RegionSize,")
        code.append("    ULONG FreeType")
        code.append(");")
        code.append("")
        code.append("NTSYSAPI NTSTATUS NTAPI NtProtectVirtualMemory(")
        code.append("    HANDLE ProcessHandle,")
        code.append("    PVOID* BaseAddress,")
        code.append("    PSIZE_T RegionSize,")
        code.append("    ULONG NewProtect,")
        code.append("    PULONG OldProtect")
        code.append(");")
        code.append("")
        code.append("NTSYSAPI NTSTATUS NTAPI NtFlushInstructionCache(")
        code.append("    HANDLE ProcessHandle,")
        code.append("    PVOID BaseAddress,")
        code.append("    SIZE_T Length")
        code.append(");")
        code.append("")
        code.append("NTSYSAPI NTSTATUS NTAPI NtQuerySystemInformation(")
        code.append("    ULONG SystemInformationClass,")
        code.append("    PVOID SystemInformation,")
        code.append("    ULONG SystemInformationLength,")
        code.append("    PULONG ReturnLength")
        code.append(");")
        code.append("")
        code.append("NTSYSAPI NTSTATUS NTAPI NtOpenThread(")
        code.append("    PHANDLE ThreadHandle,")
        code.append("    ACCESS_MASK DesiredAccess,")
        code.append("    veda64_nt::OBJECT_ATTRIBUTES* ObjectAttributes,")
        code.append("    veda64_nt::CLIENT_ID* ClientId")
        code.append(");")
        code.append("")
        code.append("NTSYSAPI NTSTATUS NTAPI NtSuspendThread(")
        code.append("    HANDLE ThreadHandle,")
        code.append("    PULONG PreviousSuspendCount")
        code.append(");")
        code.append("")
        code.append("NTSYSAPI NTSTATUS NTAPI NtResumeThread(")
        code.append("    HANDLE ThreadHandle,")
        code.append("    PULONG PreviousSuspendCount")
        code.append(");")
        code.append("")
        code.append("NTSYSAPI NTSTATUS NTAPI NtClose(")
        code.append("    HANDLE Handle")
        code.append(");")
        code.append("")
        code.append("} // extern \"C\"")
        code.append("")
        code.append("// Global allocation granularity (queried once at init)")
        code.append("static ULONG g_AllocationGranularity = 0x10000;  // Default 64KB")
        code.append("")
        code.append("// Initialize allocation granularity from system info")
        code.append("static void init_allocation_granularity() {")
        code.append("    static bool initialized = false;")
        code.append("    if (initialized) return;")
        code.append("")
        code.append("    veda64_nt::SYSTEM_BASIC_INFORMATION sbi = {};")
        code.append("    ULONG len = 0;")
        code.append("    if (NtQuerySystemInformation(veda64_nt::SystemBasicInformation, &sbi, sizeof(sbi), &len) == STATUS_SUCCESS) {")
        code.append("        g_AllocationGranularity = sbi.AllocationGranularity;")
        code.append("    }")
        code.append("    initialized = true;")
        code.append("}")
        code.append("")
        code.append("// Get current thread ID using TEB (ARM64: x18 register)")
        code.append("static DWORD nt_get_current_thread_id() {")
        code.append("    return GetCurrentThreadId();  // Fallback to Win32 for compatibility")
        code.append("}")
        code.append("")
        code.append("// Get current process ID using TEB")
        code.append("static DWORD nt_get_current_process_id() {")
        code.append("    return GetCurrentProcessId();  // Fallback to Win32 for compatibility")
        code.append("}")
        code.append("")
        code.append("namespace veda64 {")
        code.append("namespace hook {")
        code.append("")
        code.append("// ============================================================================")
        code.append("// Internal structures")
        code.append("// ============================================================================")
        code.append("")
        code.append("// Trampoline structure - holds relocated instructions + jump back")
        code.append("struct Trampoline {")
        code.append("    uint8_t* code;           // Executable memory for trampoline")
        code.append("    size_t code_size;        // Total allocated size")
        code.append("    size_t used_size;        // Actually used bytes")
        code.append("    size_t insn_count;       // Number of relocated instructions")
        code.append("};")
        code.append("")
        code.append("// Hook context - complete hook state")
        code.append("struct HookContext {")
        code.append("    void* target;            // Original function address")
        code.append("    void* detour;            // Hook function address")
        code.append("    Trampoline trampoline;   // Trampoline for calling original")
        code.append("")
        code.append("    uint8_t original_bytes[32];  // Saved original bytes")
        code.append("    uint8_t hook_bytes[32];      // Hook jump sequence")
        code.append("    size_t hook_size;            // Size of hook (bytes overwritten)")
        code.append("")
        code.append("    bool enabled;            // Is hook currently active?")
        code.append("    bool valid;              // Is hook context valid?")
        code.append("};")
        code.append("")
        code.append("// Global state")
        code.append("struct HookState {")
        code.append("    bool initialized = false;")
        code.append("    HookConfig config;")
        code.append("    std::mutex mutex;")
        code.append("    std::vector<HookContext*> hooks;")
        code.append("    std::unordered_map<void*, HookContext*> target_map;")
        code.append("};")
        code.append("")
        code.append("static HookState g_state;")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("// ============================================================================")
        code.append("// Status to string")
        code.append("// ============================================================================")
        code.append("")
        code.append("const char* status_to_string(HookStatus status) {")
        code.append("    switch (status) {")
        code.append("        case HookStatus::Success: return \"Success\";")
        code.append("        case HookStatus::NotInitialized: return \"Hooking subsystem not initialized\";")
        code.append("        case HookStatus::InvalidTarget: return \"Invalid target address\";")
        code.append("        case HookStatus::InvalidDetour: return \"Invalid detour address\";")
        code.append("        case HookStatus::AllocationFailed: return \"Memory allocation failed\";")
        code.append("        case HookStatus::ProtectionFailed: return \"Memory protection change failed\";")
        code.append("        case HookStatus::DisassemblyFailed: return \"Instruction disassembly failed\";")
        code.append("        case HookStatus::RelocationFailed: return \"Instruction relocation failed\";")
        code.append("        case HookStatus::InstructionTooComplex: return \"Instruction too complex to relocate\";")
        code.append("        case HookStatus::HookAlreadyInstalled: return \"Hook already installed at target\";")
        code.append("        case HookStatus::HookNotFound: return \"Hook not found\";")
        code.append("        case HookStatus::HookDisabled: return \"Hook is disabled\";")
        code.append("        case HookStatus::InternalError: return \"Internal error\";")
        code.append("        default: return \"Unknown error\";")
        code.append("    }")
        code.append("}")
        code.append("#endif // VEDA64_NO_STRINGS")
        code.append("")
        code.append("// ============================================================================")
        code.append("// Configuration")
        code.append("// ============================================================================")
        code.append("")
        code.append("void set_config(const HookConfig& config) {")
        code.append("    std::lock_guard<std::mutex> lock(g_state.mutex);")
        code.append("    g_state.config = config;")
        code.append("}")
        code.append("")
        code.append("HookConfig get_config() {")
        code.append("    std::lock_guard<std::mutex> lock(g_state.mutex);")
        code.append("    return g_state.config;")
        code.append("}")
        code.append("")
        code.append("// ============================================================================")
        code.append("// Initialization")
        code.append("// ============================================================================")
        code.append("")
        code.append("HookStatus initialize() {")
        code.append("    std::lock_guard<std::mutex> lock(g_state.mutex);")
        code.append("")
        code.append("    if (g_state.initialized) {")
        code.append("        return HookStatus::Success;")
        code.append("    }")
        code.append("")
        code.append("    // Initialize allocation granularity from system info")
        code.append("    init_allocation_granularity();")
        code.append("")
        code.append("    // Set default config")
        code.append("    g_state.config = HookConfig{};")
        code.append("    g_state.initialized = true;")
        code.append("")
        code.append("    return HookStatus::Success;")
        code.append("}")
        code.append("")
        code.append("void shutdown() {")
        code.append("    std::lock_guard<std::mutex> lock(g_state.mutex);")
        code.append("")
        code.append("    if (!g_state.initialized) {")
        code.append("        return;")
        code.append("    }")
        code.append("")
        code.append("    // Remove all hooks (unlock to avoid deadlock)")
        code.append("    g_state.mutex.unlock();")
        code.append("    remove_all();")
        code.append("    g_state.mutex.lock();")
        code.append("")
        code.append("    g_state.initialized = false;")
        code.append("}")
        code.append("")
        code.append("bool is_initialized() {")
        code.append("    std::lock_guard<std::mutex> lock(g_state.mutex);")
        code.append("    return g_state.initialized;")
        code.append("}")
        code.append("")
        code.append("// ============================================================================")
        code.append("// Low-level memory operations (using NT syscalls)")
        code.append("// ============================================================================")
        code.append("")
        code.append("namespace detail {")
        code.append("")
        code.append("void* alloc_executable_near(void* target, size_t size) {")
        code.append("    // Try to allocate RWX memory near the target for PC-relative instructions")
        code.append("    // We need to be within ±4GB for ADRP, ±128MB for B/BL")
        code.append("")
        code.append("    uintptr_t alloc_granularity = g_AllocationGranularity;")
        code.append("    uintptr_t target_addr = reinterpret_cast<uintptr_t>(target);")
        code.append("")
        code.append("    // Try to allocate within ±2GB of target (safe range for ADRP)")
        code.append("    // Search in both directions")
        code.append("    for (uintptr_t offset = alloc_granularity; offset < 0x7FFFFFFF; offset += alloc_granularity) {")
        code.append("        // Try above target")
        code.append("        if (target_addr + offset > target_addr) {  // Check for overflow")
        code.append("            PVOID base_addr = reinterpret_cast<PVOID>((target_addr + offset) & ~(alloc_granularity - 1));")
        code.append("            SIZE_T region_size = size;")
        code.append("            NTSTATUS status = NtAllocateVirtualMemory(")
        code.append("                NtCurrentProcess(),")
        code.append("                &base_addr,")
        code.append("                0,")
        code.append("                &region_size,")
        code.append("                MEM_COMMIT | MEM_RESERVE,")
        code.append("                PAGE_EXECUTE_READWRITE")
        code.append("            );")
        code.append("            if (status == STATUS_SUCCESS) return base_addr;")
        code.append("        }")
        code.append("")
        code.append("        // Try below target")
        code.append("        if (target_addr > offset) {  // Check for underflow")
        code.append("            PVOID base_addr = reinterpret_cast<PVOID>((target_addr - offset) & ~(alloc_granularity - 1));")
        code.append("            SIZE_T region_size = size;")
        code.append("            NTSTATUS status = NtAllocateVirtualMemory(")
        code.append("                NtCurrentProcess(),")
        code.append("                &base_addr,")
        code.append("                0,")
        code.append("                &region_size,")
        code.append("                MEM_COMMIT | MEM_RESERVE,")
        code.append("                PAGE_EXECUTE_READWRITE")
        code.append("            );")
        code.append("            if (status == STATUS_SUCCESS) return base_addr;")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // Fall back to any location")
        code.append("    PVOID base_addr = nullptr;")
        code.append("    SIZE_T region_size = size;")
        code.append("    NTSTATUS status = NtAllocateVirtualMemory(")
        code.append("        NtCurrentProcess(),")
        code.append("        &base_addr,")
        code.append("        0,")
        code.append("        &region_size,")
        code.append("        MEM_COMMIT | MEM_RESERVE,")
        code.append("        PAGE_EXECUTE_READWRITE")
        code.append("    );")
        code.append("    return (status == STATUS_SUCCESS) ? base_addr : nullptr;")
        code.append("}")
        code.append("")
        code.append("void* alloc_executable(size_t size) {")
        code.append("    // Standard allocation (may be far from target)")
        code.append("    PVOID base_addr = nullptr;")
        code.append("    SIZE_T region_size = size;")
        code.append("    NTSTATUS status = NtAllocateVirtualMemory(")
        code.append("        NtCurrentProcess(),")
        code.append("        &base_addr,")
        code.append("        0,")
        code.append("        &region_size,")
        code.append("        MEM_COMMIT | MEM_RESERVE,")
        code.append("        PAGE_EXECUTE_READWRITE")
        code.append("    );")
        code.append("    return (status == STATUS_SUCCESS) ? base_addr : nullptr;")
        code.append("}")
        code.append("")
        code.append("void free_executable(void* ptr, size_t /* size */) {")
        code.append("    if (ptr) {")
        code.append("        PVOID base_addr = ptr;")
        code.append("        SIZE_T region_size = 0;")
        code.append("        NtFreeVirtualMemory(NtCurrentProcess(), &base_addr, &region_size, MEM_RELEASE);")
        code.append("    }")
        code.append("}")
        code.append("")
        code.append("uint32_t make_writable(void* addr, size_t size) {")
        code.append("    PVOID base_addr = addr;")
        code.append("    SIZE_T region_size = size;")
        code.append("    ULONG old_protect = 0;")
        code.append("    NtProtectVirtualMemory(NtCurrentProcess(), &base_addr, &region_size, PAGE_EXECUTE_READWRITE, &old_protect);")
        code.append("    return static_cast<uint32_t>(old_protect);")
        code.append("}")
        code.append("")
        code.append("void restore_protection(void* addr, size_t size, uint32_t old_protect) {")
        code.append("    PVOID base_addr = addr;")
        code.append("    SIZE_T region_size = size;")
        code.append("    ULONG dummy = 0;")
        code.append("    NtProtectVirtualMemory(NtCurrentProcess(), &base_addr, &region_size, static_cast<ULONG>(old_protect), &dummy);")
        code.append("}")
        code.append("")
        code.append("void flush_icache(void* addr, size_t size) {")
        code.append("    NtFlushInstructionCache(NtCurrentProcess(), addr, size);")
        code.append("}")
        code.append("")
        code.append("void suspend_threads() {")
        code.append("    DWORD current_tid = nt_get_current_thread_id();")
        code.append("    DWORD pid = nt_get_current_process_id();")
        code.append("")
        code.append("    // Query process/thread information using NtQuerySystemInformation")
        code.append("    ULONG buffer_size = 1024 * 1024;  // Start with 1MB")
        code.append("    std::vector<BYTE> buffer(buffer_size);")
        code.append("    ULONG return_length = 0;")
        code.append("")
        code.append("    NTSTATUS status;")
        code.append("    while ((status = NtQuerySystemInformation(")
        code.append("        veda64_nt::SystemProcessInformation,")
        code.append("        buffer.data(),")
        code.append("        static_cast<ULONG>(buffer.size()),")
        code.append("        &return_length)) == STATUS_INFO_LENGTH_MISMATCH) {")
        code.append("        buffer.resize(return_length + 4096);")
        code.append("    }")
        code.append("")
        code.append("    if (status != STATUS_SUCCESS) {")
        code.append("        return;")
        code.append("    }")
        code.append("")
        code.append("    // Find our process and enumerate its threads")
        code.append("    auto* proc_info = reinterpret_cast<veda64_nt::SYSTEM_PROCESS_INFORMATION*>(buffer.data());")
        code.append("    while (true) {")
        code.append("        if (HandleToULong(proc_info->UniqueProcessId) == pid) {")
        code.append("            // Found our process, enumerate threads")
        code.append("            for (ULONG i = 0; i < proc_info->NumberOfThreads; ++i) {")
        code.append("                DWORD tid = HandleToULong(proc_info->Threads[i].ClientId.UniqueThread);")
        code.append("                if (tid != current_tid) {")
        code.append("                    // Open and suspend this thread")
        code.append("                    HANDLE thread_handle = nullptr;")
        code.append("                    veda64_nt::OBJECT_ATTRIBUTES obj_attr = {};")
        code.append("                    obj_attr.Length = sizeof(obj_attr);")
        code.append("                    veda64_nt::CLIENT_ID client_id = {};")
        code.append("                    client_id.UniqueThread = ULongToHandle(tid);")
        code.append("")
        code.append("                    if (NtOpenThread(&thread_handle, THREAD_SUSPEND_RESUME, &obj_attr, &client_id) == STATUS_SUCCESS) {")
        code.append("                        NtSuspendThread(thread_handle, nullptr);")
        code.append("                        NtClose(thread_handle);")
        code.append("                    }")
        code.append("                }")
        code.append("            }")
        code.append("            break;")
        code.append("        }")
        code.append("")
        code.append("        if (proc_info->NextEntryOffset == 0) break;")
        code.append("        proc_info = reinterpret_cast<veda64_nt::SYSTEM_PROCESS_INFORMATION*>(")
        code.append("            reinterpret_cast<BYTE*>(proc_info) + proc_info->NextEntryOffset);")
        code.append("    }")
        code.append("}")
        code.append("")
        code.append("void resume_threads() {")
        code.append("    DWORD current_tid = nt_get_current_thread_id();")
        code.append("    DWORD pid = nt_get_current_process_id();")
        code.append("")
        code.append("    // Query process/thread information using NtQuerySystemInformation")
        code.append("    ULONG buffer_size = 1024 * 1024;  // Start with 1MB")
        code.append("    std::vector<BYTE> buffer(buffer_size);")
        code.append("    ULONG return_length = 0;")
        code.append("")
        code.append("    NTSTATUS status;")
        code.append("    while ((status = NtQuerySystemInformation(")
        code.append("        veda64_nt::SystemProcessInformation,")
        code.append("        buffer.data(),")
        code.append("        static_cast<ULONG>(buffer.size()),")
        code.append("        &return_length)) == STATUS_INFO_LENGTH_MISMATCH) {")
        code.append("        buffer.resize(return_length + 4096);")
        code.append("    }")
        code.append("")
        code.append("    if (status != STATUS_SUCCESS) {")
        code.append("        return;")
        code.append("    }")
        code.append("")
        code.append("    // Find our process and enumerate its threads")
        code.append("    auto* proc_info = reinterpret_cast<veda64_nt::SYSTEM_PROCESS_INFORMATION*>(buffer.data());")
        code.append("    while (true) {")
        code.append("        if (HandleToULong(proc_info->UniqueProcessId) == pid) {")
        code.append("            // Found our process, enumerate threads")
        code.append("            for (ULONG i = 0; i < proc_info->NumberOfThreads; ++i) {")
        code.append("                DWORD tid = HandleToULong(proc_info->Threads[i].ClientId.UniqueThread);")
        code.append("                if (tid != current_tid) {")
        code.append("                    // Open and resume this thread")
        code.append("                    HANDLE thread_handle = nullptr;")
        code.append("                    veda64_nt::OBJECT_ATTRIBUTES obj_attr = {};")
        code.append("                    obj_attr.Length = sizeof(obj_attr);")
        code.append("                    veda64_nt::CLIENT_ID client_id = {};")
        code.append("                    client_id.UniqueThread = ULongToHandle(tid);")
        code.append("")
        code.append("                    if (NtOpenThread(&thread_handle, THREAD_SUSPEND_RESUME, &obj_attr, &client_id) == STATUS_SUCCESS) {")
        code.append("                        NtResumeThread(thread_handle, nullptr);")
        code.append("                        NtClose(thread_handle);")
        code.append("                    }")
        code.append("                }")
        code.append("            }")
        code.append("            break;")
        code.append("        }")
        code.append("")
        code.append("        if (proc_info->NextEntryOffset == 0) break;")
        code.append("        proc_info = reinterpret_cast<veda64_nt::SYSTEM_PROCESS_INFORMATION*>(")
        code.append("            reinterpret_cast<BYTE*>(proc_info) + proc_info->NextEntryOffset);")
        code.append("    }")
        code.append("}")
        code.append("")
        code.append("// ============================================================================")
        code.append("// ARM64 instruction analysis and generation")
        code.append("// ============================================================================")
        code.append("")
        code.append("// ARM64 jump sequence using LDR + BR (16 bytes total)")
        code.append("// LDR X16, [PC, #8]   ; 0x58000050")
        code.append("// BR X16              ; 0xD61F0200")
        code.append("// .quad target        ; 8 bytes for address")
        code.append("size_t generate_jump(uint8_t* buffer, void* target) {")
        code.append("    uint32_t* insn = reinterpret_cast<uint32_t*>(buffer);")
        code.append("")
        code.append("    // LDR X16, [PC, #8] - load address from 8 bytes ahead")
        code.append("    insn[0] = 0x58000050;")
        code.append("")
        code.append("    // BR X16 - branch to register")
        code.append("    insn[1] = 0xD61F0200;")
        code.append("")
        code.append("    // 64-bit target address")
        code.append("    uint64_t* addr = reinterpret_cast<uint64_t*>(&insn[2]);")
        code.append("    *addr = reinterpret_cast<uint64_t>(target);")
        code.append("")
        code.append("    return 16;")
        code.append("}")
        code.append("")
        code.append("// ARM64 call sequence using LDR + BLR (16 bytes, returns to next insn)")
        code.append("size_t generate_call(uint8_t* buffer, void* target) {")
        code.append("    uint32_t* insn = reinterpret_cast<uint32_t*>(buffer);")
        code.append("")
        code.append("    // LDR X16, [PC, #8] - load address from 8 bytes ahead")
        code.append("    insn[0] = 0x58000050;")
        code.append("")
        code.append("    // BLR X16 - branch with link to register")
        code.append("    insn[1] = 0xD63F0200;")
        code.append("")
        code.append("    // 64-bit target address")
        code.append("    uint64_t* addr = reinterpret_cast<uint64_t*>(&insn[2]);")
        code.append("    *addr = reinterpret_cast<uint64_t>(target);")
        code.append("")
        code.append("    return 16;")
        code.append("}")
        code.append("")
        code.append("// Check if instruction is PC-relative")
        code.append("bool is_pc_relative(uint32_t insn) {")
        code.append("    // Use veda64 to decode the instruction")
        code.append("    auto decoded = decode(insn);")
        code.append("    if (!decoded) {")
        code.append("        return false;")
        code.append("    }")
        code.append("")
        code.append("    // Check for PC-relative instruction classes:")
        code.append("    // - B, BL (unconditional branch)")
        code.append("    // - B.cond (conditional branch)")
        code.append("    // - CBZ, CBNZ (compare and branch)")
        code.append("    // - TBZ, TBNZ (test and branch)")
        code.append("    // - ADR, ADRP (address calculation)")
        code.append("    // - LDR (literal) - loads from PC-relative address")
        code.append("")
        code.append("    switch (decoded->mnemonic) {")
        code.append("        // Unconditional branches")
        code.append("        case Mnemonic::B:")
        code.append("        case Mnemonic::BL:")
        code.append("        // Conditional branches (B.cond is encoded as BC in ARM64)")
        code.append("        case Mnemonic::BC:")
        code.append("        // Compare and branch")
        code.append("        case Mnemonic::CBZ:")
        code.append("        case Mnemonic::CBNZ:")
        code.append("        // Test and branch")
        code.append("        case Mnemonic::TBZ:")
        code.append("        case Mnemonic::TBNZ:")
        code.append("        // Address calculation")
        code.append("        case Mnemonic::ADR:")
        code.append("        case Mnemonic::ADRP:")
        code.append("            return true;")
        code.append("")
        code.append("        // LDR literal - check for PC-relative form")
        code.append("        case Mnemonic::LDR:")
        code.append("        case Mnemonic::LDRSW:")
        code.append("        case Mnemonic::PRFM:")
        code.append("            // PC-relative if has relative operand")
        code.append("            for (const auto& op : decoded->operands) {")
        code.append("                if (op.type == OperandType::Relative) {")
        code.append("                    return true;")
        code.append("                }")
        code.append("            }")
        code.append("            return false;")
        code.append("")
        code.append("        default:")
        code.append("            return false;")
        code.append("    }")
        code.append("}")
        code.append("")
        code.append("// Check if instruction can be safely relocated")
        code.append("bool can_relocate(uint32_t insn) {")
        code.append("    // Zero (UDF #0) is treated as padding, always safe to skip")
        code.append("    if (insn == 0) return true;")
        code.append("")
        code.append("    auto decoded = decode(insn);")
        code.append("    if (!decoded) {")
        code.append("        return false;")
        code.append("    }")
        code.append("")
        code.append("    // Most instructions can be relocated")
        code.append("    // RET/SVC are position-independent (just BR X30 / supervisor call)")
        code.append("    // They are safe to copy to a trampoline as-is")
        code.append("")
        code.append("    switch (decoded->mnemonic) {")
        code.append("        // Authenticated returns - can't relocate (PAC dependent on address)")
        code.append("        case Mnemonic::RETAA:")
        code.append("        case Mnemonic::RETAB:")
        code.append("        case Mnemonic::ERETAA:")
        code.append("        case Mnemonic::ERETAB:")
        code.append("            return false;")
        code.append("")
        code.append("        default:")
        code.append("            // All other instructions are either position-independent")
        code.append("            // or handled by relocate_instruction()")
        code.append("            return true;")
        code.append("    }")
        code.append("}")
        code.append("")
        code.append("// Resolve forwarding stubs: if function starts with unconditional B,")
        code.append("// follow the branch to the real implementation.")
        code.append("// Returns the resolved address (unchanged if not a forwarding stub).")
        code.append("void* resolve_forwarding_stub(void* target) {")
        code.append("    const uint32_t* insns = static_cast<const uint32_t*>(target);")
        code.append("    // Follow up to 5 chained B stubs (safety limit)")
        code.append("    for (int depth = 0; depth < 5; ++depth) {")
        code.append("        uint32_t insn = insns[0];")
        code.append("        // Unconditional B: bits [31:26] = 0b000101")
        code.append("        if ((insn & 0xFC000000) != 0x14000000) break;")
        code.append("        // Decode imm26 (signed)")
        code.append("        int32_t imm26 = static_cast<int32_t>(insn & 0x03FFFFFF);")
        code.append("        if (imm26 & 0x02000000) imm26 |= 0xFC000000;")
        code.append("        int64_t offset = static_cast<int64_t>(imm26) * 4;")
        code.append("        uintptr_t addr = reinterpret_cast<uintptr_t>(insns) + offset;")
        code.append("        insns = reinterpret_cast<const uint32_t*>(addr);")
        code.append("    }")
        code.append("    return const_cast<void*>(static_cast<const void*>(insns));")
        code.append("}")
        code.append("")
        code.append("// Detect Windows ARM64 syscall stub pattern: SVC #imm + RET + 0 + 0")
        code.append("bool is_syscall_stub(const uint8_t* target) {")
        code.append("    const uint32_t* insns = reinterpret_cast<const uint32_t*>(target);")
        code.append("    // SVC: encoding is 0xD4000001 | (imm16 << 5)")
        code.append("    // Check bits [31:21] = 0b11010100_000 and bits [4:0] = 0b00001")
        code.append("    bool is_svc = (insns[0] & 0xFFE0001F) == 0xD4000001;")
        code.append("    // RET (Xn=X30): 0xD65F03C0")
        code.append("    bool is_ret = insns[1] == 0xD65F03C0;")
        code.append("    // Two zero words of padding")
        code.append("    bool is_pad = (insns[2] == 0) && (insns[3] == 0);")
        code.append("    return is_svc && is_ret && is_pad;")
        code.append("}")
        code.append("")
        code.append("// Relocate a single instruction")
        code.append("bool relocate_instruction(")
        code.append("    uint32_t insn,")
        code.append("    uint64_t old_pc,")
        code.append("    uint64_t new_pc,")
        code.append("    uint32_t* out_insn,")
        code.append("    size_t* out_count")
        code.append(") {")
        code.append("    auto decoded = decode(insn);")
        code.append("    if (!decoded) {")
        code.append("        *out_count = 0;")
        code.append("        return false;")
        code.append("    }")
        code.append("")
        code.append("    // If not PC-relative, just copy the instruction")
        code.append("    if (!is_pc_relative(insn)) {")
        code.append("        out_insn[0] = insn;")
        code.append("        *out_count = 1;")
        code.append("        return true;")
        code.append("    }")
        code.append("")
        code.append("    // Handle PC-relative instructions")
        code.append("    switch (decoded->mnemonic) {")
        code.append("        case Mnemonic::B: {")
        code.append("            // B.cond also decodes as Mnemonic::B; distinguish by encoding")
        code.append("            // B.cond: bits [31:24]=0x54, bit4=0 -> mask 0xFF000010")
        code.append("            if ((insn & 0xFF000010) == 0x54000000) {")
        code.append("                // B.cond imm19 - 19-bit signed offset * 4")
        code.append("                int32_t imm19 = static_cast<int32_t>((insn >> 5) & 0x7FFFF);")
        code.append("                if (imm19 & 0x40000) { imm19 |= 0xFFF80000; }")
        code.append("                int64_t offset = static_cast<int64_t>(imm19) * 4;")
        code.append("                uint64_t target = old_pc + offset;")
        code.append("                int64_t new_offset = static_cast<int64_t>(target - new_pc);")
        code.append("                if (new_offset >= -1048576 && new_offset <= 1048572 && (new_offset & 3) == 0) {")
        code.append("                    uint32_t new_imm19 = static_cast<uint32_t>((new_offset / 4) & 0x7FFFF);")
        code.append("                    out_insn[0] = (insn & 0xFF00001F) | (new_imm19 << 5);")
        code.append("                    *out_count = 1;")
        code.append("                    return true;")
        code.append("                }")
        code.append("                *out_count = 0;")
        code.append("                return false;")
        code.append("            }")
        code.append("            // Unconditional B: fall through to B/BL handling")
        code.append("        }")
        code.append("        [[fallthrough]];")
        code.append("        case Mnemonic::BL: {")
        code.append("            // B/BL imm26 - 26-bit signed offset * 4")
        code.append("            int32_t imm26 = static_cast<int32_t>(insn & 0x03FFFFFF);")
        code.append("            if (imm26 & 0x02000000) {  // Sign extend")
        code.append("                imm26 |= 0xFC000000;")
        code.append("            }")
        code.append("            int64_t offset = static_cast<int64_t>(imm26) * 4;")
        code.append("            uint64_t target = old_pc + offset;")
        code.append("")
        code.append("            // Calculate new offset")
        code.append("            int64_t new_offset = static_cast<int64_t>(target - new_pc);")
        code.append("")
        code.append("            // Check if within range (±128MB)")
        code.append("            if (new_offset >= -134217728 && new_offset <= 134217724 && (new_offset & 3) == 0) {")
        code.append("                // Can use direct branch")
        code.append("                uint32_t new_imm26 = static_cast<uint32_t>((new_offset / 4) & 0x03FFFFFF);")
        code.append("                out_insn[0] = (insn & 0xFC000000) | new_imm26;")
        code.append("                *out_count = 1;")
        code.append("                return true;")
        code.append("            }")
        code.append("")
        code.append("            // Need to use indirect branch sequence")
        code.append("            // This is more complex - for now, return failure")
        code.append("            *out_count = 0;")
        code.append("            return false;")
        code.append("        }")
        code.append("")
        code.append("        case Mnemonic::BC: {")
        code.append("            // B.cond imm19 - 19-bit signed offset * 4")
        code.append("            int32_t imm19 = static_cast<int32_t>((insn >> 5) & 0x7FFFF);")
        code.append("            if (imm19 & 0x40000) {  // Sign extend")
        code.append("                imm19 |= 0xFFF80000;")
        code.append("            }")
        code.append("            int64_t offset = static_cast<int64_t>(imm19) * 4;")
        code.append("            uint64_t target = old_pc + offset;")
        code.append("")
        code.append("            int64_t new_offset = static_cast<int64_t>(target - new_pc);")
        code.append("")
        code.append("            // Check if within range (±1MB)")
        code.append("            if (new_offset >= -1048576 && new_offset <= 1048572 && (new_offset & 3) == 0) {")
        code.append("                uint32_t new_imm19 = static_cast<uint32_t>((new_offset / 4) & 0x7FFFF);")
        code.append("                out_insn[0] = (insn & 0xFF00001F) | (new_imm19 << 5);")
        code.append("                *out_count = 1;")
        code.append("                return true;")
        code.append("            }")
        code.append("")
        code.append("            *out_count = 0;")
        code.append("            return false;")
        code.append("        }")
        code.append("")
        code.append("        case Mnemonic::CBZ:")
        code.append("        case Mnemonic::CBNZ: {")
        code.append("            // CBZ/CBNZ imm19 - 19-bit signed offset * 4")
        code.append("            int32_t imm19 = static_cast<int32_t>((insn >> 5) & 0x7FFFF);")
        code.append("            if (imm19 & 0x40000) {")
        code.append("                imm19 |= 0xFFF80000;")
        code.append("            }")
        code.append("            int64_t offset = static_cast<int64_t>(imm19) * 4;")
        code.append("            uint64_t target = old_pc + offset;")
        code.append("")
        code.append("            int64_t new_offset = static_cast<int64_t>(target - new_pc);")
        code.append("")
        code.append("            if (new_offset >= -1048576 && new_offset <= 1048572 && (new_offset & 3) == 0) {")
        code.append("                uint32_t new_imm19 = static_cast<uint32_t>((new_offset / 4) & 0x7FFFF);")
        code.append("                out_insn[0] = (insn & 0xFF00001F) | (new_imm19 << 5);")
        code.append("                *out_count = 1;")
        code.append("                return true;")
        code.append("            }")
        code.append("")
        code.append("            *out_count = 0;")
        code.append("            return false;")
        code.append("        }")
        code.append("")
        code.append("        case Mnemonic::TBZ:")
        code.append("        case Mnemonic::TBNZ: {")
        code.append("            // TBZ/TBNZ imm14 - 14-bit signed offset * 4")
        code.append("            int32_t imm14 = static_cast<int32_t>((insn >> 5) & 0x3FFF);")
        code.append("            if (imm14 & 0x2000) {")
        code.append("                imm14 |= 0xFFFFC000;")
        code.append("            }")
        code.append("            int64_t offset = static_cast<int64_t>(imm14) * 4;")
        code.append("            uint64_t target = old_pc + offset;")
        code.append("")
        code.append("            int64_t new_offset = static_cast<int64_t>(target - new_pc);")
        code.append("")
        code.append("            // Check if within range (±32KB)")
        code.append("            if (new_offset >= -32768 && new_offset <= 32764 && (new_offset & 3) == 0) {")
        code.append("                uint32_t new_imm14 = static_cast<uint32_t>((new_offset / 4) & 0x3FFF);")
        code.append("                out_insn[0] = (insn & 0xFFF8001F) | (new_imm14 << 5);")
        code.append("                *out_count = 1;")
        code.append("                return true;")
        code.append("            }")
        code.append("")
        code.append("            *out_count = 0;")
        code.append("            return false;")
        code.append("        }")
        code.append("")
        code.append("        case Mnemonic::ADR: {")
        code.append("            // ADR Xd, label - 21-bit signed offset")
        code.append("            uint32_t immlo = (insn >> 29) & 0x3;")
        code.append("            uint32_t immhi = (insn >> 5) & 0x7FFFF;")
        code.append("            int32_t imm21 = static_cast<int32_t>((immhi << 2) | immlo);")
        code.append("            if (imm21 & 0x100000) {")
        code.append("                imm21 |= 0xFFE00000;")
        code.append("            }")
        code.append("            uint64_t target = old_pc + imm21;")
        code.append("")
        code.append("            int64_t new_offset = static_cast<int64_t>(target - new_pc);")
        code.append("")
        code.append("            // Check if within range (±1MB)")
        code.append("            if (new_offset >= -1048576 && new_offset <= 1048575) {")
        code.append("                uint32_t new_imm21 = static_cast<uint32_t>(new_offset) & 0x1FFFFF;")
        code.append("                uint32_t new_immlo = new_imm21 & 0x3;")
        code.append("                uint32_t new_immhi = (new_imm21 >> 2) & 0x7FFFF;")
        code.append("                out_insn[0] = (insn & 0x9F00001F) | (new_immlo << 29) | (new_immhi << 5);")
        code.append("                *out_count = 1;")
        code.append("                return true;")
        code.append("            }")
        code.append("")
        code.append("            *out_count = 0;")
        code.append("            return false;")
        code.append("        }")
        code.append("")
        code.append("        case Mnemonic::ADRP: {")
        code.append("            // ADRP Xd, label - page-aligned address")
        code.append("            uint32_t immlo = (insn >> 29) & 0x3;")
        code.append("            uint32_t immhi = (insn >> 5) & 0x7FFFF;")
        code.append("            int32_t imm21 = static_cast<int32_t>((immhi << 2) | immlo);")
        code.append("            if (imm21 & 0x100000) {")
        code.append("                imm21 |= 0xFFE00000;")
        code.append("            }")
        code.append("            int64_t offset = static_cast<int64_t>(imm21) << 12;")
        code.append("            uint64_t target = (old_pc & ~0xFFFULL) + offset;")
        code.append("")
        code.append("            int64_t new_offset = static_cast<int64_t>(target - (new_pc & ~0xFFFULL));")
        code.append("")
        code.append("            // Check if within range (±4GB pages)")
        code.append("            if (new_offset >= -4294967296LL && new_offset <= 4294963200LL) {")
        code.append("                int32_t new_imm21 = static_cast<int32_t>(new_offset >> 12);")
        code.append("                uint32_t new_immlo = new_imm21 & 0x3;")
        code.append("                uint32_t new_immhi = (new_imm21 >> 2) & 0x7FFFF;")
        code.append("                out_insn[0] = (insn & 0x9F00001F) | (new_immlo << 29) | (new_immhi << 5);")
        code.append("                *out_count = 1;")
        code.append("                return true;")
        code.append("            }")
        code.append("")
        code.append("            *out_count = 0;")
        code.append("            return false;")
        code.append("        }")
        code.append("")
        code.append("        default:")
        code.append("            // For other PC-relative instructions (LDR literal, etc.)")
        code.append("            // we'd need more complex handling")
        code.append("            out_insn[0] = insn;")
        code.append("            *out_count = 1;")
        code.append("            return true;")
        code.append("    }")
        code.append("}")
        code.append("")
        code.append("} // namespace detail")
        code.append("")
        code.append("// ============================================================================")
        code.append("// Hook installation")
        code.append("// ============================================================================")
        code.append("")
        code.append("static HookStatus create_trampoline(void* target, size_t hook_size, Trampoline* out_tramp) {")
        code.append("    *out_tramp = {};")
        code.append("    Trampoline& tramp = *out_tramp;")
        code.append("")
        code.append("    // Allocate space for relocated instructions + jump back")
        code.append("    // Each instruction might expand to multiple instructions during relocation")
        code.append("    size_t max_size = (hook_size / 4) * 16 + 16;  // Worst case expansion + jump")
        code.append("")
        code.append("    // Allocate near the target for PC-relative instruction relocation")
        code.append("    tramp.code = static_cast<uint8_t*>(detail::alloc_executable_near(target, max_size));")
        code.append("    if (!tramp.code) {")
        code.append("        return HookStatus::AllocationFailed;")
        code.append("    }")
        code.append("    tramp.code_size = max_size;")
        code.append("")
        code.append("    uint8_t* src = static_cast<uint8_t*>(target);")
        code.append("    uint8_t* dst = tramp.code;")
        code.append("    size_t dst_offset = 0;")
        code.append("")
        code.append("    // Check for Windows ARM64 syscall stub pattern: SVC + RET + 0 + 0")
        code.append("    // These are exactly 16 bytes: the SVC does the syscall, RET returns.")
        code.append("    // Trampoline just needs SVC + RET (no jump-back, RET returns to caller).")
        code.append("    if (hook_size == 16 && detail::is_syscall_stub(src)) {")
        code.append("        uint32_t* dst_insn = reinterpret_cast<uint32_t*>(dst);")
        code.append("        const uint32_t* src_insn = reinterpret_cast<const uint32_t*>(src);")
        code.append("        dst_insn[0] = src_insn[0];  // SVC #imm")
        code.append("        dst_insn[1] = src_insn[1];  // RET")
        code.append("        tramp.used_size = 8;")
        code.append("        tramp.insn_count = 2;")
        code.append("        detail::flush_icache(tramp.code, tramp.used_size);")
        code.append("        return HookStatus::Success;")
        code.append("    }")
        code.append("")
        code.append("    // General case: disassemble and relocate instructions")
        code.append("    size_t src_offset = 0;")
        code.append("    uint64_t src_pc = reinterpret_cast<uint64_t>(target);")
        code.append("    uint64_t dst_pc = reinterpret_cast<uint64_t>(tramp.code);")
        code.append("    bool found_ret = false;")
        code.append("")
        code.append("    while (src_offset < hook_size) {")
        code.append("        uint32_t insn = *reinterpret_cast<uint32_t*>(src + src_offset);")
        code.append("")
        code.append("        // Skip zero padding (UDF #0)")
        code.append("        if (insn == 0) {")
        code.append("            src_offset += 4;")
        code.append("            continue;")
        code.append("        }")
        code.append("")
        code.append("        // Check if we can relocate this instruction")
        code.append("        if (!detail::can_relocate(insn)) {")
        code.append("            detail::free_executable(tramp.code, tramp.code_size);")
        code.append("            tramp.code = nullptr;")
        code.append("            return HookStatus::InstructionTooComplex;")
        code.append("        }")
        code.append("")
        code.append("        // Track if we hit a RET — no jump-back needed after it")
        code.append("        if (insn == 0xD65F03C0) found_ret = true;")
        code.append("")
        code.append("        // Relocate the instruction")
        code.append("        uint32_t relocated[4];")
        code.append("        size_t relocated_count = 0;")
        code.append("")
        code.append("        if (!detail::relocate_instruction(")
        code.append("            insn,")
        code.append("            src_pc + src_offset,")
        code.append("            dst_pc + dst_offset,")
        code.append("            relocated,")
        code.append("            &relocated_count")
        code.append("        )) {")
        code.append("            detail::free_executable(tramp.code, tramp.code_size);")
        code.append("            tramp.code = nullptr;")
        code.append("            return HookStatus::RelocationFailed;")
        code.append("        }")
        code.append("")
        code.append("        // Copy relocated instructions to trampoline")
        code.append("        for (size_t i = 0; i < relocated_count; ++i) {")
        code.append("            *reinterpret_cast<uint32_t*>(dst + dst_offset) = relocated[i];")
        code.append("            dst_offset += 4;")
        code.append("        }")
        code.append("")
        code.append("        src_offset += 4;")
        code.append("        tramp.insn_count++;")
        code.append("    }")
        code.append("")
        code.append("    // Add jump back to original code after hook (unless we already have a RET)")
        code.append("    if (!found_ret) {")
        code.append("        void* return_addr = static_cast<uint8_t*>(target) + hook_size;")
        code.append("        dst_offset += detail::generate_jump(dst + dst_offset, return_addr);")
        code.append("    }")
        code.append("")
        code.append("    tramp.used_size = dst_offset;")
        code.append("")
        code.append("    // Flush instruction cache for trampoline")
        code.append("    detail::flush_icache(tramp.code, tramp.used_size);")
        code.append("")
        code.append("    return HookStatus::Success;")
        code.append("}")
        code.append("")
        code.append("HookStatus install_impl(void* target, void* detour, void** original, HookHandle* handle) {")
        code.append("    if (handle) *handle = nullptr;")
        code.append("")
        code.append("    if (!g_state.initialized) {")
        code.append("        return HookStatus::NotInitialized;")
        code.append("    }")
        code.append("")
        code.append("    if (!target) {")
        code.append("        return HookStatus::InvalidTarget;")
        code.append("    }")
        code.append("")
        code.append("    if (!detour) {")
        code.append("        return HookStatus::InvalidDetour;")
        code.append("    }")
        code.append("")
        code.append("    // Resolve forwarding stubs (e.g., kernel32 -> kernelbase)")
        code.append("    target = detail::resolve_forwarding_stub(target);")
        code.append("")
        code.append("    std::lock_guard<std::mutex> lock(g_state.mutex);")
        code.append("")
        code.append("    // Check if already hooked")
        code.append("    if (g_state.target_map.find(target) != g_state.target_map.end()) {")
        code.append("        if (!g_state.config.allow_chain) {")
        code.append("            return HookStatus::HookAlreadyInstalled;")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // Create hook context")
        code.append("    HookContext* ctx = new HookContext{};")
        code.append("    ctx->target = target;")
        code.append("    ctx->detour = detour;")
        code.append("    ctx->hook_size = g_state.config.min_hook_size;")
        code.append("    ctx->enabled = false;")
        code.append("    ctx->valid = false;")
        code.append("")
        code.append("    // Round up hook size to instruction boundary")
        code.append("    if (ctx->hook_size % 4 != 0) {")
        code.append("        ctx->hook_size = ((ctx->hook_size / 4) + 1) * 4;")
        code.append("    }")
        code.append("")
        code.append("    // Ensure minimum size for jump sequence (16 bytes)")
        code.append("    if (ctx->hook_size < 16) {")
        code.append("        ctx->hook_size = 16;")
        code.append("    }")
        code.append("")
        code.append("    // Save original bytes")
        code.append("    std::memcpy(ctx->original_bytes, target, ctx->hook_size);")
        code.append("")
        code.append("    // Create trampoline")
        code.append("    HookStatus tramp_status = create_trampoline(target, ctx->hook_size, &ctx->trampoline);")
        code.append("    if (tramp_status != HookStatus::Success) {")
        code.append("        delete ctx;")
        code.append("        return tramp_status;")
        code.append("    }")
        code.append("")
        code.append("    // Generate hook jump sequence (stored but not yet written to target)")
        code.append("    detail::generate_jump(ctx->hook_bytes, detour);")
        code.append("")
        code.append("    // Hook starts disabled — call enable() to activate")
        code.append("    ctx->enabled = false;")
        code.append("    ctx->valid = true;")
        code.append("")
        code.append("    // Store hook in global state")
        code.append("    g_state.hooks.push_back(ctx);")
        code.append("    g_state.target_map[target] = ctx;")
        code.append("")
        code.append("    // Return trampoline as original function pointer")
        code.append("    if (original) {")
        code.append("        *original = ctx->trampoline.code;")
        code.append("    }")
        code.append("")
        code.append("    if (handle) {")
        code.append("        *handle = ctx;")
        code.append("    }")
        code.append("")
        code.append("    return HookStatus::Success;")
        code.append("}")
        code.append("")
        code.append("// ============================================================================")
        code.append("// Hook removal")
        code.append("// ============================================================================")
        code.append("")
        code.append("HookStatus remove(HookHandle handle) {")
        code.append("    if (!g_state.initialized) {")
        code.append("        return HookStatus::NotInitialized;")
        code.append("    }")
        code.append("")
        code.append("    if (!handle || !handle->valid) {")
        code.append("        return HookStatus::HookNotFound;")
        code.append("    }")
        code.append("")
        code.append("    std::lock_guard<std::mutex> lock(g_state.mutex);")
        code.append("")
        code.append("    // Find and validate hook")
        code.append("    auto it = std::find(g_state.hooks.begin(), g_state.hooks.end(), handle);")
        code.append("    if (it == g_state.hooks.end()) {")
        code.append("        return HookStatus::HookNotFound;")
        code.append("    }")
        code.append("")
        code.append("    HookContext* ctx = handle;")
        code.append("")
        code.append("    // Restore original bytes")
        code.append("    if (ctx->enabled) {")
        code.append("        if (g_state.config.thread_safe) {")
        code.append("            detail::suspend_threads();")
        code.append("        }")
        code.append("")
        code.append("        uint32_t old_protect = detail::make_writable(ctx->target, ctx->hook_size);")
        code.append("        std::memcpy(ctx->target, ctx->original_bytes, ctx->hook_size);")
        code.append("        detail::restore_protection(ctx->target, ctx->hook_size, old_protect);")
        code.append("        detail::flush_icache(ctx->target, ctx->hook_size);")
        code.append("")
        code.append("        if (g_state.config.thread_safe) {")
        code.append("            detail::resume_threads();")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // Free trampoline")
        code.append("    if (ctx->trampoline.code) {")
        code.append("        detail::free_executable(ctx->trampoline.code, ctx->trampoline.code_size);")
        code.append("    }")
        code.append("")
        code.append("    // Remove from global state")
        code.append("    g_state.target_map.erase(ctx->target);")
        code.append("    g_state.hooks.erase(it);")
        code.append("")
        code.append("    // Delete context")
        code.append("    ctx->valid = false;")
        code.append("    delete ctx;")
        code.append("")
        code.append("    return HookStatus::Success;")
        code.append("}")
        code.append("")
        code.append("void remove_all() {")
        code.append("    if (!g_state.initialized) {")
        code.append("        return;")
        code.append("    }")
        code.append("")
        code.append("    std::lock_guard<std::mutex> lock(g_state.mutex);")
        code.append("")
        code.append("    // Copy hook list (remove modifies it)")
        code.append("    std::vector<HookContext*> hooks_copy = g_state.hooks;")
        code.append("")
        code.append("    g_state.mutex.unlock();")
        code.append("    for (auto* ctx : hooks_copy) {")
        code.append("        remove(ctx);")
        code.append("    }")
        code.append("    g_state.mutex.lock();")
        code.append("}")
        code.append("")
        code.append("// ============================================================================")
        code.append("// Hook enable/disable")
        code.append("// ============================================================================")
        code.append("")
        code.append("HookStatus enable(HookHandle handle) {")
        code.append("    if (!g_state.initialized) {")
        code.append("        return HookStatus::NotInitialized;")
        code.append("    }")
        code.append("")
        code.append("    if (!handle || !handle->valid) {")
        code.append("        return HookStatus::HookNotFound;")
        code.append("    }")
        code.append("")
        code.append("    std::lock_guard<std::mutex> lock(g_state.mutex);")
        code.append("")
        code.append("    if (handle->enabled) {")
        code.append("        return HookStatus::Success;")
        code.append("    }")
        code.append("")
        code.append("    // Install hook bytes")
        code.append("    if (g_state.config.thread_safe) {")
        code.append("        detail::suspend_threads();")
        code.append("    }")
        code.append("")
        code.append("    uint32_t old_protect = detail::make_writable(handle->target, handle->hook_size);")
        code.append("    std::memcpy(handle->target, handle->hook_bytes, handle->hook_size);")
        code.append("    detail::restore_protection(handle->target, handle->hook_size, old_protect);")
        code.append("    detail::flush_icache(handle->target, handle->hook_size);")
        code.append("")
        code.append("    if (g_state.config.thread_safe) {")
        code.append("        detail::resume_threads();")
        code.append("    }")
        code.append("")
        code.append("    handle->enabled = true;")
        code.append("    return HookStatus::Success;")
        code.append("}")
        code.append("")
        code.append("HookStatus disable(HookHandle handle) {")
        code.append("    if (!g_state.initialized) {")
        code.append("        return HookStatus::NotInitialized;")
        code.append("    }")
        code.append("")
        code.append("    if (!handle || !handle->valid) {")
        code.append("        return HookStatus::HookNotFound;")
        code.append("    }")
        code.append("")
        code.append("    std::lock_guard<std::mutex> lock(g_state.mutex);")
        code.append("")
        code.append("    if (!handle->enabled) {")
        code.append("        return HookStatus::Success;")
        code.append("    }")
        code.append("")
        code.append("    // Restore original bytes")
        code.append("    if (g_state.config.thread_safe) {")
        code.append("        detail::suspend_threads();")
        code.append("    }")
        code.append("")
        code.append("    uint32_t old_protect = detail::make_writable(handle->target, handle->hook_size);")
        code.append("    std::memcpy(handle->target, handle->original_bytes, handle->hook_size);")
        code.append("    detail::restore_protection(handle->target, handle->hook_size, old_protect);")
        code.append("    detail::flush_icache(handle->target, handle->hook_size);")
        code.append("")
        code.append("    if (g_state.config.thread_safe) {")
        code.append("        detail::resume_threads();")
        code.append("    }")
        code.append("")
        code.append("    handle->enabled = false;")
        code.append("    return HookStatus::Success;")
        code.append("}")
        code.append("")
        code.append("bool is_enabled(HookHandle handle) {")
        code.append("    if (!handle || !handle->valid) {")
        code.append("        return false;")
        code.append("    }")
        code.append("    return handle->enabled;")
        code.append("}")
        code.append("")
        code.append("HookStatus enable_all() {")
        code.append("    if (!g_state.initialized) {")
        code.append("        return HookStatus::NotInitialized;")
        code.append("    }")
        code.append("")
        code.append("    std::lock_guard<std::mutex> lock(g_state.mutex);")
        code.append("")
        code.append("    if (g_state.config.thread_safe) {")
        code.append("        detail::suspend_threads();")
        code.append("    }")
        code.append("")
        code.append("    HookStatus result = HookStatus::Success;")
        code.append("    for (auto* ctx : g_state.hooks) {")
        code.append("        if (!ctx->valid || ctx->enabled) continue;")
        code.append("        uint32_t old_protect = detail::make_writable(ctx->target, ctx->hook_size);")
        code.append("        std::memcpy(ctx->target, ctx->hook_bytes, ctx->hook_size);")
        code.append("        detail::restore_protection(ctx->target, ctx->hook_size, old_protect);")
        code.append("        detail::flush_icache(ctx->target, ctx->hook_size);")
        code.append("        ctx->enabled = true;")
        code.append("    }")
        code.append("")
        code.append("    if (g_state.config.thread_safe) {")
        code.append("        detail::resume_threads();")
        code.append("    }")
        code.append("")
        code.append("    return result;")
        code.append("}")
        code.append("")
        code.append("HookStatus disable_all() {")
        code.append("    if (!g_state.initialized) {")
        code.append("        return HookStatus::NotInitialized;")
        code.append("    }")
        code.append("")
        code.append("    std::lock_guard<std::mutex> lock(g_state.mutex);")
        code.append("")
        code.append("    if (g_state.config.thread_safe) {")
        code.append("        detail::suspend_threads();")
        code.append("    }")
        code.append("")
        code.append("    HookStatus result = HookStatus::Success;")
        code.append("    for (auto* ctx : g_state.hooks) {")
        code.append("        if (!ctx->valid || !ctx->enabled) continue;")
        code.append("        uint32_t old_protect = detail::make_writable(ctx->target, ctx->hook_size);")
        code.append("        std::memcpy(ctx->target, ctx->original_bytes, ctx->hook_size);")
        code.append("        detail::restore_protection(ctx->target, ctx->hook_size, old_protect);")
        code.append("        detail::flush_icache(ctx->target, ctx->hook_size);")
        code.append("        ctx->enabled = false;")
        code.append("    }")
        code.append("")
        code.append("    if (g_state.config.thread_safe) {")
        code.append("        detail::resume_threads();")
        code.append("    }")
        code.append("")
        code.append("    return result;")
        code.append("}")
        code.append("")
        code.append("// ============================================================================")
        code.append("// Hook information")
        code.append("// ============================================================================")
        code.append("")
        code.append("void* get_target(HookHandle handle) {")
        code.append("    if (!handle || !handle->valid) return nullptr;")
        code.append("    return handle->target;")
        code.append("}")
        code.append("")
        code.append("void* get_detour(HookHandle handle) {")
        code.append("    if (!handle || !handle->valid) return nullptr;")
        code.append("    return handle->detour;")
        code.append("}")
        code.append("")
        code.append("void* get_trampoline(HookHandle handle) {")
        code.append("    if (!handle || !handle->valid) return nullptr;")
        code.append("    return handle->trampoline.code;")
        code.append("}")
        code.append("")
        code.append("size_t get_hook_size(HookHandle handle) {")
        code.append("    if (!handle || !handle->valid) return 0;")
        code.append("    return handle->hook_size;")
        code.append("}")
        code.append("")
        code.append("size_t get_relocated_count(HookHandle handle) {")
        code.append("    if (!handle || !handle->valid) return 0;")
        code.append("    return handle->trampoline.insn_count;")
        code.append("}")
        code.append("")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("void dump_hook(HookHandle handle) {")
        code.append("    if (!handle || !handle->valid) {")
        code.append("        printf(\"Invalid hook handle\\n\");")
        code.append("        return;")
        code.append("    }")
        code.append("")
        code.append("    printf(\"Hook Information:\\n\");")
        code.append("    printf(\"  Target:      %p\\n\", handle->target);")
        code.append("    printf(\"  Detour:      %p\\n\", handle->detour);")
        code.append("    printf(\"  Trampoline:  %p\\n\", handle->trampoline.code);")
        code.append("    printf(\"  Hook size:   %zu bytes\\n\", handle->hook_size);")
        code.append("    printf(\"  Relocated:   %zu instructions\\n\", handle->trampoline.insn_count);")
        code.append("    printf(\"  Enabled:     %s\\n\", handle->enabled ? \"yes\" : \"no\");")
        code.append("")
        code.append("    printf(\"  Original bytes: \");")
        code.append("    for (size_t i = 0; i < handle->hook_size; ++i) {")
        code.append("        printf(\"%02X \", handle->original_bytes[i]);")
        code.append("    }")
        code.append("    printf(\"\\n\");")
        code.append("")
        code.append("    printf(\"  Hook bytes:     \");")
        code.append("    for (size_t i = 0; i < handle->hook_size; ++i) {")
        code.append("        printf(\"%02X \", handle->hook_bytes[i]);")
        code.append("    }")
        code.append("    printf(\"\\n\");")
        code.append("")
        code.append("    // Disassemble original instructions")
        code.append("    printf(\"  Original instructions:\\n\");")
        code.append("    uint32_t* insns = reinterpret_cast<uint32_t*>(handle->original_bytes);")
        code.append("    for (size_t i = 0; i < handle->hook_size / 4; ++i) {")
        code.append("        auto decoded = decode(insns[i]);")
        code.append("        if (decoded) {")
        code.append("            printf(\"    %08X: %s\\n\", insns[i], decoded->to_string().c_str());")
        code.append("        } else {")
        code.append("            printf(\"    %08X: <unknown>\\n\", insns[i]);")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // Disassemble trampoline")
        code.append("    printf(\"  Trampoline instructions:\\n\");")
        code.append("    insns = reinterpret_cast<uint32_t*>(handle->trampoline.code);")
        code.append("    for (size_t i = 0; i < handle->trampoline.used_size / 4; ++i) {")
        code.append("        auto decoded = decode(insns[i]);")
        code.append("        if (decoded) {")
        code.append("            printf(\"    %08X: %s\\n\", insns[i], decoded->to_string().c_str());")
        code.append("        } else {")
        code.append("            printf(\"    %08X: <unknown>\\n\", insns[i]);")
        code.append("        }")
        code.append("    }")
        code.append("}")
        code.append("#endif // !VEDA64_NO_STRINGS")
        code.append("")
        code.append("} // namespace hook")
        code.append("} // namespace veda64")
        code.append("")
        code.append("#endif // !VEDA64_NO_HOOKS && (_WIN32 || VEDA64_HOOK_SUPPORT)")
        code.append("")

        output_file = lib_dir / "hook.cpp"
        self._write_file(output_file, code)
        print(f"Generated {output_file.name}")

    def generate_reference_test(self, test_dir: Path):
        """Generate a reference test based on real disassembly output."""
        code = self._license_header()
        code.append("#include \"veda64.hpp\"")
        code.append("#include <iostream>")
        code.append("#include <cassert>")
        code.append("#include <cctype>")
        code.append("#include <algorithm>")
        code.append("#include <string>")
        code.append("")
        code.append("using namespace veda64;")
        code.append("")
        code.append("// Convert string to lowercase")
        code.append("std::string to_lower(const std::string& s) {")
        code.append("    std::string result = s;")
        code.append("    for (char& c : result) {")
        code.append("        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));")
        code.append("    }")
        code.append("    return result;")
        code.append("}")
        code.append("")
        code.append("// Normalize disassembly for comparison:")
        code.append("// - Convert to lowercase")
        code.append("// - Normalize register aliases (x29->fp, x30->lr)")
        code.append("// - Normalize hex format")
        code.append("std::string normalize(const std::string& s) {")
        code.append("    std::string result = to_lower(s);")
        code.append("    ")
        code.append("    // Replace register aliases")
        code.append("    size_t pos;")
        code.append("    while ((pos = result.find(\"x29\")) != std::string::npos) {")
        code.append("        result.replace(pos, 3, \"fp\");")
        code.append("    }")
        code.append("    while ((pos = result.find(\"x30\")) != std::string::npos) {")
        code.append("        result.replace(pos, 3, \"lr\");")
        code.append("    }")
        code.append("    ")
        code.append("    return result;")
        code.append("}")
        code.append("")
        code.append("// Check if disassembly output matches expected (case-insensitive, with normalization)")
        code.append("bool check_disasm(uint32_t insn, const char* expected) {")
        code.append("    auto result = decode(insn);")
        code.append("    if (!result) {")
        code.append("        std::cerr << \"FAIL: Failed to decode 0x\" << std::hex << insn << std::dec << std::endl;")
        code.append("        std::cerr << \"      Expected: \" << expected << std::endl;")
        code.append("        return false;")
        code.append("    }")
        code.append("    ")
        code.append("    std::string got = result->to_string();")
        code.append("    std::string norm_got = normalize(got);")
        code.append("    std::string norm_expected = normalize(expected);")
        code.append("    ")
        code.append("    if (norm_got != norm_expected) {")
        code.append("        std::cerr << \"FAIL: Mismatch for 0x\" << std::hex << insn << std::dec << std::endl;")
        code.append("        std::cerr << \"      Expected: \" << expected << std::endl;")
        code.append("        std::cerr << \"      Got:      \" << got << std::endl;")
        code.append("        return false;")
        code.append("    }")
        code.append("    ")
        code.append("    std::cout << \"  OK: \" << got << std::endl;")
        code.append("    return true;")
        code.append("}")
        code.append("")
        code.append("int main() {")
        code.append("    std::cout << \"Running reference tests...\" << std::endl;")
        code.append("    int passed = 0;")
        code.append("    int failed = 0;")
        code.append("")

        # Reference test cases - validated against actual ARM64 instruction encodings
        # Format: (native uint32_t hex value, expected full disassembly)
        # Native value = byte-swap of the little-endian memory representation
        # e.g., memory bytes {0xd5, 0x03, 0x23, 0x7f} -> native 0xd503237f (PACIBSP)
        # Note: Using alias forms where applicable (MOV for ADD #0, MOVZ with shift=0, MOVN)
        # Register names: fp=X29, lr=X30, sp=SP, wzr=WZR
        # All immediate values are in hexadecimal
        test_cases = [
            ("0xd503237f", "pacibsp"),                     # HINT #27 (CRm=3, op2=3)
            ("0xa9be7bfd", "stp fp, lr, [sp, #-0x20]!"),   # -32 = -0x20
            ("0x910003fd", "mov x29, sp"),                  # alias: ADD with imm=0
            ("0x390043bf", "strb wzr, [x29, #0x10]"),      # byte: imm12 unscaled (size=0)
            ("0xd2800004", "mov x4, #0x0"),               # alias: MOVZ with no shift
            ("0x52800023", "mov w3, #0x1"),               # alias: MOVZ 32-bit
            ("0x910043a2", "add x2, fp, #0x10"),
            ("0x52800221", "mov w1, #0x11"),              # alias: MOVZ 32-bit
            ("0x92800020", "mov x0, #-0x2"),              # alias: MOVN (imm16=1, hw=0, ~1=0xFFFFFFFFFFFFFFFE)
            ("0x97fa94a3", "bl .-0x15ad74"),               # -1420660 = -0x15ad74
            ("0x37f800a0", "tbnz w0, #0x1f, .+0x14"),      # b5=0 → W register (bit < 32)
            ("0x394043a8", "ldrb w8, [x29, #0x10]"),       # byte: imm12 unscaled (size=0)
            ("0x35000068", "cbnz w8, .+0xc"),              # 12 = 0xc
            ("0xd43e0000", "brk #0xf000"),
            ("0x14000001", "b .+0x4"),
            ("0xa8c27bfd", "ldp fp, lr, [sp], #0x20"),     # 32 = 0x20
            ("0xd50323ff", "autibsp"),                     # HINT #31
            ("0xd65f03c0", "ret"),
            # MOVI with vector arrangement
            ("0x4f00e407", "movi v7.16b, #0"),             # MOVI Vd.16B, #0 (Q=1, cmode=1110, op=0)
            # SIMD/FP load-store (Q register)
            ("0x3d800fe7", "str q7, [sp, #0x30]"),         # STR Qt, [Xn, #imm] (size=00, V=1, opc=00 → Q, scale=16)
            ("0xad021fe7", "stp q7, q7, [sp, #0x40]"),     # STP Qt1, Qt2, [Xn, #imm]
            # ADR/ADRP with label operand
            ("0x90000008", "adrp x8, .+0x0"),              # ADRP Xd, #0 (immhi=0, immlo=0)
            ("0x10000020", "adr x0, .+0x4"),               # ADR Xd, .+4 (immhi=0x00001, immlo=0)
            # Conditional branch
            ("0x54000040", "b.eq .+0x8"),                  # B.cond with condition suffix
            ("0x54000061", "b.ne .+0xc"),                  # B.cond NE
            # Condition at end of operand list
            ("0x7a400000", "ccmp w0, w0, #0, eq"),         # CCMP with condition at end
            ("0x1a800000", "csel w0, w0, w0, eq"),         # CSEL with condition at end
            # DMB barrier option
            ("0xd50335bf", "dmb nshld"),                   # DMB with CRm=5 (nshld)
            ("0xd50333bf", "dmb osh"),                     # DMB with CRm=3 (osh)
            ("0xd5033fbf", "dmb sy"),                      # DMB with CRm=15 (sy)
            # LDNP/STNP (non-temporal pair)
            ("0xa8401c26", "ldnp x6, x7, [x1]"),          # LDNP Xt1, Xt2, [Xn]
            ("0xa87f2488", "ldnp x8, x9, [x4, #-0x10]"),  # LDNP with negative offset
            ("0x28402026", "ldnp w6, w8, [x1]"),           # LDNP 32-bit
            # LDR/STR unsigned scaled offset (imm12 * size_bytes)
            ("0xb9431002", "ldr w2, [x0, #0x310]"),        # LDR W: imm12=0xC4, *4 = 0x310
            ("0xf9408402", "ldr x2, [x0, #0x108]"),        # LDR X: imm12=0x21, *8 = 0x108
            ("0xb9400001", "ldr w1, [x0]"),                 # LDR W: imm12=0, no offset
            ("0xf9400001", "ldr x1, [x0]"),                 # LDR X: imm12=0, no offset
            ("0xb9000001", "str w1, [x0]"),                 # STR W: imm12=0
            ("0xb9000421", "str w1, [x1, #4]"),             # STR W: imm12=1, *4 = 4
            ("0xf9000421", "str x1, [x1, #8]"),             # STR X: imm12=1, *8 = 8
            # LDURB/STURB (unscaled byte)
            ("0x385ff08a", "ldurb w10, [x4, #-1]"),        # LDURB with -1 offset
            # LDUR/STUR (unscaled word/dword)
            ("0xb85fc088", "ldur w8, [x4, #-4]"),          # LDUR W with -4 offset
            ("0xb81fc0a8", "stur w8, [x5, #-4]"),          # STUR W with -4 offset
            # Register-offset loads/stores
            ("0x386f6828", "ldrb w8, [x1, x15]"),           # LDRB with register offset (option=3, S=0)
            ("0xf8606820", "ldr x0, [x1, x0]"),            # LDR X with register offset
            ("0xb8606820", "ldr w0, [x1, x0]"),            # LDR W with register offset
            # UBFM aliases (LSR, LSL, UXTB, UXTH)
            ("0xd341fc4f", "lsr x15, x2, #1"),             # UBFM X15, X2, #1, #63 -> LSR (imms=63=regsize-1)
            ("0x53017c08", "lsr w8, w0, #1"),              # UBFM W8, W0, #1, #31 -> LSR (imms=31)
            ("0x53001c00", "uxtb w0, w0"),                 # UBFM W0, W0, #0, #7 -> UXTB
            ("0x53003c00", "uxth w0, w0"),                 # UBFM W0, W0, #0, #15 -> UXTH
            # SBFM aliases (ASR, SXTB, SXTH, SXTW)
            ("0x93401c00", "sxtb x0, w0"),                 # SBFM X0, X0, #0, #7 -> SXTB (W source)
            ("0x93403c00", "sxth x0, w0"),                 # SBFM X0, X0, #0, #15 -> SXTH (W source)
            ("0x93407c00", "sxtw x0, w0"),                 # SBFM X0, X0, #0, #31 -> SXTW (W source)
            ("0x13001c00", "sxtb w0, w0"),                 # SBFM W0, W0, #0, #7 -> SXTB 32-bit
            # BFM aliases
            ("0x33070c00", "bfi w0, w0, #25, #4"),         # BFM with imms < immr -> BFI
            # ADD/SUB extended register (addsub_ext): Rn=31→SP, extend+shift combined
            ("0xeb2f73f0", "subs x16, sp, x15, lsl #4"),   # SUBS Xd, SP, Xm, LSL #4
            ("0x8b2063e0", "add x0, sp, x0"),               # ADD Xd, SP, Xm (default extend suppressed)
            ("0xcb2043e0", "sub x0, sp, w0, uxtw"),         # SUB Xd, SP, Wm, UXTW
            # Logical immediate (64-bit bitmask, decode_bit_masks)
            ("0x9278dc63", "and x3, x3, #0xffffffffffffff00"),  # AND with 64-bit bitmask
            ("0xf278dc7f", "tst x3, #0xffffffffffffff00"),      # TST (ANDS Rd=31) with 64-bit bitmask
            # NEG alias (SUB with Rn=xzr, shifted register form)
            ("0xcb0407e4", "neg x4, x4, lsl #1"),               # NEG Xd, Xm, LSL #1
            # FMOV float-to-int
            ("0x9e660025", "fmov x5, d1"),                      # FMOV Xd, Dn (64D)
            ("0x9e670025", "fmov d5, x1"),                      # FMOV Dd, Xn (D64)
            ("0x1e270000", "fmov s0, w0"),                      # FMOV Sd, Wn (S32)
            ("0x1e260000", "fmov w0, s0"),                      # FMOV Wd, Sn (32S)
            # MOVK with shift in hex
            ("0xf2a0ffe5", "movk x5, #0x7ff, lsl #0x10"),      # MOVK with hw=1 shift
            # PRFM prefetch operation
            ("0xf9800c01", "prfm pldl1strm, [x0, #0x18]"),     # PRFM with prefetch op name
            # SIMD arrangements
            ("0x4e209800", "cmeq v0.16b, v0.16b, #0"),         # CMEQ zero-compare with arrangement
            ("0x4e010c20", "dup v0.16b, w1"),                   # DUP general with arrangement + GPR source
            ("0x4ea31c60", "orr v0.16b, v3.16b, v3.16b"),      # ORR vector (bitwise, always byte arrangement)
            ("0x4e22bc00", "addp v0.16b, v0.16b, v2.16b"),     # ADDP with arrangement
            # Conditional aliases
            ("0x1a9f07e0", "cset w0, ne"),                      # CSET = CSINC Wd, WZR, WZR, invert(cond)
            ("0x5a802400", "cneg w0, w0, lo"),                  # CNEG = CSNEG Wd, Wn, Wn, invert(cond) (lo preferred over cc)
            ("0x1a800400", "cinc w0, w0, ne"),                  # CINC = CSINC Wd, Wn, Wn, invert(cond)
            ("0x5a9f03e0", "csetm w0, ne"),                     # CSETM = CSINV Wd, WZR, WZR, invert(cond)
            ("0x5a800000", "cinv w0, w0, ne"),                  # CINV = CSINV Wd, Wn, Wn, invert(cond)
            # CLREX: optional CRm operand defaults to 15
            ("0xd5033f5f", "clrex"),                            # CLREX with CRm=15 (default, omit operand)
            ("0xd503325f", "clrex #2"),                         # CLREX with CRm=2 (non-default, show operand)
            # SVE predicate LDR/STR: full 9-bit signed immediate with mul vl
            ("0x85800000", "ldr p0, [x0]"),                    # LDR predicate, imm9=0
            ("0x85800400", "ldr p0, [x0, #1, mul vl]"),        # LDR predicate, imm9=1
            ("0x85810000", "ldr p0, [x0, #8, mul vl]"),        # LDR predicate, imm9=8 (imm9h=1)
            ("0xe5800000", "str p0, [x0]"),                    # STR predicate, imm9=0
            # Post-index LDR/STR: [base], #imm ordering
            ("0xb8404423", "ldr w3, [x1], #4"),               # LDR post-index 32-bit
            ("0xf8408681", "ldr x1, [x20], #8"),              # LDR post-index 64-bit
            ("0xf81f84df", "str xzr, [x6], #-8"),             # STR post-index negative
            # MOVZ with hw shift: MOV alias shows shifted value
            ("0x52a00408", "mov w8, #0x200000"),               # MOVZ W8, #0x20, LSL #16
            ("0xd2a00038", "mov x24, #0x10000"),               # MOVZ X24, #1, LSL #16
            # MOVN: MOV alias with complement
            ("0x12b00009", "mov w9, #0x7fffffff"),             # MOVN W9, #0x8000, LSL #16
            # ADD with imm=0 but neither Rd/Rn is SP: stays as add
            ("0x91000108", "add x8, x8, #0"),                  # ADD X8, X8, #0 (not MOV)
            # ADD with SP: stays as MOV alias
            ("0x910003fd", "mov x29, sp"),                     # ADD X29, SP, #0 → MOV
            # IC IALLUIS: no register shown even when Rt≠XZR
            ("0xd5087108", "ic ialluis"),                      # IC IALLUIS (Rt=x8 ignored)
            # TLBI VMALLE1IS: no register shown
            ("0xd5088308", "tlbi vmalle1is"),                  # TLBI VMALLE1IS (Rt=x8 ignored)
            # CFP/CPP/DVP aliases
            ("0xd50b7388", "cfp rctx, x8"),                   # CFP RCTX, X8
            ("0xd50b73e8", "cpp rctx, x8"),                   # CPP RCTX, X8
            ("0xd50b73a8", "dvp rctx, x8"),                   # DVP RCTX, X8
            # SADDV: scalar D destination, governing predicate, SVE source
            ("0x04002001", "saddv d1, p0, z0.b"),              # SADDV D1, P0, Z0.B
        ]

        for insn_hex, expected in test_cases:
            code.append(f"    if (check_disasm({insn_hex}, \"{expected}\")) passed++; else failed++;")

        code.append("")
        code.append("    std::cout << std::endl;")
        code.append("    std::cout << \"Passed: \" << passed << \"/\" << (passed + failed) << std::endl;")
        code.append("    ")
        code.append("    if (failed > 0) {")
        code.append("        std::cerr << \"FAILED: \" << failed << \" test(s)\" << std::endl;")
        code.append("        return 1;")
        code.append("    }")
        code.append("    ")
        code.append("    std::cout << \"All reference tests passed!\" << std::endl;")
        code.append("    return 0;")
        code.append("}")
        code.append("")

        output_file = test_dir / "test_reference.cpp"
        self._write_file(output_file, code)
        print(f"Generated {output_file.name}")

    def generate_hook_test(self, test_dir: Path):
        """Generate test_hook.cpp for the hooking subsystem."""
        code = self._license_header()
        code.append("#include \"veda64.hpp\"")
        code.append("")
        code.append("#if !defined(VEDA64_NO_HOOKS) && (defined(_WIN32) || defined(VEDA64_HOOK_SUPPORT))")
        code.append("")
        code.append("#include <cassert>")
        code.append("#include <cstdint>")
        code.append("#include <cstring>")
        code.append("#include <iostream>")
        code.append("#include <windows.h>")
        code.append("")
        code.append("using namespace veda64;")
        code.append("")

        # ---- Test 1: Initialization lifecycle ----
        code.append("void test_initialization_lifecycle() {")
        code.append("    std::cout << \"  test_initialization_lifecycle...\" << std::endl;")
        code.append("")
        code.append("    // Should not be initialized yet")
        code.append("    hook::shutdown(); // clean slate")
        code.append("    assert(!hook::is_initialized());")
        code.append("")
        code.append("    // Initialize")
        code.append("    auto status = hook::initialize();")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("    assert(hook::is_initialized());")
        code.append("")
        code.append("    // Double-init is idempotent")
        code.append("    status = hook::initialize();")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("    assert(hook::is_initialized());")
        code.append("")
        code.append("    // Shutdown")
        code.append("    hook::shutdown();")
        code.append("    assert(!hook::is_initialized());")
        code.append("")
        code.append("    // Double-shutdown is safe")
        code.append("    hook::shutdown();")
        code.append("    assert(!hook::is_initialized());")
        code.append("}")
        code.append("")

        # ---- Test 2: Configuration round-trip ----
        code.append("void test_configuration() {")
        code.append("    std::cout << \"  test_configuration...\" << std::endl;")
        code.append("")
        code.append("    hook::initialize();")
        code.append("")
        code.append("    hook::HookConfig cfg;")
        code.append("    cfg.min_hook_size = 32;")
        code.append("    cfg.max_relocated_insns = 64;")
        code.append("    cfg.thread_safe = false;")
        code.append("    cfg.preserve_flags = false;")
        code.append("    cfg.allow_chain = true;")
        code.append("    hook::set_config(cfg);")
        code.append("")
        code.append("    auto got = hook::get_config();")
        code.append("    assert(got.min_hook_size == 32);")
        code.append("    assert(got.max_relocated_insns == 64);")
        code.append("    assert(got.thread_safe == false);")
        code.append("    assert(got.preserve_flags == false);")
        code.append("    assert(got.allow_chain == true);")
        code.append("")
        code.append("    hook::shutdown();")
        code.append("}")
        code.append("")

        # ---- Test 3: Status strings ----
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("void test_status_strings() {")
        code.append("    std::cout << \"  test_status_strings...\" << std::endl;")
        code.append("")
        code.append("    assert(hook::status_to_string(hook::HookStatus::Success) != nullptr);")
        code.append("    assert(hook::status_to_string(hook::HookStatus::NotInitialized) != nullptr);")
        code.append("    assert(hook::status_to_string(hook::HookStatus::InvalidTarget) != nullptr);")
        code.append("    assert(hook::status_to_string(hook::HookStatus::InvalidDetour) != nullptr);")
        code.append("    assert(hook::status_to_string(hook::HookStatus::AllocationFailed) != nullptr);")
        code.append("    assert(hook::status_to_string(hook::HookStatus::ProtectionFailed) != nullptr);")
        code.append("    assert(hook::status_to_string(hook::HookStatus::DisassemblyFailed) != nullptr);")
        code.append("    assert(hook::status_to_string(hook::HookStatus::RelocationFailed) != nullptr);")
        code.append("    assert(hook::status_to_string(hook::HookStatus::InstructionTooComplex) != nullptr);")
        code.append("    assert(hook::status_to_string(hook::HookStatus::HookAlreadyInstalled) != nullptr);")
        code.append("    assert(hook::status_to_string(hook::HookStatus::HookNotFound) != nullptr);")
        code.append("    assert(hook::status_to_string(hook::HookStatus::HookDisabled) != nullptr);")
        code.append("    assert(hook::status_to_string(hook::HookStatus::InternalError) != nullptr);")
        code.append("")
        code.append("    // Verify specific strings are not empty")
        code.append("    assert(strlen(hook::status_to_string(hook::HookStatus::Success)) > 0);")
        code.append("    assert(strlen(hook::status_to_string(hook::HookStatus::InternalError)) > 0);")
        code.append("}")
        code.append("#endif")
        code.append("")

        # ---- Test 4: Error handling ----
        code.append("void test_error_handling() {")
        code.append("    std::cout << \"  test_error_handling...\" << std::endl;")
        code.append("")
        code.append("    // Ensure not initialized")
        code.append("    hook::shutdown();")
        code.append("")
        code.append("    // install before initialize should fail")
        code.append("    hook::HookStatus status;")
        code.append("    int dummy_target = 0;")
        code.append("    int dummy_detour = 0;")
        code.append("    void* original = nullptr;")
        code.append("    hook::HookHandle handle = nullptr;")
        code.append("    status = hook::install(reinterpret_cast<void*>(&dummy_target),")
        code.append("                           reinterpret_cast<void*>(&dummy_detour), &original, &handle);")
        code.append("    assert(handle == nullptr);")
        code.append("    assert(status == hook::HookStatus::NotInitialized);")
        code.append("")
        code.append("    // Initialize for remaining tests")
        code.append("    hook::initialize();")
        code.append("")
        code.append("    // null target should fail")
        code.append("    status = hook::install(static_cast<void*>(nullptr),")
        code.append("                           reinterpret_cast<void*>(&dummy_detour), &original, &handle);")
        code.append("    assert(handle == nullptr);")
        code.append("    assert(status == hook::HookStatus::InvalidTarget);")
        code.append("")
        code.append("    // null detour should fail")
        code.append("    status = hook::install(reinterpret_cast<void*>(&dummy_target),")
        code.append("                           static_cast<void*>(nullptr), &original, &handle);")
        code.append("    assert(handle == nullptr);")
        code.append("    assert(status == hook::HookStatus::InvalidDetour);")
        code.append("")
        code.append("    hook::shutdown();")
        code.append("}")
        code.append("")

        # ---- Test 5: Jump generation ----
        code.append("void test_generate_jump() {")
        code.append("    std::cout << \"  test_generate_jump...\" << std::endl;")
        code.append("")
        code.append("    uint8_t buffer[16] = {};")
        code.append("    void* target = reinterpret_cast<void*>(static_cast<uintptr_t>(0xDEADBEEFCAFE0000ULL));")
        code.append("    size_t written = hook::detail::generate_jump(buffer, target);")
        code.append("    (void)written;")
        code.append("")
        code.append("    assert(written == 16);")
        code.append("")
        code.append("    // First instruction: LDR X16, [PC+8] = 0x58000050")
        code.append("    uint32_t insn0;")
        code.append("    memcpy(&insn0, &buffer[0], 4);")
        code.append("    assert(insn0 == 0x58000050);")
        code.append("")
        code.append("    // Second instruction: BR X16 = 0xD61F0200")
        code.append("    uint32_t insn1;")
        code.append("    memcpy(&insn1, &buffer[4], 4);")
        code.append("    assert(insn1 == 0xD61F0200);")
        code.append("")
        code.append("    // Remaining 8 bytes: target address")
        code.append("    uint64_t addr;")
        code.append("    memcpy(&addr, &buffer[8], 8);")
        code.append("    assert(addr == reinterpret_cast<uint64_t>(target));")
        code.append("}")
        code.append("")

        # ---- Test 6: Call generation ----
        code.append("void test_generate_call() {")
        code.append("    std::cout << \"  test_generate_call...\" << std::endl;")
        code.append("")
        code.append("    uint8_t buffer[16] = {};")
        code.append("    void* target = reinterpret_cast<void*>(static_cast<uintptr_t>(0x1234567890ABCDEFULL));")
        code.append("    size_t written = hook::detail::generate_call(buffer, target);")
        code.append("    (void)written;")
        code.append("")
        code.append("    assert(written == 16);")
        code.append("")
        code.append("    // First instruction: LDR X16, [PC+8] = 0x58000050")
        code.append("    uint32_t insn0;")
        code.append("    memcpy(&insn0, &buffer[0], 4);")
        code.append("    assert(insn0 == 0x58000050);")
        code.append("")
        code.append("    // Second instruction: BLR X16 = 0xD63F0200")
        code.append("    uint32_t insn1;")
        code.append("    memcpy(&insn1, &buffer[4], 4);")
        code.append("    assert(insn1 == 0xD63F0200);")
        code.append("")
        code.append("    // Remaining 8 bytes: target address")
        code.append("    uint64_t addr;")
        code.append("    memcpy(&addr, &buffer[8], 8);")
        code.append("    assert(addr == reinterpret_cast<uint64_t>(target));")
        code.append("}")
        code.append("")

        # ---- Test 7: PC-relative detection ----
        code.append("void test_is_pc_relative() {")
        code.append("    std::cout << \"  test_is_pc_relative...\" << std::endl;")
        code.append("")
        code.append("    // PC-relative instructions should return true")
        code.append("    assert(hook::detail::is_pc_relative(0x14000001));  // B .+4")
        code.append("    assert(hook::detail::is_pc_relative(0x97fa94a3));  // BL offset")
        code.append("    assert(hook::detail::is_pc_relative(0x54000040));  // B.EQ .+8")
        code.append("    assert(hook::detail::is_pc_relative(0x34000060));  // CBZ W0, .+0xC")
        code.append("    assert(hook::detail::is_pc_relative(0x35000068));  // CBNZ W8, .+0xC")
        code.append("    assert(hook::detail::is_pc_relative(0x36080040));  // TBZ W0, #1, .+8")
        code.append("    assert(hook::detail::is_pc_relative(0x37f800a0));  // TBNZ X0, #31, .+0x14")
        code.append("    assert(hook::detail::is_pc_relative(0x10000020));  // ADR X0, .+4")
        code.append("    assert(hook::detail::is_pc_relative(0x90000000));  // ADRP X0, current page")
        code.append("")
        code.append("    // Non-PC-relative instructions should return false")
        code.append("    assert(!hook::detail::is_pc_relative(0x8b020020));  // ADD X0, X1, X2")
        code.append("    assert(!hook::detail::is_pc_relative(0x910003fd));  // MOV FP, SP")
        code.append("    assert(!hook::detail::is_pc_relative(0xd503201f));  // NOP")
        code.append("    assert(!hook::detail::is_pc_relative(0xd65f03c0));  // RET")
        code.append("}")
        code.append("")

        # ---- Test 8: Relocation capability ----
        code.append("void test_can_relocate() {")
        code.append("    std::cout << \"  test_can_relocate...\" << std::endl;")
        code.append("")
        code.append("    // Relocatable instructions")
        code.append("    assert(hook::detail::can_relocate(0x14000001));  // B .+4")
        code.append("    assert(hook::detail::can_relocate(0x8b020020));  // ADD X0, X1, X2")
        code.append("    assert(hook::detail::can_relocate(0xd503201f));  // NOP")
        code.append("")
        code.append("    // RET and SVC are position-independent, safe to relocate")
        code.append("    assert(hook::detail::can_relocate(0xd65f03c0));  // RET")
        code.append("    assert(hook::detail::can_relocate(0xd4000001));  // SVC #0")
        code.append("    assert(hook::detail::can_relocate(0x00000000));  // zero padding")
        code.append("")
        code.append("    // Non-relocatable: authenticated returns (PAC-dependent)")
        code.append("    assert(!hook::detail::can_relocate(0xd65f0bff));  // RETAA")
        code.append("")
        code.append("    // Test syscall stub detection")
        code.append("    {")
        code.append("        // NtQuerySystemInformation: SVC #0x36 + RET + 0 + 0")
        code.append("        uint32_t stub1[] = { 0xd40006c1, 0xd65f03c0, 0x00000000, 0x00000000 };")
        code.append("        assert(hook::detail::is_syscall_stub(reinterpret_cast<const uint8_t*>(stub1)));")
        code.append("")
        code.append("        // Not a syscall stub: SVC + NOP + 0 + 0")
        code.append("        uint32_t stub2[] = { 0xd40006c1, 0xd503201f, 0x00000000, 0x00000000 };")
        code.append("        assert(!hook::detail::is_syscall_stub(reinterpret_cast<const uint8_t*>(stub2)));")
        code.append("")
        code.append("        // Not a syscall stub: normal function prologue")
        code.append("        uint32_t stub3[] = { 0xa9bf7bfd, 0x910003fd, 0x8b020020, 0xd65f03c0 };")
        code.append("        assert(!hook::detail::is_syscall_stub(reinterpret_cast<const uint8_t*>(stub3)));")
        code.append("    }")
        code.append("}")
        code.append("")

        # ---- Test 9: Instruction relocation ----
        code.append("void test_relocate_instruction() {")
        code.append("    std::cout << \"  test_relocate_instruction...\" << std::endl;")
        code.append("")
        code.append("    uint32_t out_insn[4];")
        code.append("    size_t out_count;")
        code.append("    bool ok;")
        code.append("")

        # 9a: Non-PC-relative (ADD) copied unchanged
        code.append("    // Non-PC-relative (ADD) should be copied unchanged")
        code.append("    ok = hook::detail::relocate_instruction(0x8b020020, 0x1000, 0x2000, out_insn, &out_count);")
        code.append("    assert(ok);")
        code.append("    assert(out_count == 1);")
        code.append("    assert(out_insn[0] == 0x8b020020);")
        code.append("")

        # 9b: B instruction relocation
        # B .+4 (0x14000001): imm26=1, offset=4, target=old_pc+4
        # old_pc=0x1000, target=0x1004
        # new_pc=0x2000, new_offset=0x1004-0x2000=-0xFFC, new_imm26=-0xFFC/4=-0x3FF=0x03FFFC01
        code.append("    // B .+4 relocated from 0x1000 to 0x2000")
        code.append("    // target=0x1004, new_offset=0x1004-0x2000=-0xFFC")
        code.append("    ok = hook::detail::relocate_instruction(0x14000001, 0x1000, 0x2000, out_insn, &out_count);")
        code.append("    assert(ok);")
        code.append("    assert(out_count == 1);")
        code.append("    // new_imm26 = (-0xFFC / 4) & 0x03FFFFFF = 0x03FFFC01")
        code.append("    assert(out_insn[0] == (0x14000000 | 0x03FFFC01));")
        code.append("")

        # 9c: B.cond relocation
        # B.EQ .+8 (0x54000040): cond=0, imm19=2, offset=8, target=old_pc+8
        # old_pc=0x1000, target=0x1008
        # new_pc=0x3000, new_offset=0x1008-0x3000=-0x1FF8, new_imm19=-0x1FF8/4=-0x7FE
        code.append("    // B.EQ .+8 relocated from 0x1000 to 0x3000")
        code.append("    // target=0x1008, new_offset=0x1008-0x3000=-0x1FF8")
        code.append("    ok = hook::detail::relocate_instruction(0x54000040, 0x1000, 0x3000, out_insn, &out_count);")
        code.append("    assert(ok);")
        code.append("    assert(out_count == 1);")
        code.append("    // new_imm19 = (-0x1FF8 / 4) & 0x7FFFF = 0x7F802")
        code.append("    // encoding: (insn & 0xFF00001F) | (new_imm19 << 5)")
        code.append("    assert(out_insn[0] == (0x54000000 | (0x7F802u << 5)));")
        code.append("")

        # 9d: CBZ relocation
        # CBZ W0, .+0xC (0x34000060): Rt=0, imm19=3, offset=0xC, target=old_pc+0xC
        # old_pc=0x1000, target=0x100C
        # new_pc=0x2000, new_offset=0x100C-0x2000=-0xFF4, new_imm19=-0xFF4/4=-0x3FD
        code.append("    // CBZ W0, .+0xC relocated from 0x1000 to 0x2000")
        code.append("    // target=0x100C, new_offset=0x100C-0x2000=-0xFF4")
        code.append("    ok = hook::detail::relocate_instruction(0x34000060, 0x1000, 0x2000, out_insn, &out_count);")
        code.append("    assert(ok);")
        code.append("    assert(out_count == 1);")
        code.append("    // new_imm19 = (-0xFF4 / 4) & 0x7FFFF = 0x7FC03")
        code.append("    // encoding: (insn & 0xFF00001F) | (new_imm19 << 5)")
        code.append("    assert(out_insn[0] == (0x34000000 | (0x7FC03u << 5)));")
        code.append("")

        # 9e: TBZ relocation
        # TBZ W0, #1, .+8 (0x36080040): b5=0, b40=1, Rt=0, imm14=2, offset=8
        # old_pc=0x1000, target=0x1008
        # new_pc=0x2000, new_offset=0x1008-0x2000=-0xFF8, new_imm14=-0xFF8/4=-0x3FE
        code.append("    // TBZ W0, #1, .+8 relocated from 0x1000 to 0x2000")
        code.append("    // target=0x1008, new_offset=0x1008-0x2000=-0xFF8")
        code.append("    ok = hook::detail::relocate_instruction(0x36080040, 0x1000, 0x2000, out_insn, &out_count);")
        code.append("    assert(ok);")
        code.append("    assert(out_count == 1);")
        code.append("    // new_imm14 = (-0xFF8 / 4) & 0x3FFF = 0x3C02")
        code.append("    // encoding: (insn & 0xFFF8001F) | (new_imm14 << 5)")
        code.append("    assert(out_insn[0] == (0x36080000 | (0x3C02u << 5)));")
        code.append("")

        # 9f: ADR relocation
        # ADR X0, .+4 (0x10000020): Rd=0, immhi=0, immlo=1 -> imm21=0b10=2? No.
        # Actually: ADR encoding: immlo = bits[30:29], immhi = bits[23:5]
        # 0x10000020 = 0001_0000_0000_0000_0000_0000_0010_0000
        # op=0 (ADR), immlo=bits[30:29]=00, immhi=bits[23:5]=0x00001, Rd=bits[4:0]=0x00
        # imm21 = (immhi << 2) | immlo = (1 << 2) | 0 = 4
        # target = old_pc + 4
        code.append("    // ADR X0, .+4 relocated from 0x1000 to 0x5000")
        code.append("    // target=0x1004, new_offset=0x1004-0x5000=-0x3FFC")
        code.append("    ok = hook::detail::relocate_instruction(0x10000020, 0x1000, 0x5000, out_insn, &out_count);")
        code.append("    assert(ok);")
        code.append("    assert(out_count == 1);")
        code.append("    // new_imm21 = -0x3FFC & 0x1FFFFF = 0x1C0004")
        code.append("    // new_immlo = 0x1C0004 & 0x3 = 0")
        code.append("    // new_immhi = (0x1C0004 >> 2) & 0x7FFFF = 0x70001")
        code.append("    // encoding: (insn & 0x9F00001F) | (immlo << 29) | (immhi << 5)")
        code.append("    {")
        code.append("        uint32_t new_imm21 = static_cast<uint32_t>(static_cast<int32_t>(-0x3FFC)) & 0x1FFFFF;")
        code.append("        uint32_t new_immlo = new_imm21 & 0x3;")
        code.append("        uint32_t new_immhi = (new_imm21 >> 2) & 0x7FFFF;")
        code.append("        uint32_t expected = (0x10000020 & 0x9F00001F) | (new_immlo << 29) | (new_immhi << 5);")
        code.append("        (void)expected;")
        code.append("        assert(out_insn[0] == expected);")
        code.append("    }")
        code.append("")

        # 9g: ADRP relocation
        # ADRP X0, current page (0x90000000): Rd=0, immhi=0, immlo=0, imm21=0
        # target = (old_pc & ~0xFFF) + 0 = old_pc page
        code.append("    // ADRP X0, 0 relocated from 0x1000 to 0x5000")
        code.append("    // target_page = (0x1000 & ~0xFFF) + 0 = 0x1000")
        code.append("    // new_offset = 0x1000 - (0x5000 & ~0xFFF) = 0x1000 - 0x5000 = -0x4000")
        code.append("    ok = hook::detail::relocate_instruction(0x90000000, 0x1000, 0x5000, out_insn, &out_count);")
        code.append("    assert(ok);")
        code.append("    assert(out_count == 1);")
        code.append("    {")
        code.append("        // new_imm21 = -0x4000 >> 12 = -4 = 0xFFFFFFFC")
        code.append("        int32_t new_imm21_val = static_cast<int32_t>(-0x4000) >> 12; // -4")
        code.append("        uint32_t new_immlo = static_cast<uint32_t>(new_imm21_val) & 0x3;")
        code.append("        uint32_t new_immhi = (static_cast<uint32_t>(new_imm21_val) >> 2) & 0x7FFFF;")
        code.append("        uint32_t expected = (0x90000000 & 0x9F00001F) | (new_immlo << 29) | (new_immhi << 5);")
        code.append("        (void)expected;")
        code.append("        assert(out_insn[0] == expected);")
        code.append("    }")
        code.append("}")
        code.append("")

        # ---- ARM64-only tests ----
        code.append("#if defined(_M_ARM64) || defined(__aarch64__)")
        code.append("")

        # Test 10: Live hook install/remove
        code.append("static volatile int g_hook_called = 0;")
        code.append("")
        code.append("// Target function must be large enough for the 16-byte hook sequence.")
        code.append("// Use volatile to prevent the compiler from optimizing away the body.")
        code.append("#pragma optimize(\"\", off)")
        code.append("__declspec(noinline) static int target_func(int a, int b) {")
        code.append("    volatile int x = a;")
        code.append("    volatile int y = b;")
        code.append("    volatile int sum = x + y;")
        code.append("    return sum;")
        code.append("}")
        code.append("#pragma optimize(\"\", on)")
        code.append("")
        code.append("static int (*original_func)(int, int) = nullptr;")
        code.append("")
        code.append("static int detour_func(int a, int b) {")
        code.append("    g_hook_called++;")
        code.append("    return original_func(a, b);")
        code.append("}")
        code.append("")
        code.append("// Helper: configure hook for testing (disable thread suspension)")
        code.append("static void setup_test_config() {")
        code.append("    hook::HookConfig cfg;")
        code.append("    cfg.thread_safe = false;  // Avoid NT thread enumeration in tests")
        code.append("    hook::set_config(cfg);")
        code.append("}")
        code.append("")
        code.append("void test_live_hook() {")
        code.append("    std::cout << \"  test_live_hook...\" << std::endl;")
        code.append("")
        code.append("    hook::initialize();")
        code.append("    setup_test_config();")
        code.append("    g_hook_called = 0;")
        code.append("")
        code.append("    // Verify original behavior")
        code.append("    assert(target_func(3, 4) == 7);")
        code.append("    assert(g_hook_called == 0);")
        code.append("")
        code.append("    // Install hook using type-safe template (starts disabled)")
        code.append("    hook::HookHandle handle = nullptr;")
        code.append("    auto status = hook::install(")
        code.append("        &target_func,")
        code.append("        &detour_func,")
        code.append("        &original_func,")
        code.append("        &handle);")
        code.append("    assert(handle != nullptr);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("    assert(!hook::is_enabled(handle));")
        code.append("")
        code.append("    // Enable the hook")
        code.append("    status = hook::enable(handle);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("    assert(hook::is_enabled(handle));")
        code.append("")
        code.append("    // Call through hook - detour should be called")
        code.append("    int result = target_func(3, 4);")
        code.append("    assert(result == 7);")
        code.append("    assert(g_hook_called == 1);")
        code.append("")
        code.append("    // Call original through trampoline")
        code.append("    result = original_func(10, 20);")
        code.append("    assert(result == 30);")
        code.append("    assert(g_hook_called == 1);  // detour not called via trampoline")
        code.append("")
        code.append("    // Remove hook")
        code.append("    auto rem_status = hook::remove(handle);")
        code.append("    (void)rem_status;")
        code.append("    assert(rem_status == hook::HookStatus::Success);")
        code.append("")
        code.append("    // Verify original behavior restored")
        code.append("    g_hook_called = 0;")
        code.append("    result = target_func(5, 6);")
        code.append("    assert(result == 11);")
        code.append("    assert(g_hook_called == 0);")
        code.append("")
        code.append("    hook::shutdown();")
        code.append("}")
        code.append("")

        # Test 11: Hook enable/disable
        code.append("void test_hook_enable_disable() {")
        code.append("    std::cout << \"  test_hook_enable_disable...\" << std::endl;")
        code.append("")
        code.append("    hook::initialize();")
        code.append("    setup_test_config();")
        code.append("    g_hook_called = 0;")
        code.append("")
        code.append("    hook::HookHandle handle = nullptr;")
        code.append("    auto status = hook::install(")
        code.append("        &target_func, &detour_func, &original_func, &handle);")
        code.append("    assert(handle != nullptr);")
        code.append("    assert(!hook::is_enabled(handle));  // Starts disabled")
        code.append("")
        code.append("    // Enable hook first")
        code.append("    status = hook::enable(handle);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("    assert(hook::is_enabled(handle));")
        code.append("")
        code.append("    // Disable hook")
        code.append("    status = hook::disable(handle);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("    assert(!hook::is_enabled(handle));")
        code.append("")
        code.append("    // Call should go to original")
        code.append("    g_hook_called = 0;")
        code.append("    assert(target_func(1, 2) == 3);")
        code.append("    assert(g_hook_called == 0);")
        code.append("")
        code.append("    // Re-enable hook")
        code.append("    status = hook::enable(handle);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("    assert(hook::is_enabled(handle));")
        code.append("")
        code.append("    // Call should go through detour again")
        code.append("    assert(target_func(1, 2) == 3);")
        code.append("    assert(g_hook_called == 1);")
        code.append("")
        code.append("    hook::remove(handle);")
        code.append("    hook::shutdown();")
        code.append("}")
        code.append("")

        # Test 12: Hook info getters
        code.append("void test_hook_info() {")
        code.append("    std::cout << \"  test_hook_info...\" << std::endl;")
        code.append("")
        code.append("    hook::initialize();")
        code.append("    setup_test_config();")
        code.append("")
        code.append("    hook::HookHandle handle = nullptr;")
        code.append("    auto status = hook::install(")
        code.append("        &target_func, &detour_func, &original_func, &handle);")
        code.append("    (void)status;")
        code.append("    assert(handle != nullptr);")
        code.append("")
        code.append("    assert(hook::get_target(handle) == reinterpret_cast<void*>(&target_func));")
        code.append("    assert(hook::get_detour(handle) == reinterpret_cast<void*>(&detour_func));")
        code.append("    assert(hook::get_trampoline(handle) != nullptr);")
        code.append("    assert(hook::get_hook_size(handle) >= 16);")
        code.append("    assert(hook::get_relocated_count(handle) > 0);")
        code.append("")
        code.append("    hook::remove(handle);")
        code.append("    hook::shutdown();")
        code.append("}")
        code.append("")

        # Test 13: Double-hook rejection
        code.append("void test_double_hook_rejection() {")
        code.append("    std::cout << \"  test_double_hook_rejection...\" << std::endl;")
        code.append("")
        code.append("    hook::initialize();")
        code.append("    setup_test_config();")
        code.append("")
        code.append("    int (*orig1)(int, int) = nullptr;")
        code.append("    int (*orig2)(int, int) = nullptr;")
        code.append("    hook::HookHandle handle1 = nullptr;")
        code.append("    hook::HookHandle handle2 = nullptr;")
        code.append("")
        code.append("    auto status = hook::install(")
        code.append("        &target_func, &detour_func, &orig1, &handle1);")
        code.append("    assert(handle1 != nullptr);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("")
        code.append("    // Second hook on same target should fail")
        code.append("    status = hook::install(")
        code.append("        &target_func, &detour_func, &orig2, &handle2);")
        code.append("    assert(handle2 == nullptr);")
        code.append("    assert(status == hook::HookStatus::HookAlreadyInstalled);")
        code.append("")
        code.append("    hook::remove(handle1);")
        code.append("    hook::shutdown();")
        code.append("}")
        code.append("")

        # Test 14: Windows API hook (VirtualAlloc from kernel32.dll)
        # VirtualAlloc is a large function, safe to hook on ARM64
        code.append("using VirtualAlloc_t = LPVOID (WINAPI *)(LPVOID, SIZE_T, DWORD, DWORD);")
        code.append("static VirtualAlloc_t original_VirtualAlloc = nullptr;")
        code.append("static volatile int g_valloc_hook_count = 0;")
        code.append("")
        code.append("static LPVOID WINAPI hooked_VirtualAlloc(LPVOID addr, SIZE_T size, DWORD type, DWORD protect) {")
        code.append("    g_valloc_hook_count++;")
        code.append("    return original_VirtualAlloc(addr, size, type, protect);")
        code.append("}")
        code.append("")
        code.append("void test_winapi_hook() {")
        code.append("    std::cout << \"  test_winapi_hook (VirtualAlloc)...\" << std::endl;")
        code.append("")
        code.append("    hook::initialize();")
        code.append("    setup_test_config();")
        code.append("    g_valloc_hook_count = 0;")
        code.append("")
        code.append("    // Resolve VirtualAlloc address from kernel32")
        code.append("    HMODULE kernel32 = GetModuleHandleA(\"kernel32.dll\");")
        code.append("    assert(kernel32 != nullptr);")
        code.append("    auto target = reinterpret_cast<VirtualAlloc_t>(GetProcAddress(kernel32, \"VirtualAlloc\"));")
        code.append("    assert(target != nullptr);")
        code.append("")
        code.append("    // Install hook — template deduces function type from VirtualAlloc_t")
        code.append("    hook::HookHandle handle = nullptr;")
        code.append("    auto status = hook::install(target, &hooked_VirtualAlloc, &original_VirtualAlloc, &handle);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("")
        code.append("    // Enable and test")
        code.append("    status = hook::enable(handle);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("")
        code.append("    // Allocate memory — should trigger our hook")
        code.append("    LPVOID mem = VirtualAlloc(nullptr, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);")
        code.append("    assert(mem != nullptr);")
        code.append("    assert(g_valloc_hook_count == 1);")
        code.append("")
        code.append("    // Free the memory")
        code.append("    VirtualFree(mem, 0, MEM_RELEASE);")
        code.append("")
        code.append("    // Remove hook and verify unhook works")
        code.append("    hook::remove(handle);")
        code.append("    g_valloc_hook_count = 0;")
        code.append("    mem = VirtualAlloc(nullptr, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);")
        code.append("    assert(mem != nullptr);")
        code.append("    assert(g_valloc_hook_count == 0);  // Hook removed")
        code.append("    VirtualFree(mem, 0, MEM_RELEASE);")
        code.append("")
        code.append("    hook::shutdown();")
        code.append("}")
        code.append("")

        # Test 15: Windows API hook (GetEnvironmentVariableA from kernel32.dll)
        code.append("using GetEnvVarA_t = DWORD (WINAPI *)(LPCSTR, LPSTR, DWORD);")
        code.append("static GetEnvVarA_t original_GetEnvVarA = nullptr;")
        code.append("static volatile int g_getenv_hook_count = 0;")
        code.append("")
        code.append("static DWORD WINAPI hooked_GetEnvVarA(LPCSTR name, LPSTR buf, DWORD size) {")
        code.append("    g_getenv_hook_count++;")
        code.append("    return original_GetEnvVarA(name, buf, size);")
        code.append("}")
        code.append("")
        code.append("void test_winapi_hook_getenv() {")
        code.append("    std::cout << \"  test_winapi_hook (GetEnvironmentVariableA)...\" << std::endl;")
        code.append("")
        code.append("    hook::initialize();")
        code.append("    setup_test_config();")
        code.append("    g_getenv_hook_count = 0;")
        code.append("")
        code.append("    HMODULE kernel32 = GetModuleHandleA(\"kernel32.dll\");")
        code.append("    assert(kernel32 != nullptr);")
        code.append("    auto target = reinterpret_cast<GetEnvVarA_t>(GetProcAddress(kernel32, \"GetEnvironmentVariableA\"));")
        code.append("    assert(target != nullptr);")
        code.append("")
        code.append("    // Install hook — template deduces function type from GetEnvVarA_t")
        code.append("    hook::HookHandle handle = nullptr;")
        code.append("    auto status = hook::install(target, &hooked_GetEnvVarA, &original_GetEnvVarA, &handle);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("")
        code.append("    status = hook::enable(handle);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("")
        code.append("    // Query an environment variable — should trigger our hook")
        code.append("    char buf[256];")
        code.append("    GetEnvironmentVariableA(\"PATH\", buf, sizeof(buf));")
        code.append("    assert(g_getenv_hook_count == 1);")
        code.append("")
        code.append("    hook::remove(handle);")
        code.append("    hook::shutdown();")
        code.append("}")
        code.append("")

        # Test 16: NT syscall hook (NtClose)
        code.append("void test_syscall_hook() {")
        code.append("    std::cout << \"  test_syscall_hook (NtClose)...\" << std::endl;")
        code.append("")
        code.append("    hook::initialize();")
        code.append("    setup_test_config();")
        code.append("")
        code.append("    // NtClose signature: NTSTATUS NTAPI NtClose(HANDLE Handle)")
        code.append("    typedef LONG NTSTATUS;")
        code.append("    typedef NTSTATUS (NTAPI *NtClose_t)(HANDLE);")
        code.append("")
        code.append("    static NtClose_t original_NtClose = nullptr;")
        code.append("    static volatile int close_hook_count = 0;")
        code.append("")
        code.append("    struct SyscallDetours {")
        code.append("        static NTSTATUS NTAPI hooked_NtClose(HANDLE h) {")
        code.append("            close_hook_count++;")
        code.append("            return original_NtClose(h);")
        code.append("        }")
        code.append("    };")
        code.append("")
        code.append("    // Resolve NtClose from ntdll.dll")
        code.append("    HMODULE ntdll = GetModuleHandleA(\"ntdll.dll\");")
        code.append("    assert(ntdll != nullptr);")
        code.append("    auto target = reinterpret_cast<NtClose_t>(GetProcAddress(ntdll, \"NtClose\"));")
        code.append("    assert(target != nullptr);")
        code.append("")
        code.append("    // Install and enable hook — template deduces type from NtClose_t")
        code.append("    hook::HookHandle handle = nullptr;")
        code.append("    NtClose_t detour = &SyscallDetours::hooked_NtClose;")
        code.append("    auto status = hook::install(target, detour, &original_NtClose, &handle);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("")
        code.append("    status = hook::enable(handle);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("")
        code.append("    // Create a dummy event handle and close it — triggers NtClose")
        code.append("    HANDLE evt = CreateEventA(nullptr, FALSE, FALSE, nullptr);")
        code.append("    assert(evt != nullptr);")
        code.append("    close_hook_count = 0;")
        code.append("    CloseHandle(evt);  // This calls NtClose internally")
        code.append("    assert(close_hook_count > 0);")
        code.append("")
        code.append("    // Remove hook and verify normal operation")
        code.append("    hook::remove(handle);")
        code.append("    close_hook_count = 0;")
        code.append("    evt = CreateEventA(nullptr, FALSE, FALSE, nullptr);")
        code.append("    assert(evt != nullptr);")
        code.append("    CloseHandle(evt);")
        code.append("    assert(close_hook_count == 0);  // Hook removed, counter stays 0")
        code.append("")
        code.append("    hook::shutdown();")
        code.append("}")
        code.append("")

        # Test 17: NT syscall hook (NtQueryVirtualMemory)
        code.append("void test_syscall_hook_query_memory() {")
        code.append("    std::cout << \"  test_syscall_hook (NtQueryVirtualMemory)...\" << std::endl;")
        code.append("")
        code.append("    hook::initialize();")
        code.append("    setup_test_config();")
        code.append("")
        code.append("    typedef LONG NTSTATUS;")
        code.append("    typedef NTSTATUS (NTAPI *NtQueryVirtualMemory_t)(")
        code.append("        HANDLE ProcessHandle, PVOID BaseAddress,")
        code.append("        ULONG MemoryInformationClass, PVOID MemoryInformation,")
        code.append("        SIZE_T MemoryInformationLength, PSIZE_T ReturnLength);")
        code.append("")
        code.append("    static NtQueryVirtualMemory_t original_NtQueryVirtualMemory = nullptr;")
        code.append("    static volatile int query_hook_count = 0;")
        code.append("")
        code.append("    struct SyscallDetours {")
        code.append("        static NTSTATUS NTAPI hooked_NtQueryVirtualMemory(")
        code.append("            HANDLE ProcessHandle, PVOID BaseAddress,")
        code.append("            ULONG MemoryInformationClass, PVOID MemoryInformation,")
        code.append("            SIZE_T MemoryInformationLength, PSIZE_T ReturnLength) {")
        code.append("            query_hook_count++;")
        code.append("            return original_NtQueryVirtualMemory(ProcessHandle, BaseAddress,")
        code.append("                MemoryInformationClass, MemoryInformation,")
        code.append("                MemoryInformationLength, ReturnLength);")
        code.append("        }")
        code.append("    };")
        code.append("")
        code.append("    HMODULE ntdll = GetModuleHandleA(\"ntdll.dll\");")
        code.append("    assert(ntdll != nullptr);")
        code.append("    auto target = reinterpret_cast<NtQueryVirtualMemory_t>(GetProcAddress(ntdll, \"NtQueryVirtualMemory\"));")
        code.append("    assert(target != nullptr);")
        code.append("")
        code.append("    NtQueryVirtualMemory_t detour = &SyscallDetours::hooked_NtQueryVirtualMemory;")
        code.append("    hook::HookHandle handle = nullptr;")
        code.append("    auto status = hook::install(target, detour, &original_NtQueryVirtualMemory, &handle);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("")
        code.append("    status = hook::enable(handle);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("")
        code.append("    // Query memory info for our own module — triggers the hook")
        code.append("    MEMORY_BASIC_INFORMATION mbi = {};")
        code.append("    query_hook_count = 0;")
        code.append("    VirtualQuery(GetModuleHandleA(nullptr), &mbi, sizeof(mbi));")
        code.append("    assert(query_hook_count > 0);")
        code.append("")
        code.append("    hook::remove(handle);")
        code.append("    hook::shutdown();")
        code.append("}")
        code.append("")

        code.append("#endif // _M_ARM64 || __aarch64__")
        code.append("")

        # ---- main() ----
        code.append("int main() {")
        code.append("    std::cout << \"Running hook tests...\" << std::endl;")
        code.append("")
        code.append("    // Cross-platform tests")
        code.append("    test_initialization_lifecycle();")
        code.append("    test_configuration();")
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("    test_status_strings();")
        code.append("#endif")
        code.append("    test_error_handling();")
        code.append("    test_generate_jump();")
        code.append("    test_generate_call();")
        code.append("    test_is_pc_relative();")
        code.append("    test_can_relocate();")
        code.append("    test_relocate_instruction();")
        code.append("")
        code.append("    // ARM64-only tests")
        code.append("#if defined(_M_ARM64) || defined(__aarch64__)")
        code.append("    test_live_hook();")
        code.append("    test_hook_enable_disable();")
        code.append("    test_hook_info();")
        code.append("    test_double_hook_rejection();")
        code.append("    test_winapi_hook();")
        code.append("    test_winapi_hook_getenv();")
        code.append("    test_syscall_hook();")
        code.append("    test_syscall_hook_query_memory();")
        code.append("#else")
        code.append("    std::cout << \"  (ARM64-only tests skipped on this platform)\" << std::endl;")
        code.append("#endif")
        code.append("")
        code.append("    std::cout << \"All hook tests passed!\" << std::endl;")
        code.append("    return 0;")
        code.append("}")
        code.append("")
        code.append("#else // VEDA64_NO_HOOKS || !(_WIN32 || VEDA64_HOOK_SUPPORT)")
        code.append("")
        code.append("// Hook support not available on this platform")
        code.append("#include <iostream>")
        code.append("int main() {")
        code.append("    std::cout << \"Hook tests skipped (hooks disabled or not on Windows)\" << std::endl;")
        code.append("    return 0;")
        code.append("}")
        code.append("")
        code.append("#endif // !VEDA64_NO_HOOKS && (_WIN32 || VEDA64_HOOK_SUPPORT)")
        code.append("")

        output_file = test_dir / "test_hook.cpp"
        self._write_file(output_file, code)
        print(f"Generated {output_file.name}")

    def generate_hook_examples(self, test_dir: Path):
        """Generate comprehensive hook examples for Windows ARM64."""
        self._generate_hook_examples_cpp(test_dir)

    def _generate_hook_examples_cpp(self, test_dir: Path):
        """Generate hook_examples.cpp implementation file."""
        code = self._license_header()
        code.append("")
        code.append("#include \"veda64.hpp\"")
        code.append("")
        code.append("#if !defined(VEDA64_NO_HOOKS) && defined(_WIN32) && (defined(_M_ARM64) || defined(__aarch64__))")
        code.append("#include <iostream>")
        code.append("#include <string>")
        code.append("#include <vector>")
        code.append("#include <chrono>")
        code.append("#include <mutex>")
        code.append("#include <windows.h>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("namespace examples {")
        code.append("")

        # Example 1: Logging Hook implementation
        code.append("// ============================================================================")
        code.append("// Example 1: LoggingHook")
        code.append("// Intercepts function calls and logs parameters with timestamps")
        code.append("// ============================================================================")
        code.append("namespace logging_hook {")
        code.append("")
        code.append("struct LogEntry {")
        code.append("    std::chrono::system_clock::time_point timestamp;")
        code.append("    int arg1, arg2, result;")
        code.append("};")
        code.append("")
        code.append("static int (*original_func)(int, int) = nullptr;")
        code.append("static hook::HookHandle hook_handle = nullptr;")
        code.append("static std::mutex log_mutex;")
        code.append("static std::vector<LogEntry> call_log;")
        code.append("")
        code.append("static int detour_func(int a, int b) {")
        code.append("    auto start = std::chrono::system_clock::now();")
        code.append("    int result = original_func(a, b);")
        code.append("    std::lock_guard<std::mutex> lock(log_mutex);")
        code.append("    call_log.push_back({start, a, b, result});")
        code.append("    return result;")
        code.append("}")
        code.append("")
        code.append("using TargetFunc = int (*)(int, int);")
        code.append("")
        code.append("bool install(TargetFunc target) {")
        code.append("    auto status = hook::install(target, &detour_func, &original_func, &hook_handle);")
        code.append("    if (status != hook::HookStatus::Success) return false;")
        code.append("    return hook::enable(hook_handle) == hook::HookStatus::Success;")
        code.append("}")
        code.append("")
        code.append("std::vector<LogEntry> uninstall() {")
        code.append("    if (hook_handle) { hook::remove(hook_handle); hook_handle = nullptr; }")
        code.append("    std::lock_guard<std::mutex> lock(log_mutex);")
        code.append("    auto result = std::move(call_log);")
        code.append("    call_log.clear();")
        code.append("    return result;")
        code.append("}")
        code.append("")
        code.append("void clear_log() {")
        code.append("    std::lock_guard<std::mutex> lock(log_mutex);")
        code.append("    call_log.clear();")
        code.append("}")
        code.append("")
        code.append("} // namespace logging_hook")
        code.append("")

        # Example 2: Validation Hook implementation
        code.append("// ============================================================================")
        code.append("// Example 2: ValidationHook")
        code.append("// Validates allocation sizes and rejects oversized requests")
        code.append("// ============================================================================")
        code.append("namespace validation_hook {")
        code.append("")
        code.append("struct Stats { size_t total_bytes, alloc_count, reject_count; };")
        code.append("")
        code.append("static void* (*original_alloc)(size_t) = nullptr;")
        code.append("static hook::HookHandle hook_handle = nullptr;")
        code.append("static size_t max_alloc_size = 100 * 1024 * 1024;")
        code.append("static bool log_allocations = false;")
        code.append("static size_t total_allocated = 0;")
        code.append("static size_t allocation_count = 0;")
        code.append("static size_t rejected_count = 0;")
        code.append("")
        code.append("static void* detour_alloc(size_t size) {")
        code.append("    if (size > max_alloc_size) {")
        code.append("        rejected_count++;")
        code.append("        if (log_allocations) std::cerr << \"[ValidationHook] Rejected: \" << size << std::endl;")
        code.append("        return Arrangement::None;")
        code.append("    }")
        code.append("    void* result = original_alloc(size);")
        code.append("    if (result) { total_allocated += size; allocation_count++; }")
        code.append("    return result;")
        code.append("}")
        code.append("")
        code.append("using AllocFunc = void* (*)(size_t);")
        code.append("")
        code.append("bool install(AllocFunc target, size_t max_size) {")
        code.append("    max_alloc_size = max_size;")
        code.append("    auto status = hook::install(target, &detour_alloc, &original_alloc, &hook_handle);")
        code.append("    if (status != hook::HookStatus::Success) return false;")
        code.append("    return hook::enable(hook_handle) == hook::HookStatus::Success;")
        code.append("}")
        code.append("")
        code.append("void uninstall() { if (hook_handle) { hook::remove(hook_handle); hook_handle = nullptr; } }")
        code.append("void set_logging(bool enable) { log_allocations = enable; }")
        code.append("Stats get_stats() { return {total_allocated, allocation_count, rejected_count}; }")
        code.append("void reset_stats() { total_allocated = allocation_count = rejected_count = 0; }")
        code.append("")
        code.append("} // namespace validation_hook")
        code.append("")

        # Example 3: Return Modify Hook implementation
        code.append("// ============================================================================")
        code.append("// ReturnModifyHook Implementation")
        code.append("// ============================================================================")
        code.append("namespace return_modify_hook {")
        code.append("")
        code.append("static BOOL (WINAPI *original_func)() = nullptr;")
        code.append("static hook::HookHandle hook_handle = nullptr;")
        code.append("static bool force_result = false;")
        code.append("static BOOL forced_value = FALSE;")
        code.append("")
        code.append("static BOOL WINAPI detour_func() {")
        code.append("    return force_result ? forced_value : original_func();")
        code.append("}")
        code.append("")
        code.append("using IsDebuggerPresent_t = BOOL (WINAPI *)();")
        code.append("")
        code.append("bool install() {")
        code.append("    HMODULE kernel32 = GetModuleHandleA(\"kernel32.dll\");")
        code.append("    if (!kernel32) return false;")
        code.append("    auto target = reinterpret_cast<IsDebuggerPresent_t>(GetProcAddress(kernel32, \"IsDebuggerPresent\"));")
        code.append("    if (!target) return false;")
        code.append("    auto status = hook::install(target, &detour_func, &original_func, &hook_handle);")
        code.append("    if (status != hook::HookStatus::Success) return false;")
        code.append("    return hook::enable(hook_handle) == hook::HookStatus::Success;")
        code.append("}")
        code.append("")
        code.append("void uninstall() { if (hook_handle) { hook::remove(hook_handle); hook_handle = nullptr; } }")
        code.append("void set_forced_result(bool enable, BOOL value) { force_result = enable; forced_value = value; }")
        code.append("")
        code.append("} // namespace return_modify_hook")
        code.append("")

        # Example 4: String Hook implementation
        code.append("// ============================================================================")
        code.append("// StringHook Implementation")
        code.append("// ============================================================================")
        code.append("namespace string_hook {")
        code.append("")
        code.append("typedef HANDLE (WINAPI *CreateFileAFunc)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);")
        code.append("static CreateFileAFunc original_func = nullptr;")
        code.append("static hook::HookHandle hook_handle = nullptr;")
        code.append("static FileAccessCallback callback = nullptr;")
        code.append("static std::string redirect_from;")
        code.append("static std::string redirect_to;")
        code.append("")
        code.append("static HANDLE WINAPI detour_func(LPCSTR lpFileName, DWORD dwAccess, DWORD dwShare,")
        code.append("    LPSECURITY_ATTRIBUTES lpSec, DWORD dwCreate, DWORD dwFlags, HANDLE hTemplate) {")
        code.append("    if (callback) callback(lpFileName, dwAccess);")
        code.append("    if (!redirect_from.empty()) {")
        code.append("        std::string path(lpFileName);")
        code.append("        if (path.find(redirect_from) == 0) {")
        code.append("            path = redirect_to + path.substr(redirect_from.length());")
        code.append("            return original_func(path.c_str(), dwAccess, dwShare, lpSec, dwCreate, dwFlags, hTemplate);")
        code.append("        }")
        code.append("    }")
        code.append("    return original_func(lpFileName, dwAccess, dwShare, lpSec, dwCreate, dwFlags, hTemplate);")
        code.append("}")
        code.append("")
        code.append("bool install() {")
        code.append("    HMODULE kernel32 = GetModuleHandleA(\"kernel32.dll\");")
        code.append("    if (!kernel32) return false;")
        code.append("    auto target = reinterpret_cast<CreateFileAFunc>(GetProcAddress(kernel32, \"CreateFileA\"));")
        code.append("    if (!target) return false;")
        code.append("    auto status = hook::install(target, &detour_func, &original_func, &hook_handle);")
        code.append("    if (status != hook::HookStatus::Success) return false;")
        code.append("    return hook::enable(hook_handle) == hook::HookStatus::Success;")
        code.append("}")
        code.append("")
        code.append("void uninstall() { if (hook_handle) { hook::remove(hook_handle); hook_handle = nullptr; } }")
        code.append("void set_callback(FileAccessCallback cb) { callback = cb; }")
        code.append("void set_redirect(const std::string& from, const std::string& to) { redirect_from = from; redirect_to = to; }")
        code.append("")
        code.append("} // namespace string_hook")
        code.append("")

        # Example 5: Profiling Hook implementation
        code.append("// ============================================================================")
        code.append("// Example 5: ProfilingHook")
        code.append("// Measures function execution time with high-resolution timer")
        code.append("// ============================================================================")
        code.append("namespace profiling_hook {")
        code.append("")
        code.append("struct ProfileData { uint64_t call_count, total_ticks, min_ticks, max_ticks; };")
        code.append("")
        code.append("typedef int (*TargetFuncType)(int);")
        code.append("static TargetFuncType original_func = nullptr;")
        code.append("static hook::HookHandle hook_handle = nullptr;")
        code.append("static ProfileData data = {0, 0, UINT64_MAX, 0};")
        code.append("static std::mutex mtx;")
        code.append("")
        code.append("static int detour_func(int arg) {")
        code.append("    LARGE_INTEGER start, end;")
        code.append("    QueryPerformanceCounter(&start);")
        code.append("    int result = original_func(arg);")
        code.append("    QueryPerformanceCounter(&end);")
        code.append("    uint64_t elapsed = end.QuadPart - start.QuadPart;")
        code.append("    std::lock_guard<std::mutex> lock(mtx);")
        code.append("    data.call_count++;")
        code.append("    data.total_ticks += elapsed;")
        code.append("    if (elapsed < data.min_ticks) data.min_ticks = elapsed;")
        code.append("    if (elapsed > data.max_ticks) data.max_ticks = elapsed;")
        code.append("    return result;")
        code.append("}")
        code.append("")
        code.append("bool install(TargetFuncType target) {")
        code.append("    auto status = hook::install(target, &detour_func, &original_func, &hook_handle);")
        code.append("    if (status != hook::HookStatus::Success) return false;")
        code.append("    return hook::enable(hook_handle) == hook::HookStatus::Success;")
        code.append("}")
        code.append("")
        code.append("void uninstall() { if (hook_handle) { hook::remove(hook_handle); hook_handle = nullptr; } }")
        code.append("ProfileData get_data() { std::lock_guard<std::mutex> lock(mtx); return data; }")
        code.append("void reset() { std::lock_guard<std::mutex> lock(mtx); data = {0, 0, UINT64_MAX, 0}; }")
        code.append("")
        code.append("double get_average_ms() {")
        code.append("    LARGE_INTEGER freq;")
        code.append("    QueryPerformanceFrequency(&freq);")
        code.append("    std::lock_guard<std::mutex> lock(mtx);")
        code.append("    if (data.call_count == 0) return 0.0;")
        code.append("    return (double)data.total_ticks / data.call_count / freq.QuadPart * 1000.0;")
        code.append("}")
        code.append("")
        code.append("} // namespace profiling_hook")
        code.append("")

        # Example 6: Conditional Hook implementation
        code.append("// ============================================================================")
        code.append("// ConditionalHook Implementation")
        code.append("// ============================================================================")
        code.append("namespace conditional_hook {")
        code.append("")
        code.append("static DWORD (WINAPI *original_sleep)(DWORD) = nullptr;")
        code.append("static hook::HookHandle hook_handle = nullptr;")
        code.append("static bool skip_long = false;")
        code.append("static DWORD max_ms = 1000;")
        code.append("static bool accelerate = false;")
        code.append("static float accel_factor = 10.0f;")
        code.append("")
        code.append("static DWORD WINAPI detour_sleep(DWORD ms) {")
        code.append("    if (skip_long && ms > max_ms) return 0;")
        code.append("    if (accelerate) { ms = static_cast<DWORD>(ms / accel_factor); if (ms == 0) ms = 1; }")
        code.append("    return original_sleep(ms);")
        code.append("}")
        code.append("")
        code.append("using Sleep_t = DWORD (WINAPI *)(DWORD);")
        code.append("")
        code.append("bool install() {")
        code.append("    HMODULE kernel32 = GetModuleHandleA(\"kernel32.dll\");")
        code.append("    if (!kernel32) return false;")
        code.append("    auto target = reinterpret_cast<Sleep_t>(GetProcAddress(kernel32, \"Sleep\"));")
        code.append("    if (!target) return false;")
        code.append("    auto status = hook::install(target, &detour_sleep, &original_sleep, &hook_handle);")
        code.append("    if (status != hook::HookStatus::Success) return false;")
        code.append("    return hook::enable(hook_handle) == hook::HookStatus::Success;")
        code.append("}")
        code.append("")
        code.append("void uninstall() { if (hook_handle) { hook::remove(hook_handle); hook_handle = nullptr; } }")
        code.append("void configure(bool skip, DWORD max, bool acc, float f) { skip_long = skip; max_ms = max; accelerate = acc; accel_factor = f; }")
        code.append("")
        code.append("} // namespace conditional_hook")
        code.append("")

        # Example 7: Hook Manager class
        code.append("// ============================================================================")
        code.append("// Example 7: HookManager")
        code.append("// Manages multiple hooks with automatic cleanup")
        code.append("// ============================================================================")
        code.append("class HookManager {")
        code.append("public:")
        code.append("    struct HookInfo {")
        code.append("        hook::HookHandle handle;")
        code.append("        std::string name;")
        code.append("        void* target;")
        code.append("        void* detour;")
        code.append("        bool enabled;")
        code.append("    };")
        code.append("")
        code.append("    HookManager() { hook::initialize(); }")
        code.append("    ~HookManager() { remove_all(); }")
        code.append("")
        code.append("    bool add(const std::string& name, void* target, void* detour, void** original) {")
        code.append("        std::lock_guard<std::mutex> lock(mutex_);")
        code.append("        hook::HookHandle h = nullptr;")
        code.append("        auto status = hook::install(target, detour, original, &h);")
        code.append("        if (status != hook::HookStatus::Success) return false;")
        code.append("        if (hook::enable(h) != hook::HookStatus::Success) { hook::remove(h); return false; }")
        code.append("        hooks_.push_back({h, name, target, detour, true});")
        code.append("        return true;")
        code.append("    }")
        code.append("")
        code.append("    bool remove(const std::string& name) {")
        code.append("        std::lock_guard<std::mutex> lock(mutex_);")
        code.append("        for (auto it = hooks_.begin(); it != hooks_.end(); ++it) {")
        code.append("            if (it->name == name) { hook::remove(it->handle); hooks_.erase(it); return true; }")
        code.append("        }")
        code.append("        return false;")
        code.append("    }")
        code.append("")
        code.append("    void remove_all() {")
        code.append("        std::lock_guard<std::mutex> lock(mutex_);")
        code.append("        for (auto& info : hooks_) hook::remove(info.handle);")
        code.append("        hooks_.clear();")
        code.append("    }")
        code.append("")
        code.append("    bool enable(const std::string& name) {")
        code.append("        std::lock_guard<std::mutex> lock(mutex_);")
        code.append("        for (auto& info : hooks_) {")
        code.append("            if (info.name == name) {")
        code.append("                info.enabled = (hook::enable(info.handle) == hook::HookStatus::Success);")
        code.append("                return info.enabled;")
        code.append("            }")
        code.append("        }")
        code.append("        return false;")
        code.append("    }")
        code.append("")
        code.append("    bool disable(const std::string& name) {")
        code.append("        std::lock_guard<std::mutex> lock(mutex_);")
        code.append("        for (auto& info : hooks_) {")
        code.append("            if (info.name == name) {")
        code.append("                if (hook::disable(info.handle) == hook::HookStatus::Success) {")
        code.append("                    info.enabled = false; return true;")
        code.append("                }")
        code.append("                return false;")
        code.append("            }")
        code.append("        }")
        code.append("        return false;")
        code.append("    }")
        code.append("")
        code.append("    void print_status() const {")
        code.append("        std::cout << \"=== HookManager (\" << hooks_.size() << \" hooks) ===\" << std::endl;")
        code.append("        for (const auto& info : hooks_)")
        code.append("            std::cout << \"  \" << info.name << \" [\" << (info.enabled ? \"on\" : \"off\") << \"]\" << std::endl;")
        code.append("    }")
        code.append("")
        code.append("    size_t count() const { return hooks_.size(); }")
        code.append("")
        code.append("private:")
        code.append("    std::vector<HookInfo> hooks_;")
        code.append("    mutable std::mutex mutex_;")
        code.append("};")
        code.append("")

        # Close namespaces and ifdef
        code.append("} // namespace examples")
        code.append("} // namespace veda64")
        code.append("")
        code.append("#endif // !VEDA64_NO_HOOKS && Windows ARM64")
        code.append("")

        output_file = test_dir / "hook_examples.cpp"
        self._write_file(output_file, code)
        print(f"Generated {output_file.name}")

def main():
    """Main entry point."""
    # Use the 2025-12 version (latest)
    xml_dir = Path(__file__).parent / "arm64" / "ISA_A64_xml_A_profile-2025-12"

    if not xml_dir.exists():
        # Fallback to 2025-09 version
        xml_dir = Path(__file__).parent / "arm64" / "ISA_A64_xml_A_profile-2025-09"

    if not xml_dir.exists():
        print(f"Error: XML directory not found: {xml_dir}")
        return

    print(f"Parsing XML files from: {xml_dir}")

    # Parse all XML files
    parser = ARM64XMLParser(xml_dir)
    parser.parse_all()

    # Print summary
    parser.print_summary()

    # Create output directories
    base_dir = Path(__file__).parent
    include_dir = base_dir / "include"
    include_format_dir = include_dir / "format"
    lib_dir = base_dir / "lib"
    lib_format_dir = lib_dir / "format"
    test_dir = base_dir / "test"
    include_dir.mkdir(exist_ok=True)
    include_format_dir.mkdir(exist_ok=True)
    lib_dir.mkdir(exist_ok=True)
    lib_format_dir.mkdir(exist_ok=True)
    test_dir.mkdir(exist_ok=True)

    # Note: class/ folder generation is deprecated and disabled

    # Generate base headers (veda64.hpp) and implementation
    parser.generate_header_files(include_dir, lib_dir)

    # Generate format-based files (organized by encoding format)
    parser.generate_format_files(include_format_dir, lib_format_dir)

    # Generate hook files (Windows ARM64 API hooking)
    print(f"\n=== Generating Hook Files ===")
    parser.generate_hook_files(include_dir, lib_dir)

    # Hook implementation is generated independently as lib/hook.cpp

    # Generate CMake build files
    print(f"\n=== Generating CMake Build Files ===")
    parser.generate_cmake_files(base_dir, test_dir)
    print(f"Generated CMakeLists.txt")

    # Generate test suite
    print(f"\n=== Generating Test Suite ===")
    parser.generate_encoding_tests(test_dir)
    parser.generate_undef_tests(test_dir)
    parser.generate_reference_test(test_dir)
    parser.generate_hook_test(test_dir)
    parser.generate_hook_examples(test_dir)
    print(f"Generated test files")

    # Generate tools
    print(f"\n=== Generating Tools ===")
    tools_dir = base_dir / "tools"
    parser.generate_disasm_tool(tools_dir)

    # Generate Python bindings
    print(f"\n=== Generating Python Bindings ===")
    parser.generate_python_bindings(base_dir)

    # Validate ASL IR parser against all encodings
    # Validate execute pseudocode parsing + C++ emission
if __name__ == '__main__':
    main()
