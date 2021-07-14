cmake_minimum_required (VERSION 3.8)
 
project(Main)
 
set(SOURCE_FILES 
    "src/main.cpp"
)

set(HEADER_FILES
    
)

include_directories(src)

add_executable (Main ${HEADER_FILES} ${SOURCE_FILES})
#include_directories()
target_link_libraries(Main Discord)