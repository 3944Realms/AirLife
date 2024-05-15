cmake_minimum_required(VERSION 3.28)
add_subdirectory(dialogs)
add_subdirectory(easterEgg)
add_subdirectory(mainWindows)
add_subdirectory(widgets)
add_subdirectory(test)
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
add_library(GUI
        dialogs/logindialog.cpp
        test/testwindows.cpp
        easterEgg/hui.cpp
        dialogs/airlifeerrordialog.cpp
        dialogs/airlifeerrordialog.h
        dialogs/airlifeerrordialog.ui
        dialogs/airlifeinfodialog.cpp
        dialogs/airlifeinfodialog.h
        dialogs/airlifeinfodialog.ui
        mainWindows/customermainwindow.cpp
        mainWindows/customermainwindow.h
        mainWindows/customermainwindow.ui
        mainWindows/administermainwindow.cpp
        mainWindows/administermainwindow.h
        mainWindows/administermainwindow.ui
        widgets/ordercreatorwidget.cpp
        widgets/ordercreatorwidget.h
        widgets/ordercreatorwidget.ui
        widgets/orderdestroyerwidget.cpp
        widgets/orderdestroyerwidget.h
        widgets/orderdestroyerwidget.ui
        widgets/informationfinderwidget.cpp
        widgets/informationfinderwidget.h
        widgets/informationfinderwidget.ui
        widgets/informationloggerwidget.cpp
        widgets/informationloggerwidget.h
        widgets/informationloggerwidget.ui
        widgets/informationmodifierwidget.cpp
        widgets/informationmodifierwidget.h
        widgets/informationmodifierwidget.ui
        dialogs/airliferunningdialog.cpp
        dialogs/airliferunningdialog.h
        dialogs/airliferunningdialog.ui
)
target_include_directories(GUI PUBLIC ${Qt5Widgets_INCLUDE_DIRS})
target_link_libraries(GUI
        PUBLIC
        Qt5::Core Qt5::Widgets
)