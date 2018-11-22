/**
 *  @file   arctk/data/bin/regular/fixed.inl
 *  @date   22/11/2018
 *  @author Freddy Wordingham
 *
 *  Fixed range regular interval binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_REGULAR_FIXED_INL
#define ARCTK_DATA_BIN_REGULAR_FIXED_INL



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
            namespace regular //! regular interval namespace
            {



                //  == INSTANTIATION ==
                //  -- Constructors --
                template <typename T>
                inline Fixed<T>::Fixed(const double min_, const double max_, const size_t res_, const T& init_) noexcept
                  : Regular<T>(min_, max_, res_, init_)
                {
                    assert(min_ < max_);
                    assert(res_ > 0);
                }



                //  == OPERATORS ==
                //  -- Access --
                template <typename T>
                inline T& Fixed<T>::operator[](const double pos_) noexcept
                {
                    assert(pos_ >= Bin<T>::_min);
                    assert(pos_ <= Bin<T>::_max);

                    return (Bin<T>::_data[Regular<T>::index(pos_)]);
                }

                template <typename T>
                inline const T& Fixed<T>::operator[](const double pos_) const noexcept
                {
                    assert(pos_ >= Bin<T>::_min);
                    assert(pos_ <= Bin<T>::_max);

                    return (Bin<T>::_data[Regular<T>::index(pos_)]);
                }



            } // namespace regular
        }     // namespace bin
    }         // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_REGULAR_FIXED_INL
