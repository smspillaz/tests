file (DOWNLOAD "http://smspillaz.wordpress.com"
      "${CMAKE_CURRENT_BINARY_DIR}/File")
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_BINARY_DIR}/DownloadedModules")
include (ModMan)
