#   == VERSION CONTROL ==
#   -- Git --
arctk.commit()
{
    if [ "$#" != "1" ]; then
        echo "Error! Unable to commit files."
        echo "Commit requires a single commit message string."

        return
    fi

    cd $ARCTK_DIR

    git add .
    git commit -m "$1"

    cd - > /dev/null
}

arctk.amend()
{
    if [ "$#" != "1" ]; then
        echo "Error! Unable to amend commit."
        echo "Amend requires a single commit message string."

        return
    fi

    cd $ARCTK_DIR

    git commit --amend -m "$1"

    cd - > /dev/null
}

arctk.push()
{
    cd $ARCTK_DIR

    arctk.clean
    arctk.commit "Cleaned build files."

    git push

    cd - > /dev/null
}


#   -- Updating --
arctk.update()
{
    cd $ARCTK_DIR

    git pull origin master

    arctk.build $ARCTK_BUILD_ARGS
    arctk.install

    cd - > /dev/null
}
