R""(
//  == VERSION ==
#version 330 core



//  == CONSTANTS ==
//  -- Lighting --
const float amb_pow  = 0.1;
const float spec_pow = 0.5;



//  == LINKING ==
//  -- Uniforms --
uniform vec4 col;
uniform vec3 cam_pos;
uniform vec3 sun_col = vec3(1.0, 1.0, 1.0);
uniform vec3 sun_pos = vec3(3.0, 4.0, 5.0);



//  == IN/OUTPUT ==
//  -- Input --
in vec3 vert_norm;
in vec3 vert_pos;

//  -- Output --
out vec4 frag_col;



//  == MAIN ==
void main()
{
    vec4 ambient = amb_pow * vec4(sun_col, 1.0);

    vec3  vert_norm = normalize(vert_norm);
    vec3  light_dir = normalize(sun_pos - vert_pos);
    float diff      = max(dot(vert_norm, light_dir), 0.0);
    vec4  diffuse   = diff * vec4(sun_col, 1.0);

    vec3  view_dir    = normalize(cam_pos - vert_pos);
    vec3  reflect_dir = reflect(-light_dir, vert_norm);
    float spec        = pow(max(dot(view_dir, reflect_dir), 0.0), 16);
    vec4  specular    = spec_pow * spec * vec4(sun_col, 1.0);

    frag_col = (ambient + diffuse + specular) * col;
}
)""
