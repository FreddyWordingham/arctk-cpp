/**
 *  @file   arctk/opt/sop/simple.hpp
 *  @date   10/10/2018
 *  @author Freddy Wordingham
 *
 *  Simple specific-optical-properties control class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_SOP_SIMPLE_HPP
#define ARCTK_OPT_SOP_SIMPLE_HPP



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
             *  Simple specific-optical-proeprties control class.
             */
            class Simple : public Sop
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
                inline Simple(double ref_index_, double dist_, double albedo_, double asym_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double interact_dist(random::Generator* rng_, const dom::Cell* /*unused*/) const noexcept override;

                //  -- Interaction --
                inline bool interact(random::Generator* rng_, phys::Photon* phot_, dom::Cell* cell_, double dist_) const noexcept override;
            };



        } // namespace sop
    }     // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/sop/simple.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_SIMPLE_HPP
