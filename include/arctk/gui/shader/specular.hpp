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
            {
            }



            //  == METHODS ==



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_SPECULAR_HPP
