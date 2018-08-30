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
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == METHODS ==
        //  -- Getters --



    } // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_CELL_HPP
