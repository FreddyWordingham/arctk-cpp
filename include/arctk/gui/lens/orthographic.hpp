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


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              private:
                //  -- Updating --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==
            //  -- Updating --



        } // namespace lens
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_LENS_ORTHOGRAPHIC_HPP
