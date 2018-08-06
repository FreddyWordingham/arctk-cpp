/**
 *  @file   arctk/shader/specular/vert.hpp
 *  @date   06/08/2018
 *  @author Freddy Wordingham
 *
 *  Specular vertex subshader source code.
 */



//  == GUARD ==
#ifndef ARCTK_SHADER_SPECULAR_VERT_HPP
#define ARCTK_SHADER_SPECULAR_VERT_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace shader //! shader namespace
    {
        namespace specular //! specular shader namespace
        {



            //  == CONSTANTS ==
            //  -- Source --
            static const char* vert = R"(
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
            )"; //!< Specular vertex subshader source code.



        } // namespace specular
    }     // namespace shader
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SHADER_SPECULAR_VERT_HPP
