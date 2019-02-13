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
    cd $ARCTK_DIR/bui

    scan-build -analyze-headers --force-analyze-debug-code --view make -j 8

    local cmake_compile_status=$?

    cd

    return ($cmake_compile_status)
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


#   -- Documentation --
arctk.doc()
{
    cd $ARCTK_DIR/build > /dev/null

    make doc

    mv docs/ ..

    open ../docs/html/index.html

    cd - > /dev/null
}


#   -- Coverage --
arctk.cover.gen()
{
    cd $ARCTK_DIR/bin/test > /dev/null

    rm $ARCTK_DIR/build/coverage/*

    for test in *; do
        if [ -f "$test" ]; then
            printf "Generating coverage report for test: $test\n"
            ./$test > /dev/null
            llvm-profdata merge -sparse default.profraw -o $ARCTK_DIR/build/coverage/$test.profdata
            rm default.profraw
        fi
    done

    list=$(ls $ARCTK_DIR/build/coverage/*.profdata)
    llvm-profdata merge -sparse $list -o $ARCTK_DIR/build/coverage/COMPLETE.profdata

    cd - > /dev/null
}

arctk.cover.view()
{
    cd $ARCTK_DIR/bin/test > /dev/null

    if [ "$#" == "0" ]; then
        for test in *; do
            if [ -f "$test" ]; then
                filename=${test#unit_}
                filename=${filename%_test}
                filename=${filename//_//}
                # llvm-cov report ./$test -instr-profile=$ARCTK_DIR/build/coverage/$test.profdata
                printf "$test\t"
                llvm-cov report ./$test -instr-profile=$ARCTK_DIR/build/coverage/$test.profdata | grep $filename | awk '{print $4}' | tr "\n" "\t"
                printf "\n"
            fi
        done
    elif [ "$#" == "1" ]; then
       llvm-cov report ./$1 -instr-profile=$ARCTK_DIR/build/coverage/$1.profdata
        # llvm-cov report ./$1 -instr-profile=$ARCTK_DIR/build/coverage/COMPLETE.profdata
    else
       llvm-cov show ./$1 -instr-profile=$ARCTK_DIR/build/coverage/$1.profdata -format=text -Xdemangler c++filt -Xdemangler -n -show-line-counts-or-regions | bcat
        # llvm-cov show ./$1 -instr-profile=$ARCTK_DIR/build/coverage/COMPLETE.profdata -format=html -Xdemangler c++filt -Xdemangler -n -show-line-counts-or-regions | bcat
    fi
 
    cd - > /dev/null
}

arctk.cover.view.tab()
{
    arctk.cover.view | column -t
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
