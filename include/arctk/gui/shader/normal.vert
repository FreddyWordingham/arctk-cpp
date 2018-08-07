//  == VERSION ==
#version 330 core



//  == LINKING ==
//  -- Layout --
layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 norm;



//  == IN/OUTPUT ==
//  -- Output --
out vec3 vert_pos;
out vec3 vert_norm;



//  == MAIN ==
void main()
{
    vert_pos  = pos;
    vert_norm = norm;
}
