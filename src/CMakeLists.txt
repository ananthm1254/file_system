# (1) Build a library with my application sources
set(APP_LIB_SOURCE
    file_utils.c
    cmd_handler.c
)

include_directories(inc)

set(CMAKE_BUILD_TYPE Debug)

add_library(${APP_LIB_NAME} ${APP_LIB_SOURCE})

# (2) Add main(..) to the application library to have something we can run