if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
  message(FATAL_ERROR "Prevented in-tree build. Please create a build directory outside of the SDL source code and run \"cmake -S ${CMAKE_SOURCE_DIR} -B .\" from there")
endif()

cmake_minimum_required(VERSION 3.1)
project(Yuzu)

find_package(SDL2 REQUIRED)

if(MSVC)
    SET(CMAKE_CXX_FLAGS "/W4 /EHsc /std:c++11")
else()
    SET(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -L.")
endif()

file(GLOB_RECURSE SRCS "src/*.cpp")
file(GLOB_RECURSE HEADERS "inc/*.hpp" ${SDL2_INCLUDE_DIRS}/*.h)
include_directories(inc inc/render ${SDL2_INCLUDE_DIRS})

add_compile_definitions(RENDER_SDL2)

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})