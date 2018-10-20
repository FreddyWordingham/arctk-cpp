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
#include <cstddef>
#include <string>
#include <vector>



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



    } // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/image.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_IMAGE_HPP
