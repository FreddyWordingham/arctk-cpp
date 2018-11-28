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



        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Driver::~Driver() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        const double Driver::scattering_coef() const noexcept
        {
            return (_scattering_coef);
        }

        const double Driver::absorption_coef() const noexcept
        {
            return (_absorption_coef);
        }

        const double Driver::emission_coef() const noexcept
        {
            return (_emission_coef);
        }

        const double Driver::interaction_coef() const noexcept
        {
            return (_interaction_coef);
        }



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_DRIVER_INL
