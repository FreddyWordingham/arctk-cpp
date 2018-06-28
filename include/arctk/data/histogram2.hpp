/**
 *  @file   arctk/data/histogram2.hpp
 *  @date   28/06/2018
 *  @author Freddy Wordingham
 *
 *  Two-dimensional data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_HISTOGRAM2_HPP
#define ARCTK_DATA_HISTOGRAM2_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Arctk --
#include <arctk/data/histogram.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/math.hpp>
#include <arctk/settings.hpp>
#include <arctk/sys.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Two-dimensional data binning class.
         *
         *  @tparam T   Type binned.
         */
        template <typename T>
        class Histogram<T, 2>
        {
            //  == FIELDS ==
          protected:
            //  -- Bounds --
            vec2 _min; //!< Minimum bound of the histogram range.
            vec2 _max; //!< Maximum bound of the histogram range.

          private:
            //  -- Bin --
            vec2 _bin_width; //!< Width of the bins.

          protected:
            //  -- Data --
            std::vector<std::vector<T>> _bins; //!< Bin data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Histogram(const vec2& min_, const vec2& max_, const vec2s& size_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const vec2&                        min() const noexcept;
            inline const vec2&                        max() const noexcept;
            inline const vec2&                        bin_width() const noexcept;
            inline const std::vector<std::vector<T>>& bins() const noexcept;
            inline const vec2s&                       size() const noexcept;
            inline vec2                               centre(const vec2s& index_) const noexcept;
            inline std::vector<std::vector<double>>   centres() const noexcept;

            //  -- Searching --
            inline size_t find_index(double pos_) noexcept;

            //  -- Collection --
            virtual inline void collect(double   pos_,
                                        const T& val_) noexcept = 0; //!<  Collect a value into the histogram at a given position.  @tparam T   Type binned. @param  pos_    Position of the value to place.  @param  val_    Value to place within the bins.

            //  -- Printing --
            inline std::string str(char delim_ = settings::DEFAULT_DELIM, size_t width_ = settings::DEFAULT_PRINT_WIDTH) const noexcept;

            //  -- Saving --
            inline void save(const std::string& path_, char delim_ = settings::DEFAULT_DELIM, size_t width_ = settings::DEFAULT_PRINT_WIDTH) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a two-dimensional histogram object with given bounds and size.
         *
         *  @tparam T   Type binned.
         *
         *  @param  min_    Minimum bound of the histogram range.
         *  @param  max_    Maximum bound of the histogram range.
         *  @param  size_   Number of bins.
         *
         *  @pre    min_ must be less than max_.
         *  @pre    size_ must be positive.
         */
        template <typename T>
        inline Histogram<T, 2>::Histogram(const vec2& min_, const vec2& max_, const vec2s& size_) noexcept
          : _min(min_)
          , _max(max_)
          , _bin_width((max_.x - min_.x) / size_.x, (max_.y - min_.y) / size_.y)
          , _bins(std::vector<double>(size_.y), size_.x)
        {
            assert(min_.x < max_.x);
            assert(min_.y < max_.y);
            assert(size_.x > 0);
            assert(size_.y > 0);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum bound of the histogram.
         *
         *  @tparam T   Type binned.
         *
         *  @return Minimum bound of the histogram.
         */
        template <typename T>
        inline const vec2& Histogram<T, 2>::min() const noexcept
        {
            return (_min);
        }

        /**
         *  Get the maximum bound of the histogram.
         *
         *  @tparam T   Type binned.
         *
         *  @return Maximum bound of the histogram.
         */
        template <typename T>
        inline const vec2& Histogram<T, 2>::max() const noexcept
        {
            return (_max);
        }

        /**
         *  Get the width of the histogram's bins.
         *
         *  @tparam T   Type binned.
         *
         *  @return Width of the histogram's bins.
         */
        template <typename T>
        inline const vec2& Histogram<T, 2>::bin_width() const noexcept
        {
            return (_bin_width);
        }

        /**
         *  Get the bin data of the histogram.
         *
         *  @tparam T   Type binned.
         *
         *  @return Bin data of the histogram.
         */
        template <typename T>
        inline const std::vector<std::vector<T>>& Histogram<T, 2>::bins() const noexcept
        {
            return (_bins);
        }

        /**
         *  Get the size of the bin data bins vector.
         *
         *  @tparam T   Type binned.
         *
         *  @return Size of the bin data bins vector.
         */
        template <typename T>
        inline const vec2s& Histogram<T, 2>::size() const noexcept
        {
            return (_bins.size());
        }

        template <typename T>
        inline vec2 Histogram<T, 2>::centre(const vec2s& index_) const noexcept
        {
            assert(index_.x < _bins.size());
            assert(index_.y < _bins.front().size());

            return (vec2(_min.x + ((static_cast<double>(index_.x) + 0.5) * (_max.x - _min.x)), _min.y + ((static_cast<double>(index_.y) + 0.5) * (_max.y - _min.y))));
        }

        template <typename T>
        inline std::vector<std::vector<double>> Histogram<T, 2>::centres() const noexcept
        {
            std::vector<double> centres(std::vector<double>(_bins.front().size()), _bins.size());

            for (size_t i = 0; i < centres.size(); ++i)
            {
                for (size_t j = 0; j < centres.size(); ++j)
                {
                    centres[i][j] = centre(vec2s(i, j));
                }
            }

            return (centres);
        }


        //  -- Searching --
        /**
         *  Determine the index of the bin a position belongs in.
         *
         *  @tparam T   Type binned.
         *
         *  @param  pos_    Position to place within the bin.
         *
         *  @pre    pos_ must be greater than, or equal to, the minimum bound of the histogram.
         *  @pre    pos_ must be less than, or equal to, the maximum bound of the histogram.
         *
         *  @return Index of the bin to corresponding to the given position.
         */
        template <typename T>
        inline size_t Histogram<T, 2>::find_index(const double pos_) noexcept
        {
            assert(pos_ >= _min);
            assert(pos_ <= _max);

            const auto index = static_cast<size_t>((pos_ - _min) / _bin_width);

            return ((index == _bins.size()) ? (index - 1) : index);
        }


        //  -- Printing --
        /**
         *  Form the histogram data into a human readable string.
         *
         *  @tparam T   Type binned.
         *
         *  @param  delim_  Delimiter character used to seperate consecutive values.
         *  @param  width_  Print width allocated to each value.
         *
         *  @return Human readable string of the histogram data.
         */
        template <typename T>
        inline std::string Histogram<T, 2>::str(const char delim_, const size_t width_) const noexcept
        {
            const std::vector<double> centres = Histogram<T, 2>::centres();

            std::stringstream stream;

            for (size_t i = 0; i < centres.size(); ++i)
            {
                if (i != 0)
                {
                    stream << "\n";
                }

                stream << std::setw(width_) << centres[i] << delim_ << std::setw(width_) << _bins[i];
            }

            return (stream.str());
        }


        //  -- Saving --
        /**
         *  Save data table as a csv file.
         *
         *  @tparam T   Type binned.
         *
         *  @param  path_   Path to the output file.
         *  @param  delim_  Delimiter character used to seperate consecutive values.
         *  @param  width_  Print width allocated to each value.
         *
         *  @pre    path_ may not be empty.
         */
        template <typename T>
        inline void Histogram<T, 2>::save(const std::string& path_, const char delim_, const size_t width_) const noexcept
        {
            assert(!path_.empty());

            sys::file::Out file(path_);

            file << str(delim_, width_);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM2_HPP
