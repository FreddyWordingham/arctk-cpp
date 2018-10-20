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



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <memory>
#include <tuple>

//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/equip/entity.hpp>
#include <arctk/phys.hpp>



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
                const arc::phys::Mat& _mat; //!< Material to emit photons into.

              private:
                //  -- Killing --
                const bool   _kill;  //!< False if photon is killed upon hit.
                const double _power; //!< Power of the light.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Light(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const arc::phys::Mat& mat_, double power_, bool kill_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double power() const noexcept;

                //  -- Emission --
                virtual std::tuple<phys::Photon, const arc::phys::Mat*, std::unique_ptr<arc::phys::Sop>> emit(random::Generator* rng_, double energy_, double time_) const
                  noexcept = 0; //!< Emit a photon in a given material with specific-optical-properties. @param  rng_    Random number generator.    @param  energy_ Initial energy of the photon.   @param  time_   Initial timestamp of the photon.    @return
                                //!< Emitted photon in a material with specific-optical-properties.

              private:
                //  -- Collision --
                inline bool hit_front(random::Generator* /*unused*/, phys::Photon* phot_, const phys::Mat** /*unused*/, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept override;
                inline bool hit_back(random::Generator* /*unused*/, phys::Photon* phot_, const phys::Mat** /*unused*/, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a light source entity which emits photons at its surface.
             *
             *  @param  serial_     Serialised wavefront file.
             *  @param  scale_      Scaling transformation.
             *  @param  rot_        Rotation transformation.
             *  @param  trans_      Translation transformation.
             *  @param  mat_        Material to emit photons into.
             *  @param  power_      Power of the light.
             *  @param  kill_       Kill photons on collision.
             *
             *  @pre    serial may not be empty.
             *  @pre    scale_.x must be positive.
             *  @pre    scale_.y must be positive.
             *  @pre    scale_.z must be positive.
             *  @pre    power_ must be positive.
             */
            inline Light::Light(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const arc::phys::Mat& mat_, const double power_, const bool kill_) noexcept
              : Entity(serial_, scale_, rot_, trans_)
              , _mat(mat_)
              , _kill(kill_)
              , _power(power_)
            {
                assert(!serial_.empty());
                assert(scale_.x > 0.0);
                assert(scale_.y > 0.0);
                assert(scale_.z > 0.0);
                assert(power_ > 0.0);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the power of the light source.
             *
             *  @return Power of the light source.
             */
            inline double Light::power() const noexcept
            {
                return (_power);
            }


            //  -- Collision --
            /**
             *  Perform a front hit event.
             *
             *  @param  phot_   Photon hitting the entity.
             *  @param  sop_    Current specific-optical-properties.
             *  @param  cell_   Current domain cell.
             *  @param  coll_   Collision event information.
             *
             *  @pre    phot_ may not be nullptr.
             *  @pre    sop_ may not be nullptr.
             *  @pre    cell_ may not be nullptr.
             *
             *  @return False if the photon should be removed from the simulation.
             */
            inline bool Light::hit_front(random::Generator* /*unused*/, phys::Photon* phot_, const phys::Mat** /*unused*/, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept
            {
                assert(phot_ != nullptr);
                assert(sop_ != nullptr);
                assert(cell_ != nullptr);

                phot_->move(coll_.dist() + consts::num::BUMP, sop_->get()->ref_index(), cell_);

                return (_kill);
            }

            /**
             *  Perform a back hit event.
             *
             *  @param  phot_   Photon hitting the entity.
             *  @param  sop_    Current specific-optical-properties.
             *  @param  cell_   Current domain cell.
             *  @param  coll_   Collision event information.
             *
             *  @pre    phot_ may not be nullptr.
             *  @pre    sop_ may not be nullptr.
             *  @pre    cell_ may not be nullptr.
             *
             *  @return False if the photon should be removed from the simulation.
             */
            inline bool Light::hit_back(random::Generator* /*unused*/, phys::Photon* phot_, const phys::Mat** /*unused*/, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept
            {
                assert(phot_ != nullptr);
                assert(sop_ != nullptr);
                assert(cell_ != nullptr);

                phot_->move(coll_.dist() + consts::num::BUMP, sop_->get()->ref_index(), cell_);

                return (_kill);
            }



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_LIGHT_HPP
