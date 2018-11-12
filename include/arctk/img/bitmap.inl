/**
 *  @file   arctk/img/bitmap.inl
 *  @date   12/11/2018
 *  @author Freddy Wordingham
 *
 *  Bitmap image class.
 */



//  == GUARD ==
#ifndef ARCTK_IMG_BITMAP_INL
#define ARCTK_IMG_BITMAP_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/math/container.hpp>
#include <arctk/prop/limits.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace img //! image namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Bitmap::Bitmap(const multi::vector<double, 2>& pixels_) noexcept
          : _pixels(pixels_)
          , _min(math::container::min(pixels_))
          , _max(math::container::max(pixels_))
        {
            //            assert(prop::limits::always_greater_than_or_equal_to(pixels_)); TODO
            assert(_min >= 0.0);
        }



        //  == METHODS ==



    } // namespace img
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IMG_BITMAP_INL
