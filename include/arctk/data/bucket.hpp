/**
 *  @file   arctk/data/bucket.hpp
 *  @date   09/06/2018
 *  @author Freddy Wordingham
 *
 *  Data binning base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BUCKET_HPP
#define ARCTK_DATA_BUCKET_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Histogram class which bins values into a data vector.
         *
         *  @tparam T   Type of value to be counted.
         */
        template <typename T>
        class Bucket
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            double _min; //!< Minimum bound of the bucket range.
            double _max; //!< Maximum bound of the bucket range.

            //  -- Properties --
            double _width; //!< Bin width.

            //  -- Data --
            std::vector<T> _bins; //!< Individual bin data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --

            //  == METHODS ==
          public:
            //  -- Getters --
            inline double min() const noexcept;
            inline double max() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == OPERATORS ==
        //  -- Stream --



        //  == METHODS ==
        //  -- Getters --
        template <typename T>
        inline double Bin<T>::min() const noexcept
        {
            return (_min);
        }

        template <typename T>
        inline double Bin<T>::max() const noexcept
        {
            return (_max);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_HPP
