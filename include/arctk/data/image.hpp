/**
 *  @file   arctk/data/image.hpp
 *  @date   15/06/2018
 *  @author Freddy Wordingham
 *
 *  Image forming class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_IMAGE_HPP
#define ARCTK_DATA_IMAGE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/math.hpp>
#include <arctk/sys.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Image data writer.
         */
        class Image
        {
            //  == FIELDS ==
          private:
            //  -- Information --
            const size_t _width;  //!< Width of the image in pixels.
            const size_t _height; //!< Height of the image in pixels.

            //  -- Data --
            utl::MultiVec<vec3i, 2> _pixels; //!< Pixel data of the image.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Image(size_t width_, size_t height_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline size_t width() noexcept;
            inline size_t height() noexcept;

            //  -- Collection --
            inline void collect(size_t col_, size_t row_, int val_) noexcept;
            inline void collect(size_t col_, size_t row_, const vec3i& val_) noexcept;

            //  -- Saving --
            inline void save(const std::string& path_) const noexcept;
            inline void save(const std::string& path_, int norm_) const noexcept;
            inline void save(const std::string& path_, const vec3i& norm_) const noexcept;
        };



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
        inline Image::Image(size_t width_, size_t height_) noexcept
          : _width(width_)
          , _height(height_)
          , _pixels(utl::make_MultiVec<vec3i, 2>({{width_, height_}}))
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
        inline size_t Image::width() noexcept
        {
            return (_width);
        }

        /**
         *  Get the pixel height of the image.
         *
         *  @return Pixel height of the image.
         */
        inline size_t Image::height() noexcept
        {
            return (_height);
        }


        //  -- Collection --
        /**
         *  Collect an integer value into the pixel array.
         *  All channels are increased uniformly.
         *
         *  @param  col_    Column of pixel to add value to.
         *  @param  row_    Row of pixel to add value to.
         *  @param  val_    Value to add to pixel.
         *
         *  @pre    col_ must be less than _width;
         *  @pre    row_ must be less than _height;
         *  @pre    val_ must be non-negative.
         */
        inline void Image::collect(const size_t col_, const size_t row_, const int val_) noexcept
        {
            assert(col_ < _width);
            assert(row_ < _height);
            assert(val_ >= 0);

            _pixels[col_][row_] += val_;
        }

        /**
         *  Collect a colour value into the pixel array.
         *
         *  @param  col_    Column of pixel to add value to.
         *  @param  row_    Row of pixel to add value to.
         *  @param  val_    Value to add to pixel.
         *
         *  @pre    col_ must be less than _width;
         *  @pre    row_ must be less than _height;
         *  @pre    val_ components must all be non-negative.
         */
        inline void Image::collect(const size_t col_, const size_t row_, const vec3i& val_) noexcept
        {
            assert(col_ < _width);
            assert(row_ < _height);
            assert(val_.r >= 0);
            assert(val_.g >= 0);
            assert(val_.b >= 0);

            _pixels[col_][row_] += val_;
        }


        //  -- Saving --
        /**
         *  Save the image as a ppm file.
         *  Pixel data is normalised using the maximum value of the pixels.
         *
         *  @param  path_   Path to save file.
         *
         *  @pre    path_ may not be empty.
         */
        inline void Image::save(const std::string& path_) const noexcept
        {
            assert(!path_.empty());

            int max = 0;
            for (size_t i = 0; i < _height; ++i)
            {
                for (size_t j = 0; j < _width; ++j)
                {
                    for (size_t k = 0; k < 3; ++k)
                    {
                        if (_pixels[j][i][k] > max)
                        {
                            max = _pixels[j][i][k];
                        }
                    }
                }
            }

            if (max == 0)
            {
                max = 1;
            }

            save(path_, max);
        }

        /**
         *  Save the image as a ppm file.
         *  Pixel data is normalised using a given value.
         *
         *  @param  path_   Path to save file.
         *
         *  @pre    path_ may not be empty.
         *  @pre    norm_ must be positive.
         */
        inline void Image::save(const std::string& path_, const int norm_) const noexcept
        {
            assert(!path_.empty());
            assert(norm_ > 0);

            save(path_, {norm_, norm_, norm_});
        }

        inline void Image::save(const std::string& path_, const vec3i& norm_) const noexcept
        {
            assert(!path_.empty());
            assert(norm_.r > 0);
            assert(norm_.g > 0);
            assert(norm_.b > 0);

            sys::file::Out file(path_);

            file << "P3\n"
                 << _width << " " << _height << "\n"
                 << "255\n";

            for (size_t i = 0; i < _height; ++i)
            {
                for (size_t j = 0; j < _width; ++j)
                {
                    for (size_t k = 0; k < 3; ++k)
                    {
                        file << std::min(255, (255 * _pixels[j][_height - i - 1][k]) / norm_[k]) << "\t";
                    }
                    file << "\t";
                }
                file << "\n";
            }
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_IMAGE_HPP
