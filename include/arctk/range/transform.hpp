//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- For Each --
        template <typename R, typename F>
        constexpr inline void for_each(R* range_, const F& trans_) noexcept;
        template <typename R, typename F>
        constexpr inline void for_each(const R& range_, const F& trans_) noexcept;

        //  -- Order --
        template <typename R>
        constexpr inline void sort(R* range_) noexcept;
        template <typename R>
        constexpr inline void reverse(R* range_) noexcept;
        template <typename R>
        constexpr inline void rotate(R* range_) noexcept;



    } // namespace range
} // namespace arc
