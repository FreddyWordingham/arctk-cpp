/**
 *  @file   arctk/data/bin.inl
 *  @date   20/11/2018
 *  @author Freddy Wordingham
 *
 *  Data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_INL
#define ARCTK_DATA_BIN_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, size_t N>
        inline Bin<T, N>::Bin(const vecN<N>& min_, const vecN<N>& max_, const std::array<size_t, N>& res_, const T& init_) noexcept
          : _min(min_)
          , _max(max_)
          , _res(res_)
          , _bins(multi::vector_helper<T, N>::shape(res_, init_))
        {
            for (size_t i = 0; i < N; ++i)
            {
                assert(min_[i] < max_[i]);
                assert(res_[i] > 0);
            }
        }



        //  == METHODS ==
        //  -- Checking --



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_INL
