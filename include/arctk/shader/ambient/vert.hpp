/**
 *  @file   arctk/shader/ambient/vert.hpp
 *  @date   05/08/2018
 *  @author Freddy Wordingham
 *
 *  Ambient lighting vertex subshader source code.
 */



//  == GUARD ==
#ifndef ARCTK_SHADER_AMBIENT_VERT_HPP
#define ARCTK_SHADER_AMBIENT_VERT_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace shader //! shader namespace
    {
        namespace ambient //! ambient shader namespace
        {



            //  == CONSTANTS ==
            //  -- Source --
            static const char* vert = R"(
                //  == VERSION ==
                #version 330 core



                //  == LINKING ==
                //  -- Layout --
                layout(location = 0) in vec3 pos;

                //  -- Uniforms --
                uniform mat4 model;
                uniform mat4 view;
                uniform mat4 proj;
                uniform vec4 col;



                //  == IN/OUTPUT ==
                //  -- Output --
                out vec4 vert_col;



                //  == MAIN ==
                void main()
                {
                    gl_Position = proj * view * model * vec4(pos, 1.0);

                    vert_col = col;
                }
            )"; //!< Ambient vertex subshader source code.



        } // namespace ambient
    }     // namespace shader
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SHADER_AMBIENT_VERT_HPP
