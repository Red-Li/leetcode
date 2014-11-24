cmake_minimum_required(VERSION 2.8.9)

SET(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)
cmake_policy(SET CMP0020 NEW)

#
project (leetcode)

if(CMAKE_SIZEOF_VOID_P MATCHES 8)
    set(ARCH_STR "x64")
else()
    set(ARCH_STR "x86")
endif()

#Platform 
if(WIN32)
    set(LIBRARY_PATH_HINTS c:/libs/)
else()
    message(FATAL_ERROR "Can't support current platform")
endif()


#include modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    )

#GLOG
if(WIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN -D_CRT_SECURE_NO_WARNINGS -DUNICODE -D_UNICODE)
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(tests)

