/**
 *  @file   arctk/dom/block.inl
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain discretisation material block class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_BLOCK_INL
#define ARCTK_DOM_BLOCK_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <utility>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Block::Block(const vec3& min_, const vec3& max_, const std::string& aether_id_, const Mat& aether_) noexcept
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
        inline std::unordered_map<std::string, std::unique_ptr<Mat>> Block::init_mats(const std::string& aether_id_, const Mat& aether_) const noexcept
        {
            std::unordered_map<std::string, std::unique_ptr<Mat>> mats;

            mats.insert(std::make_pair(aether_id_, aether_.clone()));

            return (mats);
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_BLOCK_INL
