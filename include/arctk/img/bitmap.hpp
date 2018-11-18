/**
 *  @file   arctk/img/bitmap.hpp
 *  @date   12/11/2018
 *  @author Freddy Wordingham
 *
 *  Bitmap image class.
 */



//  == GUARD ==
#ifndef ARCTK_IMG_BITMAP_HPP
#define ARCTK_IMG_BITMAP_HPP



//  == IMPORTS ==
//  -- Std --
#include <functional>
#include <vector>

//  -- Arctk --
#include <arctk/math/vec3.hpp>
#include <arctk/multi/vector.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace img //! image namespace
    {



        //  == CLASS ==
        /**
         *  Bitmap image class.
         */
        class Bitmap
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bitmap()                       = default; //!< Defaulted constructor.
            inline Bitmap(const Bitmap&) noexcept = default; //!< Defaulted copy constructor.
            inline Bitmap(Bitmap&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Bitmap() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Bitmap& operator=(const Bitmap&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Bitmap& operator=(Bitmap&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual inline size_t width() const noexcept  = 0; //!< Get the width of the bitmap in pixels.  @return Width of the bitmap in pixels.
            virtual inline size_t height() const noexcept = 0; //!< Get the height of the bitmap in pixels.  @return Height of the bitmap in pixels.

            //  -- Saving --
            virtual inline void save(const std::string& path_) const noexcept = 0; //!< Save the state of the bitmap as an ppm image.   @param  path_   Path to the images save location.
        };



    } // namespace img
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/img/bitmap.inl>



//  == GUARD END ==
#endif // ARCTK_IMG_BITMAP_HPP
