#   == TEMPLATES ==
#   -- Class --
arctk.class()
{
    cd $ARCTK_DIR/resources/templates/class

    python3 -B gen.py "$@"

    cd -
}


#   -- Structure --
arctk.structure()
{
    cd $ARCTK_DIR/resources/templates/structure

    python3 -B gen.py "$@"

    cd -
}


#   -- Functions --
arctk.functions()
{
    cd $ARCTK_DIR/resources/templates/functions

    python3 -B gen.py "$@"

    cd -
}


#   -- Constants --
arctk.constants()
{
    cd $ARCTK_DIR/resources/templates/constants

    python3 -B gen.py "$@"

    cd -
}
