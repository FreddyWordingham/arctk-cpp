/**
 *  @file   arctk/utl/multivec.hpp
 *  @date   10/06/2018
 *  @author Freddy Wordingham
 *
 *  Mulit-dimensional vector class.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_MULTIVEC_HPP
#define ARCTK_UTL_MULTIVEC_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace utl //! utility namespace
    {



        //  == CLASSES ==
        //  -- N-Dimensional --
        /**
         *  N-Dimensional storage vector class.
         *
         *  @tparam T   Type stored.
         *  @tparam N   Dimensionality of the vector.
         */
        template <typename T, size_t N>
        class MultiVecHelper
        {
            //  == TYPES ==
          public:
            //  -- Data --
            using S    = typename MultiVecHelper<T, N - 1>::type; //!< Type stored by this vector.
            using type = std::vector<S>;                          //!< Type of this class.


            //  == INSTANTIATION ==
          public:
            //  -- Methods --
            static type size(const std::array<size_t, N>& dim_, const T& val_ = {})
            {
                std::array<size_t, N - 1> dim;
                std::copy(std::next(std::begin(dim_)), std::end(dim_), std::begin(dim));

                type vec(dim_.front(), MultiVecHelper<T, N - 1>::size(dim, val_));

                return (vec);
            }
        };



        //  -- One-Dimensional --
        /**
         *  One-dimensional storage vector class.
         *
         *  @tparam T   Type stored.
         */
        template <typename T>
        class MultiVecHelper<T, 1>
        {
            //  == TYPES ==
          public:
            //  -- Data --
            using type = std::vector<T>; //!< Type of this class.


            //  == INSTANTIATION ==
          public:
            //  -- Methods --
            static type size(const std::array<size_t, 1>& dim_, const T& val_ = {})
            {
                type vec(dim_.front(), val_);

                return (vec);
            }
        };



        //  == ALIASES ==
        //  -- MultiVec --
        /**
         *  Multi-vector alias.
         *
         *  @tparam T   Type stored.
         *  @tparam N   Dimensionality.
         */
        template <typename T, size_t N>
        using MultiVec = typename MultiVecHelper<T, N>::type;


        /**
         *  Multi-vector size initialisation alias.
         *
         *  @tparam T   Type stored.
         *  @tparam N   Dimensionality.
         */
        template <typename T, size_t N>
        constexpr auto MultiVecSize = MultiVecHelper<T, N>::size;



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_MULTIVEC_HPP
