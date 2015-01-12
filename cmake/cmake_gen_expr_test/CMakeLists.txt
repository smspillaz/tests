cmake_minimum_required(VERSION 3.0)
cmake_policy (VERSION 3.0)

set (CMAKE_MODULE_PATH 
     ${CMAKE_MODULE_PATH}
     ${CMAKE_CURRENT_LIST_DIR}/cmake-imported-project-utils)

include (ImportedProjectUtils)

polysquare_import_external_project (OtherLibrary library-exports
                                    OPTIONS
                                    URL ${CMAKE_CURRENT_SOURCE_DIR}/extproj
                                    TARGETS
                                    OTHER_LIBRARY otherlibrary
                                    SPECIAL_LIBRARY speciallibrary
                                    INCLUDE_DIRS
                                    LIBRARY_INCLUDE include
                                    GENERATE_EXPORTS)

include_directories (${LIBRARY_INCLUDE})
add_executable (executable executable.c)
target_link_libraries (executable ${OTHER_LIBRARY} ${SPECIAL_LIBRARY})
