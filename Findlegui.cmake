#This cmake module finds the legui library, if it is on a known install path.

find_library(legui_LIBRARY NAMES legui)

set(legui_INCLUDE_DIR "/usr/local/include")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(legui DEFAULT_MSG legui_LIBRARY legui_INCLUDE_DIR)

if(legui_FOUND)
 set(legui_LIBRARIES ${JPEG_LIBRARY})
endif(legui_FOUND)
