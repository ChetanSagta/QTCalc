cmake_minimum_required(VERSION 3.16)

project(calculator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -Wall -pedantic -Wextra -Werror -Wshadow")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(${PROJECT_NAME}
    main.cpp
    MainWindow.cpp
    MainWindow.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
set_property(TARGET ${PROJECT_NAME} PROPERTY AUTOMOC ON)
