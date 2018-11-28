/**
 *  @file   arctk/disc/block.inl
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain discretisation material block class.
 */



//  == GUARD ==
#ifndef ARCTK_DISC_BLOCK_INL
#define ARCTK_DISC_BLOCK_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <utility>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace disc //! discretisation namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Block::Block(const vec3& min_, const vec3& max_, const std::string& aether_id_, const opt::Material& aether_) noexcept
          : geom::shape::Box(min_, max_)
          , _mats(init_mats(aether_id_, aether_))
        {
            assert(min_.x < max_.x);
            assert(min_.y < max_.y);
            assert(min_.z < max_.z);
            assert(!aether_id_.empty());
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Block::~Block() noexcept = default;


        //  -- Initialisation --
        inline std::unordered_map<std::string, std::unique_ptr<opt::Material>> Block::init_mats(const std::string& aether_id_, const opt::Material& aether_) const noexcept
        {
            std::unordered_map<std::string, std::unique_ptr<opt::Material>> mats;

            mats.insert(std::make_pair(aether_id_, aether_.clone()));

            return (mats);
        }



        //  == METHODS ==
        //  -- Getters --
        inline const opt::Material* Block::mat(const std::string& mat_id_) const noexcept
        {
            assert(_mats.count(mat_id_) > 0);

            return (_mats.at(mat_id_).get());
        }


        //  -- Setters --
        inline void Block::add_mat(const std::string& mat_id_, const opt::Material& mat_) noexcept
        {
            assert(_mats.count(mat_id_) == 0);

            _mats.insert(std::make_pair(mat_id_, mat_.clone()));
        }



    } // namespace disc
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DISC_BLOCK_INL
