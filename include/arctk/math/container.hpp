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
#include <arctk/type/temp.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace container //! container namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Iterator --
            template <typename T>
            inline size_t num_elem(const T& cont_) noexcept;
            template <typename T>
            inline typename type::temp::core_type<T>::type sum(const T& cont_) noexcept;
            template <typename T>
            inline typename type::temp::core_type<T>::type ave(const T& cont_) noexcept;
            template <typename T>
            inline typename type::temp::core_type<T>::type min(const T& cont_) noexcept;
            template <typename T>
            inline typename type::temp::core_type<T>::type max(const T& cont_) noexcept;



        } // namespace container
    }     // namespace math
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/container.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_CONTAINER_HPP
