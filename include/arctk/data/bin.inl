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
        template <typename T>
        inline Bin<T>::Bin(const double min_, const double max_, const double res_, const T& init_) noexcept
          : _min(min_)
          , _max(max_)
          , _bin_width((max_ - min_) / res_)
          , _data(res_, init_)
        {
            assert(min_ < max_);
            assert(res_ > 0);
        }



        //  == METHODS ==
        //  -- Checking --



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_INL
