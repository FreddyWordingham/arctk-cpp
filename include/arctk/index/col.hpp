/**
 *  @file   arctk/index/col.hpp
 *  @date   20/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection colour focused enumerations.
 */



//  == GUARD ==
#ifndef ARCTK_INDEX_COL_HPP
#define ARCTK_INDEX_COL_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace col //! colour namespace
    {



        //  == Enumerations ==
        //  -- Colours --
        /**
         *  Enumeration of the colour channels.
         *  Used for index consistency.
         */
        enum channels
        {
            R, //! Red colour channel.
            G, //! Green colour channel.
            B, //! Blue colour channel.
            A  //! Transparency colour channel.
        };



    } // namespace col
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_INDEX_COL_HPP
