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

            //  -- Data --
            utl::MultiVec<T, N> _bins;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bucket(const std::array<double, N>& min_, const std::array<double, N>& max_, const std::array<size_t, N>& res_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const utl::MultiVec<T, N>& bins() noexcept;

            //  -- Collection --
            void collect(const std::array<double, N>& pos_, const T& val_)
            {
                collect(_bins, pos_, val_);
            }

          private:
            template <size_t I>
            void collect(utl::MultiVec<T, I>& bins_, const std::array<double, I>& pos_, const T& val_)
            {
                std::array<double, I - 1> pos;
                std::copy(std::next(std::begin(pos_)), std::end(pos_), std::begin(pos));

                const size_t index = 0;

                collect(bins_[index], pos, val_);
            }

            void collect(utl::MultiVec<T, 1>& bins_, const std::array<double, 1>& pos_, const T& val_)
            {
                const size_t index = 0;

                bins_[index] += val_;
            }

            template <size_t I>
            size_t find_index(const double pos_)
            {
                assert(pos_ >= _min[I]);
                assert(pos_ <= _max[I]);

                const auto index = static_cast<size_t>((pos_ - _min[I]) / _width);

                return ((index == _res[I]) ? (index - 1) : index);
            }
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, size_t N>
        inline Bucket<T, N>::Bucket(const std::array<double, N>& min_, const std::array<double, N>& max_, const std::array<size_t, N>& res_) noexcept
          : _min(min_)
          , _max(max_)
          , _bins(utl::make_MultiVec<T, N>(res_))
        {
        }



        //  == METHODS ==
        //  -- Getters --
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
