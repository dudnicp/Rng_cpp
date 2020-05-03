include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB allTests *.cpp)

foreach(test ${allTests})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName}.exe test)
    target_link_libraries(${testName}.exe dvector)
endforeach(test)
