//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/arithmetic.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
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
        for (auto& l : lhs_)
        {
            l += rhs_;
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

    template <typename Rl, typename Rr, typename>
    inline std::vector<decltype(*(std::declval<Rl>().begin()) + *(std::declval<Rr>().begin()))> operator+(const Rl& lhs_, const Rr& rhs_) noexcept
    {
        assert(lhs_.size() == rhs_.size());

        std::vector<decltype(*(lhs_.begin()) + *(rhs_.begin()))> res;
        res.reserve(lhs_.size());

        for (const auto [l, r] : range::view::Zip{lhs_, rhs_})
        {
            res.emplace_back(l + r);
        }

        return (res);
    }

    template <typename Rl, typename Rr, typename>
    inline std::vector<decltype(*(std::declval<Rl>().begin()) - *(std::declval<Rr>().begin()))> operator-(const Rl& lhs_, const Rr& rhs_) noexcept
    {
        assert(lhs_.size() == rhs_.size());

        std::vector<decltype(*(lhs_.begin()) - *(rhs_.begin()))> res;
        res.reserve(lhs_.size());

        for (const auto [l, r] : range::view::Zip{lhs_, rhs_})
        {
            res.emplace_back(l - r);
        }

        return (res);
    }

    template <typename Rl, typename Rr, typename>
    inline std::vector<decltype(*(std::declval<Rl>().begin()) * *(std::declval<Rr>().begin()))> operator*(const Rl& lhs_, const Rr& rhs_) noexcept
    {
        assert(lhs_.size() == rhs_.size());

        std::vector<decltype(*(lhs_.begin()) * *(rhs_.begin()))> res;
        res.reserve(lhs_.size());

        for (const auto [l, r] : range::view::Zip{lhs_, rhs_})
        {
            res.emplace_back(l * r);
        }

        return (res);
    }

    template <typename Rl, typename Rr, typename>
    inline std::vector<decltype(*(std::declval<Rl>().begin()) / *(std::declval<Rr>().begin()))> operator/(const Rl& lhs_, const Rr& rhs_) noexcept
    {
        assert(lhs_.size() == rhs_.size());

        std::vector<decltype(*(lhs_.begin()) / *(rhs_.begin()))> res;
        res.reserve(lhs_.size());

        for (const auto [l, r] : range::view::Zip{lhs_, rhs_})
        {
            res.emplace_back(l / r);
        }

        return (res);
    }

    template <typename Rl, typename Rr, typename>
    inline std::vector<decltype(*(std::declval<Rl>().begin()) % *(std::declval<Rr>().begin()))> operator%(const Rl& lhs_, const Rr& rhs_) noexcept
    {
        assert(lhs_.size() == rhs_.size());

        std::vector<decltype(*(lhs_.begin()) % *(rhs_.begin()))> res;
        res.reserve(lhs_.size());

        for (const auto [l, r] : range::view::Zip{lhs_, rhs_})
        {
            res.emplace_back(l % r);
        }

        return (res);
    }



} // namespace arc
