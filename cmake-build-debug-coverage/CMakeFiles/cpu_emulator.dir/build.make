# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/cpu_emulator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cpu_emulator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cpu_emulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpu_emulator.dir/flags.make

CMakeFiles/cpu_emulator.dir/main.cpp.o: CMakeFiles/cpu_emulator.dir/flags.make
CMakeFiles/cpu_emulator.dir/main.cpp.o: /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/main.cpp
CMakeFiles/cpu_emulator.dir/main.cpp.o: CMakeFiles/cpu_emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpu_emulator.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpu_emulator.dir/main.cpp.o -MF CMakeFiles/cpu_emulator.dir/main.cpp.o.d -o CMakeFiles/cpu_emulator.dir/main.cpp.o -c /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/main.cpp

CMakeFiles/cpu_emulator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu_emulator.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/main.cpp > CMakeFiles/cpu_emulator.dir/main.cpp.i

CMakeFiles/cpu_emulator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu_emulator.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/main.cpp -o CMakeFiles/cpu_emulator.dir/main.cpp.s

CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.o: CMakeFiles/cpu_emulator.dir/flags.make
CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.o: /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cpu-emulator.cpp
CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.o: CMakeFiles/cpu_emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.o -MF CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.o.d -o CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.o -c /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cpu-emulator.cpp

CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cpu-emulator.cpp > CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.i

CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cpu-emulator.cpp -o CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.s

CMakeFiles/cpu_emulator.dir/preprocessor.cpp.o: CMakeFiles/cpu_emulator.dir/flags.make
CMakeFiles/cpu_emulator.dir/preprocessor.cpp.o: /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/preprocessor.cpp
CMakeFiles/cpu_emulator.dir/preprocessor.cpp.o: CMakeFiles/cpu_emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cpu_emulator.dir/preprocessor.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpu_emulator.dir/preprocessor.cpp.o -MF CMakeFiles/cpu_emulator.dir/preprocessor.cpp.o.d -o CMakeFiles/cpu_emulator.dir/preprocessor.cpp.o -c /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/preprocessor.cpp

CMakeFiles/cpu_emulator.dir/preprocessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu_emulator.dir/preprocessor.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/preprocessor.cpp > CMakeFiles/cpu_emulator.dir/preprocessor.cpp.i

CMakeFiles/cpu_emulator.dir/preprocessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu_emulator.dir/preprocessor.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/preprocessor.cpp -o CMakeFiles/cpu_emulator.dir/preprocessor.cpp.s

CMakeFiles/cpu_emulator.dir/parser.cpp.o: CMakeFiles/cpu_emulator.dir/flags.make
CMakeFiles/cpu_emulator.dir/parser.cpp.o: /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/parser.cpp
CMakeFiles/cpu_emulator.dir/parser.cpp.o: CMakeFiles/cpu_emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cpu_emulator.dir/parser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpu_emulator.dir/parser.cpp.o -MF CMakeFiles/cpu_emulator.dir/parser.cpp.o.d -o CMakeFiles/cpu_emulator.dir/parser.cpp.o -c /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/parser.cpp

CMakeFiles/cpu_emulator.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu_emulator.dir/parser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/parser.cpp > CMakeFiles/cpu_emulator.dir/parser.cpp.i

CMakeFiles/cpu_emulator.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu_emulator.dir/parser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/parser.cpp -o CMakeFiles/cpu_emulator.dir/parser.cpp.s

CMakeFiles/cpu_emulator.dir/commands.cpp.o: CMakeFiles/cpu_emulator.dir/flags.make
CMakeFiles/cpu_emulator.dir/commands.cpp.o: /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/commands.cpp
CMakeFiles/cpu_emulator.dir/commands.cpp.o: CMakeFiles/cpu_emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cpu_emulator.dir/commands.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpu_emulator.dir/commands.cpp.o -MF CMakeFiles/cpu_emulator.dir/commands.cpp.o.d -o CMakeFiles/cpu_emulator.dir/commands.cpp.o -c /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/commands.cpp

CMakeFiles/cpu_emulator.dir/commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu_emulator.dir/commands.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/commands.cpp > CMakeFiles/cpu_emulator.dir/commands.cpp.i

CMakeFiles/cpu_emulator.dir/commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu_emulator.dir/commands.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/commands.cpp -o CMakeFiles/cpu_emulator.dir/commands.cpp.s

CMakeFiles/cpu_emulator.dir/command_builder.cpp.o: CMakeFiles/cpu_emulator.dir/flags.make
CMakeFiles/cpu_emulator.dir/command_builder.cpp.o: /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/command_builder.cpp
CMakeFiles/cpu_emulator.dir/command_builder.cpp.o: CMakeFiles/cpu_emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cpu_emulator.dir/command_builder.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpu_emulator.dir/command_builder.cpp.o -MF CMakeFiles/cpu_emulator.dir/command_builder.cpp.o.d -o CMakeFiles/cpu_emulator.dir/command_builder.cpp.o -c /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/command_builder.cpp

CMakeFiles/cpu_emulator.dir/command_builder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu_emulator.dir/command_builder.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/command_builder.cpp > CMakeFiles/cpu_emulator.dir/command_builder.cpp.i

CMakeFiles/cpu_emulator.dir/command_builder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu_emulator.dir/command_builder.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/command_builder.cpp -o CMakeFiles/cpu_emulator.dir/command_builder.cpp.s

# Object files for target cpu_emulator
cpu_emulator_OBJECTS = \
"CMakeFiles/cpu_emulator.dir/main.cpp.o" \
"CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.o" \
"CMakeFiles/cpu_emulator.dir/preprocessor.cpp.o" \
"CMakeFiles/cpu_emulator.dir/parser.cpp.o" \
"CMakeFiles/cpu_emulator.dir/commands.cpp.o" \
"CMakeFiles/cpu_emulator.dir/command_builder.cpp.o"

# External object files for target cpu_emulator
cpu_emulator_EXTERNAL_OBJECTS =

cpu_emulator: CMakeFiles/cpu_emulator.dir/main.cpp.o
cpu_emulator: CMakeFiles/cpu_emulator.dir/cpu-emulator.cpp.o
cpu_emulator: CMakeFiles/cpu_emulator.dir/preprocessor.cpp.o
cpu_emulator: CMakeFiles/cpu_emulator.dir/parser.cpp.o
cpu_emulator: CMakeFiles/cpu_emulator.dir/commands.cpp.o
cpu_emulator: CMakeFiles/cpu_emulator.dir/command_builder.cpp.o
cpu_emulator: CMakeFiles/cpu_emulator.dir/build.make
cpu_emulator: CMakeFiles/cpu_emulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable cpu_emulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpu_emulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpu_emulator.dir/build: cpu_emulator
.PHONY : CMakeFiles/cpu_emulator.dir/build

CMakeFiles/cpu_emulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpu_emulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpu_emulator.dir/clean

CMakeFiles/cpu_emulator.dir/depend:
	cd /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cmake-build-debug-coverage /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cmake-build-debug-coverage /Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/cmake-build-debug-coverage/CMakeFiles/cpu_emulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpu_emulator.dir/depend

