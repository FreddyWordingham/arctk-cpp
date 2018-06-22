/**
 *  @file   arctk/data/image/greyscale.hpp
 *  @date   22/06/2018
 *  @author Freddy Wordingham
 *
 *  Scalar image forming class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_IMAGE_GREYSCALE_HPP
#define ARCTK_DATA_IMAGE_GREYSCALE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Arctk --
#include <arctk/data/image.hpp>



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace image //! image namespace
        {



            //  == CLASS ==
            /**
             *  Greyscale data writer.
             */
            class Greyscale : public Image
            {
                //  == FIELDS ==
              private:
                //  -- Data --
                utl::MultiVec<double, 2> _pixels; //!< Pixel data of the image.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Greyscale(size_t width_, size_t height_) noexcept;


                //  == METHODS ==
              public:
                //  -- Collection --
                inline void collect(size_t col_, size_t row_, double val_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a greyscale image with given dimensions in pixels.
             *
             *  @param  width_  Width of the image in pixels.
             *  @param  height_ Height of the image in pixels.
             *
             *  @pre    width_ must be positive.
             *  @pre    height_ must be positive.
             */
            inline Greyscale::Greyscale(const size_t width_, const size_t height_) noexcept
              : Image(width_, height_)
              , _pixels(utl::make_MultiVec<double, 2>({{width_, height_}}))
            {
                assert(width_ > 0);
                assert(height_ > 0);
            }


            //  == METHODS ==
            //  -- Collection --
            inline void Greyscale::collect(const size_t col_, const size_t row_, const double val_) noexcept
            {
                assert(col_ < _width);
                assert(row_ < _height);
                assert(val_ >= 0.0);

                _pixels[col_][row_] += val_;
            }



        } // namespace image
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_IMAGE_GREYSCALE_HPP
