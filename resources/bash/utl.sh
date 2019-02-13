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


#   -- List --
arctk.list()
{
    cd $ARCTK_DIR > /dev/null

    find . -name "*.cpp"
    find . -name "*.hpp"
    find . -name "*.inl"

    cd - > /dev/null
}


#   -- Installation --
arctk.install()
{
    printf "\n" >> ~/.bash_profile
    printf "#   == ARCTK ==\n" >> ~/.bash_profile
    printf "export ARCTK_DIR=\"$PROJECTS_DIR/arctk\"\n" >> ~/.bash_profile
    printf "source $ARCTK_DIR/resources/bash/vcs.sh\n" >> ~/.bash_profile
    printf "source $ARCTK_DIR/resources/bash/build.sh\n" >> ~/.bash_profile
    printf "source $ARCTK_DIR/resources/bash/utl.sh\n" >> ~/.bash_profile
    printf "source $ARCTK_DIR/resources/bash/templates.sh\n" >> ~/.bash_profile
    printf ". $ARCTK_DIR/.build\n" >> ~/.bash_profile
}


#   -- VSCode --
arctk.extension()
{
    cp -r $ARCTK_DIR/resources/vscode/arctk-extension ~/.vscode/extensions/arctk-extension
}
