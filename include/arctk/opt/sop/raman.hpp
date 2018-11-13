/**
 *  @file   arctk/opt/sop/raman.hpp
 *  @date   13/11/2018
 *  @author Freddy Wordingham
 *
 *  Raman specific-optical-properties control class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_SOP_RAMAN_HPP
#define ARCTK_OPT_SOP_RAMAN_HPP



//  == BASE ==
#include <arctk/opt/sop.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {
        class Cell;
    }              // namespace dom
    namespace phys //! physics namespace
    {
        class Photon;
    }                // namespace phys
    namespace random //! random number namespace
    {
        class Generator;
    } // namespace random
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {
        namespace sop //! specific-optical-properties namespace
        {



            //  == CLASS ==
            /**
             *  Raman specific-optical-proeprties control class.
             */
            class Raman : public Sop
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
                inline double interact_dist(random::Generator* /*unused*/, const dom::Cell* /*unused*/) const noexcept override;

                //  -- Interaction --
                inline bool interact(random::Generator* rng_, phys::Photon* phot_, dom::Cell* cell_, double dist_) const noexcept override;
            };



        } // namespace sop
    }     // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/sop/raman.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_RAMAN_HPP
