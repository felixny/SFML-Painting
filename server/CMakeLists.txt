############### INSTALLATION #######################
# Installation on Mac
# 'brew install cmake'
#
# Installation on Linux
# 'sudo apt-get install cmake'
#
# Installation on Windows
# See download page and download
####################################################

############## How to use CMake ####################
# I recommend you create a separate directory for
# your CMake generated files. This is a clean way
# to separate out all of your binary files generated
# from the source code. 
#
# mkdir bin	# Make a directory
# cd bin	# navigate to that directory
# cmake .. 	# Then execute the CMakeLists.txt
#		# file found one directory up.
####################################################

####################################################
# Writing a CMake file involves writing one 
# cmake command per line.

# The minimum required version of CMake to use
cmake_minimum_required(VERSION 3.10)

# Set the project name to your project name
project(
    App             # Name of our application
    VERSION 1.0     # Version of our software
    LANGUAGES CXX)  # Language that we are using

# We can additionally set the langauge standard for
# C++
set(CMAKE_CXX_STANDARD 17)

# Where are the include directories
# Should be different on your PC
include_directories("/usr/local/include")
include_directories("./include/")

# Where are the libraries
# Should be different on your PC
link_directories("/usr/local/lib")

# Add the source code files to a specific project
# We can indeed have multiple executables generated from
# one CMakeLists.txt file.
add_executable(App_Server ./src/App_Server.cpp ./src/Draw.cpp ./src/Command.cpp ./src/main_server.cpp) # example with more files
add_executable(App_Test ./src/App_Server.cpp ./src/Command.cpp ./src/Draw.cpp ./tests/main_test.cpp ./tests/catch_amalgamated.cpp)


# Add any libraries
target_link_libraries(App_Server sfml-graphics sfml-window sfml-system sfml-network)
target_link_libraries(App_Test sfml-graphics sfml-window sfml-system sfml-network)
