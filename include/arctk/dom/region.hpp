/**
 *  @file   arctk/dom/region.hpp
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain region class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_REGION_HPP
#define ARCTK_DOM_REGION_HPP



//  == BASE ==
#include <arctk/geom/shape/box.hpp>



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

//  -- Arctk --
#include <arctk/dom/block.hpp>
#include <arctk/math/vec.hpp>
#include <arctk/multi/vector.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == CLASS ==
        /**
         *  Domain region class.
         */
        class Region : public geom::shape::Box
        {
            //  == FIELDS ==
          protected:
            //  -- Blocks --
            const std::array<size_t, 3>                                               _res;
            const vec3                                                                _block_size;
            multi::vector<std::unordered_map<std::string, std::unique_ptr<Block>>, 3> _blocks;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Region(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const std::string& aether_id_, const Block& aether_) noexcept;

          private:
            //  -- Initialisation --
            inline multi::vector<std::unordered_map<std::string, std::unique_ptr<Block>>, 3> init_blocks(const std::array<size_t, 3>& res_, const std::string& aether_id_, const Block& aether_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            const std::array<size_t, 3>& res() const noexcept;
            const vec3&                  block_size() const noexcept;
            std::unique_ptr<Driver>      driver(const phys::Photon& phot_) const noexcept;
        };



    } // namespace dom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/dom/region.inl>



//  == GUARD END ==
#endif // ARCTK_DOM_REGION_HPP
