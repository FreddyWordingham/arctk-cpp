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



        /**
         *  Structure used in helping the contruction of multi-dimensional arrays.
         *
         *  @tparam T   Type stored by the multi-dimensional array.
         *  @tparam N   Size of this multi-dimensional array.
         *  @tparam Ns  Sizes of child arrays.
         */
        template <class T, size_t N, size_t... Ns>
        struct array_helper // NOLINT
        {
            using type = std::array<typename array_helper<T, Ns...>::type, N>; //!< Type alias.
        };

        /**
         *  Structure used in helping the contruction of multi-dimensional arrays.
         *
         *  @tparam T   Type stored by the multi-dimensional array.
         *  @tparam N   Size of this multi-dimensional array.
         */
        template <class T, size_t N>
        struct array_helper<T, N> // NOLINT
        {
            using type = std::array<T, N>; //!< Type alias.
        };



        //  == ALIASES ==
        /**
         *  Alias used to construct multi-dimensional arrays.
         *
         *  @tparam T   Type stored by the multi-dimensional array.
         *  @tparam Ns  Size of each array dimension.
         */
        template <class T, size_t... Ns>
        using array = typename array_helper<T, Ns...>::type;



    } // namespace multi
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MULTI_ARRAY_HPP
