/**
 *  @file   arctk/math/conversion.hpp
 *  @date   26/05/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical conversion functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_CONVERSION_HPP
#define ARCTK_MATH_CONVERSION_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename T>
        inline T rad_to_deg(const T x_) noexcept;
        template <typename T>
        inline T deg_to_rad(const T x_) noexcept;



        //  == FUNCTIONS ==
        /**
         *  Convert a value in radians to degrees.
         *
         *  @param  x_  Value to convert to degrees.
         *
         *  @return Value in degrees.
         */
        template <typename T>
        inline T rad_to_deg(const T x_) noexcept
        {
            return (static_cast<T>(180.0 / constant::PI * x_));
        }

        /**
         *  Convert a value in degrees to radians.
         *
         *  @param  x_  Value to convert to radians.
         *
         *  @return Value in radians.
         */
        template <typename T>
        inline T deg_to_rad(const T x_) noexcept
        {
            return (static_cast<T>(constant::PI / 180.0 * x_));
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_CONVERSION_HPP
