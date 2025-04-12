# Tetris

https://github.com/user-attachments/assets/66d78994-20d0-4c67-9a72-868b454460f6

This project is a custom implementation of the iconic Tetris puzzle game, developed in C++ with raylib for graphics and input handling. The project uses CMake for an organized and portable build system.

Features include:

- Classic Tetris mechanics: tetromino generation, rotation, collision detection, line clearing
- Grid-based logic with clean object-oriented structure in C++
- Real-time input response and rendering via raylib
- Score tracking and increasing difficulty
- Cross-platform compatibility using CMake

This project is a solid entry point for understanding game loops, 2D grid logic, and real-time rendering using a lightweight and modern C++ framework.

## Pre-requisites

### CMake

Before building the project you need to have CMake installed in your machine. You can use `brew install cmake` command or you can go to https://cmake.org/download/ and download the latest version for your machine OS. We recommend installing via first option but if you go with the second option after running the installer open the CMake app, go to Tools/How To Install For Command Line Use, and follow the instructions to finish installation.

To build the application on Windows you will need Visual Studio with Clang support. On the Visual Studio Installer app, make sure you install the following:

* Workloads
    * Desktop development with C++
* Individual components
    * C++ Clang Compiler for Windows
    * C++ Clang-cl for v143 build tools (x64/x86)

### Clang-format

macOS
```
brew install clang-format
```

Windows

You can get it as part of the LLVM compiler or Clang Compiler build for Windows. You also can try to install it with npm
```
npm install -g clang-format
```

## How to build project and open IDE? (recommended)

macOS
```
sh Scripts/macOS/build_xcode.sh
```

Windows
```
start Scripts/windows/build_vs22.bat
```

## How to format code?

macOS
```
sh Scripts/macOS/formatter.sh
```

Windows
```
start Scripts/windows/formatter.bat
```
