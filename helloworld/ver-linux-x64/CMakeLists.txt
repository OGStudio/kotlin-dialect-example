cmake_minimum_required(VERSION 3.16)
project(helloworld)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(
    Qt6
    REQUIRED
    COMPONENTS
    Quick
    QuickControls2
    Widgets
)

#qt_standard_project_setup(REQUIRES 6.0)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
include(GNUInstallDirs)

# Приложение
set(
    SOURCES
    src/ignore.kd.cpp
    src/main/main.cpp
    src/other/App.cpp
    src/other/VM.cpp
)
qt_wrap_cpp(
    SOURCES
    src/ignore.kd.h
    src/other/VM.h
)
qt_add_executable(hwL64 ${SOURCES})
set_source_files_properties(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/other/view/AppView.qml"
    PROPERTIES
    QT_RESOURCE_ALIAS "helloworld/AppView.qml"
)
set_source_files_properties(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main/view/MainView.qml"
    PROPERTIES
    QT_RESOURCE_ALIAS "helloworld/MainView.qml"
)
qt6_add_resources(hwL64 "app_qml"
    PREFIX "/"
    FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/other/view/AppView.qml"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/main/view/MainView.qml"
)

# SDK
target_include_directories(
    hwL64
    PRIVATE
    ${CMAKE_SOURCE_DIR}/../sdk-linux-x64/hw/build/bin/native/releaseShared
    src
    src/main
    src/other
)
target_link_directories(
    hwL64
    PRIVATE
    ${CMAKE_SOURCE_DIR}/../sdk-linux-x64/hw/build/bin/native/releaseShared
)

# Link
target_link_libraries(
    hwL64
    PRIVATE
    hw
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Widgets
)
