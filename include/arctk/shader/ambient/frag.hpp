/**
 *  @file   arctk/shader/ambient/frag.hpp
 *  @date   05/08/2018
 *  @author Freddy Wordingham
 *
 *  Ambient lighting fragment subshader source code.
 */



//  == GUARD ==
#ifndef ARCTK_SHADER_AMBIENT_FRAG_HPP
#define ARCTK_SHADER_AMBIENT_FRAG_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace shader //! shader namespace
    {
        namespace ambient //! ambient shader namespace
        {



            //  == CONSTANTS ==
            //  -- Source --
            static const char* frag = R"(
                //  == VERSION ==
                #version 330 core



                //  == IN/OUTPUT ==
                //  -- Input --
                in vec4 vert_col;

                //  -- Output --
                out vec4 frag_col;



                //  == MAIN ==
                void main()
                {
                    frag_col = vert_col;
                }
            )"; //!< Diffuse fragment subshader source code.



        } // namespace ambient
    }     // namespace shader
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SHADER_AMBIENT_FRAG_HPP
