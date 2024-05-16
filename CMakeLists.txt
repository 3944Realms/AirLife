cmake_minimum_required(VERSION 3.28)
project(AirLife VERSION 0.0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/Base)
add_subdirectory(src/Core)
add_subdirectory(src/UI)
add_subdirectory(resource)

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
# 设置应用程序图标
set(ICON_FILE "E:\\AirLife\\resource\\airLifeLogo.ico")
set(RESOURCES
        resource/resource.qrc
        resource/appicon.rc
)
if(WIN32)
set(CMAKE_RC_COMPILER_INIT windres)
ENABLE_LANGUAGE(RC)
set(CMAKE_RC_COMPILE_OBJECT "<CMAKE_RC_COMPILER> <FLAGS> -o <OBJECT> <SOURCE>")
endif ()
find_package(Qt5 COMPONENTS Core Widgets LinguistTools REQUIRED)
message(STATUS "${Qt5Widgets_LIBRARIES}")
message(STATUS "${Qt5Core_LIBRARIES}")
# 添加翻译文件
set(TS_FILES Demo_en.ts Demo_fr.ts)
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

message(STATUS "QM File List: ${QM_FILES}")
# 添加执行文件
add_executable(AirLife src/main.cpp
        ${QM_FILES} ${RESOURCES}
)
# 包含 Qt 的头文件目录
target_include_directories(${PROJECT_NAME} PUBLIC ${Qt5Widgets_INCLUDE_DIRS})
# 链接 Qt 库和其他子项目
target_link_libraries(${PROJECT_NAME}
        PUBLIC
            Qt5::Core Qt5::Widgets
        PRIVATE
            Component
            CoreCode
            GUI
)
# 复制 ICO 文件到构建目录
add_custom_command(TARGET AirLife POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${ICON_FILE}"
        "${CMAKE_CURRENT_BINARY_DIR}"
)
# 定义编译器警告标志
target_compile_definitions(AirLife PRIVATE QT_DEPRECATED_WARNINGS)