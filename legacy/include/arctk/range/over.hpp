//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
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
            constexpr inline explicit over(const C& cont_, const std::size_t begin_offset_ = 0, const std::size_t end_offset_ = 0);


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const I& begin() const noexcept;
            constexpr inline const I& end() const noexcept;
        };



    } // namespace range
} // namespace arc
