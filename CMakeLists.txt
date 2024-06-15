cmake_minimum_required(VERSION 3.27.4)
project(moving-semantics)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(Move\ semantics/CMakeLists.txt)
include(Brace\ initialization/CMakeLists.txt)
include(Auto\ keyword/CMakeLists.txt)
include(Lambda\ expressions/CMakeLists.txt)
include(Smart\ pointers/CMakeLists.txt)

