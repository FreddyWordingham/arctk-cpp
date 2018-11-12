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
            assert(_max >= _min);
        }



        //  == METHODS ==
        //  -- Setters --
        inline void Bitmap::set_min(const double min_) noexcept
        {
            assert(min_ <= _max);

            _min = min_;
        }

        inline void Bitmap::set_max(const double max_) noexcept
        {
            assert(max_ >= _min);

            _max = max_;
        }



    } // namespace img
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IMG_BITMAP_INL
