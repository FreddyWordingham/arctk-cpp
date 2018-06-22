/**
 *  @file   arctk/data/image.hpp
 *  @date   22/06/2018
 *  @author Freddy Wordingham
 *
 *  Image forming base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_IMAGE_HPP
#define ARCTK_DATA_IMAGE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <algorithm>

//  -- Arctk --
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
          protected:
            //  -- Information --
            const size_t _width;  //!< Width of the image in pixels.
            const size_t _height; //!< Height of the image in pixels.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Image(size_t width_, size_t height_) noexcept;

            //  -- Destructors --
            virtual inline ~Image() noexcept = default;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline size_t width() const noexcept;
            inline size_t height() const noexcept;

            //  -- Collection --
            virtual inline void collect(size_t col_, size_t row_, double val_) noexcept = 0;

            //  -- Saving --
            virtual inline void save(const std::string& path_) const noexcept                                                                         = 0;
            virtual inline void save(const std::string& path_, double (*const scale_)(const double)) const noexcept                                   = 0;
            virtual inline void save(const std::string& path_, vec3 (*const map_)(const double)) const noexcept                                       = 0;
            virtual inline void save(const std::string& path_, double (*const scale_)(const double), vec3 (*const map_)(const double)) const noexcept = 0;

          protected:
            //  -- Saving --
            inline void write_ppm(const std::string& path_, const utl::MultiVec<vec3, 2>& pixels) const noexcept;
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
        inline void Image::write_ppm(const std::string& path_, const utl::MultiVec<vec3, 2>& pixels) const noexcept
        {
            assert(!path_.empty());
            assert(pixels.size() == _width);
            assert(pixels.front().size() == _height);

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
                        file << std::clamp(static_cast<int>(255 * pixels[j][_height - i - 1][k]), 0, 255) << "\t";
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
