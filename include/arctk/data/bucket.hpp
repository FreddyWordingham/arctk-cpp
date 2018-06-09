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
            inline Bucket(double min_, double max_, size_t res_) noexcept;

            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                min() const noexcept;
            inline double                max() const noexcept;
            inline double                width() const noexcept;
            inline const std::vector<T>& bins() const noexcept;

            //  -- Collection --
            virtual inline void collect(const std::vector<double>& pos_, T val_) noexcept = 0;

          private:
            //  -- Placement --
            inline size_t find_index(double pos_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        inline Bucket<T>::Bucket(const double min_, const double max_, const size_t res_) noexcept
          : _min(min_)
          , _max(max_)
          , _width((max_ - min_) / res_)
          , _bins(res_)
        {
            assert(min_ < max_);
            assert(res_ > 0);
        }



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
        inline double Bucket<T>::width() const noexcept
        {
            return (_width);
        }

        template <typename T>
        inline const std::vector<T>& Bucket<T>::bins() const noexcept
        {
            return (_bins);
        }


        //  -- Placement --
        template <typename T>
        inline size_t Bucket<T>::find_index(double pos_) const noexcept
        {
            assert(pos_ >= _min);
            assert(pos_ <= _max);

            const auto index = static_cast<size_t>((pos_ - _min) / _width);

            return ((index == _bins.size()) ? (index - 1) : index);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_HPP
