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
#include <type_traits>



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
        template <typename T>
        inline T rad_to_deg(const T x_) noexcept;

        template <typename T>
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
        template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
        inline T rad_to_deg(const T x_) noexcept
        {
            return (static_cast<T>(180.0 / M_PI) * x_);
        }

        template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
        inline T deg_to_rad(const T x_) noexcept
        {
            return (static_cast<T>(M_PI / 180.0) * x_);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_HPP
