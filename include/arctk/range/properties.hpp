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



        //  == FUNCTIONS ==
        //  -- Properties --
        template <typename R>
        constexpr inline std::size_t num_its(const R& range_) noexcept;
        template <typename R, typename F>
        constexpr inline bool all_of(const R& range_, const F& pred_) noexcept;
        template <typename R, typename F>
        constexpr inline bool any_of(const R& range_, const F& pred_) noexcept;
        template <typename R, typename F>
        constexpr inline bool none_of(const R& range_, const F& pred_) noexcept;
        template <typename R, typename T>
        constexpr inline auto count(const R& range_, const T& val_) noexcept;
        template <typename R, typename F>
        constexpr inline auto count_if(const R& range_, const F& pred_) noexcept;

        //  -- Mathematical --
        template <typename R>
        constexpr inline auto min(const R& range_) noexcept;
        template <typename R>
        constexpr inline auto max(const R& range_) noexcept;

        //  -- Order --
        template <typename R>
        constexpr inline bool is_sorted(const R& range_) noexcept;



    } // namespace range
} // namespace arc
