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
#include <type_traits>
#include <vector>

//  -- Arctk --
#include <arctk/data/cube3.hpp>
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
         *  Data packet domain class.
         */
        class Domain : public geom::shape::Aabb
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const std::array<size_t, 3>                                    _res;         //!< Resolution of the data.
            const vec3                                                     _packet_size; //!< Dimensions of each contained packet.
            std::vector<std::vector<std::vector<std::unique_ptr<Packet>>>> _packets;     //!< Stored data packets.


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
            inline Packet const*                packet(size_t index_x_, size_t index_y_, size_t index_z_) const noexcept;

            //  -- Retrieval --
            inline std::pair<Packet*, geom::shape::Aabb> packet(const vec3& pos_) noexcept;

            //  -- Saving --
            template <typename T>
            inline void save(const std::string& path_, const std::string& set_name_) const noexcept;

          private:
            //  -- Saving --
            template <typename T, typename... A>
            inline void save_helper(const std::string& path_, const std::string& set_name_, const std::tuple<A...>& /*unused*/) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a domain with given bounds, a given resolution and initial data packet data.
         *
         *  @tparam T   Type of packet stored by the domain.
         *
         *  @param  min_    Minimum bound of the domain.
         *  @param  max_    Maximum bound of the domain.
         *  @param  res_    Resolution of the domain.
         *  @param  pack_   Initial conditions of the data packets.
         *
         *  @pre    T must be derived from Packet.
         *
         *  @pre    min_.x must be less than max_.x.
         *  @pre    min_.y must be less than max_.y.
         *  @pre    min_.z must be less than max_.z.
         *  @pre    res_ balues must be positive.
         */
        template <typename T>
        inline Domain::Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const T& pack_) noexcept
          : geom::shape::Aabb(min_, max_)
          , _res(res_)
          , _packet_size(init_packet_size(min_, max_, res_))
          , _packets(init_packets(res_, pack_))
        {
            static_assert(std::is_base_of<Packet, T>::value);

            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);
        }


        //  -- Initialisation --
        /**
         *  Initialise the size of the data packets.
         *
         *  @param  min_    Minimum bound of the domain.
         *  @param  max_    Maximum bound of the domain.
         *  @param  res_    Resolution of the domain.
         *
         *  @pre    min_.x must be less than max_.x.
         *  @pre    min_.y must be less than max_.y.
         *  @pre    min_.z must be less than max_.z.
         *  @pre    res_ balues must be positive.
         *
         *  @return Size of the data packets.
         */
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

        /**
         *  Initialise the three-dimensional vector of data packets by copying a given packet and casting it to a unique pointer to a base Packet.
         *
         *  @tparam T   Type of packet stored by the domain.
         *
         *  @param  res_    Resolution of the domain.
         *  @param  pack_   Initial conditions of the data packets.
         *
         *  @pre    T must be derived from Packet.
         *
         *  @return Initialised three-dimensional vector of data packets.
         */
        template <typename T>
        inline std::vector<std::vector<std::vector<std::unique_ptr<Packet>>>> Domain::init_packets(const std::array<size_t, 3>& res_, const T& pack_) const noexcept
        {
            static_assert(std::is_base_of<Packet, T>::value);

            std::vector<std::vector<std::vector<std::unique_ptr<Packet>>>> packets;
            packets.reserve(index::dim::cartesian::X);

            for (size_t i = 0; i < res_[index::dim::cartesian::X]; ++i)
            {
                packets.emplace_back(std::vector<std::vector<std::unique_ptr<Packet>>>());
                packets.back().reserve(res_[index::dim::cartesian::Y]);

                for (size_t j = 0; j < res_[index::dim::cartesian::Y]; ++j)
                {
                    packets.back().emplace_back(std::vector<std::unique_ptr<Packet>>());
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
        /**
         *  Get the number of packets stored by the domain.
         *
         *  @return Number of packets stored by the domain.
         */
        inline size_t Domain::num_packets() const noexcept
        {
            return (_res[index::dim::cartesian::X] * _res[index::dim::cartesian::Y] * _res[index::dim::cartesian::Z]);
        }

        /**
         *  Get the resolution of the domain.
         *
         *  @return Resolution of the domain.
         */
        inline const std::array<size_t, 3>& Domain::res() const noexcept
        {
            return (_res);
        }

        /**
         *  Get the individual packet size.
         *
         *  @return Individual packet size.
         */
        inline const vec3& Domain::packet_size() const noexcept
        {
            return (_packet_size);
        }

        /**
         *  Get a raw pointer to a domain packet by its index.
         *
         *  @param  index_x_    X index of the requested packet.
         *  @param  index_y_    Y index of the requested packet.
         *  @param  index_z_    Z index of the requested packet.
         *
         *  @pre    index_x_ must be less than _res[index::dim::cartesian::X].
         *  @pre    index_y_ must be less than _res[index::dim::cartesian::Y].
         *  @pre    index_z_ must be less than _res[index::dim::cartesian::Z].
         *
         *  @return Raw pointer to the domain packet.
         */
        inline Packet const* Domain::packet(const size_t index_x_, const size_t index_y_, const size_t index_z_) const noexcept
        {
            PRE(index_x_ < _res[index::dim::cartesian::X]);
            PRE(index_y_ < _res[index::dim::cartesian::Y]);
            PRE(index_z_ < _res[index::dim::cartesian::Z]);

            return (_packets[index_x_][index_y_][index_z_].get());
        }


        //  -- Retrieval --
        /**
         *  Retrieve a raw pointer to a domain packet corresponding to a position within the domain.
         *  Also get a axis-aligned bounding box outlining the bounds of the packet's sub-domain.
         *
         *  @param  pos_    Position of the point.
         *
         *  @pre    pos_ must be contained within the domain.
         *
         *  @post   index_x must be less than _res[index::dim::cartesian::X].
         *  @post   index_y must be less than _res[index::dim::cartesian::Y].
         *  @post   index_z must be less than _res[index::dim::cartesian::Z].
         *
         *  @return Raw pointer to the domain packet and an axis-aligned bounding box of the packet's sub-domain.
         */
        inline std::pair<Packet*, geom::shape::Aabb> Domain::packet(const vec3& pos_) noexcept;
        {
            PRE(contains(pos_));

            const vec3 rel_pos = pos_ - _min;
            const auto index_x = static_cast<size_t>(rel_pos.x / _packet_size.x);
            const auto index_y = static_cast<size_t>(rel_pos.y / _packet_size.y);
            const auto index_z = static_cast<size_t>(rel_pos.z / _packet_size.z);

            const vec3 min = -min + vec3(_packet_size.x * index_x, _packet_size.y * index_y, _packet_size.z * index_z);

            POST(index_x < _res[index::dim::cartesian::X]);
            POST(index_y < _res[index::dim::cartesian::Y]);
            POST(index_z < _res[index::dim::cartesian::Z]);

            return (std::pair<Packet*, geom::shape::Aabb>(_packets[index_x][index_y][index_z].get(), geom::shape::Aabb(min, min + _packet_size)));
        }


        //  -- Saving --
        /**
         *  Save the contents of the domain as a vtk file.
         *
         *  @tparam T   Type to cast domain packets to.
         *
         *  @param  path_       Path to file location.
         *  @param  set_name_   Name of data set.
         *
         *  @pre    T must be derived from Packet.
         *
         *  @pre    path_ may not be empty.
         *  @pre    set_name_ may not be empty.
         *  @pre    set_name_ may not contain a newline character.
         *  @pre    set_name_ may not contain a space character.
         */
        template <typename T>
        inline void Domain::save(const std::string& path_, const std::string& set_name_) const noexcept
        {
            static_assert(std::is_base_of<Packet, T>::value);

            PRE(!path_.empty());
            PRE(!set_name_.empty());
            PRE(set_name_.find_first_of('\n') == std::string::npos);
            PRE(set_name_.find_first_of(' ') == std::string::npos);

            save_helper<T>(path_, set_name_, dynamic_cast<T*>(_packets.front().front().front().get())->data());
        }

        /**
         *  Save method helper method.
         *
         *  @tparam T   Type to cast domain packets to.
         *  @tparam A   Variadic list of arguments contained by return tuple of data method call.
         *
         *  @param  path_       Path to file location.
         *  @param  set_name_   Name of data set.
         *
         *  @pre    T must be derived from Packet.
         *
         *  @pre    path_ may not be empty.
         *  @pre    set_name_ may not be empty.
         *  @pre    set_name_ may not contain a newline character.
         *  @pre    set_name_ may not contain a space character.
         */
        template <typename T, typename... A>
        inline void Domain::save_helper(const std::string& path_, const std::string& set_name_, const std::tuple<A...>& /*unused*/) const noexcept
        {
            static_assert(std::is_base_of<Packet, T>::value);

            PRE(!path_.empty());
            PRE(!set_name_.empty());
            PRE(set_name_.find_first_of('\n') == std::string::npos);
            PRE(set_name_.find_first_of(' ') == std::string::npos);

            std::vector<std::vector<std::vector<std::tuple<A...>>>> data(_res[0], std::vector<std::vector<std::tuple<A...>>>(_res[1], std::vector<std::tuple<A...>>(_res[2])));
            for (size_t i = 0; i < _res[index::dim::cartesian::X]; ++i)
            {
                for (size_t j = 0; j < _res[index::dim::cartesian::Y]; ++j)
                {
                    for (size_t k = 0; k < _res[index::dim::cartesian::Z]; ++k)
                    {
                        data[i][j][k] = dynamic_cast<T*>(_packets[i][j][k].get())->data();
                    }
                }
            }

            Cube<3, A...>(data).save(path_, set_name_, dynamic_cast<T*>(_packets[0][0][0].get())->data_names(), _min, _max);
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_DOMAIN_HPP
