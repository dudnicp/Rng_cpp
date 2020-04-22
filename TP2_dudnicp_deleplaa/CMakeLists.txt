# Le fichier doit être renommé CMakeLists.txt
cmake_minimum_required(VERSION 2.8.2)

project(TP1_dudnicp_deleplaa)

set(CMAKE_CXX_FLAGS "-g -Wall")

set(SOURCE_FILES 
src/Dvector.cpp
src/Dvector.h
src/Test_Dvector.cpp)

add_executable(test_tp2 ${SOURCE_FILES})

