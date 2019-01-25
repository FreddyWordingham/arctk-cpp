#   == BUILDING ==
#   -- Clean --
arctk.clean()
{
    arctk.uninstall

    cd $ARCTK_DIR >/dev/null

    rm -r bin
    rm -r build
    rm -r doc
    rm include/config/*

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

arctk.cover.gen()
{
    arctk.clean

    arctk.build cover clang clang++ true false
    arctk.make

    cd $ARCTK_DIR/bin/test > /dev/null

    for test in *; do
        printf "Generating coverage data of $test\n"

        LLVM_PROFILE_FILE="./coverage/$test.profraw" ./"$test"
    done

    llvm-profdata merge coverage/*.profraw -o coverage/complete.profdata

    cd - > /dev/null
}

arctk.cover.view()
{
    if [[ ("$#" != "1") && ("$#" != "2") ]]; then
        printf "Error! Incorrect number of arguments. ($#)\n"
        printf "arctk_build <text|html> (unit_test_name)\n"

        return
    fi

    cd $ARCTK_DIR/bin/test > /dev/null

    if [ "$#" == "1" ]; then
        for test in *; do
            if [ -f "$test" ]; then
                output="$(llvm-cov report $test -instr-profile=coverage/complete.profdata -format=$1 | tail -1 | awk '{print $4}')"
                printf "%s" "$output"
                printf "\t$test\n"
            fi
        done
    else
        llvm-cov report $2 -instr-profile=coverage/complete.profdata -format=$1
    fi

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
