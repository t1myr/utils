cmake_minimum_required(VERSION 3.20)
project(utils_tests)

add_subdirectory(lib/googletest)

include_directories(${UTILS_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/utils_tests.cpp src/bitmask_test.cpp src/bitset_test.cpp)

add_executable(utils_tests ${SOURCE_FILES})
target_link_libraries(utils_tests utils_lib gtest)
install(TARGETS utils_tests DESTINATION bin)