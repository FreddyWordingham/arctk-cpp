//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Transform --
        template <typename R, typename F>
        constexpr inline void transform(R* range_, const F& trans_) noexcept;
        template <typename R, typename F>
        constexpr inline void transform(const R& range_, const F& trans_) noexcept;
        template <typename R, typename F, typename RO>
        constexpr inline void transform(const R& range_, const F& trans_, const RO& range_out_) noexcept;

        //  -- Order --
        template <typename R>
        constexpr inline void sort(R* range_) noexcept;
        template <typename R>
        constexpr inline void reverse(R* range_) noexcept;
        template <typename R>
        constexpr inline void rotate(R* range_) noexcept;



    } // namespace range
} // namespace arc
