/**
 *  @file   arctk/multivec.hpp
 *  @date   10/06/2018
 *  @author Freddy Wordingham
 *
 *  Mulit-dimensional vector class.
 */



//  == GUARD ==
#ifndef ARCTK_STD_MULTIVEC_HPP
#define ARCTK_STD_MULTIVEC_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace std //! standard library expansion namespace
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
        class MulitVec
        {
            //  == TYPES ==
            //  -- Data --
            using S    = typename MulitVec<T, N - 1>::type;
            using type = std::vector<S>;
        };



        //  -- One-Dimensional --
        /**
         *  One-dimensional storage vector class.
         *
         *  @tparam T   Type storef.
         */
        template <typename T>
        class MultiVec<T, 1>
        {
            using type = std::vector<T>;
        };



    } // namespace std
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STD_MULTIVEC_HPP
