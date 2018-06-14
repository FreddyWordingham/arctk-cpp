/**
 *  @file   arctk/math/multivec.hpp
 *  @date   14/06/2018
 *  @author Freddy Wordingham
 *
 *  Mulit-vector mathematical functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MULTIVEC_HPP
#define ARCTK_MATH_MULTIVEC_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Arithmetic --
        template <typename T, size_t N>
        inline arc::utl::MultiVec<T, N> add(const arc::utl::MultiVec<T, N>& lhs_, const arc::utl::MultiVec<T, N>& rhs_) noexcept;



        //  == FUNCTIONS ==
        //  -- Arithmetic --
        template <typename T, size_t N>
        inline arc::utl::MultiVec<T, N> add(const arc::utl::MultiVec<T, N>& lhs_, const arc::utl::MultiVec<T, N>& rhs_) noexcept
        {
            assert(lhs_.size() == rhs_.size());

            arc::utl::MultiVec<T, N> vec(lhs_.size());

            for (size_t i = 0; i < lhs_.size(); ++i)
            {
                if constexpr (N == 1)
                {
                    vec[i] = lhs_[i] + rhs_[i];
                }
                else
                {
                    vec[i] = add<T, N - 1>(lhs_[i], rhs_[i]);
                }
            }

            return (vec);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_MULTIVEC_HPP
