# Kotlin Dialect examples

This repository contains example project to showcase how Kotlin Dialect
application looks like

## Hello world

`helloworld` example depicts how to alter text on button click

`helloworld` structure:

```
helloworld/
├── kd.yml                          Design: context fields + output paths
│
├── components/                     Hand-written source (single source of truth)
│   ├── main/                       Core domain logic
│   │   ├── android/  (main.kt, MainView.kt)
│   │   ├── desktop/  (main.cpp/h, MainView.qml)
│   │   └── sdk/      (mainProto.kt, mainShould.kt)
│   └── other/                      App scaffolding (VM, entry point)
│       ├── android/  (MainActivity.kt, VM.kt)
│       ├── desktop/  (App.cpp, VM.cpp/h, KT.h, AppView.qml)
│       └── sdk/      (other.kt)
│
├── sdk-{linux,mac,windows}-x64/    Kotlin/Native Gradle projects
│   └── hw/src/nativeMain/...       Generated ignore.kd.kt + symlinks → components/*/sdk/
│                                    Builds → libhw.{so,dylib,dll}
│
├── ver-{linux,mac,windows}-x64/    Desktop verification/build projects
│   ├── CMakeLists.txt              Qt6 CMake build
│   └── src/                        Symlinks → components/*/desktop/
│                                    + generated ignore.kd.{cpp,h}
│
├── ver-android/                    Android Gradle project
│   └── app/src/main/               Symlinks → components/*/{android,sdk}/
│                                    + generated ignore.kd.kt + Compose UI
│
└── util/                           Build/launch scripts
    ├── step/
    │   ├── cloneKD    → git clone kotlin-dialect tool
    │   ├── genKD      → node dist/app.js --file=kd.yml
    │   ├── buildDesktopSDK → gradle linkReleaseSharedNative
    │   └── buildDesktop→ cmake .. && cmake --build .
    ├── build-{linux,mac,windows,android}
    └── launch-{linux,mac,windows}
```

### Android

https://github.com/user-attachments/assets/e85859bd-7da8-46c3-9726-51f4e220ee4e

Prerequisites:

* Android Studio

Instructions:

| № | Step | Example |
|---|---   |---      |
| 1 | Open a terminal | |
| 2 | Go to `helloworld` directory | `cd helloworld` |
| 3 | Generate files out of `kd.yml` | `./util/build-android` |
| 4 | Launch Android Studio | |
| 5 | Open `helloworld/ver-android` project | |
| 6 | Press Run | |

### Linux

https://github.com/user-attachments/assets/80bb1702-7aaa-499e-9149-582646c5c16c

Prerequisites:

| № | Prerequisite | Details |
| --- | --- | --- |
| 1 | Lubuntu 26.04 | Qt 6.5+ is required |
| 2 | GCC | `sudo apt install build-essential` |
| 3 | Qt6 | `sudo apt install qtcreator` |
| 4 | CMake | `sudo apt install cmake` |
| 5 | Node.js | `sudo apt install nodejs` |
| 6 | OpenJDK | `sudo apt install openjdk-21-jdk` |

### macOS

https://github.com/user-attachments/assets/4b940da3-4c5c-4e2f-a057-7d8e925489ca

Prerequisites:

* cmake
* Qt6
* Xcode

Instructions (Intel):

| № | Step | Example |
|---|---   |---      |
| 1 | Open a terminal | |
| 2 | Go to `helloworld` directory | `cd helloworld` |
| 3 | Build the application | `./util/build-mac-x64` |
| 4 | Launch the application | `./util/launch-mac-x64`|

### Windows

https://github.com/user-attachments/assets/54437654-c9db-42f7-b4ee-e8499db09120

Prerequisites:

| № | Prerequisite | Details |
| --- | --- | --- |
| 1 | Windows 11 | Configure **symlinks**: <br>1. Add to `~/.bash_profile`: `export MSYS="winsymlinks:nativestrict"` <br>2. Clone Kotlin dialect example repository with **symlink** support: `git clone -c core.symlinks=true github.com/OGStudio/kotlin-dialect-example` |
| 2 | [MSYS2](https://www.msys2.org) | Use UCRT64 shell |
| 3 | [Qt6](https://wiki.qt.io/MSYS2) | `pacman -S mingw-w64-ucrt-x86_64-qt-creator` |
| 4 | cmake | `pacman -S mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja` |
| 5 | Node.js | `pacman -S mingw-w64-ucrt-x86_64-nodejs` |
| 6 | dlltool | `pacman -S mingw-w64-ucrt-x86_64-toolchain` |
| 7 | [OpenJDK](https://jdk.java.net/archive) | Install and unpack 21.0.2 version to `C:`, then add to `~/.bash_profile`: `export PATH="$PATH:/c/jdk-21.0.2"` |

Instructions:

| № | Step | Example |
|---|---   |---      |
| 1 | **As admin** open MSYS2 UCRT terminal | 1. Make sure you launched the terminal **as admin** otherwise symlinks won't work <br> 2. Make sure you cloned the repository with `-c core.symlinks=true` otherwise symlinks won't work|
| 2 | Go to `helloworld` directory | `cd helloworld` |
| 3 | Build the application | `./util/build-windows-x64` |
| 4 | Launch the application | `./util/launch-windows-x64`|
