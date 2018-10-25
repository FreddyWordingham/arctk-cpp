/**
 *  @file   arctk/prop/order.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of order property functions.
 */



//  == GUARD ==
#ifndef ARCTK_PROP_ORDER_HPP
#define ARCTK_PROP_ORDER_HPP



//  == IMPORTS ==
//  -- Std --
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {
        namespace order //! ordering namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Order --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool ascending(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool descending(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool monotonic(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool uniform(const C& cont_) noexcept;



        } // namespace order
    }     // namespace prop
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/prop/order.inl>



//  == GUARD END ==
#endif // ARCTK_PROP_ORDER_HPP
