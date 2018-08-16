/**
 *  @file   arctk/gui/point.hpp
 *  @date   16/08/2018
 *  @author Freddy Wordingham
 *
 *  Data point class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_POINT_HPP
#define ARCTK_GUI_POINT_HPP



//  == IMPORTS ==
//  -- Graphical --
#include <glm/glm.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



        //  == CLASS ==
        /**
         *  Data point class.
         */
        class Point
        {
            //  == FIELDS ==
          private:
            //  -- Spatial --
            const glm::vec3 pos;

            //  -- Optical --
            const float wavelength;



            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
        };



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_POINT_HPP
