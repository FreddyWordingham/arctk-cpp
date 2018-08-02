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


                //  == METHODS ==
              public:
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==



        } // namespace lens
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_LENS_PERSPECTIVE_HPP
