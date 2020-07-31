cmake_minimum_required(VERSION 3.13)

add_library(CLMat src/CLMat/CLMat.cpp)
target_include_directories(CLMat PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(CLMat System)
target_link_libraries(CLMat -lOpenCL)
target_link_libraries(CLMat -lclblast)
