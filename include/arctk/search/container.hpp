/**
 *  @file   arctk/search/container.hpp
 *  @date   25/05/2018
 *  @author Freddy Wordingham
 *
 *  Search container functions.
 */



//  == GUARD ==
#ifndef ARCTK_SEARCH_CONTAINER_HPP
#define ARCTK_SEARCH_CONTAINER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <cmath>
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace search //! search namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C, typename I = typename C::const_iterator>
        inline size_t min_index(const C& cont_) noexcept;
        template <typename C, typename I = typename C::const_iterator>
        inline size_t max_index(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type>
        inline T min(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type>
        inline T max(const C& cont_) noexcept;



        //  == FUNCTIONS ==
        /**
         *  Find the index of the minimum element within a container.
         *
         *  @param  cont_   Container to determine the minimum element index of.
         *
         *  @return Index of the minimum element within the container.
         */
        template <typename C, typename I>
        inline size_t min_index(const C& cont_) noexcept
        {
            I min_index = std::begin(cont_);

            for (I it = min_index + 1; it != std::end(cont_); ++it)
            {
                if (*it < *min_index)
                {
                    min_index = it;
                }
            }

            return (std::distance(std::begin(cont_), min_index));
        }

        /**
         *  Find the index of the maximum element within a container.
         *
         *  @param  cont_   Container to determine the maximum element index of.
         *
         *  @return Index of the maximum element within the container.
         */
        template <typename C, typename I>
        inline size_t max_index(const C& cont_) noexcept
        {
            I max_index = std::begin(cont_);

            for (I it = max_index + 1; it != std::end(cont_); ++it)
            {
                if (*it > *max_index)
                {
                    max_index = it;
                }
            }

            return (std::distance(std::begin(cont_), max_index));
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



    } // namespace search
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SEARCH_CONTAINER_HPP
