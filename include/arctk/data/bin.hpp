/**
 *  @file   arctk/data/bin.hpp
 *  @date   20/11/2018
 *  @author Freddy Wordingham
 *
 *  Data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_HPP
#define ARCTK_DATA_BIN_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>
#include <vector>

//  -- Arctk --
#include <arctk/math/vec.hpp>
#include <arctk/multi/vector.hpp>



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
         *  @tparam N   Dimensionality of the bin.
         */
        template <typename T, size_t N>
        class Bin
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            std::array<double, N> _min;
            std::array<double, N> _max;

            //  -- Data --
            const std::array<size_t, N> _res;
            std::array<double, N>       _bin_width;
            multi::vector<T, N>         _bins;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bin(double min_, double max_, size_t res_, const T& init_ = {}) noexcept;
            inline Bin(const std::array<double, N>& min_, const std::array<double, N>& max_, const std::array<size_t, N>& res_, const T& init_ = {}) noexcept;

          private:
            //  -- Initialisation --
            inline std::array<double, N> init_bin_width(const std::array<double, N>& min_, const std::array<double, N>& max_, const std::array<size_t, N>& res_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const multi::vector<T, N>& data() const noexcept
            {
                return (_bins);
            }

            inline void count(const vecN<N>& pos_, const T& value_) noexcept
            {
                count_helper<N>(pos_, value_, _bins);
            }

          private:
            template <size_t M>
            inline void count_helper(const vecN<N>& pos_, const T& value_, multi::vector<T, M>& bins_) noexcept
            {
                count_helper<N - 1>(pos_, value_, bins_[static_cast<size_t>((pos_[N - M] - _min[N - M]) / _bin_width[N - M])]);
            }

            template <>
            inline void count_helper<1>(const vecN<N>& pos_, const T& value_, std::vector<T>& bins_) noexcept
            {
                bins_[static_cast<size_t>((pos_[N - 1] - _min[N - 1]) / _bin_width[N - 1])] += value_;
            }
        };



    } // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/bin.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_HPP
