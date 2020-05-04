include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(DemoQ1 DemoQ1.cpp)
target_link_libraries(DemoQ1 dvector)

add_executable(DemoComplete DemoComplete.cpp)
target_link_libraries(DemoComplete dvector)