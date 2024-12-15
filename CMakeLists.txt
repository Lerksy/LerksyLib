cmake_minimum_required(VERSION 3.29)
project(LerksyLib)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC
    src/Buffer.cpp src/Buffer.h include/Buffer
    src/Color.h include/Color
    src/NumberUtils.h
    src/ColorT.h include/ColorT
    )

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_subdirectory(ThirdParty)
add_subdirectory(Tests)

