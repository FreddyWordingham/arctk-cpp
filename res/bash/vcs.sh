#   == VERSION CONTROL ==
#   -- Git --
arctk_commit()
{
    if [ "$#" != "1" ]; then
        printf "Error! Unable to commit files.\n";
        printf "Commit requires a single commit message string.\n";

        return;
    fi

    cd $ARCTK_DIR > /dev/null;

    git add .;
    git commit -m "$1";

    cd - > /dev/null;
}

arctk_push()
{
    cd $ARCTK_DIR > /dev/null;

    arctk_clean;

    git push;

    cd - > /dev/null;
}



printf "arctk vcs bash functions loaded.\n";
