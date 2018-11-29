/**
 *  @file   arctk/opt/driver.inl
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Optical controller class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_DRIVER_INL
#define ARCTK_OPT_DRIVER_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/opt/material.hpp>
#include <arctk/phys/photon.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Driver::Driver(const Material* base_mat_) noexcept
          : _base_mat(base_mat_)
          , _path_length(0.0)
        {
            assert(base_mat_ != nullptr);
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Driver::~Driver() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        inline double Driver::interaction_dist(random::Generator* rng_) noexcept
        {
            _path_length = calc_interaction_dist(rng_);

            return (_path_length);
        }

        inline bool Driver::interact(random::Generator* rng_, phys::Photon* phot_) noexcept
        {
            assert(rng_ != nullptr);
            assert(phot_ != nullptr);

            phot_->move(_path_length, ref_index());
            _base_mat->record_travel(phot_, _path_length, ref_index());

            return (perform_interaction(rng_, phot_));
        }



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_DRIVER_INL
