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


            //  == METHODS ==
          public:
            //  -- Collision --
        };



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_COLLISION_HPP
