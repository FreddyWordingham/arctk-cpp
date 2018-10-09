/**
 *  @file   arctk/equip/entity/mirror.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Mirror entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_MIRROR_HPP
#define ARCTK_EQUIP_ENTITY_MIRROR_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/equip/entity.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace entity //! entity namespace
        {



            //  == CLASS ==
            /**
             *  Mirror entity equipment class.
             */
            class Mirror : public Entity
            {
                //  == FIELDS ==
              private:
                //  -- Reflectance --
                const double _front_ref;
                const double _back_ref;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Mirror(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, double front_ref_, double back_ref_) noexcept;


                //  == METHODS ==
              private:
                //  -- Collision --
                inline void hit_front(random::Generator* rng_, phys::Photon* phot_, scene::Cell* cell_, const geom::Collision& coll_) noexcept override;
                inline void hit_back(random::Generator* rng_, phys::Photon* phot_, scene::Cell* cell_, const geom::Collision& coll_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Mirror::Mirror(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const double front_ref_, const double back_ref_) noexcept
              : Entity(serial_, scale_, rot_, trans_)
              , _front_ref(front_ref_)
              , _back_ref(back_ref_)
            {
                PRE((front_ref_ >= 0.0) && (front_ref_ <= 1.0));
                PRE((back_ref_ >= 0.0) && (back_ref_ <= 1.0));
            }



            //  == METHODS ==
            //  -- Collision --
            inline void Mirror::hit_front(random::Generator* rng_, phys::Photon* phot_, scene::Cell* cell_, const geom::Collision& coll_) noexcept
            {
                phot_.move(coll_.dist());
            }

            inline void Mirror::hit_back(random::Generator* rng_, phys::Photon* phot_, scene::Cell* cell_, const geom::Collision& coll_) noexcept
            {
                phot_.move(coll_.dist());
            }



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_MIRROR_HPP
