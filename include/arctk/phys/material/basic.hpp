/**
 *  @file   arctk/phys/material/basic.hpp
 *  @date   15/08/2018
 *  @author Freddy Wordingham
 *
 *  Basic material physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_MATERIAL_BASIC_HPP
#define ARCTK_PHYS_MATERIAL_BASIC_HPP



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
             *  Basic material class.
             */
            class Basic : public Material
            {
                //  == FIELDS ==
              private:
                //  -- Interaction --
                const double _dist; //!< Interaction distance.

                //  -- Scattering --
                const double _g; //!< Asymmetry scattering factor.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Basic(double dist_, double g_) noexcept;


                //  == METHODS ==
              public:
                //  -- Interaction --
                inline double interaction_dist(random::Generator* /*unused*/, const particle::Photon& /*unused*/) const noexcept override;
                inline void   interact(random::Generator* rng_, particle::Photon* phot_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a basic material with a set interaction distance and asymmetry factor.
             *
             *  @param  dist_   Interaction distance.
             *  @param  g_      Asymmetry factor.
             *
             *  @pre    dist_   Must be positive.
             *  @pre    g_      Must between minus one and plus one.
             */
            inline Basic::Basic(const double dist_, const double g_) noexcept
              : _dist(dist_)
              , _g(g_)
            {
                PRE(dist_ > 0.0);
                PRE((g_ >= -1.0) && (g_ <= 1.0));
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Determine the distance until a material interaction occurs.
             *
             *  @return Distance to interaction.
             */
            inline double Basic::interaction_dist(random::Generator* /*unused*/, const particle::Photon& /*unused*/) const noexcept
            {
                return (_dist);
            }

            /**
             *  Perform an interaction on a given photon.
             *
             *  @param  rng_    Random number generator.
             *  @param  phot_   Photon to interact with.
             */
            inline void Basic::interact(random::Generator* rng_, particle::Photon* const phot_) const noexcept
            {
                phot_->wavelength();
                phot_->rotate(random::distribution::henyey_greenstein::sample(rng_, _g), rng_->gen() * 2.0 * consts::math::PI);
            }



        } // namespace material
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_BASIC_HPP
