#   == TEMPLATES ==
#   -- Class --
arctk.class()
{
    cd $ARCTK_DIR/resources/templates/class > /dev/null

    python3 -B gen.py "$@"

    cd - > /dev/null
}


#   -- Structure --
arctk.structure()
{
    cd $ARCTK_DIR/resources/templates/structure > /dev/null

    python3 -B gen.py "$@"

    cd - > /dev/null
}


#   -- Functions --
arctk.functions()
{
    cd $ARCTK_DIR/resources/templates/functions > /dev/null

    python3 -B gen.py "$@"

    cd - > /dev/null
}


#   -- Constants --
arctk.constants()
{
    cd $ARCTK_DIR/resources/templates/constants > /dev/null

    python3 -B gen.py "$@"

    cd - > /dev/null
}
