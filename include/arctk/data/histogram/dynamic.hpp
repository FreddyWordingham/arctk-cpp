/**
 *  @file   arctk/data/histogram/dynamic.hpp
 *  @date   12/07/2018
 *  @author Freddy Wordingham
 *
 *  Dynamic-range, data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_HISTOGRAM_DYNAMIC_HPP
#define ARCTK_DATA_HISTOGRAM_DYNAMIC_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
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
             *  One-dimensional, dynamic-range, data binning class.
             *
             *  @tparam T   Type binned.
             *  @tparam N   Dimensionality of the histogram.
             */
            template <typename T, size_t N>
            class Dynamic
            {
            };



        } // namespace histogram
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM_DYNAMIC_HPP
