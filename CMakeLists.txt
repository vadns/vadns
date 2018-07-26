cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(vadns
    LANGUAGES C CXX
    VERSION 0.0.1)

# VADNS_VERSION_SUFFIX could be:
#   unstable, alpha, beta, rc, stable
set(VADNS_VERSION_SUFFIX "unstable")


# Parse git branch and commit hash that we are building from
# TODO: What if we are not building from a git repository?
# TODO: What if 'git' is not installed?
#
# Get the current working branch
execute_process(
    COMMAND git rev-parse --abbrev-ref HEAD
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE VADNS_GIT_BRANCH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get the latest full commit hash of the working branch
execute_process(
    COMMAND git log -1 --format=%H
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE VADNS_GIT_COMMIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)


# Enable C++ 11
set(CMAKE_CXX_STANDARD 11)


# Add "src" to include directories
include_directories("src")

# Configure or copy headers in source directory to build dir
# Add finished directory to include directories
# configure_file(A B ...):
#   A is relative to CMAKE_CURRENT_SOURCE_DIR
#   B is relative to CMAKE_CURRENT_BINARY_DIR
#
# "dir" must be relative path to CMAKE_CURRENT_SOURCE_DIR
macro(ConfigureOrCopyFiles dir)
    file(GLOB_RECURSE filenames RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/${dir}/*")
    # Configure *.cmakein
    foreach(filename ${filenames})
        if ("${filename}" MATCHES "\\.cmakein$")
            string(REGEX REPLACE "\\.cmakein$" "" basename ${filename})
            message(STATUS "Configure file: ${CMAKE_CURRENT_SOURCE_DIR}/${filename} -> ${CMAKE_CURRENT_BINARY_DIR}/${basename}")
            configure_file("${filename}" "${basename}" @ONLY)
        endif()
    endforeach()
    # Copy files other than *.cmakein
    foreach(filename ${filenames})
        if (NOT "${filename}" MATCHES "\\.cmakein$")
            message(STATUS "Copy file: ${CMAKE_CURRENT_SOURCE_DIR}/${filename} -> ${CMAKE_CURRENT_BINARY_DIR}/${filename}")
            configure_file("${filename}" "${filename}" COPYONLY)
        endif()
    endforeach()
    # Add to include directories
    include_directories("${CMAKE_CURRENT_BINARY_DIR}/${dir}")
endmacro()

# Configure or copy headers in include/vadns (and add to include directories)
ConfigureOrCopyFiles(include/vadns)


set(SOURCE_FILES
    src/main.cpp
    src/core/macros.h
    src/net/server.cpp src/net/server.h
    src/dns/iana.h src/compat/types.h)

add_executable(vadns ${SOURCE_FILES})
