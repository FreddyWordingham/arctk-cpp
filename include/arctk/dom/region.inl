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
            multi::vector<std::unordered_map<std::string, std::unique_ptr<Block>>, 3> blocks;
            blocks.reserve(res_[0]);

            for (size_t i = 0; i < res_[0]; ++i)
            {
                blocks.emplace_back(multi::vector<std::unordered_map<std::string, std::unique_ptr<Block>>, 2>());
                blocks.back().reserve(res_[1]);

                for (size_t j = 0; j < res_[1]; ++j)
                {
                    blocks.back().emplace_back(std::vector<std::unordered_map<std::string, std::unique_ptr<Block>>>());
                    blocks.back().back().reserve(res_[2]);

                    for (size_t k = 0; k < res_[2]; ++k)
                    {
                        blocks.back().back().emplace_back(std::unordered_map<std::string, std::unique_ptr<Block>>());
                        blocks.back().back().back().insert(std::make_pair(aether_id_, std::make_unique<Block>(aether_)));
                    }
                }
            }

            return (blocks);
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_REGION_INL
