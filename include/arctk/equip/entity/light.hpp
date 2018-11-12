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
    } // namespace math
    using vec3 = math::Vec<double, 3>;
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
                //  -- Power --
                const double            _power;    //!< Power of the light.
                const unsigned long int _num_phot; //!< Number of photons for the light source to emit.

                //  -- Killing --
                const bool _kill; //!< False if photon is killed upon hit.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Light(const geom::shape::Mesh& surf_, const opt::Mat& mat_, double power_, unsigned long int num_phot_, bool kill_) noexcept;
                inline Light(const Light&) = default; //!< Defaulted copy constructor.
                inline Light(Light&&)      = default; //!< Defaulted move constructor.

                //  -- Destructors --
                inline ~Light() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Light& operator=(const Light&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Light& operator=(Light&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


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
