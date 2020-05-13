find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIRS}
)

add_definitions(-DBOOST_TEST_DYN_LINK)

file(GLOB allTests *.cpp)

foreach(test ${allTests})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test})
    target_link_libraries(${testName} dvector
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    )
endforeach(test)
