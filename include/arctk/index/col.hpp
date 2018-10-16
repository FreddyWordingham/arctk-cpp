/**
 *  @file   arctk/index/col.hpp
 *  @date   20/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of colour focused enumerations.
 */



//  == GUARD ==
#ifndef ARCTK_INDEX_COL_HPP
#define ARCTK_INDEX_COL_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace index //! indexing namespace
    {
        namespace col //! colour namespace
        {



            //  == ENUMERATIONS ==
            //  -- Colours --
            /**
             *  Enumeration of the colour channels.
             *  Used for index consistency.
             */
            enum channels
            {
                R, //!< Red colour channel.
                G, //!< Green colour channel.
                B, //!< Blue colour channel.
                A  //!< Transparency colour channel.
            };



        } // namespace col
    }     // namespace index
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_INDEX_COL_HPP
