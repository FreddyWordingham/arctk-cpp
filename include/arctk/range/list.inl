//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/list.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/properties.inl"

//  -- Std --
#include <cassert>
#include <cmath>
#include <vector>


//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Lists --
        template <typename T, typename>
        constexpr inline std::vector<T> list(const T last_) noexcept
        {
            return (list(T{}, last_, math::sign(last_)));
        }

        template <typename T, typename>
        constexpr inline std::vector<T> list(const T first_, const T last_) noexcept
        {
            return (list(first_, last_, math::sign(last_ - first_)));
        }

        template <typename T, typename>
        constexpr inline std::vector<T> list(const T first_, const T last_, const T spacing_) noexcept
        {
            assert(spacing_ != 0);
            assert(((last_ - first_) % spacing_) == 0);
            assert(((last_ - first_) * spacing_) > 0);

            std::vector<T> list(1 + static_cast<typename std::vector<T>::size_type>((last_ - first_) / spacing_));

            auto val{first_};
            for (auto& l : list)
            {
                l = val;
                val += spacing_;
            }

            return (list);
        }



    } // namespace range
} // namespace arc
