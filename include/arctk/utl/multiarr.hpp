/**
 *  @file   arctk/utl/multiarr.hpp
 *  @date   10/06/2018
 *  @author Freddy Wordingham
 *
 *  Mulit-dimensional array class.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_MULTIARR_HPP
#define ARCTK_UTL_MULTIARR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <array>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace utl //! utility namespace
    {



        //  == CLASSES ==
        //  -- N-Dimensional --
        /**
         *  N-Dimensional storage array class.
         *
         *  @tparam T   Type stored.
         *  @tparam N   Dimensionality of the array.
         *  @tparam M   Pack of lower dimensionalities.
         */
        template <typename T, size_t N, size_t... M>
        class _MultiArr // NOLINT
        {
            //  == TYPES ==
          public:
            //  -- Data --
            using stored = typename _MultiArr<T, M...>::type; //!< Type stored by this array.
            using type   = std::array<stored, N>;             //!< Type of this class.
        };



        //  -- One-Dimensional --
        /**
         *  One-dimensional storage array class.
         *
         *  @tparam T   Type stored.
         *  @tparam N   Dimensionality of the array.
         */
        template <typename T, size_t N>
        class _MultiArr<T, N>
        {
            //  == TYPES ==
          public:
            //  -- Data --
            using type = std::array<T, N>; //!< Type of this class.
        };



        //  == ALIASES ==
        //  -- MultiArr --
        /**
         *  Multi-array alias.
         *
         *  @tparam T   Type stored.
         *  @tparam M   Pack of dimensionalities.
         */
        template <typename T, size_t... M>
        using MultiArr = typename _MultiArr<T, M...>::type; // NOLINT



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_MULTIARR_HPP
