param(
    [switch]$Configure,
    [switch]$VS,
    [switch]$Test,
    [switch]$Clean
)

$ErrorActionPreference = "Stop"

# VS2026 dev shell setup (ARM64 native)
Import-Module "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\Microsoft.VisualStudio.DevShell.dll"
Enter-VsDevShell -VsInstallPath "C:\Program Files\Microsoft Visual Studio\18\Community" -SkipAutomaticLocation -Arch arm64

$root = Split-Path $PSScriptRoot -Parent

# Common cmake args
$cmakeArgs = @(
    "-DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
    "-DVCPKG_OVERLAY_PORTS=$root/vcpkg_overlay_ports"
    "-DPython_EXECUTABLE=C:/Python311-arm64/python.exe"
)

if ($VS) {
    $buildDir = "$root/__build_vs"
} else {
    $buildDir = "$root/__build_arm64"
}

if ($Clean) {
    Write-Host "Cleaning $buildDir..."
    if (Test-Path $buildDir) { Remove-Item $buildDir -Recurse -Force }
    exit 0
}

if ($VS) {
    # Visual Studio 2026 generator (for IDE use)
    if ($Configure -or !(Test-Path "$buildDir/veda64.sln")) {
        Write-Host "Configuring VS2026 ARM64..."
        cmake -B $buildDir -G "Visual Studio 18 2026" -A ARM64 @cmakeArgs -S $root
    }
    Write-Host "Building (Release)..."
    cmake --build $buildDir --config Release
    if ($Test) {
        Write-Host "Testing..."
        ctest --test-dir $buildDir -C Release
    }
} else {
    # Ninja generator (default, fast)
    if ($Configure -or !(Test-Path "$buildDir/build.ninja")) {
        Write-Host "Configuring Ninja ARM64..."
        cmake -B $buildDir -G Ninja -DCMAKE_BUILD_TYPE=Release @cmakeArgs -S $root
    }
    Write-Host "Building..."
    ninja -C $buildDir
    if ($Test) {
        Write-Host "Testing..."
        ctest --test-dir $buildDir
    }
}
