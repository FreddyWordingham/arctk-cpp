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
uniform vec4 col;
uniform vec3 sun_pos;



//  == IN/OUTPUT ==
//  -- Output --
out vec4 vert_col;
out vec3 cam_space_norm;
out vec3  cam_space_light_dir;
out float dist;



//  == MAIN ==
void main()
{
    gl_Position = proj * view * model * vec4(pos, 1.0);

    vert_col = col;

    cam_space_light_dir = normalize((view * vec4(sun_pos, 1.0)).xyz - (view * vec4(pos, 1.0)).xyz);
    cam_space_norm      = normalize((view * vec4(norm, 0.0)).xyz);

    dist = length(sun_pos - pos);
}
)""
