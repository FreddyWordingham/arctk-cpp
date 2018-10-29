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



//  == BASE ==
#include <arctk/opt/mat.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>

//  -- Arctk --
#include <arctk/opt/sop.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        class Photon;
    }              // namespace random
    namespace phys //! physics namespace
    {
        class Photon;
    } // namespace phys
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
                inline double interact_dist(random::Generator* /*unused*/, const dom::Cell* /*unused*/) const noexcept override;

                //  -- Interaction --
                inline bool interact(random::Generator* rng_, phys::Photon* phot_, dom::Cell* cell_, double dist_) const noexcept override;
            };



        } // namespace sop
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_DUMB_HPP
