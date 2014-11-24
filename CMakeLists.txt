cmake_minimum_required (VERSION 2.6)

project (HACK)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wno-exit-time-destructors -Weverything -Wno-weak-vtables -std=c++11 -Wno-c++98-compat -Wno-c++11-extensions -Wno-padded -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-documentation-unknown-command -Wno-undef -Wno-documentation -Wno-extra-semi -Wno-old-style-cast -Wno-switch-enum -Wno-disabled-macro-expansion -g")

set (HACK_VERSION_MAJOR 0)
set (HACK_VERSION_MINOR 1)

add_executable(hack 
  ainstruction.cc
  cinstruction.cc
  hack.cc
  instruction.cc
  invalidsyntaxexception.cc
  variable.cc
  program.cc
)

set (Boost_STATIC_LIBRARIES ON)

find_package(Boost 1.5.7 COMPONENTS regex log REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
add_definitions(-DBOOST_LOG_DYN_LINK)

target_link_libraries(hack ${Boost_LIBRARIES})

