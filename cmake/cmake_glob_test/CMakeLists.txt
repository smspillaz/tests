project (GlobTest)
cmake_minimum_required (VERSION 2.8)

file (GLOB RESULT /Users/smspillaz/Source/*.cpp)

message ("GLOB RESULT: ${RESULT}")