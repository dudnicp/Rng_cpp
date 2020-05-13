project(rng)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIRS})

file(GLOB sources *.cpp)
add_library(${PROJECT_NAME} ${sources})