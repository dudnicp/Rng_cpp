include_directories(${CMAKE_SOURCE_DIR}/src)

file(COPY init_files/ DESTINATION ${CMAKE_BINARY_DIR}/test)
file(COPY init_files/ DESTINATION ${CMAKE_BINARY_DIR})

file(GLOB allTests *.cpp)

foreach(test ${allTests})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test})
    target_link_libraries(${testName} dvector)
endforeach(test)


