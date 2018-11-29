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
            inline Elastic::Elastic(material::Elastic* const mat_, const double ref_index_, const double scat_coef_, const double abs_coef_, const double asym_) noexcept
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
            inline double Elastic::interaction_dist(random::Generator* const rng_) const noexcept
            {
                assert(rng_ != nullptr);

                _path_length = -std::log(rng_->gen() / _interaction_coef);

                return (_path_length);
            }

            inline bool Elastic::interact(random::Generator* const rng_, phys::Photon* const phot_) const noexcept
            {
                assert(rng_ != nullptr);
                assert(phot_ != nullptr);

                return (true);
            }



        } // namespace driver
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_DRIVER_ELASTIC_INL
