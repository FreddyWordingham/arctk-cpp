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

arctk.cover.gen()
{
    cd $ARCTK_DIR/bin/test > /dev/null

    rm -r coverage/ > /dev/null

    for test in *; do
        if [ -f "$test" ]; then
            printf "Generating coverage data of $test\n"

            LLVM_PROFILE_FILE="./coverage/$test.profraw" ./"$test" > /dev/null
        fi
    done

    llvm-profdata merge coverage/*.profraw -o coverage/complete.profdata

    cd - > /dev/null
}

arctk.cover.view()
{
    if [[ "$#" > "2" ]]; then
        printf "Error! Incorrect number of arguments. ($#)\n"
        printf "arctk_build (<unit_test_name> (text|html))\n"

        return
    fi

    cd $ARCTK_DIR/bin/test > /dev/null

    if [ "$#" == "0" ]; then
        for test in *; do
            if [ -f "$test" ]; then
                printf "%s\t$test\n" "$(llvm-cov report $test -instr-profile=coverage/complete.profdata -format=text | tail -1 | awk '{print $4}')"
            fi
        done
    elif [ "$#" == "1" ]; then
        llvm-cov report $1 -instr-profile=coverage/complete.profdata
    else
        if [ "$2" == "text" ]; then
            llvm-cov show $1 -Xdemangler c++filt -Xdemangler -n -instr-profile=coverage/complete.profdata -format=text
        elif [ "$2" == "html" ]; then
            llvm-cov show $1 -Xdemangler c++filt -Xdemangler -n -instr-profile=coverage/complete.profdata -format=html | bcat
        else
            printf "Unknonw render type: $2.\n"
        fi
    fi

    cd - > /dev/null
}

arctk.cover()
{
    cd $ARCTK_DIR/bin/test > /dev/null

    for test in *; do
        if [ -f "$test" ]; then
            rm -r coverage/ > /dev/null

            printf "Generating coverage data of $test\n"
            LLVM_PROFILE_FILE="./coverage/$test.profraw" ./"$test" > /dev/null
            llvm-profdata merge coverage/$test.profraw -o coverage/complete.profdata

            llvm-cov report $test -instr-profile=coverage/complete.profdata -format=text

            printf "*******\n\n\n"
        fi
    done

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
