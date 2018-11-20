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
        };



    } // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/bin.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_HPP
