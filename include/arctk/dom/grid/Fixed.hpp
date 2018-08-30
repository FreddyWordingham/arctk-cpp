/**
 *  @file   arctk/dom/grid/fixed.hpp
 *  @date   30/08/2018
 *  @author Freddy Wordingham
 *
 *  Fixed domain gridding class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_GRID_FIXED_HPP
#define ARCTK_DOM_GRID_FIXED_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/dom/cell.hpp>
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
                std::vector<std::vector<std::vector<cell::Leaf>>> _leaves;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const Cell& cell(const vec3& pos_) const noexcept override;
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
