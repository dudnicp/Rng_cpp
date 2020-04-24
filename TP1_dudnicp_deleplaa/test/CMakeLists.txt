include_directories(${CMAKE_SOURCE_DIR}/src)

file(COPY test.txt DESTINATION ${CMAKE_BINARY_DIR}/test)
file(COPY test.txt DESTINATION ${CMAKE_BINARY_DIR})

add_executable (test_default_constructor test_default_constructor.cpp)
target_link_libraries(test_default_constructor dvector)

add_executable (test_constructor test_constructor.cpp)
target_link_libraries(test_constructor dvector)

add_executable (test_copy_constructor test_copy_constructor.cpp)
target_link_libraries(test_copy_constructor dvector)

add_executable (test_file_constructor test_file_constructor.cpp)
target_link_libraries(test_file_constructor dvector)

add_executable (test_display test_display.cpp)
target_link_libraries(test_display dvector)

add_executable(demo_Q1 demo_Q1.cpp)
target_link_libraries(demo_Q1 dvector)

add_custom_target(check 
    COMMAND test_default_constructor
    COMMAND test_constructor
    COMMAND test_copy_constructor
    COMMAND test_file_constructor
    COMMAND test_display)

