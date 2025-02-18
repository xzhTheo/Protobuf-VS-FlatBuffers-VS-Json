cmake_minimum_required(VERSION 3.25)
PROJECT(FBS_PB_JSON)
set(CMAKE_CXX_STANDARD 17)
SET(SRC_LIST serializationTest.cpp fbsParser.cpp)
include_directories ("/Users/theo.xu/study/serialization_compare/fbsgenerate/flatbuffers-2.0.0/include") 


ADD_EXECUTABLE(xzh ${SRC_LIST})