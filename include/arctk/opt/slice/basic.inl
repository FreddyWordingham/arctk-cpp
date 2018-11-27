/**
 *  @file   arctk/opt/slice/basic.inl
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Basic specific optical properties class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_SLICE_BASIC_INL
#define ARCTK_OPT_SLICE_BASIC_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {
        namespace slice //! specific optical properties namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Basic::Basic(const double ref_index_, const double scat_coef_, const double abs_coef_, const double asym_) noexcept
              : _ref_index(ref_index_)
              , _scat_coef(scat_coef_)
              , _abs_coef(abs_coef_)
              , _asym(asym_)
              , _interaction_coef(scat_coef_ + abs_coef_)
              , _albedo(abs_coef_ / (scat_coef_ + abs_coef_))
            {
                assert(ref_index_ >= 1.0);
                assert(scat_coef_ > 0.0);
                assert(abs_coef_ > 0.0);
                assert(asym_ >= -1.0);
                assert(asym_ <= 1.0);

                assert(_interaction_coef >= 0.0);
                assert(_albedo >= 0.0);
                assert(_albedo <= 1.0);
            }



            //  == METHODS ==
            //  -- Getters --



        } // namespace slice
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_SLICE_BASIC_INL
