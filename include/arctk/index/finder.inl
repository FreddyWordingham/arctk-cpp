/**
 *  @file   arctk/index/finder.inl
 *  @date   20/11/2018
 *  @author Freddy Wordingham
 *
 *  Index finding class.
 */



//  == GUARD ==
#ifndef ARCTK_INDEX_FINDER_INL
#define ARCTK_INDEX_FINDER_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace index //! indexing namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <size_t N>
        inline Finder<N>::Finder(const vecN<N>& min_, const vecN<N>& max_, const std::array<size_t, N>& res_) noexcept
          : _min(min_)
          , _max(max_)
          , _size()
          , _res(res_)
        {
        }


        //  -- Initialisation --
        template <size_t N>
        inline vecN<N> Finder<N>::init_size(const vecN<N>& min_, const vecN<N>& max_, const std::array<size_t, N>& res_) const noexcept
        {
            vecN<N> size = max_ - min_;

            for (size_t i = 0; i < N; ++i)
            {
                size[i] /= res_[i];
            }

            return (size);
        }



        //  == METHODS ==
        //  -- Checking --



    } // namespace index
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_INDEX_FINDER_INL
