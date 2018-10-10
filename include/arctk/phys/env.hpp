/**
 *  @file   arctk/phys/env.hpp
 *  @date   10/10/2018
 *  @author Freddy Wordingham
 *
 *  Physical environment control class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_ENV_HPP
#define ARCTK_PHYS_ENV_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/phys/cell.hpp>
#include <arctk/phys/photon.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Photon environment control class.
         */
        class Env
        {
            //  == FIELDS ==
          private:
            //  -- Data --


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
            //  -- Getters --

            //  -- Interaction --
            virtual bool interact(random::Generator* rng_, phys::Photon* phot_, phys::Cell* cell_, const double dist_) const noexcept = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_ENV_HPP
