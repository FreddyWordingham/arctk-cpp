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
         *  @tparam T   Type stored by the bucket.
         *  @tparam N   Dimensionality of the bucket.
         */
        template <typename T, size_t N>
        class Bucket
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            vecN<N> _min;
            vecN<N> _max;

            //  -- Bin Information --
            std::array<size_t, N> _res;
            std::array<double, N> _width;

            //  -- Data --
            utl::MultiVec<T, N> _bins;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bucket(const vecN<N> min_, const vecN<N> max_, const std::array<size_t, N>& res_) noexcept;

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
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, size_t N>
        inline Bucket<T, N>::Bucket(const vecN<N> min_, const vecN<N> max_, const std::array<size_t, N>& res_) noexcept
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
        template <typename T, size_t N>
        inline const std::array<double, N>& Bucket<T, N>::min() noexcept
        {
            return (_min);
        }

        template <typename T, size_t N>
        inline const std::array<double, N>& Bucket<T, N>::max() noexcept
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



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_HPP
