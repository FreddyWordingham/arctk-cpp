/**
 *  @file   arctk/torus/sim.hpp
 *  @date   09/12/2018
 *  @author Freddy Wordingham
 *
 *  Radiative transfer simulation class.
 */



//  == GUARD ==
#ifndef ARCTK_TORUS_SIM_HPP
#define ARCTK_TORUS_SIM_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>
#include <memory>
#include <string>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/disc/domain.hpp>
#include <arctk/equip/entity.hpp>
#include <arctk/math/vec.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace entity //! entity namespace
        {
            class Detector;
            class Light;
        }         // namespace entity
    }             // namespace equip
    namespace opt //! optical namespace
    {
        class Material;
    } // namespace opt
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace torus //! transport of radiation under skin namespace
    {



        //  == CLASS ==
        /**
         *  Radiative transfer simulation class.
         */
        class Sim
        {
            //  == FIELDS ==
          private:
            //  -- Entities --
            std::vector<std::unique_ptr<equip::Entity>>                         _entities;
            std::vector<equip::entity::Light* const>                            _lights;
            std::vector<std::pair<const equip::entity::Detector*, std::string>> _detectors;

            //  -- Domain --
            disc::Domain _dom;

            //  -- Tree --
            size_t _max_depth;
            size_t _tar_tris;

            //  -- Roulette --
            bool   _roulette;
            double _roulette_limit;
            double _roulette_chance;

            //  -- Parallelisation --
            unsigned int _update_delta;
            size_t       _num_threads;

            //  -- Rendering --
            bool _pre_render;
            bool _post_render;

            //  -- Output --
            std::string _output_dir;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Sim(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const std::string& aether_id_, const opt::Material& aether_) noexcept;


            //  == METHODS ==
          public:
            //  -- Setters --
            inline void set_tree_max_depth(size_t max_depth_) noexcept;
            inline void set_tree_tar_tris(size_t tar_tris_) noexcept;
            inline void set_roulette(bool roulette_) noexcept;
            inline void set_roulette_limit(double roulette_limit_) noexcept;
            inline void set_roulette_chance(double roulette_chance_) noexcept;
            inline void set_update_delta(unsigned int update_delta_) noexcept;
            inline void set_num_threads(size_t num_threads_) noexcept;
            inline void set_pre_render_(bool pre_render_) noexcept;
            inline void set_post_render_(bool post_render_) noexcept;
            inline void set_output_dir(const std::string& output_dir_) noexcept;

            //  -- Additions --
            inline void add_mat(const std::string& mat_id_, const opt::Material& mat_) noexcept;
            template <typename T>
            inline void add_entity(T&& ent_) noexcept;
            template <typename T>
            inline void add_light(T&& light_) noexcept;
            template <typename T>
            inline void add_detector(T&& det_, const std::string& dir_name_) noexcept;
        };



    } // namespace torus
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/torus/sim.inl>



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_HPP
