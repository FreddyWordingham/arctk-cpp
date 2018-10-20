/**
 *  @file   arctk/data/histogram/dynamic1.hpp
 *  @date   12/07/2018
 *  @author Freddy Wordingham
 *
 *  One-dimensional, dynamic-range, data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_HISTOGRAM_DYNAMIC1_HPP
#define ARCTK_DATA_HISTOGRAM_DYNAMIC1_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/data/histogram/dynamic.hpp>
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
                inline Dynamic(double min_, double max_, size_t size_) noexcept;


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
             *  @pre    Size_ must be even.
             */
            template <typename T>
            inline Dynamic<T, 1>::Dynamic(const double min_, const double max_, const size_t size_) noexcept
              : Histogram<T, 1>(min_, max_, size_)
            {
                PRE(min_ < max_);
                PRE(size_ > 0);
                PRE((size_ % 2) == 0);
            }



            //  == METHODS ==
            //  -- Collection --
            /**
             *  Collect a value into the histogram at a given position.
             *  If the position is outside the bounds of the histogram then expand the histogram range to accommodate it.
             *
             *  @tparam T   Type binned.
             *
             *  @param  pos_    Position of the value to place.
             *  @param  val_    Value to place within the bins.
             */
            template <typename T>
            inline void Dynamic<T, 1>::collect(const double pos_, const T& val_) noexcept
            {
                while (pos_ < Histogram<T, 1>::_min)
                {
                    descend();
                }
                while (pos_ > Histogram<T, 1>::_max)
                {
                    ascend();
                }

                Histogram<T, 1>::_bins[Histogram<T, 1>::find_index(pos_)] += val_;
            }


            //  -- Growth --
            /**
             *  Increase the maximum bound of the histogram while maintaining the total number of bins.
             *  Values are re-binned in the process.
             *
             *  @tparam T   Type binned.
             */
            template <typename T>
            inline void Dynamic<T, 1>::ascend() noexcept
            {
                Histogram<T, 1>::_max += (Histogram<T, 1>::_max - Histogram<T, 1>::_min);
                Histogram<T, 1>::_width *= 2.0;

                for (size_t i = 0; i < (Histogram<T, 1>::_bins.size() / 2); ++i)
                {
                    const size_t index        = (2 * i);
                    Histogram<T, 1>::_bins[i] = Histogram<T, 1>::_bins[index] + Histogram<T, 1>::_bins[index + 1];
                }
                for (size_t i = (Histogram<T, 1>::_bins.size() / 2); i < Histogram<T, 1>::_bins.size(); ++i)
                {
                    Histogram<T, 1>::_bins[i] = 0.0;
                }
            }

            /**
             *  Decrease the minimum bound of the histogram while maintaining the total number of bins.
             *  Values are re-binned in the process.
             *
             *  @tparam T   Type binned.
             */
            template <typename T>
            inline void Dynamic<T, 1>::descend() noexcept
            {
                Histogram<T, 1>::_min -= (Histogram<T, 1>::_max - Histogram<T, 1>::_min);
                Histogram<T, 1>::_width *= 2.0;

                for (size_t i = (Histogram<T, 1>::_bins.size() - 1); i >= (Histogram<T, 1>::_bins.size() / 2); --i)
                {
                    const size_t index        = (2 * i) - Histogram<T, 1>::_bins.size();
                    Histogram<T, 1>::_bins[i] = Histogram<T, 1>::_bins[index] + Histogram<T, 1>::_bins[index + 1];
                }
                for (size_t i = 0; i < (Histogram<T, 1>::_bins.size() / 2); ++i)
                {
                    Histogram<T, 1>::_bins[i] = 0.0;
                }
            }



        } // namespace histogram
    }     // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM_DYNAMIC1_HPP
