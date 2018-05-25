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
#include <cmath>
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace cont //! container namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Properties --
        template <typename C>
        inline size_t size(const C& cont_) noexcept;

        //  -- Mathematical --
        template <typename C, typename T = typename C::value_type>
        inline T sum(const C& cont_) noexcept;
        template <typename C>
        inline double ave(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type>
        inline double mag(const C& cont_) noexcept;
        template <typename C>
        inline size_t min_index(const C& cont_) noexcept;
        template <typename C>
        inline size_t max_index(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type>
        inline T min(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type>
        inline T max(const C& cont_) noexcept;



        //  == FUNCTIONS ==
        //  -- Properties --
        /**
         *  Calculate the size of a container.
         *
         *  @param  cont_   Container to determine the size of.
         *
         *  @return Size of the container.
         */
        template <typename C>
        inline size_t size(const C& cont_) noexcept
        {
            return (std::distance(std::begin(cont_), std::end(cont_)));
        }


        //  -- Mathematical --
        /**
         *  Calculate the sum of a container's elements.
         *
         *  @param  cont_   Container to determine the sum of.
         *
         *  @return Sum of the containers elements.
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
         *  @return Average of the containers elements.
         */
        template <typename C>
        inline double ave(const C& cont_) noexcept
        {
            return (static_cast<double>(sum(cont_)) / cont::size(cont_));
        }

        /**
         *  Calculate the magnitude of a container's elements.
         *
         *  @param  cont_   Container to determine the magnitude of.
         *
         *  @return Magnitude the containers elements.
         */
        template <typename C, typename T>
        inline double mag(const C& cont_) noexcept
        {
            T sq_sum{};

            for (auto it = std::begin(cont_); it != std::end(cont_); ++it)
            {
                sq_sum += *it * *it;
            }

            return (std::sqrt(static_cast<double>(sq_sum)));
        }

        /**
         *  Find the index of the minimum element within a container.
         *
         *  @param  cont_   Container to determine the minimum element index of.
         *
         *  @return Index of the minimum element within the container.
         */
        template <typename C>
        inline size_t min_index(const C& cont_) noexcept
        {
            size_t min_index = 0;

            for (auto it = std::begin(cont_); it != std::end(cont_); ++it)
            {
                if (*it < min_index)
                {
                    min_index = *it;
                }
            }

            return (min_index);
        }

        template <typename C>
        inline size_t max_index(const C& cont_) noexcept
        {
        }

        /**
         *  Find the minimum element within a container.
         *
         *  @param  cont_   Container to determine the minimum element of.
         *
         *  @return Value of the minimum element within the container.
         */
        template <typename C, typename T>
        inline T min(const C& cont_) noexcept
        {
            return (cont_[min_index(cont_)]);
        }

        /**
         *  Find the maximum element within a container.
         *
         *  @param  cont_   Container to determine the maximum element of.
         *
         *  @return Value of the maximum element within the container.
         */
        template <typename C, typename T>
        inline T max(const C& cont_) noexcept
        {
            return (cont_[max_index(cont_)]);
        }



    } // namespace cont
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_CONTAINER_HPP
