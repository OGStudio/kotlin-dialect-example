cmake_minimum_required(VERSION 3.16)
project(helloworld)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
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
qt_add_qml_module(
    hwL64
    URI helloworld
    VERSION 1.0
    RESOURCE_PREFIX # Replace the default "/qt/qml" prefix with "/" when loading QML
    NO_RESOURCE_TARGET_PATH # Strip "src/other/view" path when loading QML
    QML_FILES
    src/main/view/MainView.qml
    src/other/view/AppView.qml
)

# SDK
add_library(hw SHARED IMPORTED)
set_target_properties(hw PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../sdk-linux-x64/hw/build/bin/native/releaseShared/libhw.so)
target_include_directories(
    hwL64
    PRIVATE
    ${CMAKE_SOURCE_DIR}/../sdk-linux-x64/hw/build/bin/native/releaseShared
    src
    src/main
    src/other
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
set_target_properties(
    hwL64
    PROPERTIES
    INSTALL_RPATH "$ORIGIN/../../../sdk-linux-x64/hw/build/bin/native/releaseShared"
)
