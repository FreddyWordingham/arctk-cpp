/**
 *  @file   arctk/data/histogram/average.hpp
 *  @date   28/06/2018
 *  @author Freddy Wordingham
 *
 *  Average data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_HISTOGRAM_AVERAGE_HPP
#define ARCTK_DATA_HISTOGRAM_AVERAGE_HPP



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
        namespace histogram //! histogram namespace
        {



            //  == CLASS ==
            /**
             *  One-dimensional, averaging, data binning class.
             *
             *  @tparam T   Type binned.
             *  @tparam N   Dimensionality of the histogram.
             */
            template <typename T, size_t N>
            class Average : public Histogram<T, N>
            {
            };



        } // namespace histogram
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM_AVERAGE_HPP
