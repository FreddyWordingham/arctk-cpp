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
#include <arctk/data/packet.hpp>
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
            std::vector<std::vector<std::vector<std::unique_ptr<Packet>>>> _packets;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            template <typename T>
            inline Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const T& pack_) noexcept;

          private:
            //  -- Initialisation --
            inline vec3 init_packet_size(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) const noexcept;
            template <typename T>
            inline std::vector<std::vector<std::vector<std::unique_ptr<Packet>>>> init_packets(const std::array<size_t, 3>& res_, const T& pack_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline size_t      num_packets() const noexcept;
            inline const vec3& packet_size() const noexcept;
            inline Packet*     packet(const vec3& pos_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        inline Domain::Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const T& pack_) noexcept
          : geom::shape::Aabb(min_, max_)
          , _packet_size(init_packet_size(min_, max_, res_))
          , _packets(init_packets<T>(res_), const T& pack_))
        {
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);
        }


        //  -- Initialisation --
        inline vec3 Domain::init_packet_size(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) const noexcept
        {
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);

            vec3 packet_size = max_ - min_;

            packet_size.x /= static_cast<double>(res_[index::dim::cartesian::X]);
            packet_size.y /= static_cast<double>(res_[index::dim::cartesian::Y]);
            packet_size.z /= static_cast<double>(res_[index::dim::cartesian::Z]);

            return (packet_size);
        }

        template <typename T>
        inline std::vector<std::vector<std::vector<std::unique_ptr<Packet>>>> Domain::init_packets(const std::array<size_t, 3>& res_, const T& pack_)) const noexcept
        {
            std::vector<std::vector<std::vector<std::unique_ptr<Packet>>>> packets;
            packets.reserve(index::dim::cartesian::X);

            for (size_t i = 0; i < res_[index::dim::cartesian::X]; ++i)
            {
                std::vector<std::vector<std::unique_ptr<Packet>>> slice;
                slice.reserve(res_[index::dim::cartesian::Y]);

                for (size_t j = 0; j < res_[index::dim::cartesian::Y]; ++j)
                {
                    std::vector<std::unique_ptr<Packet>> line;
                    line.reserve(res_[index::dim::cartesian::Z]);

                    for (size_t k = 0; k < res_[index::dim::cartesian::Z]; ++k)
                    {
                        line.emplace_back(std::make_unique<T>(pack_));
                    }

                    slice.emplace_back(line);
                }

                packets.emplace_back(slice);
            }

            return (packets);
        }



        //  == METHODS ==
        //  -- Getters --
        inline size_t Domain::num_packets() const noexcept
        {
            return (_packets.size() * _packets.front().size() * _packets.front().front().size());
        }

        inline const vec3& Domain::packet_size() const noexcept
        {
            return (_packet_size);
        }

        inline Packet* Domain::packet(const vec3& pos_) const noexcept
        {
            const vec3   rel_pos = pos_ - _min;
            const size_t x_index = static_cast<size_t>(rel_pos.x / _packet_size.x);
            const size_t y_index = static_cast<size_t>(rel_pos.y / _packet_size.y);
            const size_t z_index = static_cast<size_t>(rel_pos.z / _packet_size.z);

            return (_packets[x_index][y_index][z_index].get());
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_DOMAIN_HPP
