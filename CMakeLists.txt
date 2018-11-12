#   == CMAKE ==
cmake_minimum_required(VERSION 3.5.1)



#   == PROJECTS ==
#   -- Arctk --
project(arctk)



#   == VERSION ==
set(ARCTK_VERSION_MAJOR 0)

set(ARCTK_VERSION_MINOR 0)

execute_process(COMMAND git rev-list --count HEAD OUTPUT_VARIABLE ARCTK_VERSION_PATCH)
string(REGEX REPLACE "\n$" "" ARCTK_VERSION_PATCH "${ARCTK_VERSION_PATCH}")
set(ARCTK_VERSION_PATCH ${ARCTK_VERSION_PATCH})
message("arctk version: ${ARCTK_VERSION_MAJOR}.${ARCTK_VERSION_MINOR}.${ARCTK_VERSION_PATCH}")



#   == BUILD INFORMATION ==
execute_process(COMMAND git log -1 --format=%cd --date=short OUTPUT_VARIABLE ARCTK_DATE)
string(REGEX REPLACE "\n$" "" ARCTK_DATE "${ARCTK_DATE}")
message("arctk date: ${ARCTK_DATE}")

execute_process(COMMAND git rev-parse --abbrev-ref HEAD OUTPUT_VARIABLE ARCTK_BRANCH)
string(REGEX REPLACE "\n$" "" ARCTK_BRANCH "${ARCTK_BRANCH}")
message("arctk branch: ${ARCTK_BRANCH}")

execute_process(COMMAND git rev-parse --short HEAD OUTPUT_VARIABLE ARCTK_HASH)
string(REGEX REPLACE "\n$" "" ARCTK_HASH "${ARCTK_HASH}")
message("arctk hash: ${ARCTK_HASH}")

set(ARCTK_TYPE ${CMAKE_BUILD_TYPE})
message("arctk type: ${ARCTK_TYPE}")

set(ARCTK_COMPILER ${CMAKE_CXX_COMPILER_ID})
message("arctk compiler: ${ARCTK_COMPILER}")

set(ARCTK_DIR ${CMAKE_SOURCE_DIR})
message("arctk directory: ${ARCTK_DIR}")



#   == DIRECTORIES ==
#   -- Binary --
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#   -- Libraries --
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)



#   == CONFIGURATION ==
set(CONFIG_BUILD_HEADER_IN ${CMAKE_SOURCE_DIR}/config/include/arctk/config/build.hpp.in)
set(CONFIG_BUILD_HEADER ${CMAKE_SOURCE_DIR}/include/arctk/config/build.hpp)
configure_file(${CONFIG_BUILD_HEADER_IN} ${CONFIG_BUILD_HEADER} @ONLY)

set(CONFIG_VERSION_HEADER_IN ${CMAKE_SOURCE_DIR}/config/include/arctk/config/version.hpp.in)
set(CONFIG_VERSION_HEADER ${CMAKE_SOURCE_DIR}/include/arctk/config/version.hpp)
configure_file(${CONFIG_VERSION_HEADER_IN} ${CONFIG_VERSION_HEADER} @ONLY)

set(DOXYFILE_IN ${CMAKE_SOURCE_DIR}/config/docs/Doxyfile.in)
set(DOXYFILE ${CMAKE_SOURCE_DIR}/build/docs/Doxyfile)
configure_file(${DOXYFILE_IN} ${DOXYFILE} @ONLY)



#   == OPTIONS ==
message("Unit testing: ${UNIT_TESTING}")

if (CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
endif ()
message("Clang-Tidy: ${CLANG_TIDY}")

if (DOCUMENT)
    find_package(Doxygen)
    if (NOT DOXYGEN_FOUND)
        message (FATAL_ERROR "Doxygen is required to build the documentation.")
    endif ()

    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build/docs
        COMMENT "Generating API documentation with Doxygen."
        VERBATIM)
endif ()
message("Document: ${DOCUMENT}")



#   == SOURCE CODE ==
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/include/arctk/*.hpp)
file(GLOB_RECURSE IMPL_FILES ${CMAKE_SOURCE_DIR}/include/arctk/*.inl)
file(GLOB_RECURSE TEST_SOURCE_FILES ${CMAKE_SOURCE_DIR}/test/*.cpp)



#   == FLAGS ==
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (CMAKE_BUILD_TYPE MATCHES "debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
        -DDEBUG                             \
        -O0                                 \
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
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}      \
        -Weverything                             \
        -Wno-c++98-compat                        \
        -Wno-c++98-compat-bind-to-temporary-copy \
        -Wno-padded                              \
        -Wno-reserved-id-macro                   \
        -Wno-weak-vtables                        \
    ")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}     \
        -Waddress                               \
        -Waggressive-loop-optimizations         \
        -Wall                                   \
        -Walloc-zero                            \
        -Walloca                                \
        -Warray-bounds                          \
        -Wattributes                            \
        -Wbool-compare                          \
        -Wbool-operation                        \
        -Wbuiltin-declaration-mismatch          \
        -Wbuiltin-macro-redefined               \
        -Wc++11-compat                          \
        -Wc++14-compat                          \
        -Wc++17-compat                          \
        -Wcast-align                            \
        -Wcast-qual                             \
        -Wchar-subscripts                       \
        -Wchkp                                  \
        -Wclobbered                             \
        -Wcomments                              \
        -Wconditionally-supported               \
        -Wconversion                            \
        -Wconversion-null                       \
        -Wcoverage-mismatch                     \
        -Wcpp                                   \
        -Wctor-dtor-privacy                     \
        -Wdangling-else                         \
        -Wdate-time                             \
        -Wdelete-incomplete                     \
        -Wdelete-non-virtual-dtor               \
        -Wdeprecated                            \
        -Wdeprecated-declarations               \
        -Wdisabled-optimization                 \
        -Wdiv-by-zero                           \
        -Wdouble-promotion                      \
        -Wduplicated-branches                   \
        -Wduplicated-cond                       \
        -Weffc++                                \
        -Wempty-body                            \
        -Wendif-labels                          \
        -Wenum-compare                          \
        -Werror-implicit-function-declaration   \
        -Wexpansion-to-defined                  \
        -Wextra                                 \
        -Wfloat-conversion                      \
        -Wfloat-equal                           \
        -Wformat-contains-nul                   \
        -Wformat-extra-args                     \
        -Wformat-nonliteral                     \
        -Wformat-overflow                       \
        -Wformat-security                       \
        -Wformat-signedness                     \
        -Wformat-truncation                     \
        -Wformat-y2k                            \
        -Wformat-zero-length                    \
        -Wframe-address                         \
        -Wfree-nonheap-object                   \
        -Whsa                                   \
        -Wignored-attributes                    \
        -Wignored-qualifiers                    \
        -Wimplicit-fallthrough                  \
        -Wimport                                \
        -Winherited-variadic-ctor               \
        -Winit-self                             \
        -Winline                                \
        -Wint-in-bool-context                   \
        -Wint-to-pointer-cast                   \
        -Winvalid-memory-model                  \
        -Winvalid-offsetof                      \
        -Winvalid-pch                           \
        -Wliteral-suffix                        \
        -Wlogical-not-parentheses               \
        -Wlogical-op                            \
        -Wlong-long                             \
        -Wlto-type-mismatch                     \
        -Wmain                                  \
        -Wmaybe-uninitialized                   \
        -Wmemset-elt-size                       \
        -Wmemset-transposed-args                \
        -Wmisleading-indentation                \
        -Wmissing-braces                        \
        -Wmissing-declarations                  \
        -Wmissing-field-initializers            \
        -Wmissing-format-attribute              \
        -Wmissing-include-dirs                  \
        -Wmissing-noreturn                      \
        -Wmultichar                             \
        -Wmultiple-inheritance                  \
        -Wnarrowing                             \
        -Wnoexcept                              \
        -Wnoexcept-type                         \
        -Wnon-template-friend                   \
        -Wnon-virtual-dtor                      \
        -Wnonnull                               \
        -Wnonnull-compare                       \
        -Wnormalized                            \
        -Wnull-dereference                      \
        -Wodr                                   \
        -Wold-style-cast                        \
        -Wopenmp-simd                           \
        -Woverflow                              \
        -Woverlength-strings                    \
        -Woverloaded-virtual                    \
        -Wpacked                                \
        -Wpacked-bitfield-compat                \
        -Wparentheses                           \
        -Wpedantic                              \
        -Wplacement-new                         \
        -Wpmf-conversions                       \
        -Wpointer-arith                         \
        -Wpointer-compare                       \
        -Wpragmas                               \
        -Wpsabi                                 \
        -Wredundant-decls                       \
        -Wregister                              \
        -Wreorder                               \
        -Wrestrict                              \
        -Wreturn-local-addr                     \
        -Wreturn-type                           \
        -Wscalar-storage-order                  \
        -Wsequence-point                        \
        -Wshadow                                \
        -Wshadow-compatible-local               \
        -Wshadow-local                          \
        -Wshadow=compatible-local               \
        -Wshadow=global                         \
        -Wshadow=local                          \
        -Wshift-count-negative                  \
        -Wshift-count-overflow                  \
        -Wshift-negative-value                  \
        -Wsign-compare                          \
        -Wsign-conversion                       \
        -Wsign-promo                            \
        -Wsized-deallocation                    \
        -Wsizeof-array-argument                 \
        -Wsizeof-pointer-memaccess              \
        -Wstack-protector                       \
        -Wstrict-aliasing                       \
        -Wstrict-null-sentinel                  \
        -Wstrict-overflow                       \
        -Wstringop-overflow                     \
        -Wsubobject-linkage                     \
        -Wsuggest-attribute=const               \
        -Wsuggest-attribute=format              \
        -Wsuggest-attribute=noreturn            \
        -Wsuggest-attribute=pure                \
        -Wsuggest-final-methods                 \
        -Wsuggest-final-types                   \
        -Wsuggest-override                      \
        -Wswitch                                \
        -Wswitch-bool                           \
        -Wswitch-enum                           \
        -Wswitch-unreachable                    \
        -Wsync-nand                             \
        -Wsynth                                 \
        -Wtautological-compare                  \
        -Wterminate                             \
        -Wtrampolines                           \
        -Wtrigraphs                             \
        -Wtype-limits                           \
        -Wundef                                 \
        -Wuninitialized                         \
        -Wno-unknown-pragmas                    \
        -Wunreachable-code                      \
        -Wunsafe-loop-optimizations             \
        -Wunused                                \
        -Wunused-but-set-parameter              \
        -Wunused-but-set-variable               \
        -Wunused-function                       \
        -Wunused-label                          \
        -Wunused-local-typedefs                 \
        -Wunused-macros                         \
        -Wunused-parameter                      \
        -Wunused-result                         \
        -Wunused-value                          \
        -Wunused-variable                       \
        -Wuseless-cast                          \
        -Wvarargs                               \
        -Wvariadic-macros                       \
        -Wvector-operation-performance          \
        -Wvirtual-inheritance                   \
        -Wvirtual-move-assign                   \
        -Wvla                                   \
        -Wvolatile-register-var                 \
        -Wwrite-strings                         \
        -Wzero-as-null-pointer-constant         \
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
install(DIRECTORY ./include/arctk/ DESTINATION include/arctk FILES_MATCHING PATTERN "*.h")
install(DIRECTORY ./include/arctk/ DESTINATION include/arctk FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY ./include/arctk/ DESTINATION include/arctk FILES_MATCHING PATTERN "*.inl")
install(TARGETS arctk EXPORT arctk LIBRARY DESTINATION lib ARCHIVE DESTINATION lib INCLUDES DESTINATION include)



#   == TESTING ==
if (UNIT_TESTING)

    enable_testing()

    message("Tests: ${TEST_SOURCE_FILES}")

    foreach(loop_var ${TEST_SOURCE_FILES})

        set(NAME ${loop_var})
        STRING(REGEX REPLACE "${CMAKE_SOURCE_DIR}/test/" "" NAME ${NAME})
        STRING(REGEX REPLACE "/" "_" NAME ${NAME})
        STRING(REGEX REPLACE ".cpp" "_unit_test" NAME ${NAME})

        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/test)
        add_executable(${NAME} ${loop_var})

        #   -- Packages --
        find_package(OpenGL REQUIRED)
        find_package(SDL2 REQUIRED)
        find_package(GLEW REQUIRED)
        find_package(glfw3 3.2.1 REQUIRED)

        #   -- Include System Directories --
        target_include_directories(${NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
        target_include_directories(${NAME} SYSTEM PUBLIC ${OPENGL_INCLUDE_DIR})
        target_include_directories(${NAME} SYSTEM PUBLIC ${SDL2_INCLUDE_DIRS})
        target_include_directories(${NAME} SYSTEM PUBLIC ${GLEW_INCLUDE_DIRS})

        #   -- Link Libraries --
        target_link_libraries(${NAME} c++fs)
        target_link_libraries(${NAME} ${OPENGL_LIBRARIES})
        target_link_libraries(${NAME} ${SDL2_LIBRARIES})
        target_link_libraries(${NAME} ${GLEW_LIBRARIES})
        target_link_libraries(${NAME} glfw)

        add_test(${NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${NAME})

    endforeach(loop_var)

endif()
