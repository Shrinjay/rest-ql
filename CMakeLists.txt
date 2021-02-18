cmake_minimum_required(VERSION 3.17)
project(C_DB)

set(CMAKE_CXX_STANDARD 20)

add_executable(C_DB main.cpp modules/InputBuffer.cpp modules/InputBuffer.h modules/relp_logic.h)