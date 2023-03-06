project(drivers)

include_directories(${PROJECT_SOURCE_DIR})

set(SOURCE
    ${PROJECT_SOURCE_DIR}/WaterDriver.cpp
    ${PROJECT_SOURCE_DIR}/WindowDriver.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
