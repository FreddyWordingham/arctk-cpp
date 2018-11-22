/**
 *  @file   arctk/data/bin/regular.inl
 *  @date   22/11/2018
 *  @author Freddy Wordingham
 *
 *  Fixed range regular interval binning class.
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
            inline Regular<T>::Regular(double min_, double max_, size_t res_, const T& init_ = {}) noexcept
            {
            }



            //  == OPERATORS ==
            //  -- Access --



        } // namespace bin
    }     // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_REGULAR_INL
