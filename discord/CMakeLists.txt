cmake_minimum_required (VERSION 3.8)
 
project(Discord)
 
set(SOURCE_FILES
    "src/connection_win.cpp"
    "src/rpc_connection.cpp"
    "src/serialization.cpp"
)

set(HEADER_FILES
    "src/connection.h"
    "src/rpc_connection.h"
    "src/serialization.h"
)

add_library(Discord STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(Discord PUBLIC
    src
    lib/rapidjson-1.1.0/include
)

#include_directories(lib/rapidjson-1.1.0/include)
#target_link_libraries(Discord lib/rapidjson-1.1.0/include)