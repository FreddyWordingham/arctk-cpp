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
#include <string>

//  -- Arctk --
#include <arctk/debug.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace index //! indexing namespace
    {
        namespace dim //! dimension namespace
        {



            //  == Enumerations ==
            //  -- Cartesian --
            /**
             *  Enumeration of the cartesian dimensions.
             *  Used for index consistency.
             */
            enum cartesian
            {
                X,    //! X spatial dimension.
                Y,    //! Y spatial dimension.
                Z,    //! Z spatial dimension.
                TOTAL //!< Total number of cartesian spatial dimensions.
            };



            //  == FUNCTION PROTOTYPES ==
            //  -- Naming --
            inline std::string name(const size_t dim_) noexcept;



            //  == FUNCTIONS ==
            //  -- Naming --
            inline std::string name(const size_t dim_) noexcept
            {
                PRE(dim_ < cartesian::TOTAL);

                switch (dim_)
                {
                    case cartesian::X:
                        return ("x");
                    case cartesian::Y:
                        return ("y");
                    case cartesian::Z:
                        return ("z");
                }
            }



        } // namespace dim
    }     // namespace index
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_INDEX_DIM_HPP
