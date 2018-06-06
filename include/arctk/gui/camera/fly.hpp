/**
 *  @file   arctk/gui/camera/fly.hpp
 *  @date   07/06/2018
 *  @author Freddy Wordingham
 *
 *  Fly camera class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_FLY_HPP
#define ARCTK_GUI_CAMERA_FLY_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_GUI



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/gui/camera.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical user interface namespace
    {
        namespace camera //! camera namespace
        {



            //  == CONSTANTS ==
            //  -- View Distance --
            constexpr const float FLY_NEAR_CULL_DIST = 1e-3f; //!< Far culling distance for the fly camera.
            constexpr const float FLY_FAR_CULL_DIST  = 1e+3f; //!< Near culling distance for the fly camera.



            //  == CLASS ==
            /**
             *  Fly camera class.
             */
            class Fly : public Camera
            {
                //  == FIELDS ==
              private:
                //  -- View --
                float _fov;          //!< Field-of-view of the camera.
                float _aspect_ratio; //!< Aspect ratio of the camera.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Birdseye(float fov_, float aspect_ratio_, const glm::vec3& pos_ = {0.0f, 0.0f, 1.0f}, const glm::vec3& dir_ = {0.0f, 0.0f, -1.0f}, const glm::vec3& up_ = {0.0f, 1.0f, 0.0f}) noexcept;


                //  == METHODS ==
              private:
                //  -- Updating --
            };



            //  == INSTANTIATION --
            //  -- Constructors --
            /**
             *  Construct a fly camera.
             *
             *  @param  fov_            Field-of-view of the camera.
             *  @param  aspect_ratio_   Aspect ratio of the camera.
             *  @param  pos_            Initial position of the camera.
             *  @param  dir_            Direction for the camera to face.
             *  @param  up_             Up direction of the camera.
             *
             *  @pre    fov_ must be positive.
             *  @pre    aspect_ratio_ must be positive.
             */
            inline Birdseye::Birdseye(float fov_, float aspect_ratio_, const glm::vec3& pos_, const glm::vec3& dir_, const glm::vec3& up_) noexcept
              : Camera(pos_, dir_, up_)
              , _fov(fov_)
              , _aspect_ratio(aspect_ratio_)
            {
                assert(fov_ > 0.0f);
                assert(aspect_ratio_ > 0.0f);

                update_mvp();
            }



            //  == METHODS ==
            //  -- Updating --



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_FLY_HPP
