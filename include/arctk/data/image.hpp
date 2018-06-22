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
            virtual inline void save(const std::string& path_) const noexcept = 0;
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



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_IMAGE_HPP
