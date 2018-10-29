/**
 *  @file   arctk/gui/point.inl
 *  @date   16/08/2018
 *  @author Freddy Wordingham
 *
 *  Data point class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_POINT_INL
#define ARCTK_GUI_POINT_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a data point recording the time and wavelength at a given position.
         *
         *  @param  pos_        Position of the data point.
         *  @param  time_       Time of the data point.
         *  @param  wavelength_ Wavelength of the data point.
         *
         *  @pre    time_ must be non-negative.
         *  @pre    wavelength_ must be positive.
         */
        inline Point::Point(const glm::vec3& pos_, const float time_, const float wavelength_) noexcept
          : pos(pos_)
          , time(time_)
          , wavelength(wavelength_)
        {
            assert(time_ >= 0.0f);
            assert(wavelength_ > 0.0f);
        }



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_POINT_INL
