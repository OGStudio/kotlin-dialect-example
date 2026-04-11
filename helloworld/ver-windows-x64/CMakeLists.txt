cmake_minimum_required(VERSION 3.16)
project(helloworld)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(Qt6 REQUIRED COMPONENTS Quick)
qt_standard_project_setup(REQUIRES 6.8)

# Приложение
set(
    SOURCES
    src/ignore.App.cpp
    src/ignore.main.cpp
    src/ignore.kd.cpp
    src/ignore.VM.cpp
)
qt_wrap_cpp(
    SOURCES
    src/ignore.kd.h
    src/ignore.VM.h
)
qt_add_executable(hwW64 ${SOURCES})
qt_add_qml_module(
  hwW64
  URI helloworld
  QML_FILES src/ignore.AppView.qml
)

# SDK
add_library(hw SHARED IMPORTED)
set_target_properties(hw PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../sdk-windows-x64/hw/build/bin/native/releaseShared/libhw.dll)
target_include_directories(hwW64 PRIVATE ${CMAKE_SOURCE_DIR}/../sdk-window-x64/hw/build/bin/native/releaseShared)

# Линкуем
target_link_libraries(hwW64 PRIVATE Qt6::Quick hw)
