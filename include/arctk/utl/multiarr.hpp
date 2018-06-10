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
        class MultiArrHelper
        {
            //  == TYPES ==
          public:
            //  -- Data --
            using S    = typename MultiArrHelper<T, M...>::type;
            using type = std::array<S, N>;
        };



        //  -- One-Dimensional --
        /**
         *  One-dimensional storage array class.
         *
         *  @tparam T   Type stored.
         *  @tparam N   Dimensionality of the array.
         */
        template <typename T, size_t N>
        class MultiArrHelper<T, N>
        {
            //  == TYPES ==
          public:
            //  -- Data --
            using type = std::array<T, N>;
        };



        //  == ALIASES ==
        //  -- MultiArr --
        template <typename T, size_t... M>
        using MultiArr = typename MultiArrHelper<T, M...>::type;



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_MULTIARR_HPP
