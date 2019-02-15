//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/math/properties.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Properties --
        template <typename T>
        constexpr inline bool is_prime(const T n_) noexcept
        {
            static_assert(std::is_integral<T>::value);

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

            while ((i * i) <= n)
            {
                if ((n % i) == 0)
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
