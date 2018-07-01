/**
 *  @file   arctk/data/histogram/dynamic1.hpp
 *  @date   01/07/2018
 *  @author Freddy Wordingham
 *
 *  One-dimensional, dynamic-range, data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_HISTOGRAM_DYNAMIC1_HPP
#define ARCTK_DATA_HISTOGRAM_DYNAMIC1_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Arctk --
#include <arctk/data/histogram/dynamic.hpp>



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
             *  One-dimensional, dynamic-range, data binning class.
             *
             *  @tparam T   Type binned.
             */
            template <typename T>
            class Dynamic<T, 1> : public Histogram<T, 1>
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Dynamic(double min_, double max_, double size_) noexcept;


                //  == METHODS ==
              public:
                //  -- Collection --
                inline void collect(double pos_, const T& val_) noexcept override;

              private:
                //  -- Growth --
                inline void ascend() noexcept;
                inline void descend() noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a dynamic one-dimensional histogram object with given initial bounds and size.
             *
             *  @tparam T   Type binned.
             *
             *  @param  min_    Initial minimum bound of the histogram range.
             *  @param  max_    Initial maximum bound of the histogram range.
             *  @param  size_   Number of bins.
             *
             *  @pre    min_ must be less than max_.
             *  @pre    Size_ must be positive.
             */
            template <typename T>
            inline Dynamic<T, 1>::Dynamic(const double min_, const double max_, const double size_) noexcept
              : Histogram<T, 1>(min_, max_, size_)
            {
                assert(min_ < max_);
                assert(size_ > 0);
            }



            //  == METHODS ==
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
            inline void Dynamic<T, 1>::collect(const double pos_, const T& val_) noexcept
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



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM_DYNAMIC1_HPP
