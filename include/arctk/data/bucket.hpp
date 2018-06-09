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
            inline double                min() const noexcept;
            inline double                max() const noexcept;
            inline double                width() const noexcept;
            inline const std::vector<T>& bins() const noexcept;


          private:
            //  -- Placement --
            inline size_t find_index(double pos_) const noexcept;
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

        template <typename T>
        inline double Bin<T>::width() const noexcept
        {
            return (_width);
        }

        template <Typename T>
        inline const std::vector<T>& Bin<T>::bins() const noexcept
        {
            return (_bins);
        }


        //  -- Placement --
        template <typename T>
        inline size_t Bin<T>::find_index(double pos_) const noexcept
        {
            assert(pos_ >= _min);
            assert(pos_ <= _max);

            const auto index = static_cast<size_t>((pos_ - _min) / _width);

            return ((index == _counts.size()) ? (index - 1) : index);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_HPP
