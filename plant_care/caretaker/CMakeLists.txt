project(caretaker)

include_directories(${PROJECT_SOURCE_DIR})

set(SOURCE
    ${PROJECT_SOURCE_DIR}/GreenHousePlantCaretaker.cpp
    ${PROJECT_SOURCE_DIR}/GardenPlantCaretaker.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE})
target_link_libraries(${PROJECT_NAME} drivers observer sensors)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
