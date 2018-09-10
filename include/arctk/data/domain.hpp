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
            const std::array<size_t, 3> _res;         //!< Resolution of the domain.
            const vec3                  _packet_size; //!< Dimensions of each contained packet.

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
            inline size_t                       num_packets() const noexcept;
            inline const std::array<size_t, 3>& res() const noexcept;
            inline const vec3&                  packet_size() const noexcept;
            inline Packet const* const          packet(const size_t index_x_, const size_t index_y_, const size_t index_z_) const noexcept;

            //  -- Retrieval --
            inline Packet* packet(const vec3& pos_) noexcept;

            //  -- Saving --
            inline void save(const std::string& path_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        inline Domain::Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const T& pack_) noexcept
          : geom::shape::Aabb(min_, max_)
          , _res(res_)
          , _packet_size(init_packet_size(min_, max_, res_))
          , _packets(init_packets(res_, pack_))
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
        inline std::vector<std::vector<std::vector<std::unique_ptr<Packet>>>> Domain::init_packets(const std::array<size_t, 3>& res_, const T& pack_) const noexcept
        {
            std::vector<std::vector<std::vector<std::unique_ptr<Packet>>>> packets;
            packets.reserve(index::dim::cartesian::X);

            for (size_t i = 0; i < res_[index::dim::cartesian::X]; ++i)
            {
                packets.push_back(std::vector<std::vector<std::unique_ptr<Packet>>>());
                packets.back().reserve(res_[index::dim::cartesian::Y]);

                for (size_t j = 0; j < res_[index::dim::cartesian::Y]; ++j)
                {
                    packets.back().push_back(std::vector<std::unique_ptr<Packet>>());
                    packets.back().back().reserve(res_[index::dim::cartesian::Z]);

                    for (size_t k = 0; k < res_[index::dim::cartesian::Z]; ++k)
                    {
                        packets.back().back().emplace_back(std::make_unique<T>(pack_));
                    }
                }
            }

            return (packets);
        }



        //  == METHODS ==
        //  -- Getters --
        inline size_t Domain::num_packets() const noexcept
        {
            return (_res[index::dim::cartesian::X] * _res[index::dim::cartesian::Y] * _res[index::dim::cartesian::Z]);
        }

        inline const std::array<size_t, 3>& Domain::res() const noexcept
        {
            return (_res);
        }

        inline const vec3& Domain::packet_size() const noexcept
        {
            return (_packet_size);
        }

        inline Packet const* const Domain::packet(const size_t index_x_, const size_t index_y_, const size_t index_z_) const noexcept
        {
            PRE(index_x_ < _res[index::dim::cartesian::X]);
            PRE(index_y_ < _res[index::dim::cartesian::Y]);
            PRE(index_z_ < _res[index::dim::cartesian::Z]);

            return (_packets[index_x_][index_y_][index_z_].get());
        }


        //  -- Retrieval --
        inline Packet* Domain::packet(const vec3& pos_) noexcept
        {
            const vec3   rel_pos = pos_ - _min;
            const size_t x_index = static_cast<size_t>(rel_pos.x / _packet_size.x);
            const size_t y_index = static_cast<size_t>(rel_pos.y / _packet_size.y);
            const size_t z_index = static_cast<size_t>(rel_pos.z / _packet_size.z);

            return (_packets[x_index][y_index][z_index].get());
        }


        //  -- Saving --
        inline void Domain::save(const std::string& path_) const noexcept
        {
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_DOMAIN_HPP
