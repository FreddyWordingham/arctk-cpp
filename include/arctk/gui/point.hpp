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
          public:
            //  -- Spatial --
            const glm::vec3 pos; //!< Position of the data point.

            //  -- Temporal --
            const float time; //!< Time of the data point.

            //  -- Optical --
            const float wavelength; //!< Wavelength of the data point.
            const float phase;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Point(const glm::vec3& pos_, float time_, float wavelength_, float phase_) noexcept;
        };



    } // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/point.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_POINT_HPP
