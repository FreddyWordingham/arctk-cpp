/**
 *  @file   arctk/index/finder.hpp
 *  @date   20/11/2018
 *  @author Freddy Wordingham
 *
 *  Index finding class.
 */



//  == GUARD ==
#ifndef ARCTK_INDEX_FINDER_HPP
#define ARCTK_INDEX_FINDER_HPP



//  == IMPORTS ==
//  -- Std --
#include <cstddef>

//  -- Arctk --
#include <arctk/math/vec.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace index //! indexing namespace
    {



        //  == CLASS ==
        /**
         *  Array element finding class.
         *
         *  @tparam N   Dimensionality of the finder.
         */
        template <size_t N>
        class Finder
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            const vecN<N> _min;
            const vecN<N> _max;

            //  -- Properties --
            const vecN<N>               _size;
            const std::array<size_t, N> _res;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Finder(const vecN<N>& min_, const vecN<N>& max_, const std::array<size_t, N>& res_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
        };



    } // namespace index
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/index/finder.inl>



//  == GUARD END ==
#endif // ARCTK_INDEX_FINDER_HPP
