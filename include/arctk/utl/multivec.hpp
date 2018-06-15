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
        class _MultiVec
        {
            //  == TYPES ==
          public:
            //  -- Data --
            using S    = typename _MultiVec<T, N - 1>::type; //!< Type stored by this vector.
            using type = std::vector<S>;                     //!< Type of this class.


            //  == INSTANTIATION ==
          public:
            //  -- Factories --
            static inline type make(const std::array<size_t, N>& dim_) noexcept;


            //  == METHODS ==
          public:
            //  -- Setters --
            static inline void reset(type& vec_) noexcept;
        };


        //  -- One-Dimensional --
        /**
         *  One-dimensional storage vector class.
         *
         *  @tparam T   Type stored.
         */
        template <typename T>
        class _MultiVec<T, 1>
        {
            //  == TYPES ==
          public:
            //  -- Data --
            using type = std::vector<T>; //!< Type of this class.


            //  == INSTANTIATION ==
          public:
            //  -- Factories --
            static inline type make(const std::array<size_t, 1>& dim_) noexcept;


            //  == METHODS ==
          public:
            //  -- Setters --
            static inline void reset(type& vec_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Factories --
        /**
         *  Create a N-dimensional multi-vec object.
         *
         *  @tparam T   Type stored.
         *  @tparam N   Dimensionality of the vector.
         *
         *  @param  dim_    Dimensionality.
         *
         *  @return Created N-dimensional multi-vec object.
         */
        template <typename T, size_t N>
        inline typename _MultiVec<T, N>::type _MultiVec<T, N>::make(const std::array<size_t, N>& dim_) noexcept
        {
            std::array<size_t, N - 1> dim;
            std::copy(std::next(std::begin(dim_)), std::end(dim_), std::begin(dim));

            type vec(dim_.front(), _MultiVec<T, N - 1>::make(dim));

            return (vec);
        }

        /**
         *  Create a one-dimensional multi-vec object.
         *
         *  @tparam T   Type stored.
         *
         *  @param  dim_    Dimensionality.
         *
         *  @return Created one-dimensional multi-vec object.
         */
        template <typename T>
        inline typename _MultiVec<T, 1>::type _MultiVec<T, 1>::make(const std::array<size_t, 1>& dim_) noexcept
        {
            type vec(dim_.front());

            return (vec);
        }



        //  == METHODS ==
        //  -- Setters --
        /**
         *  Reset all end values stored by a multi-dimensional MultiVec to their defaults.
         *
         *  @tparam T   Type stored.
         *  @tparam N   Dimensionality of the vector.
         *
         *  @param  vec_    MultiVec to be reset.
         */
        template <typename T, size_t N>
        inline void _MultiVec<T, N>::reset(type& vec_) noexcept
        {
            for (size_t i = 0; i < vec_.size(); ++i)
            {
                _MultiVec<T, N - 1>::reset(vec_[i]);
            }
        }

        /**
         *  Reset all end values stored by a one-dimensional MultiVec to their defaults.
         *
         *  @tparam T   Type stored.
         *
         *  @param  vec_    MultiVec to be reset.
         */
        template <typename T>
        inline void _MultiVec<T, 1>::reset(type& vec_) noexcept
        {
            for (size_t i = 0; i < vec_.size(); ++i)
            {
                vec_[i] = {};
            }
        }



        //  == ALIASES ==
        //  -- MultiVec --
        /**
         *  Multi-vector alias.
         *
         *  @tparam T   Type stored.
         *  @tparam N   Dimensionality.
         */
        template <typename T, size_t N>
        using MultiVec = typename _MultiVec<T, N>::type;


        /**
         *  Multi-vector size initialisation alias.
         *
         *  @tparam T   Type stored.
         *  @tparam N   Dimensionality.
         */
        template <typename T, size_t N>
        constexpr auto make_MultiVec = _MultiVec<T, N>::make;


        /**
         *  Multi-vector reset initialisation alias.
         *
         *  @tparam T   Type stored.
         *  @tparam N   Dimensionality.
         */
        template <typename T, size_t N>
        constexpr auto reset_MultiVec = _MultiVec<T, N>::reset;



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_MULTIVEC_HPP
