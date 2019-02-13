#   == UTILITY ==
#   -- Search --
arctk.search()
{
    if [ "$#" != "1" ]; then
    echo "Error! Unable to search Arctk files."
    echo "Search requires a single regex string."

        return
    fi

    cd $ARCTK_DIR

    grep -r "$1" .

    cd - > /dev/null
}

arctk.search.lib()
{
    if [ "$#" != "1" ]; then
    echo "Error! Unable to search Arctk library files."
    echo "Search requires a single regex string."

        return
    fi

    cd $ARCTK_DIR/include/arctk

    grep -r "$1" .

    cd - > /dev/null
}

arctk.list()
{
    echo "\t== Declerations =="
    arctk.list.dec

    echo "\n\t== Implementation =="
    arctk.list.impl

    echo "\n\t== Testing =="
    arctk.list.test

    echo "\n\t== Benchmark =="
    arctk.list.bench

}

arctk.list.dec()
{
    cd $ARCTK_DIR/include/arctk

    find . -name "*.hpp"

    cd - > /dev/null
}

arctk.list.impl()
{
    cd $ARCTK_DIR/include/arctk

    find . -name "*.inl"

    cd - > /dev/null
}

arctk.list.test()
{
    cd $ARCTK_DIR/testing

    find . -name "*.cpp"

    cd - > /dev/null
}

arctk.list.bench()
{
    cd $ARCTK_DIR/benchmark

    find . -name "*.cpp"

    cd - > /dev/null
}


#   -- Installation --
arctk.install.scripts()
{
    echo ""                                               >> ~/.bash_profile
    echo "#   == ARCTK =="                                >> ~/.bash_profile
    echo "export ARCTK_DIR=\"$PROJECTS_DIR/arctk\""       >> ~/.bash_profile
    echo "source $ARCTK_DIR/resources/bash/vcs.sh"        >> ~/.bash_profile
    echo "source $ARCTK_DIR/resources/bash/build.sh"      >> ~/.bash_profile
    echo "source $ARCTK_DIR/resources/bash/utl.sh"        >> ~/.bash_profile
    echo "source $ARCTK_DIR/resources/bash/templates.sh"  >> ~/.bash_profile
    echo ". $ARCTK_DIR/.build"                            >> ~/.bash_profile
}


#   -- VSCode --
arctk.extension()
{
    rm -r ~/.vscode/extensions/arctk-extension
    cp -r $ARCTK_DIR/resources/vscode/arctk-extension ~/.vscode/extensions/arctk-extension
}
