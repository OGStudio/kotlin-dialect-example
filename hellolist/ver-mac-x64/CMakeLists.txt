cmake_minimum_required(VERSION 3.16)
project(hellolist)
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
qt_standard_project_setup(REQUIRES 6.5)

# Application
set(
    SOURCES
    src/ignore.kd.cpp
    src/root/root.cpp
    src/root/rootEffect.cpp
    src/other/App.cpp
    src/other/KT.cpp
    src/other/VM.cpp
)
qt_wrap_cpp(
    SOURCES
    src/ignore.kd.h
    src/other/VM.h
)
qt_add_executable(hlM64 ${SOURCES})
qt_add_qml_module(
    hlM64
    URI hellolist
    QML_FILES
    src/root/view/RootView.qml
    src/other/view/AppView.qml
)

# SDK
add_library(hl SHARED IMPORTED)
set_target_properties(hl PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../sdk-mac-x64/hl/build/bin/native/releaseShared/libhl.dylib)
target_include_directories(
    hlM64
    PRIVATE
    ${CMAKE_SOURCE_DIR}/../sdk-mac-x64/hl/build/bin/native/releaseShared
    src
    src/root
    src/other
)

# Link
target_link_libraries(
    hlM64
    PRIVATE
    hl
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Widgets
)
