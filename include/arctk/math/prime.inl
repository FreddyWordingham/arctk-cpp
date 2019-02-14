//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/math/prime.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Prime --
        template <typename T>
        inline bool is_prime(const T x_) noexcept
        {
            static_assert(std::is_integral<T>::value);

            assert(x_ >= 0);

            if ((x_ == 2) || (x_ == 3))
            {
                return (true);
            }

            if (((x_ % 2) == 0) || ((x_ % 3) == 0))
            {
                return false;
            }

            T divisor{6};
            while (((divisor * divisor) - (2 * divisor) + 1) <= x_)
            {
                if ((((x_ % 5) == 0)) || ((x_ % 7) == 0))
                {
                    return (false);
                }

                divisor += 6;
            }

            return (true);
        }

        template <typename T>
        inline T next_prime(T x_) noexcept
        {
            static_assert(std::is_integral<T>::value);

            assert(x_ >= 0);

            while (!is_prime(++x_))
            {
            }

            return (x_);
        }



    } // namespace math
} // namespace arc
