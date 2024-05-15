cmake_minimum_required(VERSION 3.28)
set(CMAKE_PREFIX_PATH "D:\\Qt5.14.2\\5.14.2\\mingw73_64;${CMAKE_PREFIX_PATH}")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()
set(CMAKE_INCLUDE)


find_package(Qt5 COMPONENTS Core Widgets LinguistTools REQUIRED)
message(STATUS "${Qt5Widgets_LIBRARIES}")
message(STATUS "${Qt5Core_LIBRARIES}")

set(TS_FILES Demo_en.ts Demo_fr.ts)
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
message(STATUS "QM File List: ${QM_FILES}")
add_library(CoreCode
        LoginHandler.cpp
        GuiHandler.cpp
        GuiHandler.h
        ReadFileHandler.cpp
        ReadFileHandler.h
        WriteFileHandler.cpp
        WriteFileHandler.h
)
target_include_directories(CoreCode PUBLIC ${Qt5Widgets_INCLUDE_DIRS})

target_link_libraries(CoreCode
        PUBLIC
        Qt5::Core Qt5::Widgets
)