cmake_minimum_required(VERSION 3.0)

project(myhttpd)

set(CMAKE_CXX_FLAGS "-std=c++17 -pedantic -Wall -Wextra -Werror"
  )

set(SRCS
  src/httpd.cc
  src/server.cc
  )

set(HEADERS
  src/server.hh
  )

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${myhttpd_SOURCE_DIR})
add_executable(myhttpd ${SRCS} ${HEADERS})
