include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB examples *.cpp)

foreach(f ${examples})
    get_filename_component(fName ${f} NAME_WE)
    add_executable(${fName} ${f})
    target_link_libraries(${fName} rng)
endforeach(f)
