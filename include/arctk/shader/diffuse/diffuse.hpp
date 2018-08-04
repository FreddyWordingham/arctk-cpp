/**
 *  @file   arctk/shader/diffuse.frag
 *  @date   04/08/2018
 *  @author Freddy Wordingham
 *
 *  Diffuse lighting shader subshader source code.
 */



std::string vert = R"(
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
)";

std::string frag = R"(
//  == VERSION ==
#version 330 core



//  == SETTINGS ==
//  -- Light Properties --
const float light_pow = 5.0;
const float amb_pow   = 0.1;
uniform vec3 sun_pos;



//  == IN/OUTPUT ==
//  -- Input --
in vec4 vert_col;
in vec3 cam_space_norm;
in vec3  cam_space_light_dir;
in float dist;

//  -- Output --
out vec4 frag_col;



//  == MAIN ==
void main()
{
    float cos_theta = clamp(dot(cam_space_norm, cam_space_light_dir), 0.0, 1.0);

    frag_col = vert_col;

    frag_col.xyz *= (amb_pow + ((light_pow * cos_theta) / (dist * dist)));
}
)";
