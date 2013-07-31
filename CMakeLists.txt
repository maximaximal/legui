cmake_minimum_required(VERSION 2.6)
project(LEGUI)

#Set the cmake module path
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/Config.cpp
    ${PROJECT_SOURCE_DIR}/src/Widget.cpp)

add_library(legui SHARED ${SOURCES})
