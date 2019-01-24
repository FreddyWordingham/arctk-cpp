//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include <arctk/si/unit.hpp>



//  == IMPORTS ==
//  -- Arc --



//  == NAMESPACE ==
namespace arc
{
    namespace si
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename D>
        constexpr inline Unit<D>::Unit() noexcept
          : _mag{0.0}
        {
        }

        template <typename D>
        constexpr inline Unit<D>::Unit(const double mag_) noexcept
          : _mag{mag_}
        {
        }

        constexpr inline Unit<si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>>::Unit() noexcept
          : _mag{0.0}
        {
        }

        constexpr inline Unit<si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>>::Unit(const double mag_) noexcept
          : _mag{mag_}
        {
        }



        //  == OPERATORS ==
        //  -- Conversion --
        constexpr inline Unit<si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>>::operator double() const noexcept
        {
            return (_mag);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename D>
        constexpr inline double Unit<D>::mag() const noexcept
        {
            return (_mag);
        }

        constexpr inline double Unit<si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>>::mag() const noexcept
        {
            return (_mag);
        }



    } // namespace si
} // namespace arc
