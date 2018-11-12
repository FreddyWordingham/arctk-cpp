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

//  -- Arctk --
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
            //  == FIELDS ==
          private:
            //  -- Data --
            multi::vector<double, 2> _pixels;
            double                   _min;
            double                   _max;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Bitmap(const multi::vector<double, 2>& pixels_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --

            //  == METHODS ==
          public:
            //  -- Setters --
            inline void set_min(const double min_) noexcept;
            inline void set_max(const double max_) noexcept;
        };



    } // namespace img
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/img/bitmap.inl>



//  == GUARD END ==
#endif // ARCTK_IMG_BITMAP_HPP
