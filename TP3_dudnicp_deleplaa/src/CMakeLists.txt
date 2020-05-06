project(rng)
file(GLOB sources *.cpp)
add_library(${PROJECT_NAME} ${sources})