/**
 *  @file   arctk/data/image.inl
 *  @date   12/07/2018
 *  @author Freddy Wordingham
 *
 *  Image forming base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_IMAGE_INL
#define ARCTK_DATA_IMAGE_INL



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <cassert>
#include <fstream>

//  -- Arctk --
#include <arctk/math/vec3.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct an image with given dimensions in pixels.
         *
         *  @param  width_  Width of the image in pixels.
         *  @param  height_ Height of the image in pixels.
         *
         *  @pre    width_ must be positive.
         *  @pre    height_ must be positive.
         */
        inline Image::Image(const size_t width_, const size_t height_) noexcept
          : _width(width_)
          , _height(height_)
        {
            assert(width_ > 0);
            assert(height_ > 0);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the pixel width of the image.
         *
         *  @return Pixel width of the image.
         */
        inline size_t Image::width() const noexcept
        {
            return (_width);
        }

        /**
         *  Get the pixel height of the image.
         *
         *  @return Pixel height of the image.
         */
        inline size_t Image::height() const noexcept
        {
            return (_height);
        }


        //  -- Saving --
        /**
         *  Save the pixel data of the image in ppm format.
         *
         *  @param  path_   Path to the output file.
         *  @param  pixels_ Pixel data to save as a ppm image.
         *
         *  @pre    path_ may not be empty.
         *  @pre    pixels_ size must match _width.
         *  @pre    pixels_ first stored vector size must match _height.
         */
        inline void Image::write_ppm(const std::string& path_, const std::vector<std::vector<vec3>>& pixels_) const noexcept
        {
            assert(!path_.empty());
            assert(pixels_.size() == _width);
            assert(pixels_.front().size() == _height);

            std::ofstream file(path_);

            file << "P3\n"
                 << _width << " " << _height << "\n"
                 << "255\n";

            for (size_t i = 0; i < _height; ++i)
            {
                for (size_t j = 0; j < _width; ++j)
                {
                    for (size_t k = 0; k < 3; ++k)
                    {
                        file << std::clamp(static_cast<int>(255 * pixels_[j][_height - i - 1][k]), 0, 255) << "\t";
                    }
                    file << "\t";
                }
                file << "\n";
            }
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_IMAGE_INL
