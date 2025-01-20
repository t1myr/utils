cmake_minimum_required(VERSION 3.20)

project(cmake-utils VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(UTILS_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(UTILS_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(UTILS_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(UTILS_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/app)

include_directories(${UTILS_INSTALL_INCLUDE_DIR})
include_directories(${UTILS_HEADERS_DIR})

add_subdirectory(src)
add_subdirectory(test)

# cmake_minimum_required(VERSION 3.20)

# project(utils VERSION 1.0 LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# file(GLOB_RECURSE SOURCES "src/*.cpp")

# add_library(${PROJECT_NAME}_lib ${SOURCES})

# target_include_directories(${PROJECT_NAME}_lib PRIVATE include)

# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     target_compile_options(${PROJECT_NAME}_lib PRIVATE -Wall -Wextra -g)
# elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
#     target_compile_options(${PROJECT_NAME}_lib PRIVATE -O3)
# endif()

# add_executable(utils ${CMAKE_SOURCE_DIR}/src/main.cpp)

# target_link_libraries(utils PRIVATE ${PROJECT_NAME}_lib)

# target_include_directories(utils PRIVATE include)

