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



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace math //! arc namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Power --
        template <class T>
        inline T sq(T x_) noexcept;



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



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_HPP
