cmake_minimum_required (VERSION 3.0)
project(threadpool)

# cthreadpool library
add_library(threadpool STATIC thpool.c thpool.h)
# for usage of this folder to include the thpool.h file
target_include_directories(threadpool PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# link with the pthread library used
target_link_libraries(threadpool pthread)
# install library
set_target_properties(threadpool PROPERTIES PUBLIC_HEADER "thpool.h")
INSTALL(TARGETS threadpool
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)

