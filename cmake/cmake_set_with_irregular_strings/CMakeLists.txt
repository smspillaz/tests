set (IRREGULAR_STRING_VARIABLE "irregular string")

option (SET_CACHE_VAR OFF "Set cache var")

if (SET_CACHE_VAR)
set ("${IRREGULAR_STRING_VARIABLE}" "value"  CACHE INTERNAL "" FORCE)
endif (SET_CACHE_VAR)

message ("${${IRREGULAR_STRING_VARIABLE}}")
