/**
 *  @file   arctk/gui/lens/perspective.hpp
 *  @date   02/08/2018
 *  @author Freddy Wordingham
 *
 *  Perspective camera lens.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_LENS_PERSPECTIVE_HPP
#define ARCTK_GUI_LENS_PERSPECTIVE_HPP



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Graphical --
#include <glm/glm.hpp>

//  -- Arctk --
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
            constexpr const float PERSPECTIVE_NEAR_CULL_DIST = 1e-3f; //!< Far culling distance for the perspective lens.
            constexpr const float PERSPECTIVE_FAR_CULL_DIST  = 1e+3f; //!< Near culling distance for the perspective lens.



            //  == CLASS ==
            /**
             *  Perspective lens.
             */
            class Perspective : public Lens
            {
                //  == FIELDS ==
              private:
                //  -- View --
                const float _fov;          //!< Field of view.
                const float _aspect_ratio; //!< Aspect ratio of the camera.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Perspective(float fov_, float aspect_ratio_) noexcept;


                //  == METHODS ==
              private:
                //  -- Updating --
                inline void update_view() noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a perspective lens with a given field-of-view and aspect ratio.
             *
             *  @param  fov_            Field-of-view of the lens.
             *  @param  aspect_ratio_   Aspect ratio of the lens.
             *
             *  @pre    fov_ must be positive.
             */
            inline Perspective::Perspective(const float fov_, const float aspect_ratio_) noexcept
              : _fov(fov_)
              , _aspect_ratio(aspect_ratio_)
            {
                assert(fov_ > 0.0f);

                update_view();
            }



            //  == METHODS ==
            //  -- Updating --
            /**
             *  Update the projection matrix of the lens.
             */
            inline void Perspective::update_view() noexcept
            {
                _proj = glm::perspective(_fov, _aspect_ratio, PERSPECTIVE_NEAR_CULL_DIST, PERSPECTIVE_FAR_CULL_DIST);
            }



        } // namespace lens
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_LENS_PERSPECTIVE_HPP
