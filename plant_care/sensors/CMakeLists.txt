project(sensors)

include_directories(${PROJECT_SOURCE_DIR})

set(SOURCE
    ${PROJECT_SOURCE_DIR}/HumiditySensor.cpp
    ${PROJECT_SOURCE_DIR}/LightSensor.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} observer)