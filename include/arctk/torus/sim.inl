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
        DEFAULT_RESOLUTION
        DEFAULT_MAX_DEPTH
        DEFAULT_TAR_TRIS
        DEFAULT_ROULETTE_STATUS
        DEFAULT_ROULETTE_LIMIT
        DEFAULT_ROULETTE_CHANCE
        DEFAULT_UPDATE_DELTA
        DEFAULT_NUM_THREADS
        DEFAULT_PRE_RENDER
        DEFAULT_POST_RENDER
        DEFAULT_OUTPUT_DIR



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



    } // namespace torus
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_INL
