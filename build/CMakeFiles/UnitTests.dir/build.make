# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/build

# Include any dependencies generated for this target.
include CMakeFiles/UnitTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/UnitTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/UnitTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UnitTests.dir/flags.make

CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.o: CMakeFiles/UnitTests.dir/flags.make
CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.o: /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/test/test_DataLoader.cc
CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.o: CMakeFiles/UnitTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.o -MF CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.o.d -o CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.o -c /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/test/test_DataLoader.cc

CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/test/test_DataLoader.cc > CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.i

CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/test/test_DataLoader.cc -o CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.s

CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.o: CMakeFiles/UnitTests.dir/flags.make
CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.o: /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/test/test_ManifoldGeometry.cc
CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.o: CMakeFiles/UnitTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.o -MF CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.o.d -o CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.o -c /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/test/test_ManifoldGeometry.cc

CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/test/test_ManifoldGeometry.cc > CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.i

CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/test/test_ManifoldGeometry.cc -o CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.s

CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.o: CMakeFiles/UnitTests.dir/flags.make
CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.o: /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/test/test_BDTTrainer.cc
CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.o: CMakeFiles/UnitTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.o -MF CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.o.d -o CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.o -c /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/test/test_BDTTrainer.cc

CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/test/test_BDTTrainer.cc > CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.i

CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/test/test_BDTTrainer.cc -o CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.s

# Object files for target UnitTests
UnitTests_OBJECTS = \
"CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.o" \
"CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.o" \
"CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.o"

# External object files for target UnitTests
UnitTests_EXTERNAL_OBJECTS =

UnitTests: CMakeFiles/UnitTests.dir/test/test_DataLoader.cc.o
UnitTests: CMakeFiles/UnitTests.dir/test/test_ManifoldGeometry.cc.o
UnitTests: CMakeFiles/UnitTests.dir/test/test_BDTTrainer.cc.o
UnitTests: CMakeFiles/UnitTests.dir/build.make
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libCore.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libImt.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libRIO.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libNet.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libHist.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libGraf.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libGraf3d.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libGpad.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libROOTDataFrame.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libTree.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libTreePlayer.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libRint.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libPostscript.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libMatrix.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libPhysics.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libMathCore.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libThread.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libMultiProc.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libROOTVecOps.so
UnitTests: /opt/homebrew/Cellar/root/6.32.08/lib/root/libTMVA.so
UnitTests: /opt/homebrew/lib/libCatch2Main.a
UnitTests: /opt/homebrew/lib/libCatch2.a
UnitTests: CMakeFiles/UnitTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable UnitTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UnitTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UnitTests.dir/build: UnitTests
.PHONY : CMakeFiles/UnitTests.dir/build

CMakeFiles/UnitTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UnitTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UnitTests.dir/clean

CMakeFiles/UnitTests.dir/depend:
	cd /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/build /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/build /Users/am/Documents/05.FlavorPhysics/BsToMuMuGamma/BDT_Riemannian/build/CMakeFiles/UnitTests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/UnitTests.dir/depend

