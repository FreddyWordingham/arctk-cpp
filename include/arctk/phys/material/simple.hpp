/**
 *  @file   arctk/phys/material/simple.hpp
 *  @date   10/08/2018
 *  @author Freddy Wordingham
 *
 *  Simple material physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_MATERIAL_SIMPLE_HPP
#define ARCTK_PHYS_MATERIAL_SIMPLE_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>
#include <arctk/random.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        namespace material //! material namespace
        {



            //  == CLASS ==
            /**
             *  Simple material class.
             */
            class Simple : public Material
            {
                //  == FIELDS ==
              private:
                //  -- Interaction --
                const double _dist;

                //  -- Scattering --
                const double _g;



                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Simple(double dist_, double g_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double interaction_dist(const particle::Photon& phot_) const noexcept override;
                inline void   interact(random::Generator* rng_, particle::Photon& phot_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Simple::Simple(const double dist_, const double g_) noexcept
              : _dist(dist_)
              , _g(g_)
            {
                PRE(dist > 0.0);
                PRE((g_ >= -1.0) && (g_ <= 1.0));
            }



            //  == METHODS ==
            //  -- Getters --
            inline double Simple::interaction_dist(const particle::Photon& /*unused*/) const noexcept
            {
                return (_dist);
            }

            inline void Simple::interact(random::Generator* rng_, particle::Photon& phot_) const noexcept
            {
                phot_.rotate(random::distribution::henyey_greenstein::sample(rng_, _g), rng_->gen() * 2.0 * consts::math::PI);
            }



        } // namespace material
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_SIMPLE_HPP
