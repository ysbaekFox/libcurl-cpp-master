project(libcurl-cpp-master)

cmake_minimum_required(VERSION 3.0)

add_definitions(-DCURL_STATICLIB)
set(LIB_CURL_PATH libcurl/win64)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE)

set(CURL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/${LIB_CURL_PATH}/include)
set(CURL_LIBRARY 	${CMAKE_SOURCE_DIR}/${LIB_CURL_PATH}/lib/libcurl_a.lib)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

add_executable(curl-exec "main.cpp")
target_link_libraries(curl-exec ${CURL_LIBRARY})