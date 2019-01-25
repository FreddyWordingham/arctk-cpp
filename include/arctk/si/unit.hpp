//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace si
    {



        //  == CLASSES ==
        //  -- Unit --
        template <int M, int L, int T, int K, int C, int I, int N, int A>
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
        class Unit<0, 0, 0, 0, 0, 0, 0, 0>
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
        using Scalar = Unit<0, 0, 0, 0, 0, 0, 0, 0>;

        //  -- Base --
        using Mass        = Unit<1, 0, 0, 0, 0, 0, 0, 0>;
        using Length      = Unit<0, 1, 0, 0, 0, 0, 0, 0>;
        using Time        = Unit<0, 0, 1, 0, 0, 0, 0, 0>;
        using Temperature = Unit<0, 0, 0, 1, 0, 0, 0, 0>;
        using Current     = Unit<0, 0, 0, 0, 1, 0, 0, 0>;
        using Intensity   = Unit<0, 0, 0, 0, 0, 1, 0, 0>;
        using Amount      = Unit<0, 0, 0, 0, 0, 0, 1, 0>;
        using Angle       = Unit<0, 0, 0, 0, 0, 0, 0, 1>;

        //  -- Derived --
        using SolidAngle                     = Unit<0, 0, 0, 0, 0, 0, 0, 2>;
        using Area                           = Unit<0, 2, 0, 0, 0, 0, 0, 0>;
        using Volume                         = Unit<0, 3, 0, 0, 0, 0, 0, 0>;
        using Velocity                       = Unit<0, 1, -1, 0, 0, 0, 0, 0>;
        using Acceleration                   = Unit<0, 1, -2, 0, 0, 0, 0, 0>;
        using Jerk                           = Unit<0, 1, -3, 0, 0, 0, 0, 0>;
        using Snap                           = Unit<0, 1, -4, 0, 0, 0, 0, 0>;
        using Crackle                        = Unit<0, 1, -5, 0, 0, 0, 0, 0>;
        using Pop                            = Unit<0, 1, -6, 0, 0, 0, 0, 0>;
        using Wavenumber                     = Unit<0, -1, 0, 0, 0, 0, 0, 0>;
        using Density                        = Unit<1, -3, 0, 0, 0, 0, 0, 0>;
        using SurfaceDensity                 = Unit<1, -2, 0, 0, 0, 0, 0, 0>;
        using SpecificVolume                 = Unit<-1, 3, 0, 0, 0, 0, 0, 0>;
        using CurrentDensity                 = Unit<0, -2, 0, 0, 1, 0, 0, 0>;
        using MagneticFieldStrength          = Unit<0, -1, 0, 0, 1, 0, 0, 0>;
        using Concentration                  = Unit<0, -3, 0, 0, 0, 0, 1, 0>;
        using Luminance                      = Unit<0, -2, 0, 0, 0, 1, 0, 0>;
        using Illuminance                    = Unit<0, -2, 0, 0, 0, 1, 0, 0>;
        using Frequency                      = Unit<0, 0, -1, 0, 0, 0, 0, 0>;
        using Force                          = Unit<1, 1, -2, 0, 0, 0, 0, 0>;
        using Pressure                       = Unit<1, -1, -2, 0, 0, 0, 0, 0>;
        using Stress                         = Unit<1, -1, -2, 0, 0, 0, 0, 0>;
        using EnergyDensity                  = Unit<1, -1, -2, 0, 0, 0, 0, 0>;
        using Energy                         = Unit<1, 2, -2, 0, 0, 0, 0, 0>;
        using Work                           = Unit<1, 2, -2, 0, 0, 0, 0, 0>;
        using Heat                           = Unit<1, 2, -2, 0, 0, 0, 0, 0>;
        using Power                          = Unit<1, 2, -3, 0, 0, 0, 0, 0>;
        using RadiantFlux                    = Unit<1, 2, -3, 0, 0, 0, 0, 0>;
        using Charge                         = Unit<0, 0, 1, 0, 1, 0, 0, 0>;
        using Potential                      = Unit<1, 2, -3, 0, -1, 0, 0, 0>;
        using Capacitance                    = Unit<-1, -2, 4, 0, -1, 0, 0, 0>;
        using Resistance                     = Unit<1, 2, -3, 0, -2, 0, 0, 0>;
        using Conductance                    = Unit<-1, -2, 3, 0, 2, 0, 0, 0>;
        using MagneticFlux                   = Unit<1, 2, -2, 0, -1, 0, 0, 0>;
        using MagneticFluxDensity            = Unit<1, 0, -2, 0, -1, 0, 0, 0>;
        using Inductance                     = Unit<1, 2, -2, 0, -2, 0, 0, 0>;
        using LuminousFlux                   = Unit<0, 0, 0, 0, 0, 1, 0, 2>;
        using Activity                       = Unit<0, 0, -1, 0, 0, 0, 0, 0>;
        using AbsorbedDose                   = Unit<0, 2, -2, 0, 0, 0, 0, 0>;
        using Kerma                          = Unit<0, 2, -2, 0, 0, 0, 0, 0>;
        using SpecificEnergy                 = Unit<0, 2, -2, 0, 0, 0, 0, 0>;
        using DoseEquivalent                 = Unit<0, 2, -2, 0, 0, 0, 0, 0>;
        using CatalyticActivity              = Unit<0, 0, -1, 0, 0, 0, 1, 0>;
        using DynamicViscosity               = Unit<1, -1, -1, 0, 0, 0, 0, 0>;
        using KinematicViscosity             = Unit<0, 2, -1, 0, 0, 0, 0, 0>;
        using Moment                         = Unit<1, 2, -2, 0, 0, 0, 0, 0>;
        using SurfaceTension                 = Unit<1, 0, -2, 0, 0, 0, 0, 0>;
        using AngularVelocity                = Unit<0, 0, -1, 0, 0, 0, 0, 1>;
        using AngularAcceleration            = Unit<0, 0, -2, 0, 0, 0, 0, 1>;
        using AngularJerk                    = Unit<0, 0, -3, 0, 0, 0, 0, 1>;
        using AngularSnap                    = Unit<0, 0, -4, 0, 0, 0, 0, 1>;
        using AngularCrackle                 = Unit<0, 0, -5, 0, 0, 0, 0, 1>;
        using AngularPop                     = Unit<0, 0, -6, 0, 0, 0, 0, 1>;
        using HeatFluxDensity                = Unit<1, 0, -3, 0, 0, 0, 0, 0>;
        using Irradiance                     = Unit<1, 0, -3, 0, 0, 0, 0, 0>;
        using HeatCapacity                   = Unit<1, 2, -2, -1, 0, 0, 0, 0>;
        using Entropy                        = Unit<1, 2, -2, -1, 0, 0, 0, 0>;
        using SpecificHeatCapacity           = Unit<0, 2, -2, -1, 0, 0, 0, 0>;
        using SpecificEntropy                = Unit<0, 2, -2, -1, 0, 0, 0, 0>;
        using ThermalConductivity            = Unit<1, 1, -3, -1, 0, 0, 0, 0>;
        using ElectricFieldStrength          = Unit<1, 1, -3, 0, 0, -1, 0, 0>;
        using ElectricChargeDensity          = Unit<0, -3, 1, 0, 0, 1, 0, 0>;
        using SurfaceChargeDensity           = Unit<0, -2, 1, 0, 0, 1, 0, 0>;
        using ElectricFluxDensity            = Unit<0, -2, 1, 0, 0, 1, 0, 0>;
        using ElectricDisplacement           = Unit<0, -2, 1, 0, 0, 1, 0, 0>;
        using Permittivity                   = Unit<-1, -3, 4, 0, 0, 2, 0, 0>;
        using Permeability                   = Unit<1, 1, -2, 0, 0, -2, 0, 0>;
        using MolarEnergy                    = Unit<1, 2, -2, 0, 0, 0, -1, 0>;
        using MolarEntropy                   = Unit<1, 2, -2, -1, 0, 0, -1, 0>;
        using MolarHeatCapacity              = Unit<1, 2, -2, -1, 0, 0, -1, 0>;
        using Exposure                       = Unit<-1, 0, 1, 0, 0, 1, 0, 0>;
        using AbsorbedDoseRate               = Unit<0, 2, -3, 0, 0, 0, 0, 0>;
        using RadiantIntensity               = Unit<1, 2, -3, 0, 0, 0, 0, 2>;
        using Radiance                       = Unit<1, 0, -3, 0, 0, 0, 0, 2>;
        using CatalyticActivityConcentration = Unit<0, -3, -1, 0, 0, 0, 1, 0>;
        using Action                         = Unit<1, 2, -1, 0, 0, 0, 0, 0>;



    } // namespace si



    //  == OPERATORS ==
    //  -- Increment / Decrement --
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Unit<M, L, T, K, C, I, N, A> operator++(si::Unit<M, L, T, K, C, I, N, A>& lhs_, const int) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Unit<M, L, T, K, C, I, N, A> operator--(si::Unit<M, L, T, K, C, I, N, A>& lhs_, const int) noexcept;

    //  -- Arithmetic --
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Unit<M, L, T, K, C, I, N, A> operator+(const si::Unit<M, L, T, K, C, I, N, A>& rhs_) noexcept;
    template <int M, int L, int T, int K, int C, int I, int N, int A>
    constexpr inline si::Unit<M, L, T, K, C, I, N, A> operator-(const si::Unit<M, L, T, K, C, I, N, A>& rhs_) noexcept;


    template <int ML, int LL, int TL, int KL, int CL, int IL, int NL, int AL, int MR, int LR, int TR, int KR, int CR, int IR, int NR, int AR, typename L_ADD_R = typename type::arithmetic::add<TL, TR>>
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
