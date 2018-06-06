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



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == CLASS ==
        /**
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
            inline explicit Collision(double dist_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline explicit Collision::Collision(const double dist_) noexcept
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
