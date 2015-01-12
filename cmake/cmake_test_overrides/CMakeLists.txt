set (CMAKE_MODULE_PATH
     ${CMAKE_CURRENT_LIST_DIR})

include (Override)

add_custom_command (OUTPUT generated.c
                    COMMAND cmake -E touch generated.c)
add_custom_target (target ALL
                   SOURCES generated.c)
