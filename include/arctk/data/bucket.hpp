/**
 *  @file   arctk/data/bucket.hpp
 *  @date   23/06/2018
 *  @author Freddy Wordingham
 *
 *  Data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BUCKET_HPP
#define ARCTK_DATA_BUCKET_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data binning class.
         *
         *  @tparam T   Type binned.
         */
        template <typename T>
        class Bucket
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            double _min; //!< Minimum bound of the bucket.
            double _max; //!< Maximum bound of the bucket.

            //  -- Bin --
            double _bin_width; //!< Width of the bins.

            //  -- Data --
            std::vector<T> _bins; //!< Bin data.


            //  == INSTANTIATION ==
          public:
            //  == METHODS ==
          public:
            //  -- Getters --
            inline double min() const noexcept;
            inline double max() const noexcept;
            inline double bin_width() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == METHODS ==
        //  -- Getters --
        template <typename T>
        inline double Bucket<T>::min() const noexcept
        {
            return (_min);
        }

        template <typename T>
        inline double Bucket<T>::max() const noexcept
        {
            return (_max);
        }

        template <typename T>
        inline double Bucket<T>::bin_width() const noexcept
        {
            return (_bin_width);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_HPP
