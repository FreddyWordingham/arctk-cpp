/**
 *  @file   arctk/opt/region.inl
 *  @date   26/11/2018
 *  @author Freddy Wordingham
 *
 *  Optical region class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_REGION_INL
#define ARCTK_OPT_REGION_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Region::Region(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) noexcept
          : geom::shape::Box(min_, max_)
          , _res(res_)
        {
            assert(min_.x < max_.x);
            assert(min_.y < max_.y);
            assert(min_.z < max_.z);
            for (size_t i = 0; i < 3; ++i)
            {
                assert(res_[i] > 0);
            }
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Region::~Region() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        inline const std::array<size_t, 3>& Region::res() const noexcept
        {
            return (_res);
        }



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_REGION_INL
