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
            using S    = typename MultiVecHelper<T, N - 1>::type;
            using type = std::vector<S>;
        };



        //  -- One-Dimensional --
        /**
         *  One-dimensional storage vector class.
         *
         *  @tparam T   Type storef.
         */
        template <typename T>
        class MultiVecHelper<T, 1>
        {
            //  == TYPES ==
          public:
            //  -- Data --
            using type = std::vector<T>;
        };



        //  == ALIASES ==
        //  -- MultiVec --
        template <typename T, size_t N>
        using MultiVec = typename MultiVecHelper<T, N>::type;



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_MULTIARR_HPP
