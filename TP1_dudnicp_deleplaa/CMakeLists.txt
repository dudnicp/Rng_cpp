# Le fichier doit être renommé CMakeLists.txt
cmake_minimum_required(VERSION 2.8.2)

project(TP1_dudnicp_deleplaa)

set(CMAKE_CXX_FLAGS "-g -Wall")

add_executable(exe src/Dvector.cpp
src/Dvector.h
)

