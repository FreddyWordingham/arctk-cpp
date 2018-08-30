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
        class Cell
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            const vec3 _min; //!< Minimum bound of the cell.
            const vec3 _max; //!< Maximum bound of the cell.


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
