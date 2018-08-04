/**
 *  @file   arctk/shader/diffuse.frag
 *  @date   04/08/2018
 *  @author Freddy Wordingham
 *
 *  Diffuse lighting fragment shader.
 */


std::string diffuse = R"(
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
