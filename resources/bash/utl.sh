#   == UTILITY ==
#   -- Search --
arctk.search()
{
    if [ "$#" != "1" ]; then
        printf "Error! Unable to search Arctk files.\n"
        printf "Search requires a single regex string.\n"

        return
    fi

    cd $ARCTK_DIR/include/arctk >/dev/null

    grep -r "$1" .

    cd - >/dev/null
}


#   -- List --
arctk.list()
{
    cd $ARCTK_DIR >/dev/null

    find . -name "*.cpp"
    find . -name "*.hpp"
    find . -name "*.inl"

    cd - >/dev/null
}


#   -- VSCode --
arctk.extension()
{
    cp -r $ARCTK_DIR/resources/vscode/arctk-extension ~/.vscode/extensions/arctk-extension
}


printf "Arctk utility bash functions loaded.\n"
