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
          , _bins(multi::vector_helper<T, N>::shape(res_, init_))
        {
        }



        //  == METHODS ==
        //  -- Checking --



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_INL
