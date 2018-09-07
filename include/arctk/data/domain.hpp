/**
 *  @file   arctk/data/domain.hpp
 *  @date   07/09/2018
 *  @author Freddy Wordingham
 *
 *  Data domain class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_DOMAIN_HPP
#define ARCTK_DATA_DOMAIN_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <vector>

//  -- Arctk --
#include <arctk/geom.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data domain class.
         */
        class Domain : public geom::shape::Aabb
        {
            //  == FIELDS ==
          protected:
            //  -- Resolution --
            const vec3 _packet_size; //!< Dimensions of each contained packet.

            //  -- Information --
            const std::vector<std::vector<std::vector<std::unique<Packet>>>> _packets;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == METHODS ==
        //  -- Getters --



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_DOMAIN_HPP
