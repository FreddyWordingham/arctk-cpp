/**
 *  @file   arctk/gui/camera/fly.hpp
 *  @date   17/07/2018
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
#include <arctk/debug.hpp>
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
                inline explicit Fly(float fov_, float aspect_ratio_, const glm::vec3& pos_ = {0.0f, 0.0f, 1.0f}, const glm::vec3& dir_ = {0.0f, 0.0f, -1.0f}, const glm::vec3& up_ = {0.0f, 1.0f, 0.0f}) noexcept;


                //  == METHODS ==
              private:
                //  -- Updating --
                inline void update_view_proj() noexcept override;
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
            inline Fly::Fly(float fov_, float aspect_ratio_, const glm::vec3& pos_, const glm::vec3& dir_, const glm::vec3& up_) noexcept
              : Camera(pos_, dir_, up_)
              , _fov(fov_)
              , _aspect_ratio(aspect_ratio_)
            {
                PRE(fov_ > 0.0f);
                PRE(aspect_ratio_ > 0.0f);

                update_view_proj();
            }



            //  == METHODS ==
            //  -- Updating --
            /**
             *  Update the model-view-projection matrix of the camera.
             */
            inline void Fly::update_view_proj() noexcept
            {
                const glm::mat4 view = glm::lookAt(_pos, _pos + _dir, _up);
                const glm::mat4 proj = glm::perspective(_fov, _aspect_ratio, FLY_NEAR_CULL_DIST, FLY_FAR_CULL_DIST);

                _view_proj = proj * view;
            }



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_FLY_HPP
