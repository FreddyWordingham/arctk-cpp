#   == TEMPLATES ==
#   -- Class --
arctk.class()
{
    cd $ARCTK_DIR/resources/templates/class > /dev/null

    python3 -B gen.py "$@"

    cd - > /dev/null
}
