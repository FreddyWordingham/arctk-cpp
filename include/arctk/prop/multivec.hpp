/**
 *  @file   arctk/prop/multivec.hpp
 *  @date   22/06/2018
 *  @author Freddy Wordingham
 *
 *  Multi-Vec proprty functions.
 */



//  == GUARD ==
#ifndef ARCTK_PROP_MULTIVEC_HPP
#define ARCTK_PROP_MULTIVEC_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Layout --
        template <typename T>
        inline bool rectangular(const utl::MultiVec<T, 2>& pixels) noexcept;



        //  == FUNCTIONS ==
        //  -- Layout --
        /**
         *  Check if a two dimensional vector may be considered rectangular.
         *  Check if each vector stored within a vector are of the same length.
         *
         *  @tparam T   Base type stored by the multi-vec.
         *
         *  @param  vec MulitVec to test.
         *
         *  @return True if all vectors stored by the vector are of the same length.
         */
        template <typename T>
        inline bool rectangular(const utl::MultiVec<T, 2>& vec) noexcept
        {
            if (vec.empty())
            {
                return (true);
            }

            const size_t size = vec.front().size();
            for (size_t i = 1; i < vec.size(); ++i)
            {
                if (vec[i].size() != size)
                {
                    return (false);
                }
            }

            return (true);
        }



    } // namespace prop
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PROP_MULTIVEC_HPP
