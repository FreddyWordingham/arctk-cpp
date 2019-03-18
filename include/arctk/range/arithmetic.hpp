//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/zip.inl"
#include "arctk/type/traits.hpp"

//  -- Std --
#include <cassert>
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <typename R, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    constexpr inline auto operator+(const R& range_) noexcept;
    template <typename R, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    constexpr inline auto operator-(const R& range_) noexcept;

    // template <template <typename...> typename R, typename T, typename S>
    // inline R<decltype(std::declval<T>() / std::declval<S>())> operator/(const R<T>& range_, const S& val_)
    // {
    //     R<decltype(std::declval<T>() / std::declval<S>())> ran;

    //     for (const auto r : range_)
    //     {
    //         ran.emplace_back(r / val_);
    //     }

    //     return (ran);
    // }
    template <template <typename...> typename R, typename T, typename S, typename = typename std::enable_if_t<type::is_rangeable_v<R<T>> && type::is_rangeable_v<R<S>>>>
    inline R<decltype(std::declval<T>() + std::declval<S>())> operator+(const R<T>& lhs_, const R<S>& rhs_)
    {
        assert(lhs_.size() == rhs_.size());

        R<decltype(std::declval<T>() + std::declval<S>())> range;
        range.reserve(lhs_.size());

        for (const auto [l, r] : range::view::Zip{lhs_, rhs_})
        {
            range.emplace_back(l + r);
        }

        return (range);
    }



} // namespace arc
