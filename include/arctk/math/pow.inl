/**
 *  @file   arctk/math/pow.inl
 *  @date   07/07/2018
 *  @author Freddy Wordingham
 *
 *  Math power functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_POW_INL
#define ARCTK_MATH_POW_INL



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace pow //! power namespace
        {



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
#endif // ARCTK_MATH_POW_INL
