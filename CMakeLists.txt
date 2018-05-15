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
