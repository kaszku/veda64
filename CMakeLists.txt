cmake_minimum_required(VERSION 3.14)
project(veda64 VERSION 0.1.0 LANGUAGES CXX)

# Enable IDE folder grouping (Visual Studio solution folders)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Option to reduce binary size and remove strings
option(VEDA64_NO_STRINGS "Disable all string functions (to_string, mnemonic_to_string, status_to_string, dump_hook)" OFF)
option(VEDA64_BUILD_TESTS "Build test executables" ON)
option(VEDA64_HOOK "Enable inline hooking support (Windows only)" ON)

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

# Organize library files into IDE groups and solution folder
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/lib" PREFIX "lib" FILES ${VEDA64_SOURCES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/include" PREFIX "include" FILES ${VEDA64_HEADERS})
set_target_properties(veda64 PROPERTIES FOLDER "lib")

# Link ntdll for NT syscalls on Windows (only when hooks are enabled)
if(WIN32 AND VEDA64_HOOK)
    target_link_libraries(veda64 PUBLIC ntdll)
endif()

# Tools
file(GLOB TOOLS_SOURCES "tools/*.cpp")
add_executable(veda64-disasm ${TOOLS_SOURCES})
target_link_libraries(veda64-disasm PRIVATE veda64)
source_group("tools" FILES ${TOOLS_SOURCES})
set_target_properties(veda64-disasm PROPERTIES FOLDER "tools")

# Enable testing
if(VEDA64_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

# Installation
install(TARGETS veda64 veda64-disasm
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/ DESTINATION include)
