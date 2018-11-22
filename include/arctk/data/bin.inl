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
        //  -- Constructors --
        template <typename T>
        inline Bin<T>::Bin(const double min_, const double max_, const size_t res_, const T& init_) noexcept
          : _min(min_)
          , _max(max_)
          , _data(res_, init_)
        {
            assert(min_ < max_);
            assert(res_ > 0);
        }



        //  == OPERATORS ==
        //  -- Access --
        template <typename T>
        inline T& Bin<T>::operator[](const size_t index_) noexcept
        {
            return (_data[index_]);
        }

        template <typename T>
        inline const T& Bin<T>::operator[](const size_t index_) const noexcept
        {
            return (_data[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T>
        inline double Bin<T>::min() const noexcept
        {
            return (_min);
        }

        template <typename T>
        inline double Bin<T>::max() const noexcept
        {
            return (_max);
        }

        template <typename T>
        inline const std::vector<T>& Bin<T>::data() const noexcept
        {
            return (_data);
        }

        template <typename T>
        inline size_t Bin<T>::res() const noexcept
        {
            return (_data.size());
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_INL
