#   == VERSION CONTROL ==
#   -- Git --
arctk_commit() {
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

arctk_amend() {
    if [ "$#" != "1" ]; then
        printf "Error! Unable to amend commit.\n"
        printf "Amend requires a single commit message string.\n"

        return
    fi

    cd $ARCTK_DIR >/dev/null

    git commit --amend -m "$1"

    cd - >/dev/null
}

arctk_push() {
    cd $ARCTK_DIR >/dev/null

    arctk_make_doc
    if [ "$?" != "0" ]; then
        printf "Error! Unable to push.\n"
        printf "Failed to generate documentation.\n"

        return
    fi

    rm -r $ARCTK_DIR/docs
    mv $ARCTK_DIR/build/docs/html $ARCTK_DIR/docs

    arctk_clean

    arctk_commit "Cleaned build files and updated documentation."

    git push

    cd - >/dev/null
}

arctk_push_no_doc() {
    cd $ARCTK_DIR >/dev/null

    arctk_clean

    arctk_commit "Cleaned build files."

    git push

    cd - >/dev/null
}

arctk_update() {
    cd $ARCTK_DIR >/dev/null

    git pull origin master

    arctk_build $ARCTK_BUILD_ARGS

    arctk_install

    cd - >/dev/null
}

printf "arctk vcs bash functions loaded.\n"
