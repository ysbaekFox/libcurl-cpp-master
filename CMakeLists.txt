project(libcurl-cpp-master)

cmake_minimum_required(VERSION 3.0)

add_definitions(-DCURL_STATICLIB)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE)
set(CURL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libcurl/include)

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
add_definitions(-DVC16)
set(CURL_LIBRARY ${CMAKE_SOURCE_DIR}/libcurl/lib/win64/libcurl_a.lib)

elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
add_definitions(-DLINUX)

find_package(ZLIB)
find_package(Threads REQUIRED)

set(CURL_LIBRARY ${CMAKE_SOURCE_DIR}/libcurl/lib/linux-x86_64/libcurl.a
	            ${CMAKE_SOURCE_DIR}/libcurl/lib/linux-x86_64/libssl.a
	            ${CMAKE_SOURCE_DIR}/libcurl/lib/linux-x86_64/libcrypto.a
	            Threads::Threads 
	            ZLIB::ZLIB
	            ${CMAKE_DL_LIBS}
)

elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
elseif(CMAKE_SYSTEM_NAME MATCHES "Android")
endif()

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

add_executable(curl-exec "main.cpp")
target_link_libraries(curl-exec ${CURL_LIBRARY})