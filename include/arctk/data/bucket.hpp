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
            //  -- Constructors --
            inline Bucket(double min_, double max_, size_t size_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                min() const noexcept;
            inline double                max() const noexcept;
            inline double                bin_width() const noexcept;
            inline const std::vector<T>& bins() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a one-dimensional bucket object with given bounds and size.
         *
         *  @tparam T   Type binned.
         *
         *  @param  min_    Minimum bound of the bucket.
         *  @param  max_    Maximum bound of the bucket.
         *  @param  size_   Number of bins.
         *
         *  @pre    min_ must be less than max_.
         *  @pre    Size_ must be positive.
         */
        inline Bucket::Bucket(const double min_, const double max_, const size_t size_) noexcept
          : _min(min_)
          , _max(max_)
          , _bin_width((max_ - min_) / size_)
          , _bins(size_)
        {
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum bound of the bucket.
         *
         *  @tparam T   Type binned.
         *
         *  @return Minimum bound of the bucket.
         */
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

        template <typename T>
        inline const std::vector<T>& bins() const noexcept
        {
            return (_bins);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_HPP
