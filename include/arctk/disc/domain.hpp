/**
 *  @file   arctk/disc/domain.hpp
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain class.
 */



//  == GUARD ==
#ifndef ARCTK_DISC_DOMAIN_HPP
#define ARCTK_DISC_DOMAIN_HPP



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
#include <arctk/disc/block.hpp>
#include <arctk/math/vec.hpp>
#include <arctk/multi/vector.hpp>
#include <arctk/opt/material.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        class Photon;
    } // namespace phys
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace disc //! discretisation namespace
    {



        //  == CLASS ==
        /**
         *  Simulation domain class.
         */
        class Domain : public geom::shape::Box
        {
            //  == FIELDS ==
          protected:
            //  -- Blocks --
            const std::array<size_t, 3> _res;
            const vec3                  _block_size;
            multi::vector<Block, 3>     _blocks;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const std::string& aether_id_, const opt::Material& aether_) noexcept;

          private:
            //  -- Initialisation --
            inline multi::vector<Block, 3> init_blocks(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const std::string& aether_id_, const opt::Material& aether_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::array<size_t, 3>& res() const noexcept;
            inline const vec3&                  block_size() const noexcept;

            //  -- Access --
            inline Block* block(const vec3& pos_) noexcept;

            //  -- Setters --
            inline void add_mat(const std::string& mat_id_, const opt::Material& mat_) noexcept;

          private:
            //  -- Indexing --
            inline std::array<size_t, 3> indices(const vec3& pos_) const noexcept;

            //  -- Reduction --
            //            inline std::
        };



    } // namespace disc
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/disc/domain.inl>



//  == GUARD END ==
#endif // ARCTK_DISC_DOMAIN_HPP
