function (my_macro)

    set (VARIANTS a b c d e f g h i j k l m b n o p)

    foreach (VAR ${VARIANTS})

    function (my_function_${VAR})
        message ("Called! ${VAR}")
    endfunction ()

    endforeach ()

endfunction (my_macro)

my_macro ()

get_property (ALL_COMMANDS GLOBAL PROPERTY COMMANDS)

foreach (COMMAND ${ALL_COMMANDS})

    message ("${COMMAND}")

endforeach ()
