/**
 *  @file   arctk/opt/driver/elastic.hpp
 *  @date   28/11/2018
 *  @author Freddy Wordingham
 *
 *  Elastic scattering controller class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_DRIVER_ELASTIC_HPP
#define ARCTK_OPT_DRIVER_ELASTIC_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/opt/material/elastic.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
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
        namespace driver //! driver namespace
        {



            //  == CLASS ==
            /**
             *  Elastic scattering controller class.
             */
            class Elastic
            {
                //  == FIELDS ==
              private:
                //  -- Material --
                const material::Elastic* _mat;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
                //     //  -- Getters --
                //     virtual double ref_index() const noexcept = 0;

                //     //  -- Interaction --
                //     virtual bool interact(random::Generator* rng_, phys::Photon* phot_) const noexcept = 0;

                //   private:
                //     virtual double calc_interact_dist(random::Generator* rng_) const noexcept = 0;
            };



        } // namespace driver
    }     // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/driver/elastic.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_DRIVER_ELASTIC_HPP
