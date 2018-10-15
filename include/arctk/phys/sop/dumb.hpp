/**
 *  @file   arctk/phys/sop/dumb.hpp
 *  @date   10/10/2018
 *  @author Freddy Wordingham
 *
 *  Dumb physical specific-optical-properties control class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_SOP_DUMB_HPP
#define ARCTK_PHYS_SOP_DUMB_HPP



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
    namespace phys //! physics namespace
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
                const double _dist;
                const double _albedo;
                const double _asym;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Dumb(double ref_index_, double dist_, double albedo_, double asym_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double interact_dist(random::Generator* /*unused*/, const phys::Cell& /*unused*/) const noexcept override;

                //  -- Interaction --
                inline bool interact(random::Generator* rng_, phys::Photon* phot_, const phys::Cell* /*unused*/, double dist_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Dumb::Dumb(const double ref_index_, const double dist_, const double albedo_, const double asym_) noexcept
              : Sop(ref_index_)
              , _dist(dist_)
              , _albedo(albedo_)
              , _asym(asym_)
            {
                PRE(ref_index_ >= 1.0);
                PRE(_dist > 0.0);
                PRE((albedo_ >= 0.0) || (albedo_ <= 1.0));
                PRE((asym_ >= -1.0) || (asym_ <= 1.0));
            }



            //  == METHODS ==
            //  -- Getters --
            inline double Dumb::interact_dist(random::Generator* /*unused*/, const phys::Cell& /*unused*/) const noexcept
            {
                return (_dist);
            }


            //  -- Interaction --
            inline bool Dumb::interact(random::Generator* rng_, phys::Photon* phot_, const phys::Cell* /*unused*/, const double dist_) const noexcept
            {
                phot_->move(dist_);
                phot_->rotate(random::distribution::henyey_greenstein(rng_, _asym), rng_->gen() * consts::math::TWO_PI);
                phot_->multiply_weight(_albedo);

                return (true);
            }



        } // namespace sop
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_SOP_DUMB_HPP
