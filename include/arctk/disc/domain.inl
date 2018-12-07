/**
 *  @file   arctk/disc/domain.inl
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain class.
 */



//  == GUARD ==
#ifndef ARCTK_DISC_DOMAIN_INL
#define ARCTK_DISC_DOMAIN_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Std --
#include <arctk/index/dim.hpp>
#include <arctk/phys/photon.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace disc //! discretisation namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Domain::Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const std::string& aether_id_, const opt::Material& aether_) noexcept
          : geom::shape::Box(min_, max_)
          , _res(res_)
          , _block_size((max_.x - min_.x) / res_[index::dim::cartesian::X], (max_.y - min_.y) / res_[index::dim::cartesian::Y], (max_.z - min_.z) / res_[index::dim::cartesian::Z])
          , _blocks(init_blocks(min_, max_, res_, aether_id_, aether_))
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
        inline multi::vector<Block, 3> Domain::init_blocks(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const std::string& aether_id_, const opt::Material& aether_) const noexcept
        {
            assert(min_.x < max_.x);
            assert(min_.y < max_.y);
            assert(min_.z < max_.z);
            assert(res_[index::dim::cartesian::X] > 0);
            assert(res_[index::dim::cartesian::Y] > 0);
            assert(res_[index::dim::cartesian::Z] > 0);
            assert(!aether_id_.empty());

            const vec3 block_size((max_.x - min_.x) / res_[index::dim::cartesian::X], (max_.y - min_.y) / res_[index::dim::cartesian::Y], (max_.z - min_.z) / res_[index::dim::cartesian::Z]);

            multi::vector<Block, 3> blocks;
            blocks.reserve(res_[index::dim::cartesian::X]);

            for (size_t i = 0; i < res_[index::dim::cartesian::X]; ++i)
            {
                const double x = min_.x + (block_size.x * i);

                blocks.emplace_back(multi::vector<Block, 2>());
                blocks.back().reserve(res_[index::dim::cartesian::Y]);

                for (size_t j = 0; j < res_[index::dim::cartesian::Y]; ++j)
                {
                    const double y = min_.y + (block_size.y * j);

                    blocks.back().emplace_back(std::vector<Block>());
                    blocks.back().back().reserve(res_[index::dim::cartesian::Z]);

                    for (size_t k = 0; k < res_[index::dim::cartesian::Z]; ++k)
                    {
                        const double z = min_.z + (block_size.z * j);

                        blocks.back().back().emplace_back(Block(vec3(x, y, z), vec3(x + block_size.x, y + block_size.y, z + block_size.z), aether_id_, aether_));
                    }
                }
            }

            return (blocks);
        }



        //  == METHODS ==
        //  -- Getters --
        inline const std::array<size_t, 3>& Domain::res() const noexcept
        {
            return (_res);
        }

        inline const vec3& Domain::block_size() const noexcept
        {
            return (_block_size);
        }


        //  -- Access --
        inline Block* Domain::block(const vec3& pos_) noexcept
        {
            const std::array<size_t, 3> index = indices(pos_);

            return (&_blocks[index[index::dim::cartesian::X]][index[index::dim::cartesian::Y]][index[index::dim::cartesian::Z]]);
        }


        //  -- Setters --
        inline void Domain::add_mat(const std::string& mat_id_, const opt::Material& mat_) noexcept
        {
            for (size_t i = 0; i < _res[index::dim::cartesian::X]; ++i)
            {
                for (size_t j = 0; j < _res[index::dim::cartesian::Y]; ++j)
                {
                    for (size_t k = 0; k < _res[index::dim::cartesian::Z]; ++k)
                    {
                        _blocks[i][j][k].add_mat(mat_id_, mat_);
                    }
                }
            }
        }


        //  -- Indexing --
        inline std::array<size_t, 3> Domain::indices(const vec3& pos_) const noexcept
        {
            assert(intersect(pos_));

            std::array<size_t, 3> indices;

            for (size_t i = 0; i < 3; ++i)
            {
                const size_t index = static_cast<size_t>((pos_[i] - _min[i]) / _block_size[i]);

                indices[i] = (index == _res[i]) ? (index - 1) : index;
            }

            return (indices);
        }


        //  -- Reduction --
        inline std::unordered_map<std::string, multi::vector<double, 3>> Domain::create_data_cube() const noexcept
        {
            std::unordered_map<std::string, multi::vector<double, 3>> cube;

            for (size_t i = 0; i < _res[index::dim::cartesian::X]; ++i)
            {
                for (size_t j = 0; j < _res[index::dim::cartesian::Y]; ++j)
                {
                    for (size_t k = 0; k < _res[index::dim::cartesian::Z]; ++k)
                    {
                        const std::unordered_map<std::string, double> data = _blocks[i][j][k].data();
                    }
                }
            }

            return (cube);
        }



    } // namespace disc
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DISC_DOMAIN_INL
