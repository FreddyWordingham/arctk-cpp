/**
 *  @file   arctk/phys/optical.hpp
 *  @date   16/08/2018
 *  @author Freddy Wordingham
 *
 *  Optical physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_OPTICAL_HPP
#define ARCTK_PHYS_OPTICAL_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Physical particle class.
         */
        class Optical
        {
            //  == FIELDS ==
          private:
            //  -- Properties --
            const double _interact_coef{}; //!< Interaction coefficient.
            const double _asym{};          //!< Asymmetry parameter.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Optical(double interact_coef, double asym_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double interact_coef() const noexcept;
            inline double asym() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Optical::Optical(double interact_coef, double asym_) noexcept
        {
                }



        //  == METHODS ==
        //  -- Getters --
        inline double Optical::interact_coef() const noexcept
        {
            return (_interact_coef);
        }

        inline double Optical::asym() const noexcept
        {
            return (_asym);
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_OPTICAL_HPP
