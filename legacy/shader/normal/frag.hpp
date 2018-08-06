/**
 *  @file   arctk/shader/normal/frag.hpp
 *  @date   06/08/2018
 *  @author Freddy Wordingham
 *
 *  Normal fragment subshader source code.
 */



//  == GUARD ==
#ifndef ARCTK_SHADER_NORMAL_FRAG_HPP
#define ARCTK_SHADER_NORMAL_FRAG_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace shader //! shader namespace
    {
        namespace normal //! normal shader namespace
        {



            //  == CONSTANTS ==
            //  -- Source --
            static const char* frag = R"(
                //  == VERSION ==
                #version 330 core



                //  == IN/OUTPUT ==
                //  -- Input --
                in vec4 geom_col;

                //  -- Output --
                out vec4 frag_col;



                //  == MAIN ==
                void main()
                {
                    frag_col = geom_col;
                }
            )"; //!< Normal fragment subshader source code.



        } // namespace normal
    }     // namespace shader
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SHADER_NORMAL_FRAG_HPP
