/**
 *  @file   arctk/data/obj.inl
 *  @date   06/11/2018
 *  @author Freddy Wordingham
 *
 *  Data object class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_OBJ_INL
#define ARCTK_DATA_OBJ_INL



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
        inline Obj::Obj(const std::string& str_) noexcept
          : _data(init_data(str_))
        {
            assert(!str_.empty());
        }



        //  == METHODS ==



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_OBJ_INL
