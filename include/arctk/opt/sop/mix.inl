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
#include <arctk/math/compare.hpp>
#include <arctk/math/container.hpp>
#include <arctk/phys/photon.hpp>
#include <arctk/random/distribution.hpp>
#include <arctk/random/generator.hpp>
#include <arctk/search/index.hpp>



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
              : _bases(std::move(bases_))
              , _probs(probs_)
              , _cumulative_probs(init_cumulative_probs(probs_))
            {
                assert(bases_.size() >= 2);
                assert(probs_.size() >= 2);
                assert(math::compare::unity(math::container::sum(probs_)));
                assert(bases_.size() == probs_.size());
            }


            //  -- Initialisation --
            inline std::vector<double> Mix::init_cumulative_probs(const std::vector<double>& probs_) const noexcept
            {
                assert(probs_.size() >= 2);
                assert(math::compare::unity(math::container::sum(probs_)));

                std::vector<double> cumulative_probs(probs_.size() + 1);

                cumulative_probs[0] = 0.0;
                for (size_t i = 0; i < probs_.size(); ++i)
                {
                    cumulative_probs[i + 1] = cumulative_probs[i] + probs_[i];
                }

                assert(math::compare::unity(cumulative_probs.back()));

                return (cumulative_probs);
            }



            //  == METHODS ==
            //  -- Getters --
            inline double Mix::interact_dist(random::Generator* rng_, const dom::Cell* cell_) const noexcept
            {
                assert(rng_ != nullptr);
                assert(cell_ != nullptr);

                double interact_dist = 0.0;
                for (size_t i = 0; i < _bases.size(); ++i)
                {
                    interact_dist += _bases[i]->interact_dist(rng_, cell_) * _probs[i];
                }

                return (interact_dist);
            }


            //  -- Interaction --
            inline bool Mix::interact(random::Generator* rng_, phys::Photon* phot_, dom::Cell* cell_, double dist_) const noexcept
            {
                assert(rng_ != nullptr);
                assert(cell_ != nullptr);

                return (_bases[search::index::lower(_cumulative_probs, rng_->gen())]->interact(rng_, phot_, cell_, dist_));
            }



        } // namespace sop
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_MIX_INL
