/**
 *  @file   arctk/dom/grid.hpp
 *  @date   07/09/2018
 *  @author Freddy Wordingham
 *
 *  Domain gridding base class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_GRID_HPP
#define ARCTK_DOM_GRID_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/geom.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == CLASS ==
        /**
         *  Domain gridding class.
         */
        class Grid
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            const geom::shape::Aabb _box; //!< Bounds of the grid.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Grid(const vec3& min_, const vec3& max_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Grid::Grid(const vec3& min_, const vec3& max_) noexcept
          : _box(min_, max_)
        {
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_GRID_HPP
