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



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {



        //  == INSTANTIATION ==
        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Driver::~Driver() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        inline double Driver::interact_dist(random::Generator* rng_) const noexcept
        {
            _interaction_dist = calc_interaction_dist(rng_);

            return (_interaction_dist);
        }



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_DRIVER_INL
