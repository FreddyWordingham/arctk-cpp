/**
 *  @file   arctk/equip/entity.hpp
 *  @date   17/09/2018
 *  @author Freddy Wordingham
 *
 *  Entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_HPP
#define ARCTK_EQUIP_ENTITY_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {



        //  == CLASS ==
        /**
         *  Entity class.
         */
        class Entity
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const std::string& _name;

            //  -- Structure --
            const geom::Shape& _surf;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::string& name() const noexcept;
            inline const geom::Shape& surf() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == METHODS ==
        //  -- Getters --
        inline const std::string& Entity::name() const noexcept
        {
            return (_name);
        }

        inline const geom::Shape& Entity::surf() const noexcept
        {
            return (_surf);
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_HPP
