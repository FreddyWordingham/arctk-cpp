//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/math/pure.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/compare.inl"



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Properties --
        template <typename T>
        constexpr inline bool is_positive(const T n_) noexcept
        {
            return (n_ > 0);
        }

        template <typename T>
        constexpr inline bool is_negative(const T n_) noexcept
        {
            return (n_ < 0);
        }

        template <typename T>
        constexpr inline bool is_zero(const T n_) noexcept
        {
            return (n_ == 0);
        }

        template <>
        constexpr inline bool is_zero(const double n_) noexcept
        {
            return (zero(n_));
        }

        template <typename T, typename>
        constexpr inline bool is_prime(const T n_) noexcept
        {
            if (n_ == 1)
            {
                return (false);
            }

            if ((n_ == 2) || (n_ == 3))
            {
                return (true);
            }

            if (((n_ % 2) == 0) || ((n_ % 3) == 0))
            {
                return (false);
            }

            T i{5};
            T w{2};

            while ((i * i) <= n_)
            {
                if ((n_ % i) == 0)
                {
                    return (false);
                }

                i += w;
                w = 6 - w;
            }

            return (true);
        }



    } // namespace math
} // namespace arc
