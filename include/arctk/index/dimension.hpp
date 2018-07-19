/**
 *  @file   arctk/index/dimension.hpp
 *  @date   20/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection dimension focused enumerations.
 */



//  == GUARD ==
#ifndef ARCTK_INDEX_DIMENSION_HPP
#define ARCTK_INDEX_DIMENSION_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical user interface namespace
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



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_INDEX_DIMENSION_HPP
