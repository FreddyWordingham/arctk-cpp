/**
 *  @file   arctk/math/container.hpp
 *  @date   07/10/2018
 *  @author Freddy Wordingham
 *
 *  Math container functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_CONTAINER_HPP
#define ARCTK_MATH_CONTAINER_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace container //! container namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Iterator --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline T sum(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline T ave(const C& cont_) noexcept;



        } // namespace container
    }     // namespace math
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/container.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_CONTAINER_HPP
