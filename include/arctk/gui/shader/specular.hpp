/**
 *  @file   arctk/gui/camera/orbit.hpp
 *  @date   06/08/2018
 *  @author Freddy Wordingham
 *
 *  Specular shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_SPECULAR_HPP
#define ARCTK_GUI_SHADER_SPECULAR_HPP



//  == IMPORTS ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace shader //! shader namespace
        {



            //  == CONSTANTS ==
            //  -- Shader Source Code --
            const char* SPECULAR_SOURCE_FRAG = R"(
                //  == VERSION ==
                #version 330 core



                //  == CONSTANTS ==
                //  -- Lighting --
                const float amb_pow  = 0.1;
                const float spec_pow = 0.5;



                //  == LINKING ==
                //  -- Uniforms --
                uniform vec3 view_pos;
                uniform vec4 col;
                uniform vec4 sun_col = vec4(1.0, 1.0, 1.0, 1.0);
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
                    vec4 ambient = amb_pow * sun_col;

                    vec3  vert_norm = normalize(vert_norm);
                    vec3  light_dir = normalize(sun_pos - vert_pos);
                    float diff      = max(dot(vert_norm, light_dir), 0.0);
                    vec4  diffuse   = diff * sun_col;

                    vec3  view_dir    = normalize(view_pos - vert_pos);
                    vec3  reflect_dir = reflect(-light_dir, vert_norm);
                    float spec        = pow(max(dot(view_dir, reflect_dir), 0.0), 16);
                    vec4  specular    = spec_pow * spec * sun_col;

                    frag_col = (ambient + diffuse + specular) * col;
                }
            )"; //!< Specular fragment subshader source code.



            //  == CLASS ==
            /**
             *  Shader using a specular lighting source.
             */
            class Specular : public Shader
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Specular() noexcept;


                //  == METHODS ==
              public:
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Specular::Specular() noexcept
              : Shader(SPECULAR_SOURCE_VERT, SPECULAR_SOURCE_FRAG)
            {
            }



            //  == METHODS ==



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_SPECULAR_HPP
