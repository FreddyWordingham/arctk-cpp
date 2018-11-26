/**
 *  @file   arctk/data/sorter/irregular/fixed.inl
 *  @date   25/11/2018
 *  @author Freddy Wordingham
 *
 *  Fixed range irregular interval sorting class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_SORTER_IRREGULAR_FIXED_INL
#define ARCTK_DATA_SORTER_IRREGULAR_FIXED_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/prop/order.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace sorter //! sorting namespace
        {
            namespace irregular //! irregular interval namespace
            {



                //  == INSTANTIATION ==
                //  -- Constructors --
                template <typename T>
                inline Fixed<T>::Fixed(const std::vector<double>& bounds_, const T& init_) noexcept
                  : Irregular<T>(bounds_, init_)
                {
                    assert(prop::order::ascending(bounds_));
                    assert(bounds_.size() >= 2);
                }



                //  == OPERATORS ==
                //  -- Call --
                template <typename T>
                inline T& Fixed<T>::operator()(const double pos_) noexcept
                {
                    assert(pos_ >= Sorter<T>::_min);
                    assert(pos_ <= Sorter<T>::_max);

                    return (Sorter<T>::_data[Irregular<T>::index(pos_)]);
                }

                template <typename T>
                inline const T& Fixed<T>::operator()(const double pos_) const noexcept
                {
                    assert(pos_ >= Sorter<T>::_min);
                    assert(pos_ <= Sorter<T>::_max);

                    return (Sorter<T>::_data[Irregular<T>::index(pos_)]);
                }



            } // namespace irregular
        }     // namespace sorter
    }         // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_SORTER_IRREGULAR_FIXED_INL
