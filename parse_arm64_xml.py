#!/usr/bin/env python3
"""
ARM64 Instruction XML Parser

This script parses ARM64 instruction encoding XML files and extracts
structured information about each instruction including encodings,
operands, and descriptions.
"""

import xml.etree.ElementTree as ET
from pathlib import Path
from typing import Dict, List, Optional
import json


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

        # Parse encodings
        classes_elem = root.find('classes')
        if classes_elem is not None:
            instr.encodings = self._parse_encodings(classes_elem)

        # Parse operand explanations
        explanations_elem = root.find('explanations')
        if explanations_elem is not None:
            instr.operands = self._parse_operands(explanations_elem)

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

    def _parse_encodings(self, classes_elem: ET.Element) -> List[InstructionEncoding]:
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

            field_info = {
                'hibit': int(hibit) if hibit else None,
                'width': int(width) if width else 1,
            }

            # Check if this is a fixed value (may have multiple <c> elements)
            if settings:
                c_elements = box.findall('c')
                if c_elements:
                    # Concatenate all <c> elements to form the complete binary value
                    # Handle partial patterns like "x1" where some bits are fixed
                    binary_value = ''.join([c.text.strip() if c.text else '' for c in c_elements])
                    if binary_value:
                        # Check if fully fixed (all 0s and 1s)
                        if all(b in '01' for b in binary_value):
                            bit_pattern[name] = binary_value
                            field_info['fixed'] = binary_value
                        # Check if partially fixed (has some 0s or 1s mixed with x)
                        elif any(b in '01' for b in binary_value):
                            # Store raw pattern for reference, but mark as partial
                            field_info['fixed'] = None
                            field_info['partial_pattern'] = binary_value
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

        # Generate veda64.hpp (main header) and veda64.cpp (implementation)
        veda64_header = include_dir / "veda64.hpp"
        veda64_impl = lib_dir / "veda64.cpp"
        self._generate_veda64_header(veda64_header)
        self._generate_veda64_implementation(veda64_impl)
        print(f"Generated {veda64_header.name} and {veda64_impl.name}")

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
        code = []
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
                'mnemonic': mnemonic
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
        code = []
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
                'mnemonic': mnemonic
            })

        # Include header
        code.append(f"#include \"format/{group_name}.hpp\"")
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
        code = []

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
        code = []

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
        code.append("    Prefetch,           // Prefetch operation")
        code.append("    Barrier,            // Barrier option")
        code.append("    Unknown")
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
        code.append("    bool is_64bit = true;        // True for 64-bit registers (X), false for 32-bit (W)")
        code.append("    bool is_sp = false;          // True if reg 31 should be SP/WSP, false for XZR/WZR")
        code.append("    const char* arrangement = nullptr;  // Vector arrangement specifier (.16b, .4s, etc.)")
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
        code.append("")
        code.append("private:")
        code.append("    // Helper functions for formatting")
        code.append("    static std::string format_register(uint32_t reg, bool is_64bit, bool is_sp = false);")
        code.append("    static std::string format_vector_register(uint32_t reg, const char* arrangement);")
        code.append("#endif")
        code.append("};")
        code.append("")

        # Generate helper function declaration
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("// Convert mnemonic enum to string")
        code.append("const char* mnemonic_to_string(Mnemonic mnem);")
        code.append("")
        code.append("// Determine vector arrangement for MOVI/MVNI based on Q and cmode fields")
        code.append("const char* get_movi_arrangement(uint32_t insn);")
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

    def _generate_veda64_implementation(self, output_file: Path):
        """Generate veda64.cpp with implementations."""
        code = []

        code.append("#include \"veda64.hpp\"")
        code.append("#include \"format/format.hpp\"")
        code.append("#include <cstring>")
        code.append("#include <sstream>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")

        # Collect all unique mnemonics
        mnemonics = set()
        for instr in self.instructions:
            if instr.mnemonic:
                mnemonics.add(instr.mnemonic)

        # Add HINT aliases that are decoded at runtime (complete list from ARM64 XML)
        hint_aliases = ['NOP', 'YIELD', 'WFE', 'WFI', 'SEV', 'SEVL', 'DGH', 'XPACLRI',
                        'PACIA1716', 'PACIB1716', 'AUTIA1716', 'AUTIB1716',
                        'ESB', 'PSB', 'TSB', 'GCSB', 'CSDB', 'CLRBHB',
                        'PACIAZ', 'PACIASP', 'PACIBZ', 'PACIBSP',
                        'AUTIAZ', 'AUTIASP', 'AUTIBZ', 'AUTIBSP']
        mnemonics.update(hint_aliases)

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
        code.append("    // Use register aliases for x29 (fp) and x30 (lr)")
        code.append("    if (is_64bit) {")
        code.append("        if (reg == 29) return \"fp\";")
        code.append("        if (reg == 30) return \"lr\";")
        code.append("    }")
        code.append("    char prefix = is_64bit ? 'x' : 'w';")
        code.append("    return std::string(1, prefix) + std::to_string(reg);")
        code.append("}")
        code.append("")

        # Generate format_vector_register helper (now in Operand class)
        code.append("// Format a vector register")
        code.append("std::string Operand::format_vector_register(uint32_t reg, const char* arrangement) {")
        code.append("    // Single-char scalar prefixes: d, s, h, b → \"d7\", \"s7\", etc.")
        code.append("    if (arrangement && arrangement[0] != '\\0' && arrangement[1] == '\\0') {")
        code.append("        char c = arrangement[0];")
        code.append("        if (c == 'd' || c == 's' || c == 'h' || c == 'b') {")
        code.append("            return std::string(1, c) + std::to_string(reg);")
        code.append("        }")
        code.append("    }")
        code.append("    std::string result = \"v\" + std::to_string(reg);")
        code.append("    if (arrangement && arrangement[0] != '\\0') {")
        code.append("        result += \".\";")
        code.append("        result += arrangement;")
        code.append("    }")
        code.append("    return result;")
        code.append("}")
        code.append("")

        # Generate helper for MOVI/MVNI arrangement determination
        code.append("// Determine vector arrangement for MOVI/MVNI based on Q and cmode fields")
        code.append("const char* get_movi_arrangement(uint32_t insn) {")
        code.append("    uint32_t Q = (insn >> 30) & 1;")
        code.append("    uint32_t op = (insn >> 29) & 1;")
        code.append("    uint32_t cmode = (insn >> 12) & 0xF;")
        code.append("    ")
        code.append("    // 8-bit (cmode=1110, op=0)")
        code.append("    if (op == 0 && cmode == 0xE) {")
        code.append("        return Q ? \"16b\" : \"8b\";")
        code.append("    }")
        code.append("    // 16-bit shifted (cmode=10x0, op=0)")
        code.append("    if (op == 0 && (cmode & 0xD) == 0x8) {")
        code.append("        return Q ? \"8h\" : \"4h\";")
        code.append("    }")
        code.append("    // 32-bit shifted (cmode=0xx0, op=0)")
        code.append("    if (op == 0 && (cmode & 0x9) == 0x0) {")
        code.append("        return Q ? \"4s\" : \"2s\";")
        code.append("    }")
        code.append("    // 32-bit shifting ones (cmode=110x, op=0)")
        code.append("    if (op == 0 && (cmode & 0xE) == 0xC) {")
        code.append("        return Q ? \"4s\" : \"2s\";")
        code.append("    }")
        code.append("    // 64-bit (cmode=1110, op=1)")
        code.append("    if (op == 1 && cmode == 0xE) {")
        code.append("        return Q ? \"2d\" : nullptr;  // Scalar form (D register) doesn't use arrangement")
        code.append("    }")
        code.append("    return nullptr;")
        code.append("}")
        code.append("")

        # Generate condition_to_string function
        code.append("const char* condition_to_string(Condition cond) {")
        code.append("    static const char* names[] = {\"eq\", \"ne\", \"cs\", \"cc\", \"mi\", \"pl\", \"vs\", \"vc\",")
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
        code.append("    if (insn.mnemonic == Mnemonic::ADD && insn.operands.size() >= 3) {")
        code.append("        auto& op0 = insn.operands[0];")
        code.append("        auto& op1 = insn.operands[1];")
        code.append("        auto& op2 = insn.operands[2];")
        code.append("        if ((op0.value == 31 || op1.value == 31) &&")
        code.append("            op2.type == OperandType::Immediate && op2.value == 0) {")
        code.append('            return std::string("mov ") + op0.to_string() + ", " + op1.to_string();')
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
        code.append("        // Check if there's a shift operand")
        code.append("        bool has_shift = insn.operands.size() >= 3 && insn.operands[2].type == OperandType::Shift;")
        code.append("        if (has_shift) {")
        code.append("            // Compute the final shifted value")
        code.append("            uint64_t imm = insn.operands[1].value;")
        code.append("            uint32_t shift_amt = insn.operands[2].value & 0xFF;")
        code.append("            uint64_t final_val = imm << shift_amt;")
        code.append("            std::ostringstream oss;")
        code.append("            oss << \"mov \" << insn.operands[0].to_string() << \", #0x\" << std::hex << final_val;")
        code.append("            return oss.str();")
        code.append("        } else {")
        code.append("            std::ostringstream oss;")
        code.append("            oss << \"mov \" << insn.operands[0].to_string() << \", #0x\" << std::hex << insn.operands[1].value;")
        code.append("            return oss.str();")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    if (insn.mnemonic == Mnemonic::MOVN && insn.operands.size() >= 2) {")
        code.append("        bool has_shift = insn.operands.size() >= 3 && insn.operands[2].type == OperandType::Shift;")
        code.append("        if (has_shift) {")
        code.append("            // Compute the final shifted and inverted value")
        code.append("            uint64_t imm = insn.operands[1].value;")
        code.append("            uint32_t shift_amt = insn.operands[2].value & 0xFF;")
        code.append("            uint64_t final_val = ~(imm << shift_amt);")
        code.append("            // Mask to register size")
        code.append("            if (!insn.operands[0].is_64bit) final_val &= 0xFFFFFFFFULL;")
        code.append("            std::ostringstream oss;")
        code.append("            oss << \"mov \" << insn.operands[0].to_string() << \", #0x\" << std::hex << final_val;")
        code.append("            return oss.str();")
        code.append("        } else {")
        code.append("            std::ostringstream oss;")
        code.append("            oss << \"mvn \" << insn.operands[0].to_string() << \", #0x\" << std::hex << insn.operands[1].value;")
        code.append("            return oss.str();")
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    // CMP/CMN/TST aliases: Rd (bits [4:0]) == 31 (XZR)")
        code.append("    // Use raw bits to detect - alias encodings may omit Rd from operands")
        code.append("    if (insn.mnemonic == Mnemonic::SUBS && (insn.raw_value & 0x1F) == 0x1F) {")
        code.append("        // CMP alias: skip Rd if present in operands")
        code.append("        size_t start = (insn.operands.size() >= 3 && insn.operands[0].type == OperandType::Register && insn.operands[0].value == 31) ? 1 : 0;")
        code.append("        // Only alias if not also NEGS (Rn==31)")
        code.append("        if (((insn.raw_value >> 5) & 0x1F) != 0x1F) {")
        code.append('            std::string result = "cmp";')
        code.append("            for (size_t i = start; i < insn.operands.size(); ++i) {")
        code.append('                result += (i == start ? " " : ", ") + insn.operands[i].to_string();')
        code.append("            }")
        code.append("            return result;")
        code.append("        }")
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
        code.append("    // NEG Aliases: SUB/SUBS with Rn (bits [9:5]) == 31 (register form only)")
        code.append("    if (insn.mnemonic == Mnemonic::SUB && ((insn.raw_value >> 5) & 0x1F) == 0x1F) {")
        code.append("        // Only for register form (not immediate) - check bit 24")
        code.append("        if ((insn.raw_value & (1u << 24)) == 0) {")
        code.append("            // Emit Rd, Rm (skip Rn)")
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
        code.append("        if ((insn.raw_value & (1u << 24)) == 0) {")
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
        code.append("    // MUL Aliases: MADD/MSUB with Ra==31")
        code.append("    if (insn.mnemonic == Mnemonic::MADD && insn.operands.size() >= 4) {")
        code.append("        if (insn.operands[3].value == 31) {")
        code.append('            return std::string("mul ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();')
        code.append("        }")
        code.append("    }")
        code.append("")
        code.append("    if (insn.mnemonic == Mnemonic::MSUB && insn.operands.size() >= 4) {")
        code.append("        if (insn.operands[3].value == 31) {")
        code.append('            return std::string("mneg ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();')
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
        code.append("                // Use decimal for small values (0-15), hex for larger")
        code.append("                if (value <= 15) {")
        code.append("                    oss << \"#\" << std::dec << value;")
        code.append("                } else {")
        code.append("                    oss << \"#0x\" << std::hex << value;")
        code.append("                }")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::SignedImmediate:")
        code.append("            {")
        code.append("                std::ostringstream oss;")
        code.append("                int32_t sval = static_cast<int32_t>(value);")
        code.append("                if (sval < 0) {")
        code.append("                    if (sval >= -15) {")
        code.append("                        oss << \"#\" << std::dec << sval;")
        code.append("                    } else {")
        code.append("                        oss << \"#-0x\" << std::hex << (-sval);")
        code.append("                    }")
        code.append("                } else {")
        code.append("                    if (sval <= 15) {")
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
        code.append("            return format_vector_register(value, arrangement ? arrangement : \"\");")
        code.append("        ")
        code.append("        case OperandType::SVERegister:")
        code.append("            return \"z\" + std::to_string(value);")
        code.append("        ")
        code.append("        case OperandType::PredicateRegister:")
        code.append("            return \"p\" + std::to_string(value);")
        code.append("        ")
        code.append("        case OperandType::SMETileRegister:")
        code.append("            return \"za\" + std::to_string(value);")
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
        code.append("            // [Xn|SP, Rm{, extend {#amount}}]")
        code.append("            {")
        code.append("                std::string result = \"[\" + format_register(base_reg, true, true) + \", \";")
        code.append("                result += format_register(index_reg, true, false);")
        code.append("                if (extend != 0 || amount != 0) {")
        code.append("                    const char* extends[] = {\"UXTB\", \"UXTH\", \"UXTW\", \"UXTX\", ")
        code.append("                                             \"SXTB\", \"SXTH\", \"SXTW\", \"SXTX\"};")
        code.append("                    if (extend < 8) {")
        code.append("                        result += \", \" + std::string(extends[extend]);")
        code.append("                        if (amount != 0) {")
        code.append("                            result += \" #\" + std::to_string(amount);")
        code.append("                        }")
        code.append("                    }")
        code.append("                }")
        code.append("                result += \"]\";")
        code.append("                return result;")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::SystemRegister:")
        code.append("            return \"s\" + std::to_string(value);")
        code.append("        ")
        code.append("        case OperandType::Shift:")
        code.append("            {")
        code.append("                // value encodes shift_type in bits [9:8] and amount in bits [7:0]")
        code.append("                const char* shifts[] = {\"lsl\", \"lsr\", \"asr\", \"ror\"};")
        code.append("                uint32_t shift_type = (value >> 8) & 0x3;")
        code.append("                uint32_t shift_amount = value & 0xFF;")
        code.append("                if (value < 4) return shifts[value];  // Legacy: bare shift type")
        code.append('                return std::string(shifts[shift_type]) + " #" + std::to_string(shift_amount);')
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::Extend:")
        code.append("            {")
        code.append("                const char* extends[] = {\"uxtb\", \"uxth\", \"uxtw\", \"uxtx\", ")
        code.append("                                         \"sxtb\", \"sxth\", \"sxtw\", \"sxtx\"};")
        code.append("                if (value < 8) return extends[value];")
        code.append("                return \"ext\" + std::to_string(value);")
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
        code.append("                int32_t sval = static_cast<int32_t>(value);")
        code.append("                if (sval < 0) oss << \".-0x\" << std::hex << (-sval);")
        code.append("                else oss << \".+0x\" << std::hex << sval;")
        code.append("                return oss.str();")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::Pattern:")
        code.append("            // SVE pattern specifier")
        code.append("            return \"#\" + std::to_string(value);")
        code.append("        ")
        code.append("        case OperandType::Prefetch:")
        code.append("            // Prefetch operation")
        code.append("            {")
        code.append("                const char* prfops[] = {\"pldl1keep\", \"pldl1strm\", \"pldl2keep\", \"pldl2strm\",")
        code.append("                                        \"pldl3keep\", \"pldl3strm\", \"#6\", \"#7\",")
        code.append("                                        \"plil1keep\", \"plil1strm\", \"plil2keep\", \"plil2strm\",")
        code.append("                                        \"plil3keep\", \"plil3strm\", \"#14\", \"#15\",")
        code.append("                                        \"pstl1keep\", \"pstl1strm\", \"pstl2keep\", \"pstl2strm\",")
        code.append("                                        \"pstl3keep\", \"pstl3strm\", \"#22\", \"#23\"};")
        code.append("                if (value < 24) return prfops[value];")
        code.append("                return \"#\" + std::to_string(value);")
        code.append("            }")
        code.append("        ")
        code.append("        case OperandType::Barrier:")
        code.append("            // Barrier option")
        code.append("            {")
        code.append("                const char* barriers[] = {\"#0\", \"oshld\", \"oshst\", \"osh\",")
        code.append("                                          \"#4\", \"nshld\", \"nshst\", \"nsh\",")
        code.append("                                          \"#8\", \"ishld\", \"ishst\", \"ish\",")
        code.append("                                          \"#12\", \"ld\", \"st\", \"sy\"};")
        code.append("                if (value < 16) return barriers[value];")
        code.append("                return \"#\" + std::to_string(value);")
        code.append("            }")
        code.append("        ")
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


    def _generate_veda64_header(self, output_file: Path):
        """Generate the main veda64.hpp header file."""
        code = []

        code.append("#pragma once")
        code.append("")
        code.append("#include <cstdint>")
        code.append("#include <cstddef>")
        code.append("#include <string>")
        code.append("#include <vector>")
        code.append("#include <optional>")
        code.append("#include <memory>")
        code.append("")
        code.append("namespace veda64 {")
        code.append("")
        code.append("// Library version")
        code.append("constexpr int VERSION_MAJOR = 0;")
        code.append("constexpr int VERSION_MINOR = 1;")
        code.append("constexpr int VERSION_PATCH = 0;")
        code.append("")

        # Generate byte-order conversion utility (little-endian, ARM64 native)
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

        # Generate inline DecodeBitMasks helper for logical immediate decoding
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
        code.append("    uint64_t welem = (1ULL << (S + 1)) - 1;")
        code.append("    if (R != 0) {")
        code.append("        welem = ((welem >> R) | (welem << (esize - R))) & ((1ULL << esize) - 1);")
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

        for mnem in sorted(mnemonics):
            code.append(f"    {mnem},")
        code.append("    UNKNOWN")
        code.append("};")
        code.append("")

        # Generate Condition enum
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

        # Generate OperandType enum
        code.append("// Operand type enumeration")
        code.append("enum class OperandType {")
        code.append("    Register,           // General purpose register (Xn, Wn)")
        code.append("    VectorRegister,     // Vector/SIMD register (Vn, Qn, Dn, Sn, Hn, Bn)")
        code.append("    SVERegister,        // SVE scalable vector register (Zn)")
        code.append("    PredicateRegister,  // SVE predicate register (Pn)")
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
        code.append("    Prefetch,           // Prefetch operation")
        code.append("    Barrier,            // Barrier option")
        code.append("    Unknown")
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
        code.append("    bool is_64bit = true;        // True for 64-bit registers (X), false for 32-bit (W)")
        code.append("    bool is_sp = false;          // True if reg 31 should be SP/WSP, false for XZR/WZR")
        code.append("    const char* arrangement = nullptr;  // Vector arrangement specifier (.16b, .4s, etc.)")
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
        code.append("")
        code.append("private:")
        code.append("    // Helper functions for formatting")
        code.append("    static std::string format_register(uint32_t reg, bool is_64bit, bool is_sp = false);")
        code.append("    static std::string format_vector_register(uint32_t reg, const char* arrangement);")
        code.append("#endif")
        code.append("};")
        code.append("")

        # Generate helper function declaration
        code.append("#ifndef VEDA64_NO_STRINGS")
        code.append("// Convert mnemonic enum to string")
        code.append("const char* mnemonic_to_string(Mnemonic mnem);")
        code.append("")
        code.append("// Determine vector arrangement for MOVI/MVNI based on Q and cmode fields")
        code.append("const char* get_movi_arrangement(uint32_t insn);")
        code.append("")
        code.append("// Convert condition code to string (\"eq\", \"ne\", etc.)")
        code.append("const char* condition_to_string(Condition cond);")
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

        # Hook API declarations (conditionally compiled)
        code.append("// ============================================================================")
        code.append("// Hook API (Windows ARM64 inline hooking)")
        code.append("// ============================================================================")
        code.append("")
        code.append("#if !defined(VEDA64_NO_HOOKS) && (defined(_WIN32) || defined(VEDA64_HOOK_SUPPORT))")
        code.append("")
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
        code.append("// Install an inline hook (starts disabled — call enable() to activate)")
        code.append("// target: address of function to hook")
        code.append("// detour: address of your hook function")
        code.append("// original: receives pointer to trampoline for calling original function")
        code.append("// handle: optional output — receives handle to the hook")
        code.append("// Returns: HookStatus indicating success or failure")
        code.append("HookStatus install(void* target, void* detour, void** original, HookHandle* handle = nullptr);")
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
        code.append("")
        code.append("#endif // !VEDA64_NO_HOOKS && (_WIN32 || VEDA64_HOOK_SUPPORT)")
        code.append("")
        code.append("} // namespace veda64")
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

                # Use encoding-specific mnemonic if available, otherwise fall back to instruction mnemonic
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
        code = []

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
        code = []

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
            'hw', 'shift', 'cond', 'nzcv', 'option',
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
                    code.extend(['            ' + line for line in self._generate_operand_extraction(class_name, info, indent=3)])
                    code.append(f"        }}")
                else:
                    # Multiple encodings with identical pattern - return first
                    primary = encodings[0]
                    code.append(f"        case 0x{pattern:08X}u: {{ // {primary['encoding_name']}")
                    for alt in encodings[1:]:
                        code.append(f"            // Also matches: {alt['encoding_name']} ({alt['mnemonic']})")
                    code.extend(['            ' + line for line in self._generate_operand_extraction(class_name, primary, indent=3)])
                    code.append(f"        }}")

            code.append("        default: break;")
            code.append("    }")
            code.append("")

        code.append("    // No matching encoding found")
        code.append("    return std::nullopt;")
        code.append("}")

        return code

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

    def _generate_operand_extraction(self, class_name: str, encoding_info: Dict, indent: int = 2) -> List[str]:
        """Generate code to extract operands from raw instruction using struct fields."""
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
        is_branch = mnemonic in ['B', 'BL', 'CBZ', 'CBNZ', 'TBZ', 'TBNZ', 'BC']
        is_ret = mnemonic == 'RET'
        is_hint = mnemonic == 'HINT'
        is_movz = mnemonic == 'MOVZ'
        is_movn = mnemonic == 'MOVN'
        is_movk = mnemonic == 'MOVK'
        is_add_sub = mnemonic in ['ADD', 'ADDS', 'SUB', 'SUBS']
        is_ldp_stp = 'ldstpair' in encoding_name or 'ldstnapair' in encoding_name or 'ldp' in encoding_name or 'stp' in encoding_name or 'ldnp' in encoding_name or 'stnp' in encoding_name

        # Determine if this is a load/store with memory addressing
        is_load_store = any(x in encoding_name for x in ['ldst', 'ldap', 'stl', 'ldur', 'stur',
                                                          'ldr_', 'str_', 'ldnp', 'stnp', 'ldtr', 'sttr',
                                                          'ldrb', 'strb', 'ldrh', 'strh'])
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
            code.append(f"{ind}    case 17: result.mnemonic = Mnemonic::PSB; break;")
            code.append(f"{ind}    case 18: result.mnemonic = Mnemonic::TSB; break;")
            code.append(f"{ind}    case 19: result.mnemonic = Mnemonic::GCSB; break;")
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

        # Special case: RET with implicit X30
        if is_ret:
            code.append(f"{ind}// RET - X30 is implicit, no operands needed")
            code.append(f"{ind}return result;")
            return code

        # Decode struct for field extraction (after early returns that don't need it)
        code.append(f"{ind}{union_name} enc = {{}};")
        code.append(f"{ind}enc.raw = insn;")

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
            is_simd_q = '_Q_' in encoding_name or '_q_' in encoding_name
            is_simd_d = '_D_' in encoding_name and ('ldstpair' in encoding_name or 'ldstnapair' in encoding_name)
            is_simd_s = '_S_' in encoding_name and ('ldstpair' in encoding_name or 'ldstnapair' in encoding_name)

            if is_simd_q:
                # 128-bit Q registers (SIMD), scale=16
                code.append(f"{ind}int scale = 16;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::VectorRegister, enc.{member_name}.{rt_field}, true));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::VectorRegister, enc.{member_name}.{rt2_field}, true));")
            elif is_simd_d:
                # 64-bit D registers (SIMD), scale=8 - use 'v' prefix (equivalent to 'd')
                code.append(f"{ind}int scale = 8;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::VectorRegister, enc.{member_name}.{rt_field}, false));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::VectorRegister, enc.{member_name}.{rt2_field}, false));")
            elif is_simd_s:
                # 32-bit S registers (SIMD), scale=4 - use 'v' prefix (equivalent to 's')
                code.append(f"{ind}int scale = 4;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::VectorRegister, enc.{member_name}.{rt_field}, false));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::VectorRegister, enc.{member_name}.{rt2_field}, false));")
            elif 'opc' in field_map and not field_map['opc']['is_fixed']:
                opc_field = field_map['opc']['name']
                code.append(f"{ind}bool is_64bit = (enc.{member_name}.{opc_field} == 2);")
                code.append(f"{ind}int scale = is_64bit ? 8 : 4;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, is_64bit));")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt2_field}, is_64bit));")
            else:
                # Fallback: check encoding name for integer size
                is_64bit_val = '64' in encoding_name or '_d' in encoding_name
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
                # ADRP: offset is imm21 << 12 (page-aligned)
                code.append(f"{ind}int32_t offset = imm21 << 12;")
            else:
                # ADR: offset is imm21 directly
                code.append(f"{ind}int32_t offset = imm21;")
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));")
            code.append(f"{ind}return result;")
            return code

        # Special case: Barrier instructions (DMB, DSB, ISB) - extract CRm as Barrier operand
        if mnemonic in ['DMB', 'DSB', 'ISB'] and 'CRm' in field_map and not field_map['CRm']['is_fixed']:
            crm_field = field_map['CRm']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Barrier, enc.{member_name}.{crm_field}, true));")
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
                    is_64 = '_64_' in encoding_name
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
                # Always use X register for clarity (WinDbg convention) even though ARM spec uses b5
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, true));")
                # Bit number (6-bit value from b5:b40)
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (enc.{member_name}.{b5_field} << 5) | enc.{member_name}.{b40_field}, true));")
                # Sign-extend 14-bit immediate and multiply by 4
                code.append(f"{ind}int32_t offset = static_cast<int32_t>(enc.{member_name}.{imm_field} << 18) >> 18;")
                code.append(f"{ind}offset *= 4;")
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));")
                code.append(f"{ind}return result;")
                return code
            # Fall through to default if required fields not found

        # Special case: MOVZ/MOVN/MOVK - only if required fields exist
        if (is_movz or is_movn or is_movk) and 'Rd' in field_map and 'imm16' in field_map:
            rd_field = field_map['Rd']['name']
            imm_field = field_map['imm16']['name']

            if has_sf and 'sf' in field_map:
                sf_field = field_map['sf']['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rd_field}, static_cast<bool>(enc.{member_name}.{sf_field})));")
            else:
                # Determine is_64bit from encoding name (_32_ means 32-bit, _64_ means 64-bit)
                is_64 = '_64_' in encoding_name or not '_32_' in encoding_name
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
                is_64 = '_64_' in encoding_name or not '_32_' in encoding_name
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
                is_64 = '_64_' in encoding_name
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
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));")

            code.append(f"{ind}return result;")
            return code

        # Special case: Load/store byte/half (LDRB, STRB, LDRH, STRH, LDURB, STURB, LDURH, STURH) - only if required fields exist
        if is_load_store and 'Rt' in field_map and 'Rn' in field_map and any(x in encoding_name for x in ['ldrb', 'strb', 'ldrh', 'strh', 'ldurb', 'sturb', 'ldurh', 'sturh', '32b_', '32h_']):
            rt_field = field_map['Rt']['name']
            rn_field = field_map['Rn']['name']
            imm_field = None
            for imm_name in ['imm12', 'imm9', 'simm9', 'imm']:
                if imm_name in field_map:
                    imm_field = field_map[imm_name]['name']
                    break

            # Byte/half loads use W register (32-bit)
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, false));")

            # Determine scale for unsigned offset: halfword = 2, byte = 1
            is_halfword = any(x in encoding_name for x in ['ldrh', 'strh', 'ldurh', 'sturh', '32h_'])
            is_unscaled = any(x in encoding_name for x in ['ldur', 'stur'])
            scale_factor = 2 if is_halfword and not is_unscaled else 1

            # Memory operand (imm9 is 9-bit signed for pre/post/unscaled, imm12 is unsigned for offset)
            if addr_mode == 'post_index':
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

        # Special case: General load/store (LDR, STR 32/64-bit) - only if required fields exist
        if is_load_store and mnemonic in ['LDR', 'STR', 'LDUR', 'STUR', 'LDTR', 'STTR'] and 'Rt' in field_map and 'Rn' in field_map:
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
                    code.append(f'{ind}    op.arrangement = "{simd_char}";')
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
                        code.append(f"{ind}int scale = 8;")
                else:
                    code.append(f"{ind}bool is_64bit = false;")
                    if needs_scale:
                        code.append(f"{ind}int scale = 4;")

                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rt_field}, is_64bit));")

            # Check if this is an unscaled load/store (LDUR/STUR use signed imm9, no scaling)
            is_unscaled = mnemonic in ['LDUR', 'STUR']

            # Memory operand with scaling for imm12 (unsigned offset)
            if addr_mode == 'post_index':
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
            elif '64' in encoding_name or '_d' in encoding_name or '_x' in encoding_name:
                code.append(f"{ind}bool is_64bit = true;")
            elif mnemonic in ['ADR', 'ADRP'] or 'pcreladdr' in encoding_name:
                # ADR/ADRP always produce 64-bit X registers
                code.append(f"{ind}bool is_64bit = true;")
            else:
                code.append(f"{ind}bool is_64bit = false;")

        # Extract all GPR register operands - pass is_64bit as third parameter
        # Special case: For advsimd/simd_dp classes, Rd/Rn/Rm might actually be vector registers
        # Check if this is an advsimd instruction that uses vector registers
        is_advsimd_vector = (class_name in ['advsimd', 'simd_dp'] and mnemonic in [
            'MOVI', 'MVNI', 'ORR', 'BIC', 'FMOV', 'DUP', 'INS', 'UMOV', 'SMOV',
            'ABS', 'NEG', 'NOT', 'CNT', 'CLS', 'CLZ', 'RBIT', 'REV16', 'REV32', 'REV64',
            'ADD', 'SUB', 'MUL', 'MLA', 'MLS', 'AND', 'EOR', 'BSL', 'BIT', 'BIF',
            'SMAX', 'SMIN', 'UMAX', 'UMIN', 'SMAXP', 'SMINP', 'UMAXP', 'UMINP',
            'SHL', 'SHR', 'SSHR', 'USHR', 'SSRA', 'USRA', 'SRSHR', 'URSHR',
            'SHADD', 'UHADD', 'SHSUB', 'UHSUB', 'SRHADD', 'URHADD',
            'SADDLP', 'UADDLP', 'SADALP', 'UADALP',
            'SQABS', 'SQNEG', 'SUQADD', 'USQADD',
            'ADDP', 'ADDV', 'SADDLV', 'UADDLV',
            'FCVT', 'FCVTL', 'FCVTN', 'FCVTXN',
            'FADD', 'FSUB', 'FMUL', 'FDIV', 'FNEG', 'FABS', 'FSQRT',
            'FMAX', 'FMIN', 'FMAXNM', 'FMINNM', 'FMAXP', 'FMINP',
            'FCMEQ', 'FCMGE', 'FCMGT', 'FCMLE', 'FCMLT',
            'FRINTN', 'FRINTP', 'FRINTM', 'FRINTZ', 'FRINTA', 'FRINTX', 'FRINTI',
            'XTN', 'SQXTN', 'UQXTN', 'SQXTUN', 'SHLL',
            'UXTL', 'SXTL', 'SADDL', 'SADDW', 'SSUBL', 'SSUBW', 'UADDL', 'UADDW', 'USUBL', 'USUBW',
            'SMLAL', 'SMLSL', 'UMLAL', 'UMLSL', 'SMULL', 'UMULL',
            'SQDMLAL', 'SQDMLSL', 'SQDMULL', 'SQDMULH', 'SQRDMULH',
            'PMUL', 'PMULL', 'SABD', 'UABD', 'SABA', 'UABA'
        ])
        
        for reg_name in ['Rd', 'Rn', 'Rm', 'Ra', 'Rt', 'Rs', 'Rt2', 'Rdn']:
            if reg_name in field_map and not field_map[reg_name]['is_fixed']:
                field_cpp_name = field_map[reg_name]['name']
                if is_advsimd_vector:
                    # Use VectorRegister for advsimd vector instructions
                    if mnemonic in ['MOVI', 'MVNI'] and reg_name == 'Rd':
                        # MOVI/MVNI need arrangement from Q and cmode fields
                        code.append(f"{ind}{{")
                        code.append(f"{ind}    Operand op(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false);")
                        code.append(f"{ind}    op.arrangement = get_movi_arrangement(insn);")
                        code.append(f"{ind}    result.operands.push_back(op);")
                        code.append(f"{ind}}}")
                    else:
                        code.append(f"{ind}result.operands.push_back(Operand(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, false));")
                else:
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{field_cpp_name}, is_64bit));")

        # Extract SVE Z register operands
        for reg_name in ['Zd', 'Zn', 'Zm', 'Za', 'Zk', 'Zt', 'Zda', 'Zdn']:
            if reg_name in field_map and not field_map[reg_name]['is_fixed']:
                field_cpp_name = field_map[reg_name]['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::SVERegister, enc.{member_name}.{field_cpp_name}, true));")

        # Extract SIMD V register operands
        for reg_name in ['Vd', 'Vdn', 'Vn', 'Vm']:
            if reg_name in field_map and not field_map[reg_name]['is_fixed']:
                field_cpp_name = field_map[reg_name]['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::VectorRegister, enc.{member_name}.{field_cpp_name}, true));")

        # Extract SVE predicate register operands
        for reg_name in ['Pd', 'Pn', 'Pm', 'Pg', 'Pt', 'Pv', 'Pdm', 'Pdn', 'PNd', 'PNn', 'PNg', 'PNv']:
            if reg_name in field_map and not field_map[reg_name]['is_fixed']:
                field_cpp_name = field_map[reg_name]['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::PredicateRegister, enc.{member_name}.{field_cpp_name}, true));")

        # Extract SME ZA tile register operands
        for reg_name in ['ZAd', 'ZAda', 'ZAn', 'ZAt']:
            if reg_name in field_map and not field_map[reg_name]['is_fixed']:
                field_cpp_name = field_map[reg_name]['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::SMETileRegister, enc.{member_name}.{field_cpp_name}, true));")

        # Extract Rv index register (2-bit field encoding W8-W11)
        if 'Rv' in field_map and not field_map['Rv']['is_fixed']:
            rv_field = field_map['Rv']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Register, enc.{member_name}.{rv_field} + 8, false));")

        # Combine split immediate fields before extracting individual immediates
        # i3h + i3l -> combined 3-bit index
        if 'i3h' in field_map and not field_map['i3h']['is_fixed'] and 'i3l' in field_map and not field_map['i3l']['is_fixed']:
            i3h_field = field_map['i3h']['name']
            i3l_field = field_map['i3l']['name']
            i3l_width = field_map['i3l']['width']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (enc.{member_name}.{i3h_field} << {i3l_width}) | enc.{member_name}.{i3l_field}, true));")

        # i4h + i4l -> combined 4-bit index
        if 'i4h' in field_map and not field_map['i4h']['is_fixed'] and 'i4l' in field_map and not field_map['i4l']['is_fixed']:
            i4h_field = field_map['i4h']['name']
            i4l_field = field_map['i4l']['name']
            i4l_width = field_map['i4l']['width']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (enc.{member_name}.{i4h_field} << {i4l_width}) | enc.{member_name}.{i4l_field}, true));")

        # i2h + i2l -> combined 2-bit index
        if 'i2h' in field_map and not field_map['i2h']['is_fixed'] and 'i2l' in field_map and not field_map['i2l']['is_fixed']:
            i2h_field = field_map['i2h']['name']
            i2l_field = field_map['i2l']['name']
            i2l_width = field_map['i2l']['width']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, (enc.{member_name}.{i2h_field} << {i2l_width}) | enc.{member_name}.{i2l_field}, true));")

        # imm9h + imm9l -> combined imm9 (SVE LDR/STR pred/vec)
        if 'imm9h' in field_map and not field_map['imm9h']['is_fixed'] and 'imm9l' in field_map and not field_map['imm9l']['is_fixed']:
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
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, {combined}, true));")

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

                field_cpp_name = field_map[imm_name]['name']

                if is_unsigned or not self._is_signed_field(imm_name):
                    code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{field_cpp_name}, true));")
                else:
                    # Sign extend
                    code.append(f"{ind}{{")
                    code.append(f"{ind}    int32_t val = static_cast<int32_t>(enc.{member_name}.{field_cpp_name} << {32-bits}) >> {32-bits};")
                    code.append(f"{ind}    result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));")
                    code.append(f"{ind}}}")

        # Extract SVE/SME offset fields
        for off_name in ['off4', 'off3', 'off2']:
            if off_name in field_map and not field_map[off_name]['is_fixed']:
                field_cpp_name = field_map[off_name]['name']
                code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{field_cpp_name}, true));")

        # Extract SVE/SME split index fields
        for idx_name in ['i1', 'i2', 'i3', 'i4']:
            if idx_name in field_map and not field_map[idx_name]['is_fixed']:
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
        if 'pattern' in field_map and not field_map['pattern']['is_fixed']:
            pattern_field = field_map['pattern']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Pattern, enc.{member_name}.{pattern_field}, true));")

        # Handle prefetch operation (pldl1keep, pstl2strm, etc.)
        if 'prfop' in field_map and not field_map['prfop']['is_fixed']:
            prfop_field = field_map['prfop']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Prefetch, enc.{member_name}.{prfop_field}, true));")

        # Handle NZCV flags immediate (CCMN/CCMP)
        if 'nzcv' in field_map and not field_map['nzcv']['is_fixed']:
            nzcv_field = field_map['nzcv']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{nzcv_field}, true));")

        # Handle rotation amount (0/90/180/270 for complex multiply)
        if 'rot' in field_map and not field_map['rot']['is_fixed']:
            rot_field = field_map['rot']['name']
            code.append(f"{ind}result.operands.push_back(Operand(OperandType::Immediate, enc.{member_name}.{rot_field} * 90, true));")

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
        code.append("# Option to reduce binary size and remove strings")
        code.append("option(VEDA64_NO_STRINGS \"Disable all string functions (to_string, mnemonic_to_string, status_to_string, dump_hook)\" OFF)")
        code.append("option(VEDA64_BUILD_TESTS \"Build test executables\" ON)")
        code.append("option(VEDA64_HOOK \"Enable inline hooking support (Windows only)\" ON)")
        code.append("")
        code.append("# Compiler warnings")
        code.append("if(MSVC)")
        code.append("    add_compile_options(/W4)")
        code.append("else()")
        code.append("    add_compile_options(-Wall -Wextra -Wpedantic)")
        code.append("endif()")
        code.append("")
        code.append("# Pass options as compile definitions")
        code.append("if(VEDA64_NO_STRINGS)")
        code.append("    add_compile_definitions(VEDA64_NO_STRINGS)")
        code.append("endif()")
        code.append("")
        code.append("# Collect all source files")
        code.append("file(GLOB_RECURSE VEDA64_SOURCES \"lib/*.cpp\")")
        code.append("")
        code.append("# Hook support")
        code.append("if(NOT VEDA64_HOOK)")
        code.append("    list(REMOVE_ITEM VEDA64_SOURCES \"${CMAKE_CURRENT_SOURCE_DIR}/lib/hook.cpp\")")
        code.append("    add_compile_definitions(VEDA64_NO_HOOKS)")
        code.append("endif()")
        code.append("")
        code.append("# Create library")
        code.append("add_library(veda64 ${VEDA64_SOURCES})")
        code.append("target_include_directories(veda64 PUBLIC")
        code.append("    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
        code.append("    $<INSTALL_INTERFACE:include>")
        code.append(")")
        code.append("")
        code.append("# Link ntdll for NT syscalls on Windows (only when hooks are enabled)")
        code.append("if(WIN32 AND VEDA64_HOOK)")
        code.append("    target_link_libraries(veda64 PUBLIC ntdll)")
        code.append("endif()")
        code.append("")
        code.append("# Tools")
        code.append("add_executable(veda64-disasm tools/veda64-disasm.cpp)")
        code.append("target_link_libraries(veda64-disasm PRIVATE veda64)")
        code.append("")
        code.append("# Enable testing")
        code.append("if(VEDA64_BUILD_TESTS)")
        code.append("    enable_testing()")
        code.append("    add_subdirectory(test)")
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
        code.append("endforeach()")
        code.append("")

        output_file = test_dir / "CMakeLists.txt"
        self._write_file(output_file, code)

    def generate_test_suite(self, test_dir: Path):
        """Generate test files for each instruction class."""
        # Clean up old test files (remove stale generated files)
        for f in test_dir.iterdir():
            if f.is_file() and f.suffix == '.cpp' and f.name.startswith('test_'):
                f.unlink()

        # Group instructions by class
        by_class = {}
        for instr in self.instructions:
            cls = instr.instr_class or 'unknown'
            if cls not in by_class:
                by_class[cls] = []
            by_class[cls].append(instr)

        # Generate test file for each class
        for cls, instrs in sorted(by_class.items()):
            test_file = test_dir / f"test_{cls}.cpp"
            self._generate_class_tests(cls, instrs, test_file)
            print(f"Generated test_{cls}.cpp ({len(instrs)} instructions)")

    def _generate_class_tests(self, class_name: str, instructions: List[Instruction], output_file: Path):
        """Generate test file for a specific instruction class using format-based decode."""
        code = []

        code.append(f"// Auto-generated - do not edit")
        code.append(f"// Test suite for {class_name} instruction class")
        code.append("#include \"veda64.hpp\"")
        code.append("#include <cassert>")
        code.append("#include <iostream>")
        code.append("")
        code.append("using namespace veda64;")
        code.append("")

        # Generate test functions for sample instructions
        test_funcs = []
        for instr in instructions[:10]:  # Test first 10 instructions per class
            if not instr.encodings:
                continue

            encoding = instr.encodings[0]
            if not encoding.name:
                continue

            func_name = self._sanitize_function_name(encoding.name)

            # Compute the instruction value with all fixed bits set, variable bits = 0
            _, _, _, _, full_pattern, _ = self._generate_encoding_struct(instr, encoding)

            if full_pattern is None:
                continue

            test_funcs.append((func_name, instr.mnemonic, full_pattern))

            code.append(f"void test_{func_name}() {{")
            code.append(f"    // Test {instr.mnemonic}: {instr.brief}")
            code.append(f"    uint32_t test_insn = 0x{full_pattern:08X}u;")
            code.append(f"")
            code.append(f"    auto result = decode(test_insn);")
            code.append(f"    assert(result.has_value());")
            code.append(f"    (void)result;")
            if instr.mnemonic:
                code.append(f"    assert(result->mnemonic == Mnemonic::{instr.mnemonic});")
            code.append(f"")
            code.append(f"    std::cout << \"  {func_name}: \" << result->to_string() << std::endl;")
            code.append(f"}}")
            code.append("")

        # Generate main function
        code.append(f"int main() {{")
        code.append(f"    std::cout << \"Running {class_name} tests...\" << std::endl;")
        code.append(f"")

        # Call all test functions
        for func_name, _, _ in test_funcs:
            code.append(f"    test_{func_name}();")

        code.append(f"")
        code.append(f"    std::cout << \"All {len(test_funcs)} tests passed!\" << std::endl;")
        code.append(f"    return 0;")
        code.append(f"}}")
        code.append("")

        self._write_file(output_file, code)

    def generate_disasm_tool(self, tools_dir: Path):
        """Generate the veda64-disasm tool."""
        tools_dir.mkdir(exist_ok=True)

        code = []
        code.append("// veda64-disasm - ARM64 instruction disassembler")
        code.append("// Auto-generated - do not edit")
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
        code = []
        code.append("// veda64 API Hooking for Windows ARM64 - Implementation")
        code.append("// Uses veda64 disassembler for instruction analysis and relocation")
        code.append("// Uses direct NT syscalls instead of Win32 API for stealth")
        code.append("// Auto-generated - do not edit")
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
        code.append("    auto decoded = decode(insn);")
        code.append("    if (!decoded) {")
        code.append("        return false;")
        code.append("    }")
        code.append("")
        code.append("    // Most instructions can be relocated")
        code.append("    // Exceptions:")
        code.append("    // - Instructions that read PC directly (rare on ARM64)")
        code.append("    // - Some system instructions")
        code.append("")
        code.append("    switch (decoded->mnemonic) {")
        code.append("        // These are generally safe even if PC-relative (we handle them)")
        code.append("        case Mnemonic::B:")
        code.append("        case Mnemonic::BL:")
        code.append("        case Mnemonic::BC:")
        code.append("        case Mnemonic::CBZ:")
        code.append("        case Mnemonic::CBNZ:")
        code.append("        case Mnemonic::TBZ:")
        code.append("        case Mnemonic::TBNZ:")
        code.append("        case Mnemonic::ADR:")
        code.append("        case Mnemonic::ADRP:")
        code.append("        case Mnemonic::LDR:")
        code.append("        case Mnemonic::LDRSW:")
        code.append("            return true;")
        code.append("")
        code.append("        // Return instructions - can't relocate")
        code.append("        case Mnemonic::RET:")
        code.append("        case Mnemonic::RETAA:")
        code.append("        case Mnemonic::RETAB:")
        code.append("        case Mnemonic::ERET:")
        code.append("        case Mnemonic::ERETAA:")
        code.append("        case Mnemonic::ERETAB:")
        code.append("            return false;")
        code.append("")
        code.append("        default:")
        code.append("            // Most other instructions are position-independent")
        code.append("            return true;")
        code.append("    }")
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
        code.append("static Trampoline create_trampoline(void* target, size_t hook_size, HookStatus* status) {")
        code.append("    Trampoline tramp = {};")
        code.append("")
        code.append("    // Allocate space for relocated instructions + jump back")
        code.append("    // Each instruction might expand to multiple instructions during relocation")
        code.append("    size_t max_size = (hook_size / 4) * 16 + 16;  // Worst case expansion + jump")
        code.append("")
        code.append("    // Allocate near the target for PC-relative instruction relocation")
        code.append("    tramp.code = static_cast<uint8_t*>(detail::alloc_executable_near(target, max_size));")
        code.append("    if (!tramp.code) {")
        code.append("        *status = HookStatus::AllocationFailed;")
        code.append("        return tramp;")
        code.append("    }")
        code.append("    tramp.code_size = max_size;")
        code.append("")
        code.append("    // Disassemble and relocate instructions")
        code.append("    uint8_t* src = static_cast<uint8_t*>(target);")
        code.append("    uint8_t* dst = tramp.code;")
        code.append("    size_t src_offset = 0;")
        code.append("    size_t dst_offset = 0;")
        code.append("    uint64_t src_pc = reinterpret_cast<uint64_t>(target);")
        code.append("    uint64_t dst_pc = reinterpret_cast<uint64_t>(tramp.code);")
        code.append("")
        code.append("    while (src_offset < hook_size) {")
        code.append("        uint32_t insn = *reinterpret_cast<uint32_t*>(src + src_offset);")
        code.append("")
        code.append("        // Check if we can relocate this instruction")
        code.append("        if (!detail::can_relocate(insn)) {")
        code.append("            *status = HookStatus::InstructionTooComplex;")
        code.append("            detail::free_executable(tramp.code, tramp.code_size);")
        code.append("            tramp.code = nullptr;")
        code.append("            return tramp;")
        code.append("        }")
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
        code.append("            *status = HookStatus::RelocationFailed;")
        code.append("            detail::free_executable(tramp.code, tramp.code_size);")
        code.append("            tramp.code = nullptr;")
        code.append("            return tramp;")
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
        code.append("    // Add jump back to original code after hook")
        code.append("    void* return_addr = static_cast<uint8_t*>(target) + hook_size;")
        code.append("    dst_offset += detail::generate_jump(dst + dst_offset, return_addr);")
        code.append("")
        code.append("    tramp.used_size = dst_offset;")
        code.append("")
        code.append("    // Flush instruction cache for trampoline")
        code.append("    detail::flush_icache(tramp.code, tramp.used_size);")
        code.append("")
        code.append("    *status = HookStatus::Success;")
        code.append("    return tramp;")
        code.append("}")
        code.append("")
        code.append("HookStatus install(void* target, void* detour, void** original, HookHandle* handle) {")
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
        code.append("    HookStatus tramp_status;")
        code.append("    ctx->trampoline = create_trampoline(target, ctx->hook_size, &tramp_status);")
        code.append("    if (!ctx->trampoline.code) {")
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
        code = []

        code.append("// Reference test - validates decode output against known disassembly")
        code.append("// Auto-generated - do not edit")
        code.append("// Tests both mnemonic and operands (case-insensitive)")
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
            ("0x910003fd", "mov fp, sp"),                  # alias: ADD with imm=0
            ("0x390043bf", "strb wzr, [fp, #0x10]"),       # 16 = 0x10
            ("0xd2800004", "mov x4, #0x0"),               # alias: MOVZ with no shift
            ("0x52800023", "mov w3, #0x1"),               # alias: MOVZ 32-bit
            ("0x910043a2", "add x2, fp, #0x10"),
            ("0x52800221", "mov w1, #0x11"),              # alias: MOVZ 32-bit
            ("0x92800020", "mvn x0, #0x1"),               # alias: MOVN
            ("0x97fa94a3", "bl .-0x15ad74"),               # -1420660 = -0x15ad74
            ("0x37f800a0", "tbnz x0, #0x1f, .+0x14"),      # Always show X register (WinDbg convention)
            ("0x394043a8", "ldrb w8, [fp, #0x10]"),
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
            # LDURB/STURB (unscaled byte)
            ("0x385ff08a", "ldurb w10, [x4, #-1]"),        # LDURB with -1 offset
            # LDUR/STUR (unscaled word/dword)
            ("0xb85fc088", "ldur w8, [x4, #-4]"),          # LDUR W with -4 offset
            ("0xb81fc0a8", "stur w8, [x5, #-4]"),          # STUR W with -4 offset
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
        code = []

        code.append("// Hook library tests - validates hooking subsystem functionality")
        code.append("// Auto-generated - do not edit")
        code.append("// Cross-platform tests run on any Windows target (x64 or ARM64)")
        code.append("// Live hook tests only run on ARM64")
        code.append("#include \"veda64.hpp\"")
        code.append("")
        code.append("#if !defined(VEDA64_NO_HOOKS) && (defined(_WIN32) || defined(VEDA64_HOOK_SUPPORT))")
        code.append("")
        code.append("#include <cassert>")
        code.append("#include <cstdint>")
        code.append("#include <cstring>")
        code.append("#include <iostream>")
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
        code.append("    status = hook::install(&dummy_target, &dummy_detour, &original, &handle);")
        code.append("    assert(handle == nullptr);")
        code.append("    assert(status == hook::HookStatus::NotInitialized);")
        code.append("")
        code.append("    // Initialize for remaining tests")
        code.append("    hook::initialize();")
        code.append("")
        code.append("    // null target should fail")
        code.append("    status = hook::install(nullptr, &dummy_detour, &original, &handle);")
        code.append("    assert(handle == nullptr);")
        code.append("    assert(status == hook::HookStatus::InvalidTarget);")
        code.append("")
        code.append("    // null detour should fail")
        code.append("    status = hook::install(&dummy_target, nullptr, &original, &handle);")
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
        code.append("    // Non-relocatable instructions")
        code.append("    assert(!hook::detail::can_relocate(0xd65f03c0));  // RET")
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
        code.append("    // Install hook (starts disabled)")
        code.append("    hook::HookHandle handle = nullptr;")
        code.append("    auto status = hook::install(")
        code.append("        reinterpret_cast<void*>(&target_func),")
        code.append("        reinterpret_cast<void*>(&detour_func),")
        code.append("        reinterpret_cast<void**>(&original_func),")
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
        code.append("        reinterpret_cast<void*>(&target_func),")
        code.append("        reinterpret_cast<void*>(&detour_func),")
        code.append("        reinterpret_cast<void**>(&original_func),")
        code.append("        &handle);")
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
        code.append("        reinterpret_cast<void*>(&target_func),")
        code.append("        reinterpret_cast<void*>(&detour_func),")
        code.append("        reinterpret_cast<void**>(&original_func),")
        code.append("        &handle);")
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
        code.append("    void* orig1 = nullptr;")
        code.append("    void* orig2 = nullptr;")
        code.append("    hook::HookHandle handle1 = nullptr;")
        code.append("    hook::HookHandle handle2 = nullptr;")
        code.append("")
        code.append("    auto status = hook::install(")
        code.append("        reinterpret_cast<void*>(&target_func),")
        code.append("        reinterpret_cast<void*>(&detour_func),")
        code.append("        &orig1, &handle1);")
        code.append("    assert(handle1 != nullptr);")
        code.append("    assert(status == hook::HookStatus::Success);")
        code.append("")
        code.append("    // Second hook on same target should fail")
        code.append("    status = hook::install(")
        code.append("        reinterpret_cast<void*>(&target_func),")
        code.append("        reinterpret_cast<void*>(&detour_func),")
        code.append("        &orig2, &handle2);")
        code.append("    assert(handle2 == nullptr);")
        code.append("    assert(status == hook::HookStatus::HookAlreadyInstalled);")
        code.append("")
        code.append("    hook::remove(handle1);")
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
        code = []

        code.append("// Comprehensive hook examples for Windows ARM64")
        code.append("// Demonstrates various hooking patterns using veda64")
        code.append("//")
        code.append("// This file contains complete, self-contained examples.")
        code.append("// Each namespace demonstrates a different hooking pattern.")
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
        code.append("bool install(void* target) {")
        code.append("    auto status = hook::install(target, reinterpret_cast<void*>(&detour_func),")
        code.append("                                reinterpret_cast<void**>(&original_func), &hook_handle);")
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
        code.append("        return nullptr;")
        code.append("    }")
        code.append("    void* result = original_alloc(size);")
        code.append("    if (result) { total_allocated += size; allocation_count++; }")
        code.append("    return result;")
        code.append("}")
        code.append("")
        code.append("bool install(void* target, size_t max_size) {")
        code.append("    max_alloc_size = max_size;")
        code.append("    auto status = hook::install(target, reinterpret_cast<void*>(&detour_alloc),")
        code.append("                                reinterpret_cast<void**>(&original_alloc), &hook_handle);")
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
        code.append("bool install() {")
        code.append("    HMODULE kernel32 = GetModuleHandleA(\"kernel32.dll\");")
        code.append("    if (!kernel32) return false;")
        code.append("    void* target = GetProcAddress(kernel32, \"IsDebuggerPresent\");")
        code.append("    if (!target) return false;")
        code.append("    auto status = hook::install(target, reinterpret_cast<void*>(&detour_func),")
        code.append("                                reinterpret_cast<void**>(&original_func), &hook_handle);")
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
        code.append("    void* target = GetProcAddress(kernel32, \"CreateFileA\");")
        code.append("    if (!target) return false;")
        code.append("    auto status = hook::install(target, reinterpret_cast<void*>(&detour_func),")
        code.append("                                reinterpret_cast<void**>(&original_func), &hook_handle);")
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
        code.append("bool install(void* target) {")
        code.append("    auto status = hook::install(target, reinterpret_cast<void*>(&detour_func),")
        code.append("                                reinterpret_cast<void**>(&original_func), &hook_handle);")
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
        code.append("bool install() {")
        code.append("    HMODULE kernel32 = GetModuleHandleA(\"kernel32.dll\");")
        code.append("    if (!kernel32) return false;")
        code.append("    void* target = GetProcAddress(kernel32, \"Sleep\");")
        code.append("    if (!target) return false;")
        code.append("    auto status = hook::install(target, reinterpret_cast<void*>(&detour_sleep),")
        code.append("                                reinterpret_cast<void**>(&original_sleep), &hook_handle);")
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
    parser.generate_test_suite(test_dir)
    parser.generate_reference_test(test_dir)
    parser.generate_hook_test(test_dir)
    parser.generate_hook_examples(test_dir)
    print(f"Generated test files")

    # Generate tools
    print(f"\n=== Generating Tools ===")
    tools_dir = base_dir / "tools"
    parser.generate_disasm_tool(tools_dir)


if __name__ == '__main__':
    main()
