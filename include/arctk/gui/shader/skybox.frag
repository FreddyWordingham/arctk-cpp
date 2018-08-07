R""(
//  == VERSION ==
#version 330 core



//  == LINKING ==
//  -- Uniforms --
uniform samplerCube skybox;



//  == IN/OUTPUT ==
//  -- Input --
in vec3 texture_coor;

//  -- Output --
out vec4 frag_colour;



//  == MAIN ==
void main()
{
    frag_colour = texture(skybox, texture_coor);
}
)""
