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



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_IMAGE_HPP
