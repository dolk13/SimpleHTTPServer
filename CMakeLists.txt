cmake_minimum_required(VERSION 2.8)
project(SimpleHTTPServer)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.54.0 COMPONENTS system filesystem regex REQUIRED) 

if( Boost_FOUND )
	message( STATUS "Boost found!" )
endif()

include_directories(${Boost_INCLUDE_DIRS}) 

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(final ${SOURCE_FILES})
target_link_libraries(final ${Boost_LIBRARIES})
