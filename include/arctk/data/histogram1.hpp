/**
 *  @file   arctk/data/histogram1.hpp
 *  @date   28/06/2018
 *  @author Freddy Wordingham
 *
 *  One-dimensional data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_HISTOGRAM1_HPP
#define ARCTK_DATA_HISTOGRAM1_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Arctk --
#include <arctk/data/histogram.hpp>



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
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a one-dimensional histogram object with given bounds and size.
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
        inline Histogram<T>::Histogram(const double min_, const double max_, const size_t size_) noexcept
          : _min(min_)
          , _max(max_)
          , _bin_width((max_ - min_) / size_)
          , _bins(size_)
        {
            assert(min_ < max_);
            assert(size_ > 0);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM1_HPP
