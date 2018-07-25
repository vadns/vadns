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


# Configure <vadns/version.h>
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.cmakein"
    "${CMAKE_CURRENT_BINARY_DIR}/cmakein/vadns/version.h"
    @ONLY
)


set(SOURCE_FILES
    src/main.cpp)

include_directories("${CMAKE_CURRENT_BINARY_DIR}/cmakein")

add_executable(vadns ${SOURCE_FILES})
