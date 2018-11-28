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

//  -- Std --
#include <arctk/index/dim.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Region::Region(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const std::string& aether_id_, const Block& aether_) noexcept
          : geom::shape::Box(min_, max_)
          , _res(res_)
          , _blocks(init_blocks(res_, aether_id_, aether_))
        {
            assert(min_.x < max_.x);
            assert(min_.y < max_.y);
            assert(min_.z < max_.z);
            assert(res_[index::dim::cartesian::X] > 0);
            assert(res_[index::dim::cartesian::Y] > 0);
            assert(res_[index::dim::cartesian::Z] > 0);
            assert(!aether_id_.empty());
        }


        //  -- Initialisation --
        inline multi::vector<std::unordered_map<std::string, std::unique_ptr<Block>>, 3> Region::init_blocks(const std::array<size_t, 3>& res_, const std::string& aether_id_, const Block& aether_) const noexcept
        {
            multi::vector<std::unordered_map<std::string, std::unique_ptr<Block>>, 3> blocks = multi::vector::shape(res_);

            return (blocks);
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_REGION_INL
