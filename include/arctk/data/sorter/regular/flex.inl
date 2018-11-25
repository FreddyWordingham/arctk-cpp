/**
 *  @file   arctk/data/sorter/regular/flex.inl
 *  @date   25/11/2018
 *  @author Freddy Wordingham
 *
 *  Flexible range regular interval sorting class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_SORTER_REGULAR_FLEX_INL
#define ARCTK_DATA_SORTER_REGULAR_FLEX_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace sorter //! sorting namespace
        {
            namespace regular //! regular interval namespace
            {



                //  == INSTANTIATION ==
                //  -- Constructors --
                template <typename T>
                inline Flex<T>::Flex(const double min_, const double max_, const size_t res_, const T& init_) noexcept
                  : Regular<T>(min_, max_, res_, init_)
                {
                    assert(min_ < max_);
                    assert(res_ > 0);
                    assert((res_ % 2) == 0);
                }



                //  == OPERATORS ==
                //  -- Access --
                template <typename T>
                inline T& Fixed<T>::operator()(const double pos_) noexcept
                {
                    assert(pos_ >= Sorter<T>::_min);
                    assert(pos_ <= Sorter<T>::_max);

                    return (Sorter<T>::_data[Regular<T>::index(pos_)]);
                }

                template <typename T>
                inline const T& Fixed<T>::operator()(const double pos_) const noexcept
                {
                    assert(pos_ >= Sorter<T>::_min);
                    assert(pos_ <= Sorter<T>::_max);

                    return (Sorter<T>::_data[Regular<T>::index(pos_)]);
                }


                //  == METHODS ==
              private:
                //  -- Growth --
                template <typename T>
                inline void Flex<T>::ascend() noexcept
                {
                    Sorter<T>::_max += Sorter<T>::_max - Sorter<T>::_min;
                    Regular<T>::_interval *= 2.0;

                    for (size_t i = 0; i < (Sorter<T, 1>::_data.size() / 2); ++i)
                    {
                        const size_t index     = (2 * i);
                        Sorter<T, 1>::_data[i] = Histogram<T, 1>::_data[index] + Histogram<T, 1>::_data[index + 1];
                    }
                    for (size_t i = (Histogram<T, 1>::_data.size() / 2); i < Histogram<T, 1>::_data.size(); ++i)
                    {
                        Histogram<T, 1>::_data[i] = {};
                    }
                }

                template <typename T>
                inline void Flex<T>::descend() noexcept
                {
                }



            } // namespace regular
        }     // namespace sorter
    }         // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_SORTER_REGULAR_FLEX_INL
