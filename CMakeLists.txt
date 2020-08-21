cmake_minimum_required(VERSION 3.17)
project(cserver)

set(CMAKE_CXX_STANDARD 14)

add_executable(cserver main.cpp App/Kernel.cpp App/Kernel.h Deps/Request.cpp Deps/Request.h Deps/Utils.cpp Deps/Utils.h)