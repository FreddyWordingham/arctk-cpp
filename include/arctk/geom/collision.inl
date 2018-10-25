/**
 *  @file   arctk/geom/collision.inl
 *  @date   06/10/2018
 *  @author Freddy Wordingham
 *
 *  Geometric collision information class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_COLLISION_INL
#define ARCTK_GEOM_COLLISION_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a collision event.
         *
         *  @param  front_  True if the collision ocurred on the front of the surface.
         *  @param  dist_   Distance to the collision.
         *  @param  norm_   Normal of the surface at the point of collision.
         *
         *  @pre    dist_ must be positive.
         *  @pre    norm_ must be normalised.
         */
        inline Collision::Collision(const bool front_, const double dist_, const vec3& norm_) noexcept
          : _front(front_)
          , _dist(dist_)
          , _norm(norm_)
        {
            assert(dist_ > 0.0);
            assert(norm_.normalised());
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the front hit status of the collision.
         *
         *  @return True if the collision ocurred on the front of the surface.
         */
        inline bool Collision::front() const noexcept
        {
            return (_front);
        }

        /**
         *  Get the distance to the collision event.
         *
         *  @return Distance to the collision event.
         */
        inline double Collision::dist() const noexcept
        {
            return (_dist);
        }

        /**
         *  Get the normal of the surface at the point of collision.
         *
         *  @return Normal of the surface at the point of collision.
         */
        inline const vec3& Collision::norm() const noexcept
        {
            return (_norm);
        }



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_COLLISION_INL
