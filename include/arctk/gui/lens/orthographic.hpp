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



            //  == CONSTANTS ==
            //  -- Culling --
            constexpr const float ORTHOGRAPHIC_NEAR_CULL_DIST = 1e-3f; //!< Far culling distance for the orthographic lens.
            constexpr const float ORTHOGRAPHIC_FAR_CULL_DIST  = 1e+3f; //!< Near culling distance for the orthographic lens.



            //  == CLASS ==
            /**
             *  Orthographic lens.
             */
            class Orthographic : public Lens
            {
                //  == FIELDS ==
              private:
                //  -- View --
                const unsigned int _width;
                const unsigned int _height;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Orthographic(unsigned int width_, unsigned int float_) noexcept;


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
            inline Orthographic::Orthographic(const unsigned int width_, const unsigned int height_) noexcept
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
                _proj = glm::ortho(0, _width, _height, 0, ORTHOGRAPHIC_NEAR_CULL_DIST, ORTHOGRAPHIC_FAR_CULL_DIST);
            }



        } // namespace lens
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_LENS_ORTHOGRAPHIC_HPP
