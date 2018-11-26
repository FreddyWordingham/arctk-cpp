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
            inline Mix::Mix(const std::vector<std::unique_ptr<Sop>>& bases_, const std::vector<double>& probs_) noexcept
              : Sop(init_ref_index(bases_, probs_))
              , _bases(bases_)
              , _probs(probs_)
            {
            }



            //  == METHODS ==
            //  -- Getters --


            //  -- Interaction --



        } // namespace sop
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_MIX_INL
