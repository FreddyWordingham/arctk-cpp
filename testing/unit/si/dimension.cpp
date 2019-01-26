//  == IMPORTS ==
//  -- Arc --
#include <arctk/math/compare.inl>
#include <arctk/si/dimension.inl>

//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        inline void scalar() noexcept;
        template <typename T>
        inline void dimensional() noexcept;
        inline void cross_dimensional() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::scalar();
    arc::test::dimensional<arc::si::Mass>();
    arc::test::dimensional<arc::si::Length>();
    arc::test::dimensional<arc::si::Time>();
    arc::test::dimensional<arc::si::Temperature>();
    arc::test::dimensional<arc::si::Current>();
    arc::test::dimensional<arc::si::Intensity>();
    arc::test::dimensional<arc::si::Amount>();
    arc::test::dimensional<arc::si::Angle>();
    arc::test::dimensional<arc::si::SolidAngle>();
    arc::test::dimensional<arc::si::Area>();
    arc::test::dimensional<arc::si::Volume>();
    arc::test::dimensional<arc::si::Velocity>();
    arc::test::dimensional<arc::si::Acceleration>();
    arc::test::dimensional<arc::si::Jerk>();
    arc::test::dimensional<arc::si::Snap>();
    arc::test::dimensional<arc::si::Crackle>();
    arc::test::dimensional<arc::si::Pop>();
    arc::test::dimensional<arc::si::Wavenumber>();
    arc::test::dimensional<arc::si::Density>();
    arc::test::dimensional<arc::si::SurfaceDensity>();
    arc::test::dimensional<arc::si::SpecificVolume>();
    arc::test::dimensional<arc::si::CurrentDensity>();
    arc::test::dimensional<arc::si::MagneticFieldStrength>();
    arc::test::dimensional<arc::si::Concentration>();
    arc::test::dimensional<arc::si::Luminance>();
    arc::test::dimensional<arc::si::Illuminance>();
    arc::test::dimensional<arc::si::Frequency>();
    arc::test::dimensional<arc::si::Force>();
    arc::test::dimensional<arc::si::Pressure>();
    arc::test::dimensional<arc::si::Stress>();
    arc::test::dimensional<arc::si::EnergyDensity>();
    arc::test::dimensional<arc::si::Energy>();
    arc::test::dimensional<arc::si::Work>();
    arc::test::dimensional<arc::si::Heat>();
    arc::test::dimensional<arc::si::Power>();
    arc::test::dimensional<arc::si::RadiantFlux>();
    arc::test::dimensional<arc::si::Charge>();
    arc::test::dimensional<arc::si::Potential>();
    arc::test::dimensional<arc::si::Capacitance>();
    arc::test::dimensional<arc::si::Resistance>();
    arc::test::dimensional<arc::si::Conductance>();
    arc::test::dimensional<arc::si::MagneticFlux>();
    arc::test::dimensional<arc::si::MagneticFluxDensity>();
    arc::test::dimensional<arc::si::Inductance>();
    arc::test::dimensional<arc::si::LuminousFlux>();
    arc::test::dimensional<arc::si::Activity>();
    arc::test::dimensional<arc::si::AbsorbedDose>();
    arc::test::dimensional<arc::si::Kerma>();
    arc::test::dimensional<arc::si::SpecificEnergy>();
    arc::test::dimensional<arc::si::DoseEquivalent>();
    arc::test::dimensional<arc::si::CatalyticActivity>();
    arc::test::dimensional<arc::si::DynamicViscosity>();
    arc::test::dimensional<arc::si::KinematicViscosity>();
    arc::test::dimensional<arc::si::Moment>();
    arc::test::dimensional<arc::si::SurfaceTension>();
    arc::test::dimensional<arc::si::AngularVelocity>();
    arc::test::dimensional<arc::si::AngularAcceleration>();
    arc::test::dimensional<arc::si::AngularJerk>();
    arc::test::dimensional<arc::si::AngularSnap>();
    arc::test::dimensional<arc::si::AngularCrackle>();
    arc::test::dimensional<arc::si::AngularPop>();
    arc::test::dimensional<arc::si::HeatFluxDensity>();
    arc::test::dimensional<arc::si::Irradiance>();
    arc::test::dimensional<arc::si::HeatCapacity>();
    arc::test::dimensional<arc::si::Entropy>();
    arc::test::dimensional<arc::si::SpecificHeatCapacity>();
    arc::test::dimensional<arc::si::SpecificEntropy>();
    arc::test::dimensional<arc::si::ThermalConductivity>();
    arc::test::dimensional<arc::si::ElectricFieldStrength>();
    arc::test::dimensional<arc::si::ElectricChargeDensity>();
    arc::test::dimensional<arc::si::SurfaceChargeDensity>();
    arc::test::dimensional<arc::si::ElectricFluxDensity>();
    arc::test::dimensional<arc::si::ElectricDisplacement>();
    arc::test::dimensional<arc::si::Permittivity>();
    arc::test::dimensional<arc::si::Permeability>();
    arc::test::dimensional<arc::si::MolarEnergy>();
    arc::test::dimensional<arc::si::MolarEntropy>();
    arc::test::dimensional<arc::si::MolarHeatCapacity>();
    arc::test::dimensional<arc::si::Exposure>();
    arc::test::dimensional<arc::si::AbsorbedDoseRate>();
    arc::test::dimensional<arc::si::RadiantIntensity>();
    arc::test::dimensional<arc::si::Radiance>();
    arc::test::dimensional<arc::si::CatalyticActivityConcentration>();
    arc::test::dimensional<arc::si::Action>();
    arc::test::cross_dimensional();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        inline void scalar() noexcept
        {
            const si::Scalar scal_0;
            assert(math::zero(scal_0.mag()));

            const si::Scalar scal_1{1.25};
            assert(math::equal(scal_1.mag(), 1.25));

            const double x{1.25};

            si::Scalar scal_2{3.14159};
            scal_2 += scal_1;
            assert(math::equal(scal_2.mag(), 4.39159));

            si::Scalar scal_3{3.14159};
            scal_3 += x;
            assert(math::equal(scal_3.mag(), 4.39159));

            si::Scalar scal_4{3.14159};
            scal_4 -= scal_1;
            assert(math::equal(scal_4.mag(), 1.89159));

            si::Scalar scal_5{3.14159};
            scal_5 -= x;
            assert(math::equal(scal_5.mag(), 1.89159));

            si::Scalar scal_6{3.14159};
            scal_6 *= scal_1;
            assert(math::equal(scal_6.mag(), 3.9269875));

            si::Scalar scal_7{3.14159};
            scal_7 *= x;
            assert(math::equal(scal_7.mag(), 3.9269875));

            si::Scalar scal_8{3.14159};
            scal_8 /= scal_1;
            assert(math::equal(scal_8.mag(), 2.513272));

            si::Scalar scal_9{3.14159};
            scal_9 /= x;
            assert(math::equal(scal_9.mag(), 2.513272));

            si::Scalar scal_10{2.71};
            assert(math::equal((++scal_10).mag(), 3.71));
            assert(math::equal(scal_10.mag(), 3.71));

            si::Scalar scal_11{2.71};
            assert(math::equal((--scal_11).mag(), 1.71));
            assert(math::equal(scal_11.mag(), 1.71));

            si::Scalar scal_12{2.71};
            assert(math::equal((scal_12++).mag(), 2.71));
            assert(math::equal(scal_12.mag(), 3.71));

            si::Scalar scal_13{2.71};
            assert(math::equal((scal_13--).mag(), 2.71));
            assert(math::equal(scal_13.mag(), 1.71));

            const si::Scalar scal_14{+scal_1};
            assert(math::equal(scal_14.mag(), 1.25));

            const si::Scalar scal_15{-scal_1};
            assert(math::equal(scal_15.mag(), -1.25));

            const si::Scalar scal_16{scal_1 + scal_1};
            assert(math::equal(scal_16.mag(), 2.5));

            const si::Scalar scal_17{scal_1 + x};
            assert(math::equal(scal_17.mag(), 2.5));

            const si::Scalar scal_18{x + scal_1};
            assert(math::equal(scal_18.mag(), 2.5));

            const si::Scalar scal_19{scal_1 - scal_1};
            assert(math::zero(scal_19.mag()));

            const si::Scalar scal_20{scal_1 - x};
            assert(math::zero(scal_20.mag()));

            const si::Scalar scal_21{x - scal_1};
            assert(math::zero(scal_21.mag()));

            const si::Scalar scal_22{scal_1 * scal_1};
            assert(math::equal(scal_22.mag(), 1.5625));

            const si::Scalar scal_23{scal_1 * x};
            assert(math::equal(scal_23.mag(), 1.5625));

            const si::Scalar scal_24{x * scal_1};
            assert(math::equal(scal_24.mag(), 1.5625));

            const si::Scalar scal_25{scal_1 / scal_1};
            assert(math::equal(scal_25.mag(), 1.0));

            const si::Scalar scal_26{scal_1 / x};
            assert(math::equal(scal_26.mag(), 1.0));

            const si::Scalar scal_27{x / scal_1};
            assert(math::equal(scal_27.mag(), 1.0));
        }

        template <typename T>
        inline void dimensional() noexcept
        {
            const T dim_0;
            assert(math::zero(dim_0.mag()));

            const T dim_1{1.25};
            assert(math::equal(dim_1.mag(), 1.25));

            const double x{1.25};

            T dim_2{3.14159};
            dim_2 += dim_1;
            assert(math::equal(dim_2.mag(), 4.39159));

            T dim_3{3.14159};
            dim_3 -= dim_1;
            assert(math::equal(dim_3.mag(), 1.89159));

            T dim_4{3.14159};
            dim_4 *= dim_1;
            assert(math::equal(dim_4.mag(), 3.9269875));

            T dim_5{3.14159};
            dim_5 /= dim_1;
            assert(math::equal(dim_5.mag(), 2.513272));

            T dim_6{2.71};
            assert(math::equal((++dim_6).mag(), 3.71));
            assert(math::equal(dim_6.mag(), 3.71));

            T dim_7{2.71};
            assert(math::equal((--dim_7).mag(), 1.71));
            assert(math::equal(dim_7.mag(), 1.71));

            T dim_8{2.71};
            assert(math::equal((dim_8++).mag(), 2.71));
            assert(math::equal(dim_8.mag(), 3.71));

            T dim_9{2.71};
            assert(math::equal((dim_9--).mag(), 2.71));
            assert(math::equal(dim_9.mag(), 1.71));

            const T dim_10{+dim_1};
            assert(math::equal(dim_10.mag(), 1.25));

            const T dim_11{-dim_1};
            assert(math::equal(dim_11.mag(), -1.25));

            const T dim_12{dim_1 + dim_1};
            assert(math::equal(dim_12.mag(), 2.5));

            const T dim_13{dim_1 - dim_1};
            assert(math::zero(dim_13.mag()));

            const T dim_14{dim_1 * x};
            assert(math::equal(dim_14.mag(), 1.5625));

            const T dim_15{x * dim_1};
            assert(math::equal(dim_15.mag(), 1.5625));

            const T dim_16{dim_1 / dim_1};
            assert(math::equal(dim_16.mag(), 1.0));

            const T dim_17{dim_1 / x};
            assert(math::equal(dim_17.mag(), 1.0));
        }

        inline void cross_dimensional() noexcept
        {
            const si::Mass   mass{1.25};
            const si::Length leng{40.0};
            const si::Time   time{2.0};

            const si::Energy energy{mass * (leng / time) * (leng / time)};
            assert(math::equal(energy.mag(), 500.0));

            const si::Velocity vel{leng / time};
            assert(math::equal(vel.mag(), 20.0));

            const si::Acceleration acc{vel / time};
            assert(math::equal(acc.mag(), 10.0));

            const si::Force force{mass * acc};
            assert(math::equal(force.mag(), 12.5));
        }



    } // namespace test
} // namespace arc
