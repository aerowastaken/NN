cmake_minimum_required(VERSION 3.13)

add_library(System src/System/System.cpp src/System/Platform.cpp src/System/Device.cpp src/System/Utils.cpp)
target_include_directories(System PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(System PUBLIC -lOpenCL)
