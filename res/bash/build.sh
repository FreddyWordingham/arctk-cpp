#   == BUILDING ==
#   -- Clean --
arctk_clean()
{
    arctk_uninstall;

    cd $ARCTK_DIR > /dev/null;

    rm -r bin;
    rm -r build;

    cd - > /dev/null;
}
