project (MyProject CXX)
cmake_minimum_required (VERSION 3.0)

add_custom_command (OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Generated.cpp
                    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/Generated.cpp)
add_custom_command (OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/generated_stamp
                    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/generated_stamp
                    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/Generated.cpp
                    COMMENT "Checking Generated.cpp")

add_custom_command (OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/stamp
                    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/stamp
                    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source.cpp
                    COMMENT "Checking Source.cpp")

#set_property (SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/Source.cpp
#              APPEND PROPERTY OBJECT_DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/stamp)
#set_property (SOURCE ${CMAKE_CURRENT_BINARY_DIR}/Generated.cpp
#              APPEND PROPERTY OBJECT_DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/generated_stamp)

add_library (library SHARED ${CMAKE_CURRENT_SOURCE_DIR}/Source.cpp ${CMAKE_CURRENT_BINARY_DIR}/Generated.cpp)

set_property (TARGET library
              APPEND PROPERTY SOURCES ${CMAKE_CURRENT_BINARY_DIR}/generated_stamp ${CMAKE_CURRENT_BINARY_DIR}/stamp)
