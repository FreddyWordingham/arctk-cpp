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



        /**
         *  Structure used in helping the contruction of multi-dimensional vectors.
         *
         *  @tparam T   Type stored by the multi-dimensional vector.
         *  @tparam N   Size of this multi-dimensional vector.
         */
        template <class T, size_t N>
        struct vector_helper
        {
            using type = std::vector<typename vector_helper<T, N - 1>::type>;
        };

        /**
         *  Structure used in helping the contruction of multi-dimensional vectors.
         *
         *  @tparam T   Type stored by the multi-dimensional vector.
         */
        template <class T>
        struct vector_helper<T, 1>
        {
            using type = std::vector<T>;
        };



        //  == ALIASES ==
        template <class T, size_t N>
        using vector = typename vector_helper<T, N>::type;



    } // namespace multi
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MULTI_VECTOR_HPP
