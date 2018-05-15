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
