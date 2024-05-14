cmake_minimum_required(VERSION 3.28)
project(AirLife VERSION 0.0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/Base)
add_subdirectory(src/Core)
add_subdirectory(src/UI)

#定义变量 #set()
#boo <==> "boo"
#普通变量 ${NAME}
#环境变量
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

add_executable(AirLife src/main.cpp
        ${QM_FILES}

)
target_include_directories(${PROJECT_NAME} PUBLIC ${Qt5Widgets_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}
        PUBLIC
            Qt5::Core Qt5::Widgets
        PRIVATE
            Component
            CoreCode
            GUI
)
