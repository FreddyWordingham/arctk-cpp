/**
 *  @file   arctk/multi/array.hpp
 *  @date   01/11/2018
 *  @author Freddy Wordingham
 *
 *  Multi-dimensional array aliases.
 */



//  == GUARD ==
#ifndef ARCTK_MULTI_ARRAY_HPP
#define ARCTK_MULTI_ARRAY_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace multi //! multiple-dimension namespace
    {



        template <class T, size_t N, size_t... Ns>
        struct array_helper
        {
            using type = std::array<typename array_helper<T, Ns...>::type, N>;
        };

        template <class T, size_t N>
        struct array_helper<T, N>
        {
            using type = std::array<T, N>;
        };



        //  == ALIASES ==
        template <class T, size_t N>
        using array = typename array_helper<T, N...>::type;



    } // namespace multi
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MULTI_ARRAY_HPP
