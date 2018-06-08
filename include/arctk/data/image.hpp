/**
 *  @file   arctk/data/image.hpp
 *  @date   08/06/2018
 *  @author Freddy Wordingham
 *
 *  Image construction class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_IMAGE_HPP
#define ARCTK_DATA_IMAGE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/math.hpp>
#include <arctk/sys.hpp>



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
            std::vector<std::vector<math::Vec3<double>>> _pixels; //!< Pixel image data.


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
            inline void collect(size_t row_, size_t col_, double val_) noexcept;
            inline void collect(size_t row_, size_t col_, const math::Vec3<double>& val_) noexcept;

            //  -- Saving --
            inline void save(const std::string& path_, const math::Vec3<double>& norm_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Image::Image(const size_t width_, const size_t height_) noexcept
          : _width(width_)
          , _height(height_)
          , _pixels(std::vector<std::vector<math::math::Vec3<double>>>(width_, std::vector<math::Vec3<double>>(height_)))
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
         *  Collect a uniform value into the image.
         *
         *  @param  row_    Row of the pixel to add to.
         *  @param  col_    Column of the pixel to add to,
         *  @param  val_    Value to add uniformly to the pixel.
         *
         *  @pre    row_ must be less than _width.
         *  @pre    col_ must be less than _height.
         *  @pre    val_ must be non-negative.
         */
        inline void Image::collect(const size_t row_, const size_t col_, const double val_) noexcept
        {
            assert(row_ < _width);
            assert(col_ < _height);
            assert(val_ >= 0.0);

            _pixels[row_][col_] += val_;
        }

        /**
         *  Collect a pixel value into the image.
         *
         *  @param  row_    Row of the pixel to add to.
         *  @param  col_    Column of the pixel to add to,
         *  @param  val_    RGB value to add to the pixel.
         *
         *  @pre    row_ must be less than _width.
         *  @pre    col_ must be less than _height.
         *  @pre    val_.r must be non-negative.
         *  @pre    val_.g must be non-negative.
         *  @pre    val_.b must be non-negative.
         */
        inline void Image::collect(const size_t row_, const size_t col_, const math::Vec3<double>& val_) noexcept
        {
            assert(row_ < _width);
            assert(col_ < _height);
            assert(val_.r >= 0.0);
            assert(val_.g >= 0.0);
            assert(val_.b >= 0.0);

            _pixels[row_][col_] += val_;
        }


        //  -- Saving --
        /**
         *  Save the image to a file.
         *  Normalise the values of the image using the normalisation vector given.
         *
         *  @param  path_   Path to the save file.
         *  @param  norm_   Normalisation values to be applied.
         *
         *  @pre    norm.r must be non-negative.
         *  @pre    norm.g must be non-negative.
         *  @pre    norm.b must be non-negative.
         */
        inline void Image::save(const std::string& path_, const math::Vec3<double>& norm_) const noexcept
        {
            assert(norm_.r > 0.0);
            assert(norm_.g > 0.0);
            assert(norm_.b > 0.0);

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
                        file << std::min(255, static_cast<int>(255 * (_pixels[i][j][k] / norm_[k]))) << "\t";
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
