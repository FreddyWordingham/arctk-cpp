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



        } // namespace dim
    }     // namespace index
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_INDEX_DIM_HPP
