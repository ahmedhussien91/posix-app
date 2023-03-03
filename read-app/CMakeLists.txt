cmake_minimum_required (VERSION 3.0)
project(posix-readapp)

add_executable(readapp app.c)
target_link_libraries(readapp threadpool file -static)
