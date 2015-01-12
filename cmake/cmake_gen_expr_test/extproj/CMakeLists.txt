add_library (otherlibrary SHARED library.c)
add_library (speciallibrary SHARED speciallibrary.c)
#export (TARGETS speciallibrary otherlibrary FILE library-exports.cmake)
