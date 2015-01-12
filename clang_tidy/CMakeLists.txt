project (TestClangTidy)
cmake_minimum_required (VERSION 3.0)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -stdlib=libc++")
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable (clang_tidy_test
                tidy.cpp)
