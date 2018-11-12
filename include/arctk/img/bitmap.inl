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
#include <arctk/prop/shape.hpp>



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
          , _scale_map([](const double x_) { return (x_); })
          , _colour_map([](const double x_) { return (vec3(x_, x_, x_)); })
        {
            assert(prop::shape::square(pixels_));
            assert(_max >= _min);
        }



        //  == OPERATORS ==
        //  -- Access --
        inline std::vector<double>& Bitmap::operator[](const size_t index_) noexcept
        {
            assert(index_ <= _pixels.size());

            return (_pixels[index_]);
        }

        inline const std::vector<double>& Bitmap::operator[](const size_t index_) const noexcept
        {
            assert(index_ <= _pixels.size());

            return (_pixels[index_]);
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

        inline void Bitmap::set_scale_map(std::function<double(double)> scale_map_) noexcept
        {
            _scale_map = scale_map_;
        }

        inline void Bitmap::set_colour_map(std::function<vec3(double)> colour_map_) noexcept
        {
            _colour_map = colour_map_;
        }



    } // namespace img
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IMG_BITMAP_INL
