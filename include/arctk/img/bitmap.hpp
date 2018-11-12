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
            //  == FIELDS ==
          private:
            //  -- Data --
            multi::vector<double, 2> _pixels;
            double                   _min;
            double                   _max;

            //  -- Mapping --
            std::function<double(double)> _scale_map;
            std::function<vec3(double)>   _colour_map;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Bitmap(const multi::vector<double, 2>& pixels_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            inline std::vector<double>&       operator[](const size_t index_) noexcept;
            inline const std::vector<double>& operator[](const size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Setters --
            inline void set_min(const double min_) noexcept;
            inline void set_max(const double max_) noexcept;
            inline void set_scale_map(std::function<double(double)> scale_map_) noexcept;
            inline void set_colour_map(std::function<vec3(double)> colour_map_) noexcept;

            //  -- Saving --
            inline void save(const std::string& path_) const noexcept;
        };



    } // namespace img
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/img/bitmap.inl>



//  == GUARD END ==
#endif // ARCTK_IMG_BITMAP_HPP
