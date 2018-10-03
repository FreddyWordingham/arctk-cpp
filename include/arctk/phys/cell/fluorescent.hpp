/**
 *  @file   arctk/phys/cell/fluorescent.hpp
 *  @date   27/09/2018
 *  @author Freddy Wordingham
 *
 *  Fluorescent cell physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_CELL_FLUORESCENT_HPP
#define ARCTK_PHYS_CELL_FLUORESCENT_HPP



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
             *  Fluorescent material cell class.
             */
            class Fluorescent : public Cell
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Fluorescent(const vec3& min_, const vec3& max_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a domain cell for a fluorescent material.
             *
             *  @param  min_    Minimum bound of the cell.
             *  @param  max_    Maximum bound of the cell.
             *
             *  @pre    min_.x must be less than max_.x.
             *  @pre    min_.y must be less than max_.y.
             *  @pre    min_.z must be less than max_.z.
             */
            inline Fluorescent::Fluorescent(const vec3& min_, const vec3& max_) noexcept
              : Cell(min_, max_)
            {
            }



        } // namespace cell
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_CELL_FLUORESCENT_HPP
