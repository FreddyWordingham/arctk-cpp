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
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T, size_t N>
            inline Dynamic<T, N>::Dynamic(const vecN<N>& min_, const vecN<N>& max_, const std::array<size_t, N>& res_) noexcept
              : Bucket<T, N>(min_, max_, res_)
            {
            }


            //  == METHODS ==
            //  -- Collection --
            template <typename T, size_t N>
            inline void Dynamic<T, N>::collect(const vecN<N>& pos_, const T& val_) noexcept
            {
                for (size_t i = 0; i < N; ++i)
                {
                    while (pos_[i] < Bucket<T, N>::_min[i])
                    {
                        descend(i);
                    }

                    while (pos_[i] > Bucket<T, N>::_max[i])
                    {
                        ascend(i);
                    }
                }

                Bucket<T, N>::template store<N>(Bucket<T, N>::_bins, static_cast<std::array<double, N>>(pos_), val_);
            }



        } // namespace bucket
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_DYNAMIC_HPP
