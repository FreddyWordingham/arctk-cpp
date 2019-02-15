//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/compare.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/type/is_iterable.hpp"

//  -- Arc --
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    inline namespace range
    {



        //  == OPERATORS ==
        //  -- Compare --
        template <typename C, typename T, typename = typename std::enable_if<type::is_iterable<C>::value && !type::is_iterable<T>::value>::type>
        constexpr inline bool operator==(const C& lhs_, const T& rhs_) noexcept
        {
            for (const auto& l : lhs_)
            {
                if (!(l == rhs_))
                {
                    return (false);
                }
            }

            return (true);
        }

        template <typename C, typename T, typename = typename std::enable_if<type::is_iterable<C>::value && !type::is_iterable<T>::value>::type>
        constexpr inline bool operator!=(const C& lhs_, const T& rhs_) noexcept
        {
            for (const auto& l : lhs_)
            {
                if (!(l != rhs_))
                {
                    return (false);
                }
            }

            return (true);
        }

        template <typename C, typename T, typename = typename std::enable_if<type::is_iterable<C>::value && !type::is_iterable<T>::value>::type>
        constexpr inline bool operator<(const C& lhs_, const T& rhs_) noexcept
        {
            for (const auto& l : lhs_)
            {
                if (!(l < rhs_))
                {
                    return (false);
                }
            }

            return (true);
        }

        template <typename C, typename T, typename = typename std::enable_if<type::is_iterable<C>::value && !type::is_iterable<T>::value>::type>
        constexpr inline bool operator>(const C& lhs_, const T& rhs_) noexcept
        {
            for (const auto& l : lhs_)
            {
                if (!(l > rhs_))
                {
                    return (false);
                }
            }

            return (true);
        }

        template <typename C, typename T, typename = typename std::enable_if<type::is_iterable<C>::value && !type::is_iterable<T>::value>::type>
        constexpr inline bool operator<=(const C& lhs_, const T& rhs_) noexcept
        {
            for (const auto& l : lhs_)
            {
                if (!(l <= rhs_))
                {
                    return (false);
                }
            }

            return (true);
        }

        template <typename C, typename T, typename = typename std::enable_if<type::is_iterable<C>::value && !type::is_iterable<T>::value>::type>
        constexpr inline bool operator>=(const C& lhs_, const T& rhs_) noexcept
        {
            for (const auto& l : lhs_)
            {
                if (!(l >= rhs_))
                {
                    return (false);
                }
            }

            return (true);
        }



    } // namespace range
} // namespace arc
