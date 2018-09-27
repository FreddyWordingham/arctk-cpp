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
             *  Basic material class.
             */
            class Basic : public Cell
            {
                //  == FIELDS ==
              private:
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Basic(const vec3& min_, const vec3& max_) noexcept;


                //  == METHODS ==
              public:
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Basic::Basic(const vec3& min_, const vec3& max_) noexcept
              : Cell(min_, max_)
            {
            }



            //  == METHODS ==



        } // namespace cell
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_CELL_BASIC_HPP
