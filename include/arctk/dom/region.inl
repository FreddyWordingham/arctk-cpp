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
#include <arctk/phys/photon.hpp>



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
          , _block_size((max_.x - min_.x) / res_[index::dim::cartesian::X], (max_.y - min_.y) / res_[index::dim::cartesian::Y], (max_.z - min_.z) / res_[index::dim::cartesian::Z])
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
            blocks.reserve(res_[index::dim::cartesian::X]);

            for (size_t i = 0; i < res_[index::dim::cartesian::X]; ++i)
            {
                blocks.emplace_back(multi::vector<std::unordered_map<std::string, std::unique_ptr<Block>>, 2>());
                blocks.back().reserve(res_[index::dim::cartesian::Y]);

                for (size_t j = 0; j < res_[index::dim::cartesian::Y]; ++j)
                {
                    blocks.back().emplace_back(std::vector<std::unordered_map<std::string, std::unique_ptr<Block>>>());
                    blocks.back().back().reserve(res_[index::dim::cartesian::Z]);

                    for (size_t k = 0; k < res_[index::dim::cartesian::Z]; ++k)
                    {
                        blocks.back().back().emplace_back(std::unordered_map<std::string, std::unique_ptr<Block>>());
                        blocks.back().back().back().insert(std::make_pair(aether_id_, aether_.clone()));
                    }
                }
            }

            return (blocks);
        }



        //  == METHODS ==
        //  -- Getters --
        const std::array<size_t, 3>& Region::res() const noexcept
        {
            return (_res);
        }

        const vec3& Region::block_size() const noexcept
        {
            return (_block_size);
        }

        std::unique_ptr<Driver> Region::driver(const phys::Photon& phot_) const noexcept
        {
            const std::array<size_t, 3> index = indices(phot_.pos());

            const std::unordered_map<std::string, std::unique_ptr<Block>>& map = _blocks[index[index::dim::cartesian::X]][index[index::dim::cartesian::Y]][index[index::dim::cartesian::Z]];

            assert(map.find(phot_.cur_mat_id()) != map.end());

            return (map[phot_.mat_id()].driver(phot_));
        }


        //  -- Indexing --
        const std::array<size_t, 3>& Region::indices(const vec3& pos_) const noexcept
        {
            assert(contains(pos_));

            std::array<size_t, 3> indices;

            for (size_t i = 0; i < 3; ++i)
            {
                const size_t index = static_cast<size_t>((pos_[i] - _min[i]) / _block_size[i]);

                indices[i] = (index == _res[i]) ? (index - 1) : index;
            }

            return (indices);
        }



    } // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_REGION_INL
