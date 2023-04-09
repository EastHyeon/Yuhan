cmake_minimum_required(VERSION 3.0)

# set(CMAKE_BUILD_TYPE Debug)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(
    Dino 
    VERSION 0.1 
    DESCRIPTION "디노 프로젝트")

set (CMAKE_C_STANDARD 99)

file(GLOB SOURCES  *.c)

add_executable(${PROJECT_NAME} ${SOURCES} )