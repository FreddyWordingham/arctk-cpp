#   == BUILDING ==
#   -- Clean --
arctk.clean()
{
    arctk.uninstall

    cd $ARCTK_DIR >/dev/null

    rm -r bin
    rm -r build
    rm -r doc
    rm include/arctk/config/*

    cd - >/dev/null
}


#   -- Build --
arctk.build()
{
    if [ "$#" == "0" ]; then
        if [ -z "$ARCTK_BUILD_ARGS" ]; then
            printf "Error! ARCTK_BUILD_ARGS are not set!\n"

            return
        fi

        arctk.build $ARCTK_BUILD_ARGS

        return
    fi

    if [ "$#" != "5" ]; then
        printf "Error! Incorrect number of arguments. ($#)\n"
        printf "arctk_build <build_type> <C compiler> <C++ compiler> <unit testing> <clang-tidy>\n"

        return
    fi

    ARCTK_BUILD_ARGS="$1 $2 $3 $4 $5"
    printf "export ARCTK_BUILD_ARGS='$ARCTK_BUILD_ARGS'" > $ARCTK_DIR/.build

    arctk.clean

    mkdir $ARCTK_DIR/build
    cd $ARCTK_DIR/build > /dev/null

    cmake -j 8 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
        -DCMAKE_BUILD_TYPE=$1 \
        -DCMAKE_C_COMPILER=$2 \
        -DCMAKE_CXX_COMPILER=$3 \
        -DUNIT_TESTING=$4 \
        -DCLANG_TIDY=$5 \
        ..

    local cmake_build_status=$?

    cd - > /dev/null

    return $cmake_build_status
}


#   -- Make --
arctk.make()
{
    cd $ARCTK_DIR/build > /dev/null

    scan-build -analyze-headers --force-analyze-debug-code --view make -j 8

    local cmake_compile_status=$?

    cd - > /dev/null

    return $cmake_compile_status
}


#   -- Testing --
arctk.test()
{
    cd $ARCTK_DIR/build > /dev/null

    make test

    cd - > /dev/null
}


#   -- Coverage --
arctk.cover()
{
    rm -r $ARCTK_DIR/temp/coverage
    mkdir $ARCTK_DIR/temp
    mkdir $ARCTK_DIR/temp/coverage

    cd $ARCTK_DIR/temp/coverage > /dev/null

    find ../../build/CMakeFiles -name "*.gcda" -exec mv {} . \;
    find ../../build/CMakeFiles -name "*.gcno" -exec mv {} . \;

    lcov --capture --directory . --output-file coverage.info

    genhtml coverage.info --output-directory $ARCTK_DIR/docs/coverage

    cd - > /dev/null
}


#   -- Installation --
arctk.install()
{
    cd $ARCTK_DIR/build > /dev/null

    arctk.uninstall
    make install

    cd - > /dev/null
}

arctk.uninstall()
{
    rm /usr/local/lib/libarctk.a
    rm -r /usr/local/include/arctk/
}
