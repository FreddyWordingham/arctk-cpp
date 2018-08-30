/**
 *  @file   arctk/dom/cell.hpp
 *  @date   30/08/2018
 *  @author Freddy Wordingham
 *
 *  Domain cell class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_CELL_HPP
#define ARCTK_DOM_CELL_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/geom.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == CLASS ==
        /**
         *  Domain cell class.
         */
        class Cell : public geom::Aabb
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            double _energy; //!< Energy of the cell (J).


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Cell(const vec3& min_, const vec3& max_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Cell::Cell(const vec3& min_, const vec3& max_) noexcept
          : Aabb(min_, max_)
          , _energy(0.0)
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
#endif // ARCTK_DOM_CELL_HPP
