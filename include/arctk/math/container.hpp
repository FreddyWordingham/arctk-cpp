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



//  == IMPORTS ==
//  -- Std --
#include <type_traits>

//  -- Arctk --
#include <arctk/multi/vector.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace container //! container namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Iterator --
            template <typename T, typename C>
            inline size_t size(const C& cont_) noexcept;
            template <typename T, typename C>
            inline T sum(const C& cont_) noexcept;
            template <typename T, typename C>
            inline T ave(const C& cont_) noexcept;



        } // namespace container
    }     // namespace math
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/container.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_CONTAINER_HPP
