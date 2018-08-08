/**
 *  @file   arctk/gui/lens/orthographic.hpp
 *  @date   08/08/2018
 *  @author Freddy Wordingham
 *
 *  Perspective camera lens.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_LENS_ORTHOGRAPHIC_HPP
#define ARCTK_GUI_LENS_ORTHOGRAPHIC_HPP



//  == IMPORTS ==
//  -- Graphical --
#include <glm/glm.hpp>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/gui/lens.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace lens //! lens namespace
        {



            //  == CLASS ==
            /**
             *  Orthographic lens.
             */
            class Orthographic : public Lens
            {
                //  == FIELDS ==
              private:
                //  -- View --
                const glm::vec3 _min;
                const glm::vec3 _max;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Orthographic(float width_, float float_) noexcept;


                //  == METHODS ==
              private:
                //  -- Updating --
                inline void update_view() noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct an orthographic lens with a given view width and height.
             *
             *  @param  width_  Width of the viewport.
             *  @param  height_ Height of the viewport.
             *
             *  @pre    width_ must be positive.
             *  @pre    height_ must be positive.
             */
            inline Orthographic::Orthographic(const float width_, const float height_) noexcept
              : _width(width_)
              , _height(height_)
            {
                PRE(width_ > 0);
                PRE(height_ > 0);

                update_view();
            }


            //  == METHODS ==
            //  -- Updating --
            /**
             *  Update the orthographic matrix of the lens.
             */
            inline void Orthographic::update_view() noexcept
            {
                //                _proj = glm::ortho(0.0f, _width, 0.0f, _height);
                _proj = glm::ortho(-10.0f, +10.0f, +10.0f, -10.0f, -10.0f, 20.0f);
            }



        } // namespace lens
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_LENS_ORTHOGRAPHIC_HPP
