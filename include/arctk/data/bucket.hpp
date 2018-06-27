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
#include <arctk/settings.hpp>



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


            //  == OPERATORS ==
          public:
            //  -- Stream --
            template <typename S, typename _T>
            friend inline S& operator<<(S& stream_, const Bucket<_T>& buck_) noexcept; //!< Write the bucket data in a human-readable format. @tparam S   Stream type to write to. @tparam _T  Type binned. @param  stream_ Stream to write to. @param  buck_
                                                                                       //!< Bucket to be printed. @return Reference to the stream post-print.

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
            inline std::string str(const char delim_ = settings::DEFAULT_DELIM, const size_t width_ = settings::DEFAULT_PRINT_WIDTH) const noexcept;

            //  -- Saving --
            inline void save(const std::string& path_, const char delim_ = settings::DEFAULT_DELIM, const size_t width_ = settings::DEFAULT_PRINT_WIDTH) const noexcept;
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



        //  == OPERATORS ==
        //  -- Stream --
        /**
         *  Write the bucket data in a human-readable format.
         *
         *  @tparam S   Stream type to write to.
         *  @tparam T   Type binned.
         *
         *  @param  stream_ Stream to write to.
         *  @param  buck_   Bucket to be printed.
         *
         *  @return Reference to the stream post-print.
         */
        template <typename S, typename T>
        inline S& operator<<(S& stream_, const Bucket<T>& buck_) noexcept
        {
            stream_ << buck_.str();

            return (stream_);
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


        //  -- Printing --
        /**
         *  Form the bucket data into a human readable string.
         *
         *  @tparam T   Type binned.
         *
         *  @param  delim_  Delimiter character used to seperate consecutive values.
         *  @param  width_  Print width allocated to each value.
         *
         *  @return Human readable string of the bucket data.
         */
        template <typename T>
        inline std::string Bucket<T>::str(const char delim_, const size_t width_) const noexcept
        {
            std::vector<double> pos(_bins.size());

            for (size_t i = 0; i < pos.size(); ++i)
            {
                pos[i] = _min + ((i + 0.5) * _bin_width);
            }

            return (arc::data::Table<double, T>(pos, _bins).str(delim_, width_));
        }


        //  -- Saving --
        /**
         *  Save bucket data as a csv file.
         *
         *  @tparam T   Type binned.
         *
         *  @param  path_   Path to the output file.
         *  @param  delim_  Delimiter character used to seperate consecutive values.
         *  @param  width_  Print width allocated to each value.
         *
         *  @pre    path_ may not be empty.
         */
        template <typename T>
        inline void Bucket<T>::save(const std::string& path_, const char delim_, const size_t width_) const noexcept
        {
            assert(!path_.empty());

            sys::file::Out file(path_);

            file << str(delim_, width_);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_HPP
