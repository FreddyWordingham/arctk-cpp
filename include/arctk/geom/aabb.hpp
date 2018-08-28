/**
 *  @file   arctk/geom/aabb.hpp
 *  @date   29/08/2018
 *  @author Freddy Wordingham
 *
 *  Geometric axis-aligned bounding box class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_AABB_HPP
#define ARCTK_GEOM_AABB_HPP



//  == IMPORTS ==
//  -- Std --

//  -- Arctk --


//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == CLASS ==
        /**
         *  Axis-aligned bounding box.
         */
        class Aabb
        {
            //  == FIELDS ==
          private:
            //  -- Positioning --
            const vec3 _min; //!< Minimum vertex of the aabb.
            const vec3 _max; //!< Maximum vertex of the aabb.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_AABB_HPP
