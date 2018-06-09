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



        //  == CLASS PROTOTYPES ==
        template <typename T>
        class Bucket;



        //  == STRUCTS ==
        template <typename>
        struct is_bucket : std::false_type
        {
        };

        template <typename T>
        struct is_bucket<Bucket<T>> : std::true_type
        {
        };



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
          protected:
            //  -- Bounds --
            double _min; //!< Minimum bound of the bucket range.
            double _max; //!< Maximum bound of the bucket range.

          private:
            //  -- Properties --
            double _width; //!< Bin width.

          protected:
            //  -- Data --
            std::vector<T> _bins; //!< Individual bin data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bucket(std::vector<double> min_, std::vector<double> max_, std::vector<size_t> res_) noexcept;

            //  -- Initialisation --
            inline std::vector<T> init_bins(std::vector<double> min_, std::vector<double> max_, std::vector<size_t> res_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                min() const noexcept;
            inline double                max() const noexcept;
            inline double                width() const noexcept;
            inline const std::vector<T>& bins() const noexcept;

            //  -- Collection --
            template <typename S>
            inline void collect(std::vector<double> pos_, const S& val_) noexcept
            {
                if constexpr (!is_bucket<T>::value)
                {
                    assert(pos_.size() == 1);
                }

                const double pos = pos_.back();
                pos_.pop_back();

                if ((pos < _min) || (pos > _max))
                {
                    return;
                }

                const size_t index = find_index(pos);

                if constexpr (is_bucket<T>::value)
                {
                    _bins[index].collect(pos_, val_);
                }
                else
                {
                    _bins[index] += val_;
                }
            }

          protected:
            //  -- Placement --
            inline size_t find_index(double pos_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        inline Bucket<T>::Bucket(std::vector<double> min_, std::vector<double> max_, std::vector<size_t> res_) noexcept
          : _min(min_.back())
          , _max(max_.back())
          , _width((max_.back() - min_.back()) / res_.back())
          , _bins(init_bins(min_, max_, res_))
        {
        }

        //  -- Initialisation --
        template <typename T>
        inline std::vector<T> Bucket<T>::init_bins(std::vector<double> min_, std::vector<double> max_, std::vector<size_t> res_) noexcept
        {
            const double min = min_.back();
            const double max = max_.back();
            const double res = res_.back();

            min_.pop_back();
            max_.pop_back();
            res_.pop_back();

            assert(min < max);
            assert(res > 0);

            if constexpr (is_bucket<T>::value)
            {
                return (std::vector<T>(res, T(min_, max_, res_)));
            }
            else
            {
                return (std::vector<T>(res));
            }
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
