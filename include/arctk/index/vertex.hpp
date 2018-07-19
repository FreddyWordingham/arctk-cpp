/**
 *  @file   arctk/index/vertex.hpp
 *  @date   20/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of vertex focused enumerations.
 */



//  == GUARD ==
#ifndef ARCTK_INDEX_VERTEX_HPP
#define ARCTK_INDEX_VERTEX_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace vertex //! vertex namespace
    {



        //  == Enumerations ==
        //  -- Vertices --
        /**
         *  Enumeration of the triangle vertices.
         *  Used for index consistency.
         *  Spatial ordering of vertices is not guaranteed.
         */
        enum vertices
        {
            ALPHA, //! First vertex.
            BETA,  //! Second vertex.
            GAMMA  //! Third vertex.
        };



    } // namespace vertex
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_INDEX_VERTEX_HPP
