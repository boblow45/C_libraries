# Set the cmake version which the user needs in order for this to work
cmake_minimum_required(VERSION 3.12)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build"
)

# The gtest/gmock targets carry header search path dependencies
# automatically when using CMake 2.8.11 or later. Otherwise we
# have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include"
    )
endif()

# Set the variable "This", which will be used as the project name through out this file
set(This Example)

# State that we will be using C and C++
project(${This} VERSION 1.0.0)

# Set the compiler to the strictest mode, enable all warnings and make all warnings errors
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
# Force all libs to be staticly linked instead of dynamicly linked 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -g")
# Set compiler to maximum optimization and remove all debug code from the compiled file
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -s -DNDEBUG") 

# Set the C and C++ Standard to use for the project.
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(DCMAKE_BUILD_TYPE DEBUG)

# Add directories of any header files which will be used in the project
include_directories (
                        "./include"
                        "./source"
)

# Add indiviual include files
set(Headers
    "./include/binary_search.h"
    "./include/bit_manipulation.h"
    "./include/sorting_alg.h"
    "./include/circular_buffer.h"
    "./include/linked_list.h"
    "./include/stack.h"
    "./include/list.hpp"
    "./include/hashmap.hpp"
    "./include/bst.hpp"
    )
    

# Add indiviual source files
set(Sources
    "./source/binary_search.c"
    "./source/bit_manipulation.c"
    "./source/sorting_alg.c"
    "./source/circular_buffer.c"
    "./source/linked_list.c"
    "./source/stack.c"
    "./source/list.cpp"
    "./source/bst.cpp"
)

# Build the code as a static lib, this is done so google test can link against the code 
add_library(${This} STATIC ${Sources} ${Headers})

# Add the test directory as a subdirectory. This directory will contain another cmake file
# which will build the tests 
enable_testing()
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)
add_subdirectory(test)


# Adding something we can run - Output name matches target name
add_executable("${This}EXE" "./source/main.cpp")


ADD_CUSTOM_TARGET(run COMMAND "./${This}EXE"
  COMMENT "Run with ${CMAKE_BUILD_TYPE} configuration"
  )

option(BUILD_DOC "Build documentation" ON)
# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)