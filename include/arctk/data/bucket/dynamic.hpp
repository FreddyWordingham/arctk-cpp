/**
 *  @file   arctk/data/bucket/dynamic.hpp
 *  @date   14/06/2018
 *  @author Freddy Wordingham
 *
 *  Dynamic range data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BUCKET_DYNAMIC_HPP
#define ARCTK_DATA_BUCKET_DYNAMIC_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Arctk --
#include <arctk/data/bucket.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <iostream>

//  -- Arctk --
#include <arctk/math.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace bucket //! bucketing namespace
        {



            //  == CLASS ==
            /**
             *  Dynamic range binning class.
             *  Re-organises to capture all collection values.
             *
             *  @tparam T   Type stored by the bucket.
             *  @tparam N   Dimensionality of the bucket.
             */
            template <typename T, size_t N>
            class Dynamic : public Bucket<T, N>
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Dynamic(const vecN<N>& min_, const vecN<N>& max_, const std::array<size_t, N>& res_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const T& misses() noexcept;

                //  -- Collection --
                inline void collect(const vecN<N>& pos_, const T& val_) noexcept override;

              private:
                //  -- Re-organisation --
                // template <size_t I>
                // inline void descend() noexcept;
                template <size_t I>
                inline void ascend(utl::MultiVec<T, I>& bins_, const vecN<N>& pos_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T, size_t N>
            inline Dynamic<T, N>::Dynamic(const vecN<N>& min_, const vecN<N>& max_, const std::array<size_t, N>& res_) noexcept
              : Bucket<T, N>(min_, max_, res_)
            {
                for (size_t i = 0; i < N; ++i)
                {
                    assert(min_[i] < max_[i]);
                    assert((res_[i] % 2) == 0);
                }
                assert(prop::always_greater_than(res_, 0));
            }


            //  == METHODS ==
            //  -- Collection --
            template <typename T, size_t N>
            inline void Dynamic<T, N>::collect(const vecN<N>& pos_, const T& val_) noexcept
            {
                ascend<N>(Bucket<T, N>::_bins, pos_);
                std::cout << "Check!\n";

                // Bucket<T, N>::template store<N>(Bucket<T, N>::_bins, static_cast<std::array<double, N>>(pos_), val_);
            }


            //  -- Re-organisation --
            /*template <typename T, size_t N>
            inline void Dynamic<T, N>::descend(const size_t dim_) noexcept
            {
                assert(dim_ < N);

                Bucket<T, N>::_min[dim_] -= (Bucket<T, N>::_max[dim_] - Bucket<T, N>::_min[dim_]);
                Bucket<T, N>::_width[dim_] *= 2.0;

                for (size_t i = (Bucket<T, N>::_res[dim_] - 1); i >= (Bucket<T, N>::_res[dim_] / 2); --i)
                {
                    const size_t index           = (2 * i) - Bucket<T, N>::_res[dim_];
                    Bucket<T, N>::_bins[dim_][i] = math::add<T, N>(Bucket<T, N>::_bins[dim_][index], Bucket<T, N>::_bins[dim_][index + 1]);
                }

                for (size_t i = 0; i < (Bucket<T, N>::_res[dim_] / 2); ++i)
                {
                    Bucket<T, N>::_bins[dim_][i] = {};
                }
            }*/

            template <typename T, size_t N>
            template <size_t I>
            inline void Dynamic<T, N>::ascend(utl::MultiVec<T, I>& bins_, const vecN<N>& pos_) noexcept
            {
                std::cout << "I is : " << I << "\n";

                while (pos_[I - 1] > Bucket<T, N>::_max[I - 1])
                {
                    Bucket<T, N>::_max[I - 1] += (Bucket<T, N>::_max[I - 1] - Bucket<T, N>::_min[I - 1]);
                    Bucket<T, N>::_width[I - 1] *= 2.0;

                    if constexpr (I > 1)
                    {
                        for (size_t i = 0; i < (Bucket<T, N>::_res[I - 1] / 2); ++i)
                        {
                            const size_t index = 2 * i;
                            std::cout << bins_[index].size() << "\t:\t" << bins_[index + 1].size() << "\t:\t" << Bucket<T, N>::_res[I - 1] << "\t:\t" << index << "\n";
                            bins_[i] = math::add<T, I - 1>(bins_[index], bins_[index + 1]);
                        }

                        for (size_t i = (Bucket<T, N>::_res[I - 1] / 2); i < Bucket<T, N>::_res[I - 1]; ++i)
                        {
                            if constexpr (I > 2)
                            {
                                utl::reset_MultiVec<T, I - 1>(Bucket<T, N>::_bins[i]);
                            }
                            else
                            {
                                Bucket<T, N>::_bins[i] = {};
                            }
                        }
                    }
                    else
                    {

                        for (size_t i = 0; i < (Bucket<T, N>::_res[I - 1] / 2); ++i)
                        {
                            const size_t index = 2 * i;
                            bins_[i]           = bins_[index] + bins_[index + 1];
                        }

                        for (size_t i = (Bucket<T, N>::_res[I - 1] / 2); i < Bucket<T, N>::_res[I - 1]; ++i)
                        {
                            bins_[i] = 0.0;
                        }
                    }
                }

                if constexpr (I > 1)
                {
                    for (size_t i = 0; i < bins_.size(); ++i)
                    {
                        ascend<I - 1>(bins_[i], pos_);
                    }
                }
            }



        } // namespace bucket
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_DYNAMIC_HPP
