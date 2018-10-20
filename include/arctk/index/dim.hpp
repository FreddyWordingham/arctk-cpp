/**
 *  @file   arctk/index/dim.hpp
 *  @date   20/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of dimension focused enumerations.
 */



//  == GUARD ==
#ifndef ARCTK_INDEX_DIM_HPP
#define ARCTK_INDEX_DIM_HPP



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>

//  -- Arctk --
#include <arctk/exit.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace index //! indexing namespace
    {
        namespace dim //! dimension namespace
        {



            //  == ENUMERATIONS ==
            //  -- Cartesian --
            /**
             *  Enumeration of the cartesian dimensions.
             *  Used for index consistency.
             */
            enum cartesian
            {
                X,    //!< X spatial dimension.
                Y,    //!< Y spatial dimension.
                Z,    //!< Z spatial dimension.
                TOTAL //!< Total number of cartesian spatial dimensions.
            };



            //  == FUNCTION PROTOTYPES ==
            //  -- Naming --
            inline std::string name(cartesian dim_) noexcept;



            //  == FUNCTIONS ==
            //  -- Naming --
            /**
             *  Get the name of the cartesian dimension.
             *
             *  @param  dim_    Dimension to find the name of.
             *
             *  @pre    dim_ must be less than the total number of cartesian dimensions.
             *
             *  @return String name of the cartesian dimension.
             */
            inline std::string name(const cartesian dim_) noexcept
            {
                assert(dim_ < cartesian::TOTAL);

                switch (dim_)
                {
                    case cartesian::X:
                        return ("x");
                    case cartesian::Y:
                        return ("y");
                    case cartesian::Z:
                        return ("z");
                    case cartesian::TOTAL:
                        std::cerr << "Unreachable location has been reached.\n";
                        std::exit(exit::error::UNREACHABLE_CODE);
                }
            }



        } // namespace dim
    }     // namespace index
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_INDEX_DIM_HPP
