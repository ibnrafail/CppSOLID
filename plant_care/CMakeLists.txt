cmake_minimum_required(VERSION 3.10)

project(plantcare)

SET(CMAKE_CXX_FLAGS "-std=c++20 -O3 -pedantic -Wall -Werror -g")

enable_testing()

add_subdirectory(observer)
add_subdirectory(drivers)
add_subdirectory(sensors)
add_subdirectory(caretaker)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} sensors caretaker)
