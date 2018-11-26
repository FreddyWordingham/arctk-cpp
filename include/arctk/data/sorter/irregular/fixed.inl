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

                template <typename T>
                inline Irregular<T>::Irregular(const std::vector<double>& bounds_, const T& init_) noexcept
                  : Sorter<T>(bounds_.front(), bounds_.back(), bounds_.size() - 1, init_)
                  , _bounds(bounds_)
                {
                    assert(prop::order::ascending(bounds_));
                    assert(bounds_.size() >= 2);
                }

                //  == OPERATORS ==
                //  -- Call --



            } // namespace irregular
        }     // namespace sorter
    }         // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_SORTER_IRREGULAR_FIXED_INL
