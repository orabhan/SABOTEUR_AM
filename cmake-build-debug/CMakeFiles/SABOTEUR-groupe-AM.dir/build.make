# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/theobonnet/Desktop/SABOTEUR_AM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/theobonnet/Desktop/SABOTEUR_AM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SABOTEUR-groupe-AM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SABOTEUR-groupe-AM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SABOTEUR-groupe-AM.dir/flags.make

CMakeFiles/SABOTEUR-groupe-AM.dir/main.c.o: CMakeFiles/SABOTEUR-groupe-AM.dir/flags.make
CMakeFiles/SABOTEUR-groupe-AM.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/theobonnet/Desktop/SABOTEUR_AM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SABOTEUR-groupe-AM.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SABOTEUR-groupe-AM.dir/main.c.o   -c /Users/theobonnet/Desktop/SABOTEUR_AM/main.c

CMakeFiles/SABOTEUR-groupe-AM.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SABOTEUR-groupe-AM.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/theobonnet/Desktop/SABOTEUR_AM/main.c > CMakeFiles/SABOTEUR-groupe-AM.dir/main.c.i

CMakeFiles/SABOTEUR-groupe-AM.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SABOTEUR-groupe-AM.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/theobonnet/Desktop/SABOTEUR_AM/main.c -o CMakeFiles/SABOTEUR-groupe-AM.dir/main.c.s

CMakeFiles/SABOTEUR-groupe-AM.dir/fonctionSetup.c.o: CMakeFiles/SABOTEUR-groupe-AM.dir/flags.make
CMakeFiles/SABOTEUR-groupe-AM.dir/fonctionSetup.c.o: ../fonctionSetup.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/theobonnet/Desktop/SABOTEUR_AM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SABOTEUR-groupe-AM.dir/fonctionSetup.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SABOTEUR-groupe-AM.dir/fonctionSetup.c.o   -c /Users/theobonnet/Desktop/SABOTEUR_AM/fonctionSetup.c

CMakeFiles/SABOTEUR-groupe-AM.dir/fonctionSetup.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SABOTEUR-groupe-AM.dir/fonctionSetup.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/theobonnet/Desktop/SABOTEUR_AM/fonctionSetup.c > CMakeFiles/SABOTEUR-groupe-AM.dir/fonctionSetup.c.i

CMakeFiles/SABOTEUR-groupe-AM.dir/fonctionSetup.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SABOTEUR-groupe-AM.dir/fonctionSetup.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/theobonnet/Desktop/SABOTEUR_AM/fonctionSetup.c -o CMakeFiles/SABOTEUR-groupe-AM.dir/fonctionSetup.c.s

# Object files for target SABOTEUR-groupe-AM
SABOTEUR__groupe__AM_OBJECTS = \
"CMakeFiles/SABOTEUR-groupe-AM.dir/main.c.o" \
"CMakeFiles/SABOTEUR-groupe-AM.dir/fonctionSetup.c.o"

# External object files for target SABOTEUR-groupe-AM
SABOTEUR__groupe__AM_EXTERNAL_OBJECTS =

SABOTEUR-groupe-AM: CMakeFiles/SABOTEUR-groupe-AM.dir/main.c.o
SABOTEUR-groupe-AM: CMakeFiles/SABOTEUR-groupe-AM.dir/fonctionSetup.c.o
SABOTEUR-groupe-AM: CMakeFiles/SABOTEUR-groupe-AM.dir/build.make
SABOTEUR-groupe-AM: /usr/local/lib/libFLAC++.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libFLAC++.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libFLAC.8.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libFLAC.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_acodec.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_acodec.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_acodec.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_audio.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_audio.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_audio.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_color.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_color.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_color.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_dialog.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_dialog.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_dialog.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_font.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_font.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_font.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_image.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_image.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_image.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_main.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_main.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_main.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_memfile.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_memfile.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_memfile.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_physfs.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_physfs.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_physfs.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_primitives.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_primitives.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_primitives.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_ttf.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_ttf.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_ttf.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_video.5.2.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_video.5.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/liballegro_video.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libfreetype.6.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libfreetype.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libjpeg.9.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libjpeg.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libogg.0.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libogg.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libopus.0.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libopus.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libopusfile.0.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libopusfile.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libopusurl.0.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libopusurl.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libphysfs.1.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libphysfs.3.0.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libphysfs.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libpng.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libpng16.16.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libpng16.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libtheora.0.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libtheora.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libtheoradec.1.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libtheoradec.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libtheoraenc.1.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libtheoraenc.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libtiff.5.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libtiff.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libtiffxx.5.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libtiffxx.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libvorbis.0.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libvorbis.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libvorbisenc.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libvorbisenc.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libvorbisfile.3.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libvorbisfile.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libwebp.7.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libwebp.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libwebpdecoder.3.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libwebpdecoder.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libwebpdemux.2.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libwebpdemux.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libwebpmux.3.dylib
SABOTEUR-groupe-AM: /usr/local/lib/libwebpmux.dylib
SABOTEUR-groupe-AM: CMakeFiles/SABOTEUR-groupe-AM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/theobonnet/Desktop/SABOTEUR_AM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable SABOTEUR-groupe-AM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SABOTEUR-groupe-AM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SABOTEUR-groupe-AM.dir/build: SABOTEUR-groupe-AM

.PHONY : CMakeFiles/SABOTEUR-groupe-AM.dir/build

CMakeFiles/SABOTEUR-groupe-AM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SABOTEUR-groupe-AM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SABOTEUR-groupe-AM.dir/clean

CMakeFiles/SABOTEUR-groupe-AM.dir/depend:
	cd /Users/theobonnet/Desktop/SABOTEUR_AM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/theobonnet/Desktop/SABOTEUR_AM /Users/theobonnet/Desktop/SABOTEUR_AM /Users/theobonnet/Desktop/SABOTEUR_AM/cmake-build-debug /Users/theobonnet/Desktop/SABOTEUR_AM/cmake-build-debug /Users/theobonnet/Desktop/SABOTEUR_AM/cmake-build-debug/CMakeFiles/SABOTEUR-groupe-AM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SABOTEUR-groupe-AM.dir/depend

