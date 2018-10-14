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
#include <utility>

//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/debug.hpp>
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
              private:
                //  -- Material --
                const arc::phys::Mat* _mat;

                //  -- Killing --
                const bool   _kill;
                const double _power;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Light(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const arc::phys::Mat* mat_, double power_, bool kill_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double power() const noexcept;

                //  -- Emission --
                virtual std::pair<phys::Photon, std::unique_ptr<arc::phys::Sop>> emit(random::Generator* rng_, double energy_) const noexcept = 0;

              private:
                //  -- Collision --
                inline bool hit_front(random::Generator* /*unused*/, phys::Photon* phot_, phys::Cell* /*unused*/, const geom::Collision& coll_) noexcept override;
                inline bool hit_back(random::Generator* /*unused*/, phys::Photon* phot_, phys::Cell* /*unused*/, const geom::Collision& coll_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Light::Light(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const arc::phys::Mat* mat_, const double power_, const bool kill_) noexcept
              : Entity(serial_, scale_, rot_, trans_)
              , _mat(mat_)
              , _kill(kill_)
              , _power(power_)
            {
                PRE(mat_ != nullptr);
                PRE(power_ > 0.0);
            }



            //  == METHODS ==
            //  -- Getters --
            inline double Light::power() const noexcept
            {
                return (_power);
            }


            //  -- Collision --
            inline bool Light::hit_front(random::Generator* /*unused*/, phys::Photon* phot_, phys::Cell* /*unused*/, const geom::Collision& coll_) noexcept
            {
                phot_->move(coll_.dist() + consts::num::BUMP);

                return (_kill);
            }

            inline bool Light::hit_back(random::Generator* /*unused*/, phys::Photon* phot_, phys::Cell* /*unused*/, const geom::Collision& coll_) noexcept
            {
                phot_->move(coll_.dist() + consts::num::BUMP);

                return (_kill);
            }



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_LIGHT_HPP
