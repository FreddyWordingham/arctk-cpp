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
//  -- Arctk --
#include <arctk/math/vec3.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {
        class Cell;
    } // namespace dom
} // namespace arc



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
            double       _wavelength; //!< Wavelength of the photon.
            const double _energy;     //!< Energy of the packet.
            double       _time;       //!< Current photon time.
            double       _phase;      //!< Current photon phase.

            //  -- Statistical --
            double _weight; //!< Statistical weight of the photon.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Photon(const vec3& pos_, const vec3& dir_, double wavelength_, double energy_, double time_, double phase_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const vec3& pos() const noexcept;
            inline const vec3& dir() const noexcept;
            inline double      wavelength() const noexcept;
            inline double      energy() const noexcept;
            inline double      time() const noexcept;
            inline double      phase() const noexcept;
            inline double      weight() const noexcept;

            //  -- Setters --
            inline void move(double dist_, double ref_index_) noexcept;
            inline void rotate(double theta_, double phi_) noexcept;
            inline void set_dir(const vec3& dir_) noexcept;
            inline void shift_wavelength(double delta_) noexcept;
            inline void increase_phase() noexcept;
            inline void multiply_weight(double mult_) noexcept;
        };



    } // namespace phys
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/phys/photon.inl>



//  == GUARD END ==
#endif // ARCTK_PHYS_PHOTON_HPP
