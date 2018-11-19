/**
 *  @file   arctk/torus/sim.hpp
 *  @date   07/11/2018
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
#include <optional>
#include <string>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/geom/collision.hpp>
#include <arctk/math/vec3.hpp>
#include <arctk/type/collision.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {
        class Region;
    }               // namespace dom
    namespace equip //! equipment namespace
    {
        class Entity;
        namespace entity //! entity namespace
        {
            class Detector;
            class Light;
        }         // namespace entity
    }             // namespace equip
    namespace gui //! graphical-user-interface namespace
    {
        class Point;
    }              // namespace gui
    namespace tree //! tree namespace
    {
        class Root;
    } // namespace tree
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace torus //! transport of radiation under skin namespace
    {



        //  == SETTINGS ==
        //  -- Filenames --
        constexpr const char* const INFO_FILENAME = "info.txt"; //!< Name of produced information file.



        //  == CLASS ==
        /**
         *  Radiative transfer simulation class.
         */
        class Sim
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            const vec3 _min; //!< Minimum bound of the domain.
            const vec3 _max; //!< Maximum bound of the domain.

            //  -- Parallelisation --
            unsigned int _update_delta; //!< Update delta (ms).
            size_t       _num_threads;  //!< Number of simulation threads.

            //  -- Output --
            std::string _output_dir; //!< Path to the output directory.

            //  -- Domain --
            std::array<size_t, 3> _res; //!< Resolution of the domain.

            //  -- Tree --
            size_t _max_depth; //!< Maximum depth of the simulation tree.
            size_t _tar_tris;  //!< Target maximum number of triangles to contain within tree leaf cells.

            //  -- Rendering --
            bool _pre_render;  //!< Pre-rendering toggle.
            bool _post_render; //!< Post-rendering toggle.

            //  -- Entities --
            std::vector<std::unique_ptr<equip::Entity>>                         _entities;  //!< Vector of entities within the simulation.
            std::vector<const equip::entity::Light*>                            _lights;    //!< Vector of light sources within the simulation.
            std::vector<std::pair<const equip::entity::Detector*, std::string>> _detectors; //!< Vector of detectors within the simulation.

            //  -- Roulette --
            bool _roulette;        //!< If true, perform roulette optimisation.
            double _roulette_limit;  //!< Weight at which to begin roulette.
            double _roulette_chance; //!< Chance of photon kill during roulette.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Sim(const vec3& min_, const vec3& max_) noexcept;


            //  == METHODS ==
          public:
            //  --  Getters --
            inline unsigned long int total_phot() const noexcept;
            inline double            total_power() const noexcept;

            //  -- Setters --
            inline void set_update_delta(unsigned int update_delta_) noexcept;
            inline void set_num_threads(size_t num_threads_) noexcept;
            inline void set_output_dir(const std::string& output_dir_) noexcept;
            inline void set_res(size_t res_) noexcept;
            inline void set_res(const std::array<size_t, 3>& res_) noexcept;
            inline void set_max_depth(size_t max_depth_) noexcept;
            inline void set_tar_tris(size_t tar_tris_) noexcept;
            inline void set_pre_render(bool pre_render_) noexcept;
            inline void set_post_render(bool post_render_) noexcept;
            inline void set_roulette(bool roulette_) noexcept;
            inline void set_roulette_limit(double roulette_limit_) noexcept;
            inline void set_roulette_chance(double roulette_chance_) noexcept;

            //  -- Additions --
            template <typename T>
            inline void add_entity(T&& ent_) noexcept;
            template <typename T>
            inline void add_light(T&& light_) noexcept;
            template <typename T>
            inline void add_detector(T&& det_, const std::string& path_) noexcept;

            //  -- Pre-flight --
          private:
            inline void create_output_dir() const noexcept;
            inline void pre_flight_info_write() const noexcept; // NOLINT

            //  -- Post-flight --
          private:
            inline void post_flight_info_write() const noexcept; // NOLINT
            inline void save_output_data() const noexcept;

            //  -- Simulate --
          public:
            inline void run() const noexcept; // NOLINT

          private:
            inline void                                 run_pre_flight() const noexcept;                                                                                                                                                          // NOLINT
            inline void                                 run_post_flight() const noexcept;                                                                                                                                                         // NOLINT
            inline void                                 simulate() const noexcept;                                                                                                                                                                // NOLINT
            inline std::vector<std::vector<gui::Point>> simulate_thread(size_t thread_index_, unsigned long int num_phot_, std::vector<unsigned long int>* thread_phot_, size_t light_index_, dom::Region* dom_, const tree::Root& tree_) const   // NOLINT
              noexcept;                                                                                                                                                                                                                           // NOLINT
            inline type::collision collide(double inter_, const std::optional<std::pair<equip::Entity*, geom::Collision>>& ent_, const std::optional<double>& leaf_, const std::optional<double>& cell_, const std::optional<double>& dom_) const // NOLINT
              noexcept;                                                                                                                                                                                                                           // NOLINT
            inline void report(unsigned long int num_phot_, std::vector<unsigned long int>* thread_phot_, size_t light_index_) const noexcept;

            //  -- Rendering --
          private:
            inline void render(const dom::Region& dom_, const tree::Root& tree_, const std::vector<std::vector<std::vector<gui::Point>>>& paths_ = {}) const noexcept; // NOLINT
        };



    } // namespace torus
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/torus/sim.inl>



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_HPP
