/**
 *  @file   arctk/opt/driver.hpp
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Optical controller class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_DRIVER_HPP
#define ARCTK_OPT_DRIVER_HPP



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {
        class Material;
    }              // namespace opt
    namespace phys //! physics namespace
    {
        class Photon;
    }                // namespace phys
    namespace random //! random number namespace
    {
        class Generator;
    } // namespace random
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {



        //  == CLASS ==
        /**
         *  Optical controller class.
         */
        class Driver
        {
            //  == FIELDS ==
          private:
            //  -- Material --
            Material* const _base_mat;

            //  -- Stored --
            double _path_length; //!< Distance to the next interaction event.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Driver(Material* const base_mat_) noexcept;
            inline Driver(const Driver&) noexcept = default; //!< Defaulted copy constructor.
            inline Driver(Driver&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Driver() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Driver& operator=(const Driver&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Driver& operator=(Driver&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual double ref_index() const noexcept = 0;

            //  -- Interaction --
            inline double interaction_dist(random::Generator* rng_) noexcept;


          private:
            virtual double calc_interaction_dist(random::Generator* rng_) const noexcept                    = 0;
            virtual bool   perform_interaction(random::Generator* rng_, phys::Photon* phot_) const noexcept = 0;
        };



    } // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/driver.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_DRIVER_HPP
