//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/arithmetic.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include "arctk/range/properties.inl"
#include "arctk/range/view/zip.inl"

//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Assignment --
    template <typename R, typename T, typename>
    inline R& operator+=(R& lhs_, const T& rhs_) noexcept
    {
        if constexpr (type::is_rangeable_v<T>)
        {
            assert(range::num_its(lhs_) == range::num_its(rhs_));

            // for (auto& [l, r] : range::view::Zip{lhs_, rhs_}) // TODO find a way of zipping a const and non-const range.
            // {
            //     l += r;
            // }
        }
        else
        {
            for (auto& l : lhs_)
            {
                l += rhs_;
            }
        }

        return (lhs_);
    }

    template <typename R, typename T, typename>
    inline R& operator-=(R& lhs_, const T& rhs_) noexcept
    {
        for (auto& l : lhs_)
        {
            l -= rhs_;
        }

        return (lhs_);
    }

    template <typename R, typename T, typename>
    inline R& operator*=(R& lhs_, const T& rhs_) noexcept
    {
        for (auto& l : lhs_)
        {
            l *= rhs_;
        }

        return (lhs_);
    }

    template <typename R, typename T, typename>
    inline R& operator/=(R& lhs_, const T& rhs_) noexcept
    {
        for (auto& l : lhs_)
        {
            l /= rhs_;
        }

        return (lhs_);
    }

    template <typename R, typename T, typename>
    inline R& operator%=(R& lhs_, const T& rhs_) noexcept
    {
        for (auto& l : lhs_)
        {
            l %= rhs_;
        }

        return (lhs_);
    }


    //  -- Arithmetic --
    template <typename R, typename>
    constexpr inline auto operator+(const R& range_) noexcept
    {
        auto range{range_};

        for (auto& r : range)
        {
            r = +r;
        }

        return (range);
    }

    template <typename R, typename>
    constexpr inline auto operator-(const R& range_) noexcept
    {
        auto range{range_};

        for (auto& r : range)
        {
            r = -r;
        }

        return (range);
    }

    template <typename R, typename T, typename>
    inline std::vector<decltype(*(std::begin(std::declval<R>())) + std::declval<T>())> operator+(const R& lhs_, const T& rhs_) noexcept
    {
        std::vector<decltype(*(std::begin(std::declval<R>())) + std::declval<T>())> res;
        res.reserve(lhs_.size());

        for (const auto l : lhs_)
        {
            res.emplace_back(l + rhs_);
        }

        return (res);
    }

    template <typename Rl, typename Rr, typename>
    inline std::vector<decltype(*(std::begin(std::declval<Rl>())) + *(std::begin(std::declval<Rr>())))> operator+(const Rl& lhs_, const Rr& rhs_) noexcept
    {
        assert(lhs_.size() == rhs_.size());

        std::vector<decltype(*(std::begin(lhs_)) + *(std::begin(rhs_)))> res;
        res.reserve(lhs_.size());

        for (const auto [l, r] : range::view::Zip{lhs_, rhs_})
        {
            res.emplace_back(l + r);
        }

        return (res);
    }

    template <typename R, typename T, typename>
    inline std::vector<decltype(*(std::begin(std::declval<R>())) - std::declval<T>())> operator-(const R& lhs_, const T& rhs_) noexcept
    {
        std::vector<decltype(*(std::begin(std::declval<R>())) - std::declval<T>())> res;
        res.reserve(lhs_.size());

        for (const auto l : lhs_)
        {
            res.emplace_back(l - rhs_);
        }

        return (res);
    }

    template <typename Rl, typename Rr, typename>
    inline std::vector<decltype(*(std::begin(std::declval<Rl>())) - *(std::begin(std::declval<Rr>())))> operator-(const Rl& lhs_, const Rr& rhs_) noexcept
    {
        assert(lhs_.size() == rhs_.size());

        std::vector<decltype(*(std::begin(lhs_)) - *(std::begin(rhs_)))> res;
        res.reserve(lhs_.size());

        for (const auto [l, r] : range::view::Zip{lhs_, rhs_})
        {
            res.emplace_back(l - r);
        }

        return (res);
    }

    template <typename R, typename T, typename>
    inline std::vector<decltype(*(std::begin(std::declval<R>())) * std::declval<T>())> operator*(const R& lhs_, const T& rhs_) noexcept
    {
        std::vector<decltype(*(std::begin(std::declval<R>())) * std::declval<T>())> res;
        res.reserve(lhs_.size());

        for (const auto l : lhs_)
        {
            res.emplace_back(l * rhs_);
        }

        return (res);
    }

    template <typename Rl, typename Rr, typename>
    inline std::vector<decltype(*(std::begin(std::declval<Rl>())) * *(std::begin(std::declval<Rr>())))> operator*(const Rl& lhs_, const Rr& rhs_) noexcept
    {
        assert(lhs_.size() == rhs_.size());

        std::vector<decltype(*(std::begin(lhs_)) * *(std::begin(rhs_)))> res;
        res.reserve(lhs_.size());

        for (const auto [l, r] : range::view::Zip{lhs_, rhs_})
        {
            res.emplace_back(l * r);
        }

        return (res);
    }

    template <typename R, typename T, typename>
    inline std::vector<decltype(*(std::begin(std::declval<R>())) / std::declval<T>())> operator/(const R& lhs_, const T& rhs_) noexcept
    {
        std::vector<decltype(*(std::begin(std::declval<R>())) / std::declval<T>())> res;
        res.reserve(lhs_.size());

        for (const auto l : lhs_)
        {
            res.emplace_back(l / rhs_);
        }

        return (res);
    }

    template <typename Rl, typename Rr, typename>
    inline std::vector<decltype(*(std::begin(std::declval<Rl>())) / *(std::begin(std::declval<Rr>())))> operator/(const Rl& lhs_, const Rr& rhs_) noexcept
    {
        assert(lhs_.size() == rhs_.size());

        std::vector<decltype(*(std::begin(lhs_)) / *(std::begin(rhs_)))> res;
        res.reserve(lhs_.size());

        for (const auto [l, r] : range::view::Zip{lhs_, rhs_})
        {
            res.emplace_back(l / r);
        }

        return (res);
    }

    template <typename R, typename T, typename>
    inline std::vector<decltype(*(std::begin(std::declval<R>())) % std::declval<T>())> operator%(const R& lhs_, const T& rhs_) noexcept
    {
        std::vector<decltype(*(std::begin(std::declval<R>())) % std::declval<T>())> res;
        res.reserve(lhs_.size());

        for (const auto l : lhs_)
        {
            res.emplace_back(l % rhs_);
        }

        return (res);
    }

    template <typename Rl, typename Rr, typename>
    inline std::vector<decltype(*(std::begin(std::declval<Rl>())) % *(std::begin(std::declval<Rr>())))> operator%(const Rl& lhs_, const Rr& rhs_) noexcept
    {
        assert(lhs_.size() == rhs_.size());

        std::vector<decltype(*(std::begin(lhs_)) % *(std::begin(rhs_)))> res;
        res.reserve(lhs_.size());

        for (const auto [l, r] : range::view::Zip{lhs_, rhs_})
        {
            res.emplace_back(l % r);
        }

        return (res);
    }



} // namespace arc
