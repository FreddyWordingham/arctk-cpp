//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Properties --
        template <typename R, typename F>
        constexpr inline bool all_of(const R& range_, F pred_) noexcept;
        template <typename R, typename F>
        constexpr inline bool any_of(const R& range_, F pred_) noexcept;
        template <typename R, typename F>
        constexpr inline bool none_of(const R& range_, F pred_) noexcept;
        template <typename R, typename T>
        constexpr inline auto count(const R& range_, const T& val_) noexcept;
        template <typename R, typename F>
        constexpr inline auto count_if(const R& range_, F pred_) noexcept;



    } // namespace range
} // namespace arc
