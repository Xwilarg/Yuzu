cmake_minimum_required(VERSION 3.1)
project(Yuzu)

find_package(SDL2 REQUIRED)

if(MSVC)
    SET(CMAKE_CXX_FLAGS "/W4 /EHsc /std:c++11")
else()
    SET(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -L.")
endif()

file(GLOB_RECURSE SRCS "src/*.cpp")
include_directories(inc ${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})