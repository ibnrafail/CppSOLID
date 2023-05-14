cmake_minimum_required(VERSION 3.22)

project(ocp)

SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -O3 -pedantic -Wall -Werror")

enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCE
    ${PROJECT_SOURCE_DIR}/ocp_dyn_polymorphism.cpp
)

add_executable(ocp_dyn_polymorphism ${SOURCE})
