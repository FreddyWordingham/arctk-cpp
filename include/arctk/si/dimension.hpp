//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace si
    {



        //  == CLASSES ==
        //  -- Dimension --
        template <int M, // Mass
                  int L, // Length
                  int T, // Time
                  int K, // Temperature
                  int C, // Current
                  int I, // Intensity
                  int N, // Amount
                  int A  // Angle
                  >
        class Dimension
        {
            //  == CONSTANTS ==
          public:
            //  -- Bases --
            static const int MASS_EXPONENT;
            static const int LENGTH_EXPONENT;
            static const int TIME_EXPONENT;
            static const int TEMPERATURE_EXPONENT;
            static const int CURRENT_EXPONENT;
            static const int INTENSITY_EXPONENT;
            static const int AMOUNT_EXPONENT;
            static const int ANGLE_EXPONENT;

            //  -- Units --
            static const char* const UNITS;


            //  == FIELDS ==
          private:
            //  -- Magnitude --
            double _mag;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Dimension() noexcept;
            constexpr inline explicit Dimension(const double mag_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            constexpr inline const Dimension& operator+=(const Dimension& rhs_) noexcept;
            constexpr inline const Dimension& operator-=(const Dimension& rhs_) noexcept;
            constexpr inline const Dimension& operator*=(const double rhs_) noexcept;
            constexpr inline const Dimension& operator/=(const double rhs_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline const Dimension& operator++() noexcept;
            constexpr inline const Dimension& operator--() noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline double mag() const noexcept;
        };


        //  -- Specialisations --
        template <>
        class Dimension<0, 0, 0, 0, 0, 0, 0, 0>
        {
            //  == CONSTANTS ==
          public:
            //  -- Bases --
            static const int MASS_EXPONENT;
            static const int LENGTH_EXPONENT;
            static const int TIME_EXPONENT;
            static const int TEMPERATURE_EXPONENT;
            static const int CURRENT_EXPONENT;
            static const int INTENSITY_EXPONENT;
            static const int AMOUNT_EXPONENT;
            static const int ANGLE_EXPONENT;

            //  -- Units --
            static const char* const UNITS;


            //  == FIELDS ==
          private:
            //  -- Magnitude --
            double _mag;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Dimension() noexcept;
            constexpr inline Dimension(const double mag_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Conversion --
            constexpr inline operator double() const;

            //  -- Assignment --
            constexpr inline const Dimension& operator+=(const Dimension& rhs_) noexcept;
            constexpr inline const Dimension& operator-=(const Dimension& rhs_) noexcept;
            constexpr inline const Dimension& operator*=(const double rhs_) noexcept;
            constexpr inline const Dimension& operator/=(const double rhs_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline const Dimension& operator++() noexcept;
            constexpr inline const Dimension& operator--() noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline double mag() const noexcept;
        };



        //  == ALIASES ==
        //  -- Dimensionless --
        using Scalar = Dimension<0, 0, 0, 0, 0, 0, 0, 0>;

        //  -- Base --
        using Mass        = Dimension<1, 0, 0, 0, 0, 0, 0, 0>;
        using Length      = Dimension<0, 1, 0, 0, 0, 0, 0, 0>;
        using Time        = Dimension<0, 0, 1, 0, 0, 0, 0, 0>;
        using Temperature = Dimension<0, 0, 0, 1, 0, 0, 0, 0>;
        using Current     = Dimension<0, 0, 0, 0, 1, 0, 0, 0>;
        using Intensity   = Dimension<0, 0, 0, 0, 0, 1, 0, 0>;
        using Amount      = Dimension<0, 0, 0, 0, 0, 0, 1, 0>;
        using Angle       = Dimension<0, 0, 0, 0, 0, 0, 0, 1>;

        //  -- Derived --
        using SolidAngle                     = Dimension<0, 0, 0, 0, 0, 0, 0, 2>;
        using Area                           = Dimension<0, 2, 0, 0, 0, 0, 0, 0>;
        using Volume                         = Dimension<0, 3, 0, 0, 0, 0, 0, 0>;
        using Velocity                       = Dimension<0, 1, -1, 0, 0, 0, 0, 0>;
        using Acceleration                   = Dimension<0, 1, -2, 0, 0, 0, 0, 0>;
        using Jerk                           = Dimension<0, 1, -3, 0, 0, 0, 0, 0>;
        using Snap                           = Dimension<0, 1, -4, 0, 0, 0, 0, 0>;
        using Crackle                        = Dimension<0, 1, -5, 0, 0, 0, 0, 0>;
        using Pop                            = Dimension<0, 1, -6, 0, 0, 0, 0, 0>;
        using Wavenumber                     = Dimension<0, -1, 0, 0, 0, 0, 0, 0>;
        using Density                        = Dimension<1, -3, 0, 0, 0, 0, 0, 0>;
        using SurfaceDensity                 = Dimension<1, -2, 0, 0, 0, 0, 0, 0>;
        using SpecificVolume                 = Dimension<-1, 3, 0, 0, 0, 0, 0, 0>;
        using CurrentDensity                 = Dimension<0, -2, 0, 0, 1, 0, 0, 0>;
        using MagneticFieldStrength          = Dimension<0, -1, 0, 0, 1, 0, 0, 0>;
        using Concentration                  = Dimension<0, -3, 0, 0, 0, 0, 1, 0>;
        using Luminance                      = Dimension<0, -2, 0, 0, 0, 1, 0, 0>;
        using Illuminance                    = Dimension<0, -2, 0, 0, 0, 1, 0, 0>;
        using Frequency                      = Dimension<0, 0, -1, 0, 0, 0, 0, 0>;
        using Force                          = Dimension<1, 1, -2, 0, 0, 0, 0, 0>;
        using Pressure                       = Dimension<1, -1, -2, 0, 0, 0, 0, 0>;
        using Stress                         = Dimension<1, -1, -2, 0, 0, 0, 0, 0>;
        using EnergyDensity                  = Dimension<1, -1, -2, 0, 0, 0, 0, 0>;
        using Energy                         = Dimension<1, 2, -2, 0, 0, 0, 0, 0>;
        using Work                           = Dimension<1, 2, -2, 0, 0, 0, 0, 0>;
        using Heat                           = Dimension<1, 2, -2, 0, 0, 0, 0, 0>;
        using Power                          = Dimension<1, 2, -3, 0, 0, 0, 0, 0>;
        using RadiantFlux                    = Dimension<1, 2, -3, 0, 0, 0, 0, 0>;
        using Charge                         = Dimension<0, 0, 1, 0, 1, 0, 0, 0>;
        using Potential                      = Dimension<1, 2, -3, 0, -1, 0, 0, 0>;
        using Capacitance                    = Dimension<-1, -2, 4, 0, -1, 0, 0, 0>;
        using Resistance                     = Dimension<1, 2, -3, 0, -2, 0, 0, 0>;
        using Conductance                    = Dimension<-1, -2, 3, 0, 2, 0, 0, 0>;
        using MagneticFlux                   = Dimension<1, 2, -2, 0, -1, 0, 0, 0>;
        using MagneticFluxDensity            = Dimension<1, 0, -2, 0, -1, 0, 0, 0>;
        using Inductance                     = Dimension<1, 2, -2, 0, -2, 0, 0, 0>;
        using LuminousFlux                   = Dimension<0, 0, 0, 0, 0, 1, 0, 2>;
        using Activity                       = Dimension<0, 0, -1, 0, 0, 0, 0, 0>;
        using AbsorbedDose                   = Dimension<0, 2, -2, 0, 0, 0, 0, 0>;
        using Kerma                          = Dimension<0, 2, -2, 0, 0, 0, 0, 0>;
        using SpecificEnergy                 = Dimension<0, 2, -2, 0, 0, 0, 0, 0>;
        using DoseEquivalent                 = Dimension<0, 2, -2, 0, 0, 0, 0, 0>;
        using CatalyticActivity              = Dimension<0, 0, -1, 0, 0, 0, 1, 0>;
        using DynamicViscosity               = Dimension<1, -1, -1, 0, 0, 0, 0, 0>;
        using KinematicViscosity             = Dimension<0, 2, -1, 0, 0, 0, 0, 0>;
        using Moment                         = Dimension<1, 2, -2, 0, 0, 0, 0, 0>;
        using SurfaceTension                 = Dimension<1, 0, -2, 0, 0, 0, 0, 0>;
        using AngularVelocity                = Dimension<0, 0, -1, 0, 0, 0, 0, 1>;
        using AngularAcceleration            = Dimension<0, 0, -2, 0, 0, 0, 0, 1>;
        using AngularJerk                    = Dimension<0, 0, -3, 0, 0, 0, 0, 1>;
        using AngularSnap                    = Dimension<0, 0, -4, 0, 0, 0, 0, 1>;
        using AngularCrackle                 = Dimension<0, 0, -5, 0, 0, 0, 0, 1>;
        using AngularPop                     = Dimension<0, 0, -6, 0, 0, 0, 0, 1>;
        using HeatFluxDensity                = Dimension<1, 0, -3, 0, 0, 0, 0, 0>;
        using Irradiance                     = Dimension<1, 0, -3, 0, 0, 0, 0, 0>;
        using HeatCapacity                   = Dimension<1, 2, -2, -1, 0, 0, 0, 0>;
        using Entropy                        = Dimension<1, 2, -2, -1, 0, 0, 0, 0>;
        using SpecificHeatCapacity           = Dimension<0, 2, -2, -1, 0, 0, 0, 0>;
        using SpecificEntropy                = Dimension<0, 2, -2, -1, 0, 0, 0, 0>;
        using ThermalConductivity            = Dimension<1, 1, -3, -1, 0, 0, 0, 0>;
        using ElectricFieldStrength          = Dimension<1, 1, -3, 0, 0, -1, 0, 0>;
        using ElectricChargeDensity          = Dimension<0, -3, 1, 0, 0, 1, 0, 0>;
        using SurfaceChargeDensity           = Dimension<0, -2, 1, 0, 0, 1, 0, 0>;
        using ElectricFluxDensity            = Dimension<0, -2, 1, 0, 0, 1, 0, 0>;
        using ElectricDisplacement           = Dimension<0, -2, 1, 0, 0, 1, 0, 0>;
        using Permittivity                   = Dimension<-1, -3, 4, 0, 0, 2, 0, 0>;
        using Permeability                   = Dimension<1, 1, -2, 0, 0, -2, 0, 0>;
        using MolarEnergy                    = Dimension<1, 2, -2, 0, 0, 0, -1, 0>;
        using MolarEntropy                   = Dimension<1, 2, -2, -1, 0, 0, -1, 0>;
        using MolarHeatCapacity              = Dimension<1, 2, -2, -1, 0, 0, -1, 0>;
        using Exposure                       = Dimension<-1, 0, 1, 0, 0, 1, 0, 0>;
        using AbsorbedDoseRate               = Dimension<0, 2, -3, 0, 0, 0, 0, 0>;
        using RadiantIntensity               = Dimension<1, 2, -3, 0, 0, 0, 0, 2>;
        using Radiance                       = Dimension<1, 0, -3, 0, 0, 0, 0, 2>;
        using CatalyticActivityConcentration = Dimension<0, -3, -1, 0, 0, 0, 1, 0>;
        using Action                         = Dimension<1, 2, -1, 0, 0, 0, 0, 0>;



    } // namespace si



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator+(const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator-(const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator+(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator-(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator*(const double lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator*(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const double rhs_) noexcept;
    template <int Ml, int Ll, int Tl, int Kl, int Cl, int Il, int Nl, int Al, int Mr, int Lr, int Tr, int Kr, int Cr, int Ir, int Nr, int Ar>
    constexpr inline si::Dimension<Ml + Mr, Ll + Lr, Tl + Tr, Kl + Kr, Cl + Cr, Il + Ir, Nl + Nr, Al + Ar> operator*(const si::Dimension<Ml, Ll, Tl, Kl, Cl, Il, Nl, Al>& lhs_, const si::Dimension<Mr, Lr, Tr, Kr, Cr, Ir, Nr, Ar>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<-M, -L, -T, -K, -C, -I, -N, -A> operator/(const double lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator/(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const double rhs_) noexcept;
    template <int Ml, int Ll, int Tl, int Kl, int Cl, int Il, int Nl, int Al, int Mr, int Lr, int Tr, int Kr, int Cr, int Ir, int Nr, int Ar>
    constexpr inline si::Dimension<Ml - Mr, Ll - Lr, Tl - Tr, Kl - Kr, Cl - Cr, Il - Ir, Nl - Nr, Al - Ar> operator/(const si::Dimension<Ml, Ll, Tl, Kl, Cl, Il, Nl, Al>& lhs_, const si::Dimension<Mr, Lr, Tr, Kr, Cr, Ir, Nr, Ar>& rhs_) noexcept;

    //  -- Increment / Decrement --
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator++(si::Dimension<M, L, T, K, C, I, N, A>& dim_, const int /*unused*/) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Dimension<M, L, T, K, C, I, N, A> operator--(si::Dimension<M, L, T, K, C, I, N, A>& dim_, const int /*unused*/) noexcept;

    //  -- Comparison --
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator==(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator!=(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator<(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator>(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator<=(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline bool operator>=(const si::Dimension<M, L, T, K, C, I, N, A>& lhs_, const si::Dimension<M, L, T, K, C, I, N, A>& rhs_) noexcept;



} // namespace arc
