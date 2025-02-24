cmake_minimum_required(VERSION 3.25)
PROJECT(FBS_PB_JSON)
set(CMAKE_CXX_STANDARD 17)
SET(SRC_LIST serializationTest.cpp)
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/fbsgenerate/flatbuffers-2.0.0/include")

ADD_EXECUTABLE(xzh ${SRC_LIST})