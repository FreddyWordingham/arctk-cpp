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
