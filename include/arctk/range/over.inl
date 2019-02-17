//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/over.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == INSTANTATION ==
        //  -- Constructors --
        template <typename C, typename I>
        constexpr inline over<C, I>::over(const C& cont_, const std::size_t begin_offset_, const std::size_t end_offset_)
          : _begin{cont_.begin() + begin_offset_}
          , _end{cont_.end() - end_offset_}
        {
            assert((begin_offset_ + end_offset_) <= cont_.size());
        }


        //  == METHODS ==
        //  -- Getters --
        template <typename C, typename I>
        constexpr inline const I& over<C, I>::begin() const noexcept
        {
            return (_begin);
        }

        template <typename C, typename I>
        constexpr inline const I& over<C, I>::end() const noexcept
        {
            return (_end);
        }



    } // namespace range
} // namespace arc
