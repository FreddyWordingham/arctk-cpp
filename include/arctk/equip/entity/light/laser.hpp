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



//  == BASE ==
#include <arctk/equip/entity/light.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <string>
#include <tuple>

//  -- Arctk --
#include <arctk/opt/sop.hpp>
#include <arctk/phys/photon.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        template <typename T, size_t N>
        class Vec;
        using vec3 = math::Vec<double, 3>;
    }             // namespace math
    namespace opt //! optical namespace
    {
        class Mat;
    }                // namespace opt
    namespace random //! random number namespace
    {
        class Generator;
    } // namespace random
} // namespace arc



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
                    const double _wavelength; //!< Emission wavelength.


                    //  == INSTANTIATION ==
                  public:
                    //  -- Constructors --
                    inline Laser(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const opt::Mat& mat_, double power_, bool kill_, double wavelength_) noexcept;


                    //  == METHODS ==
                  public:
                    //  -- Emission --
                    inline std::tuple<phys::Photon, const opt::Mat*, std::unique_ptr<opt::Sop>> emit(random::Generator* rng_, double energy_, double time_) const noexcept override;
                };



            } // namespace light
        }     // namespace entity
    }         // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity/light/laser.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_LIGHT_LASER_HPP
