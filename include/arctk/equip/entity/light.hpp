/**
 *  @file   arctk/equip/entity/light.hpp
 *  @date   14/10/2018
 *  @author Freddy Wordingham
 *
 *  Light source entity equipment base class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_LIGHT_HPP
#define ARCTK_EQUIP_ENTITY_LIGHT_HPP



//  == BASE ==
#include <arctk/equip/entity.hpp>



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
    namespace dom //! domain namespace
    {
        class Cell;
    }              // namespace dom
    namespace geom //! geometric namespace
    {
        class Collision;
    }              // namespace geom
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



            //  == CLASS ==
            /**
             *  Light entity equipment base class.
             */
            class Light : public Entity
            {
                //  == FIELDS ==
              protected:
                //  -- Material --
                const opt::Mat& _mat; //!< Material to emit photons into.

              private:
                //  -- Killing --
                const bool   _kill;  //!< False if photon is killed upon hit.
                const double _power; //!< Power of the light.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Light(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const opt::Mat& mat_, double power_, bool kill_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double power() const noexcept;

                //  -- Emission --
                virtual std::tuple<phys::Photon, const opt::Mat*, std::unique_ptr<opt::Sop>> emit(random::Generator* rng_, double energy_, double time_) const
                  noexcept = 0; //!< Emit a photon in a given material with specific-optical-properties. @param  rng_    Random number generator.    @param  energy_ Initial energy of the photon.   @param  time_   Initial timestamp of the photon.    @return
                                //!< Emitted photon in a material with specific-optical-properties.

              private:
                //  -- Collision --
                inline bool hit_front(random::Generator* /*unused*/, phys::Photon* phot_, const opt::Mat** /*unused*/, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept override;
                inline bool hit_back(random::Generator* /*unused*/, phys::Photon* phot_, const opt::Mat** /*unused*/, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept override;
            };



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity/light.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_LIGHT_HPP
