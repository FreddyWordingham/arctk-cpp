#   == CMAKE ==
#   -- Version --
cmake_minimum_required(VERSION 3.11.1)


#   == PROJECTS ==
#   -- Arctk Library --
project(arctk)


#   == BUILD INFORMATION ==
#   -- Date --
execute_process(COMMAND git log -1 --format=%cd --date=short OUTPUT_VARIABLE ARCTK_DATE)
string(REGEX REPLACE "\n$" "" ARCTK_DATE "${ARCTK_DATE}")
set(ARCTK_DATE ${ARCTK_DATE})
message("arctk date: '${ARCTK_DATE}'.")

#   -- Branch --
execute_process(COMMAND git rev-parse --abbrev-ref HEAD OUTPUT_VARIABLE ARCTK_BRANCH)
string(REGEX REPLACE "\n$" "" ARCTK_BRANCH "${ARCTK_BRANCH}")
set(ARCTK_BRANCH ${ARCTK_BRANCH})
message("arctk branch: '${ARCTK_BRANCH}'.")

#   -- Patch --
execute_process(COMMAND git rev-list --count HEAD OUTPUT_VARIABLE ARCTK_PATCH)
string(REGEX REPLACE "\n$" "" ARCTK_PATCH "${ARCTK_PATCH}")
set(ARCTK_PATCH ${ARCTK_PATCH})
message("arctk patch: '${ARCTK_PATCH}'.")

#   -- Hash --
execute_process(COMMAND git rev-parse --short HEAD OUTPUT_VARIABLE ARCTK_HASH)
string(REGEX REPLACE "\n$" "" ARCTK_HASH "${ARCTK_HASH}")
set(ARCTK_HASH ${ARCTK_HASH})
message("arctk hash: '${ARCTK_HASH}'.")

#   -- Type --
set(ARCTK_TYPE ${CMAKE_BUILD_TYPE})
message("arctk type: '${ARCTK_TYPE}'.")

#   -- Compiler --
set(ARCTK_COMPILER ${CMAKE_CXX_COMPILER_ID})
message("arctk compiler: '${ARCTK_COMPILER}'.")

#   -- Directory --
set(ARCTK_DIR ${CMAKE_SOURCE_DIR})
message("arctk directory: '${ARCTK_DIR}'.")


#   == DIRECTORIES ==
#   -- Output --
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


#   == OPTIONS ==
#   -- Clang-Tidy --
if (CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
endif ()
message("Clang-Tidy: '${CLANG_TIDY}'.")

#   -- Include What You Use --
if (IWYU)
    set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "iwyu")
endif ()
message("IWYU: '${IWYU}'.")

#   -- Doxygen --



#   == CONFIGURATION ==
#   -- Header --
configure_file(${CMAKE_SOURCE_DIR}/res/include/config.hpp.in ${CMAKE_SOURCE_DIR}/include/config.hpp)


#   == SOURCE CODE ==
#   -- Glob Files --
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/include/*.hpp)


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

#   -- Warning --
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
        -Weverything                        \
    ")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}     \
        -Wabi                                   \
        -Waddress                               \
        -Waggregate-return                      \
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
        -Wswitch-default                        \
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
        -Wunknown-pragmas                       \
        -Wunreachable-code                      \
        -Wunsafe-loop-optimizations             \
        -Wunused                                \
        -Wunused-but-set-parameter              \
        -Wunused-but-set-variable               \
        -Wunused-const-variable                 \
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
    message(FATAL_ERROR "Warning flags are not defined for compiler type: '${CMAKE_CXX_COMPILER_ID}'.")
endif ()


#   == TARGETS ==
#   -- Libraries --
add_library(arctk STATIC ${SOURCE_FILES} ${HEADER_FILES})


#   == MODULES ==
#   -- Core --
if (NOT DEFINED ARCTK_MOD_CORE)
    set(ARCTK_MOD_CORE OFF)
endif ()
message("Module core: '${ARCTK_MOD_CORE}'.")
if (ARCTK_CORE)
    #   -- Macros --
    target_compile_definitions(arctk PRIVATE ARCTK_MOD_CORE)
endif ()


#   == INCLUDES ==
#   -- Local --
target_include_directories(arctk PRIVATE ${CMAKE_SOURCE_DIR}/include)


#   == INSTALLATION ==
#   -- Headers --
install(DIRECTORY ./include/arctk/ DESTINATION include/arctk FILES_MATCHING PATTERN "*.hpp")

#   -- Library --
install(TARGETS arctk EXPORT arctk LIBRARY DESTINATION lib ARCHIVE DESTINATION lib INCLUDES DESTINATION include)
