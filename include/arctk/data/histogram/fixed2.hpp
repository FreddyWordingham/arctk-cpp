/**
 *  @file   arctk/data/histogram/fixed2.hpp
 *  @date   28/06/2018
 *  @author Freddy Wordingham
 *
 *  Two-dimensional, fixed-range, data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_HISTOGRAM_FIXED2_HPP
#define ARCTK_DATA_HISTOGRAM_FIXED2_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Arctk --
#include <arctk/data/histogram/fixed.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace histogram //! histogram namespace
        {



            //  == CLASS ==
            /**
             *  Two-dimensional, fixed-range, data binning class.
             *
             *  @tparam T   Type binned.
             */
            template <typename T>
            class Fixed<T, 2> : public Histogram<T, 2>
            {
                //  == FIELDS ==
              private:
                //  -- Counts --
                T _misses{}; //!< Number of range misses.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Fixed(double min_, double max_, double size_) noexcept;


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
            inline Fixed<T, 2>::Fixed(const double min_, const double max_, const double size_) noexcept
              : Histogram<T, 2>(min_, max_, size_)
            {
                assert(min_ < max_);
                assert(size_ > 0);
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
            inline const T& Fixed<T, 2>::misses() const noexcept
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
            inline void Fixed<T, 2>::collect(const double pos_, const T& val_) noexcept
            {
                if ((pos_ < Histogram<T, 2>::_min) || (pos_ > Histogram<T, 2>::_max))
                {
                    _misses += val_;

                    return;
                }

                Histogram<T, 2>::_bins[Histogram<T, 2>::find_index(pos_)] += val_;
            }



        } // namespace histogram
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM_FIXED2_HPP
