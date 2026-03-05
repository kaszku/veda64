cmake_minimum_required(VERSION 3.14)
project(veda64 VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# IDE folder grouping
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Option to reduce binary size and remove strings
option(VEDA64_NO_STRINGS "Disable all string functions (to_string, mnemonic_to_string, status_to_string, dump_hook)" OFF)
option(VEDA64_BUILD_TESTS "Build test executables" ON)
option(VEDA64_HOOK "Enable inline hooking support (Windows only)" ON)
option(VEDA64_PYTHON "Build Python bindings via nanobind (requires vcpkg toolchain)" ON)
option(VEDA64_NO_IR "Disable IR lifting support" OFF)

# Compiler warnings
if(MSVC)
    add_compile_options(/W4 /bigobj)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Pass options as compile definitions
if(VEDA64_NO_STRINGS)
    add_compile_definitions(VEDA64_NO_STRINGS)
endif()

if(VEDA64_NO_IR)
    add_compile_definitions(VEDA64_NO_IR)
endif()

# Collect all source and header files
file(GLOB_RECURSE VEDA64_SOURCES "lib/*.cpp")
file(GLOB_RECURSE VEDA64_HEADERS "include/*.hpp")

# Hook support
if(NOT VEDA64_HOOK)
    list(REMOVE_ITEM VEDA64_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/lib/hook.cpp")
    add_compile_definitions(VEDA64_NO_HOOKS)
endif()

# Create library
add_library(veda64 ${VEDA64_SOURCES} ${VEDA64_HEADERS})
target_include_directories(veda64 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
set_target_properties(veda64 PROPERTIES FOLDER "lib")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/lib" PREFIX "Source Files" FILES ${VEDA64_SOURCES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${VEDA64_HEADERS})

# Link ntdll for NT syscalls on Windows (only when hooks are enabled)
if(WIN32 AND VEDA64_HOOK)
    target_link_libraries(veda64 PUBLIC ntdll)
endif()

# Tools
add_executable(veda64-disasm tools/veda64-disasm.cpp)
target_link_libraries(veda64-disasm PRIVATE veda64)
set_target_properties(veda64-disasm PROPERTIES FOLDER "tools")

if(NOT VEDA64_NO_IR)
    add_executable(veda64-interp tools/veda64-interp.cpp)
    target_link_libraries(veda64-interp PRIVATE veda64)
    set_target_properties(veda64-interp PROPERTIES FOLDER "tools")
endif()

# Enable testing
if(VEDA64_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

# Python bindings via nanobind (use vcpkg toolchain to satisfy dependency)
if(VEDA64_PYTHON)
    find_package(Python 3 COMPONENTS Interpreter Development.Module REQUIRED)
    find_package(nanobind CONFIG REQUIRED)
    nanobind_add_module(veda64_py NB_STATIC python/veda64_py.cpp)
    target_link_libraries(veda64_py PRIVATE veda64)
    set_target_properties(veda64_py PROPERTIES FOLDER "python")
    install(TARGETS veda64_py LIBRARY DESTINATION python)
endif()

# Installation
install(TARGETS veda64 veda64-disasm
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/ DESTINATION include)
