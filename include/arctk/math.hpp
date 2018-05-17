/**
 *  @date   16/05/2018.
 *  @author Freddy Wordingham
 *
 *  Collection of mathematical classes and functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_HPP
#define ARCTK_MATH_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <cmath>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace math //! math namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Power --
        template <class T>
        inline T sq(T x_) noexcept;
        template <class T>
        inline T cube(T x_) noexcept;

        //  -- Conversion --
        template <class T>
        inline T rad_to_deg(const T x_) noexcept;
        template <class T>
        inline T deg_to_rad(const T x_) noexcept;


        //  == FUNCTIONS ==
        //  -- Power --
        /**
         *  Find the square of a given value.
         *
         *  @param  x_  Value to be squared.
         *
         *  @return The square of x_.
         */
        template <class T>
        inline T sq(const T x_) noexcept
        {
            return (x_ * x_);
        }

        /**
         *  Find the cube of a given value.
         *
         *  @param  x_  Value to be cubed.
         *
         *  @return The cube of x_.
         */
        template <class T>
        inline T cube(const T x_) noexcept
        {
            return (x_ * x_ * x_);
        }


        //  -- Conversion --
        /**
         *  Convert the value in radians to degrees.
         *
         *  @pre    T must be an arithmetic type.
         *
         *  @tparam T   Type of value to convert.
         *
         *  @param  x_  Value to be converted to degrees.
         *
         *  @return Value of x_ in degrees.
         */
        template <class T>
        inline T rad_to_deg(const T x_) noexcept
        {
            static_assert(std::is_arithmetic<T>::value);

            return (static_cast<T>(180.0 / M_PI) * x_);
        }

        /**
         *  Convert the value in degrees to radians.
         *
         *  @pre    T must be an arithmetic type.
         *
         *  @tparam T   Type of value to convert.
         *
         *  @param  x_  Value to be converted to radians.
         *
         *  @return Value of x_ in radians.
         */
        template <class T>
        inline T deg_to_rad(const T x_) noexcept
        {
            static_assert(std::is_arithmetic<T>::value);

            return (static_cast<T>(M_PI / 180.0) * x_);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_HPP
