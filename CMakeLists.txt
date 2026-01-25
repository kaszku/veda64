cmake_minimum_required(VERSION 3.15)
project(veda64 VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create library
add_library(veda64 STATIC
    lib/veda64.cpp
)

# Set public headers
target_include_directories(veda64 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

# Add compiler flags for better warnings
if(MSVC)
    target_compile_options(veda64 PRIVATE /W4)
else()
    target_compile_options(veda64 PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Enable testing
enable_testing()

# Add test executable
add_executable(veda64_test test/test_veda64.cpp)
target_link_libraries(veda64_test PRIVATE veda64)

# Register tests
add_test(NAME veda64_basic_tests COMMAND veda64_test)
