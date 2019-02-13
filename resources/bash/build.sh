#   == BUILDING ==
#   -- Clean --
arctk.clean()
{
    rm -r $ARCTK_DIR/build
    rm -r $ARCTK_DIR/bin
    rm -r $ARCTK_DIR/include/arctk/config

    arctk.uninstall
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

    if [ "$#" != "7" ]; then
        printf "Error! Incorrect number of arguments. ($#)\n"
        printf "arctk.build <build_type> <C compiler> <C++ compiler> <unit testing> <benchmark> <clang-tidy> <iwyu> <document>\n"

        return
    fi

    ARCTK_BUILD_ARGS="$1 $2 $3 $4 $5 $6 $7 $8"
    printf "export ARCTK_BUILD_ARGS='$ARCTK_BUILD_ARGS'" > $ARCTK_DIR/.build

    arctk.clean

    mkdir $ARCTK_DIR/build
    cd $ARCTK_DIR/build

    cmake -j 8 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
        -DCMAKE_BUILD_TYPE=$1                     \
        -DCMAKE_C_COMPILER=$2                     \
        -DCMAKE_CXX_COMPILER=$3                   \
        -DUNIT_TESTING=$4                         \
        -DBENCHMARK=$5                            \
        -DCLANG_TIDY=$6                           \
        -DIWYU=$7                                 \
        -DDOCUMENT=$8                             \
        ..

    cd -
}


#   -- Make --
arctk.make()
{
    cd $ARCTK_DIR/build

    scan-build -analyze-headers --force-analyze-debug-code --view make -j 8

    cd -
}


#   -- Testing --
arctk.test()
{
    cd $ARCTK_DIR/build

    for test in $ARCTK_DIR/bin/test/*; do
        if [ -f $test ]; then
            $test
        fi
    done

    cd -
}

arctk.bench()
{
    cd $ARCTK_DIR/build

    for bench in $ARCTK_DIR/bin/bench/*; do
        if [ -f $bench ]; then
            $bench
        fi
    done

    cd -
}


#   -- Documentation --
arctk.doc()
{
    cd $ARCTK_DIR/build

    make doc
    mv docs/ ..
    open ../docs/html/index.html

    cd -
}


#   -- Coverage --
arctk.cover()
{
    cd $ARCTK_DIR

    lcov --capture --directory . --output-file coverage.info
    lcov --remove coverage.info '/usr/*' --output-file coverage.info
    lcov --list coverage.info
    bash <(curl -s https://codecov.io/bash) -t "57886efc-8eca-416f-9e8b-1b0ee825efe5" -f coverage.info || echo "Codecov did not collect coverage reports"

    cd -
}


#   -- Imports --
arctk.import()
{
    cd $ARCTK_DIR > /dev/null

    iwyu_tool.py -p build/compile_commands.json
    # iwyu_tool.py -p build/compile_commands.json -- --no_fwd_decls

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
