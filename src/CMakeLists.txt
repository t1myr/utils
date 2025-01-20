cmake_minimum_required(VERSION 3.20)

project(utils_app VERSION 1.0 LANGUAGES CXX)

add_subdirectory(app)
set(SOURCE_FILES main.cpp)

add_executable(utils_app ${SOURCE_FILES})
target_link_libraries(utils_app utils_lib)
install(TARGETS utils_app DESTINATION ${UTILS_INSTALL_BIN_DIR})
