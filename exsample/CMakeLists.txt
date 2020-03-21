cmake_minimum_required(VERSION 2.8)

project(cereal)
IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
ENDIF()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories( /usr/local/include )
add_executable(serialize_xml serialize_xml.cpp)
add_executable(serialize_json serialize_json.cpp)
add_executable(serialize_json_demo demo.cpp)
