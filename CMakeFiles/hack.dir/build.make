# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.0.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.0.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/samdoiron/Code/C++/HACK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/samdoiron/Code/C++/HACK

# Include any dependencies generated for this target.
include CMakeFiles/hack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hack.dir/flags.make

CMakeFiles/hack.dir/ainstruction.cc.o: CMakeFiles/hack.dir/flags.make
CMakeFiles/hack.dir/ainstruction.cc.o: ainstruction.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/samdoiron/Code/C++/HACK/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hack.dir/ainstruction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hack.dir/ainstruction.cc.o -c /Users/samdoiron/Code/C++/HACK/ainstruction.cc

CMakeFiles/hack.dir/ainstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hack.dir/ainstruction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/samdoiron/Code/C++/HACK/ainstruction.cc > CMakeFiles/hack.dir/ainstruction.cc.i

CMakeFiles/hack.dir/ainstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hack.dir/ainstruction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/samdoiron/Code/C++/HACK/ainstruction.cc -o CMakeFiles/hack.dir/ainstruction.cc.s

CMakeFiles/hack.dir/ainstruction.cc.o.requires:
.PHONY : CMakeFiles/hack.dir/ainstruction.cc.o.requires

CMakeFiles/hack.dir/ainstruction.cc.o.provides: CMakeFiles/hack.dir/ainstruction.cc.o.requires
	$(MAKE) -f CMakeFiles/hack.dir/build.make CMakeFiles/hack.dir/ainstruction.cc.o.provides.build
.PHONY : CMakeFiles/hack.dir/ainstruction.cc.o.provides

CMakeFiles/hack.dir/ainstruction.cc.o.provides.build: CMakeFiles/hack.dir/ainstruction.cc.o

CMakeFiles/hack.dir/dinstruction.cc.o: CMakeFiles/hack.dir/flags.make
CMakeFiles/hack.dir/dinstruction.cc.o: dinstruction.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/samdoiron/Code/C++/HACK/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hack.dir/dinstruction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hack.dir/dinstruction.cc.o -c /Users/samdoiron/Code/C++/HACK/dinstruction.cc

CMakeFiles/hack.dir/dinstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hack.dir/dinstruction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/samdoiron/Code/C++/HACK/dinstruction.cc > CMakeFiles/hack.dir/dinstruction.cc.i

CMakeFiles/hack.dir/dinstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hack.dir/dinstruction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/samdoiron/Code/C++/HACK/dinstruction.cc -o CMakeFiles/hack.dir/dinstruction.cc.s

CMakeFiles/hack.dir/dinstruction.cc.o.requires:
.PHONY : CMakeFiles/hack.dir/dinstruction.cc.o.requires

CMakeFiles/hack.dir/dinstruction.cc.o.provides: CMakeFiles/hack.dir/dinstruction.cc.o.requires
	$(MAKE) -f CMakeFiles/hack.dir/build.make CMakeFiles/hack.dir/dinstruction.cc.o.provides.build
.PHONY : CMakeFiles/hack.dir/dinstruction.cc.o.provides

CMakeFiles/hack.dir/dinstruction.cc.o.provides.build: CMakeFiles/hack.dir/dinstruction.cc.o

CMakeFiles/hack.dir/hack.cc.o: CMakeFiles/hack.dir/flags.make
CMakeFiles/hack.dir/hack.cc.o: hack.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/samdoiron/Code/C++/HACK/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hack.dir/hack.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hack.dir/hack.cc.o -c /Users/samdoiron/Code/C++/HACK/hack.cc

CMakeFiles/hack.dir/hack.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hack.dir/hack.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/samdoiron/Code/C++/HACK/hack.cc > CMakeFiles/hack.dir/hack.cc.i

CMakeFiles/hack.dir/hack.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hack.dir/hack.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/samdoiron/Code/C++/HACK/hack.cc -o CMakeFiles/hack.dir/hack.cc.s

CMakeFiles/hack.dir/hack.cc.o.requires:
.PHONY : CMakeFiles/hack.dir/hack.cc.o.requires

CMakeFiles/hack.dir/hack.cc.o.provides: CMakeFiles/hack.dir/hack.cc.o.requires
	$(MAKE) -f CMakeFiles/hack.dir/build.make CMakeFiles/hack.dir/hack.cc.o.provides.build
.PHONY : CMakeFiles/hack.dir/hack.cc.o.provides

CMakeFiles/hack.dir/hack.cc.o.provides.build: CMakeFiles/hack.dir/hack.cc.o

CMakeFiles/hack.dir/instruction.cc.o: CMakeFiles/hack.dir/flags.make
CMakeFiles/hack.dir/instruction.cc.o: instruction.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/samdoiron/Code/C++/HACK/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hack.dir/instruction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hack.dir/instruction.cc.o -c /Users/samdoiron/Code/C++/HACK/instruction.cc

CMakeFiles/hack.dir/instruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hack.dir/instruction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/samdoiron/Code/C++/HACK/instruction.cc > CMakeFiles/hack.dir/instruction.cc.i

CMakeFiles/hack.dir/instruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hack.dir/instruction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/samdoiron/Code/C++/HACK/instruction.cc -o CMakeFiles/hack.dir/instruction.cc.s

CMakeFiles/hack.dir/instruction.cc.o.requires:
.PHONY : CMakeFiles/hack.dir/instruction.cc.o.requires

CMakeFiles/hack.dir/instruction.cc.o.provides: CMakeFiles/hack.dir/instruction.cc.o.requires
	$(MAKE) -f CMakeFiles/hack.dir/build.make CMakeFiles/hack.dir/instruction.cc.o.provides.build
.PHONY : CMakeFiles/hack.dir/instruction.cc.o.provides

CMakeFiles/hack.dir/instruction.cc.o.provides.build: CMakeFiles/hack.dir/instruction.cc.o

CMakeFiles/hack.dir/invalidsyntaxexception.cc.o: CMakeFiles/hack.dir/flags.make
CMakeFiles/hack.dir/invalidsyntaxexception.cc.o: invalidsyntaxexception.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/samdoiron/Code/C++/HACK/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hack.dir/invalidsyntaxexception.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hack.dir/invalidsyntaxexception.cc.o -c /Users/samdoiron/Code/C++/HACK/invalidsyntaxexception.cc

CMakeFiles/hack.dir/invalidsyntaxexception.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hack.dir/invalidsyntaxexception.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/samdoiron/Code/C++/HACK/invalidsyntaxexception.cc > CMakeFiles/hack.dir/invalidsyntaxexception.cc.i

CMakeFiles/hack.dir/invalidsyntaxexception.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hack.dir/invalidsyntaxexception.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/samdoiron/Code/C++/HACK/invalidsyntaxexception.cc -o CMakeFiles/hack.dir/invalidsyntaxexception.cc.s

CMakeFiles/hack.dir/invalidsyntaxexception.cc.o.requires:
.PHONY : CMakeFiles/hack.dir/invalidsyntaxexception.cc.o.requires

CMakeFiles/hack.dir/invalidsyntaxexception.cc.o.provides: CMakeFiles/hack.dir/invalidsyntaxexception.cc.o.requires
	$(MAKE) -f CMakeFiles/hack.dir/build.make CMakeFiles/hack.dir/invalidsyntaxexception.cc.o.provides.build
.PHONY : CMakeFiles/hack.dir/invalidsyntaxexception.cc.o.provides

CMakeFiles/hack.dir/invalidsyntaxexception.cc.o.provides.build: CMakeFiles/hack.dir/invalidsyntaxexception.cc.o

CMakeFiles/hack.dir/label.cc.o: CMakeFiles/hack.dir/flags.make
CMakeFiles/hack.dir/label.cc.o: label.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/samdoiron/Code/C++/HACK/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hack.dir/label.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hack.dir/label.cc.o -c /Users/samdoiron/Code/C++/HACK/label.cc

CMakeFiles/hack.dir/label.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hack.dir/label.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/samdoiron/Code/C++/HACK/label.cc > CMakeFiles/hack.dir/label.cc.i

CMakeFiles/hack.dir/label.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hack.dir/label.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/samdoiron/Code/C++/HACK/label.cc -o CMakeFiles/hack.dir/label.cc.s

CMakeFiles/hack.dir/label.cc.o.requires:
.PHONY : CMakeFiles/hack.dir/label.cc.o.requires

CMakeFiles/hack.dir/label.cc.o.provides: CMakeFiles/hack.dir/label.cc.o.requires
	$(MAKE) -f CMakeFiles/hack.dir/build.make CMakeFiles/hack.dir/label.cc.o.provides.build
.PHONY : CMakeFiles/hack.dir/label.cc.o.provides

CMakeFiles/hack.dir/label.cc.o.provides.build: CMakeFiles/hack.dir/label.cc.o

CMakeFiles/hack.dir/program.cc.o: CMakeFiles/hack.dir/flags.make
CMakeFiles/hack.dir/program.cc.o: program.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/samdoiron/Code/C++/HACK/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hack.dir/program.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hack.dir/program.cc.o -c /Users/samdoiron/Code/C++/HACK/program.cc

CMakeFiles/hack.dir/program.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hack.dir/program.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/samdoiron/Code/C++/HACK/program.cc > CMakeFiles/hack.dir/program.cc.i

CMakeFiles/hack.dir/program.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hack.dir/program.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/samdoiron/Code/C++/HACK/program.cc -o CMakeFiles/hack.dir/program.cc.s

CMakeFiles/hack.dir/program.cc.o.requires:
.PHONY : CMakeFiles/hack.dir/program.cc.o.requires

CMakeFiles/hack.dir/program.cc.o.provides: CMakeFiles/hack.dir/program.cc.o.requires
	$(MAKE) -f CMakeFiles/hack.dir/build.make CMakeFiles/hack.dir/program.cc.o.provides.build
.PHONY : CMakeFiles/hack.dir/program.cc.o.provides

CMakeFiles/hack.dir/program.cc.o.provides.build: CMakeFiles/hack.dir/program.cc.o

# Object files for target hack
hack_OBJECTS = \
"CMakeFiles/hack.dir/ainstruction.cc.o" \
"CMakeFiles/hack.dir/dinstruction.cc.o" \
"CMakeFiles/hack.dir/hack.cc.o" \
"CMakeFiles/hack.dir/instruction.cc.o" \
"CMakeFiles/hack.dir/invalidsyntaxexception.cc.o" \
"CMakeFiles/hack.dir/label.cc.o" \
"CMakeFiles/hack.dir/program.cc.o"

# External object files for target hack
hack_EXTERNAL_OBJECTS =

hack: CMakeFiles/hack.dir/ainstruction.cc.o
hack: CMakeFiles/hack.dir/dinstruction.cc.o
hack: CMakeFiles/hack.dir/hack.cc.o
hack: CMakeFiles/hack.dir/instruction.cc.o
hack: CMakeFiles/hack.dir/invalidsyntaxexception.cc.o
hack: CMakeFiles/hack.dir/label.cc.o
hack: CMakeFiles/hack.dir/program.cc.o
hack: CMakeFiles/hack.dir/build.make
hack: CMakeFiles/hack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable hack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hack.dir/build: hack
.PHONY : CMakeFiles/hack.dir/build

CMakeFiles/hack.dir/requires: CMakeFiles/hack.dir/ainstruction.cc.o.requires
CMakeFiles/hack.dir/requires: CMakeFiles/hack.dir/dinstruction.cc.o.requires
CMakeFiles/hack.dir/requires: CMakeFiles/hack.dir/hack.cc.o.requires
CMakeFiles/hack.dir/requires: CMakeFiles/hack.dir/instruction.cc.o.requires
CMakeFiles/hack.dir/requires: CMakeFiles/hack.dir/invalidsyntaxexception.cc.o.requires
CMakeFiles/hack.dir/requires: CMakeFiles/hack.dir/label.cc.o.requires
CMakeFiles/hack.dir/requires: CMakeFiles/hack.dir/program.cc.o.requires
.PHONY : CMakeFiles/hack.dir/requires

CMakeFiles/hack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hack.dir/clean

CMakeFiles/hack.dir/depend:
	cd /Users/samdoiron/Code/C++/HACK && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/samdoiron/Code/C++/HACK /Users/samdoiron/Code/C++/HACK /Users/samdoiron/Code/C++/HACK /Users/samdoiron/Code/C++/HACK /Users/samdoiron/Code/C++/HACK/CMakeFiles/hack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hack.dir/depend
