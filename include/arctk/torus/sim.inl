/**
 *  @file   arctk/torus/sim.inl
 *  @date   09/12/2018
 *  @author Freddy Wordingham
 *
 *  Radiative transfer simulation class.
 */



//  == GUARD ==
#ifndef ARCTK_TORUS_SIM_INL
#define ARCTK_TORUS_SIM_INL



//  == MACROS ==



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace torus //! transport of radiation under skin namespace
    {



        //  == CONSTANTS ==
        //  -- Defaults --
        constexpr const size_t       DEFAULT_RESOLUTION      = 11;
        constexpr const size_t       DEFAULT_MAX_DEPTH       = 6;
        constexpr const size_t       DEFAULT_TAR_TRIS        = 10;
        constexpr const bool         DEFAULT_ROULETTE_STATUS = false;
        constexpr const double       DEFAULT_ROULETTE_LIMIT  = 0.1;
        constexpr const double       DEFAULT_ROULETTE_CHANCE = 0.1;
        constexpr const unsigned int DEFAULT_UPDATE_DELTA    = 60000;
        constexpr const size_t       DEFAULT_NUM_THREADS     = 1;
        constexpr const bool         DEFAULT_PRE_RENDER      = false;
        constexpr const bool         DEFAULT_POST_RENDER     = false;
        constexpr const std::string  DEFAULT_OUTPUT_DIR      = "./";



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Sim::Sim(const vec3& min_, const vec3& max_) noexcept
          : _entities(0)
          , _lights(0)
          , _detectors(0)
          , _min(min_)
          , _max(max_)
          , _res({{DEFAULT_RESOLUTION, DEFAULT_RESOLUTION, DEFAULT_RESOLUTION}})
          , _max_depth(DEFAULT_MAX_DEPTH)
          , _tar_tris(DEFAULT_TAR_TRIS)
          , _roulette(DEFAULT_ROULETTE_STATUS)
          , _roulette_limit(DEFAULT_ROULETTE_LIMIT)
          , _roulette_chance(DEFAULT_ROULETTE_CHANCE)
          , _update_delta(DEFAULT_UPDATE_DELTA)
          , _num_threads(DEFAULT_NUM_THREADS)
          , _pre_render(DEFAULT_PRE_RENDER)
          , _post_render(DEFAULT_POST_RENDER)
          , _output_dir(DEFAULT_OUTPUT_DIR)
        {
            assert(min_.x < max_.x);
            assert(min_.y < max_.y);
            assert(min_.z < max_.z);
        }



        //  == METHODS ==
        //  -- Setters --
        inline void Sim::set_res(const size_t res_) noexcept
        {
            assert(res_ > 0);
            assert(res_ % 2 != 0);

            _res = std::array<size_t, 3>(res_, res_, res_);
        }

        inline void Sim::set_res(const std::array<size_t, 3>& res_) noexcept
        {
        }



    } // namespace torus
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_INL
