# Sorting Algorithms with Visualization

# Project build VS Code
If you want to build this project choose profile from ./conan_profiles and write **the following commands**:
1. conan install . --profile:host ./conan_profiles/windows64release --profile:build ./conan_profiles/windows64release --build missing
2. cmake --preset conan-default
3. cmake --build --preset conan-release
