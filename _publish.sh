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

echo "Running tests..."
CTEST="/c/Program Files/Microsoft Visual Studio/18/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/ctest.exe"
if ! "$CTEST" --test-dir __build_arm64 --output-on-failure; then
    echo "Error: tests failed. Fix before publishing."
    exit 1
fi

echo "Fetching public remote..."
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
