/**
 *  @file   arctk/container.hpp
 *  @date   25/05/2018
 *  @author Freddy Wordingham
 *
 *  Collection of container focused functions.
 */



//  == GUARD ==
#ifndef ARCTK_CONTAINER_HPP
#define ARCTK_CONTAINER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace cont //! container namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Mathematical --
        template <typename C, typename T = typename C::value_type>
        inline T sum(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type>
        inline T ave(const C& cont_) noexcept;



        //  == FUNCTIONS ==
        //  -- Mathematical --
        /**
         *  Calculate the sum of a container's elements.
         *
         *  @param  cont_   Container to determine the sum of.
         *
         *  @return Sum of containers elements.
         */
        template <typename C, typename T>
        inline T sum(const C& cont_) noexcept
        {
            T sum{};

            for (auto it = std::begin(cont_); it != std::end(cont_); ++it)
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
         *  @return Average of containers elements.
         */
        template <typename C, typename T>
        inline T ave(const C& cont_) noexcept
        {
            T ave{};

            for (auto it = std::begin(cont_); it != std::end(cont_); ++it)
            {
                ave += *it;
            }

            return (ave /);
        }



    } // namespace cont
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_CONTAINER_HPP
