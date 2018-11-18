/**
 *  @file   arctk/img/bitmap/greyscale.inl
 *  @date   12/11/2018
 *  @author Freddy Wordingham
 *
 *  Greyscale bitmap image class.
 */



//  == GUARD ==
#ifndef ARCTK_IMG_BITMAP_GREYSCALE_INL
#define ARCTK_IMG_BITMAP_GREYSCALE_INL



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <cassert>
#include <fstream>

//  -- Arctk --
#include <arctk/math/container.hpp>
#include <arctk/prop/shape.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace img //! image namespace
    {
        namespace bitmap //! bitmap namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Greyscale::Greyscale(const multi::vector<double, 2>& pixels_) noexcept
              : _pixels(pixels_)
              , _min(math::container::min(pixels_))
              , _max(math::container::max(pixels_))
              , _scale_map([](const double x_) { return (x_); })
              , _colour_map([](const double x_) { return (vec3(x_, x_, x_)); })
            {
                assert(prop::shape::square(pixels_));
                assert(!pixels_.empty());
                assert(!pixels_.front().empty());
                assert(_max >= _min);
            }



            //  == OPERATORS ==
            //  -- Access --
            inline std::vector<double>& Greyscale::operator[](const size_t index_) noexcept
            {
                assert(index_ <= _pixels.size());

                return (_pixels[index_]);
            }

            inline const std::vector<double>& Greyscale::operator[](const size_t index_) const noexcept
            {
                assert(index_ <= _pixels.size());

                return (_pixels[index_]);
            }



            //  == METHODS ==
            //  -- Getters --
            inline size_t Greyscale::width() const noexcept
            {
                return (_pixels.size());
            }

            inline size_t Greyscale::height() const noexcept
            {
                return (_pixels.front().size());
            }


            //  -- Setters --
            inline void Greyscale::set_min(const double min_) noexcept
            {
                assert(min_ <= _max);

                _min = min_;
            }

            inline void Greyscale::set_max(const double max_) noexcept
            {
                assert(max_ >= _min);

                _max = max_;
            }

            inline void Greyscale::set_scale_map(std::function<double(double)> scale_map_) noexcept
            {
                _scale_map = scale_map_;
            }

            inline void Greyscale::set_colour_map(std::function<vec3(double)> colour_map_) noexcept
            {
                _colour_map = colour_map_;
            }


            //  -- Saving --
            /**
             *  Save the state of the bitmap as an ppm image.
             *
             *  @param  path_   Path to the images save location.
             *
             *  @pre    path_ may not be empty.
             */
            inline void Greyscale::save(const std::string& path_) const noexcept
            {
                assert(!path_.empty());

                multi::vector<vec3, 2> pixels(_pixels.size(), std::vector<vec3>(_pixels.front().size()));

                const size_t width  = pixels.size();
                const size_t height = pixels.front().size();

                const double range = _max - _min;

                for (size_t i = 0; i < width; ++i)
                {
                    for (size_t j = 0; j < height; ++j)
                    {
                        pixels[i][j] = _colour_map(_scale_map((_pixels[i][j] - _min) / range));
                    }
                }

                std::ofstream file(path_ + ".ppm");

                file << "P3\n"
                     << width << " " << height << "\n"
                     << "255\n";

                for (size_t i = 0; i < width; ++i)
                {
                    for (size_t j = 0; j < height; ++j)
                    {
                        for (size_t k = 0; k < 3; ++k)
                        {
                            file << std::setw(4) << std::clamp(static_cast<int>(255 * pixels[i][j][k]), 0, 255);
                        }
                    }
                    file << '\t';
                }
                file << '\n';
            }



        } // namespace bitmap
    }     // namespace img
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IMG_BITMAP_GREYSCALE_INL
