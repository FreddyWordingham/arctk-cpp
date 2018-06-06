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


                //  == METHODS ==
              private:
                //  -- Updating --
            };



            //  == INSTANTIATION --
            //  -- Constructors --



            //  == METHODS ==
            //  -- Updating --



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_FLY_HPP
