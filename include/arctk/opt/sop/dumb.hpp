/**
 *  @file   arctk/opt/sop/dumb.hpp
 *  @date   10/10/2018
 *  @author Freddy Wordingham
 *
 *  Dumb specific-optical-properties control class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_SOP_DUMB_HPP
#define ARCTK_OPT_SOP_DUMB_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/phys/cell.hpp>
#include <arctk/phys/optics.hpp>
#include <arctk/phys/photon.hpp>
#include <arctk/phys/sop.hpp>
#include <arctk/random.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {
        namespace sop //! specific-optical-properties namespace
        {



            //  == CLASS ==
            /**
             *  Dumb specific-optical-proeprties control class.
             */
            class Dumb : public Sop
            {
                //  == FIELDS ==
              private:
                //  -- Optical Properties --
                const double _dist;   //!< Interaction distance.
                const double _albedo; //!< Single scattering albedo.
                const double _asym;   //!< Asymmetry factor.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Dumb(double ref_index_, double dist_, double albedo_, double asym_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double interact_dist(random::Generator* /*unused*/, const phys::Cell* /*unused*/) const noexcept override;

                //  -- Interaction --
                inline bool interact(random::Generator* rng_, phys::Photon* phot_, phys::Cell* cell_, double dist_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a dumb specific-optical-property.
             *
             *  @param  ref_index_  Refractive index.
             *  @param  dist_       Interaction distance.
             *  @param  albedo_     Single scattering albedo.
             *  @param  asym_       Asymmetry parameter.
             *
             *  @pre    ref_index_ must be greater than, or equal to, unity.
             *  @pre    dist_ must be positive.
             *  @pre    albedo_ must be positive.
             *  @pre    albedo_ must less than, or equal to, unity.
             *  @pre    asym_ must greater than, or equal to, minus one.
             *  @pre    asym_ must less than, or equal to, unity.
             */
            inline Dumb::Dumb(const double ref_index_, const double dist_, const double albedo_, const double asym_) noexcept
              : Sop(ref_index_)
              , _dist(dist_)
              , _albedo(albedo_)
              , _asym(asym_)
            {
                assert(ref_index_ >= 1.0);
                assert(dist_ > 0.0);
                assert(albedo_ >= 0.0);
                assert(albedo_ <= 1.0);
                assert(asym_ >= -1.0);
                assert(asym_ <= 1.0);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the distance until the next interaction event.
             *
             *  @return Distance until the next interaction event.
             */
            inline double Dumb::interact_dist(random::Generator* /*unused*/, const phys::Cell* /*unused*/) const noexcept
            {
                return (_dist);
            }


            //  -- Interaction --
            /**
             *  Perform an interaction event on the photon.
             *
             *  @param  rng_    Random number generator.
             *  @param  phot_   Photon to interact with.
             *  @param  cell_   Current domain cell.
             *  @param  dist_   Distance to the interaction event.
             *
             *  @return False if the photon should be removed from the loop after interacting.
             */
            inline bool Dumb::interact(random::Generator* rng_, phys::Photon* phot_, phys::Cell* cell_, const double dist_) const noexcept
            {
                cell_->add_scatter(phot_->weight());

                phot_->multiply_weight(_albedo);

                phot_->move(dist_, _ref_index, cell_);
                phot_->rotate(random::distribution::henyey_greenstein(rng_, _asym), rng_->gen() * consts::math::TWO_PI);
                phot_->multiply_weight(_albedo);

                return (true);
            }



        } // namespace sop
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_DUMB_HPP
