cmake_minimum_required(VERSION 2.6)
project(LEGUI)

#Set the cmake module path
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

#Set the output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(legui_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include" PARENT_SCOPE)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/Config.cpp
    ${PROJECT_SOURCE_DIR}/src/MouseMoveListener.cpp
    ${PROJECT_SOURCE_DIR}/src/Clickable.cpp
    ${PROJECT_SOURCE_DIR}/src/Focusable.cpp
    ${PROJECT_SOURCE_DIR}/src/Hoverable.cpp
    ${PROJECT_SOURCE_DIR}/src/HorizontalSplitter.cpp
    ${PROJECT_SOURCE_DIR}/src/Container.cpp
    ${PROJECT_SOURCE_DIR}/src/Frame.cpp
    ${PROJECT_SOURCE_DIR}/src/Label.cpp
    ${PROJECT_SOURCE_DIR}/src/FontManager.cpp
    ${PROJECT_SOURCE_DIR}/src/PageManager.cpp
    ${PROJECT_SOURCE_DIR}/src/FontStyle.cpp
    ${PROJECT_SOURCE_DIR}/src/LineEdit.cpp
    ${PROJECT_SOURCE_DIR}/src/Cursor.cpp
    ${PROJECT_SOURCE_DIR}/src/Widget.cpp)

add_library(legui SHARED ${SOURCES})

find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(legui ${SFML_LIBRARIES})
endif()

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 -pedantic")

