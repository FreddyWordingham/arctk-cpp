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



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace sorter //! sorting namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --


            //  -- Destructors --
            /**
             *  Default destructor.
             */
            template <typename T>
            inline Regular<T>::~Regular() noexcept = default;



            //  == Methods ==
            //  -- Getters --



        } // namespace sorter
    }     // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_SORTER_IRREGULAR_INL
