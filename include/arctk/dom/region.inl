/**
 *  @file   arctk/dom/region.inl
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain region class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_REGION_INL
#define ARCTK_DOM_REGION_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Region::Region(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const Block& aether_) noexcept
        {
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_REGION_INL
