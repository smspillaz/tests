project (InvokeFunctionMacro)

function (_my_function ARGUMENT)

    message ("Called with ${ARGUMENT}")

endfunction ()

macro (_invoke_function FUNCTION_NAME ARGUMENT)

    ${FUNCTION_NAME} (${ARGUMENT})

endmacro ()

invoke_function (_my_function ${ARGUMENT})
