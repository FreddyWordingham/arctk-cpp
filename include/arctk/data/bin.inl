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
        const std::vector<T>& Bin<T>::data() const noexcept
        {
            return (_data);
        }

        template <typename T>
        inline size_t Bin<T>::size() const noexcept
        {
            return (_data.size());
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_INL
