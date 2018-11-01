/**
 *  @file   arctk/multi/vector.hpp
 *  @date   31/10/2018
 *  @author Freddy Wordingham
 *
 *  Multi-dimensional vector aliases.
 */



//  == GUARD ==
#ifndef ARCTK_MULTI_VECTOR_HPP
#define ARCTK_MULTI_VECTOR_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace multi //! multiple-dimension namespace
    {



        template <class T, size_t N>
        struct vector_helper;

        template <class T>
        struct vector_helper<T, 1>
        {
            using type = std::vector<T>;
        };

        template <class T, size_t N>
        struct vector_helper
        {
            using type = std::vector<typename vector_helper<T, N - 1>::type>;
        };



        //  == ALIASES ==
        template <class T, size_t N>
        using vector = typename vector_helper<T, N>::type;



    } // namespace multi
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MULTI_VECTOR_HPP
