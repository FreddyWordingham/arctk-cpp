/**
 *  @file   arctk/geom/collision.hpp
 *  @date   06/10/2018
 *  @author Freddy Wordingham
 *
 *  Geometric collision information class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_COLLISION_HPP
#define ARCTK_GEOM_COLLISION_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/math/vec.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == CLASS ==
        /**
         *  Collision information.
         */
        class Collision
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            bool   _front; //!< True if the collision ocurres on the front of the surface.
            double _dist;  //!< Distance to the collision event.
            vec3   _norm;  //!< Normal of the surface at the point of collision.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Collision(bool front_, double dist_, const vec3& norm_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline bool        front() const noexcept;
            inline double      dist() const noexcept;
            inline const vec3& norm() const noexcept;
        };



    } // namespace geom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/geom/collision.inl>



//  == GUARD END ==
#endif // ARCTK_GEOM_COLLISION_HPP
