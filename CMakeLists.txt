cmake_minimum_required (VERSION 2.6)

project (HACK)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything -Wno-weak-vtables -std=c++11 -Wno-c++98-compat -Wno-c++11-extensions -Wno-padded -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-documentation-unknown-command -Wno-undef -Wno-documentation -Wno-extra-semi -Wno-old-style-cast -Wno-switch-enum -Wno-disabled-macro-expansion")

set (HACK_VERSION_MAJOR 0)
set (HACK_VERSION_MINOR 1)

set (Boost_USE_STATIC_LIBS ON)
set (Boost_INCLUDE_DIR lib/boost)
set (BOOST lib/boost/boost)

find_package(Boost 1.5.7 REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(hack 
  ainstruction.cc
  dinstruction.cc
  hack.cc
  instruction.cc
  invalidsyntaxexception.cc
  label.cc
  program.cc
  programline.cc
)

target_link_libraries(hack ${Boost_LIBRARIES})

