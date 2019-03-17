//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/si/dimension.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/comparison.inl"

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
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        const int Dimension<M, L, T, K, C, I, N, A>::MASS_EXPONENT{M};
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        const int Dimension<M, L, T, K, C, I, N, A>::LENGTH_EXPONENT{L};
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        const int Dimension<M, L, T, K, C, I, N, A>::TIME_EXPONENT{T};
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        const int Dimension<M, L, T, K, C, I, N, A>::TEMPERATURE_EXPONENT{K};
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        const int Dimension<M, L, T, K, C, I, N, A>::CURRENT_EXPONENT{C};
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        const int Dimension<M, L, T, K, C, I, N, A>::INTENSITY_EXPONENT{I};
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        const int Dimension<M, L, T, K, C, I, N, A>::AMOUNT_EXPONENT{N};
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        const int Dimension<M, L, T, K, C, I, N, A>::ANGLE_EXPONENT{A};


        //  -- Units --
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
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline Dimension<M, L, T, K, C, I, N, A>::Dimension() noexcept
          : _mag{0.0}
        {
        }

        constexpr inline Dimension<0, 0, 0, 0, 0, 0, 0, 0>::Dimension() noexcept
          : _mag{0.0}
        {
        }

        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline Dimension<M, L, T, K, C, I, N, A>::Dimension(const double mag_) noexcept
          : _mag{mag_}
        {
            assert(!std::isnan(mag_));
        }

        constexpr inline Dimension<0, 0, 0, 0, 0, 0, 0, 0>::Dimension(const double mag_) noexcept
          : _mag{mag_}
        {
            assert(!std::isnan(mag_));
        }



        //  == OPERATORS ==
        //  -- Conversion --
        constexpr inline Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator double() const
        {
            return (_mag);
        }


        //  -- Assignment --
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline const Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator+=(const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
        {
            _mag += rhs_.mag();

            return (*this);
        }

        constexpr inline const Dimension<0, 0, 0, 0, 0, 0, 0, 0>& Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator+=(const Dimension<0, 0, 0, 0, 0, 0, 0, 0>& rhs_) noexcept
        {
            _mag += rhs_.mag();

            return (*this);
        }

        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline const Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator-=(const Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
        {
            _mag -= rhs_.mag();

            return (*this);
        }

        constexpr inline const Dimension<0, 0, 0, 0, 0, 0, 0, 0>& Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator-=(const Dimension<0, 0, 0, 0, 0, 0, 0, 0>& rhs_) noexcept
        {
            _mag -= rhs_.mag();

            return (*this);
        }

        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline const Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator*=(const double rhs_) noexcept
        {
            _mag *= rhs_;

            return (*this);
        }

        constexpr inline const Dimension<0, 0, 0, 0, 0, 0, 0, 0>& Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator*=(const double rhs_) noexcept
        {
            _mag *= rhs_;

            return (*this);
        }

        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline const Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator/=(const double rhs_) noexcept
        {
            _mag /= rhs_;

            return (*this);
        }

        constexpr inline const Dimension<0, 0, 0, 0, 0, 0, 0, 0>& Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator/=(const double rhs_) noexcept
        {
            _mag /= rhs_;

            return (*this);
        }


        //  -- Increment / Decrement --
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline const Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator++() noexcept
        {
            ++_mag;

            return (*this);
        }

        constexpr inline const Dimension<0, 0, 0, 0, 0, 0, 0, 0>& Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator++() noexcept
        {
            ++_mag;

            return (*this);
        }

        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline const Dimension<M, L, T, K, C, I, N, A>& Dimension<M, L, T, K, C, I, N, A>::operator--() noexcept
        {
            --_mag;

            return (*this);
        }

        constexpr inline const Dimension<0, 0, 0, 0, 0, 0, 0, 0>& Dimension<0, 0, 0, 0, 0, 0, 0, 0>::operator--() noexcept
        {
            --_mag;

            return (*this);
        }



        //  == METHODS ==
        //  -- Getters --
        template <int M, int L, int T, int K, int C, int I, int N, int A>
        constexpr inline double Dimension<M, L, T, K, C, I, N, A>::mag() const noexcept
        {
            return (_mag);
        }

        constexpr inline double Dimension<0, 0, 0, 0, 0, 0, 0, 0>::mag() const noexcept
        {
            return (_mag);
        }



    } // namespace si



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator+(const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (si::Dimension<M, L, T, K, C, I, N, A>{+rhs_.mag()});
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator-(const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (si::Dimension<M, L, T, K, C, I, N, A>{-rhs_.mag()});
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator+(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (si::Dimension<M, L, T, K, C, I, N, A>{lhs_.mag() + rhs_.mag()});
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator-(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (si::Dimension<M, L, T, K, C, I, N, A>{lhs_.mag() - rhs_.mag()});
    }

    template <int Ml, int Ll, int Tl, int Kl, int Cl, int Il, int Nl, int Al, int Mr, int Lr, int Tr, int Kr, int Cr, int Ir, int Nr, int Ar>
    constexpr inline si::Dimension<Ml + Mr, Ll + Lr, Tl + Tr, Kl + Kr, Cl + Cr, Il + Ir, Nl + Nr, Al + Ar> operator*(const si::Dimension<Ml, Ll, Tl, Kl, Cl, Il, Nl, Al>& lhs_, const si::Dimension<Mr, Lr, Tr, Kr, Cr, Ir, Nr, Ar>& rhs_) noexcept
    {
        return (si::Dimension<Ml + Mr, Ll + Lr, Tl + Tr, Kl + Kr, Cl + Cr, Il + Ir, Nl + Nr, Al + Ar>{lhs_.mag() * rhs_.mag()});
    }

    template <int Ml, int Ll, int Tl, int Kl, int Cl, int Il, int Nl, int Al, int Mr, int Lr, int Tr, int Kr, int Cr, int Ir, int Nr, int Ar>
    constexpr inline si::Dimension<Ml - Mr, Ll - Lr, Tl - Tr, Kl - Kr, Cl - Cr, Il - Ir, Nl - Nr, Al - Ar> operator/(const si::Dimension<Ml, Ll, Tl, Kl, Cl, Il, Nl, Al>& lhs_, const si::Dimension<Mr, Lr, Tr, Kr, Cr, Ir, Nr, Ar>& rhs_) noexcept
    {
        return (si::Dimension<Ml - Mr, Ll - Lr, Tl - Tr, Kl - Kr, Cl - Cr, Il - Ir, Nl - Nr, Al - Ar>{lhs_.mag() / rhs_.mag()});
    }


    //  -- Increment / Decrement --
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator++(si::Dimension<M, L, T, K, C, I, N, A>& dim_, const int /*unused*/) noexcept
    {
        const auto dim{dim_};

        ++dim_;

        return (dim);
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator--(si::Dimension<M, L, T, K, C, I, N, A>& dim_, const int /*unused*/) noexcept
    {
        const auto dim{dim_};

        --dim_;

        return (dim);
    }


    //  -- Comparison --
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator==(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (math::equal(lhs_.mag(), rhs_.mag()));
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator!=(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (!(lhs_.mag() == rhs_.mag()));
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator<(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (lhs_.mag() < rhs_.mag());
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator>(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (lhs_.mag() > rhs_.mag());
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator<=(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (lhs_.mag() <= rhs_.mag());
    }

    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator>=(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept
    {
        return (lhs_.mag() >= rhs_.mag());
    }



} // namespace arc
