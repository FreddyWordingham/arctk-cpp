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
            vecN<N> _min;
            vecN<N> _max;

            //  -- Data --
            multi::vector<T, N> _bins;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bin(const vecN<N>& min_, const vecN<N>& max_, const std::array<size_t, N>& res_, const T& init_ = {}) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const multi::vector<T, N>& bins() const noexcept
            {
                return (_bins);
            }

            inline void count(const vecN<N>& pos_, const T& value_) noexcept
            {
                count_helper<N>(pos_, value_, _bins);
            }

          private:
            template <size_t M>
            inline void count_helper(const vecN<N>& pos_, const T& value_, multi::vector<T, N>& bins_) noexcept
            {
                count_helper<N - 1>(pos_, value_, _bins[0]);
            }

            template <>
            inline void count_helper(const vecN<N>& pos_, const T& value_, multi::vector<T, N>& bins_) noexcept
            {
                _bins[0] += value_;
            }
        };



    } // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/bin.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_HPP
