R""(
//  == VERSION ==
#version 330 core



//  == LINKING ==
//  -- Layout --
layout(location = 0) in vec3 pos;

//  -- Uniforms --
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
uniform vec4 col;



//  == IN/OUTPUT ==
//  -- Output --
out vec4 vert_col;



//  == MAIN ==
void main()
{
    gl_Position = proj * view * model * vec4(pos, 1.0);

    vert_col = col;
}
)""
