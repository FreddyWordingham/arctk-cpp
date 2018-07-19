/**
 *  @file   arctk/index/dimension.hpp
 *  @date   20/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection dimension focused enumerations.
 */



//  == GUARD ==
#ifndef ARCTK_INDEX_DIM_HPP
#define ARCTK_INDEX_DIM_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
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
            X, //! X spatial dimension.
            Y, //! Y spatial dimension.
            Z  //! Z spatial dimension.
        };



    } // namespace dim
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_INDEX_DIM_HPP
