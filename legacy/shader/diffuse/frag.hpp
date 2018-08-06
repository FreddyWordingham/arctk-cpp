/**
 *  @file   arctk/shader/diffuse/frag.hpp
 *  @date   04/08/2018
 *  @author Freddy Wordingham
 *
 *  Diffuse lighting fragment subshader source code.
 */



//  == GUARD ==
#ifndef ARCTK_SHADER_DIFFUSE_FRAG_HPP
#define ARCTK_SHADER_DIFFUSE_FRAG_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace shader //! shader namespace
    {
        namespace diffuse //! diffuse shader namespace
        {



            //  == CONSTANTS ==
            //  -- Source --
            static const char* frag = R"(
                //  == VERSION ==
                #version 330 core



                //  == LINKING ==
                //  -- Uniforms --
                uniform float light_pow   = 10.0;
                uniform float ambient_pow = 0.1;
                uniform vec3  sun_pos     = vec3(6.0, 8.0, 10.0);



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

                    frag_col.xyz *= (ambient_pow + ((light_pow * cos_theta) / (dist * dist)));
                }
            )"; //!< Diffuse fragment subshader source code.



        } // namespace diffuse
    }     // namespace shader
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SHADER_DIFFUSE_FRAG_HPP
