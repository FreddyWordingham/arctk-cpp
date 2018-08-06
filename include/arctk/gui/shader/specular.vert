R""(
//  == VERSION ==
#version 330 core



//  == LINKING ==
//  -- Layout --
layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 norm;

//  -- Uniforms --
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;



//  == IN/OUTPUT ==
//  -- Output --
out vec3 vert_pos;
out vec3 vert_norm;



//  == MAIN ==
void main()
{
    vert_pos  = vec3(model * vec4(pos, 1.0));
    vert_norm = mat3(transpose(inverse(model))) * norm;

    gl_Position = proj * view * vec4(vert_pos, 1.0);
}
)""
