/**
 *  @file   arctk/gui/camera/birdseye.hpp
 *  @date   17/07/2018
 *  @author Freddy Wordingham
 *
 *  Birdseye camera class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_BIRDSEYE_HPP
#define ARCTK_GUI_CAMERA_BIRDSEYE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_GUI



//  == BASE ==
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
            constexpr const float BIRDSEYE_NEAR_CULL_DIST = -1e+3f; //!< Far culling distance for the birdseye camera.
            constexpr const float BIRDSEYE_FAR_CULL_DIST  = 1e+3f;  //!< Near culling distance for the birdseye camera.



            //  == CLASS ==
            /**
             *  Birdseye camera class.
             */
            class Birdseye : public Camera
            {
                //  == FIELDS ==
              private:
                //  -- View --
                float _width_start;  //!< Start rendering width of the window.
                float _width_end;    //!< End rendering width of the window.
                float _height_start; //!< Start rendering height of the window.
                float _height_end;   //!< End rendering height of the window.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Birdseye(float width_start_ = 0.0f, float width_end_ = 1.0f, float height_start_ = 0.0f, float height_end_ = 1.0f, const glm::vec3& pos_ = {0.0f, 0.0f, 1.0f}, const glm::vec3& dir_ = {0.0f, 0.0f, -1.0f},
                                         const glm::vec3& up_ = {0.0f, 1.0f, 0.0f}) noexcept;


                //  == METHODS ==
              private:
                //  -- Updating --
                inline void update_mvp() noexcept override;
            };



            //  == INSTANTIATION --
            //  -- Constructors --
            /**
             *  Construct a birdseye camera.
             *
             *  @param  width_start_    Start rendering width of the window.
             *  @param  width_end_      End rendering width of the window.
             *  @param  height_start_   Start rendering height of the window.
             *  @param  height_end_     End rendering height of the window.
             *  @param  pos_            Initial position of the camera.
             *  @param  dir_            Direction for the camera to face.
             *  @param  up_             Up direction of the camera.
             *
             *  @pre    width_start_ must be less than width_end_.
             *  @pre    height_start_ must be less than height_end_.
             */
            inline Birdseye::Birdseye(const float width_start_, const float width_end_, const float height_start_, const float height_end_, const glm::vec3& pos_, const glm::vec3& dir_, const glm::vec3& up_) noexcept
              : Camera(pos_, dir_, up_)
              , _width_start(width_start_)
              , _width_end(width_end_)
              , _height_start(height_start_)
              , _height_end(height_end_)
            {
                assert(width_start_ < width_end_);
                assert(height_start_ < height_end_);

                update_mvp();
            }



            //  == METHODS ==
            //  -- Updating --
            /**
             *  Update the model-view-projection matrix of the camera.
             */
            inline void Birdseye::update_mvp() noexcept
            {
                const glm::mat4 view = glm::lookAt(_pos, _pos + _dir, _up);
                const glm::mat4 proj = glm::ortho(_width_start, _width_end, _height_start, _height_end, BIRDSEYE_NEAR_CULL_DIST, BIRDSEYE_FAR_CULL_DIST);

                _mvp = proj * view;
            }



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_BIRDSEYE_HPP
