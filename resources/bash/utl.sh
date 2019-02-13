#   == UTILITY ==
#   -- Search --
arctk.search()
{
    if [ "$#" != "1" ]; then
        printf "Error! Unable to search Arctk files.\n"
        printf "Search requires a single regex string.\n"

        return
    fi

    cd $ARCTK_DIR

    grep -r "$1" .

    cd -
}

arctk.search.lib()
{
    if [ "$#" != "1" ]; then
        printf "Error! Unable to search Arctk library files.\n"
        printf "Search requires a single regex string.\n"

        return
    fi

    cd $ARCTK_DIR/include/arctk

    grep -r "$1" .

    cd -
}

arctk.list()
{
    printf "\t== Declerations ==\n"
    arctk.list.dec

    printf "\n\t== Implementation ==\n"
    arctk.list.impl

    printf "\n\t== Testing ==\n"
    arctk.list.test

    printf "\n\t== Benchmark ==\n"
    arctk.list.bench

}

arctk.list.dec()
{
    cd $ARCTK_DIR/include/arctk

    find . -name "*.hpp"

    cd -
}

arctk.list.impl()
{
    cd $ARCTK_DIR/include/arctk

    find . -name "*.inl"

    cd -
}

arctk.list.test()
{
    cd $ARCTK_DIR/testing

    find . -name "*.cpp"

    cd -
}

arctk.list.bench()
{
    cd $ARCTK_DIR/benchmark

    find . -name "*.cpp"

    cd -
}


#   -- Installation --
arctk.install.scripts()
{
    printf "\n"                                                 >> ~/.bash_profile
    printf "#   == ARCTK ==\n"                                  >> ~/.bash_profile
    printf "export ARCTK_DIR=\"$PROJECTS_DIR/arctk\"\n"         >> ~/.bash_profile
    printf "source $ARCTK_DIR/resources/bash/vcs.sh\n"          >> ~/.bash_profile
    printf "source $ARCTK_DIR/resources/bash/build.sh\n"        >> ~/.bash_profile
    printf "source $ARCTK_DIR/resources/bash/utl.sh\n"          >> ~/.bash_profile
    printf "source $ARCTK_DIR/resources/bash/templates.sh\n"    >> ~/.bash_profile
    printf ". $ARCTK_DIR/.build\n"                              >> ~/.bash_profile
}


#   -- VSCode --
arctk.extension()
{
    rm -r ~/.vscode/extensions/arctk-extension
    cp -r $ARCTK_DIR/resources/vscode/arctk-extension ~/.vscode/extensions/arctk-extension
}
