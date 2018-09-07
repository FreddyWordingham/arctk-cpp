/**
 *  @file   arctk/dom/cell/branch.hpp
 *  @date   07/09/2018
 *  @author Freddy Wordingham
 *
 *  Domain branch cell class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_CELL_BRANCH_HPP
#define ARCTK_DOM_CELL_BRANCH_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <memory>

//  -- Arctk --
#include <arctk/dom/cell.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {
        namespace cell //! cell namespace
        {



            //  == CLASS ==
            /**
             *  Domain branch cell class.
             */
            class Branch : public Cell
            {
                //  == FIELDS ==
              private:
                //  -- Daughters --
                std::array<std::unique_ptr<Cell>, 8> _childs;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Branch(const vec3& min_, const vec3& max_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Branch::Branch(const vec3& min_, const vec3& max_) noexcept
              : Cell(min_, max_)
            {
            }



            //  == METHODS ==
            //  -- Getters --



        } // namespace cell
    }     // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_CELL_BRANCH_HPP
