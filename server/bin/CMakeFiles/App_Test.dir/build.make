# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/bin"

# Include any dependencies generated for this target.
include CMakeFiles/App_Test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/App_Test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/App_Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/App_Test.dir/flags.make

CMakeFiles/App_Test.dir/src/App_Server.cpp.o: CMakeFiles/App_Test.dir/flags.make
CMakeFiles/App_Test.dir/src/App_Server.cpp.o: ../src/App_Server.cpp
CMakeFiles/App_Test.dir/src/App_Server.cpp.o: CMakeFiles/App_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/App_Test.dir/src/App_Server.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/App_Test.dir/src/App_Server.cpp.o -MF CMakeFiles/App_Test.dir/src/App_Server.cpp.o.d -o CMakeFiles/App_Test.dir/src/App_Server.cpp.o -c "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/src/App_Server.cpp"

CMakeFiles/App_Test.dir/src/App_Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/App_Test.dir/src/App_Server.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/src/App_Server.cpp" > CMakeFiles/App_Test.dir/src/App_Server.cpp.i

CMakeFiles/App_Test.dir/src/App_Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/App_Test.dir/src/App_Server.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/src/App_Server.cpp" -o CMakeFiles/App_Test.dir/src/App_Server.cpp.s

CMakeFiles/App_Test.dir/src/Command.cpp.o: CMakeFiles/App_Test.dir/flags.make
CMakeFiles/App_Test.dir/src/Command.cpp.o: ../src/Command.cpp
CMakeFiles/App_Test.dir/src/Command.cpp.o: CMakeFiles/App_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/App_Test.dir/src/Command.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/App_Test.dir/src/Command.cpp.o -MF CMakeFiles/App_Test.dir/src/Command.cpp.o.d -o CMakeFiles/App_Test.dir/src/Command.cpp.o -c "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/src/Command.cpp"

CMakeFiles/App_Test.dir/src/Command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/App_Test.dir/src/Command.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/src/Command.cpp" > CMakeFiles/App_Test.dir/src/Command.cpp.i

CMakeFiles/App_Test.dir/src/Command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/App_Test.dir/src/Command.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/src/Command.cpp" -o CMakeFiles/App_Test.dir/src/Command.cpp.s

CMakeFiles/App_Test.dir/src/Draw.cpp.o: CMakeFiles/App_Test.dir/flags.make
CMakeFiles/App_Test.dir/src/Draw.cpp.o: ../src/Draw.cpp
CMakeFiles/App_Test.dir/src/Draw.cpp.o: CMakeFiles/App_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/App_Test.dir/src/Draw.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/App_Test.dir/src/Draw.cpp.o -MF CMakeFiles/App_Test.dir/src/Draw.cpp.o.d -o CMakeFiles/App_Test.dir/src/Draw.cpp.o -c "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/src/Draw.cpp"

CMakeFiles/App_Test.dir/src/Draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/App_Test.dir/src/Draw.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/src/Draw.cpp" > CMakeFiles/App_Test.dir/src/Draw.cpp.i

CMakeFiles/App_Test.dir/src/Draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/App_Test.dir/src/Draw.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/src/Draw.cpp" -o CMakeFiles/App_Test.dir/src/Draw.cpp.s

CMakeFiles/App_Test.dir/tests/main_test.cpp.o: CMakeFiles/App_Test.dir/flags.make
CMakeFiles/App_Test.dir/tests/main_test.cpp.o: ../tests/main_test.cpp
CMakeFiles/App_Test.dir/tests/main_test.cpp.o: CMakeFiles/App_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/App_Test.dir/tests/main_test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/App_Test.dir/tests/main_test.cpp.o -MF CMakeFiles/App_Test.dir/tests/main_test.cpp.o.d -o CMakeFiles/App_Test.dir/tests/main_test.cpp.o -c "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/tests/main_test.cpp"

CMakeFiles/App_Test.dir/tests/main_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/App_Test.dir/tests/main_test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/tests/main_test.cpp" > CMakeFiles/App_Test.dir/tests/main_test.cpp.i

CMakeFiles/App_Test.dir/tests/main_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/App_Test.dir/tests/main_test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/tests/main_test.cpp" -o CMakeFiles/App_Test.dir/tests/main_test.cpp.s

CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.o: CMakeFiles/App_Test.dir/flags.make
CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.o: ../tests/catch_amalgamated.cpp
CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.o: CMakeFiles/App_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.o -MF CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.o.d -o CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.o -c "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/tests/catch_amalgamated.cpp"

CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/tests/catch_amalgamated.cpp" > CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.i

CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/tests/catch_amalgamated.cpp" -o CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.s

# Object files for target App_Test
App_Test_OBJECTS = \
"CMakeFiles/App_Test.dir/src/App_Server.cpp.o" \
"CMakeFiles/App_Test.dir/src/Command.cpp.o" \
"CMakeFiles/App_Test.dir/src/Draw.cpp.o" \
"CMakeFiles/App_Test.dir/tests/main_test.cpp.o" \
"CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.o"

# External object files for target App_Test
App_Test_EXTERNAL_OBJECTS =

App_Test: CMakeFiles/App_Test.dir/src/App_Server.cpp.o
App_Test: CMakeFiles/App_Test.dir/src/Command.cpp.o
App_Test: CMakeFiles/App_Test.dir/src/Draw.cpp.o
App_Test: CMakeFiles/App_Test.dir/tests/main_test.cpp.o
App_Test: CMakeFiles/App_Test.dir/tests/catch_amalgamated.cpp.o
App_Test: CMakeFiles/App_Test.dir/build.make
App_Test: CMakeFiles/App_Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable App_Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/App_Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/App_Test.dir/build: App_Test
.PHONY : CMakeFiles/App_Test.dir/build

CMakeFiles/App_Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/App_Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/App_Test.dir/clean

CMakeFiles/App_Test.dir/depend:
	cd "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/bin" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server" "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server" "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/bin" "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/bin" "/Users/felixyamano/Documents/NEU/CS5500/FinalProject/gui working/server/bin/CMakeFiles/App_Test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/App_Test.dir/depend
