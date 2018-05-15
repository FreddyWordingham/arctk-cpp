#   == CMAKE ==
#   -- Version --
cmake_minimum_required(VERSION 3.11.1)


#   == PROJECTS ==
#   -- Arctk Library --
project(arctk)


#   == DIRECTORIES ==
#   -- Source --
set(ARCTK_SOURCE_DIR ${CMAKE_SOURCE_DIR}/include)

#   -- Output --
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


#   == OPTIONS ==
#   -- Clang-Tidy --
if (IWYU)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
endif ()
message("Clang-Tidy: '${CLANG_TIDY}'.")

#   -- Include What You Use --
if (IWYU)
    set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "iwyu")
endif ()
message("IWYU: '${IWYU}'.")


#   == SOURCE CODE ==
#   -- Glob Files --
file(GLOB_RECURSE SOURCE_FILES ${ARCTK_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${ARCTK_SOURCE_DIR}/*.hpp)


#   == FLAGS ==
#   -- Standard --
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#   -- Optimisation --
if (CMAKE_BUILD_TYPE MATCHES "debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
        -DDEBUG                             \
        -g                                  \
        -O0                                 \
        -fsanitize=undefined                \
    ")
elseif (CMAKE_BUILD_TYPE MATCHES "release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
        -DNDEBUG                            \
        -O3                                 \
    ")
else ()
    message(FATAL_ERROR "Optimisation flags are not defined for build type: '${CMAKE_BUILD_TYPE}'.")
endif ()
