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



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_IMAGE_HPP
