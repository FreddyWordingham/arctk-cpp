//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == STRUCTURES ==
        //  -- Over --
        template <typename C, typename I = typename C::const_iterator>
        struct over
        {
            //  == FIELDS ==
          public:
            //  -- Iterators --
            const I _begin;
            const I _end;


            //  == INSTANTATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit over(const C& cont_, const std::size_t begin_offset_ = 0, const std::size_t end_offset_ = 0)
              : _begin{cont_.begin() + begin_offset_}
              , _end{cont_.end() - end_offset_}
            {
                assert((begin_offset_ + end_offset_) <= cont_.size());
            }


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const I& begin() const noexcept
            {
                return (_begin);
            }

            constexpr inline const I& end() const noexcept
            {
                return (_end);
            }
        };



    } // namespace range
} // namespace arc
