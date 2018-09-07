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
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/index.hpp>
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
            inline Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Domain::Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) const noexcept
        {
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
            PRE(res[index::dim::cartesian::X] > 0);
            PRE(res[index::dim::cartesian::Y] > 0);
            PRE(res[index::dim::cartesian::Z] > 0);
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_DOMAIN_HPP
