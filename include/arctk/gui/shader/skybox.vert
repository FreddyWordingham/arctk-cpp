R""(
//  == VERSION ==
#version 330 core



//  == LINKING ==
//  -- Layout --
layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 norm;

//  -- Uniforms --
uniform mat4 proj;
uniform mat4 view;



//  == IN/OUTPUT ==
//  -- Output --
out vec3 texture_coor;



//  == MAIN ==
void main()
{
    gl_Position = (proj * view * vec4(pos, 1.0)).xyww;

    texture_coor = pos;
}
)""
