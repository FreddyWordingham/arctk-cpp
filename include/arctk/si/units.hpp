//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include <arctk/si/dimension.hpp>



//  == MACROS ==
//  -- Conversion --
#define CONVERT_SET_DECL(type_, unit_, op_to_base_, op_from_base_)              \
                                                                                \
    constexpr inline const type_ operator""_##unit_(long double mag_) noexcept; \
                                                                                \
    namespace si                                                                \
    {                                                                           \
        constexpr inline double to_##unit_(type_ dim_) noexcept;                \
    }

#define METRIC_SET_DECL(type_, unit_)                           \
                                                                \
    CONVERT_SET_DECL(type_, Y##unit_, x * 1.0e24, x * 1.0e-24); \
    CONVERT_SET_DECL(type_, Z##unit_, x * 1.0e21, x * 1.0e-21); \
    CONVERT_SET_DECL(type_, E##unit_, x * 1.0e18, x * 1.0e-18); \
    CONVERT_SET_DECL(type_, P##unit_, x * 1.0e15, x * 1.0e-15); \
    CONVERT_SET_DECL(type_, T##unit_, x * 1.0e12, x * 1.0e-12); \
    CONVERT_SET_DECL(type_, G##unit_, x * 1.0e9, x * 1.0e-9);   \
    CONVERT_SET_DECL(type_, M##unit_, x * 1.0e6, x * 1.0e-6);   \
    CONVERT_SET_DECL(type_, k##unit_, x * 1.0e3, x * 1.0e-3);   \
    CONVERT_SET_DECL(type_, h##unit_, x * 1.0e2, x * 1.0e-2);   \
    CONVERT_SET_DECL(type_, da##unit_, x * 1.0e1, x * 1.0e-1);  \
    CONVERT_SET_DECL(type_, unit_, x, x);                       \
    CONVERT_SET_DECL(type_, d##unit_, x * 1.0e-1, x * 1.0e1);   \
    CONVERT_SET_DECL(type_, c##unit_, x * 1.0e-2, x * 1.0e2);   \
    CONVERT_SET_DECL(type_, m##unit_, x * 1.0e-3, x * 1.0e3);   \
    CONVERT_SET_DECL(type_, u##unit_, x * 1.0e-6, x * 1.0e6);   \
    CONVERT_SET_DECL(type_, n##unit_, x * 1.0e-9, x * 1.0e9);   \
    CONVERT_SET_DECL(type_, p##unit_, x * 1.0e-12, x * 1.0e12); \
    CONVERT_SET_DECL(type_, f##unit_, x * 1.0e-15, x * 1.0e15); \
    CONVERT_SET_DECL(type_, a##unit_, x * 1.0e-18, x * 1.0e18); \
    CONVERT_SET_DECL(type_, z##unit_, x * 1.0e-21, x * 1.0e21); \
    CONVERT_SET_DECL(type_, y##unit_, x * 1.0e-24, x * 1.0e24);

#define METRIC_SET_2_DECL(type_, unit_)                         \
                                                                \
    CONVERT_SET_DECL(type_, Y##unit_, x * 1.0e48, x * 1.0e-48); \
    CONVERT_SET_DECL(type_, Z##unit_, x * 1.0e42, x * 1.0e-42); \
    CONVERT_SET_DECL(type_, E##unit_, x * 1.0e36, x * 1.0e-36); \
    CONVERT_SET_DECL(type_, P##unit_, x * 1.0e30, x * 1.0e-30); \
    CONVERT_SET_DECL(type_, T##unit_, x * 1.0e24, x * 1.0e-24); \
    CONVERT_SET_DECL(type_, G##unit_, x * 1.0e18, x * 1.0e-18); \
    CONVERT_SET_DECL(type_, M##unit_, x * 1.0e12, x * 1.0e-12); \
    CONVERT_SET_DECL(type_, k##unit_, x * 1.0e6, x * 1.0e-6);   \
    CONVERT_SET_DECL(type_, h##unit_, x * 1.0e4, x * 1.0e-4);   \
    CONVERT_SET_DECL(type_, da##unit_, x * 1.0e2, x * 1.0e-2);  \
    CONVERT_SET_DECL(type_, unit_, x, x);                       \
    CONVERT_SET_DECL(type_, d##unit_, x * 1.0e-2, x * 1.0e2);   \
    CONVERT_SET_DECL(type_, c##unit_, x * 1.0e-4, x * 1.0e4);   \
    CONVERT_SET_DECL(type_, m##unit_, x * 1.0e-6, x * 1.0e6);   \
    CONVERT_SET_DECL(type_, u##unit_, x * 1.0e-12, x * 1.0e12); \
    CONVERT_SET_DECL(type_, n##unit_, x * 1.0e-18, x * 1.0e18); \
    CONVERT_SET_DECL(type_, p##unit_, x * 1.0e-24, x * 1.0e24); \
    CONVERT_SET_DECL(type_, f##unit_, x * 1.0e-30, x * 1.0e30); \
    CONVERT_SET_DECL(type_, a##unit_, x * 1.0e-36, x * 1.0e36); \
    CONVERT_SET_DECL(type_, z##unit_, x * 1.0e-42, x * 1.0e42); \
    CONVERT_SET_DECL(type_, y##unit_, x * 1.0e-48, x * 1.0e48);

#define METRIC_SET_3_DECL(type_, unit_)                         \
                                                                \
    CONVERT_SET_DECL(type_, Y##unit_, x * 1.0e72, x * 1.0e-72); \
    CONVERT_SET_DECL(type_, Z##unit_, x * 1.0e63, x * 1.0e-63); \
    CONVERT_SET_DECL(type_, E##unit_, x * 1.0e54, x * 1.0e-54); \
    CONVERT_SET_DECL(type_, P##unit_, x * 1.0e45, x * 1.0e-45); \
    CONVERT_SET_DECL(type_, T##unit_, x * 1.0e36, x * 1.0e-36); \
    CONVERT_SET_DECL(type_, G##unit_, x * 1.0e27, x * 1.0e-27); \
    CONVERT_SET_DECL(type_, M##unit_, x * 1.0e18, x * 1.0e-18); \
    CONVERT_SET_DECL(type_, k##unit_, x * 1.0e9, x * 1.0e-9);   \
    CONVERT_SET_DECL(type_, h##unit_, x * 1.0e6, x * 1.0e-6);   \
    CONVERT_SET_DECL(type_, da##unit_, x * 1.0e3, x * 1.0e-3);  \
    CONVERT_SET_DECL(type_, unit_, x, x);                       \
    CONVERT_SET_DECL(type_, d##unit_, x * 1.0e-3, x * 1.0e3);   \
    CONVERT_SET_DECL(type_, c##unit_, x * 1.0e-6, x * 1.0e6);   \
    CONVERT_SET_DECL(type_, m##unit_, x * 1.0e-9, x * 1.0e9);   \
    CONVERT_SET_DECL(type_, u##unit_, x * 1.0e-18, x * 1.0e18); \
    CONVERT_SET_DECL(type_, n##unit_, x * 1.0e-27, x * 1.0e27); \
    CONVERT_SET_DECL(type_, p##unit_, x * 1.0e-36, x * 1.0e36); \
    CONVERT_SET_DECL(type_, f##unit_, x * 1.0e-45, x * 1.0e45); \
    CONVERT_SET_DECL(type_, a##unit_, x * 1.0e-54, x * 1.0e54); \
    CONVERT_SET_DECL(type_, z##unit_, x * 1.0e-63, x * 1.0e63); \
    CONVERT_SET_DECL(type_, y##unit_, x * 1.0e-72, x * 1.0e72);



//  == NAMESPACE ==
namespace arc
{


    //  == OPERATORS ==
    //  -- String Literal --
    CONVERT_SET_DECL(si::Scalar, pi, x * 3.141592653589793238462643383279502884197169399375105820974, x / 3.141592653589793238462643383279502884197169399375105820974);
    METRIC_SET_DECL(si::Mass, kg);
    CONVERT_SET_DECL(si::Mass, oz, x * 0.0283495, x / 0.0283495);
    CONVERT_SET_DECL(si::Mass, lb, x * 0.453592, x / 0.453592);
    CONVERT_SET_DECL(si::Mass, st, x * 6.35029, x / 6.35029);
    METRIC_SET_DECL(si::Length, m);
    CONVERT_SET_DECL(si::Length, in, x * 0.0254, x / 0.0254);
    CONVERT_SET_DECL(si::Length, ft, x * 0.3048, x / 0.3048);
    CONVERT_SET_DECL(si::Length, yd, x * 0.9144, x / 0.9144);
    CONVERT_SET_DECL(si::Length, mi, x * 1609.34, x / 1609.34);
    CONVERT_SET_DECL(si::Length, nmi, x * 1852.0, x / 1852.0);
    METRIC_SET_DECL(si::Time, s);
    CONVERT_SET_DECL(si::Time, min, x * 60.0, x / 60.0);
    CONVERT_SET_DECL(si::Time, hr, x * 3600.0, x / 3600.0);
    CONVERT_SET_DECL(si::Time, day, x * 86400.0, x / 86400.0);
    CONVERT_SET_DECL(si::Time, week, x * 604800.0, x / 604800);
    CONVERT_SET_DECL(si::Time, month, x * 2.628e6, x / 2.628e+6);
    CONVERT_SET_DECL(si::Time, yr, x * 3.154e7, x / 3.154e7);
    CONVERT_SET_DECL(si::Time, decade, x * 3.154e8, x / 3.154e8);
    CONVERT_SET_DECL(si::Time, century, x * 3.154e9, x / 3.154e9);
    METRIC_SET_DECL(si::Temperature, K);
    CONVERT_SET_DECL(si::Temperature, oC, x + 273.15, x - 273.15);
    CONVERT_SET_DECL(si::Temperature, oF, (x + 459.67) / 1.8, (x * 1.8) - 459.67);
    METRIC_SET_DECL(si::Current, A);
    METRIC_SET_DECL(si::Intensity, cd);
    METRIC_SET_DECL(si::Amount, mol);
    METRIC_SET_DECL(si::Angle, rad);
    CONVERT_SET_DECL(si::Angle, deg, x*(180.0 / 1.0_pi), x*(1.0_pi / 180.0));
    METRIC_SET_DECL(si::SolidAngle, sr);
    METRIC_SET_2_DECL(si::Area, m2);
    CONVERT_SET_DECL(si::Area, in2, x * 0.00064516, x / 0.00064516);
    CONVERT_SET_DECL(si::Area, ft2, x * 0.092903, x / 0.092903);
    CONVERT_SET_DECL(si::Area, yd2, x * 0.836127, x / 0.836127);
    CONVERT_SET_DECL(si::Area, mi2, x * 2.59e6, x / 2.59e6);
    CONVERT_SET_DECL(si::Area, ha, x * 1.0e4, x * 1.0e-4);
    CONVERT_SET_DECL(si::Area, acre, x * 4046.86, x / 4046.86);
    METRIC_SET_3_DECL(si::Volume, m3);
    CONVERT_SET_DECL(si::Volume, L, x * 1.0e-3, x * 1.0e3);
    CONVERT_SET_DECL(si::Volume, in3, x * 1.6387e-5, x / 1.6387e-5);
    CONVERT_SET_DECL(si::Volume, ft3, x * 0.0283168, x / 0.0283168);
    CONVERT_SET_DECL(si::Volume, tsp, x * 5.9194e-6, x / 5.9194e-6);
    CONVERT_SET_DECL(si::Volume, tbsp, x * 1.7758e-5, x / 1.7758e-5);
    CONVERT_SET_DECL(si::Volume, foz, x * 2.8413e-5, x / 2.8413e-5);
    CONVERT_SET_DECL(si::Volume, cup, x * 0.000284131, x / 0.000284131);
    CONVERT_SET_DECL(si::Volume, pt, x * 0.000568261, x / 0.000568261);
    CONVERT_SET_DECL(si::Volume, qt, x * 0.00113652, x / 0.00113652);
    CONVERT_SET_DECL(si::Volume, gal, x * 0.00454609, x / 0.00454609);
    CONVERT_SET_DECL(si::Volume, UStsp, x * 4.9289e-6, x / 4.9289e-6);
    CONVERT_SET_DECL(si::Volume, UStbsp, x * 1.4787e-5, x / 1.4787e-5);
    CONVERT_SET_DECL(si::Volume, USfoz, x * 2.9574e-5, x / 2.9574e-5);
    CONVERT_SET_DECL(si::Volume, UScup, x * 0.00024, x / 0.00024);
    CONVERT_SET_DECL(si::Volume, USpt, x * 0.000473176, x / 0.000473176);
    CONVERT_SET_DECL(si::Volume, USqt, x * 0.000946353, x / 0.000946353);
    CONVERT_SET_DECL(si::Volume, USgal, x * 0.00378541, x / 0.00378541);
    CONVERT_SET_DECL(si::Velocity, mph, x * 0.44704, x / 0.44704);
    CONVERT_SET_DECL(si::Velocity, knot, x * 0.514444, x / 0.514444);
    METRIC_SET_DECL(si::Frequency, Hz);
    METRIC_SET_DECL(si::Force, N);
    METRIC_SET_DECL(si::Pressure, Pa);
    // CONVERT_SET_DECL(si::Pressure, bar, x * 1.0e5, x / 1.0e5);
    // CONVERT_SET_DECL(si::Pressure, atm, x * 101325.0, x / 101325.0);
    METRIC_SET_DECL(si::Energy, J);
    // CONVERT_SET_DECL(si::Energy, eV, x * 1.6022e-19, x / 1.6022e-19);
    // CONVERT_SET_DECL(si::Energy, cal, x * 4.184, x / 4.184);
    // CONVERT_SET_DECL(si::Energy, kcal, x * 4184.0, x / 4184.0);
    // CONVERT_SET_DECL(si::Energy, Wh, x * 3600.0, x / 3600.0);
    // CONVERT_SET_DECL(si::Energy, KWh, x * 3.6e6, x / 3.6e6);
    METRIC_SET_DECL(si::Power, W);
    METRIC_SET_DECL(si::Charge, C);
    METRIC_SET_DECL(si::Potential, V);
    METRIC_SET_DECL(si::Capacitance, F);
    METRIC_SET_DECL(si::Resistance, Ohm);
    METRIC_SET_DECL(si::Conductance, S);
    METRIC_SET_DECL(si::MagneticFlux, Wb);
    METRIC_SET_DECL(si::MagneticFluxDensity, T);
    METRIC_SET_DECL(si::Inductance, H);
    METRIC_SET_DECL(si::AbsorbedDose, Gy);
    METRIC_SET_DECL(si::CatalyticActivity, kat);



} // namespace arc



//  == CLEAN UP ==
//  -- Convertsion --
#undef CONVERT_SET_DECL
#undef METRIC_SET_DECL
#undef METRIC_SET_2_DECL
#undef METRIC_SET_3_DECL
