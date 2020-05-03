cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-g -Wall")

project(TP2_dudnicp_deleplaa)

add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(test)
enable_testing()

file(GLOB allTests test/*.cpp)

foreach(test ${allTests})
    get_filename_component(testName ${test} NAME_WE)
    add_test(NAME ${testName} COMMAND ${testName})
endforeach(test)

add_custom_target(check COMMAND make test VERBATIM)