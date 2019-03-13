//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/si/dimension.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>



//  == NAMESPACE ==
namespace arc
{
    namespace si
    {



        //  == CONSTANTS ==
        //  -- Bases --
        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        const signed char Dimension<M, L, T, K, C, I, N, A>::MASS_EXPONENT{M};
        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        const signed char Dimension<M, L, T, K, C, I, N, A>::LENGTH_EXPONENT{L};
        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        const signed char Dimension<M, L, T, K, C, I, N, A>::TIME_EXPONENT{T};
        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        const signed char Dimension<M, L, T, K, C, I, N, A>::TEMPERATURE_EXPONENT{K};
        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        const signed char Dimension<M, L, T, K, C, I, N, A>::CURRENT_EXPONENT{C};
        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        const signed char Dimension<M, L, T, K, C, I, N, A>::INTENSITY_EXPONENT{I};
        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        const signed char Dimension<M, L, T, K, C, I, N, A>::AMOUNT_EXPONENT{N};
        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        const signed char Dimension<M, L, T, K, C, I, N, A>::ANGLE_EXPONENT{A};


        //  -- Units --
        template <>
        const char* const Scalar::UNITS{"_"};
        template <>
        const char* const Mass::UNITS{"kg"};
        template <>
        const char* const Length::UNITS{"m"};
        template <>
        const char* const Time::UNITS{"s"};
        template <>
        const char* const Temperature::UNITS{"K"};
        template <>
        const char* const Current::UNITS{"A"};
        template <>
        const char* const Intensity::UNITS{"cd"};
        template <>
        const char* const Amount::UNITS{"mol"};
        template <>
        const char* const Angle::UNITS{"rad"};
        template <>
        const char* const SolidAngle::UNITS{"sr"};
        template <>
        const char* const Area::UNITS{"m^2"};
        template <>
        const char* const Volume::UNITS{"m^3"};
        template <>
        const char* const Velocity::UNITS{"m/s"};
        template <>
        const char* const Acceleration::UNITS{"m/s^2"};
        template <>
        const char* const Jerk::UNITS{"m/s^3"};
        template <>
        const char* const Snap::UNITS{"m/s^4"};
        template <>
        const char* const Crackle::UNITS{"m/s^5"};
        template <>
        const char* const Pop::UNITS{"m/s^6"};
        template <>
        const char* const Wavenumber::UNITS{"m^-1"};
        template <>
        const char* const Density::UNITS{"kg/m^3"};
        template <>
        const char* const SurfaceDensity::UNITS{"kg/m^2"};
        template <>
        const char* const SpecificVolume::UNITS{"m^3/kg"};
        template <>
        const char* const CurrentDensity::UNITS{"A/m^2"};
        template <>
        const char* const MagneticFieldStrength::UNITS{"A/m"};
        template <>
        const char* const Concentration::UNITS{"mol/m^3"};
        template <>
        const char* const Luminance::UNITS{"cd/m^2"};
        template <>
        const char* const Frequency::UNITS{"Hz"};
        template <>
        const char* const Force::UNITS{"N"};
        template <>
        const char* const Pressure::UNITS{"Pa"};
        template <>
        const char* const Energy::UNITS{"J"};
        template <>
        const char* const Power::UNITS{"W"};
        template <>
        const char* const Charge::UNITS{"C"};
        template <>
        const char* const Potential::UNITS{"V"};
        template <>
        const char* const Capacitance::UNITS{"F"};
        template <>
        const char* const Resistance::UNITS{"Ω"};
        template <>
        const char* const Conductance::UNITS{"S"};
        template <>
        const char* const MagneticFlux::UNITS{"Wb"};
        template <>
        const char* const MagneticFluxDensity::UNITS{"T"};
        template <>
        const char* const Inductance::UNITS{"H"};
        template <>
        const char* const LuminousFlux::UNITS{"cd*sr"};
        template <>
        const char* const AbsorbedDose::UNITS{"Gy"};
        template <>
        const char* const CatalyticActivity::UNITS{"kat"};
        template <>
        const char* const DynamicViscosity::UNITS{"Pa*s"};
        template <>
        const char* const KinematicViscosity::UNITS{"m^2/s"};
        template <>
        const char* const SurfaceTension::UNITS{"N/m"};
        template <>
        const char* const AngularVelocity::UNITS{"rad/s"};
        template <>
        const char* const AngularAcceleration::UNITS{"rad/s^2"};
        template <>
        const char* const AngularJerk::UNITS{"rad/s^3"};
        template <>
        const char* const AngularSnap::UNITS{"rad/s^4"};
        template <>
        const char* const AngularCrackle::UNITS{"rad/s^5"};
        template <>
        const char* const AngularPop::UNITS{"rad/s^6"};
        template <>
        const char* const HeatFluxDensity::UNITS{"W/m^2"};
        template <>
        const char* const HeatCapacity::UNITS{"J/K"};
        template <>
        const char* const SpecificHeatCapacity::UNITS{"J/(kg*K)"};
        template <>
        const char* const ThermalConductivity::UNITS{"W/(m*K)"};
        template <>
        const char* const ElectricFieldStrength::UNITS{"V/m"};
        template <>
        const char* const ElectricChargeDensity::UNITS{"C/m^3"};
        template <>
        const char* const SurfaceChargeDensity::UNITS{"C/m^2"};
        template <>
        const char* const Permittivity::UNITS{"F/m"};
        template <>
        const char* const Permeability::UNITS{"H/m"};
        template <>
        const char* const MolarEnergy::UNITS{"J/mol"};
        template <>
        const char* const MolarEntropy::UNITS{"J/(mol*K)"};
        template <>
        const char* const Exposure::UNITS{"C/kg"};
        template <>
        const char* const AbsorbedDoseRate::UNITS{"Gy/s"};
        template <>
        const char* const RadiantIntensity::UNITS{"W/sr"};
        template <>
        const char* const Radiance::UNITS{"W/(m^2*sr)"};
        template <>
        const char* const CatalyticActivityConcentration::UNITS{"kat/m^3"};
        template <>
        const char* const Action::UNITS{"J*s"};



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        constexpr inline Dimension<M, L, T, K, C, I, N, A>::Dimension() noexcept
          : _mag{0.0}
        {
        }

        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        constexpr inline Dimension<M, L, T, K, C, I, N, A>::Dimension(const double mag_) noexcept
          : _mag{mag_}
        {
            assert(!std::isnan(mag_));
        }



        //  == OPERATORS ==
        //  -- Assignment --
        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        constexpr inline const Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator+=(const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
        {
            _mag += rhs_.mag();

            return (*this);
        }

        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        constexpr inline const Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator-=(const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
        {
            _mag -= rhs_.mag();

            return (*this);
        }

        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        constexpr inline const Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator*=(const double rhs_) noexcept
        {
            _mag *= rhs_;

            return (*this);
        }

        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        constexpr inline const Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator/=(const double rhs_) noexcept
        {
            _mag /= rhs_;

            return (*this);
        }


        //  -- Increment / Decrement --
        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        constexpr inline const Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator++() noexcept
        {
            ++_mag;

            return (*this);
        }

        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        constexpr inline const Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator--() noexcept
        {
            --_mag;

            return (*this);
        }



        //  == METHODS ==
        //  -- Getters --
        template <signed char M, signed char L, signed char T, signed char K, signed char C, signed char I, signed char N, signed char A>
        constexpr inline double Dimension<M, L, T, K, C, I, N, A>::mag() const noexcept
        {
            assert(!std::isnan(_mag));

            return (_mag);
        }



    } // namespace si
} // namespace arc
