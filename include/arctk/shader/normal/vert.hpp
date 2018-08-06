/**
 *  @file   arctk/shader/normal/vert.hpp
 *  @date   06/08/2018
 *  @author Freddy Wordingham
 *
 *  Normal vertex subshader source code.
 */



//  == GUARD ==
#ifndef ARCTK_SHADER_NORMAL_VERT_HPP
#define ARCTK_SHADER_NORMAL_VERT_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace shader //! shader namespace
    {
        namespace normal //! normal shader namespace
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



                //  == IN/OUTPUT ==
                //  -- Output --
                out vec3 vert_pos;
                out vec3 vert_norm;



                //  == MAIN ==
                void main()
                {
                    vert_pos  = pos;
                    vert_norm = norm;
                }
            )"; //!< Normal vertex subshader source code.



        } // namespace normal
    }     // namespace shader
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SHADER_NORMAL_VERT_HPP
