cmake_minimum_required(VERSION 3.14)
project(veda64 VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Option to reduce binary size and remove strings
option(VEDA64_NO_STRINGS "Disable all string functions (to_string, mnemonic_to_string, status_to_string, dump_hook)" OFF)

# Compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Pass options as compile definitions
if(VEDA64_NO_STRINGS)
    add_compile_definitions(VEDA64_NO_STRINGS)
endif()

# Collect all source files
file(GLOB_RECURSE VEDA64_SOURCES "lib/*.cpp")

# Create library
add_library(veda64 ${VEDA64_SOURCES})
target_include_directories(veda64 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Link ntdll for NT syscalls on Windows
if(WIN32)
    target_link_libraries(veda64 PUBLIC ntdll)
endif()

# Tools
add_executable(veda64-disasm tools/veda64-disasm.cpp)
target_link_libraries(veda64-disasm PRIVATE veda64)

# Enable testing
enable_testing()
add_subdirectory(test)

# Installation
install(TARGETS veda64 veda64-disasm
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/ DESTINATION include)
