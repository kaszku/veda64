use std::path::PathBuf;

fn main() {
    let root = PathBuf::from(env!("CARGO_MANIFEST_DIR"))
        .join("..")
        .join("..");

    let include_dir = root.join("include");
    let lib_dir = root.join("lib");

    // Collect all C++ source files from lib/
    let mut cpp_sources: Vec<PathBuf> = Vec::new();

    // Top-level lib sources
    for entry in std::fs::read_dir(&lib_dir).expect("failed to read lib/") {
        let entry = entry.unwrap();
        let path = entry.path();
        if path.extension().map_or(false, |e| e == "cpp") {
            // Skip hook.cpp on non-Windows
            if !cfg!(target_os = "windows") && path.file_name().unwrap() == "hook.cpp" {
                continue;
            }
            cpp_sources.push(path);
        }
    }

    // lib/format/ sources
    let format_dir = lib_dir.join("format");
    for entry in std::fs::read_dir(&format_dir).expect("failed to read lib/format/") {
        let entry = entry.unwrap();
        let path = entry.path();
        if path.extension().map_or(false, |e| e == "cpp") {
            cpp_sources.push(path);
        }
    }

    // lib/ir/ sources
    let ir_dir = lib_dir.join("ir");
    if ir_dir.exists() {
        for entry in std::fs::read_dir(&ir_dir).expect("failed to read lib/ir/") {
            let entry = entry.unwrap();
            let path = entry.path();
            if path.extension().map_or(false, |e| e == "cpp") {
                cpp_sources.push(path);
            }
        }
    }

    // Build the veda64 C++ library
    cc::Build::new()
        .cpp(true)
        .std("c++17")
        .define("VEDA64_STRINGS", None)
        .define("VEDA64_IR", None)
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
        .include(&include_dir)
        .include(&bridge_hpp_dir)
        .compile("veda64_bridge");

    println!("cargo:rerun-if-changed=src/bridge.rs");
    println!("cargo:rerun-if-changed=src/veda64_bridge.cpp");
    println!("cargo:rerun-if-changed=src/veda64_bridge.hpp");
}
