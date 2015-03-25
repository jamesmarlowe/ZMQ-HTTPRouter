cmake_minimum_required(VERSION 2.8)
project(httprouter)

add_definitions("-Wno-deprecated-declarations")

set(CMAKE_MODULE_PATH $ {CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

#enable c++ 11
SET(CMAKE_CXX_FLAGS "-std=c++11 -g -O3 ${CMAKE_CXX_FLAGS}")

#Protocol buffers
find_package(Protobuf REQUIRED)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})

set(httprouter_sources
    httprouter.cpp
    log.cpp
)

add_executable(httprouter ${httprouter_sources})

target_link_libraries(httprouter hiredis)
