/**
 *  @file   arctk/opt/driver/elastic.inl
 *  @date   28/11/2018
 *  @author Freddy Wordingham
 *
 *  Elastic scattering controller class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_DRIVER_ELASTIC_INL
#define ARCTK_OPT_DRIVER_ELASTIC_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>

//  -- Arctk --
#include <arctk/opt/material/elastic.hpp>
#include <arctk/random/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {
        namespace driver //! driver namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Elastic::Elastic(const material::Elastic* mat_, const double ref_index_, const double scat_coef_, const double abs_coef_, const double asym_) noexcept
              : _mat(mat_)
              , _ref_index(ref_index_)
              , _scat_coef(scat_coef_)
              , _abs_coef(abs_coef_)
              , _asym(asym_)
              , _interaction_coef(scat_coef_ + abs_coef_)
              , _albedo(1.0 - (abs_coef_ / (scat_coef_ + abs_coef_)))
            {
                assert(mat_ != nullptr);
                assert(ref_index_ >= 1.0);
                assert(scat_coef_ > 0.0);
                assert(abs_coef_ >= 0.0);
                assert(asym_ >= -1.0);
                assert(asym_ <= 1.0);
            }



            //  == METHODS ==
            //  -- Getters --
            inline double Elastic::ref_index() const noexcept
            {
                return (_ref_index);
            }


            //  -- Interaction --
            inline bool Elastic::interact(random::Generator* rng_, phys::Photon* phot_) const noexcept
            {
                // TODO

                return (true);
            }

            inline double Elastic::calc_interaction_dist(random::Generator* rng_) const noexcept
            {
                return (-std::log(rng_->gen() / _interaction_coef));
            }



        } // namespace driver
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_DRIVER_ELASTIC_INL
