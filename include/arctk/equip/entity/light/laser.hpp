/**
 *  @file   arctk/equip/entity/light/laser.hpp
 *  @date   14/10/2018
 *  @author Freddy Wordingham
 *
 *  Laser light source entity class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_LIGHT_LASER_HPP
#define ARCTK_EQUIP_ENTITY_LIGHT_LASER_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <tuple>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/equip/entity/light.hpp>
#include <arctk/phys.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace entity //! entity namespace
        {
            namespace light //! light source namespace
            {



                //  == CLASS ==
                /**
                 *  Laser light entity equipment class.
                 */
                class Laser : public Light
                {
                    //  == FIELDS ==
                  private:
                    //  -- Emission --
                    const double _wavelength;


                    //  == INSTANTIATION ==
                  public:
                    //  -- Constructors --
                    inline Laser(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const arc::phys::Mat* mat_, double power_, bool kill_, double wavelength_) noexcept;


                    //  == METHODS ==
                  public:
                    //  -- Emission --
                    inline std::tuple<phys::Photon, const arc::phys::Mat*, std::unique_ptr<arc::phys::Sop>> emit(random::Generator* rng_, double energy_) const noexcept override;
                };



                //  == INSTANTIATION ==
                //  -- Constructors --
                inline Laser::Laser(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const arc::phys::Mat* mat_, const double power_, const bool kill_, const double wavelength_) noexcept
                  : Light(serial_, scale_, rot_, trans_, mat_, power_, kill_)
                  , _wavelength(wavelength_)
                {
                    PRE(mat_ != nullptr);
                    PRE(power_ > 0.0);
                    PRE(wavelength_ > 0.0);
                }



                //  == METHODS ==
                //  -- Emission --
                inline std::tuple<phys::Photon, const arc::phys::Mat*, std::unique_ptr<arc::phys::Sop>> Laser::emit(random::Generator* rng_, const double energy_) const noexcept
                {
                    PRE(energy_ > 0.0);

                    const std::pair<arc::vec3, arc::vec3> pos_norm = random_pos_and_norm(rng_);

                    phys::Photon phot(pos_norm.first, pos_norm.second, _wavelength, energy_);

                    return (std::tuple<phys::Photon, const arc::phys::Mat*, std::unique_ptr<arc::phys::Sop>>(phot, &_mat, _mat.gen(phot)));
                }



            } // namespace light
        }     // namespace entity
    }         // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_LIGHT_LASER_HPP
