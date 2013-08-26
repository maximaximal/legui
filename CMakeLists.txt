cmake_minimum_required(VERSION 2.6)
project(legui)

set(legui_version_major 0)
set(legui_version_minor 1)
set(legui_version_build 0)

configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

#Set the cmake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_BINARY_DIR}")

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
    ${PROJECT_SOURCE_DIR}/src/PushButton.cpp
    ${PROJECT_SOURCE_DIR}/src/CenteredStrip.cpp
    ${PROJECT_SOURCE_DIR}/src/ProgressBar.cpp
    ${PROJECT_SOURCE_DIR}/src/Notification.cpp
    ${PROJECT_SOURCE_DIR}/src/NotificationData.cpp
    ${PROJECT_SOURCE_DIR}/src/NotificationQueue.cpp
    ${PROJECT_SOURCE_DIR}/src/NotificationsDisplay.cpp
    ${PROJECT_SOURCE_DIR}/src/Scrollable.cpp
    ${PROJECT_SOURCE_DIR}/src/Scrollbar.cpp
    ${PROJECT_SOURCE_DIR}/src/Widget.cpp
)
FILE(GLOB header "${CMAKE_SOURCE_DIR}/include/legui/*.h")

add_library(legui SHARED ${SOURCES})

find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(legui ${SFML_LIBRARIES})

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 -pedantic")

install(TARGETS legui DESTINATION lib)
install(FILES ${header} DESTINATION include/legui)
