//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include <arctk/si/dimension.hpp>
#include <arctk/type/arithmetic.hpp>



//  == NAMESPACE ==
namespace arc
{
    namespace si
    {



        //  == CLASSES ==
        //  -- Unit --
        template <typename T>
        class Unit
        {
            //  == FIELDS ==
          private:
            //  -- Magnitude --
            double _mag;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Unit() noexcept;
            constexpr inline explicit Unit(double mag_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --

            //  -- Increment / Decrement --
            constexpr inline Unit& operator++() noexcept;
            constexpr inline Unit& operator--() noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline double mag() const noexcept;
        };



        //  == SPECIALISATIONS ==
        //  -- Scalar --
        template <>
        class Unit<Dimension<0, 0, 0, 0, 0, 0, 0, 0>>
        {
            //  == FIELDS ==
          private:
            //  -- Magnitude --
            double _mag;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Unit() noexcept;
            constexpr inline Unit(double mag_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Conversion --
            constexpr inline operator double() const noexcept; // NOLINT

            //  -- Assignment --
            constexpr inline Unit& operator+=(const Unit& rhs_) noexcept;
            constexpr inline Unit& operator-=(const Unit& rhs_) noexcept;
            constexpr inline Unit& operator*=(const Unit& rhs_) noexcept;
            constexpr inline Unit& operator/=(const Unit& rhs_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Unit& operator++() noexcept;
            constexpr inline Unit& operator--() noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline double mag() const noexcept;
        };



        //  == ALIASES ==
        //  -- Dimensionless --
        using Scalar = Unit<Dimension<0, 0, 0, 0, 0, 0, 0, 0>>;

        //  -- Base --
        using Mass        = Unit<Dimension<1, 0, 0, 0, 0, 0, 0, 0>>;
        using Length      = Unit<Dimension<0, 1, 0, 0, 0, 0, 0, 0>>;
        using Time        = Unit<Dimension<0, 0, 1, 0, 0, 0, 0, 0>>;
        using Temperature = Unit<Dimension<0, 0, 0, 1, 0, 0, 0, 0>>;
        using Current     = Unit<Dimension<0, 0, 0, 0, 1, 0, 0, 0>>;
        using Intensity   = Unit<Dimension<0, 0, 0, 0, 0, 1, 0, 0>>;
        using Amount      = Unit<Dimension<0, 0, 0, 0, 0, 0, 1, 0>>;
        using Angle       = Unit<Dimension<0, 0, 0, 0, 0, 0, 0, 1>>;

        //  -- Derived --
        using SolidAngle                     = Unit<Dimension<0, 0, 0, 0, 0, 0, 0, 2>>;
        using Area                           = Unit<Dimension<0, 2, 0, 0, 0, 0, 0, 0>>;
        using Volume                         = Unit<Dimension<0, 3, 0, 0, 0, 0, 0, 0>>;
        using Velocity                       = Unit<Dimension<0, 1, -1, 0, 0, 0, 0, 0>>;
        using Acceleration                   = Unit<Dimension<0, 1, -2, 0, 0, 0, 0, 0>>;
        using Jerk                           = Unit<Dimension<0, 1, -3, 0, 0, 0, 0, 0>>;
        using Snap                           = Unit<Dimension<0, 1, -4, 0, 0, 0, 0, 0>>;
        using Crackle                        = Unit<Dimension<0, 1, -5, 0, 0, 0, 0, 0>>;
        using Pop                            = Unit<Dimension<0, 1, -6, 0, 0, 0, 0, 0>>;
        using Wavenumber                     = Unit<Dimension<0, -1, 0, 0, 0, 0, 0, 0>>;
        using Density                        = Unit<Dimension<1, -3, 0, 0, 0, 0, 0, 0>>;
        using SurfaceDensity                 = Unit<Dimension<1, -2, 0, 0, 0, 0, 0, 0>>;
        using SpecificVolume                 = Unit<Dimension<-1, 3, 0, 0, 0, 0, 0, 0>>;
        using CurrentDensity                 = Unit<Dimension<0, -2, 0, 0, 1, 0, 0, 0>>;
        using MagneticFieldStrength          = Unit<Dimension<0, -1, 0, 0, 1, 0, 0, 0>>;
        using Concentration                  = Unit<Dimension<0, -3, 0, 0, 0, 0, 1, 0>>;
        using Luminance                      = Unit<Dimension<0, -2, 0, 0, 0, 1, 0, 0>>;
        using Illuminance                    = Unit<Dimension<0, -2, 0, 0, 0, 1, 0, 0>>;
        using Frequency                      = Unit<Dimension<0, 0, -1, 0, 0, 0, 0, 0>>;
        using Force                          = Unit<Dimension<1, 1, -2, 0, 0, 0, 0, 0>>;
        using Pressure                       = Unit<Dimension<1, -1, -2, 0, 0, 0, 0, 0>>;
        using Stress                         = Unit<Dimension<1, -1, -2, 0, 0, 0, 0, 0>>;
        using EnergyDensity                  = Unit<Dimension<1, -1, -2, 0, 0, 0, 0, 0>>;
        using Energy                         = Unit<Dimension<1, 2, -2, 0, 0, 0, 0, 0>>;
        using Work                           = Unit<Dimension<1, 2, -2, 0, 0, 0, 0, 0>>;
        using Heat                           = Unit<Dimension<1, 2, -2, 0, 0, 0, 0, 0>>;
        using Power                          = Unit<Dimension<1, 2, -3, 0, 0, 0, 0, 0>>;
        using RadiantFlux                    = Unit<Dimension<1, 2, -3, 0, 0, 0, 0, 0>>;
        using Charge                         = Unit<Dimension<0, 0, 1, 0, 1, 0, 0, 0>>;
        using Potential                      = Unit<Dimension<1, 2, -3, 0, -1, 0, 0, 0>>;
        using Capacitance                    = Unit<Dimension<-1, -2, 4, 0, -1, 0, 0, 0>>;
        using Resistance                     = Unit<Dimension<1, 2, -3, 0, -2, 0, 0, 0>>;
        using Conductance                    = Unit<Dimension<-1, -2, 3, 0, 2, 0, 0, 0>>;
        using MagneticFlux                   = Unit<Dimension<1, 2, -2, 0, -1, 0, 0, 0>>;
        using MagneticFluxDensity            = Unit<Dimension<1, 0, -2, 0, -1, 0, 0, 0>>;
        using Inductance                     = Unit<Dimension<1, 2, -2, 0, -2, 0, 0, 0>>;
        using LuminousFlux                   = Unit<Dimension<0, 0, 0, 0, 0, 1, 0, 2>>;
        using Activity                       = Unit<Dimension<0, 0, -1, 0, 0, 0, 0, 0>>;
        using AbsorbedDose                   = Unit<Dimension<0, 2, -2, 0, 0, 0, 0, 0>>;
        using Kerma                          = Unit<Dimension<0, 2, -2, 0, 0, 0, 0, 0>>;
        using SpecificEnergy                 = Unit<Dimension<0, 2, -2, 0, 0, 0, 0, 0>>;
        using DoseEquivalent                 = Unit<Dimension<0, 2, -2, 0, 0, 0, 0, 0>>;
        using CatalyticActivity              = Unit<Dimension<0, 0, -1, 0, 0, 0, 1, 0>>;
        using DynamicViscosity               = Unit<Dimension<1, -1, -1, 0, 0, 0, 0, 0>>;
        using KinematicViscosity             = Unit<Dimension<0, 2, -1, 0, 0, 0, 0, 0>>;
        using Moment                         = Unit<Dimension<1, 2, -2, 0, 0, 0, 0, 0>>;
        using SurfaceTension                 = Unit<Dimension<1, 0, -2, 0, 0, 0, 0, 0>>;
        using AngularVelocity                = Unit<Dimension<0, 0, -1, 0, 0, 0, 0, 1>>;
        using AngularAcceleration            = Unit<Dimension<0, 0, -2, 0, 0, 0, 0, 1>>;
        using AngularJerk                    = Unit<Dimension<0, 0, -3, 0, 0, 0, 0, 1>>;
        using AngularSnap                    = Unit<Dimension<0, 0, -4, 0, 0, 0, 0, 1>>;
        using AngularCrackle                 = Unit<Dimension<0, 0, -5, 0, 0, 0, 0, 1>>;
        using AngularPop                     = Unit<Dimension<0, 0, -6, 0, 0, 0, 0, 1>>;
        using HeatFluxDensity                = Unit<Dimension<1, 0, -3, 0, 0, 0, 0, 0>>;
        using Irradiance                     = Unit<Dimension<1, 0, -3, 0, 0, 0, 0, 0>>;
        using HeatCapacity                   = Unit<Dimension<1, 2, -2, -1, 0, 0, 0, 0>>;
        using Entropy                        = Unit<Dimension<1, 2, -2, -1, 0, 0, 0, 0>>;
        using SpecificHeatCapacity           = Unit<Dimension<0, 2, -2, -1, 0, 0, 0, 0>>;
        using SpecificEntropy                = Unit<Dimension<0, 2, -2, -1, 0, 0, 0, 0>>;
        using ThermalConductivity            = Unit<Dimension<1, 1, -3, -1, 0, 0, 0, 0>>;
        using ElectricFieldStrength          = Unit<Dimension<1, 1, -3, 0, 0, -1, 0, 0>>;
        using ElectricChargeDensity          = Unit<Dimension<0, -3, 1, 0, 0, 1, 0, 0>>;
        using SurfaceChargeDensity           = Unit<Dimension<0, -2, 1, 0, 0, 1, 0, 0>>;
        using ElectricFluxDensity            = Unit<Dimension<0, -2, 1, 0, 0, 1, 0, 0>>;
        using ElectricDisplacement           = Unit<Dimension<0, -2, 1, 0, 0, 1, 0, 0>>;
        using Permittivity                   = Unit<Dimension<-1, -3, 4, 0, 0, 2, 0, 0>>;
        using Permeability                   = Unit<Dimension<1, 1, -2, 0, 0, -2, 0, 0>>;
        using MolarEnergy                    = Unit<Dimension<1, 2, -2, 0, 0, 0, -1, 0>>;
        using MolarEntropy                   = Unit<Dimension<1, 2, -2, -1, 0, 0, -1, 0>>;
        using MolarHeatCapacity              = Unit<Dimension<1, 2, -2, -1, 0, 0, -1, 0>>;
        using Exposure                       = Unit<Dimension<-1, 0, 1, 0, 0, 1, 0, 0>>;
        using AbsorbedDoseRate               = Unit<Dimension<0, 2, -3, 0, 0, 0, 0, 0>>;
        using RadiantIntensity               = Unit<Dimension<1, 2, -3, 0, 0, 0, 0, 2>>;
        using Radiance                       = Unit<Dimension<1, 0, -3, 0, 0, 0, 0, 2>>;
        using CatalyticActivityConcentration = Unit<Dimension<0, -3, -1, 0, 0, 0, 1, 0>>;
        using Action                         = Unit<Dimension<1, 2, -1, 0, 0, 0, 0, 0>>;



    } // namespace si



    //  == OPERATORS ==
    //  -- Increment / Decrement --
    template <typename T>
    constexpr inline si::Unit<T> operator++(si::Unit<T>& lhs_, const int) noexcept;
    template <typename T>
    constexpr inline si::Unit<T> operator--(si::Unit<T>& lhs_, const int) noexcept;

    //  -- Arithmetic --
    template <typename T>
    constexpr inline si::Unit<T> operator+(const si::Unit<T>& rhs_) noexcept;
    template <typename T>
    constexpr inline si::Unit<T> operator-(const si::Unit<T>& rhs_) noexcept;
    template <typename TL, typename TR, typename L_ADD_R = typename type::arithmetic::add<TL, TR>>
    constexpr inline si::Unit<L_ADD_R> operator+(const si::Unit<TL>& lhs_, const si::Unit<TR>& rhs_) noexcept;
    template <typename TL, typename TR, typename L_SUB_R = typename type::arithmetic::sub<TL, TR>>
    constexpr inline si::Unit<L_SUB_R> operator-(const si::Unit<TL>& lhs_, const si::Unit<TR>& rhs_) noexcept;
    template <typename TL, typename TR, typename L_MULT_R = typename type::arithmetic::mult<TL, TR>>
    constexpr inline si::Unit<L_MULT_R> operator*(const si::Unit<TL>& lhs_, const si::Unit<TR>& rhs_) noexcept;
    template <typename TL, typename L_MULT_R = typename type::arithmetic::mult<TL, double>>
    constexpr inline si::Unit<L_MULT_R> operator*(const si::Unit<TL>& lhs_, double rhs_) noexcept;
    template <typename TR, typename L_MULT_R = typename type::arithmetic::mult<double, TR>>
    constexpr inline si::Unit<L_MULT_R> operator*(double lhs_, const si::Unit<TR>& rhs_) noexcept;
    template <typename TL, typename TR, typename L_DIV_R = typename type::arithmetic::div<TL, TR>>
    constexpr inline si::Unit<L_DIV_R> operator/(const si::Unit<TL>& lhs_, const si::Unit<TR>& rhs_) noexcept;
    template <typename TL, typename L_DIV_R, typename L_DIR_R = typename type::arithmetic::div<TL, double>>
    constexpr inline si::Unit<L_DIV_R> operator/(const si::Unit<TL>& lhs_, double rhs_) noexcept;
    template <typename TR, typename L_DIV_R, typename L_DIR_R = typename type::arithmetic::div<double, TR>>
    constexpr inline si::Unit<L_DIV_R> operator/(double lhs_, const si::Unit<TR>& rhs_) noexcept;



} // namespace arc
