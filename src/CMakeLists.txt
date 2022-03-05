# (1) Build a library with my application sources
set(APP_LIB_SOURCE
    file_utils.c
    cmd_handler.c
    file_io/file_erase.c
    file_io/file_write.c
    file_io/file_read.c
)

include_directories(inc)
include_directories("file_io/inc")

set(CMAKE_BUILD_TYPE Debug)

add_library(${APP_LIB_NAME} ${APP_LIB_SOURCE})

# (2) Add main(..) to the application library to have something we can run