/**
 *  @file   arctk/data/sorter/irregular.inl
 *  @date   25/11/2018
 *  @author Freddy Wordingham
 *
 *  Irregular interval sorting class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_SORTER_IRREGULAR_INL
#define ARCTK_DATA_SORTER_IRREGULAR_INL



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



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T>
            inline Irregular<T>::Irregular(const std::vector<double>& bounds_, const T& init_) noexcept
              : Sorter<T>(bounds_.front(), bounds_.back(), bounds_.size() - 1, init_)
              , _bounds(bounds_)
            {
                assert(prop::order::ascending(bounds_));
                assert(bounds_.size() >= 2);
            }


            //  -- Destructors --
            /**
             *  Default destructor.
             */
            template <typename T>
            inline Irregular<T>::~Irregular() noexcept = default;



            //  == Methods ==
            //  -- Getters --
            template <typename T>
            inline std::vector<double> Irregular<T>::bounds() const noexcept
            {
                return (_bounds);
            }

            //  -- Indexing --
            template <typename T>
            inline size_t Irregular<T>::index(double pos_) const noexcept
            {
            }



        } // namespace sorter
    }     // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_SORTER_IRREGULAR_INL
