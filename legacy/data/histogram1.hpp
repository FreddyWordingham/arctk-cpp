/**
 *  @file   arctk/data/histogram1.hpp
 *  @date   12/07/2018
 *  @author Freddy Wordingham
 *
 *  One-dimensional data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_HISTOGRAM1_HPP
#define ARCTK_DATA_HISTOGRAM1_HPP



//  == IMPORTS ==
//  -- Std --
#include <fstream>
#include <iomanip>
#include <ostream>
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/data/histogram.hpp>
#include <arctk/debug.hpp>
#include <arctk/io.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  One-dimensional data binning class.
         *
         *  @tparam T   Type binned.
         */
        template <typename T>
        class Histogram<T, 1>
        {
            //  == FIELDS ==
          protected:
            //  -- Bounds --
            double _min; //!< Minimum bound of the histogram range.
            double _max; //!< Maximum bound of the histogram range.

          private:
            //  -- Bin --
            double _bin_width; //!< Width of the bins.

          protected:
            //  -- Data --
            std::vector<T> _bins; //!< Bin data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Histogram(double min_, double max_, size_t size_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Printing --
            template <typename S>
            friend inline std::ostream& operator<<(std::ostream& stream_, const Histogram<S, 1>& hist_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                min() const noexcept;
            inline double                max() const noexcept;
            inline double                bin_width() const noexcept;
            inline const std::vector<T>& bins() const noexcept;
            inline size_t                size() const noexcept;
            inline double                centre(size_t index_) const noexcept;
            inline std::vector<double>   centres() const noexcept;

            //  -- Searching --
            inline size_t find_index(double pos_) noexcept;

            //  -- Collection --
            virtual inline void collect(double   pos_,
                                        const T& val_) noexcept = 0; //!<  Collect a value into the histogram at a given position.  @tparam T   Type binned. @param  pos_    Position of the value to place.  @param  val_    Value to place within the bins.
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a one-dimensional histogram object with given bounds and size.
         *
         *  @param  min_    Minimum bound of the histogram range.
         *  @param  max_    Maximum bound of the histogram range.
         *  @param  size_   Number of bins.
         *
         *  @pre    min_ must be less than max_.
         *  @pre    size_ must be positive.
         */
        template <typename T>
        inline Histogram<T, 1>::Histogram(const double min_, const double max_, const size_t size_) noexcept
          : _min(min_)
          , _max(max_)
          , _bin_width((max_ - min_) / size_)
          , _bins(size_)
        {
            PRE(min_ < max_);
            PRE(size_ > 0);
        }



        //  == OPERATORS ==
        //  -- Printing --
        /**
         *  Print the histogram data to a given stream.
         *
         *  @tparam S   Type binned.
         *
         *  @param  stream_ Stream to print to.
         *  @param  hist_   Histogram to be printed.
         *
         *  @return Reference to the stream post-print.
         */
        template <typename S>
        inline std::ostream& operator<<(std::ostream& stream_, const Histogram<S, 1>& hist_) noexcept
        {
            stream_ << io::output::csv(hist_.centres(), hist_._bins);

            return (stream_);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum bound of the histogram.
         *
         *  @return Minimum bound of the histogram.
         */
        template <typename T>
        inline double Histogram<T, 1>::min() const noexcept
        {
            return (_min);
        }

        /**
         *  Get the maximum bound of the histogram.
         *
         *  @return Maximum bound of the histogram.
         */
        template <typename T>
        inline double Histogram<T, 1>::max() const noexcept
        {
            return (_max);
        }

        /**
         *  Get the width of the histogram's bins.
         *
         *  @return Width of the histogram's bins.
         */
        template <typename T>
        inline double Histogram<T, 1>::bin_width() const noexcept
        {
            return (_bin_width);
        }

        /**
         *  Get the bin data of the histogram.
         *
         *  @return Bin data of the histogram.
         */
        template <typename T>
        inline const std::vector<T>& Histogram<T, 1>::bins() const noexcept
        {
            return (_bins);
        }

        /**
         *  Get the size of the bin data bins vector.
         *
         *  @return Size of the bin data bins vector.
         */
        template <typename T>
        inline size_t Histogram<T, 1>::size() const noexcept
        {
            return (_bins.size());
        }

        /**
         *  Determine the centre position of a given bin index.
         *
         *  @param  index_  Index of the bin to find the centre of.
         *
         *  @pre    index_ must be less than _bins size.
         *
         *  @return Centre of the bin requested.
         */
        template <typename T>
        inline double Histogram<T, 1>::centre(const size_t index_) const noexcept
        {
            PRE(index_ < _bins.size());

            return (_min + ((static_cast<double>(index_) + 0.5) * _bin_width));
        }

        /**
         *  Construct a vector of all bin centres.
         *
         *  @return Vector of all bin centres.
         */
        template <typename T>
        inline std::vector<double> Histogram<T, 1>::centres() const noexcept
        {
            std::vector<double> centres(_bins.size());

            for (size_t i = 0; i < centres.size(); ++i)
            {
                centres[i] = centre(i);
            }

            return (centres);
        }


        //  -- Searching --
        /**
         *  Determine the index of the bin a position belongs in.
         *
         *  @param  pos_    Position to place within the bin.
         *
         *  @pre    pos_ must be greater than, or equal to, the minimum bound of the histogram.
         *  @pre    pos_ must be less than, or equal to, the maximum bound of the histogram.
         *
         *  @return Index of the bin to corresponding to the given position.
         */
        template <typename T>
        inline size_t Histogram<T, 1>::find_index(const double pos_) noexcept
        {
            PRE(pos_ >= _min);
            PRE(pos_ <= _max);

            const auto index = static_cast<size_t>((pos_ - _min) / _bin_width);

            return ((index == _bins.size()) ? (index - 1) : index);
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM1_HPP
