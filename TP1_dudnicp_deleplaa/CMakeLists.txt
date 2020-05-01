cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-g -Wall")

project(TP1_dudnicp_deleplaa)

add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(test)
enable_testing()
add_test(NAME test_default_constructor
    COMMAND test_default_constructor)
add_test(NAME test_constructor
    COMMAND test_constructor)
add_test(NAME test_copy_constructor
    COMMAND test_copy_constructor)
add_test(NAME test_file_constructor
    COMMAND test_file_constructor)
add_test(NAME test_display
    COMMAND test_display)

add_custom_target(demo COMMAND demo_Q1)
