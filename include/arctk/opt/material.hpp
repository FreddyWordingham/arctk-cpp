/**
 *  @file   arctk/opt/material.hpp
 *  @date   28/11/2018
 *  @author Freddy Wordingham
 *
 *  Optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MATERIAL_HPP
#define ARCTK_OPT_MATERIAL_HPP



//  == IMPORTS ==
//  -- Std --
#include <map>
#include <memory>
#include <string>

//  -- Arctk --
#include <arctk/math/vec.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        class Photon;
    } // namespace phys
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {



        //  == CLASS ==
        /**
         *  Optical material class.
         */
        class Material
        {
            //  == FIELDS ==
          protected:
            //  -- Bounds --
            const double _min; //!< Minimum valid wavelength of the material.
            const double _max; //!< Maximum valid wavelength of the material.

            //  -- Properties --
            double                        _energy;
            double                        _scattering;
            double                        _absorption;
            double                        _emission;
            vec3                          _travel_dir;
            std::map<std::string, double> _data;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Material(double min_, double max_) noexcept;
            inline Material(const Material&) noexcept = default; //!< Defaulted copy constructor.
            inline Material(Material&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Material() noexcept;

            //  -- Cloning --
            virtual std::unique_ptr<Material> clone() const = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Material& operator=(const Material&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Material& operator=(Material&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double      min() const noexcept;
            inline double      max() const noexcept;
            inline double      energy() const noexcept;
            inline double      scattering() const noexcept;
            inline double      absorption() const noexcept;
            inline double      emission() const noexcept;
            inline const vec3& travel_dir() const noexcept;

            //  -- Setters --
            inline void add_energy(double energy_) noexcept;
            inline void add_scattering(double scattering_) noexcept;
            inline void add_absorption(double absorption_) noexcept;
            inline void add_emission(double emission_) noexcept;
            inline void add_travel_dir(const vec3& travel_dir_) noexcept;

            //  -- Driver --
            virtual std::unique_ptr<Driver> driver(const phys::Photon& phot_) noexcept = 0;

            //  -- Evolve --
            virtual void evolve(double time_) noexcept = 0;
        };



    } // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/material.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_HPP
