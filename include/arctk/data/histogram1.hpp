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
        };



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_HISTOGRAM1_HPP
