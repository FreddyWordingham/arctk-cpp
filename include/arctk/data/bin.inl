/**
 *  @file   arctk/data/bin.inl
 *  @date   20/11/2018
 *  @author Freddy Wordingham
 *
 *  Data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_INL
#define ARCTK_DATA_BIN_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, size_t N>
        inline Bin<T, N>::Bin(double min_, double max_, size_t res_, const T& init_) noexcept
          : _min(std::array<double, 1>({{min_}}))
          , _max(std::array<double, 1>({{max_}}))
          , _res(std::array<size_t, 1>({{res_}}))
          , _bin_width(std::array<double, 1>({{(max_ - min_) / res_}}))
          , _bins(multi::vector_helper<T, 1>::shape(std::array<size_t, 1>({{res_}}), init_))
        {
            static_assert(N == 1);

            assert(min_ < max_);
            assert(res_ > 0);
        }

        template <typename T, size_t N>
        inline Bin<T, N>::Bin(const std::array<double, N>& min_, const std::array<double, N>& max_, const std::array<size_t, N>& res_, const T& init_) noexcept
          : _min(min_)
          , _max(max_)
          , _res(res_)
          , _bin_width(init_bin_width(min_, max_, res_))
          , _bins(multi::vector_helper<T, N>::shape(res_, init_))
        {
            for (size_t i = 0; i < N; ++i)
            {
                assert(min_[i] < max_[i]);
                assert(res_[i] > 0);
            }
        }


        //  -- Initialisation --
        template <typename T, size_t N>
        inline std::array<double, N> Bin<T, N>::init_bin_width(const std::array<double, N>& min_, const std::array<double, N>& max_, const std::array<size_t, N>& res_) const noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                assert(min_[i] < max_[i]);
                assert(res_[i] > 0);
            }

            std::array<double, N> bin_width;
            for (size_t i = 0; i < N; ++i)
            {
                bin_width[i] = (max_[i] - min_[i]) / res_[i];
            }

            return (bin_width);
        }



        //  == METHODS ==
        //  -- Checking --



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_INL
