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



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace index //! indexing namespace
    {
        namespace vertex //! vertex namespace
        {



            //  == ENUMERATIONS ==
            //  -- Vertices --
            /**
             *  Enumeration of the triangle vertices.
             *  Used for index consistency.
             *  Spatial ordering of vertices is not guaranteed.
             */
            enum vertices
            {
                ALPHA, //!< First vertex.
                BETA,  //!< Second vertex.
                GAMMA  //!< Third vertex.
            };



        } // namespace vertex
    }     // namespace index
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_INDEX_VERTEX_HPP
