cmake_minimum_required(VERSION 3.22)

project(ocp)

SET(CMAKE_CXX_FLAGS "-std=c++20 -O3 -pedantic -Wall -Werror")


include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(ocp_dyn_polymorphism ${PROJECT_SOURCE_DIR}/ocp_dyn_polymorphism.cpp)
add_executable(ocp_template ${PROJECT_SOURCE_DIR}/ocp_template.cpp)
add_executable(ocp_concepts ${PROJECT_SOURCE_DIR}/ocp_concepts.cpp)
