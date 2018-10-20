/**
 *  @file   arctk/data/histogram/average1.hpp
 *  @date   12/07/2018
 *  @author Freddy Wordingham
 *
 *  One-dimensional, averaging, data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_HISTOGRAM_AVERAGE1_HPP
#define ARCTK_DATA_HISTOGRAM_AVERAGE1_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/data/histogram/average.hpp>
#include <arctk/data/histogram1.hpp>
#include <arctk/debug.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace histogram //! histogram namespace
        {



            //  == CLASS ==
            /**
             *  One-dimensional, averaging, data binning class.
             *
             *  @tparam T   Type binned.
             */
            template <typename T>
            class Average<T, 1> : public Histogram<T, 1>
            {
                //  == FIELDS ==
              private:
                //  -- Counts --
                T                   _misses{}; //!< Number of range misses.
                std::vector<size_t> _counts{}; //!< Bin counts.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Average(double min_, double max_, size_t size_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const T&                   misses() const noexcept;
                inline const std::vector<size_t>& counts() const noexcept;

                //  -- Collection --
                inline void collect(double pos_, const T& val_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct an averaging one-dimensional histogram object with given bounds and size.
             *
             *  @tparam T   Type binned.
             *
             *  @param  min_    Minimum bound of the histogram range.
             *  @param  max_    Maximum bound of the histogram range.
             *  @param  size_   Number of bins.
             *
             *  @pre    min_ must be less than max_.
             *  @pre    Size_ must be positive.
             */
            template <typename T>
            inline Average<T, 1>::Average(const double min_, const double max_, const size_t size_) noexcept
              : Histogram<T, 1>(min_, max_, size_)
              , _counts(size_)
            {
                PRE(min_ < max_);
                PRE(size_ > 0);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the total number of misses.
             *
             *  @tparam T   Type binned.
             *
             *  @return Total number of misses.
             */
            template <typename T>
            inline const T& Average<T, 1>::misses() const noexcept
            {
                return (_misses);
            }

            /**
             *  Get the total number of counts collected into each bin.
             *
             *  @tparam T   Type binned.
             *
             *  @return Total number of counts collected into each bin.
             */
            template <typename T>
            inline const std::vector<size_t>& Average<T, 1>::counts() const noexcept
            {
                return (_counts);
            }


            //  -- Collection --
            /**
             *  Collect a value into the histogram at a given position.
             *  If the position is outside the bounds of the histogram then it is counted as a miss.
             *
             *  @tparam T   Type binned.
             *
             *  @param  pos_    Position of the value to place.
             *  @param  val_    Value to place within the bins.
             */
            template <typename T>
            inline void Average<T, 1>::collect(const double pos_, const T& val_) noexcept
            {
                if ((pos_ < Histogram<T, 1>::_min) || (pos_ > Histogram<T, 1>::_max))
                {
                    _misses += val_;

                    return;
                }

                const size_t index = Histogram<T, 1>::find_index(pos_);

                Histogram<T, 1>::_bins[index] = ((Histogram<T, 1>::_bins[index] * _counts[index]) + val_) / (_counts[index] + 1);
                ++_counts[index];
            }



        } // namespace histogram
    }     // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM_AVERAGE1_HPP
