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
#include <arctk/consts/math.hpp>
#include <arctk/consts/phys.hpp>
#include <arctk/opt/material/elastic.hpp>
#include <arctk/random/distribution.hpp>
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
            inline void Elastic::travel(phys::Photon* const phot_, const double dist_) noexcept
            {
                assert(phot_ != nullptr);
                assert(dist_ > 0.0);

                phot_._pos += phot_._dir * dist_;
                phot_._time += ((dist_ * _ref_index) / consts::phys::SPEED_OF_LIGHT);

                _mat->add_energy((phot_->power() * dist_ * _ref_index) / consts::phys::SPEED_OF_LIGHT);
                _mat->add_scattering(phot_->power() * dist_ * _ref_index * _scat_coef);
                _mat->add_absorption(phot_->power() * dist_ * _ref_index * _abs_coef);
                _mat->add_travel_dir(phot_->dir() * dist_);

                phot_->move(dist_, _ref_index);
            }

            inline double Elastic::interaction_dist(random::Generator* const rng_) noexcept
            {
                assert(rng_ != nullptr);

                return (-std::log(rng_->gen()) / _interaction_coef);
            }

            inline bool Elastic::interact(random::Generator* const rng_, phys::Photon* const phot_) noexcept
            {
                assert(rng_ != nullptr);
                assert(phot_ != nullptr);

                phot_->multiply_weight(_albedo);
                phot_->rotate(random::distribution::henyey_greenstein(rng_, _asym), rng_->gen() * consts::math::TWO_PI);

                return (true);
            }



        } // namespace driver
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_DRIVER_ELASTIC_INL
