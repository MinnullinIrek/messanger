cmake_minimum_required(VERSION 3.11)

project(messanger_server CXX)
set(CMAKE_CXX_STANDART 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

conan_basic_setup()

find_package(Boost 1.78.0 REQUIRED)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})

endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

add_executable(
  messanger_server

  src/main.cpp
  src/connection_handlers.h
)

target_link_libraries(messanger_server PRIVATE Threads::Threads)
