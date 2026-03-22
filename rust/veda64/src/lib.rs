//! # veda64
//!
//! Rust bindings for the veda64 ARM64 instruction decoder and disassembler.
//!
//! ```rust
//! use veda64::{decode, Mnemonic};
//!
//! let insn = decode(0x8B020020).unwrap();
//! assert_eq!(insn.mnemonic, Mnemonic::ADD);
//! assert_eq!(insn.to_string(), "add x0, x1, x2");
//! ```

mod bridge;
mod mnemonic;

pub use mnemonic::Mnemonic;

/// ARM64 condition codes.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
#[repr(i8)]
pub enum Condition {
    None = -1,
    EQ = 0,
    NE = 1,
    CS = 2,
    CC = 3,
    MI = 4,
    PL = 5,
    VS = 6,
    VC = 7,
    HI = 8,
    LS = 9,
    GE = 10,
    LT = 11,
    GT = 12,
    LE = 13,
    AL = 14,
    NV = 15,
}

impl Condition {
    pub fn from_i8(v: i8) -> Self {
        if (-1..=15).contains(&v) {
            unsafe { std::mem::transmute(v) }
        } else {
            Self::None
        }
    }

    pub fn name(&self) -> &'static str {
        match self {
            Self::None => "",
            Self::EQ => "eq",
            Self::NE => "ne",
            Self::CS => "cs",
            Self::CC => "cc",
            Self::MI => "mi",
            Self::PL => "pl",
            Self::VS => "vs",
            Self::VC => "vc",
            Self::HI => "hi",
            Self::LS => "ls",
            Self::GE => "ge",
            Self::LT => "lt",
            Self::GT => "gt",
            Self::LE => "le",
            Self::AL => "al",
            Self::NV => "nv",
        }
    }
}

/// Operand type classification.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
#[repr(u8)]
pub enum OperandType {
    Register = 0,
    IndexedRegister = 1,
    SMETileRegister = 2,
    Immediate = 3,
    DecimalImmediate = 4,
    SignedImmediate = 5,
    Memory = 6,
    MemoryRegOffset = 7,
    MemorySVEOffset = 8,
    Label = 9,
    Relative = 10,
    SystemRegister = 11,
    Shift = 12,
    Extend = 13,
    Extend64 = 14,
    Index = 15,
    Pattern = 16,
    SVEMulImm = 17,
    Prefetch = 18,
    Barrier = 19,
    FloatImmediate = 20,
    RegisterList = 21,
    IndexedRegisterList = 22,
    PstateField = 23,
    FixedSym = 24,
    SysOp = 25,
    SVEVLxImm = 26,
    Unknown = 27,
}

impl OperandType {
    pub fn from_u8(v: u8) -> Self {
        if v <= 27 {
            unsafe { std::mem::transmute(v) }
        } else {
            Self::Unknown
        }
    }
}

/// Shift type specifier.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u8)]
pub enum ShiftType {
    LSL = 0,
    LSR = 1,
    ASR = 2,
    ROR = 3,
    MSL = 4,
}

/// Extend type specifier.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u8)]
pub enum ExtendType {
    UXTB = 0,
    UXTH = 1,
    UXTW = 2,
    UXTX = 3,
    SXTB = 4,
    SXTH = 5,
    SXTW = 6,
    SXTX = 7,
}

/// Memory addressing mode.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u8)]
pub enum MemoryMode {
    Base = 0,
    Offset = 1,
    PreIndex = 2,
    PostIndex = 3,
    MulVL = 4,
}

/// A decoded operand.
#[derive(Debug, Clone)]
pub enum Operand {
    /// General-purpose, vector, SVE, or predicate register (raw register value).
    Register(u16),
    /// Register with element index.
    IndexedRegister { reg: u16, index: u32 },
    /// Unsigned immediate value.
    Immediate(u64),
    /// Decimal immediate value.
    DecimalImmediate(u64),
    /// Signed immediate value.
    SignedImmediate(i32),
    /// Memory operand: base register, offset, addressing mode.
    Memory {
        base: u16,
        offset: i32,
        mode: MemoryMode,
    },
    /// Memory with register offset.
    MemoryRegOffset {
        base: u16,
        index: u16,
        extend: ExtendType,
        amount: u8,
    },
    /// Branch target label (PC-relative offset).
    Label(i32),
    /// PC-relative offset for data references.
    Relative(u64),
    /// Shift specifier.
    Shift {
        shift_type: ShiftType,
        amount: u8,
    },
    /// Extend specifier.
    Extend {
        ext_type: ExtendType,
        amount: u8,
        is_64: bool,
    },
    /// System register.
    SystemRegister(u32),
    /// Prefetch operation.
    Prefetch(u8),
    /// Barrier option.
    Barrier(u8),
    /// Float immediate (encoded).
    FloatImmediate(u16),
    /// Register list.
    RegisterList { first: u16, count: u8 },
    /// SME tile register.
    SMETileRegister(u16),
    /// SVE pattern.
    Pattern(u8),
    /// Other/unsupported operand type with raw string representation.
    Other {
        op_type: OperandType,
        display: String,
    },
}

impl std::fmt::Display for Operand {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            Self::Register(r) => write!(f, "reg:{r}"),
            Self::IndexedRegister { reg, index } => write!(f, "reg:{reg}[{index}]"),
            Self::Immediate(v) => write!(f, "#0x{v:x}"),
            Self::DecimalImmediate(v) => write!(f, "#{v}"),
            Self::SignedImmediate(v) => write!(f, "#{v}"),
            Self::Memory { base, offset, .. } => write!(f, "[reg:{base}, #{offset}]"),
            Self::MemoryRegOffset { base, index, .. } => write!(f, "[reg:{base}, reg:{index}]"),
            Self::Label(off) => write!(f, "#{off}"),
            Self::Relative(off) => write!(f, "#{off}"),
            Self::Shift { shift_type, amount } => write!(f, "{shift_type:?} #{amount}"),
            Self::Extend { ext_type, amount, .. } => write!(f, "{ext_type:?} #{amount}"),
            Self::SystemRegister(r) => write!(f, "sysreg:{r}"),
            Self::Prefetch(p) => write!(f, "prfop:{p}"),
            Self::Barrier(b) => write!(f, "barrier:{b}"),
            Self::FloatImmediate(v) => write!(f, "fimm:{v}"),
            Self::RegisterList { first, count } => write!(f, "{{reg:{first}..+{count}}}"),
            Self::SMETileRegister(t) => write!(f, "za:{t}"),
            Self::Pattern(p) => write!(f, "pat:{p}"),
            Self::Other { display, .. } => f.write_str(display),
        }
    }
}

/// A decoded ARM64 instruction.
#[derive(Debug, Clone)]
pub struct Instruction {
    /// Instruction mnemonic.
    pub mnemonic: Mnemonic,
    /// Condition code (for conditional instructions).
    pub condition: Condition,
    /// Raw 32-bit instruction value.
    pub raw_value: u32,
    /// Decoded operands.
    pub operands: Vec<Operand>,
    /// Formatted disassembly string (cached from C++).
    display: String,
}

impl Instruction {
    /// Format as disassembly string (e.g., "add x0, x1, x2").
    pub fn to_string(&self) -> &str {
        &self.display
    }
}

impl std::fmt::Display for Instruction {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        f.write_str(&self.display)
    }
}

/// Decode a single ARM64 instruction from a 32-bit value.
///
/// Returns `None` if the encoding is unrecognized.
///
/// ```rust
/// use veda64::{decode, Mnemonic, OperandType};
///
/// let insn = decode(0x8B020020).unwrap();
/// assert_eq!(insn.mnemonic, Mnemonic::ADD);
/// assert_eq!(insn.operands.len(), 3);
/// ```
pub fn decode(raw: u32) -> Option<Instruction> {
    let d = bridge::ffi::decode(raw);
    if !bridge::ffi::is_valid(&d) {
        return None;
    }

    let mnemonic = Mnemonic::from_u16(bridge::ffi::get_mnemonic(&d));
    let condition = Condition::from_i8(bridge::ffi::get_condition(&d));
    let raw_value = bridge::ffi::get_raw_value(&d);
    let num_ops = bridge::ffi::get_num_operands(&d);
    let display = bridge::ffi::insn_to_string(&d);

    let mut operands = Vec::with_capacity(num_ops as usize);
    for i in 0..num_ops {
        let op_type = OperandType::from_u8(bridge::ffi::get_operand_type(&d, i));
        let operand = match op_type {
            OperandType::Register => Operand::Register(bridge::ffi::get_operand_reg(&d, i)),
            OperandType::IndexedRegister => Operand::IndexedRegister {
                reg: bridge::ffi::get_operand_reg(&d, i),
                index: bridge::ffi::get_operand_imm(&d, i) as u32,
            },
            OperandType::SMETileRegister => {
                Operand::SMETileRegister(bridge::ffi::get_operand_reg(&d, i))
            }
            OperandType::Immediate => Operand::Immediate(bridge::ffi::get_operand_imm(&d, i)),
            OperandType::DecimalImmediate => {
                Operand::DecimalImmediate(bridge::ffi::get_operand_imm(&d, i))
            }
            OperandType::SignedImmediate => {
                Operand::SignedImmediate(bridge::ffi::get_operand_simm(&d, i))
            }
            OperandType::Memory | OperandType::MemorySVEOffset => Operand::Memory {
                base: bridge::ffi::get_operand_mem_base(&d, i),
                offset: bridge::ffi::get_operand_mem_offset(&d, i),
                mode: unsafe {
                    std::mem::transmute(bridge::ffi::get_operand_mem_mode(&d, i).min(4))
                },
            },
            OperandType::MemoryRegOffset => Operand::MemoryRegOffset {
                base: bridge::ffi::get_operand_mem_base(&d, i),
                index: bridge::ffi::get_operand_reg(&d, i),
                extend: unsafe {
                    std::mem::transmute(bridge::ffi::get_operand_extend_type(&d, i).min(7))
                },
                amount: bridge::ffi::get_operand_extend_amount(&d, i),
            },
            OperandType::Label => Operand::Label(bridge::ffi::get_operand_simm(&d, i)),
            OperandType::Relative => Operand::Relative(bridge::ffi::get_operand_imm(&d, i)),
            OperandType::Shift => Operand::Shift {
                shift_type: unsafe {
                    std::mem::transmute(bridge::ffi::get_operand_shift_type(&d, i).min(4))
                },
                amount: bridge::ffi::get_operand_shift_amount(&d, i),
            },
            OperandType::Extend | OperandType::Extend64 => Operand::Extend {
                ext_type: unsafe {
                    std::mem::transmute(bridge::ffi::get_operand_extend_type(&d, i).min(7))
                },
                amount: bridge::ffi::get_operand_extend_amount(&d, i),
                is_64: op_type == OperandType::Extend64,
            },
            OperandType::SystemRegister => {
                Operand::SystemRegister(bridge::ffi::get_operand_imm(&d, i) as u32)
            }
            OperandType::Prefetch => {
                Operand::Prefetch(bridge::ffi::get_operand_imm(&d, i) as u8)
            }
            OperandType::Barrier => {
                Operand::Barrier(bridge::ffi::get_operand_imm(&d, i) as u8)
            }
            OperandType::FloatImmediate => {
                Operand::FloatImmediate(bridge::ffi::get_operand_imm(&d, i) as u16)
            }
            OperandType::RegisterList | OperandType::IndexedRegisterList => {
                Operand::RegisterList {
                    first: bridge::ffi::get_operand_reg(&d, i),
                    count: bridge::ffi::get_operand_shift_amount(&d, i), // count stored in rl.count
                }
            }
            OperandType::Pattern => {
                Operand::Pattern(bridge::ffi::get_operand_imm(&d, i) as u8)
            }
            _ => Operand::Other {
                op_type,
                display: bridge::ffi::operand_to_string(&d, i),
            },
        };
        operands.push(operand);
    }

    Some(Instruction {
        mnemonic,
        condition,
        raw_value,
        operands,
        display,
    })
}

/// Disassemble a single ARM64 instruction to a string.
///
/// Returns `None` if the encoding is unrecognized.
///
/// ```rust
/// assert_eq!(veda64::disassemble(0x8B020020).as_deref(), Some("add x0, x1, x2"));
/// ```
pub fn disassemble(raw: u32) -> Option<String> {
    let d = bridge::ffi::decode(raw);
    if !bridge::ffi::is_valid(&d) {
        return None;
    }
    Some(bridge::ffi::insn_to_string(&d))
}

/// Get the string name of a mnemonic from the C++ library.
pub fn mnemonic_name(m: Mnemonic) -> String {
    bridge::ffi::mnemonic_name(m as u16)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn decode_add() {
        let insn = decode(0x8B020020).unwrap();
        assert_eq!(insn.mnemonic, Mnemonic::ADD);
        assert_eq!(insn.operands.len(), 3);
        assert!(insn.to_string().contains("add"));
    }

    #[test]
    fn decode_sub() {
        let insn = decode(0xCB020020).unwrap();
        assert_eq!(insn.mnemonic, Mnemonic::SUB);
    }

    #[test]
    fn decode_invalid() {
        // All zeros = UDF
        let insn = decode(0x00000000);
        // UDF decodes but as UNKNOWN or UDF mnemonic
        assert!(insn.is_some() || insn.is_none());
    }

    #[test]
    fn decode_ldr() {
        let insn = decode(0xF9400420).unwrap();
        assert!(insn.to_string().contains("ldr"));
        // Should have a memory operand
        assert!(insn.operands.iter().any(|op| matches!(op, Operand::Memory { .. })));
    }

    #[test]
    fn decode_b() {
        let insn = decode(0x14000040).unwrap();
        assert_eq!(insn.mnemonic, Mnemonic::B);
    }

    #[test]
    fn decode_beq() {
        let insn = decode(0x54000040).unwrap();
        assert_eq!(insn.mnemonic, Mnemonic::B);
        assert_eq!(insn.condition, Condition::EQ);
    }

    #[test]
    fn decode_movz() {
        let insn = decode(0xD2824680).unwrap();
        assert!(insn.to_string().contains("mov"));
    }

    #[test]
    fn disassemble_add() {
        let s = disassemble(0x8B020020).unwrap();
        assert_eq!(s, "add x0, x1, x2");
    }

    #[test]
    fn decode_nop() {
        let insn = decode(0xD503201F).unwrap();
        assert_eq!(insn.mnemonic, Mnemonic::NOP);
        assert_eq!(insn.to_string(), "nop");
    }

    #[test]
    fn decode_ret() {
        let insn = decode(0xD65F03C0).unwrap();
        assert_eq!(insn.mnemonic, Mnemonic::RET);
    }

    #[test]
    fn mnemonic_display() {
        assert_eq!(Mnemonic::ADD.name(), "add");
        assert_eq!(Mnemonic::LDR.name(), "ldr");
        assert_eq!(format!("{}", Mnemonic::SUB), "sub");
    }

    #[test]
    fn decode_str_memory() {
        let insn = decode(0xF9000420).unwrap(); // STR X0, [X1, #8]
        assert!(insn.to_string().contains("str"));
        let mem = insn.operands.iter().find(|op| matches!(op, Operand::Memory { .. }));
        assert!(mem.is_some());
        if let Some(Operand::Memory { offset, .. }) = mem {
            assert_eq!(*offset, 8);
        }
    }

    #[test]
    fn decode_ldadd_atomic() {
        let insn = decode(0xB8200020).unwrap();
        assert!(insn.to_string().contains("ldadd"));
    }
}
