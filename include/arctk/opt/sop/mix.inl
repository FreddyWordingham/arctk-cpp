/**
 *  @file   arctk/opt/sop/mix.inl
 *  @date   26/11/2018
 *  @author Freddy Wordingham
 *
 *  Mixture specific-optical-properties control class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_SOP_MIX_INL
#define ARCTK_OPT_SOP_MIX_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>

//  -- Arctk --
#include <arctk/consts/math.hpp>
#include <arctk/dom/cell.hpp>
#include <arctk/phys/photon.hpp>
#include <arctk/random/distribution.hpp>
#include <arctk/random/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {
        namespace sop //! specific-optical-properties namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Mix::Mix(std::vector<std::unique_ptr<Sop>>&& bases_, const std::vector<double>& probs_) noexcept
              : Sop(init_ref_index(bases_, probs_))
              , _bases(std::move(bases_))
              , _probs(probs_)
            {
                assert(bases_.size() >= 2);
                assert(probs_.size() >= 2);
                assert(bases_.size() == probs_.size());
            }


            //  -- Initialisation --
            inline double Mix::init_ref_index(const std::vector<std::unique_ptr<Sop>>& bases_, const std::vector<double>& probs_) const noexcept
            {
                assert(bases_.size() >= 2);
                assert(probs_.size() >= 2);
                assert(bases_.size() == probs_.size());

                double ref_index = 0.0;

                for (size_t i = 0; i < bases_.size(); ++i)
                {
                    ref_index += bases_[i]->ref_index() * probs_[i];
                }

                return (ref_index);
            }



            //  == METHODS ==
            //  -- Getters --
            inline double Mix::interact_dist(random::Generator* rng_, const dom::Cell* cell_) const noexcept
            {
                assert(rng_ != nullptr);
                assert(cell_ != nullptr);

                return (0.0);
            }


            //  -- Interaction --
            inline bool Mix::interact(random::Generator* rng_, phys::Photon* phot_, dom::Cell* cell_, double dist_) const noexcept
            {
                assert(rng_ != nullptr);
                assert(cell_ != nullptr);

                return (false);
            }



        } // namespace sop
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_MIX_INL
