/**
 *  @file   arctk/data/histogram/fixed1.hpp
 *  @date   28/06/2018
 *  @author Freddy Wordingham
 *
 *  One-dimensional, fixed-range, data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_HISTOGRAM_FIXED1_HPP
#define ARCTK_DATA_HISTOGRAM_FIXED1_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Arctk --
#include <arctk/data/histogram/fixed.hpp>



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
            class Fixed<T, 1>
            {
                //  == FIELDS ==
              private:
                //  -- Counts --
                T _misses{}; //!< Number of range misses.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Fixed(double min_, double max_, double size_) noexcept;
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
            inline Fixed<T>::Fixed(const double min_, const double max_, const double size_) noexcept
              : Histogram<T, 1>(min_, max_, size_)
            {
                assert(min_ < max_);
                assert(size_ > 0);
            }



        } // namespace histogram
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM_FIXED1_HPP
