/**
 *  @file   arctk/dom/grid.hpp
 *  @date   30/08/2018
 *  @author Freddy Wordingham
 *
 *  Domain gridding class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_GRID_HPP
#define ARCTK_DOM_GRID_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/dom/cell.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == CLASS ==
        /**
         *  Domain gridding class.
         */
        class Grid : public geom::Aabb
        {
            //  == FIELDS ==
          private:
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual inline const Cell& cell(const vec3& pos_) const noexcept = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == METHODS ==
        //  -- Getters --



    } // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_GRID_HPP
