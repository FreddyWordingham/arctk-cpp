/**
 *  @file   arctk/phys/material.hpp
 *  @date   10/08/2018
 *  @author Freddy Wordingham
 *
 *  Material physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_MATERIAL_HPP
#define ARCTK_PHYS_MATERIAL_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/phys/cell.hpp>
#include <arctk/phys/particle/photon.hpp>
#include <arctk/random.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Physical material class.
         */
        class Material
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            const double _min; //!< Minimum valid wavelength of the material.
            const double _max; //!< Maximum valid wavelength of the material.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Material(double min_, double max_) noexcept;
            inline Material(const Material&) noexcept = default; //!< Defaulted copy constructor.
            inline Material(Material&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Material() noexcept = default;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Material& operator=(const Material&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Material& operator=(Material&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double min() const noexcept;
            inline double max() const noexcept;

            //  -- Cells --
            virtual std::unique_ptr<Cell> create_cell(const vec3& min_, const vec3& max_) const noexcept = 0;

            //  -- Optical Properties --
            virtual double ref_index(double wavelength_) const noexcept                                                                  = 0;
            virtual double interact_dist(random::Generator* const rng_, const particle::Photon& phot_, const Cell& cell_) const noexcept = 0;
            virtual void   interact(random::Generator* const rng_, particle::Photon* const phot_, Cell* const cell_) const noexcept      = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a material valid for wavelengths between the given bounds.
         *
         *  @param  min_    Minimum wavelength bound of the material.
         *  @param  max_    Maximum wavelength bound of the material.
         *
         *  @pre    min_ must be less than, or equal to, max.
         */
        inline Material::Material(const double min_, const double max_) noexcept
          : _min(min_)
          , _max(max_)
        {
            PRE(min_ <= max_);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum wavelength bound of the material.
         *
         *  @return Minimum wavelength bound of the material.
         */
        inline double Material::min() const noexcept
        {
            return (_min);
        }

        /**
         *  Get the maximum wavelength bound of the material.
         *
         *  @return Maximum wavelength bound of the material.
         */
        inline double Material::max() const noexcept
        {
            return (_max);
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_HPP
