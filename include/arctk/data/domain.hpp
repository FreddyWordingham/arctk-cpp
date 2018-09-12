/**
 *  @file   arctk/data/domain.hpp
 *  @date   12/09/2018
 *  @author Freddy Wordingham
 *
 *  Data packet domain class.
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



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data packet domain class.
         */
        class Domain : public geom::shape::Aabb
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const std::array<size_t, 3>                                    _res;     //!< Resolution of the data.
            std::vector<std::vector<std::vector<std::unique_ptr<Packet>>>> _packets; //!< Stored data packets.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            template <typename T>
            inline Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const T& pack_) noexcept;
        };



        //  == INSTANTIATION ==



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_DOMAIN_HPP
