cmake_minimum_required (VERSION 3.8)
project (CustemWindowOverlay)

add_subdirectory(discord)
add_subdirectory(main)
set_property (DIRECTORY PROPERTY VS_STARTUP_PROJECT "Main")