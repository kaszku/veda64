use std::path::PathBuf;

fn main() {
    let root = PathBuf::from(env!("CARGO_MANIFEST_DIR"))
        .join("..")
        .join("..");

    let include_dir = root.join("include");
    let lib_dir = root.join("lib");

    // Collect all C++ source files from lib/ and every subdirectory. lib/
    // was reorganized into subdirs (assembler/, codegen/, core/, hook/, ...),
    // so a one-level scan misses the modules the bridge depends on.
    let mut cpp_sources: Vec<PathBuf> = Vec::new();

    fn collect_cpp(dir: &PathBuf, out: &mut Vec<PathBuf>) {
        let entries = match std::fs::read_dir(dir) {
            Ok(it) => it,
            Err(_) => return,
        };
        for entry in entries {
            let entry = entry.unwrap();
            let path = entry.path();
            if path.is_dir() {
                collect_cpp(&path, out);
            } else if path.extension().map_or(false, |e| e == "cpp") {
                // hook code uses Win32-only syscalls.
                let name = path.file_name().unwrap().to_string_lossy().to_string();
                if !cfg!(target_os = "windows") && (name == "hook.cpp" || name.starts_with("hook")) {
                    continue;
                }
                out.push(path);
            }
        }
    }
    collect_cpp(&lib_dir, &mut cpp_sources);

    // Build the veda64 C++ library
    cc::Build::new()
        .cpp(true)
        .std("c++17")
        .define("VEDA64_STRINGS", None)
        .define("VEDA64_IR", None)
        .define("VEDA64_CODEGEN", None)
        .define("VEDA64_ASSEMBLER", None)
        .define("VEDA64_HOOK", None)
        .include(&include_dir)
        .files(&cpp_sources)
        .compile("veda64_cpp");

    // Build the cxx bridge
    let bridge_cpp = PathBuf::from(env!("CARGO_MANIFEST_DIR"))
        .join("src")
        .join("veda64_bridge.cpp");
    let bridge_hpp_dir = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("src");

    cxx_build::bridge("src/bridge.rs")
        .file(&bridge_cpp)
        .std("c++17")
        .define("VEDA64_STRINGS", None)
        .define("VEDA64_IR", None)
        .define("VEDA64_CODEGEN", None)
        .define("VEDA64_ASSEMBLER", None)
        .define("VEDA64_HOOK", None)
        .include(&include_dir)
        .include(&bridge_hpp_dir)
        .compile("veda64_bridge");

    println!("cargo:rerun-if-changed=src/bridge.rs");
    println!("cargo:rerun-if-changed=src/veda64_bridge.cpp");
    println!("cargo:rerun-if-changed=src/veda64_bridge.hpp");
}
