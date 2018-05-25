/**
 *  @file   arctk/math.hpp
 *  @date   25/05/2018
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
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace math //! math namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Mathematical --
        template <typename C, typename T = typename C::value_type>
        inline T sum(const C& cont_) noexcept;



        //  == FUNCTIONS ==
        //  -- Mathematical --
        /**
         *  Calculate the sum of a container's elements.
         *
         *  @param  cont_   Container to be summed.
         *
         *  @return Sum of containers elements.
         */
        template <typename C, typename T>
        inline T sum(const C& cont_) noexcept
        {
            T sum = 0;

            for (auto it = std::begin(cont_); it != std::end(cont_); ++it)
            {
                sum += *it;
            }

            return (sum);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_HPP
