/**
 *  @file   arctk/geom/collision.hpp
 *  @date   06/06/2018
 *  @author Freddy Wordingham
 *
 *  Collision information class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_COLLISION_HPP
#define ARCTK_GEOM_COLLISION_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <limits>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == CLASS ==
        /**
         *  Stores information about a collision event.
         */
        class Collision
        {
            //  == FIELDS ==
          public:
            //  -- Properties --
            const bool   hit;  //!< True if there was a collision.
            const double dist; //!< Distance to the collision. NaN if hit is false.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Collision(bool hit_) noexcept;
            inline explicit Collision(double dist_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a collision event object for a miss.
         *  This constructor should only be called when a collision did not occur.
         *
         *  @param  hit_    Hit status. Should be false.
         *
         *  @pre    hit_ must be false.
         */
        inline Collision::Collision(const bool hit_) noexcept
          : hit(hit_)
          , dist(std::numeric_limits<double>::signaling_NaN())
        {
            assert(!hit_);
        }

        /**
         *  Construct a collision event object for a hit.
         *  This constructor should only be called when a collision did occur.
         *
         *  @param  dist_   Distance to the collision.
         *
         *  @pre    dist_ must be non-negative.
         */
        inline Collision::Collision(const double dist_) noexcept
          : hit(true)
          , dist(dist_)
        {
            assert(dist_ >= 0.0);
        }



    } // namespace geom
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_GEOM_COLLISION_HPP
