#   == BUILDING ==
#   -- Clean --
arctk_clean()
{
    arctk_uninstall;

    cd $ARCTK_DIR > /dev/null;

    rm -r bin;
    rm -r build;

    cd - > /dev/null;
}


#   -- Build --
arctk_build()
{
    if [ "$#" != "6" ]; then
        printf "Error! Incorrect number of arguments.\n";
        printf "arctk_build <build_type> <c_compiler> <cxx_compiler> <clang-tidy> <iwyu> <core>\n";

        return;
    fi

    arctk_clean;

    mkdir $ARCTK_DIR/build;

    cd $ARCTK_DIR/build > /dev/null;

    cmake -j 4 -DCMAKE_EXPORT_COMPILE_COMMANDS=on   \
        -DCMAKE_BUILD_TYPE=$1                       \
        -DCMAKE_C_COMPILER=$2                       \
        -DCMAKE_CXX_COMPILER=$3                     \
        -DCLANG_TIDY=$4                             \
        -DIWYU=$5                                   \
        -DDOCUMENT=$6                               \
        -DARCTK_MOD_CORE=$7                         \
        ..

    local cmake_build_status=$?;

    cd - > /dev/null;

    return $cmake_build_status;
}


#   -- Make --
arctk_make()
{
    cd $ARCTK_DIR/build > /dev/null;

    scan-build -analyze-headers --force-analyze-debug-code --view make -j 8;

    local cmake_compile_status=$?;

    cd - > /dev/null;

    return $cmake_compile_status;
}


#   -- Installation --
arctk_install()
{
    cd $ARCTK_DIR/build > /dev/null;

    arctk_uninstall;

    make install;

    cd - > /dev/null;
}

arctk_uninstall()
{
    rm /usr/local/lib/libarctk.a;
    rm -r /usr/local/include/arctk/;
}



printf "arctk build bash functions loaded.\n";
