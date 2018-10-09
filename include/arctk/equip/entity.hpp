/**
 *  @file   arctk/equip/entity.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_HPP
#define ARCTK_EQUIP_ENTITY_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {



        //  == CLASS ==
        /**
         *  Entity equipment class.
         */
        class Entity : public geom::shape::Mesh
        {
            //  == FIELDS ==
          private:
            //  -- Data --


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Entity(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Entity::Entity(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept
          : _Mesh(serial_, scale_, rot_, trans_)
        {
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_HPP
