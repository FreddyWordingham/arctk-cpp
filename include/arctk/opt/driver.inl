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
        //  -- Constructors --
        inline Driver::Driver() noexcept
          : _path_length(0.0)
        {
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



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_DRIVER_INL
