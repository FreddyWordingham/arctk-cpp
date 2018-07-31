/**
 *  @file   arctk/math/pow.hpp
 *  @date   07/07/2018
 *  @author Freddy Wordingham
 *
 *  Math power functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_POW_HPP
#define ARCTK_MATH_POW_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace pow //! power namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Power --
            template <typename T>
            inline T sq(T val_) noexcept;
            template <typename T>
            inline T cube(T val_) noexcept;



            //  == FUNCTIONS ==
            //  -- Power --
            /**
             *  Square a value.
             *
             *  @tparam T   Type to be squared.
             *
             *  @param  val_    Value to be squared.
             *
             *  @return Square of the value.
             */
            template <typename T>
            inline T sq(const T val_) noexcept
            {
                return (val_ * val_);
            }

            /**
             *  Cube a value.
             *
             *  @tparam T   Type to be cubed.
             *
             *  @param  val_    Value to be cubed.
             *
             *  @return Cube of the value.
             */
            template <typename T>
            inline T cube(const T val_) noexcept
            {
                return (val_ * val_ * val_);
            }



        } // namespace pow
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_POW_HPP
