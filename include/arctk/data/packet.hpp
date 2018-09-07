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
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data packet base class.
         */
        class Packet : public geom::shape::Aabb
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Packet(const vec3& min_, const vec3& max_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Packet::Packet(const vec3& min_, const vec3& max_) noexcept
        {
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_PACKET_HPP
