#   == UTILITY ==
arctk_list_source()
{
    cd $ARCTK_DIR > /dev/null;

    find . -name "*.cpp"

    cd - > /dev/null;
}



printf "arctk utility bash functions loaded.\n";
