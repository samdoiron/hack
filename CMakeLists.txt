cmake_minimum_required (VERSION 2.6)

project (HACK)


set (CMAKE_CXX_FLAGS_DISTRIBUTION -Weverything -Werror -Wno-pad -std=c++11 -Wno-c++98-compat)

set (HACK_VERSION_MAJOR 0)
set (HACK_VERSION_MINOR 1)

add_executable(hack 
  ainstruction.cc
  dinstruction.cc
  hack.cc
  instruction.cc
  invalidsyntaxexception.cc
  label.cc
  program.cc
)

