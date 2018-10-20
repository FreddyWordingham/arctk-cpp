/**
 *  @file   arctk/data/image/greyscale.hpp
 *  @date   12/07/2018
 *  @author Freddy Wordingham
 *
 *  Scalar image forming class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_IMAGE_GREYSCALE_HPP
#define ARCTK_DATA_IMAGE_GREYSCALE_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/data/image.hpp>
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace image //! image namespace
        {



            //  == CLASS ==
            /**
             *  Greyscale image.
             */
            class Greyscale : public Image
            {
                //  == FIELDS ==
              private:
                //  -- Data --
                std::vector<std::vector<double>> _pixels; //!< Pixel data of the image.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Greyscale(size_t width_, size_t height_) noexcept;
                inline explicit Greyscale(const std::vector<std::vector<double>>& pixels_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const std::vector<std::vector<double>>& pixels() const noexcept;

                //  -- Collection --
                inline void collect(size_t col_, size_t row_, double val_) noexcept override;

                //  -- Saving --
                inline void save(const std::string& path_) const noexcept override;
                inline void save(const std::string& path_, double (*scale_)(double)) const noexcept override;
                inline void save(const std::string& path_, vec3 (*map_)(double)) const noexcept;
                inline void save(const std::string& path_, double (*scale_)(double), vec3 (*map_)(double)) const noexcept;
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
              , _pixels(std::vector<std::vector<double>>(width_, std::vector<double>(height_)))
            {
                PRE(width_ > 0);
                PRE(height_ > 0);
            }

            /**
             *  Construct a greyscale image from pixel of values.
             *
             *  @param  pixels_ Two-dimensional vector of pixel values.
             *
             *  @pre    pixels_ may not be empty.
             *  @pre    pixels_ front element may not be empty.
             */
            inline Greyscale::Greyscale(const std::vector<std::vector<double>>& pixels_) noexcept
              : Image(pixels_.size(), pixels_.empty() ? 0 : pixels_.front().size())
              , _pixels(pixels_)
            {
                PRE(!pixels_.empty());
                PRE(!pixels_.front().empty());
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the array of pixel data.
             *
             *  @return Array of pixel data.
             */
            inline const std::vector<std::vector<double>>& Greyscale::pixels() const noexcept
            {
                return (_pixels);
            }


            //  -- Collection --
            /**
             *  Collect a value into the pixel data array.
             *
             *  @param  col_    Column of the pixel to add to.
             *  @param  row_    Row of the pixel to add to.
             *  @param  val_    Value to add the pixel.
             *
             *  @pre    col_ must be less than _width.
             *  @pre    row_ must be less than _height.
             *  @pre    val_ must be non-negative.
             */
            inline void Greyscale::collect(const size_t col_, const size_t row_, const double val_) noexcept
            {
                PRE(col_ < _width);
                PRE(row_ < _height);
                PRE(val_ >= 0.0);

                _pixels[col_][row_] += val_;
            }


            //  -- Saving --
            /**
             *  Save the image data.
             *  Pixel values are normalised but not scaled.
             *  Pixel values are converted to a greyscale colour.
             *
             *  @param  path_   Path to the output file.
             */
            inline void Greyscale::save(const std::string& path_) const noexcept
            {
                save(path_, [](const double x_) { return (x_); }, [](const double x_) { return (vec3(x_, x_, x_)); });
            }

            /**
             *  Save the image data using a value scaling function.
             *  Pixel values are normalised then scaled using the given scaling function.
             *  Pixel values are converted to a greyscale colour.
             *
             *  @param  path_   Path to the output file.
             *  @param  scale_  Function used to scale the normalised values.
             */
            inline void Greyscale::save(const std::string& path_, double (*const scale_)(const double)) const noexcept
            {
                save(path_, scale_, [](const double x_) { return (vec3(x_, x_, x_)); });
            }

            /**
             *  Save the image data using a colour mapping function.
             *  Pixel values are normalised but not scaled.
             *  Pixel values are converted to a colour using the given mapping function.
             *
             *  @param  path_   Path to the output file.
             *  @param  map_    Function used to map scaled values to a colour.
             */
            inline void Greyscale::save(const std::string& path_, vec3 (*const map_)(const double)) const noexcept
            {
                save(path_, [](const double x_) { return (x_); }, map_);
            }

            /**
             *  Save the image data using value scaling and colour mapping functions.
             *  Pixel values are normalised then scaled using the given scaling function.
             *  Pixel values are converted to a colour using the given mapping function.
             *
             *  @param  path_   Path to the output file.
             *  @param  scale_  Function used to scale the normalised values.
             *  @param  map_    Function used to map scaled values to a colour.
             */
            inline void Greyscale::save(const std::string& path_, double (*const scale_)(const double), vec3 (*const map_)(const double)) const noexcept
            {
                PRE(!path_.empty());

                double max = 0.0;
                for (size_t i = 0; i < _height; ++i)
                {
                    for (size_t j = 0; j < _width; ++j)
                    {
                        if (_pixels[j][i] > max)
                        {
                            max = _pixels[j][i];
                        }
                    }
                }

                if (math::compare::zero(max))
                {
                    max = 1.0;
                }

                std::vector<std::vector<vec3>> pixels(_width, std::vector<vec3>(_height));
                for (size_t i = 0; i < _width; ++i)
                {
                    for (size_t j = 0; j < _height; ++j)
                    {
                        const vec3 col = map_(scale_(_pixels[i][j] / max));

                        for (size_t k = 0; k < 3; ++k)
                        {
                            pixels[i][j][k] = col[k];
                        }
                    }
                }

                write_ppm(path_, pixels);
            }



        } // namespace image
    }     // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_IMAGE_GREYSCALE_HPP
