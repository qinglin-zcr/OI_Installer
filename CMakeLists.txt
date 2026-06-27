cmake_minimum_required(VERSION 3.20)

project(OI_Installer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

add_executable(OI_Installer
    main.cpp
    src/installer.cpp
    src/logger.cpp
    src/config.cpp
    src/filesystem.cpp
)