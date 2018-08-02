/**
 *  @file   arctk/gui/camera/fly.hpp
 *  @date   02/08/2018
 *  @author Freddy Wordingham
 *
 *  Scene camera class with fly controls.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_FLY_HPP
#define ARCTK_GUI_CAMERA_FLY_HPP



//  == IMPORTS ==
//  -- Graphical --
#include <glm/glm.hpp>

//  -- Arctk --
#include <arctk/camera/fly.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace camera //! camera namespace
        {



            //  == CONSTANTS ==
            //  -- Culling --
            constexpr const float FLY_NEAR_CULL_DIST = 1e-3f; //!< Far culling distance for the fly camera.
            constexpr const float FLY_FAR_CULL_DIST  = 1e+3f; //!< Near culling distance for the fly camera.



            //  == CLASS ==
            /**
             *  Scene camera class with fly controls.
             */
            class Fly : public Camera
            {
                //  == FIELDS ==

                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_FLY_HPP
