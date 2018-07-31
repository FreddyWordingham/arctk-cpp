/**
 *  @file   arctk/data/histogram/fixed1.hpp
 *  @date   12/07/2018
 *  @author Freddy Wordingham
 *
 *  One-dimensional, fixed-range, data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_HISTOGRAM_FIXED1_HPP
#define ARCTK_DATA_HISTOGRAM_FIXED1_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/data/histogram/fixed.hpp>
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
             *  One-dimensional, fixed-range, data binning class.
             *
             *  @tparam T   Type binned.
             */
            template <typename T>
            class Fixed<T, 1> : public Histogram<T, 1>
            {
                //  == FIELDS ==
              private:
                //  -- Counts --
                T _misses{}; //!< Number of range misses.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Fixed(double min_, double max_, size_t size_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const T& misses() const noexcept;

                //  -- Collection --
                inline void collect(double pos_, const T& val_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a fixed one-dimensional histogram object with given bounds and size.
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
            inline Fixed<T, 1>::Fixed(const double min_, const double max_, const size_t size_) noexcept
              : Histogram<T, 1>(min_, max_, size_)
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
            inline const T& Fixed<T, 1>::misses() const noexcept
            {
                return (_misses);
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
            inline void Fixed<T, 1>::collect(const double pos_, const T& val_) noexcept
            {
                if ((pos_ < Histogram<T, 1>::_min) || (pos_ > Histogram<T, 1>::_max))
                {
                    _misses += val_;

                    return;
                }

                Histogram<T, 1>::_bins[Histogram<T, 1>::find_index(pos_)] += val_;
            }



        } // namespace histogram
    }     // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM_FIXED1_HPP
