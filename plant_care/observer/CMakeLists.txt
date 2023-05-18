project(observer)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${Boost_INCLUDE_DIRS})

set(SOURCE
    ${PROJECT_SOURCE_DIR}/IObserver.hpp
    ${PROJECT_SOURCE_DIR}/IPublisher.hpp
    ${PROJECT_SOURCE_DIR}/Publisher.hpp
    ${PROJECT_SOURCE_DIR}/Publisher.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
