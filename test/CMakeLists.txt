# Test suite for veda64

# Collect all test files
file(GLOB TEST_SOURCES "test_*.cpp")

# Create test executables
foreach(test_src ${TEST_SOURCES})
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${test_src})
    target_link_libraries(${test_name} veda64)
    add_test(NAME ${test_name} COMMAND ${test_name})
    set_target_properties(${test_name} PROPERTIES FOLDER "test")
    source_group("test" FILES ${test_src})
endforeach()
