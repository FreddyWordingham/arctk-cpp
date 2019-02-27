//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Search --
        template <typename R, typename T>
        constexpr inline bool bounded(const R& range_, const T& x_) noexcept;
        template <typename R, typename T>
        constexpr inline auto lower_index(const R& range_, const T& x_) noexcept;
        template <typename R, typename T>
        constexpr inline auto upper_index(const R& range_, const T& x_) noexcept;
        template <typename R, typename T>
        constexpr inline auto find_index(const R& range_, const T& val_) noexcept;
        template <typename R, typename F>
        constexpr inline auto find_index_if(const R& range_, const F& pred_) noexcept;
        template <typename R, typename F>
        constexpr inline auto find_index_if_not(const R& range_, const F& pred_) noexcept;



    } // namespace range
} // namespace arc
