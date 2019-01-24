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
        template <typename T>
        constexpr inline Unit<T>::Unit() noexcept
          : _mag{0.0}
        {
        }

        template <typename T>
        constexpr inline Unit<T>::Unit(const double mag_) noexcept
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
        template <typename T>
        constexpr inline double Unit<T>::mag() const noexcept
        {
            return (_mag);
        }

        constexpr inline double Unit<si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>>::mag() const noexcept
        {
            return (_mag);
        }



    } // namespace si



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <typename T>
    constexpr inline si::Unit<T> operator+(const si::Unit<T>& rhs_) noexcept
    {
        return (si::Unit<T>{+rhs_.mag()});
    }

    template <typename T>
    constexpr inline si::Unit<T> operator-(const si::Unit<T>& rhs_) noexcept
    {
        return (si::Unit<T>{-rhs_.mag()});
    }

    template <typename TL, typename TR, typename L_ADD_R>
    constexpr inline si::Unit<L_ADD_R> operator+(const si::Unit<TL>& lhs_, const si::Unit<TR>& rhs_) noexcept
    {
        return (si::Unit<L_ADD_R>{lhs_.mag() + rhs_.mag()});
    }

    template <typename TL, typename TR, typename L_SUB_R>
    constexpr inline si::Unit<L_SUB_R> operator-(const si::Unit<TL>& lhs_, const si::Unit<TR>& rhs_) noexcept
    {
        return (si::Unit<L_SUB_R>{lhs_.mag() - rhs_.mag()});
    }

    template <typename TL, typename TR, typename L_MULT_R>
    constexpr inline si::Unit<L_MULT_R> operator*(const si::Unit<TL>& lhs_, const si::Unit<TR>& rhs_) noexcept
    {
        return (si::Unit<L_MULT_R>{lhs_.mag() * rhs_.mag()});
    }

    template <typename TL, typename TR, typename L_DIV_R>
    constexpr inline si::Unit<L_DIV_R> operator/(const si::Unit<TL>& lhs_, const si::Unit<TR>& rhs_) noexcept
    {
        return (si::Unit<L_DIV_R>{lhs_.mag() / rhs_.mag()});
    }



} // namespace arc
