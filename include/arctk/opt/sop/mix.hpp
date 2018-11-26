/**
 *  @file   arctk/opt/sop/mix.hpp
 *  @date   26/11/2018
 *  @author Freddy Wordingham
 *
 *  Mixture specific-optical-properties control class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_SOP_MIX_HPP
#define ARCTK_OPT_SOP_MIX_HPP



//  == BASE ==
#include <arctk/opt/sop.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <vector>



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
             *  Mixture specific-optical-proeprties control class.
             */
            class Mix : public Sop
            {
                //  == FIELDS ==
              private:
                //  -- Bases --
                const std::vector<std::unique_ptr<Sop>> _bases;

                //  -- Proberbilities --
                const std::vector<double> _probs;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Mix(const std::vector<std::unique_ptr<Sop>>& bases_, const std::vector<double>& probs_) noexcept;


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
#include <arctk/opt/sop/mix.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_MIX_HPP
