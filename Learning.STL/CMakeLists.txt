cmake_minimum_required(VERSION 3.12)
project(Learning_STL)

set(CMAKE_CXX_STANDARD 11)

add_executable(Learning_STL main.cpp Algorithm/algorithm.cpp Algorithm/algorithm.h Algorithm/functional.cpp Algorithm/functional.h String/w_string.cpp String/w_string.h Utils/utils.cpp Utils/utils.h)