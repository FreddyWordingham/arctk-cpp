/**
 *  @file   arctk/img/bitmap/greyscale.hpp
 *  @date   12/11/2018
 *  @author Freddy Wordingham
 *
 *  Greyscale bitmap image class.
 */



//  == GUARD ==
#ifndef ARCTK_IMG_BITMAP_GREYSCALE_HPP
#define ARCTK_IMG_BITMAP_GREYSCALE_HPP



//  == BASE ==
#include <arctk/img/bitmap.hpp>



//  == IMPORTS ==
//  -- Std --
#include <functional>
#include <vector>

//  -- Arctk --
#include <arctk/math/vec.hpp>
#include <arctk/multi/vector.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace img //! image namespace
    {
        namespace bitmap //! bitmap namespace
        {



            //  == CLASS ==
            /**
             *  Greyscale bitmap image class.
             */
            class Greyscale : public Bitmap
            {
                //  == FIELDS ==
              private:
                //  -- Data --
                multi::vector<double, 2> _pixels; //!< Pixel data.
                double                   _min;    //!< Minimum scaling value.
                double                   _max;    //!< Maximum scaling value.

                //  -- Mapping --
                std::function<double(double)> _scale_map;  //!< Function pointer to scaling mapper.
                std::function<vec3(double)>   _colour_map; //!< Function pointer to colouring mapper.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Greyscale(const multi::vector<double, 2>& pixels_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Access --
                inline std::vector<double>&       operator[](size_t index_) noexcept;
                inline const std::vector<double>& operator[](size_t index_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline size_t width() const noexcept override;
                inline size_t height() const noexcept override;

                //  -- Setters --
                inline void set_min(double min_) noexcept;
                inline void set_max(double max_) noexcept;
                inline void set_scale_map(std::function<double(double)> scale_map_) noexcept;
                inline void set_colour_map(std::function<vec3(double)> colour_map_) noexcept;

                //  -- Saving --
                inline void save(const std::string& path_) const noexcept override; // NOLINT
            };



        } // namespace bitmap
    }     // namespace img
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/img/bitmap/greyscale.inl>



//  == GUARD END ==
#endif // ARCTK_IMG_BITMAP_GREYSCALE_HPP
