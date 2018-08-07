//  == VERSION ==
#version 330 core



//  == IN/OUTPUT ==
//  -- Input --
in vec4 vert_col;

//  -- Output --
out vec4 frag_col;



//  == MAIN ==
void main()
{
    frag_col = vert_col;
}
