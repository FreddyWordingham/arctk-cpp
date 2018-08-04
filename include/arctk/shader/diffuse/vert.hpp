/**
 *  @file   arctk/shader/diffuse/vert.hpp
 *  @date   04/08/2018
 *  @author Freddy Wordingham
 *
 *  Diffuse lighting vertex subshader source code.
 */



//  == GUARD ==
#ifndef ARCTK_SHADER_DIFFUSE_VERT_HPP
#define ARCTK_SHADER_DIFFUSE_VERT_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace shader //! shader namespace
    {
        namespace diffuse //! diffuse shader namespace
        {



            //  == CONSTANTS ==
            //  -- Source --
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



        } // namespace diffuse
    }     // namespace shader
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SHADER_DIFFUSE_VERT_HPP
