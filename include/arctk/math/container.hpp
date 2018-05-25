/**
 *  @file   arctk/math/container.hpp
 *  @date   25/05/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical container functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_CONTAINER_HPP
#define ARCTK_MATH_CONTAINER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <cmath>
#include <iterator>

#include <arctk/properties.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C, typename I = typename C::const_iterator, typename T = typename C::value_type>
        inline T sum(const C& cont_) noexcept;
        template <typename C>
        inline double ave(const C& cont_) noexcept;
        template <typename C, typename I = typename C::const_iterator, typename T = typename C::value_type>
        inline double mag(const C& cont_) noexcept;



        //  == FUNCTIONS ==
        /**
         *  Calculate the sum of a container's elements.
         *
         *  @param  cont_   Container to determine the sum of.
         *
         *  @return Sum of the containers elements.
         */
        template <typename C, typename I, typename T>
        inline T sum(const C& cont_) noexcept
        {
            T sum{};

            for (I it = std::begin(cont_); it != std::end(cont_); ++it)
            {
                sum += *it;
            }

            return (sum);
        }

        /**
         *  Calculate the average of a container's elements.
         *
         *  @param  cont_   Container to determine the average of.
         *
         *  @return Average of the containers elements.
         */
        template <typename C>
        inline double ave(const C& cont_) noexcept
        {
            return (static_cast<double>(sum(cont_)) / size(cont_));
        }

        /**
         *  Calculate the magnitude of a container's elements.
         *
         *  @param  cont_   Container to determine the magnitude of.
         *
         *  @return Magnitude the containers elements.
         */
        template <typename C, typename I, typename T>
        inline double mag(const C& cont_) noexcept
        {
            T sq_sum{};

            for (I it = std::begin(cont_); it != std::end(cont_); ++it)
            {
                sq_sum += *it * *it;
            }

            return (std::sqrt(static_cast<double>(sq_sum)));
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_CONTAINER_HPP
