cmake_minimum_required(VERSION 3.25)
PROJECT(FBS_PB_JSON)
set(CMAKE_CXX_STANDARD 11)
SET(SRC_LIST serializationTest.cpp)
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/fbsgenerate/flatbuffers-2.0.0/include")
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/pbgenerate/protobuf/include")

# set(CMAKE_PREFIX_PATH "/Users/theo.xu/study/serialization_compare/pbgenerate/protobuf" ${CMAKE_PREFIX_PATH})
set(Protobuf_PREFIX_PATH
    "/${CMAKE_CURRENT_SOURCE_DIR}/pbgenerate/protobuf/include"
    "/${CMAKE_CURRENT_SOURCE_DIR}/pbgenerate/protobuf/lib"
    "/${CMAKE_CURRENT_SOURCE_DIR}/pbgenerate/protobuf/bin"
)
list(APPEND CMAKE_PREFIX_PATH "${Protobuf_PREFIX_PATH}")
message(STATUS "=== CMAKE_PREFIX_PATH is: ${CMAKE_PREFIX_PATH}")
set(protobuf_MODULE_COMPATIBLE ON CACHE BOOL "")
find_package(Protobuf REQUIRED)
message(STATUS "=== Protobuf_PROTOC_EXECUTABLE: ${Protobuf_PROTOC_EXECUTABLE}")
message(STATUS "=== Protobuf_INCLUDE_DIR is: ${Protobuf_INCLUDE_DIR}")
message(STATUS "=== Protobuf_INCLUDE_DIRS is: ${Protobuf_INCLUDE_DIRS}")
# 检查是否成功找到 Protobuf
if(Protobuf_FOUND)
    message(STATUS "Found Protobuf: ${Protobuf_LIBRARIES}")
    # 包含 Protobuf 的头文件目录
    message(STATUS "Protobuf_INCLUDE_DIRS: ${Protobuf_INCLUDE_DIRS} ${PROTO_SRCS} ${PROTO_HDRS}")
    include_directories(${Protobuf_INCLUDE_DIRS})
    include_directories(${CMAKE_CURRENT_BINARY_DIR})
    # protobuf_generate_cpp(Person_PROTO_SRCS Person_PROTO_HDRS pbgenerate/protoSchema.proto)
    # message(STATUS "PROTOC Generate: ${Person_PROTO_SRCS} ${Person_PROTO_HDRS} ")
else()
    message(FATAL_ERROR "Could not find Protobuf")
endif()

ADD_EXECUTABLE(xzh ${SRC_LIST} ${CMAKE_CURRENT_SOURCE_DIR}/pbgenerate/protoSchema.pb.cc ) 

# ADD_EXECUTABLE(xzh ${SRC_LIST} ${Person_PROTO_SRCS} ${Person_PROTO_HDRS})
target_link_libraries(xzh ${Protobuf_LIBRARIES})
