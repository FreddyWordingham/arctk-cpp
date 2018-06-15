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
            const size_t _width;
            const size_t _height;

            //  -- Data --
            utl::MultiVec<vec3i, 2> _pixels;


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
            inline void collect(size_t row_, size_t col_, int val_) noexcept;
            inline void collect(size_t row_, size_t col_, const vec3i& val_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
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
        inline void Image::collect(const size_t row_, const size_t col_, const int val_) noexcept
        {
            assert(row_ < _width);
            assert(col_ < _height);
            assert(val_ >= 0);

            _pixels[row_][col_] += val_;
        }

        inline void Image::collect(const size_t row_, const size_t col_, const int vec3i& val_) noexcept
        {
            assert(row_ < _width);
            assert(col_ < _height);
            assert(val_.r >= 0);
            assert(val_.g >= 0);
            assert(val_.b >= 0);
            a _pixels[row_][col_] += val_;
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_IMAGE_HPP
