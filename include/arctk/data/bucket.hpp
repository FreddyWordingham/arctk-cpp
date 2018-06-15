/**
 *  @file   arctk/data/bucket.hpp
 *  @date   12/06/2018
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
//  -- Arctk --
#include <arctk/math.hpp>
#include <arctk/prop.hpp>
#include <arctk/utl.hpp>



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
         *  @tparam N   Dimensionality.
         */
        template <typename T, size_t N>
        class Bucket
        {
            //  == FIELDS ==
          protected:
            //  -- Bounds --
            vecN<N> _min; //!< Minimum bound of the bucket.
            vecN<N> _max; //!< Maximum bound of the bucket.

            //  -- Bin Metadata --
            std::array<size_t, N> _res;   //!< Number of bins in each dimension.
            std::array<double, N> _width; //!< Width of bins in each dimension.

            //  -- Data --
            utl::MultiVec<T, N> _bins; //!< Bin data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bucket(const vecN<N>& min_, const vecN<N>& max_, const std::array<size_t, N>& res_) noexcept;

            //  -- Initialisation --
            inline std::array<double, N> init_width(const vecN<N>& min_, const vecN<N>& max_, const std::array<size_t, N>& res_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const vecN<N>&               min() noexcept;
            inline const vecN<N>&               max() noexcept;
            inline const std::array<size_t, N>& res() noexcept;
            inline const std::array<double, N>& width() noexcept;
            inline const utl::MultiVec<T, N>&   bins() noexcept;

            //  -- Searching --
            inline size_t find_index(size_t dim_, double pos_) noexcept;

            //  -- Collection --
            virtual inline void collect(const vecN<N>& pos_, const T& val_) noexcept = 0;

          protected:
            //  -- Storage --
            template <size_t I>
            inline void store(utl::MultiVec<T, I>& bins_, const std::array<double, N>& pos_, const T& val_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a multi-dimensional bucket object with given bounds and a resolution in each dimension.
         *
         *  @tparam T   Type binned.
         *  @tparam N   Dimensionality.
         *
         *  @param  min_    Minimum bound of the bucket.
         *  @param  max_    Maximum bound of the bucket.
         *  @param  res_    Number of bins in each dimension.
         *
         *  @pre    All values of min_ must be less than each corresponding value of max_.
         *  @pre    All values of res_ must be positive.
         */
        template <typename T, size_t N>
        inline Bucket<T, N>::Bucket(const vecN<N>& min_, const vecN<N>& max_, const std::array<size_t, N>& res_) noexcept
          : _min(min_)
          , _max(max_)
          , _res(res_)
          , _width(init_width(min_, max_, res_))
          , _bins(utl::make_MultiVec<T, N>(res_))
        {
            for (size_t i = 0; i < N; ++i)
            {
                assert(min_[i] < max_[i]);
            }
            assert(prop::always_greater_than(res_, 0));
        }


        //  -- Initialisation --
        /**
         *  Initialise the width of bins in each dimension.
         *
         *  @tparam T   Type binned.
         *  @tparam N   Dimensionality.
         *
         *  @param  min_    Minimum bound of the bucket.
         *  @param  max_    Maximum bound of the bucket.
         *  @param  res_    Number of bins in each dimension.
         *
         *  @pre    All values of min_ must be less than each corresponding value of max_.
         *  @pre    All values of res_ must be positive.
         *
         *  @return Initialised array of bin widths.
         */
        template <typename T, size_t N>
        inline std::array<double, N> Bucket<T, N>::init_width(const vecN<N>& min_, const vecN<N>& max_, const std::array<size_t, N>& res_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                assert(min_[i] < max_[i]);
            }
            assert(prop::always_greater_than(res_, 0));

            std::array<double, N> width;

            for (size_t i = 0; i < N; ++i)
            {
                width[i] = (max_[i] - min_[i]) / res_[i];
            }

            return (width);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum bound of the bucket.
         *
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
         *
         *  @return Minimum bound of the bucket.
         */
        template <typename T, size_t N>
        inline const vecN<N>& Bucket<T, N>::min() noexcept
        {
            return (_min);
        }

        template <typename T, size_t N>
        inline const vecN<N>& Bucket<T, N>::max() noexcept
        {
            return (_max);
        }

        template <typename T, size_t N>
        inline const std::array<size_t, N>& Bucket<T, N>::res() noexcept
        {
            return (_res);
        }

        template <typename T, size_t N>
        inline const std::array<double, N>& Bucket<T, N>::width() noexcept
        {
            return (_width);
        }

        template <typename T, size_t N>
        inline const utl::MultiVec<T, N>& Bucket<T, N>::bins() noexcept
        {
            return (_bins);
        }


        //  -- Searching --
        template <typename T, size_t N>
        inline size_t Bucket<T, N>::find_index(const size_t dim_, const double pos_) noexcept
        {
            assert(pos_ >= _min[dim_]);
            assert(pos_ <= _max[dim_]);

            const auto index = static_cast<size_t>((pos_ - _min[dim_]) / _width[dim_]);

            return ((index == _res[dim_]) ? (index - 1) : index);
        }


        //  -- Storage --
        template <typename T, size_t N>
        template <size_t I>
        inline void Bucket<T, N>::store(utl::MultiVec<T, I>& bins_, const std::array<double, N>& pos_, const T& val_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                assert((pos_[i] >= _min[i]) && (pos_[i] <= _max[i]));
            }

            const size_t index = find_index(N - I, pos_[N - I]);

            if constexpr (I == 1)
            {
                bins_[index] += val_;
            }
            else
            {
                store<I - 1>(bins_[index], pos_, val_);
            }
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_HPP
