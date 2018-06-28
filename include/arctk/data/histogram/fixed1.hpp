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
            };



        } // namespace histogram
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM_FIXED1_HPP
