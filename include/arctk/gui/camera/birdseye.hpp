/**
 *  @file   arctk/gui/camera/birdseye.hpp
 *  @date   04/06/2018
 *  @author Freddy Wordingham
 *
 *  Birdseye camera class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_BIRDSEYE_HPP
#define ARCTK_GUI_CAMERA_BIRDSEYE_HPP



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



            //  == CLASS ==
            /**
             *  Birdseye camera class.
             */
            class Birdseye : public Camera
            {
                //  == FIELDS ==
              private:
                //  -- View --
                float _width_start;
                float _width_end;
                float _height_start;
                float _height_end;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
            };



            //  == INSTANTIATION --
            //  -- Constructors --



            //  == METHODS ==



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_BIRDSEYE_HPP
