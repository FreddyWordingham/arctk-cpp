/**
 *  @file   arctk/gui/shader.hpp
 *  @date   04/06/2018
 *  @author Freddy Wordingham
 *
 *  Graphical shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_HPP
#define ARCTK_GUI_SHADER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_GUI



//  == IMPORTS ==



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical user interface namespace
    {



        //  == CLASS ==
        /**
         *  Graphial shader class used for rendering actors.
         */
        class Shader
        {
            //  == FIELDS ==
          private:
            //  -- Handle --
            const GLuint _handle; //!< Handle of the shader.


            //  == INSTANTIATION ==
          public:
            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION --
        //  -- Constructors --



        //  == METHODS ==
        //  -- Getters --



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_HPP
