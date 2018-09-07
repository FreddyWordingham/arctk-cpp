/**
 *  @file   arctk/data/packet.hpp
 *  @date   07/09/2018
 *  @author Freddy Wordingham
 *
 *  Data packet base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_PACKET_HPP
#define ARCTK_DATA_PACKET_HPP



//  == INCLUDES ==
//  -- Arctk --
#include <arctk/geom.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data packet base class.
         */
        class Packet : geom::shape::Aabb
        {
        };



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_PACKET_HPP
