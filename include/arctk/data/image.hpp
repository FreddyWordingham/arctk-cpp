/**
 *  @file   arctk/data/image.hpp
 *  @date   12/07/2018
 *  @author Freddy Wordingham
 *
 *  Image forming base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_IMAGE_HPP
#define ARCTK_DATA_IMAGE_HPP



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



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
          protected:
            //  -- Information --
            const size_t _width;  //!< Width of the image in pixels.
            const size_t _height; //!< Height of the image in pixels.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Image(size_t width_, size_t height_) noexcept;
            inline Image(const Image&) noexcept = default; //!< Defaulted copy constructor.
            inline Image(Image&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Image() noexcept = default;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Image& operator=(const Image&) noexcept = delete; //!< Defaulted copy operator. @return Reference to copied object.
            inline Image& operator=(Image&&) noexcept = delete;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline size_t width() const noexcept;
            inline size_t height() const noexcept;

            //  -- Collection --
            virtual inline void collect(size_t col_, size_t row_,
                                        double val_) noexcept = 0; //!< Collect a value into the pixel data array. @param  col_    Column of the pixel to add to. @param  row_    Row of the pixel to add to. @param  val_    Value to add the pixel.

            //  -- Saving --
            virtual inline void save(const std::string& path_) const noexcept = 0; //!< Save the image data. Pixel values are normalised but not scaled. Pixel values are converted to a greyscale colour. @param  path_   Path to the output file.
            virtual inline void save(const std::string& path_, double (*scale_)(double)) const noexcept = 0; //!< Save the image data using a value scaling function. Pixel values are normalised then scaled using the given scaling function. Pixel values are
                                                                                                             //!< converted to a greyscale colour. @param  path_   Path to the output file. @param scale_  Function used to scale the normalised values.

          protected:
            //  -- Saving --
            inline void write_ppm(const std::string& path_, const std::vector<std::vector<vec3>>& pixels_) const noexcept;
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
        inline Image::Image(const size_t width_, const size_t height_) noexcept
          : _width(width_)
          , _height(height_)
        {
            PRE(width_ > 0);
            PRE(height_ > 0);
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
            PRE(!path_.empty());
            PRE(pixels_.size() == _width);
            PRE(pixels_.front().size() == _height);

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
#endif // ARCTK_DATA_IMAGE_HPP
