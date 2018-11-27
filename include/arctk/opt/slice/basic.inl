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
            inline double Basic::ref_index() const noexcept
            {
                return (_ref_index);
            }

            inline double Basic::scat_coef() const noexcept
            {
                return (_scat_coef);
            }

            inline double Basic::abs_coef() const noexcept
            {
                return (_abs_coef);
            }

            inline double Basic::interaction_coef() const noexcept
            {
                return (_interaction_coef);
            }

            inline double Basic::interaction_dist(random::Generator* rng_, const Block* block_) const noexcept
            {
                assert(rng_ != nullptr);

                return (-std::log(rng_->gen()) / _interaction_coef);
            }


            //  -- Interaction --
            inline bool Basic::interact(random::Generator* rng_, Block* block_, phys::Photon* phot_, const double dist_) const noexcept
            {
                assert(rng_ != nullptr);
                assert(phot_ != nullptr);
                assert(cell_ != nullptr);

                // TODO

                return (true)
            }



        } // namespace slice
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_SLICE_BASIC_INL
