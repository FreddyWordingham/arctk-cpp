/**
 *  @file   arctk/prop/limits.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of limits property functions.
 */



//  == GUARD ==
#ifndef ARCTK_PROP_LIMITS_HPP
#define ARCTK_PROP_LIMITS_HPP



//  == IMPORTS ==
//  -- Std --
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {
        namespace limits //! limits namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Limits --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool always_less_than(const C& cont_, const T& limit_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool always_less_than_or_equal_to(const C& cont_, const T& limit_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool always_greater_than(const C& cont_, const T& limit_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool always_greater_than_or_equal_to(const C& cont_, const T& limit_) noexcept;



        } // namespace limits
    }     // namespace prop
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/prop/limits.inl>



//  == GUARD END ==
#endif // ARCTK_PROP_LIMITS_HPP
