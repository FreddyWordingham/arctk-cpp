/**
 *  @file   arctk/data/histogram/fixed2.hpp
 *  @date   13/07/2018
 *  @author Freddy Wordingham
 *
 *  Two-dimensional, fixed-range, data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_HISTOGRAM_FIXED2_HPP
#define ARCTK_DATA_HISTOGRAM_FIXED2_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/data/histogram/fixed.hpp>
#include <arctk/data/histogram2.hpp>
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



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
                inline Fixed(const vec2& min_, const vec2& max_, const vec2s& size_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const T& misses() const noexcept;

                //  -- Collection --
                inline void collect(const vec2& pos_, const T& val_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a fixed two-dimensional histogram object with given bounds and size.
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
            inline Fixed<T, 2>::Fixed(const vec2& min_, const vec2& max_, const vec2s& size_) noexcept
              : Histogram<T, 2>(min_, max_, size_)
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(size_.x > 0);
                PRE(size_.y > 0);
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
            inline void Fixed<T, 2>::collect(const vec2& pos_, const T& val_) noexcept
            {
                if ((pos_.x < Histogram<T, 2>::_min.x) || (pos_.x > Histogram<T, 2>::_max.x) || (pos_.y < Histogram<T, 2>::_min.y) || (pos_.y > Histogram<T, 2>::_max.y))
                {
                    _misses += val_;

                    return;
                }

                const vec2s index = Histogram<T, 2>::find_index(pos_);
                Histogram<T, 2>::_bins[index.x][index.y] += val_;
            }



        } // namespace histogram
    }     // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM_FIXED2_HPP
