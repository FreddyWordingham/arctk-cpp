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
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



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
            const bool   _front;
            const double _dist;
            const vec3&  _norm;


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



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Collision::Collision(const bool front_, const double dist_, const vec3& norm_) noexcept
          : _front(front_)
          , _dist(dist_)
          , _norm(norm_)
        {
            PRE(dist_ > 0.0);
            PRE(norm_.normalised());
        }



        //  == METHODS ==
        //  -- Getters --
        inline bool Collision::front() const noexcept
        {
            return (_front);
        }

        inline double Collision::dist() const noexcept
        {
            return (_dist);
        }

        inline const vec3& Collision::norm() const noexcept
        {
            return (_norm);
        }



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_COLLISION_HPP
