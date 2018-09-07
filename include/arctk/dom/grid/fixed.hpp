/**
 *  @file   arctk/dom/grid/fixed.hpp
 *  @date   07/09/2018
 *  @author Freddy Wordingham
 *
 *  Fixed domain gridding base class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_GRID_FIXED_HPP
#define ARCTK_DOM_GRID_FIXED_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/dom/cell/leaf.hpp>
#include <arctk/dom/grid.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {
        namespace grid //! gridding namespace
        {



            //  == CLASS ==
            /**
             *  Fixed domain gridding class.
             */
            class Fixed : public Grid
            {
                //  == FIELDS ==
              private:
                //  -- Cells --
                std::vector<std::vector<std::vector<cell::Leaf>>> _cells;


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



        } // namespace grid
    }     // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_GRID_FIXED_HPP
