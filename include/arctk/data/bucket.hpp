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
#include <cassert>
#include <vector>

//  -- Arctk --
#include <arctk/data/table.hpp>



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
          protected:
            //  -- Bounds --
            double _min; //!< Minimum bound of the bucket.
            double _max; //!< Maximum bound of the bucket.

          private:
            //  -- Bin --
            double _bin_width; //!< Width of the bins.

          protected:
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
            inline size_t                size() const noexcept;

            //  -- Searching --
            inline size_t find_index(double pos_) noexcept;

            //  -- Collection --
            virtual inline void collect(double   pos_,
                                        const T& val_) noexcept = 0; //!<  Collect a value into the bucket at a given position.  @tparam T   Type binned. @param  pos_    Position of the value to place.  @param  val_    Value to place within the bins.

            //  -- Printing --
            inline std::string str(const char delim_ = ',', const size_t width_ = 8) const noexcept
            {
                std::vector<double> pos(_bins.size());

                return (arc::data::Table<double, T>(pos, _bins).str());
            }
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
        template <typename T>
        inline Bucket<T>::Bucket(const double min_, const double max_, const size_t size_) noexcept
          : _min(min_)
          , _max(max_)
          , _bin_width((max_ - min_) / size_)
          , _bins(size_)
        {
            assert(min_ < max_);
            assert(size_ > 0);
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

        /**
         *  Get the maximum bound of the bucket.
         *
         *  @tparam T   Type binned.
         *
         *  @return Maximum bound of the bucket.
         */
        template <typename T>
        inline double Bucket<T>::max() const noexcept
        {
            return (_max);
        }

        /**
         *  Get the width of the bucket's bins.
         *
         *  @tparam T   Type binned.
         *
         *  @return Width of the bucket's bins.
         */
        template <typename T>
        inline double Bucket<T>::bin_width() const noexcept
        {
            return (_bin_width);
        }

        /**
         *  Get the bin data of the bucket.
         *
         *  @tparam T   Type binned.
         *
         *  @return Bin data of the bucket.
         */
        template <typename T>
        inline const std::vector<T>& Bucket<T>::bins() const noexcept
        {
            return (_bins);
        }

        /**
         *  Get the size of the bin data bins vector.
         *
         *  @tparam T   Type binned.
         *
         *  @return Size of the bin data bins vector.
         */
        template <typename T>
        inline size_t Bucket<T>::size() const noexcept
        {
            return (_bins.size());
        }


        //  -- Searching --
        /**
         *  Determine the index of the bin a position belongs in.
         *
         *  @tparam T   Type binned.
         *
         *  @param  pos_    Position to place within the bin.
         *
         *  @pre    pos_ must be greater than, or equal to, the minimum bound of the bucket.
         *  @pre    pos_ must be less than, or equal to, the maximum bound of the bucket.
         *
         *  @return Index of the bin to corresponding to the given position.
         */
        template <typename T>
        inline size_t Bucket<T>::find_index(const double pos_) noexcept
        {
            assert(pos_ >= _min);
            assert(pos_ <= _max);

            const auto index = static_cast<size_t>((pos_ - _min) / _bin_width);

            return ((index == _bins.size()) ? (index - 1) : index);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_HPP
