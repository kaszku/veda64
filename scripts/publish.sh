#!/usr/bin/env bash
set -euo pipefail

DRY_RUN=false
if [[ "${1:-}" == "--dry-run" ]]; then
    DRY_RUN=true
    shift
fi

MSG="${1:-}"
if [[ -z "$MSG" ]]; then
    echo "Usage: bash _publish.sh [--dry-run] \"commit message\""
    exit 1
fi

# Verify repo root and main branch
if [[ ! -f veda64_public.txt ]]; then
    echo "Error: veda64_public.txt not found. Run from repo root."
    exit 1
fi

BRANCH=$(git rev-parse --abbrev-ref HEAD)
if [[ "$BRANCH" != "main" ]]; then
    echo "Error: must be on main branch (currently on $BRANCH)"
    exit 1
fi

if [[ -n "$(git status --porcelain -- $(grep -v '^$' veda64_public.txt))" ]]; then
    echo "Error: uncommitted changes in public files. Commit first:"
    git status --short -- $(grep -v '^$' veda64_public.txt)
    exit 1
fi

# Read file list before switching branches (file may not be committed)
mapfile -t PUBLIC_FILES < <(grep -v '^$' veda64_public.txt)

CTEST="/c/Program Files/Microsoft Visual Studio/18/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/ctest.exe"
REPO_ROOT="$(pwd)"

# ── Build and test public files in an isolated temp directory ──
echo "=== Building and testing public files in isolation ==="
TMPDIR=$(mktemp -d)
trap 'rm -rf "$TMPDIR"' EXIT

# Copy only the public files
for file in "${PUBLIC_FILES[@]}"; do
    mkdir -p "$TMPDIR/$(dirname "$file")"
    cp "$file" "$TMPDIR/$file"
done

# Convert to Windows path for PowerShell
TMPDIR_WIN=$(cygpath -w "$TMPDIR")

# Create a build script in the temp dir
cat > "$TMPDIR/_build_publish.ps1" << 'PSEOF'
param([string]$SourceDir)
$ErrorActionPreference = 'Stop'
$cmake = "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
$ninja = "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja\ninja.exe"

# Import VS dev environment
$vsdev = "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat"
$envOutput = cmd /c "`"$vsdev`" -arch=arm64 -host_arch=arm64 >nul 2>&1 && set"
foreach ($line in $envOutput) {
    if ($line -match '^([^=]+)=(.*)$') {
        [Environment]::SetEnvironmentVariable($matches[1], $matches[2], 'Process')
    }
}

$buildDir = Join-Path $SourceDir "_build"
New-Item -ItemType Directory -Path $buildDir -Force | Out-Null

Write-Host "Configuring..."
& $cmake -S $SourceDir -B $buildDir -G Ninja -DCMAKE_BUILD_TYPE=Release "-DCMAKE_MAKE_PROGRAM=$ninja" -DVEDA64_STRINGS=ON -DVEDA64_TESTS=ON -DVEDA64_IR=ON -DVEDA64_CODEGEN=ON -DVEDA64_HOOK=ON -DVEDA64_PYTHON=OFF
if ($LASTEXITCODE -ne 0) { exit 1 }

Write-Host "Building..."
& $cmake --build $buildDir
if ($LASTEXITCODE -ne 0) { exit 1 }
PSEOF

# Run the build
powershell -NoProfile -ExecutionPolicy Bypass -File "$TMPDIR/_build_publish.ps1" -SourceDir "$TMPDIR_WIN"
if [[ $? -ne 0 ]]; then
    echo "Error: build failed."
    exit 1
fi

echo "Running tests..."
if ! "$CTEST" --test-dir "$TMPDIR/_build" --output-on-failure; then
    echo "Error: tests failed. Fix before publishing."
    exit 1
fi

echo "=== Build and tests passed ==="

# ── Publish to public remote ──
echo "Fetching public remote..."
cd "$REPO_ROOT"
git fetch public

# Create temp branch from public/main
git checkout -B _public-release public/main

# Remove all tracked files
git rm -rf . > /dev/null 2>&1 || true

# Checkout public files from main and stage them
for file in "${PUBLIC_FILES[@]}"; do
    git checkout main -- "$file"
done

git add -- "${PUBLIC_FILES[@]}"
git commit -m "$MSG"

if $DRY_RUN; then
    echo ""
    echo "=== DRY RUN ==="
    echo "Commit message: $MSG"
    echo ""
    echo "All files in commit:"
    git ls-tree --name-only -r HEAD | sort
    echo ""
    echo "Diff summary vs public/main:"
    git diff --stat public/main HEAD
    echo ""
    echo "Skipping push (dry-run mode)"
else
    echo "Pushing to public..."
    git push public _public-release:main --force
fi

# Clean up
git checkout -f main
git branch -D _public-release
echo "Done."
