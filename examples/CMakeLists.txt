# veda64 examples — Windows ARM64 only

if(NOT (WIN32 AND CMAKE_SYSTEM_PROCESSOR STREQUAL "ARM64"))
    message(STATUS "Skipping examples (Windows ARM64 only)")
    return()
endif()

file(GLOB EXAMPLE_SOURCES "*.cpp")

foreach(example_src ${EXAMPLE_SOURCES})
    get_filename_component(example_name ${example_src} NAME_WE)
    add_executable(example_${example_name} ${example_src})
    target_link_libraries(example_${example_name} PRIVATE veda64)
    set_target_properties(example_${example_name} PROPERTIES FOLDER "examples")
endforeach()
