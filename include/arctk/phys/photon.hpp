/**
 *  @file   arctk/phys/photon.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Photon particle physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_PHOTON_HPP
#define ARCTK_PHYS_PHOTON_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <stack>
#include <string>

//  -- Arctk --
#include <arctk/math/vec.hpp>
#include <arctk/opt/driver.hpp>
#include <arctk/opt/material.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Photon particle class.
         */
        class Photon
        {
            //  == FIELDS ==
          private:
            //  -- Particle --
            vec3 _pos; //!< Position of the photon.
            vec3 _dir; //!< Direction of the photon.

            //  -- Properties --
            const double _power;      //!< Power of the packet.
            double       _wavelength; //!< Wavelength of the photon.
            double       _time;       //!< Current photon time.

            //  -- Statistical --
            double _weight; //!< Statistical weight of the photon.

            //  -- Material --
            std::string                  _cur_mat_id;
            std::stack<std::string>      _prev_mat_id;
            std::unique_ptr<opt::Driver> _driver;



            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Photon(const vec3& pos_, const vec3& dir_, double power_, double wavelength_, double time_, const std::string& cur_mat_id_, opt::Material* mat_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const vec3&        pos() const noexcept;
            inline const vec3&        dir() const noexcept;
            inline double             power() const noexcept;
            inline double             wavelength() const noexcept;
            inline double             time() const noexcept;
            inline double             weight() const noexcept;
            inline const std::string& cur_mat_id() const noexcept;
            inline const std::string& prev_mat_id() const noexcept;
            inline const std::string& next_mat_id(const std::string& body_mat_id_) const noexcept;

            //  -- Setters --
            inline void move(const double dist_) noexcept;
            inline void travel(const double dist_) noexcept;
            inline void set_dir(const vec3& dir_) noexcept;
            inline void rotate(const double theta_, const double phi_) noexcept;
            inline void increase_time(const double time_) noexcept;
            inline void multiply_weight(const double mult_) noexcept;

            //  -- Materials --
            inline void enter_mat(const std::string& mat_id_) noexcept;
            inline void exit_mat(const std::string& mat_id_) noexcept;
        };



    } // namespace phys
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/phys/photon.inl>



//  == GUARD END ==
#endif // ARCTK_PHYS_PHOTON_HPP
