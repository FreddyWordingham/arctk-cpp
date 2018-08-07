/**
 *  @file   arctk/gui/shader/ambient.hpp
 *  @date   06/08/2018
 *  @author Freddy Wordingham
 *
 *  Ambient lighting shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_AMBIENT_HPP
#define ARCTK_GUI_SHADER_AMBIENT_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/gui/shader.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace shader //! shader namespace
        {



            //  == CONSTANTS ==
            //  -- Shader Source Code --
            static const char* AMBIENT_SOURCE_VERT =
#include <arctk/gui/shader/ambient.vert>
              ; //!< Ambient vertex subshader source code.
            static const char* AMBIENT_SOURCE_FRAG =
#include <arctk/gui/shader/ambient.frag>
              ; //!< Ambient fragment subshader source code.



            //  == CLASS ==
            /**
             *  Shader using a ambient lighting source.
             */
            class Ambient : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms Handles --
                const GLint _model; //!< Model matrix uniform handle.
                const GLint _view;  //!< View matrix uniform handle.
                const GLint _proj;  //!< Projection matrix uniform handle.
                const GLint _col;   //!< Colour uniform handle.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Ambient() noexcept;


                //  == METHODS ==
              public:
                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept override;
                inline void render(const Actor& act_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Ambient::Ambient() noexcept
              : Shader(AMBIENT_SOURCE_VERT, AMBIENT_SOURCE_FRAG)
            {
            }



            //  == METHODS ==
            //  -- Rendering --            }



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_AMBIENT_HPP
