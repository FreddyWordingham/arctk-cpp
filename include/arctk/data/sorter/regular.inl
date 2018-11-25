/**
 *  @file   arctk/data/sorter/regular.inl
 *  @date   22/11/2018
 *  @author Freddy Wordingham
 *
 *  Regular interval sorting class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_SORTER_REGULAR_INL
#define ARCTK_DATA_SORTER_REGULAR_INL



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



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T>
            inline Regular<T>::Regular(const double min_, const double max_, const size_t res_, const T& init_) noexcept
              : Sorter<T>(min_, max_, res_, init_)
              , _interval((max_ - min_) / res_)
            {
                assert(min_ < max_);
                assert(res_ > 0);
            }


            //  -- Destructors --
            /**
             *  Default destructor.
             */
            template <typename T>
            inline Regular<T>::~Regular() noexcept = default;



            //  == Methods ==
            //  -- Getters --
            template <typename T>
            inline std::vector<double> Regular<T>::bounds() const noexcept
            {
                std::vector<double> bounds(Sorter<T>::_data.size() + 1);

                bounds.front() = Sorter<T>::_min;
                bounds.back()  = Sorter<T>::_max;

                for (size_t i = 1; i < (bounds.size() - 1); ++i)
                {
                    bounds[i] = Sorter<T>::_min + (i * _interval);
                }

                return (bounds);
            }

            template <typename T>
            inline double Regular<T>::interval() const noexcept
            {
                return (_interval);
            }


            //  -- Indexing --
            template <typename T>
            inline size_t Regular<T>::index(const double pos_) const noexcept
            {
                assert(pos_ >= Sorter<T>::_min);
                assert(pos_ <= Sorter<T>::_max);

                const size_t index = static_cast<size_t>((pos_ - Sorter<T>::_min) / _interval);

                return ((index == Sorter<T>::_data.size()) ? (index - 1) : index);
            }



        } // namespace sorter
    }     // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_SORTER_REGULAR_INL
