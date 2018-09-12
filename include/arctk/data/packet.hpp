/**
 *  @file   arctk/data/packet.hpp
 *  @date   12/09/2018
 *  @author Freddy Wordingham
 *
 *  Data packet base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_PACKET_HPP
#define ARCTK_DATA_PACKET_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data packet base class.
         */
        class Packet
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Packet()                       = default;
            inline Packet(const Packet&) noexcept = default; //!< Defaulted copy constructor.
            inline Packet(Packet&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Packet() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Packet& operator=(const Packet&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Packet& operator=(Packet&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.
        };



        //  == INSTANTIATION ==
        //  -- Destructors --
        inline Packet::~Packet() noexcept = default;



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_PACKET_HPP
