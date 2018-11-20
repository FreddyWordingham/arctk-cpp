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
        //  -- Indexing --
        template <typename T>
        inline size_t Bin<T>::index(const double val_) const noexcept
        {
            assert(val_ >= min_);
            assert(val_ <= max_);

            const size_t index = static_cast<size_t>((val_ - _min) / _bin_width);

            return ((index == _data.size()) ? (index - 1) : index);
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_INL
