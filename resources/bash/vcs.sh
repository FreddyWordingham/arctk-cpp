#   == VERSION CONTROL ==
#   -- Git --
arctk.commit()
{
    if [ "$#" != "1" ]; then
        printf "Error! Unable to commit files.\n"
        printf "Commit requires a single commit message string.\n"

        return
    fi

    cd $ARCTK_DIR >/dev/null

    git add .
    git commit -m "$1"

    cd - >/dev/null
}

arctk.amend()
{
    if [ "$#" != "1" ]; then
        printf "Error! Unable to amend commit.\n"
        printf "Amend requires a single commit message string.\n"

        return
    fi

    cd $ARCTK_DIR >/dev/null

    git commit --amend -m "$1"

    cd - >/dev/null
}

arctk.push()
{
    cd $ARCTK_DIR >/dev/null

    arctk.clean
    arctk.commit "Cleaned build files."

    git push

    cd - >/dev/null
}


#   -- Updating --
arctk.update()
{
    cd $ARCTK_DIR >/dev/null

    git pull origin master

    arctk.build $ARCTK_BUILD_ARGS
    arctk.install

    cd - >/dev/null
}



printf "Arctk version control bash functions loaded.\n"
