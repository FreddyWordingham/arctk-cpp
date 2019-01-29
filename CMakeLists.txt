#   == CMAKE ==
cmake_minimum_required(VERSION 3.13.2)



#   == PROJECTS ==
#   -- Arc --
project(arctk)



#   == VERSION ==
set(ARCTK_VERSION_MAJOR 0)

set(ARCTK_VERSION_MINOR 0)

execute_process(COMMAND git rev-list --count HEAD OUTPUT_VARIABLE ARCTK_VERSION_PATCH)
string(REGEX REPLACE "\n$" "" ARCTK_VERSION_PATCH "${ARCTK_VERSION_PATCH}")
set(ARCTK_VERSION_PATCH ${ARCTK_VERSION_PATCH})
message("Arc version: ${ARCTK_VERSION_MAJOR}.${ARCTK_VERSION_MINOR}.${ARCTK_VERSION_PATCH}")



#   == BUILD INFORMATION ==
execute_process(COMMAND git log -1 --format=%cd --date=short OUTPUT_VARIABLE ARCTK_DATE)
string(REGEX REPLACE "\n$" "" ARCTK_DATE "${ARCTK_DATE}")
message("Arc date: ${ARCTK_DATE}")

execute_process(COMMAND git rev-parse --abbrev-ref HEAD OUTPUT_VARIABLE ARCTK_BRANCH)
string(REGEX REPLACE "\n$" "" ARCTK_BRANCH "${ARCTK_BRANCH}")
message("Arc branch: ${ARCTK_BRANCH}")

execute_process(COMMAND git rev-parse --short HEAD OUTPUT_VARIABLE ARCTK_HASH)
string(REGEX REPLACE "\n$" "" ARCTK_HASH "${ARCTK_HASH}")
message("Arc hash: ${ARCTK_HASH}")

set(ARCTK_TYPE ${CMAKE_BUILD_TYPE})
message("Arc type: ${ARCTK_TYPE}")

set(ARCTK_COMPILER ${CMAKE_CXX_COMPILER_ID})
message("Arc compiler: ${ARCTK_COMPILER}")

set(ARCTK_DIR ${CMAKE_SOURCE_DIR})
message("Arc directory: ${ARCTK_DIR}")



#   == DIRECTORIES ==
#   -- Binary --
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#   -- Libraries --
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)



#   == CONFIGURATION ==
set(CONFIG_BUILD_HEADER_IN ${CMAKE_SOURCE_DIR}/config/include/build.hpp.in)
set(CONFIG_BUILD_HEADER ${CMAKE_SOURCE_DIR}/include/arctk/config/build.hpp)
configure_file(${CONFIG_BUILD_HEADER_IN} ${CONFIG_BUILD_HEADER} @ONLY)
set(CONFIG_BUILD_IMPLEMENTATION_IN ${CMAKE_SOURCE_DIR}/config/include/build.inl.in)
set(CONFIG_BUILD_IMPLEMENTATION ${CMAKE_SOURCE_DIR}/include/arctk/config/build.inl)
configure_file(${CONFIG_BUILD_IMPLEMENTATION_IN} ${CONFIG_BUILD_IMPLEMENTATION} @ONLY)

set(CONFIG_VERSION_HEADER_IN ${CMAKE_SOURCE_DIR}/config/include/version.hpp.in)
set(CONFIG_VERSION_HEADER ${CMAKE_SOURCE_DIR}/include/arctk/config/version.hpp)
configure_file(${CONFIG_VERSION_HEADER_IN} ${CONFIG_VERSION_HEADER} @ONLY)
set(CONFIG_VERSION_IMPLEMENTATION_IN ${CMAKE_SOURCE_DIR}/config/include/version.inl.in)
set(CONFIG_VERSION_IMPLEMENTATION ${CMAKE_SOURCE_DIR}/include/arctk/config/version.inl)
configure_file(${CONFIG_VERSION_IMPLEMENTATION_IN} ${CONFIG_VERSION_IMPLEMENTATION} @ONLY)



#   == OPTIONS ==
message("Unit testing: ${UNIT_TESTING}")

if (CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
endif ()
message("Clang-Tidy: ${CLANG_TIDY}")



#   == SOURCE CODE ==
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/include/arctk/*.hpp)
file(GLOB_RECURSE IMPL_FILES ${CMAKE_SOURCE_DIR}/include/arctk/*.inl)
file(GLOB_RECURSE TEST_SOURCE_FILES ${CMAKE_SOURCE_DIR}/testing/*.cpp)



#   == FLAGS ==
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (CMAKE_BUILD_TYPE MATCHES "debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
        -DDEBUG                             \
        -O0                                 \
    ")
elseif (CMAKE_BUILD_TYPE MATCHES "cover")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
        -DDEBUG                             \
        -O0                                 \
        -fprofile-arcs                      \
        -ftest-coverage                     \
    ")
elseif (CMAKE_BUILD_TYPE MATCHES "release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
        -DNDEBUG                            \
        -O3                                 \
    ")
else ()
    message(FATAL_ERROR "Optimisation flags are not defined for build type: ${CMAKE_BUILD_TYPE}")
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
        -Weverything                        \
        -Wno-c++98-compat                   \
        -Wno-c++98-compat-extra-semi        \
    ")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
        -Wall                               \
        -Wextra                             \
        -Wpedantic                          \
        -Wformat=2                          \
    ")
else ()
    message(FATAL_ERROR "Warning flags are not defined for compiler type: ${CMAKE_CXX_COMPILER_ID}")
endif ()



#   == TARGETS ==
add_library(arctk INTERFACE)
include_directories(SYSTEM "/usr/local/include")
target_include_directories(arctk INTERFACE "${CMAKE_SOURCE_DIR}/include")
target_sources(arctk INTERFACE ${HEADER_FILES} ${IMPL_FILES})



#   == INSTALLATION ==
install(DIRECTORY ./include/arctk/ DESTINATION include/arctk FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY ./include/arctk/ DESTINATION include/arctk FILES_MATCHING PATTERN "*.inl")
install(TARGETS arctk EXPORT arctk LIBRARY DESTINATION lib ARCHIVE DESTINATION lib INCLUDES DESTINATION include)



#   == TESTING ==
if (UNIT_TESTING)

    enable_testing()

    message("Tests: ${TEST_SOURCE_FILES}")

    foreach(loop_var ${TEST_SOURCE_FILES})

        set(NAME ${loop_var})
        STRING(REGEX REPLACE "${CMAKE_SOURCE_DIR}/testing/" "" NAME ${NAME})
        STRING(REGEX REPLACE "/" "_" NAME ${NAME})
        STRING(REGEX REPLACE ".cpp" "_test" NAME ${NAME})

        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/test)
        add_executable(${NAME} ${loop_var})

        target_include_directories(${NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

        target_link_libraries(${NAME} c++fs)

        add_test(${NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${NAME})

    endforeach(loop_var)

endif()
