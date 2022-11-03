cmake_minimum_required (VERSION 3.0)
project(file-read)

# cthreadpool library
add_library(file STATIC file.c file.h)
# for usage of this folder to include the thpool.h file
target_include_directories(file PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# install library
set_target_properties(file PROPERTIES PUBLIC_HEADER "file.h")
INSTALL(TARGETS file
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)

