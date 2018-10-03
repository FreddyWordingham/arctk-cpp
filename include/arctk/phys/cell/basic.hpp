/**
 *  @file   arctk/phys/cell/basic.hpp
 *  @date   27/09/2018
 *  @author Freddy Wordingham
 *
 *  Basic cell physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_CELL_BASIC_HPP
#define ARCTK_PHYS_CELL_BASIC_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/phys/cell.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        namespace cell //! cell namespace
        {



            //  == CLASS ==
            /**
             *  Basic material cell class.
             */
            class Basic : public Cell
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Basic(const vec3& min_, const vec3& max_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a domain cell for a basic material.
             *
             *  @param  min_    Minimum bound of the cell.
             *  @param  max_    Maximum bound of the cell.
             *
             *  @pre    min_.x must be less than max_.x.
             *  @pre    min_.y must be less than max_.y.
             *  @pre    min_.z must be less than max_.z.
             */
            inline Basic::Basic(const vec3& min_, const vec3& max_) noexcept
              : Cell(min_, max_)
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);
            }



        } // namespace cell
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_CELL_BASIC_HPP
