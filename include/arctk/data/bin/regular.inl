/**
 *  @file   arctk/data/bin/regular.inl
 *  @date   22/11/2018
 *  @author Freddy Wordingham
 *
 *  Regular interval binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_REGULAR_INL
#define ARCTK_DATA_BIN_REGULAR_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace bin //! binning namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T>
            inline Regular<T>::Regular(const double min_, const double max_, const size_t res_, const T& init_) noexcept
              : Bin<T>(min_, max_, res_, init_)
              , _interval((max_ - min_) / res_)
            {
                assert(min_ < max_);
                assert(res_ > 0);
            }



            //  == Methods ==
            //  -- Getters --
            template <typename T>
            inline double Regular<T>::interval() const noexcept
            {
                return (_interval);
            }



        } // namespace bin
    }     // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_REGULAR_INL
