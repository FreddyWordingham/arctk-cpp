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
        constexpr inline void transform(R* const range_, F func_) noexcept;
        template <typename R, typename F>
        constexpr inline void transform(const R& range_, F func_) noexcept;
        template <typename R, typename F, typename Ro>
        constexpr inline void transform(const R& range_, F func_, const Ro& range_out_) noexcept;

        //  -- Order --
        template <typename R>
        constexpr inline void sort(R* const range_) noexcept;
        template <typename R>
        constexpr inline void reverse(R* const range_) noexcept;
        template <typename R>
        constexpr inline void rotate(R* const range_) noexcept;



    } // namespace range
} // namespace arc
