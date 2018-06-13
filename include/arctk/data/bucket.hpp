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
         */
        template <typename T, size_t N>
        class Bucket
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            std::array<double, N> _min;
            std::array<double, N> _max;

            //  -- Bin Metadata --
            std::array<size_t, N> _res;
            std::array<double, N> _width;

            //  -- Data --
            utl::MultiVec<T, N> _bins;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bucket(const std::array<double, N>& min_, const std::array<double, N>& max_, const std::array<size_t, N>& res_) noexcept;

            //  -- Initialisation --
            inline std::array<double, N> init_width(const std::array<double, N>& min_, const std::array<double, N>& max_, const std::array<size_t, N>& res_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const utl::MultiVec<T, N>&   bins() noexcept;
            inline const std::array<double, N>& min() noexcept;
            inline const std::array<double, N>& max() noexcept;
            inline const std::array<size_t, N>& res() noexcept;
            inline const std::array<double, N>& width() noexcept;

            //  -- Collection --
            inline void collect(const std::array<double, N>& pos_, const T& val_) noexcept;

          private:
            template <size_t I>
            inline void collect(utl::MultiVec<T, I>& bins_, const std::array<double, I>& pos_, const T& val_) noexcept;
            inline void collect(utl::MultiVec<T, 1>& bins_, const std::array<double, 1>& pos_, const T& val_) noexcept;

            template <size_t I>
            size_t find_index(const double pos_)
            {
                assert(pos_ >= _min[I]);
                assert(pos_ <= _max[I]);

                const auto index = static_cast<size_t>((pos_ - _min[I]) / _width[I]);

                return ((index == _res[I]) ? (index - 1) : index);
            }
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, size_t N>
        inline Bucket<T, N>::Bucket(const std::array<double, N>& min_, const std::array<double, N>& max_, const std::array<size_t, N>& res_) noexcept
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
        inline std::array<double, N> Bucket<T, N>::init_width(const std::array<double, N>& min_, const std::array<double, N>& max_, const std::array<size_t, N>& res_) noexcept
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
        inline const utl::MultiVec<T, N>& Bucket<T, N>::bins() noexcept
        {
            return (_bins);
        }

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


        //  -- Collection --
        template <typename T, size_t N>
        inline void Bucket<T, N>::collect(const std::array<double, N>& pos_, const T& val_) noexcept
        {
            collect(_bins, pos_, val_);
        }

        template <typename T, size_t N>
        template <size_t I>
        inline void Bucket<T, N>::collect(utl::MultiVec<T, I>& bins_, const std::array<double, I>& pos_, const T& val_) noexcept
        {
            std::array<double, I - 1> pos;
            std::copy(std::next(std::begin(pos_)), std::end(pos_), std::begin(pos));

            const size_t index = find_index<N - I>(pos_.front());

            collect(bins_[index], pos, val_);
        }

        template <typename T, size_t N>
        inline void collect(utl::MultiVec<T, 1>& bins_, const std::array<double, 1>& pos_, const T& val_) noexcept
        {
            const size_t index = find_index<N - 1>(pos_.front());

            bins_[index] += val_;
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_HPP
