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
#include <array>
#include <cassert>
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
         *  @tparam N   Dimensionality of the multi-dimensional vector.
         */
        template <class T, size_t N>
        struct vector_helper // NOLINT
        {
            //  == ALIASES ==
          public:
            //  -- Type --
            using type = std::vector<typename vector_helper<T, N - 1>::type>; //!< Type alias.


            //  == METHODS ==
          public:
            //  -- Factories --
            static type shape(const std::array<size_t, N>& size_) noexcept
            {
                std::array<size_t, N - 1> size;
                for (size_t i = 1; i < N; ++i)
                {
                    size[i - 1] = size_[i];
                }

                return (type(size_[0], vector_helper<T, N - 1>::shape(size)));
            }
        };

        /**
         *  Structure used in helping the contruction of multi-dimensional vectors.
         *
         *  @tparam T   Type stored by the multi-dimensional vector.
         */
        template <class T>
        struct vector_helper<T, 1> // NOLINT
        {
            //  == ALIASES ==
          public:
            //  -- Type --
            using type = std::vector<T>; //!< Type alias.


            //  == METHODS ==
          public:
            //  -- Factories --
            static type shape(const std::array<size_t, 1>& size_) noexcept
            {
                return (std::vector<T>(size_[0]));
            }
        };



        //  == ALIASES ==
        /**
         *  Alias used to construct multi-dimensional vectors.
         *
         *  @tparam N   Dimensionality of the multi-dimensional vector.
         */
        template <class T, size_t N>
        using vector = typename vector_helper<T, N>::type;



    } // namespace multi
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MULTI_VECTOR_HPP
