#   == UTILITY ==
#   -- List --
arctk_list_source() {
    cd $ARCTK_DIR >/dev/null

    find . -name "*.cpp"
    find . -name "*.hpp"

    cd - >/dev/null
}

arctk_search() {
    if [ "$#" != "1" ]; then
        printf "Error! Unable to search arctk files.\n"
        printf "Search requires a single regex string.\n"

        return
    fi

    cd $ARCTK_DIR/include/arctk >/dev/null

    grep -r "$1" .

    cd - >/dev/null
}

printf "arctk utility bash functions loaded.\n"
