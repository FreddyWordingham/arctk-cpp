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
            //  == METHODS ==
          public:
            //  -- Saving --
            virtual inline void save(const std::string& path_) const noexcept = 0;
        };



    } // namespace img
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/img/bitmap.inl>



//  == GUARD END ==
#endif // ARCTK_IMG_BITMAP_HPP
