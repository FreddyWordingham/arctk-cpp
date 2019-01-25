//  == IMPORTS ==
//  -- Arc --
#include <arctk/math/compare.inl>
#include <arctk/si/unit.inl>

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
        inline void mass() noexcept;
        inline void length() noexcept;
        inline void time() noexcept;
        inline void temperature() noexcept;
        inline void current() noexcept;
        inline void intensity() noexcept;
        inline void amount() noexcept;
        inline void angle() noexcept;
        inline void solid_angle() noexcept;
        inline void area() noexcept;
        inline void volume() noexcept;
        inline void velocity() noexcept;
        inline void acceleration() noexcept;
        inline void jerk() noexcept;
        inline void snap() noexcept;
        inline void crackle() noexcept;
        inline void pop() noexcept;
        inline void wavenumber() noexcept;
        inline void density() noexcept;
        inline void surface_density() noexcept;
        inline void specific_volume() noexcept;
        inline void current_density() noexcept;
        inline void magnetic_field_strength() noexcept;
        inline void concentration() noexcept;
        inline void luminance() noexcept;
        inline void illuminance() noexcept;
        inline void frequency() noexcept;
        inline void force() noexcept;
        inline void pressure() noexcept;
        inline void stress() noexcept;
        inline void energy_density() noexcept;
        inline void energy() noexcept;
        inline void work() noexcept;
        inline void heat() noexcept;
        inline void power() noexcept;
        inline void radiant_flux() noexcept;
        inline void charge() noexcept;
        inline void potential() noexcept;
        inline void capacitance() noexcept;
        inline void resistance() noexcept;
        inline void conductance() noexcept;
        inline void magnetic_flux() noexcept;
        inline void mag_flux_density() noexcept;
        inline void inductance() noexcept;
        inline void luminous_flux() noexcept;
        inline void activity() noexcept;
        inline void absorbed_dose() noexcept;
        inline void kerma() noexcept;
        inline void specific_energy() noexcept;
        inline void dose_equivalent() noexcept;
        inline void catalytic_activity() noexcept;
        inline void dynamic_viscosity() noexcept;
        inline void kinematic_viscosity() noexcept;
        inline void moment() noexcept;
        inline void surface_tension() noexcept;
        inline void angular_velocity() noexcept;
        inline void angular_acceleration() noexcept;
        inline void angular_jerk() noexcept;
        inline void angular_snap() noexcept;
        inline void angular_crackle() noexcept;
        inline void angular_pop() noexcept;
        inline void heat_flux_density() noexcept;
        inline void irradiance() noexcept;
        inline void heat_capacity() noexcept;
        inline void entropy() noexcept;
        inline void specific_heat_capacity() noexcept;
        inline void specific_entropy() noexcept;
        inline void thermal_conductivity() noexcept;
        inline void electric_field_strength() noexcept;
        inline void electric_charge_density() noexcept;
        inline void surface_charge_density() noexcept;
        inline void electric_flux_density() noexcept;
        inline void electric_displacement() noexcept;
        inline void permittivity() noexcept;
        inline void permeability() noexcept;
        inline void molar_energy() noexcept;
        inline void molar_entropy() noexcept;
        inline void molar_heat_capacity() noexcept;
        inline void exposure() noexcept;
        inline void absorbed_dose_rate() noexcept;
        inline void radiant_intensity() noexcept;
        inline void radiance() noexcept;
        inline void cat_act_concentration() noexcept;
        inline void action() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::scalar();
    arc::test::mass();
    arc::test::length();
    arc::test::time();
    arc::test::temperature();
    arc::test::current();
    arc::test::intensity();
    arc::test::amount();
    arc::test::angle();
    arc::test::solid_angle();
    arc::test::area();
    arc::test::volume();
    arc::test::velocity();
    arc::test::acceleration();
    arc::test::jerk();
    arc::test::snap();
    arc::test::crackle();
    arc::test::pop();
    arc::test::wavenumber();
    arc::test::density();
    arc::test::surface_density();
    arc::test::specific_volume();
    arc::test::current_density();
    arc::test::magnetic_field_strength();
    arc::test::concentration();
    arc::test::luminance();
    arc::test::illuminance();
    arc::test::frequency();
    arc::test::force();
    arc::test::pressure();
    arc::test::stress();
    arc::test::energy_density();
    arc::test::energy();
    arc::test::work();
    arc::test::heat();
    arc::test::power();
    arc::test::radiant_flux();
    arc::test::charge();
    arc::test::potential();
    arc::test::capacitance();
    arc::test::resistance();
    arc::test::conductance();
    arc::test::magnetic_flux();
    arc::test::mag_flux_density();
    arc::test::inductance();
    arc::test::luminous_flux();
    arc::test::activity();
    arc::test::absorbed_dose();
    arc::test::kerma();
    arc::test::specific_energy();
    arc::test::dose_equivalent();
    arc::test::catalytic_activity();
    arc::test::dynamic_viscosity();
    arc::test::kinematic_viscosity();
    arc::test::moment();
    arc::test::surface_tension();
    arc::test::angular_velocity();
    arc::test::angular_acceleration();
    arc::test::angular_jerk();
    arc::test::angular_snap();
    arc::test::angular_crackle();
    arc::test::angular_pop();
    arc::test::heat_flux_density();
    arc::test::irradiance();
    arc::test::heat_capacity();
    arc::test::entropy();
    arc::test::specific_heat_capacity();
    arc::test::specific_entropy();
    arc::test::thermal_conductivity();
    arc::test::electric_field_strength();
    arc::test::electric_charge_density();
    arc::test::surface_charge_density();
    arc::test::electric_flux_density();
    arc::test::electric_displacement();
    arc::test::permittivity();
    arc::test::permeability();
    arc::test::molar_energy();
    arc::test::molar_entropy();
    arc::test::molar_heat_capacity();
    arc::test::exposure();
    arc::test::absorbed_dose_rate();
    arc::test::radiant_intensity();
    arc::test::radiance();
    arc::test::cat_act_concentration();
    arc::test::action();

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

            const double doub_0{scal_0};
            assert(math::zero(doub_0));

            const double doub_1{scal_1};
            assert(math::equal(doub_1, 1.25));

            si::Scalar scal_2{3.14159};
            assert(math::equal(scal_2.mag(), 3.14159));
            assert(math::equal((++scal_2).mag(), 4.14159));
            assert(math::equal(scal_2.mag(), 4.14159));
            assert(math::equal((--scal_2).mag(), 3.14159));
            assert(math::equal(scal_2.mag(), 3.14159));

            si::Scalar scal_3{3.14159};
            assert(math::equal(scal_3.mag(), 3.14159));
            assert(math::equal((scal_3++).mag(), 3.14159));
            assert(math::equal(scal_3.mag(), 4.14159));
            assert(math::equal((scal_3--).mag(), 4.14159));
            assert(math::equal(scal_3.mag(), 3.14159));
        }

        inline void mass() noexcept
        {
            const si::Mass mass_0;
            assert(math::zero(mass_0.mag()));

            const si::Mass mass_1{1.25};
            assert(math::equal(mass_1.mag(), 1.25));

            const si::Mass mass_2{mass_1 * 2.0};
            assert(math::equal(mass_2.mag(), 2.5));

            const si::Mass mass_3{0.5 * mass_2};
            assert(math::equal(mass_3.mag(), 1.25));

            const si::Energy energy_0{mass_1 * (si::Length{1.0} * si::Length{1.0}) / (si::Time{0.5} * si::Time{0.5})};
            assert(math::equal(energy_0.mag(), 5.0));

            si::Mass mass_4{3.14159};
            assert(math::equal(mass_4.mag(), 3.14159));
            assert(math::equal((++mass_4).mag(), 4.14159));
            assert(math::equal(mass_4.mag(), 4.14159));
            assert(math::equal((--mass_4).mag(), 3.14159));
            assert(math::equal(mass_4.mag(), 3.14159));

            si::Mass mass_5{3.14159};
            assert(math::equal(mass_5.mag(), 3.14159));
            assert(math::equal((mass_5++).mag(), 3.14159));
            assert(math::equal(mass_5.mag(), 4.14159));
            assert(math::equal((mass_5--).mag(), 4.14159));
            assert(math::equal(mass_5.mag(), 3.14159));
        }

        inline void length() noexcept
        {
            const si::Length len_0;
            assert(math::zero(len_0.mag()));

            const si::Length len_1{1.25};
            assert(math::equal(len_1.mag(), 1.25));

            const si::Length len_2{len_1 * 2.0};
            assert(math::equal(len_2.mag(), 2.5));

            const si::Length len_3{0.5 * len_2};
            assert(math::equal(len_3.mag(), 1.25));

            const si::Velocity vel_0{len_1 / si::Time{0.5}};
            assert(math::equal(vel_0.mag(), 2.5));
        }

        inline void time() noexcept
        {
            const si::Time time_0;
            assert(math::zero(time_0.mag()));

            const si::Time time_1{1.25};
            assert(math::equal(time_1.mag(), 1.25));

            const si::Time time_2{time_1 * 2.0};
            assert(math::equal(time_2.mag(), 2.5));

            const si::Time time_3{0.5 * time_2};
            assert(math::equal(time_3.mag(), 1.25));

            const si::Velocity vel_0{si::Length{1.0} / time_1};
            assert(math::equal(vel_0.mag(), 0.8));
        }

        inline void temperature() noexcept
        {
            const si::Temperature temp_0;
            assert(math::zero(temp_0.mag()));

            const si::Temperature temp_1{1.25};
            assert(math::equal(temp_1.mag(), 1.25));

            const si::Temperature temp_2{temp_1 * 2.0};
            assert(math::equal(temp_2.mag(), 2.5));

            const si::Temperature temp_3{0.5 * temp_2};
            assert(math::equal(temp_3.mag(), 1.25));

            si::Temperature temp_4{3.14159};
            assert(math::equal(temp_4.mag(), 3.14159));
            assert(math::equal((++temp_4).mag(), 4.14159));
            assert(math::equal(temp_4.mag(), 4.14159));
            assert(math::equal((--temp_4).mag(), 3.14159));
            assert(math::equal(temp_4.mag(), 3.14159));

            si::Temperature temp_5{3.14159};
            assert(math::equal(temp_5.mag(), 3.14159));
            assert(math::equal((temp_5++).mag(), 3.14159));
            assert(math::equal(temp_5.mag(), 4.14159));
            assert(math::equal((temp_5--).mag(), 4.14159));
            assert(math::equal(temp_5.mag(), 3.14159));
        }

        inline void current() noexcept
        {
            const si::Current curr_0;
            assert(math::zero(curr_0.mag()));

            const si::Current curr_1{1.25};
            assert(math::equal(curr_1.mag(), 1.25));

            const si::Current curr_2{curr_1 * 2.0};
            assert(math::equal(curr_2.mag(), 2.5));

            const si::Current curr_3{0.5 * curr_2};
            assert(math::equal(curr_3.mag(), 1.25));

            si::Current curr_4{3.14159};
            assert(math::equal(curr_4.mag(), 3.14159));
            assert(math::equal((++curr_4).mag(), 4.14159));
            assert(math::equal(curr_4.mag(), 4.14159));
            assert(math::equal((--curr_4).mag(), 3.14159));
            assert(math::equal(curr_4.mag(), 3.14159));

            si::Current curr_5{3.14159};
            assert(math::equal(curr_5.mag(), 3.14159));
            assert(math::equal((curr_5++).mag(), 3.14159));
            assert(math::equal(curr_5.mag(), 4.14159));
            assert(math::equal((curr_5--).mag(), 4.14159));
            assert(math::equal(curr_5.mag(), 3.14159));
        }

        inline void intensity() noexcept
        {
            const si::Intensity intens_0;
            assert(math::zero(intens_0.mag()));

            const si::Intensity intens_1{1.25};
            assert(math::equal(intens_1.mag(), 1.25));

            const si::Intensity intens_2{intens_1 * 2.0};
            assert(math::equal(intens_2.mag(), 2.5));

            const si::Intensity intens_3{0.5 * intens_2};
            assert(math::equal(intens_3.mag(), 1.25));

            si::Intensity intens_4{3.14159};
            assert(math::equal(intens_4.mag(), 3.14159));
            assert(math::equal((++intens_4).mag(), 4.14159));
            assert(math::equal(intens_4.mag(), 4.14159));
            assert(math::equal((--intens_4).mag(), 3.14159));
            assert(math::equal(intens_4.mag(), 3.14159));

            si::Intensity intens_5{3.14159};
            assert(math::equal(intens_5.mag(), 3.14159));
            assert(math::equal((intens_5++).mag(), 3.14159));
            assert(math::equal(intens_5.mag(), 4.14159));
            assert(math::equal((intens_5--).mag(), 4.14159));
            assert(math::equal(intens_5.mag(), 3.14159));
        }

        inline void amount() noexcept
        {
            const si::Amount amount_0;
            assert(math::zero(amount_0.mag()));

            const si::Amount amount_1{1.25};
            assert(math::equal(amount_1.mag(), 1.25));

            const si::Amount amount_2{amount_1 * 2.0};
            assert(math::equal(amount_2.mag(), 2.5));

            const si::Amount amount_3{0.5 * amount_2};
            assert(math::equal(amount_3.mag(), 1.25));

            si::Amount amount_4{3.14159};
            assert(math::equal(amount_4.mag(), 3.14159));
            assert(math::equal((++amount_4).mag(), 4.14159));
            assert(math::equal(amount_4.mag(), 4.14159));
            assert(math::equal((--amount_4).mag(), 3.14159));
            assert(math::equal(amount_4.mag(), 3.14159));

            si::Amount amount_5{3.14159};
            assert(math::equal(amount_5.mag(), 3.14159));
            assert(math::equal((amount_5++).mag(), 3.14159));
            assert(math::equal(amount_5.mag(), 4.14159));
            assert(math::equal((amount_5--).mag(), 4.14159));
            assert(math::equal(amount_5.mag(), 3.14159));
        }

        inline void angle() noexcept
        {
            const si::Angle angle_0;
            assert(math::zero(angle_0.mag()));

            const si::Angle angle_1{1.25};
            assert(math::equal(angle_1.mag(), 1.25));

            const si::Angle angle_2{angle_1 * 2.0};
            assert(math::equal(angle_2.mag(), 2.5));

            const si::Angle angle_3{0.5 * angle_2};
            assert(math::equal(angle_3.mag(), 1.25));

            si::Angle angle_4{3.14159};
            assert(math::equal(angle_4.mag(), 3.14159));
            assert(math::equal((++angle_4).mag(), 4.14159));
            assert(math::equal(angle_4.mag(), 4.14159));
            assert(math::equal((--angle_4).mag(), 3.14159));
            assert(math::equal(angle_4.mag(), 3.14159));

            si::Angle angle_5{3.14159};
            assert(math::equal(angle_5.mag(), 3.14159));
            assert(math::equal((angle_5++).mag(), 3.14159));
            assert(math::equal(angle_5.mag(), 4.14159));
            assert(math::equal((angle_5--).mag(), 4.14159));
            assert(math::equal(angle_5.mag(), 3.14159));
        }

        inline void solid_angle() noexcept
        {
            const si::SolidAngle solid_angle_0;
            assert(math::zero(solid_angle_0.mag()));

            const si::SolidAngle solid_angle_1{1.25};
            assert(math::equal(solid_angle_1.mag(), 1.25));

            const si::SolidAngle solid_angle_2{solid_angle_1 * 2.0};
            assert(math::equal(solid_angle_2.mag(), 2.5));

            const si::SolidAngle solid_angle_3{0.5 * solid_angle_2};
            assert(math::equal(solid_angle_3.mag(), 1.25));

            si::SolidAngle solid_angle_4{3.14159};
            assert(math::equal(solid_angle_4.mag(), 3.14159));
            assert(math::equal((++solid_angle_4).mag(), 4.14159));
            assert(math::equal(solid_angle_4.mag(), 4.14159));
            assert(math::equal((--solid_angle_4).mag(), 3.14159));
            assert(math::equal(solid_angle_4.mag(), 3.14159));

            si::SolidAngle solid_angle_5{3.14159};
            assert(math::equal(solid_angle_5.mag(), 3.14159));
            assert(math::equal((solid_angle_5++).mag(), 3.14159));
            assert(math::equal(solid_angle_5.mag(), 4.14159));
            assert(math::equal((solid_angle_5--).mag(), 4.14159));
            assert(math::equal(solid_angle_5.mag(), 3.14159));
        }

        inline void area() noexcept
        {
            const si::Area area_0;
            assert(math::zero(area_0.mag()));

            const si::Area area_1{1.25};
            assert(math::equal(area_1.mag(), 1.25));

            const si::Area area_2{area_1 * 2.0};
            assert(math::equal(area_2.mag(), 2.5));

            const si::Area area_3{0.5 * area_2};
            assert(math::equal(area_3.mag(), 1.25));

            si::Area area_4{3.14159};
            assert(math::equal(area_4.mag(), 3.14159));
            assert(math::equal((++area_4).mag(), 4.14159));
            assert(math::equal(area_4.mag(), 4.14159));
            assert(math::equal((--area_4).mag(), 3.14159));
            assert(math::equal(area_4.mag(), 3.14159));

            si::Area area_5{3.14159};
            assert(math::equal(area_5.mag(), 3.14159));
            assert(math::equal((area_5++).mag(), 3.14159));
            assert(math::equal(area_5.mag(), 4.14159));
            assert(math::equal((area_5--).mag(), 4.14159));
            assert(math::equal(area_5.mag(), 3.14159));
        }

        inline void volume() noexcept
        {
            const si::Volume vol_0;
            assert(math::zero(vol_0.mag()));

            const si::Volume vol_1{1.25};
            assert(math::equal(vol_1.mag(), 1.25));

            const si::Volume vol_2{vol_1 * 2.0};
            assert(math::equal(vol_2.mag(), 2.5));

            const si::Volume vol_3{0.5 * vol_2};
            assert(math::equal(vol_3.mag(), 1.25));

            si::Volume vol_4{3.14159};
            assert(math::equal(vol_4.mag(), 3.14159));
            assert(math::equal((++vol_4).mag(), 4.14159));
            assert(math::equal(vol_4.mag(), 4.14159));
            assert(math::equal((--vol_4).mag(), 3.14159));
            assert(math::equal(vol_4.mag(), 3.14159));

            si::Volume vol_5{3.14159};
            assert(math::equal(vol_5.mag(), 3.14159));
            assert(math::equal((vol_5++).mag(), 3.14159));
            assert(math::equal(vol_5.mag(), 4.14159));
            assert(math::equal((vol_5--).mag(), 4.14159));
            assert(math::equal(vol_5.mag(), 3.14159));
        }

        inline void velocity() noexcept
        {
            const si::Velocity vel_0;
            assert(math::zero(vel_0.mag()));

            const si::Velocity vel_1{1.25};
            assert(math::equal(vel_1.mag(), 1.25));

            const si::Velocity vel_2{vel_1 * 2.0};
            assert(math::equal(vel_2.mag(), 2.5));

            const si::Velocity vel_3{0.5 * vel_2};
            assert(math::equal(vel_3.mag(), 1.25));

            si::Velocity vel_4{3.14159};
            assert(math::equal(vel_4.mag(), 3.14159));
            assert(math::equal((++vel_4).mag(), 4.14159));
            assert(math::equal(vel_4.mag(), 4.14159));
            assert(math::equal((--vel_4).mag(), 3.14159));
            assert(math::equal(vel_4.mag(), 3.14159));

            si::Velocity vel_5{3.14159};
            assert(math::equal(vel_5.mag(), 3.14159));
            assert(math::equal((vel_5++).mag(), 3.14159));
            assert(math::equal(vel_5.mag(), 4.14159));
            assert(math::equal((vel_5--).mag(), 4.14159));
            assert(math::equal(vel_5.mag(), 3.14159));
        }

        inline void acceleration() noexcept
        {
            const si::Acceleration acc_0;
            assert(math::zero(acc_0.mag()));

            const si::Acceleration acc_1{1.25};
            assert(math::equal(acc_1.mag(), 1.25));

            const si::Acceleration acc_2{acc_1 * 2.0};
            assert(math::equal(acc_2.mag(), 2.5));

            const si::Acceleration acc_3{0.5 * acc_2};
            assert(math::equal(acc_3.mag(), 1.25));

            si::Acceleration acc_4{3.14159};
            assert(math::equal(acc_4.mag(), 3.14159));
            assert(math::equal((++acc_4).mag(), 4.14159));
            assert(math::equal(acc_4.mag(), 4.14159));
            assert(math::equal((--acc_4).mag(), 3.14159));
            assert(math::equal(acc_4.mag(), 3.14159));

            si::Acceleration acc_5{3.14159};
            assert(math::equal(acc_5.mag(), 3.14159));
            assert(math::equal((acc_5++).mag(), 3.14159));
            assert(math::equal(acc_5.mag(), 4.14159));
            assert(math::equal((acc_5--).mag(), 4.14159));
            assert(math::equal(acc_5.mag(), 3.14159));
        }

        inline void jerk() noexcept
        {
            const si::Jerk jerk_0;
            assert(math::zero(jerk_0.mag()));

            const si::Jerk jerk_1{1.25};
            assert(math::equal(jerk_1.mag(), 1.25));

            const si::Jerk jerk_2{jerk_1 * 2.0};
            assert(math::equal(jerk_2.mag(), 2.5));

            const si::Jerk jerk_3{0.5 * jerk_2};
            assert(math::equal(jerk_3.mag(), 1.25));

            si::Jerk jerk_4{3.14159};
            assert(math::equal(jerk_4.mag(), 3.14159));
            assert(math::equal((++jerk_4).mag(), 4.14159));
            assert(math::equal(jerk_4.mag(), 4.14159));
            assert(math::equal((--jerk_4).mag(), 3.14159));
            assert(math::equal(jerk_4.mag(), 3.14159));

            si::Jerk jerk_5{3.14159};
            assert(math::equal(jerk_5.mag(), 3.14159));
            assert(math::equal((jerk_5++).mag(), 3.14159));
            assert(math::equal(jerk_5.mag(), 4.14159));
            assert(math::equal((jerk_5--).mag(), 4.14159));
            assert(math::equal(jerk_5.mag(), 3.14159));
        }

        inline void snap() noexcept
        {
            const si::Snap snap_0;
            assert(math::zero(snap_0.mag()));

            const si::Snap snap_1{1.25};
            assert(math::equal(snap_1.mag(), 1.25));

            const si::Snap snap_2{snap_1 * 2.0};
            assert(math::equal(snap_2.mag(), 2.5));

            const si::Snap snap_3{0.5 * snap_2};
            assert(math::equal(snap_3.mag(), 1.25));

            si::Snap snap_4{3.14159};
            assert(math::equal(snap_4.mag(), 3.14159));
            assert(math::equal((++snap_4).mag(), 4.14159));
            assert(math::equal(snap_4.mag(), 4.14159));
            assert(math::equal((--snap_4).mag(), 3.14159));
            assert(math::equal(snap_4.mag(), 3.14159));

            si::Snap snap_5{3.14159};
            assert(math::equal(snap_5.mag(), 3.14159));
            assert(math::equal((snap_5++).mag(), 3.14159));
            assert(math::equal(snap_5.mag(), 4.14159));
            assert(math::equal((snap_5--).mag(), 4.14159));
            assert(math::equal(snap_5.mag(), 3.14159));
        }

        inline void crackle() noexcept
        {
            const si::Crackle crack_0;
            assert(math::zero(crack_0.mag()));

            const si::Crackle crack_1{1.25};
            assert(math::equal(crack_1.mag(), 1.25));

            const si::Crackle crack_2{crack_1 * 2.0};
            assert(math::equal(crack_2.mag(), 2.5));

            const si::Crackle crack_3{0.5 * crack_2};
            assert(math::equal(crack_3.mag(), 1.25));

            si::Crackle crack_4{3.14159};
            assert(math::equal(crack_4.mag(), 3.14159));
            assert(math::equal((++crack_4).mag(), 4.14159));
            assert(math::equal(crack_4.mag(), 4.14159));
            assert(math::equal((--crack_4).mag(), 3.14159));
            assert(math::equal(crack_4.mag(), 3.14159));

            si::Crackle crack_5{3.14159};
            assert(math::equal(crack_5.mag(), 3.14159));
            assert(math::equal((crack_5++).mag(), 3.14159));
            assert(math::equal(crack_5.mag(), 4.14159));
            assert(math::equal((crack_5--).mag(), 4.14159));
            assert(math::equal(crack_5.mag(), 3.14159));
        }

        inline void pop() noexcept
        {
            const si::Pop pop_0;
            assert(math::zero(pop_0.mag()));

            const si::Pop pop_1{1.25};
            assert(math::equal(pop_1.mag(), 1.25));

            const si::Pop pop_2{pop_1 * 2.0};
            assert(math::equal(pop_2.mag(), 2.5));

            const si::Pop pop_3{0.5 * pop_2};
            assert(math::equal(pop_3.mag(), 1.25));

            si::Pop pop_4{3.14159};
            assert(math::equal(pop_4.mag(), 3.14159));
            assert(math::equal((++pop_4).mag(), 4.14159));
            assert(math::equal(pop_4.mag(), 4.14159));
            assert(math::equal((--pop_4).mag(), 3.14159));
            assert(math::equal(pop_4.mag(), 3.14159));

            si::Pop pop_5{3.14159};
            assert(math::equal(pop_5.mag(), 3.14159));
            assert(math::equal((pop_5++).mag(), 3.14159));
            assert(math::equal(pop_5.mag(), 4.14159));
            assert(math::equal((pop_5--).mag(), 4.14159));
            assert(math::equal(pop_5.mag(), 3.14159));
        }

        inline void wavenumber() noexcept
        {
            const si::Wavenumber wavenum_0;
            assert(math::zero(wavenum_0.mag()));

            const si::Wavenumber wavenum_1{1.25};
            assert(math::equal(wavenum_1.mag(), 1.25));

            const si::Wavenumber wavenum_2{wavenum_1 * 2.0};
            assert(math::equal(wavenum_2.mag(), 2.5));

            const si::Wavenumber wavenum_3{0.5 * wavenum_2};
            assert(math::equal(wavenum_3.mag(), 1.25));

            si::Wavenumber wavenum_4{3.14159};
            assert(math::equal(wavenum_4.mag(), 3.14159));
            assert(math::equal((++wavenum_4).mag(), 4.14159));
            assert(math::equal(wavenum_4.mag(), 4.14159));
            assert(math::equal((--wavenum_4).mag(), 3.14159));
            assert(math::equal(wavenum_4.mag(), 3.14159));

            si::Wavenumber wavenum_5{3.14159};
            assert(math::equal(wavenum_5.mag(), 3.14159));
            assert(math::equal((wavenum_5++).mag(), 3.14159));
            assert(math::equal(wavenum_5.mag(), 4.14159));
            assert(math::equal((wavenum_5--).mag(), 4.14159));
            assert(math::equal(wavenum_5.mag(), 3.14159));
        }

        inline void density() noexcept
        {
            const si::Density dens_0;
            assert(math::zero(dens_0.mag()));

            const si::Density dens_1{1.25};
            assert(math::equal(dens_1.mag(), 1.25));

            const si::Density dens_2{dens_1 * 2.0};
            assert(math::equal(dens_2.mag(), 2.5));

            const si::Density dens_3{0.5 * dens_2};
            assert(math::equal(dens_3.mag(), 1.25));

            si::Density dens_4{3.14159};
            assert(math::equal(dens_4.mag(), 3.14159));
            assert(math::equal((++dens_4).mag(), 4.14159));
            assert(math::equal(dens_4.mag(), 4.14159));
            assert(math::equal((--dens_4).mag(), 3.14159));
            assert(math::equal(dens_4.mag(), 3.14159));

            si::Density dens_5{3.14159};
            assert(math::equal(dens_5.mag(), 3.14159));
            assert(math::equal((dens_5++).mag(), 3.14159));
            assert(math::equal(dens_5.mag(), 4.14159));
            assert(math::equal((dens_5--).mag(), 4.14159));
            assert(math::equal(dens_5.mag(), 3.14159));
        }

        inline void surface_density() noexcept
        {
            const si::SurfaceDensity surf_dens_0;
            assert(math::zero(surf_dens_0.mag()));

            const si::SurfaceDensity surf_dens_1{1.25};
            assert(math::equal(surf_dens_1.mag(), 1.25));

            const si::SurfaceDensity surf_dens_2{surf_dens_1 * 2.0};
            assert(math::equal(surf_dens_2.mag(), 2.5));

            const si::SurfaceDensity surf_dens_3{0.5 * surf_dens_2};
            assert(math::equal(surf_dens_3.mag(), 1.25));

            si::SurfaceDensity surf_dens_4{3.14159};
            assert(math::equal(surf_dens_4.mag(), 3.14159));
            assert(math::equal((++surf_dens_4).mag(), 4.14159));
            assert(math::equal(surf_dens_4.mag(), 4.14159));
            assert(math::equal((--surf_dens_4).mag(), 3.14159));
            assert(math::equal(surf_dens_4.mag(), 3.14159));

            si::SurfaceDensity surf_dens_5{3.14159};
            assert(math::equal(surf_dens_5.mag(), 3.14159));
            assert(math::equal((surf_dens_5++).mag(), 3.14159));
            assert(math::equal(surf_dens_5.mag(), 4.14159));
            assert(math::equal((surf_dens_5--).mag(), 4.14159));
            assert(math::equal(surf_dens_5.mag(), 3.14159));
        }

        inline void specific_volume() noexcept
        {
            const si::SpecificVolume spec_vol_0;
            assert(math::zero(spec_vol_0.mag()));

            const si::SpecificVolume spec_vol_1{1.25};
            assert(math::equal(spec_vol_1.mag(), 1.25));

            const si::SpecificVolume spec_vol_2{spec_vol_1 * 2.0};
            assert(math::equal(spec_vol_2.mag(), 2.5));

            const si::SpecificVolume spec_vol_3{0.5 * spec_vol_2};
            assert(math::equal(spec_vol_3.mag(), 1.25));

            si::SpecificVolume spec_vol_4{3.14159};
            assert(math::equal(spec_vol_4.mag(), 3.14159));
            assert(math::equal((++spec_vol_4).mag(), 4.14159));
            assert(math::equal(spec_vol_4.mag(), 4.14159));
            assert(math::equal((--spec_vol_4).mag(), 3.14159));
            assert(math::equal(spec_vol_4.mag(), 3.14159));

            si::SpecificVolume spec_vol_5{3.14159};
            assert(math::equal(spec_vol_5.mag(), 3.14159));
            assert(math::equal((spec_vol_5++).mag(), 3.14159));
            assert(math::equal(spec_vol_5.mag(), 4.14159));
            assert(math::equal((spec_vol_5--).mag(), 4.14159));
            assert(math::equal(spec_vol_5.mag(), 3.14159));
        }

        inline void current_density() noexcept
        {
            const si::CurrentDensity curr_dens_0;
            assert(math::zero(curr_dens_0.mag()));

            const si::CurrentDensity curr_dens_1{1.25};
            assert(math::equal(curr_dens_1.mag(), 1.25));

            const si::CurrentDensity curr_dens_2{curr_dens_1 * 2.0};
            assert(math::equal(curr_dens_2.mag(), 2.5));

            const si::CurrentDensity curr_dens_3{0.5 * curr_dens_2};
            assert(math::equal(curr_dens_3.mag(), 1.25));

            si::CurrentDensity curr_dens_4{3.14159};
            assert(math::equal(curr_dens_4.mag(), 3.14159));
            assert(math::equal((++curr_dens_4).mag(), 4.14159));
            assert(math::equal(curr_dens_4.mag(), 4.14159));
            assert(math::equal((--curr_dens_4).mag(), 3.14159));
            assert(math::equal(curr_dens_4.mag(), 3.14159));

            si::CurrentDensity curr_dens_5{3.14159};
            assert(math::equal(curr_dens_5.mag(), 3.14159));
            assert(math::equal((curr_dens_5++).mag(), 3.14159));
            assert(math::equal(curr_dens_5.mag(), 4.14159));
            assert(math::equal((curr_dens_5--).mag(), 4.14159));
            assert(math::equal(curr_dens_5.mag(), 3.14159));
        }

        inline void magnetic_field_strength() noexcept
        {
            const si::MagneticFieldStrength mfs_0;
            assert(math::zero(mfs_0.mag()));

            const si::MagneticFieldStrength mfs_1{1.25};
            assert(math::equal(mfs_1.mag(), 1.25));

            const si::MagneticFieldStrength mfs_2{mfs_1 * 2.0};
            assert(math::equal(mfs_2.mag(), 2.5));

            const si::MagneticFieldStrength mfs_3{0.5 * mfs_2};
            assert(math::equal(mfs_3.mag(), 1.25));

            si::MagneticFieldStrength mfs_4{3.14159};
            assert(math::equal(mfs_4.mag(), 3.14159));
            assert(math::equal((++mfs_4).mag(), 4.14159));
            assert(math::equal(mfs_4.mag(), 4.14159));
            assert(math::equal((--mfs_4).mag(), 3.14159));
            assert(math::equal(mfs_4.mag(), 3.14159));

            si::MagneticFieldStrength mfs_5{3.14159};
            assert(math::equal(mfs_5.mag(), 3.14159));
            assert(math::equal((mfs_5++).mag(), 3.14159));
            assert(math::equal(mfs_5.mag(), 4.14159));
            assert(math::equal((mfs_5--).mag(), 4.14159));
            assert(math::equal(mfs_5.mag(), 3.14159));
        }

        inline void concentration() noexcept
        {
            const si::Concentration conc_0;
            assert(math::zero(conc_0.mag()));

            const si::Concentration conc_1{1.25};
            assert(math::equal(conc_1.mag(), 1.25));

            const si::Concentration conc_2{conc_1 * 2.0};
            assert(math::equal(conc_2.mag(), 2.5));

            const si::Concentration conc_3{0.5 * conc_2};
            assert(math::equal(conc_3.mag(), 1.25));

            si::Concentration conc_4{3.14159};
            assert(math::equal(conc_4.mag(), 3.14159));
            assert(math::equal((++conc_4).mag(), 4.14159));
            assert(math::equal(conc_4.mag(), 4.14159));
            assert(math::equal((--conc_4).mag(), 3.14159));
            assert(math::equal(conc_4.mag(), 3.14159));

            si::Concentration conc_5{3.14159};
            assert(math::equal(conc_5.mag(), 3.14159));
            assert(math::equal((conc_5++).mag(), 3.14159));
            assert(math::equal(conc_5.mag(), 4.14159));
            assert(math::equal((conc_5--).mag(), 4.14159));
            assert(math::equal(conc_5.mag(), 3.14159));
        }

        inline void luminance() noexcept
        {
            const si::Luminance lum_0;
            assert(math::zero(lum_0.mag()));

            const si::Luminance lum_1{1.25};
            assert(math::equal(lum_1.mag(), 1.25));

            const si::Luminance lum_2{lum_1 * 2.0};
            assert(math::equal(lum_2.mag(), 2.5));

            const si::Luminance lum_3{0.5 * lum_2};
            assert(math::equal(lum_3.mag(), 1.25));

            si::Luminance lum_4{3.14159};
            assert(math::equal(lum_4.mag(), 3.14159));
            assert(math::equal((++lum_4).mag(), 4.14159));
            assert(math::equal(lum_4.mag(), 4.14159));
            assert(math::equal((--lum_4).mag(), 3.14159));
            assert(math::equal(lum_4.mag(), 3.14159));

            si::Luminance lum_5{3.14159};
            assert(math::equal(lum_5.mag(), 3.14159));
            assert(math::equal((lum_5++).mag(), 3.14159));
            assert(math::equal(lum_5.mag(), 4.14159));
            assert(math::equal((lum_5--).mag(), 4.14159));
            assert(math::equal(lum_5.mag(), 3.14159));
        }

        inline void illuminance() noexcept
        {
            const si::Illuminance illum_0;
            assert(math::zero(illum_0.mag()));

            const si::Illuminance illum_1{1.25};
            assert(math::equal(illum_1.mag(), 1.25));

            const si::Illuminance illum_2{illum_1 * 2.0};
            assert(math::equal(illum_2.mag(), 2.5));

            const si::Illuminance illum_3{0.5 * illum_2};
            assert(math::equal(illum_3.mag(), 1.25));

            si::Illuminance illum_4{3.14159};
            assert(math::equal(illum_4.mag(), 3.14159));
            assert(math::equal((++illum_4).mag(), 4.14159));
            assert(math::equal(illum_4.mag(), 4.14159));
            assert(math::equal((--illum_4).mag(), 3.14159));
            assert(math::equal(illum_4.mag(), 3.14159));

            si::Illuminance illum_5{3.14159};
            assert(math::equal(illum_5.mag(), 3.14159));
            assert(math::equal((illum_5++).mag(), 3.14159));
            assert(math::equal(illum_5.mag(), 4.14159));
            assert(math::equal((illum_5--).mag(), 4.14159));
            assert(math::equal(illum_5.mag(), 3.14159));
        }

        inline void frequency() noexcept
        {
            const si::Frequency freq_0;
            assert(math::zero(freq_0.mag()));

            const si::Frequency freq_1{1.25};
            assert(math::equal(freq_1.mag(), 1.25));

            const si::Frequency freq_2{freq_1 * 2.0};
            assert(math::equal(freq_2.mag(), 2.5));

            const si::Frequency freq_3{0.5 * freq_2};
            assert(math::equal(freq_3.mag(), 1.25));

            si::Frequency freq_4{3.14159};
            assert(math::equal(freq_4.mag(), 3.14159));
            assert(math::equal((++freq_4).mag(), 4.14159));
            assert(math::equal(freq_4.mag(), 4.14159));
            assert(math::equal((--freq_4).mag(), 3.14159));
            assert(math::equal(freq_4.mag(), 3.14159));

            si::Frequency freq_5{3.14159};
            assert(math::equal(freq_5.mag(), 3.14159));
            assert(math::equal((freq_5++).mag(), 3.14159));
            assert(math::equal(freq_5.mag(), 4.14159));
            assert(math::equal((freq_5--).mag(), 4.14159));
            assert(math::equal(freq_5.mag(), 3.14159));
        }

        inline void force() noexcept
        {
            const si::Force force_0;
            assert(math::zero(force_0.mag()));

            const si::Force force_1{1.25};
            assert(math::equal(force_1.mag(), 1.25));

            const si::Force force_2{force_1 * 2.0};
            assert(math::equal(force_2.mag(), 2.5));

            const si::Force force_3{0.5 * force_2};
            assert(math::equal(force_3.mag(), 1.25));

            si::Force force_4{3.14159};
            assert(math::equal(force_4.mag(), 3.14159));
            assert(math::equal((++force_4).mag(), 4.14159));
            assert(math::equal(force_4.mag(), 4.14159));
            assert(math::equal((--force_4).mag(), 3.14159));
            assert(math::equal(force_4.mag(), 3.14159));

            si::Force force_5{3.14159};
            assert(math::equal(force_5.mag(), 3.14159));
            assert(math::equal((force_5++).mag(), 3.14159));
            assert(math::equal(force_5.mag(), 4.14159));
            assert(math::equal((force_5--).mag(), 4.14159));
            assert(math::equal(force_5.mag(), 3.14159));
        }

        inline void pressure() noexcept
        {
            const si::Pressure pres_0;
            assert(math::zero(pres_0.mag()));

            const si::Pressure pres_1{1.25};
            assert(math::equal(pres_1.mag(), 1.25));

            const si::Pressure pres_2{pres_1 * 2.0};
            assert(math::equal(pres_2.mag(), 2.5));

            const si::Pressure pres_3{0.5 * pres_2};
            assert(math::equal(pres_3.mag(), 1.25));

            si::Pressure pres_4{3.14159};
            assert(math::equal(pres_4.mag(), 3.14159));
            assert(math::equal((++pres_4).mag(), 4.14159));
            assert(math::equal(pres_4.mag(), 4.14159));
            assert(math::equal((--pres_4).mag(), 3.14159));
            assert(math::equal(pres_4.mag(), 3.14159));

            si::Pressure pres_5{3.14159};
            assert(math::equal(pres_5.mag(), 3.14159));
            assert(math::equal((pres_5++).mag(), 3.14159));
            assert(math::equal(pres_5.mag(), 4.14159));
            assert(math::equal((pres_5--).mag(), 4.14159));
            assert(math::equal(pres_5.mag(), 3.14159));
        }

        inline void stress() noexcept
        {
            const si::Stress stress_0;
            assert(math::zero(stress_0.mag()));

            const si::Stress stress_1{1.25};
            assert(math::equal(stress_1.mag(), 1.25));

            const si::Stress stress_2{stress_1 * 2.0};
            assert(math::equal(stress_2.mag(), 2.5));

            const si::Stress stress_3{0.5 * stress_2};
            assert(math::equal(stress_3.mag(), 1.25));

            si::Stress stress_4{3.14159};
            assert(math::equal(stress_4.mag(), 3.14159));
            assert(math::equal((++stress_4).mag(), 4.14159));
            assert(math::equal(stress_4.mag(), 4.14159));
            assert(math::equal((--stress_4).mag(), 3.14159));
            assert(math::equal(stress_4.mag(), 3.14159));

            si::Stress stress_5{3.14159};
            assert(math::equal(stress_5.mag(), 3.14159));
            assert(math::equal((stress_5++).mag(), 3.14159));
            assert(math::equal(stress_5.mag(), 4.14159));
            assert(math::equal((stress_5--).mag(), 4.14159));
            assert(math::equal(stress_5.mag(), 3.14159));
        }

        inline void energy_density() noexcept
        {
            const si::EnergyDensity udens_0;
            assert(math::zero(udens_0.mag()));

            const si::EnergyDensity udens_1{1.25};
            assert(math::equal(udens_1.mag(), 1.25));

            const si::EnergyDensity udens_2{udens_1 * 2.0};
            assert(math::equal(udens_2.mag(), 2.5));

            const si::EnergyDensity udens_3{0.5 * udens_2};
            assert(math::equal(udens_3.mag(), 1.25));

            si::EnergyDensity udens_4{3.14159};
            assert(math::equal(udens_4.mag(), 3.14159));
            assert(math::equal((++udens_4).mag(), 4.14159));
            assert(math::equal(udens_4.mag(), 4.14159));
            assert(math::equal((--udens_4).mag(), 3.14159));
            assert(math::equal(udens_4.mag(), 3.14159));

            si::EnergyDensity udens_5{3.14159};
            assert(math::equal(udens_5.mag(), 3.14159));
            assert(math::equal((udens_5++).mag(), 3.14159));
            assert(math::equal(udens_5.mag(), 4.14159));
            assert(math::equal((udens_5--).mag(), 4.14159));
            assert(math::equal(udens_5.mag(), 3.14159));
        }

        inline void energy() noexcept
        {
            const si::Energy energy_0;
            assert(math::zero(energy_0.mag()));

            const si::Energy energy_1{1.25};
            assert(math::equal(energy_1.mag(), 1.25));

            const si::Energy energy_2{energy_1 * 2.0};
            assert(math::equal(energy_2.mag(), 2.5));

            const si::Energy energy_3{0.5 * energy_2};
            assert(math::equal(energy_3.mag(), 1.25));

            si::Energy energy_4{3.14159};
            assert(math::equal(energy_4.mag(), 3.14159));
            assert(math::equal((++energy_4).mag(), 4.14159));
            assert(math::equal(energy_4.mag(), 4.14159));
            assert(math::equal((--energy_4).mag(), 3.14159));
            assert(math::equal(energy_4.mag(), 3.14159));

            si::Energy energy_5{3.14159};
            assert(math::equal(energy_5.mag(), 3.14159));
            assert(math::equal((energy_5++).mag(), 3.14159));
            assert(math::equal(energy_5.mag(), 4.14159));
            assert(math::equal((energy_5--).mag(), 4.14159));
            assert(math::equal(energy_5.mag(), 3.14159));
        }

        inline void work() noexcept
        {
            const si::Work work_0;
            assert(math::zero(work_0.mag()));

            const si::Work work_1{1.25};
            assert(math::equal(work_1.mag(), 1.25));

            const si::Work work_2{work_1 * 2.0};
            assert(math::equal(work_2.mag(), 2.5));

            const si::Work work_3{0.5 * work_2};
            assert(math::equal(work_3.mag(), 1.25));

            si::Work work_4{3.14159};
            assert(math::equal(work_4.mag(), 3.14159));
            assert(math::equal((++work_4).mag(), 4.14159));
            assert(math::equal(work_4.mag(), 4.14159));
            assert(math::equal((--work_4).mag(), 3.14159));
            assert(math::equal(work_4.mag(), 3.14159));

            si::Work work_5{3.14159};
            assert(math::equal(work_5.mag(), 3.14159));
            assert(math::equal((work_5++).mag(), 3.14159));
            assert(math::equal(work_5.mag(), 4.14159));
            assert(math::equal((work_5--).mag(), 4.14159));
            assert(math::equal(work_5.mag(), 3.14159));
        }

        inline void heat() noexcept
        {
            const si::Heat heat_0;
            assert(math::zero(heat_0.mag()));

            const si::Heat heat_1{1.25};
            assert(math::equal(heat_1.mag(), 1.25));

            const si::Heat heat_2{heat_1 * 2.0};
            assert(math::equal(heat_2.mag(), 2.5));

            const si::Heat heat_3{0.5 * heat_2};
            assert(math::equal(heat_3.mag(), 1.25));

            si::Heat heat_4{3.14159};
            assert(math::equal(heat_4.mag(), 3.14159));
            assert(math::equal((++heat_4).mag(), 4.14159));
            assert(math::equal(heat_4.mag(), 4.14159));
            assert(math::equal((--heat_4).mag(), 3.14159));
            assert(math::equal(heat_4.mag(), 3.14159));

            si::Heat heat_5{3.14159};
            assert(math::equal(heat_5.mag(), 3.14159));
            assert(math::equal((heat_5++).mag(), 3.14159));
            assert(math::equal(heat_5.mag(), 4.14159));
            assert(math::equal((heat_5--).mag(), 4.14159));
            assert(math::equal(heat_5.mag(), 3.14159));
        }

        inline void power() noexcept
        {
            const si::Power power_0;
            assert(math::zero(power_0.mag()));

            const si::Power power_1{1.25};
            assert(math::equal(power_1.mag(), 1.25));

            const si::Power power_2{power_1 * 2.0};
            assert(math::equal(power_2.mag(), 2.5));

            const si::Power power_3{0.5 * power_2};
            assert(math::equal(power_3.mag(), 1.25));

            si::Power power_4{3.14159};
            assert(math::equal(power_4.mag(), 3.14159));
            assert(math::equal((++power_4).mag(), 4.14159));
            assert(math::equal(power_4.mag(), 4.14159));
            assert(math::equal((--power_4).mag(), 3.14159));
            assert(math::equal(power_4.mag(), 3.14159));

            si::Power power_5{3.14159};
            assert(math::equal(power_5.mag(), 3.14159));
            assert(math::equal((power_5++).mag(), 3.14159));
            assert(math::equal(power_5.mag(), 4.14159));
            assert(math::equal((power_5--).mag(), 4.14159));
            assert(math::equal(power_5.mag(), 3.14159));
        }

        inline void radiant_flux() noexcept
        {
            const si::RadiantFlux rad_flux_0;
            assert(math::zero(rad_flux_0.mag()));

            const si::RadiantFlux rad_flux_1{1.25};
            assert(math::equal(rad_flux_1.mag(), 1.25));

            const si::RadiantFlux rad_flux_2{rad_flux_1 * 2.0};
            assert(math::equal(rad_flux_2.mag(), 2.5));

            const si::RadiantFlux rad_flux_3{0.5 * rad_flux_2};
            assert(math::equal(rad_flux_3.mag(), 1.25));

            si::RadiantFlux rad_flux_4{3.14159};
            assert(math::equal(rad_flux_4.mag(), 3.14159));
            assert(math::equal((++rad_flux_4).mag(), 4.14159));
            assert(math::equal(rad_flux_4.mag(), 4.14159));
            assert(math::equal((--rad_flux_4).mag(), 3.14159));
            assert(math::equal(rad_flux_4.mag(), 3.14159));

            si::RadiantFlux rad_flux_5{3.14159};
            assert(math::equal(rad_flux_5.mag(), 3.14159));
            assert(math::equal((rad_flux_5++).mag(), 3.14159));
            assert(math::equal(rad_flux_5.mag(), 4.14159));
            assert(math::equal((rad_flux_5--).mag(), 4.14159));
            assert(math::equal(rad_flux_5.mag(), 3.14159));
        }

        inline void charge() noexcept
        {
            const si::Charge charge_0;
            assert(math::zero(charge_0.mag()));

            const si::Charge charge_1{1.25};
            assert(math::equal(charge_1.mag(), 1.25));

            const si::Charge charge_2{charge_1 * 2.0};
            assert(math::equal(charge_2.mag(), 2.5));

            const si::Charge charge_3{0.5 * charge_2};
            assert(math::equal(charge_3.mag(), 1.25));

            si::Charge charge_4{3.14159};
            assert(math::equal(charge_4.mag(), 3.14159));
            assert(math::equal((++charge_4).mag(), 4.14159));
            assert(math::equal(charge_4.mag(), 4.14159));
            assert(math::equal((--charge_4).mag(), 3.14159));
            assert(math::equal(charge_4.mag(), 3.14159));

            si::Charge charge_5{3.14159};
            assert(math::equal(charge_5.mag(), 3.14159));
            assert(math::equal((charge_5++).mag(), 3.14159));
            assert(math::equal(charge_5.mag(), 4.14159));
            assert(math::equal((charge_5--).mag(), 4.14159));
            assert(math::equal(charge_5.mag(), 3.14159));
        }

        inline void potential() noexcept
        {
            const si::Potential pot_0;
            assert(math::zero(pot_0.mag()));

            const si::Potential pot_1{1.25};
            assert(math::equal(pot_1.mag(), 1.25));

            const si::Potential pot_2{pot_1 * 2.0};
            assert(math::equal(pot_2.mag(), 2.5));

            const si::Potential pot_3{0.5 * pot_2};
            assert(math::equal(pot_3.mag(), 1.25));

            si::Potential pot_4{3.14159};
            assert(math::equal(pot_4.mag(), 3.14159));
            assert(math::equal((++pot_4).mag(), 4.14159));
            assert(math::equal(pot_4.mag(), 4.14159));
            assert(math::equal((--pot_4).mag(), 3.14159));
            assert(math::equal(pot_4.mag(), 3.14159));

            si::Potential pot_5{3.14159};
            assert(math::equal(pot_5.mag(), 3.14159));
            assert(math::equal((pot_5++).mag(), 3.14159));
            assert(math::equal(pot_5.mag(), 4.14159));
            assert(math::equal((pot_5--).mag(), 4.14159));
            assert(math::equal(pot_5.mag(), 3.14159));
        }

        inline void capacitance() noexcept
        {
            const si::Capacitance cap_0;
            assert(math::zero(cap_0.mag()));

            const si::Capacitance cap_1{1.25};
            assert(math::equal(cap_1.mag(), 1.25));

            const si::Capacitance cap_2{cap_1 * 2.0};
            assert(math::equal(cap_2.mag(), 2.5));

            const si::Capacitance cap_3{0.5 * cap_2};
            assert(math::equal(cap_3.mag(), 1.25));

            si::Capacitance cap_4{3.14159};
            assert(math::equal(cap_4.mag(), 3.14159));
            assert(math::equal((++cap_4).mag(), 4.14159));
            assert(math::equal(cap_4.mag(), 4.14159));
            assert(math::equal((--cap_4).mag(), 3.14159));
            assert(math::equal(cap_4.mag(), 3.14159));

            si::Capacitance cap_5{3.14159};
            assert(math::equal(cap_5.mag(), 3.14159));
            assert(math::equal((cap_5++).mag(), 3.14159));
            assert(math::equal(cap_5.mag(), 4.14159));
            assert(math::equal((cap_5--).mag(), 4.14159));
            assert(math::equal(cap_5.mag(), 3.14159));
        }

        inline void resistance() noexcept
        {
            const si::Resistance res_0;
            assert(math::zero(res_0.mag()));

            const si::Resistance res_1{1.25};
            assert(math::equal(res_1.mag(), 1.25));

            const si::Resistance res_2{res_1 * 2.0};
            assert(math::equal(res_2.mag(), 2.5));

            const si::Resistance res_3{0.5 * res_2};
            assert(math::equal(res_3.mag(), 1.25));

            si::Resistance res_4{3.14159};
            assert(math::equal(res_4.mag(), 3.14159));
            assert(math::equal((++res_4).mag(), 4.14159));
            assert(math::equal(res_4.mag(), 4.14159));
            assert(math::equal((--res_4).mag(), 3.14159));
            assert(math::equal(res_4.mag(), 3.14159));

            si::Resistance res_5{3.14159};
            assert(math::equal(res_5.mag(), 3.14159));
            assert(math::equal((res_5++).mag(), 3.14159));
            assert(math::equal(res_5.mag(), 4.14159));
            assert(math::equal((res_5--).mag(), 4.14159));
            assert(math::equal(res_5.mag(), 3.14159));
        }

        inline void conductance() noexcept
        {
            const si::Conductance cond_0;
            assert(math::zero(cond_0.mag()));

            const si::Conductance cond_1{1.25};
            assert(math::equal(cond_1.mag(), 1.25));

            const si::Conductance cond_2{cond_1 * 2.0};
            assert(math::equal(cond_2.mag(), 2.5));

            const si::Conductance cond_3{0.5 * cond_2};
            assert(math::equal(cond_3.mag(), 1.25));

            si::Conductance cond_4{3.14159};
            assert(math::equal(cond_4.mag(), 3.14159));
            assert(math::equal((++cond_4).mag(), 4.14159));
            assert(math::equal(cond_4.mag(), 4.14159));
            assert(math::equal((--cond_4).mag(), 3.14159));
            assert(math::equal(cond_4.mag(), 3.14159));

            si::Conductance cond_5{3.14159};
            assert(math::equal(cond_5.mag(), 3.14159));
            assert(math::equal((cond_5++).mag(), 3.14159));
            assert(math::equal(cond_5.mag(), 4.14159));
            assert(math::equal((cond_5--).mag(), 4.14159));
            assert(math::equal(cond_5.mag(), 3.14159));
        }

        inline void magnetic_flux() noexcept
        {
            const si::MagneticFlux mag_flux_0;
            assert(math::zero(mag_flux_0.mag()));

            const si::MagneticFlux mag_flux_1{1.25};
            assert(math::equal(mag_flux_1.mag(), 1.25));

            const si::MagneticFlux mag_flux_2{mag_flux_1 * 2.0};
            assert(math::equal(mag_flux_2.mag(), 2.5));

            const si::MagneticFlux mag_flux_3{0.5 * mag_flux_2};
            assert(math::equal(mag_flux_3.mag(), 1.25));

            si::MagneticFlux mag_flux_4{3.14159};
            assert(math::equal(mag_flux_4.mag(), 3.14159));
            assert(math::equal((++mag_flux_4).mag(), 4.14159));
            assert(math::equal(mag_flux_4.mag(), 4.14159));
            assert(math::equal((--mag_flux_4).mag(), 3.14159));
            assert(math::equal(mag_flux_4.mag(), 3.14159));

            si::MagneticFlux mag_flux_5{3.14159};
            assert(math::equal(mag_flux_5.mag(), 3.14159));
            assert(math::equal((mag_flux_5++).mag(), 3.14159));
            assert(math::equal(mag_flux_5.mag(), 4.14159));
            assert(math::equal((mag_flux_5--).mag(), 4.14159));
            assert(math::equal(mag_flux_5.mag(), 3.14159));
        }

        inline void mag_flux_density() noexcept
        {
            const si::MagneticFluxDensity mag_flux_dens_0;
            assert(math::zero(mag_flux_dens_0.mag()));

            const si::MagneticFluxDensity mag_flux_dens_1{1.25};
            assert(math::equal(mag_flux_dens_1.mag(), 1.25));

            const si::MagneticFluxDensity mag_flux_dens_2{mag_flux_dens_1 * 2.0};
            assert(math::equal(mag_flux_dens_2.mag(), 2.5));

            const si::MagneticFluxDensity mag_flux_dens_3{0.5 * mag_flux_dens_2};
            assert(math::equal(mag_flux_dens_3.mag(), 1.25));

            si::MagneticFluxDensity mag_flux_dens_4{3.14159};
            assert(math::equal(mag_flux_dens_4.mag(), 3.14159));
            assert(math::equal((++mag_flux_dens_4).mag(), 4.14159));
            assert(math::equal(mag_flux_dens_4.mag(), 4.14159));
            assert(math::equal((--mag_flux_dens_4).mag(), 3.14159));
            assert(math::equal(mag_flux_dens_4.mag(), 3.14159));

            si::MagneticFluxDensity mag_flux_dens_5{3.14159};
            assert(math::equal(mag_flux_dens_5.mag(), 3.14159));
            assert(math::equal((mag_flux_dens_5++).mag(), 3.14159));
            assert(math::equal(mag_flux_dens_5.mag(), 4.14159));
            assert(math::equal((mag_flux_dens_5--).mag(), 4.14159));
            assert(math::equal(mag_flux_dens_5.mag(), 3.14159));
        }

        inline void inductance() noexcept
        {
            const si::Inductance ind_0;
            assert(math::zero(ind_0.mag()));

            const si::Inductance ind_1{1.25};
            assert(math::equal(ind_1.mag(), 1.25));

            const si::Inductance ind_2{ind_1 * 2.0};
            assert(math::equal(ind_2.mag(), 2.5));

            const si::Inductance ind_3{0.5 * ind_2};
            assert(math::equal(ind_3.mag(), 1.25));

            si::Inductance ind_4{3.14159};
            assert(math::equal(ind_4.mag(), 3.14159));
            assert(math::equal((++ind_4).mag(), 4.14159));
            assert(math::equal(ind_4.mag(), 4.14159));
            assert(math::equal((--ind_4).mag(), 3.14159));
            assert(math::equal(ind_4.mag(), 3.14159));

            si::Inductance ind_5{3.14159};
            assert(math::equal(ind_5.mag(), 3.14159));
            assert(math::equal((ind_5++).mag(), 3.14159));
            assert(math::equal(ind_5.mag(), 4.14159));
            assert(math::equal((ind_5--).mag(), 4.14159));
            assert(math::equal(ind_5.mag(), 3.14159));
        }

        inline void luminous_flux() noexcept
        {
            const si::LuminousFlux lum_flux_0;
            assert(math::zero(lum_flux_0.mag()));

            const si::LuminousFlux lum_flux_1{1.25};
            assert(math::equal(lum_flux_1.mag(), 1.25));

            const si::LuminousFlux lum_flux_2{lum_flux_1 * 2.0};
            assert(math::equal(lum_flux_2.mag(), 2.5));

            const si::LuminousFlux lum_flux_3{0.5 * lum_flux_2};
            assert(math::equal(lum_flux_3.mag(), 1.25));

            si::LuminousFlux lum_flux_4{3.14159};
            assert(math::equal(lum_flux_4.mag(), 3.14159));
            assert(math::equal((++lum_flux_4).mag(), 4.14159));
            assert(math::equal(lum_flux_4.mag(), 4.14159));
            assert(math::equal((--lum_flux_4).mag(), 3.14159));
            assert(math::equal(lum_flux_4.mag(), 3.14159));

            si::LuminousFlux lum_flux_5{3.14159};
            assert(math::equal(lum_flux_5.mag(), 3.14159));
            assert(math::equal((lum_flux_5++).mag(), 3.14159));
            assert(math::equal(lum_flux_5.mag(), 4.14159));
            assert(math::equal((lum_flux_5--).mag(), 4.14159));
            assert(math::equal(lum_flux_5.mag(), 3.14159));
        }

        inline void activity() noexcept
        {
            const si::Activity activity_0;
            assert(math::zero(activity_0.mag()));

            const si::Activity activity_1{1.25};
            assert(math::equal(activity_1.mag(), 1.25));

            const si::Activity activity_2{activity_1 * 2.0};
            assert(math::equal(activity_2.mag(), 2.5));

            const si::Activity activity_3{0.5 * activity_2};
            assert(math::equal(activity_3.mag(), 1.25));

            si::Activity activity_4{3.14159};
            assert(math::equal(activity_4.mag(), 3.14159));
            assert(math::equal((++activity_4).mag(), 4.14159));
            assert(math::equal(activity_4.mag(), 4.14159));
            assert(math::equal((--activity_4).mag(), 3.14159));
            assert(math::equal(activity_4.mag(), 3.14159));

            si::Activity activity_5{3.14159};
            assert(math::equal(activity_5.mag(), 3.14159));
            assert(math::equal((activity_5++).mag(), 3.14159));
            assert(math::equal(activity_5.mag(), 4.14159));
            assert(math::equal((activity_5--).mag(), 4.14159));
            assert(math::equal(activity_5.mag(), 3.14159));
        }

        inline void absorbed_dose() noexcept
        {
            const si::AbsorbedDose abs_dose_0;
            assert(math::zero(abs_dose_0.mag()));

            const si::AbsorbedDose abs_dose_1{1.25};
            assert(math::equal(abs_dose_1.mag(), 1.25));

            const si::AbsorbedDose abs_dose_2{abs_dose_1 * 2.0};
            assert(math::equal(abs_dose_2.mag(), 2.5));

            const si::AbsorbedDose abs_dose_3{0.5 * abs_dose_2};
            assert(math::equal(abs_dose_3.mag(), 1.25));

            si::AbsorbedDose abs_dose_4{3.14159};
            assert(math::equal(abs_dose_4.mag(), 3.14159));
            assert(math::equal((++abs_dose_4).mag(), 4.14159));
            assert(math::equal(abs_dose_4.mag(), 4.14159));
            assert(math::equal((--abs_dose_4).mag(), 3.14159));
            assert(math::equal(abs_dose_4.mag(), 3.14159));

            si::AbsorbedDose abs_dose_5{3.14159};
            assert(math::equal(abs_dose_5.mag(), 3.14159));
            assert(math::equal((abs_dose_5++).mag(), 3.14159));
            assert(math::equal(abs_dose_5.mag(), 4.14159));
            assert(math::equal((abs_dose_5--).mag(), 4.14159));
            assert(math::equal(abs_dose_5.mag(), 3.14159));
        }

        inline void kerma() noexcept
        {
            const si::Kerma kerma_0;
            assert(math::zero(kerma_0.mag()));

            const si::Kerma kerma_1{1.25};
            assert(math::equal(kerma_1.mag(), 1.25));

            const si::Kerma kerma_2{kerma_1 * 2.0};
            assert(math::equal(kerma_2.mag(), 2.5));

            const si::Kerma kerma_3{0.5 * kerma_2};
            assert(math::equal(kerma_3.mag(), 1.25));

            si::Kerma kerma_4{3.14159};
            assert(math::equal(kerma_4.mag(), 3.14159));
            assert(math::equal((++kerma_4).mag(), 4.14159));
            assert(math::equal(kerma_4.mag(), 4.14159));
            assert(math::equal((--kerma_4).mag(), 3.14159));
            assert(math::equal(kerma_4.mag(), 3.14159));

            si::Kerma kerma_5{3.14159};
            assert(math::equal(kerma_5.mag(), 3.14159));
            assert(math::equal((kerma_5++).mag(), 3.14159));
            assert(math::equal(kerma_5.mag(), 4.14159));
            assert(math::equal((kerma_5--).mag(), 4.14159));
            assert(math::equal(kerma_5.mag(), 3.14159));
        }

        inline void specific_energy() noexcept
        {
            const si::SpecificEnergy spec_energy_0;
            assert(math::zero(spec_energy_0.mag()));

            const si::SpecificEnergy spec_energy_1{1.25};
            assert(math::equal(spec_energy_1.mag(), 1.25));

            const si::SpecificEnergy spec_energy_2{spec_energy_1 * 2.0};
            assert(math::equal(spec_energy_2.mag(), 2.5));

            const si::SpecificEnergy spec_energy_3{0.5 * spec_energy_2};
            assert(math::equal(spec_energy_3.mag(), 1.25));

            si::SpecificEnergy spec_energy_4{3.14159};
            assert(math::equal(spec_energy_4.mag(), 3.14159));
            assert(math::equal((++spec_energy_4).mag(), 4.14159));
            assert(math::equal(spec_energy_4.mag(), 4.14159));
            assert(math::equal((--spec_energy_4).mag(), 3.14159));
            assert(math::equal(spec_energy_4.mag(), 3.14159));

            si::SpecificEnergy spec_energy_5{3.14159};
            assert(math::equal(spec_energy_5.mag(), 3.14159));
            assert(math::equal((spec_energy_5++).mag(), 3.14159));
            assert(math::equal(spec_energy_5.mag(), 4.14159));
            assert(math::equal((spec_energy_5--).mag(), 4.14159));
            assert(math::equal(spec_energy_5.mag(), 3.14159));
        }

        inline void dose_equivalent() noexcept
        {
            const si::DoseEquivalent dose_equiv_0;
            assert(math::zero(dose_equiv_0.mag()));

            const si::DoseEquivalent dose_equiv_1{1.25};
            assert(math::equal(dose_equiv_1.mag(), 1.25));

            const si::DoseEquivalent dose_equiv_2{dose_equiv_1 * 2.0};
            assert(math::equal(dose_equiv_2.mag(), 2.5));

            const si::DoseEquivalent dose_equiv_3{0.5 * dose_equiv_2};
            assert(math::equal(dose_equiv_3.mag(), 1.25));

            si::DoseEquivalent dose_equiv_4{3.14159};
            assert(math::equal(dose_equiv_4.mag(), 3.14159));
            assert(math::equal((++dose_equiv_4).mag(), 4.14159));
            assert(math::equal(dose_equiv_4.mag(), 4.14159));
            assert(math::equal((--dose_equiv_4).mag(), 3.14159));
            assert(math::equal(dose_equiv_4.mag(), 3.14159));

            si::DoseEquivalent dose_equiv_5{3.14159};
            assert(math::equal(dose_equiv_5.mag(), 3.14159));
            assert(math::equal((dose_equiv_5++).mag(), 3.14159));
            assert(math::equal(dose_equiv_5.mag(), 4.14159));
            assert(math::equal((dose_equiv_5--).mag(), 4.14159));
            assert(math::equal(dose_equiv_5.mag(), 3.14159));
        }

        inline void catalytic_activity() noexcept
        {
            const si::CatalyticActivity cat_act_0;
            assert(math::zero(cat_act_0.mag()));

            const si::CatalyticActivity cat_act_1{1.25};
            assert(math::equal(cat_act_1.mag(), 1.25));

            const si::CatalyticActivity cat_act_2{cat_act_1 * 2.0};
            assert(math::equal(cat_act_2.mag(), 2.5));

            const si::CatalyticActivity cat_act_3{0.5 * cat_act_2};
            assert(math::equal(cat_act_3.mag(), 1.25));

            si::CatalyticActivity cat_act_4{3.14159};
            assert(math::equal(cat_act_4.mag(), 3.14159));
            assert(math::equal((++cat_act_4).mag(), 4.14159));
            assert(math::equal(cat_act_4.mag(), 4.14159));
            assert(math::equal((--cat_act_4).mag(), 3.14159));
            assert(math::equal(cat_act_4.mag(), 3.14159));

            si::CatalyticActivity cat_act_5{3.14159};
            assert(math::equal(cat_act_5.mag(), 3.14159));
            assert(math::equal((cat_act_5++).mag(), 3.14159));
            assert(math::equal(cat_act_5.mag(), 4.14159));
            assert(math::equal((cat_act_5--).mag(), 4.14159));
            assert(math::equal(cat_act_5.mag(), 3.14159));
        }

        inline void dynamic_viscosity() noexcept
        {
            const si::DynamicViscosity dyn_visc_0;
            assert(math::zero(dyn_visc_0.mag()));

            const si::DynamicViscosity dyn_visc_1{1.25};
            assert(math::equal(dyn_visc_1.mag(), 1.25));

            const si::DynamicViscosity dyn_visc_2{dyn_visc_1 * 2.0};
            assert(math::equal(dyn_visc_2.mag(), 2.5));

            const si::DynamicViscosity dyn_visc_3{0.5 * dyn_visc_2};
            assert(math::equal(dyn_visc_3.mag(), 1.25));

            si::DynamicViscosity dyn_visc_4{3.14159};
            assert(math::equal(dyn_visc_4.mag(), 3.14159));
            assert(math::equal((++dyn_visc_4).mag(), 4.14159));
            assert(math::equal(dyn_visc_4.mag(), 4.14159));
            assert(math::equal((--dyn_visc_4).mag(), 3.14159));
            assert(math::equal(dyn_visc_4.mag(), 3.14159));

            si::DynamicViscosity dyn_visc_5{3.14159};
            assert(math::equal(dyn_visc_5.mag(), 3.14159));
            assert(math::equal((dyn_visc_5++).mag(), 3.14159));
            assert(math::equal(dyn_visc_5.mag(), 4.14159));
            assert(math::equal((dyn_visc_5--).mag(), 4.14159));
            assert(math::equal(dyn_visc_5.mag(), 3.14159));
        }

        inline void kinematic_viscosity() noexcept
        {
            const si::KinematicViscosity kine_visc_0;
            assert(math::zero(kine_visc_0.mag()));

            const si::KinematicViscosity kine_visc_1{1.25};
            assert(math::equal(kine_visc_1.mag(), 1.25));

            const si::KinematicViscosity kine_visc_2{kine_visc_1 * 2.0};
            assert(math::equal(kine_visc_2.mag(), 2.5));

            const si::KinematicViscosity kine_visc_3{0.5 * kine_visc_2};
            assert(math::equal(kine_visc_3.mag(), 1.25));

            si::KinematicViscosity kine_visc_4{3.14159};
            assert(math::equal(kine_visc_4.mag(), 3.14159));
            assert(math::equal((++kine_visc_4).mag(), 4.14159));
            assert(math::equal(kine_visc_4.mag(), 4.14159));
            assert(math::equal((--kine_visc_4).mag(), 3.14159));
            assert(math::equal(kine_visc_4.mag(), 3.14159));

            si::KinematicViscosity kine_visc_5{3.14159};
            assert(math::equal(kine_visc_5.mag(), 3.14159));
            assert(math::equal((kine_visc_5++).mag(), 3.14159));
            assert(math::equal(kine_visc_5.mag(), 4.14159));
            assert(math::equal((kine_visc_5--).mag(), 4.14159));
            assert(math::equal(kine_visc_5.mag(), 3.14159));
        }

        inline void moment() noexcept
        {
            const si::Moment moment_0;
            assert(math::zero(moment_0.mag()));

            const si::Moment moment_1{1.25};
            assert(math::equal(moment_1.mag(), 1.25));

            const si::Moment moment_2{moment_1 * 2.0};
            assert(math::equal(moment_2.mag(), 2.5));

            const si::Moment moment_3{0.5 * moment_2};
            assert(math::equal(moment_3.mag(), 1.25));

            si::Moment moment_4{3.14159};
            assert(math::equal(moment_4.mag(), 3.14159));
            assert(math::equal((++moment_4).mag(), 4.14159));
            assert(math::equal(moment_4.mag(), 4.14159));
            assert(math::equal((--moment_4).mag(), 3.14159));
            assert(math::equal(moment_4.mag(), 3.14159));

            si::Moment moment_5{3.14159};
            assert(math::equal(moment_5.mag(), 3.14159));
            assert(math::equal((moment_5++).mag(), 3.14159));
            assert(math::equal(moment_5.mag(), 4.14159));
            assert(math::equal((moment_5--).mag(), 4.14159));
            assert(math::equal(moment_5.mag(), 3.14159));
        }

        inline void surface_tension() noexcept
        {
            const si::SurfaceTension surf_tens_0;
            assert(math::zero(surf_tens_0.mag()));

            const si::SurfaceTension surf_tens_1{1.25};
            assert(math::equal(surf_tens_1.mag(), 1.25));

            const si::SurfaceTension surf_tens_2{surf_tens_1 * 2.0};
            assert(math::equal(surf_tens_2.mag(), 2.5));

            const si::SurfaceTension surf_tens_3{0.5 * surf_tens_2};
            assert(math::equal(surf_tens_3.mag(), 1.25));

            si::SurfaceTension surf_tens_4{3.14159};
            assert(math::equal(surf_tens_4.mag(), 3.14159));
            assert(math::equal((++surf_tens_4).mag(), 4.14159));
            assert(math::equal(surf_tens_4.mag(), 4.14159));
            assert(math::equal((--surf_tens_4).mag(), 3.14159));
            assert(math::equal(surf_tens_4.mag(), 3.14159));

            si::SurfaceTension surf_tens_5{3.14159};
            assert(math::equal(surf_tens_5.mag(), 3.14159));
            assert(math::equal((surf_tens_5++).mag(), 3.14159));
            assert(math::equal(surf_tens_5.mag(), 4.14159));
            assert(math::equal((surf_tens_5--).mag(), 4.14159));
            assert(math::equal(surf_tens_5.mag(), 3.14159));
        }

        inline void angular_velocity() noexcept
        {
            const si::AngularVelocity ang_vel_0;
            assert(math::zero(ang_vel_0.mag()));

            const si::AngularVelocity ang_vel_1{1.25};
            assert(math::equal(ang_vel_1.mag(), 1.25));

            const si::AngularVelocity ang_vel_2{ang_vel_1 * 2.0};
            assert(math::equal(ang_vel_2.mag(), 2.5));

            const si::AngularVelocity ang_vel_3{0.5 * ang_vel_2};
            assert(math::equal(ang_vel_3.mag(), 1.25));

            si::AngularVelocity ang_vel_4{3.14159};
            assert(math::equal(ang_vel_4.mag(), 3.14159));
            assert(math::equal((++ang_vel_4).mag(), 4.14159));
            assert(math::equal(ang_vel_4.mag(), 4.14159));
            assert(math::equal((--ang_vel_4).mag(), 3.14159));
            assert(math::equal(ang_vel_4.mag(), 3.14159));

            si::AngularVelocity ang_vel_5{3.14159};
            assert(math::equal(ang_vel_5.mag(), 3.14159));
            assert(math::equal((ang_vel_5++).mag(), 3.14159));
            assert(math::equal(ang_vel_5.mag(), 4.14159));
            assert(math::equal((ang_vel_5--).mag(), 4.14159));
            assert(math::equal(ang_vel_5.mag(), 3.14159));
        }

        inline void angular_acceleration() noexcept
        {
            const si::AngularAcceleration ang_acc_0;
            assert(math::zero(ang_acc_0.mag()));

            const si::AngularAcceleration ang_acc_1{1.25};
            assert(math::equal(ang_acc_1.mag(), 1.25));

            const si::AngularAcceleration ang_acc_2{ang_acc_1 * 2.0};
            assert(math::equal(ang_acc_2.mag(), 2.5));

            const si::AngularAcceleration ang_acc_3{0.5 * ang_acc_2};
            assert(math::equal(ang_acc_3.mag(), 1.25));

            si::AngularAcceleration ang_acc_4{3.14159};
            assert(math::equal(ang_acc_4.mag(), 3.14159));
            assert(math::equal((++ang_acc_4).mag(), 4.14159));
            assert(math::equal(ang_acc_4.mag(), 4.14159));
            assert(math::equal((--ang_acc_4).mag(), 3.14159));
            assert(math::equal(ang_acc_4.mag(), 3.14159));

            si::AngularAcceleration ang_acc_5{3.14159};
            assert(math::equal(ang_acc_5.mag(), 3.14159));
            assert(math::equal((ang_acc_5++).mag(), 3.14159));
            assert(math::equal(ang_acc_5.mag(), 4.14159));
            assert(math::equal((ang_acc_5--).mag(), 4.14159));
            assert(math::equal(ang_acc_5.mag(), 3.14159));
        }

        inline void angular_jerk() noexcept
        {
            const si::AngularJerk ang_jerk_0;
            assert(math::zero(ang_jerk_0.mag()));

            const si::AngularJerk ang_jerk_1{1.25};
            assert(math::equal(ang_jerk_1.mag(), 1.25));

            const si::AngularJerk ang_jerk_2{ang_jerk_1 * 2.0};
            assert(math::equal(ang_jerk_2.mag(), 2.5));

            const si::AngularJerk ang_jerk_3{0.5 * ang_jerk_2};
            assert(math::equal(ang_jerk_3.mag(), 1.25));

            si::AngularJerk ang_jerk_4{3.14159};
            assert(math::equal(ang_jerk_4.mag(), 3.14159));
            assert(math::equal((++ang_jerk_4).mag(), 4.14159));
            assert(math::equal(ang_jerk_4.mag(), 4.14159));
            assert(math::equal((--ang_jerk_4).mag(), 3.14159));
            assert(math::equal(ang_jerk_4.mag(), 3.14159));

            si::AngularJerk ang_jerk_5{3.14159};
            assert(math::equal(ang_jerk_5.mag(), 3.14159));
            assert(math::equal((ang_jerk_5++).mag(), 3.14159));
            assert(math::equal(ang_jerk_5.mag(), 4.14159));
            assert(math::equal((ang_jerk_5--).mag(), 4.14159));
            assert(math::equal(ang_jerk_5.mag(), 3.14159));
        }

        inline void angular_snap() noexcept
        {
            const si::AngularSnap ang_snap_0;
            assert(math::zero(ang_snap_0.mag()));

            const si::AngularSnap ang_snap_1{1.25};
            assert(math::equal(ang_snap_1.mag(), 1.25));

            const si::AngularSnap ang_snap_2{ang_snap_1 * 2.0};
            assert(math::equal(ang_snap_2.mag(), 2.5));

            const si::AngularSnap ang_snap_3{0.5 * ang_snap_2};
            assert(math::equal(ang_snap_3.mag(), 1.25));

            si::AngularSnap ang_snap_4{3.14159};
            assert(math::equal(ang_snap_4.mag(), 3.14159));
            assert(math::equal((++ang_snap_4).mag(), 4.14159));
            assert(math::equal(ang_snap_4.mag(), 4.14159));
            assert(math::equal((--ang_snap_4).mag(), 3.14159));
            assert(math::equal(ang_snap_4.mag(), 3.14159));

            si::AngularSnap ang_snap_5{3.14159};
            assert(math::equal(ang_snap_5.mag(), 3.14159));
            assert(math::equal((ang_snap_5++).mag(), 3.14159));
            assert(math::equal(ang_snap_5.mag(), 4.14159));
            assert(math::equal((ang_snap_5--).mag(), 4.14159));
            assert(math::equal(ang_snap_5.mag(), 3.14159));
        }

        inline void angular_crackle() noexcept
        {
            const si::AngularCrackle ang_crack_0;
            assert(math::zero(ang_crack_0.mag()));

            const si::AngularCrackle ang_crack_1{1.25};
            assert(math::equal(ang_crack_1.mag(), 1.25));

            const si::AngularCrackle ang_crack_2{ang_crack_1 * 2.0};
            assert(math::equal(ang_crack_2.mag(), 2.5));

            const si::AngularCrackle ang_crack_3{0.5 * ang_crack_2};
            assert(math::equal(ang_crack_3.mag(), 1.25));

            si::AngularCrackle ang_crack_4{3.14159};
            assert(math::equal(ang_crack_4.mag(), 3.14159));
            assert(math::equal((++ang_crack_4).mag(), 4.14159));
            assert(math::equal(ang_crack_4.mag(), 4.14159));
            assert(math::equal((--ang_crack_4).mag(), 3.14159));
            assert(math::equal(ang_crack_4.mag(), 3.14159));

            si::AngularCrackle ang_crack_5{3.14159};
            assert(math::equal(ang_crack_5.mag(), 3.14159));
            assert(math::equal((ang_crack_5++).mag(), 3.14159));
            assert(math::equal(ang_crack_5.mag(), 4.14159));
            assert(math::equal((ang_crack_5--).mag(), 4.14159));
            assert(math::equal(ang_crack_5.mag(), 3.14159));
        }

        inline void angular_pop() noexcept
        {
            const si::AngularPop ang_pop_0;
            assert(math::zero(ang_pop_0.mag()));

            const si::AngularPop ang_pop_1{1.25};
            assert(math::equal(ang_pop_1.mag(), 1.25));

            const si::AngularPop ang_pop_2{ang_pop_1 * 2.0};
            assert(math::equal(ang_pop_2.mag(), 2.5));

            const si::AngularPop ang_pop_3{0.5 * ang_pop_2};
            assert(math::equal(ang_pop_3.mag(), 1.25));

            si::AngularPop ang_pop_4{3.14159};
            assert(math::equal(ang_pop_4.mag(), 3.14159));
            assert(math::equal((++ang_pop_4).mag(), 4.14159));
            assert(math::equal(ang_pop_4.mag(), 4.14159));
            assert(math::equal((--ang_pop_4).mag(), 3.14159));
            assert(math::equal(ang_pop_4.mag(), 3.14159));

            si::AngularPop ang_pop_5{3.14159};
            assert(math::equal(ang_pop_5.mag(), 3.14159));
            assert(math::equal((ang_pop_5++).mag(), 3.14159));
            assert(math::equal(ang_pop_5.mag(), 4.14159));
            assert(math::equal((ang_pop_5--).mag(), 4.14159));
            assert(math::equal(ang_pop_5.mag(), 3.14159));
        }

        inline void heat_flux_density() noexcept
        {
            const si::HeatFluxDensity heat_flux_dens_0;
            assert(math::zero(heat_flux_dens_0.mag()));

            const si::HeatFluxDensity heat_flux_dens_1{1.25};
            assert(math::equal(heat_flux_dens_1.mag(), 1.25));

            const si::HeatFluxDensity heat_flux_dens_2{heat_flux_dens_1 * 2.0};
            assert(math::equal(heat_flux_dens_2.mag(), 2.5));

            const si::HeatFluxDensity heat_flux_dens_3{0.5 * heat_flux_dens_2};
            assert(math::equal(heat_flux_dens_3.mag(), 1.25));

            si::HeatFluxDensity heat_flux_dens_4{3.14159};
            assert(math::equal(heat_flux_dens_4.mag(), 3.14159));
            assert(math::equal((++heat_flux_dens_4).mag(), 4.14159));
            assert(math::equal(heat_flux_dens_4.mag(), 4.14159));
            assert(math::equal((--heat_flux_dens_4).mag(), 3.14159));
            assert(math::equal(heat_flux_dens_4.mag(), 3.14159));

            si::HeatFluxDensity heat_flux_dens_5{3.14159};
            assert(math::equal(heat_flux_dens_5.mag(), 3.14159));
            assert(math::equal((heat_flux_dens_5++).mag(), 3.14159));
            assert(math::equal(heat_flux_dens_5.mag(), 4.14159));
            assert(math::equal((heat_flux_dens_5--).mag(), 4.14159));
            assert(math::equal(heat_flux_dens_5.mag(), 3.14159));
        }

        inline void irradiance() noexcept
        {
            const si::Irradiance irrad_0;
            assert(math::zero(irrad_0.mag()));

            const si::Irradiance irrad_1{1.25};
            assert(math::equal(irrad_1.mag(), 1.25));

            const si::Irradiance irrad_2{irrad_1 * 2.0};
            assert(math::equal(irrad_2.mag(), 2.5));

            const si::Irradiance irrad_3{0.5 * irrad_2};
            assert(math::equal(irrad_3.mag(), 1.25));

            si::Irradiance irrad_4{3.14159};
            assert(math::equal(irrad_4.mag(), 3.14159));
            assert(math::equal((++irrad_4).mag(), 4.14159));
            assert(math::equal(irrad_4.mag(), 4.14159));
            assert(math::equal((--irrad_4).mag(), 3.14159));
            assert(math::equal(irrad_4.mag(), 3.14159));

            si::Irradiance irrad_5{3.14159};
            assert(math::equal(irrad_5.mag(), 3.14159));
            assert(math::equal((irrad_5++).mag(), 3.14159));
            assert(math::equal(irrad_5.mag(), 4.14159));
            assert(math::equal((irrad_5--).mag(), 4.14159));
            assert(math::equal(irrad_5.mag(), 3.14159));
        }

        inline void heat_capacity() noexcept
        {
            const si::HeatCapacity heat_cap_0;
            assert(math::zero(heat_cap_0.mag()));

            const si::HeatCapacity heat_cap_1{1.25};
            assert(math::equal(heat_cap_1.mag(), 1.25));

            const si::HeatCapacity heat_cap_2{heat_cap_1 * 2.0};
            assert(math::equal(heat_cap_2.mag(), 2.5));

            const si::HeatCapacity heat_cap_3{0.5 * heat_cap_2};
            assert(math::equal(heat_cap_3.mag(), 1.25));

            si::HeatCapacity heat_cap_4{3.14159};
            assert(math::equal(heat_cap_4.mag(), 3.14159));
            assert(math::equal((++heat_cap_4).mag(), 4.14159));
            assert(math::equal(heat_cap_4.mag(), 4.14159));
            assert(math::equal((--heat_cap_4).mag(), 3.14159));
            assert(math::equal(heat_cap_4.mag(), 3.14159));

            si::HeatCapacity heat_cap_5{3.14159};
            assert(math::equal(heat_cap_5.mag(), 3.14159));
            assert(math::equal((heat_cap_5++).mag(), 3.14159));
            assert(math::equal(heat_cap_5.mag(), 4.14159));
            assert(math::equal((heat_cap_5--).mag(), 4.14159));
            assert(math::equal(heat_cap_5.mag(), 3.14159));
        }

        inline void entropy() noexcept
        {
            const si::Entropy entr_0;
            assert(math::zero(entr_0.mag()));

            const si::Entropy entr_1{1.25};
            assert(math::equal(entr_1.mag(), 1.25));

            const si::Entropy entr_2{entr_1 * 2.0};
            assert(math::equal(entr_2.mag(), 2.5));

            const si::Entropy entr_3{0.5 * entr_2};
            assert(math::equal(entr_3.mag(), 1.25));

            si::Entropy entr_4{3.14159};
            assert(math::equal(entr_4.mag(), 3.14159));
            assert(math::equal((++entr_4).mag(), 4.14159));
            assert(math::equal(entr_4.mag(), 4.14159));
            assert(math::equal((--entr_4).mag(), 3.14159));
            assert(math::equal(entr_4.mag(), 3.14159));

            si::Entropy entr_5{3.14159};
            assert(math::equal(entr_5.mag(), 3.14159));
            assert(math::equal((entr_5++).mag(), 3.14159));
            assert(math::equal(entr_5.mag(), 4.14159));
            assert(math::equal((entr_5--).mag(), 4.14159));
            assert(math::equal(entr_5.mag(), 3.14159));
        }

        inline void specific_heat_capacity() noexcept
        {
            const si::SpecificHeatCapacity spec_heat_cap_0;
            assert(math::zero(spec_heat_cap_0.mag()));

            const si::SpecificHeatCapacity spec_heat_cap_1{1.25};
            assert(math::equal(spec_heat_cap_1.mag(), 1.25));

            const si::SpecificHeatCapacity spec_heat_cap_2{spec_heat_cap_1 * 2.0};
            assert(math::equal(spec_heat_cap_2.mag(), 2.5));

            const si::SpecificHeatCapacity spec_heat_cap_3{0.5 * spec_heat_cap_2};
            assert(math::equal(spec_heat_cap_3.mag(), 1.25));

            si::SpecificHeatCapacity spec_heat_cap_4{3.14159};
            assert(math::equal(spec_heat_cap_4.mag(), 3.14159));
            assert(math::equal((++spec_heat_cap_4).mag(), 4.14159));
            assert(math::equal(spec_heat_cap_4.mag(), 4.14159));
            assert(math::equal((--spec_heat_cap_4).mag(), 3.14159));
            assert(math::equal(spec_heat_cap_4.mag(), 3.14159));

            si::SpecificHeatCapacity spec_heat_cap_5{3.14159};
            assert(math::equal(spec_heat_cap_5.mag(), 3.14159));
            assert(math::equal((spec_heat_cap_5++).mag(), 3.14159));
            assert(math::equal(spec_heat_cap_5.mag(), 4.14159));
            assert(math::equal((spec_heat_cap_5--).mag(), 4.14159));
            assert(math::equal(spec_heat_cap_5.mag(), 3.14159));
        }

        inline void specific_entropy() noexcept
        {
            const si::SpecificEntropy spec_entr_0;
            assert(math::zero(spec_entr_0.mag()));

            const si::SpecificEntropy spec_entr_1{1.25};
            assert(math::equal(spec_entr_1.mag(), 1.25));

            const si::SpecificEntropy spec_entr_2{spec_entr_1 * 2.0};
            assert(math::equal(spec_entr_2.mag(), 2.5));

            const si::SpecificEntropy spec_entr_3{0.5 * spec_entr_2};
            assert(math::equal(spec_entr_3.mag(), 1.25));

            si::SpecificEntropy spec_entr_4{3.14159};
            assert(math::equal(spec_entr_4.mag(), 3.14159));
            assert(math::equal((++spec_entr_4).mag(), 4.14159));
            assert(math::equal(spec_entr_4.mag(), 4.14159));
            assert(math::equal((--spec_entr_4).mag(), 3.14159));
            assert(math::equal(spec_entr_4.mag(), 3.14159));

            si::SpecificEntropy spec_entr_5{3.14159};
            assert(math::equal(spec_entr_5.mag(), 3.14159));
            assert(math::equal((spec_entr_5++).mag(), 3.14159));
            assert(math::equal(spec_entr_5.mag(), 4.14159));
            assert(math::equal((spec_entr_5--).mag(), 4.14159));
            assert(math::equal(spec_entr_5.mag(), 3.14159));
        }

        inline void thermal_conductivity() noexcept
        {
            const si::ThermalConductivity therm_cond_0;
            assert(math::zero(therm_cond_0.mag()));

            const si::ThermalConductivity therm_cond_1{1.25};
            assert(math::equal(therm_cond_1.mag(), 1.25));

            const si::ThermalConductivity therm_cond_2{therm_cond_1 * 2.0};
            assert(math::equal(therm_cond_2.mag(), 2.5));

            const si::ThermalConductivity therm_cond_3{0.5 * therm_cond_2};
            assert(math::equal(therm_cond_3.mag(), 1.25));

            si::ThermalConductivity therm_cond_4{3.14159};
            assert(math::equal(therm_cond_4.mag(), 3.14159));
            assert(math::equal((++therm_cond_4).mag(), 4.14159));
            assert(math::equal(therm_cond_4.mag(), 4.14159));
            assert(math::equal((--therm_cond_4).mag(), 3.14159));
            assert(math::equal(therm_cond_4.mag(), 3.14159));

            si::ThermalConductivity therm_cond_5{3.14159};
            assert(math::equal(therm_cond_5.mag(), 3.14159));
            assert(math::equal((therm_cond_5++).mag(), 3.14159));
            assert(math::equal(therm_cond_5.mag(), 4.14159));
            assert(math::equal((therm_cond_5--).mag(), 4.14159));
            assert(math::equal(therm_cond_5.mag(), 3.14159));
        }

        inline void electric_field_strength() noexcept
        {
            const si::ElectricFieldStrength elec_field_stren_0;
            assert(math::zero(elec_field_stren_0.mag()));

            const si::ElectricFieldStrength elec_field_stren_1{1.25};
            assert(math::equal(elec_field_stren_1.mag(), 1.25));

            const si::ElectricFieldStrength elec_field_stren_2{elec_field_stren_1 * 2.0};
            assert(math::equal(elec_field_stren_2.mag(), 2.5));

            const si::ElectricFieldStrength elec_field_stren_3{0.5 * elec_field_stren_2};
            assert(math::equal(elec_field_stren_3.mag(), 1.25));

            si::ElectricFieldStrength elec_field_stren_4{3.14159};
            assert(math::equal(elec_field_stren_4.mag(), 3.14159));
            assert(math::equal((++elec_field_stren_4).mag(), 4.14159));
            assert(math::equal(elec_field_stren_4.mag(), 4.14159));
            assert(math::equal((--elec_field_stren_4).mag(), 3.14159));
            assert(math::equal(elec_field_stren_4.mag(), 3.14159));

            si::ElectricFieldStrength elec_field_stren_5{3.14159};
            assert(math::equal(elec_field_stren_5.mag(), 3.14159));
            assert(math::equal((elec_field_stren_5++).mag(), 3.14159));
            assert(math::equal(elec_field_stren_5.mag(), 4.14159));
            assert(math::equal((elec_field_stren_5--).mag(), 4.14159));
            assert(math::equal(elec_field_stren_5.mag(), 3.14159));
        }

        inline void electric_charge_density() noexcept
        {
            const si::ElectricChargeDensity elec_charge_dens_0;
            assert(math::zero(elec_charge_dens_0.mag()));

            const si::ElectricChargeDensity elec_charge_dens_1{1.25};
            assert(math::equal(elec_charge_dens_1.mag(), 1.25));

            const si::ElectricChargeDensity elec_charge_dens_2{elec_charge_dens_1 * 2.0};
            assert(math::equal(elec_charge_dens_2.mag(), 2.5));

            const si::ElectricChargeDensity elec_charge_dens_3{0.5 * elec_charge_dens_2};
            assert(math::equal(elec_charge_dens_3.mag(), 1.25));

            si::ElectricChargeDensity elec_charge_dens_4{3.14159};
            assert(math::equal(elec_charge_dens_4.mag(), 3.14159));
            assert(math::equal((++elec_charge_dens_4).mag(), 4.14159));
            assert(math::equal(elec_charge_dens_4.mag(), 4.14159));
            assert(math::equal((--elec_charge_dens_4).mag(), 3.14159));
            assert(math::equal(elec_charge_dens_4.mag(), 3.14159));

            si::ElectricChargeDensity elec_charge_dens_5{3.14159};
            assert(math::equal(elec_charge_dens_5.mag(), 3.14159));
            assert(math::equal((elec_charge_dens_5++).mag(), 3.14159));
            assert(math::equal(elec_charge_dens_5.mag(), 4.14159));
            assert(math::equal((elec_charge_dens_5--).mag(), 4.14159));
            assert(math::equal(elec_charge_dens_5.mag(), 3.14159));
        }

        inline void surface_charge_density() noexcept
        {
            const si::SurfaceChargeDensity surf_charge_dens_0;
            assert(math::zero(surf_charge_dens_0.mag()));

            const si::SurfaceChargeDensity surf_charge_dens_1{1.25};
            assert(math::equal(surf_charge_dens_1.mag(), 1.25));

            const si::SurfaceChargeDensity surf_charge_dens_2{surf_charge_dens_1 * 2.0};
            assert(math::equal(surf_charge_dens_2.mag(), 2.5));

            const si::SurfaceChargeDensity surf_charge_dens_3{0.5 * surf_charge_dens_2};
            assert(math::equal(surf_charge_dens_3.mag(), 1.25));

            si::SurfaceChargeDensity surf_charge_dens_4{3.14159};
            assert(math::equal(surf_charge_dens_4.mag(), 3.14159));
            assert(math::equal((++surf_charge_dens_4).mag(), 4.14159));
            assert(math::equal(surf_charge_dens_4.mag(), 4.14159));
            assert(math::equal((--surf_charge_dens_4).mag(), 3.14159));
            assert(math::equal(surf_charge_dens_4.mag(), 3.14159));

            si::SurfaceChargeDensity surf_charge_dens_5{3.14159};
            assert(math::equal(surf_charge_dens_5.mag(), 3.14159));
            assert(math::equal((surf_charge_dens_5++).mag(), 3.14159));
            assert(math::equal(surf_charge_dens_5.mag(), 4.14159));
            assert(math::equal((surf_charge_dens_5--).mag(), 4.14159));
            assert(math::equal(surf_charge_dens_5.mag(), 3.14159));
        }

        inline void electric_flux_density() noexcept
        {
            const si::ElectricFluxDensity elec_flux_dens_0;
            assert(math::zero(elec_flux_dens_0.mag()));

            const si::ElectricFluxDensity elec_flux_dens_1{1.25};
            assert(math::equal(elec_flux_dens_1.mag(), 1.25));

            const si::ElectricFluxDensity elec_flux_dens_2{elec_flux_dens_1 * 2.0};
            assert(math::equal(elec_flux_dens_2.mag(), 2.5));

            const si::ElectricFluxDensity elec_flux_dens_3{0.5 * elec_flux_dens_2};
            assert(math::equal(elec_flux_dens_3.mag(), 1.25));

            si::ElectricFluxDensity elec_flux_dens_4{3.14159};
            assert(math::equal(elec_flux_dens_4.mag(), 3.14159));
            assert(math::equal((++elec_flux_dens_4).mag(), 4.14159));
            assert(math::equal(elec_flux_dens_4.mag(), 4.14159));
            assert(math::equal((--elec_flux_dens_4).mag(), 3.14159));
            assert(math::equal(elec_flux_dens_4.mag(), 3.14159));

            si::ElectricFluxDensity elec_flux_dens_5{3.14159};
            assert(math::equal(elec_flux_dens_5.mag(), 3.14159));
            assert(math::equal((elec_flux_dens_5++).mag(), 3.14159));
            assert(math::equal(elec_flux_dens_5.mag(), 4.14159));
            assert(math::equal((elec_flux_dens_5--).mag(), 4.14159));
            assert(math::equal(elec_flux_dens_5.mag(), 3.14159));
        }

        inline void electric_displacement() noexcept
        {
            const si::ElectricDisplacement elec_dis_0;
            assert(math::zero(elec_dis_0.mag()));

            const si::ElectricDisplacement elec_dis_1{1.25};
            assert(math::equal(elec_dis_1.mag(), 1.25));

            const si::ElectricDisplacement elec_dis_2{elec_dis_1 * 2.0};
            assert(math::equal(elec_dis_2.mag(), 2.5));

            const si::ElectricDisplacement elec_dis_3{0.5 * elec_dis_2};
            assert(math::equal(elec_dis_3.mag(), 1.25));

            si::ElectricDisplacement elec_dis_4{3.14159};
            assert(math::equal(elec_dis_4.mag(), 3.14159));
            assert(math::equal((++elec_dis_4).mag(), 4.14159));
            assert(math::equal(elec_dis_4.mag(), 4.14159));
            assert(math::equal((--elec_dis_4).mag(), 3.14159));
            assert(math::equal(elec_dis_4.mag(), 3.14159));

            si::ElectricDisplacement elec_dis_5{3.14159};
            assert(math::equal(elec_dis_5.mag(), 3.14159));
            assert(math::equal((elec_dis_5++).mag(), 3.14159));
            assert(math::equal(elec_dis_5.mag(), 4.14159));
            assert(math::equal((elec_dis_5--).mag(), 4.14159));
            assert(math::equal(elec_dis_5.mag(), 3.14159));
        }

        inline void permittivity() noexcept
        {
            const si::Permittivity perm_0;
            assert(math::zero(perm_0.mag()));

            const si::Permittivity perm_1{1.25};
            assert(math::equal(perm_1.mag(), 1.25));

            const si::Permittivity perm_2{perm_1 * 2.0};
            assert(math::equal(perm_2.mag(), 2.5));

            const si::Permittivity perm_3{0.5 * perm_2};
            assert(math::equal(perm_3.mag(), 1.25));

            si::Permittivity perm_4{3.14159};
            assert(math::equal(perm_4.mag(), 3.14159));
            assert(math::equal((++perm_4).mag(), 4.14159));
            assert(math::equal(perm_4.mag(), 4.14159));
            assert(math::equal((--perm_4).mag(), 3.14159));
            assert(math::equal(perm_4.mag(), 3.14159));

            si::Permittivity perm_5{3.14159};
            assert(math::equal(perm_5.mag(), 3.14159));
            assert(math::equal((perm_5++).mag(), 3.14159));
            assert(math::equal(perm_5.mag(), 4.14159));
            assert(math::equal((perm_5--).mag(), 4.14159));
            assert(math::equal(perm_5.mag(), 3.14159));
        }

        inline void permeability() noexcept
        {
            const si::Permeability perm_0;
            assert(math::zero(perm_0.mag()));

            const si::Permeability perm_1{1.25};
            assert(math::equal(perm_1.mag(), 1.25));

            const si::Permeability perm_2{perm_1 * 2.0};
            assert(math::equal(perm_2.mag(), 2.5));

            const si::Permeability perm_3{0.5 * perm_2};
            assert(math::equal(perm_3.mag(), 1.25));

            si::Permeability perm_4{3.14159};
            assert(math::equal(perm_4.mag(), 3.14159));
            assert(math::equal((++perm_4).mag(), 4.14159));
            assert(math::equal(perm_4.mag(), 4.14159));
            assert(math::equal((--perm_4).mag(), 3.14159));
            assert(math::equal(perm_4.mag(), 3.14159));

            si::Permeability perm_5{3.14159};
            assert(math::equal(perm_5.mag(), 3.14159));
            assert(math::equal((perm_5++).mag(), 3.14159));
            assert(math::equal(perm_5.mag(), 4.14159));
            assert(math::equal((perm_5--).mag(), 4.14159));
            assert(math::equal(perm_5.mag(), 3.14159));
        }

        inline void molar_energy() noexcept
        {
            const si::MolarEnergy molar_energy_0;
            assert(math::zero(molar_energy_0.mag()));

            const si::MolarEnergy molar_energy_1{1.25};
            assert(math::equal(molar_energy_1.mag(), 1.25));

            const si::MolarEnergy molar_energy_2{molar_energy_1 * 2.0};
            assert(math::equal(molar_energy_2.mag(), 2.5));

            const si::MolarEnergy molar_energy_3{0.5 * molar_energy_2};
            assert(math::equal(molar_energy_3.mag(), 1.25));

            si::MolarEnergy molar_energy_4{3.14159};
            assert(math::equal(molar_energy_4.mag(), 3.14159));
            assert(math::equal((++molar_energy_4).mag(), 4.14159));
            assert(math::equal(molar_energy_4.mag(), 4.14159));
            assert(math::equal((--molar_energy_4).mag(), 3.14159));
            assert(math::equal(molar_energy_4.mag(), 3.14159));

            si::MolarEnergy molar_energy_5{3.14159};
            assert(math::equal(molar_energy_5.mag(), 3.14159));
            assert(math::equal((molar_energy_5++).mag(), 3.14159));
            assert(math::equal(molar_energy_5.mag(), 4.14159));
            assert(math::equal((molar_energy_5--).mag(), 4.14159));
            assert(math::equal(molar_energy_5.mag(), 3.14159));
        }

        inline void molar_entropy() noexcept
        {
            const si::MolarEntropy molar_entr_0;
            assert(math::zero(molar_entr_0.mag()));

            const si::MolarEntropy molar_entr_1{1.25};
            assert(math::equal(molar_entr_1.mag(), 1.25));

            const si::MolarEntropy molar_entr_2{molar_entr_1 * 2.0};
            assert(math::equal(molar_entr_2.mag(), 2.5));

            const si::MolarEntropy molar_entr_3{0.5 * molar_entr_2};
            assert(math::equal(molar_entr_3.mag(), 1.25));

            si::MolarEntropy molar_entr_4{3.14159};
            assert(math::equal(molar_entr_4.mag(), 3.14159));
            assert(math::equal((++molar_entr_4).mag(), 4.14159));
            assert(math::equal(molar_entr_4.mag(), 4.14159));
            assert(math::equal((--molar_entr_4).mag(), 3.14159));
            assert(math::equal(molar_entr_4.mag(), 3.14159));

            si::MolarEntropy molar_entr_5{3.14159};
            assert(math::equal(molar_entr_5.mag(), 3.14159));
            assert(math::equal((molar_entr_5++).mag(), 3.14159));
            assert(math::equal(molar_entr_5.mag(), 4.14159));
            assert(math::equal((molar_entr_5--).mag(), 4.14159));
            assert(math::equal(molar_entr_5.mag(), 3.14159));
        }

        inline void molar_heat_capacity() noexcept
        {
            const si::MolarHeatCapacity molar_heat_cap_0;
            assert(math::zero(molar_heat_cap_0.mag()));

            const si::MolarHeatCapacity molar_heat_cap_1{1.25};
            assert(math::equal(molar_heat_cap_1.mag(), 1.25));

            const si::MolarHeatCapacity molar_heat_cap_2{molar_heat_cap_1 * 2.0};
            assert(math::equal(molar_heat_cap_2.mag(), 2.5));

            const si::MolarHeatCapacity molar_heat_cap_3{0.5 * molar_heat_cap_2};
            assert(math::equal(molar_heat_cap_3.mag(), 1.25));

            si::MolarHeatCapacity molar_heat_cap_4{3.14159};
            assert(math::equal(molar_heat_cap_4.mag(), 3.14159));
            assert(math::equal((++molar_heat_cap_4).mag(), 4.14159));
            assert(math::equal(molar_heat_cap_4.mag(), 4.14159));
            assert(math::equal((--molar_heat_cap_4).mag(), 3.14159));
            assert(math::equal(molar_heat_cap_4.mag(), 3.14159));

            si::MolarHeatCapacity molar_heat_cap_5{3.14159};
            assert(math::equal(molar_heat_cap_5.mag(), 3.14159));
            assert(math::equal((molar_heat_cap_5++).mag(), 3.14159));
            assert(math::equal(molar_heat_cap_5.mag(), 4.14159));
            assert(math::equal((molar_heat_cap_5--).mag(), 4.14159));
            assert(math::equal(molar_heat_cap_5.mag(), 3.14159));
        }

        inline void exposure() noexcept
        {
            const si::Exposure expo_0;
            assert(math::zero(expo_0.mag()));

            const si::Exposure expo_1{1.25};
            assert(math::equal(expo_1.mag(), 1.25));

            const si::Exposure expo_2{expo_1 * 2.0};
            assert(math::equal(expo_2.mag(), 2.5));

            const si::Exposure expo_3{0.5 * expo_2};
            assert(math::equal(expo_3.mag(), 1.25));

            si::Exposure expo_4{3.14159};
            assert(math::equal(expo_4.mag(), 3.14159));
            assert(math::equal((++expo_4).mag(), 4.14159));
            assert(math::equal(expo_4.mag(), 4.14159));
            assert(math::equal((--expo_4).mag(), 3.14159));
            assert(math::equal(expo_4.mag(), 3.14159));

            si::Exposure expo_5{3.14159};
            assert(math::equal(expo_5.mag(), 3.14159));
            assert(math::equal((expo_5++).mag(), 3.14159));
            assert(math::equal(expo_5.mag(), 4.14159));
            assert(math::equal((expo_5--).mag(), 4.14159));
            assert(math::equal(expo_5.mag(), 3.14159));
        }

        inline void absorbed_dose_rate() noexcept
        {
            const si::AbsorbedDoseRate abs_dose_rate_0;
            assert(math::zero(abs_dose_rate_0.mag()));

            const si::AbsorbedDoseRate abs_dose_rate_1{1.25};
            assert(math::equal(abs_dose_rate_1.mag(), 1.25));

            const si::AbsorbedDoseRate abs_dose_rate_2{abs_dose_rate_1 * 2.0};
            assert(math::equal(abs_dose_rate_2.mag(), 2.5));

            const si::AbsorbedDoseRate abs_dose_rate_3{0.5 * abs_dose_rate_2};
            assert(math::equal(abs_dose_rate_3.mag(), 1.25));

            si::AbsorbedDoseRate abs_dose_rate_4{3.14159};
            assert(math::equal(abs_dose_rate_4.mag(), 3.14159));
            assert(math::equal((++abs_dose_rate_4).mag(), 4.14159));
            assert(math::equal(abs_dose_rate_4.mag(), 4.14159));
            assert(math::equal((--abs_dose_rate_4).mag(), 3.14159));
            assert(math::equal(abs_dose_rate_4.mag(), 3.14159));

            si::AbsorbedDoseRate abs_dose_rate_5{3.14159};
            assert(math::equal(abs_dose_rate_5.mag(), 3.14159));
            assert(math::equal((abs_dose_rate_5++).mag(), 3.14159));
            assert(math::equal(abs_dose_rate_5.mag(), 4.14159));
            assert(math::equal((abs_dose_rate_5--).mag(), 4.14159));
            assert(math::equal(abs_dose_rate_5.mag(), 3.14159));
        }

        inline void radiant_intensity() noexcept
        {
            const si::RadiantIntensity rad_intens_0;
            assert(math::zero(rad_intens_0.mag()));

            const si::RadiantIntensity rad_intens_1{1.25};
            assert(math::equal(rad_intens_1.mag(), 1.25));

            const si::RadiantIntensity rad_intens_2{rad_intens_1 * 2.0};
            assert(math::equal(rad_intens_2.mag(), 2.5));

            const si::RadiantIntensity rad_intens_3{0.5 * rad_intens_2};
            assert(math::equal(rad_intens_3.mag(), 1.25));

            si::RadiantIntensity rad_intens_4{3.14159};
            assert(math::equal(rad_intens_4.mag(), 3.14159));
            assert(math::equal((++rad_intens_4).mag(), 4.14159));
            assert(math::equal(rad_intens_4.mag(), 4.14159));
            assert(math::equal((--rad_intens_4).mag(), 3.14159));
            assert(math::equal(rad_intens_4.mag(), 3.14159));

            si::RadiantIntensity rad_intens_5{3.14159};
            assert(math::equal(rad_intens_5.mag(), 3.14159));
            assert(math::equal((rad_intens_5++).mag(), 3.14159));
            assert(math::equal(rad_intens_5.mag(), 4.14159));
            assert(math::equal((rad_intens_5--).mag(), 4.14159));
            assert(math::equal(rad_intens_5.mag(), 3.14159));
        }

        inline void radiance() noexcept
        {
            const si::Radiance rad_0;
            assert(math::zero(rad_0.mag()));

            const si::Radiance rad_1{1.25};
            assert(math::equal(rad_1.mag(), 1.25));

            const si::Radiance rad_2{rad_1 * 2.0};
            assert(math::equal(rad_2.mag(), 2.5));

            const si::Radiance rad_3{0.5 * rad_2};
            assert(math::equal(rad_3.mag(), 1.25));

            si::Radiance rad_4{3.14159};
            assert(math::equal(rad_4.mag(), 3.14159));
            assert(math::equal((++rad_4).mag(), 4.14159));
            assert(math::equal(rad_4.mag(), 4.14159));
            assert(math::equal((--rad_4).mag(), 3.14159));
            assert(math::equal(rad_4.mag(), 3.14159));

            si::Radiance rad_5{3.14159};
            assert(math::equal(rad_5.mag(), 3.14159));
            assert(math::equal((rad_5++).mag(), 3.14159));
            assert(math::equal(rad_5.mag(), 4.14159));
            assert(math::equal((rad_5--).mag(), 4.14159));
            assert(math::equal(rad_5.mag(), 3.14159));
        }

        inline void cat_act_concentration() noexcept
        {
            const si::CatalyticActivityConcentration cat_act_conc_0;
            assert(math::zero(cat_act_conc_0.mag()));

            const si::CatalyticActivityConcentration cat_act_conc_1{1.25};
            assert(math::equal(cat_act_conc_1.mag(), 1.25));

            const si::CatalyticActivityConcentration cat_act_conc_2{cat_act_conc_1 * 2.0};
            assert(math::equal(cat_act_conc_2.mag(), 2.5));

            const si::CatalyticActivityConcentration cat_act_conc_3{0.5 * cat_act_conc_2};
            assert(math::equal(cat_act_conc_3.mag(), 1.25));

            si::CatalyticActivityConcentration cat_act_conc_4{3.14159};
            assert(math::equal(cat_act_conc_4.mag(), 3.14159));
            assert(math::equal((++cat_act_conc_4).mag(), 4.14159));
            assert(math::equal(cat_act_conc_4.mag(), 4.14159));
            assert(math::equal((--cat_act_conc_4).mag(), 3.14159));
            assert(math::equal(cat_act_conc_4.mag(), 3.14159));

            si::CatalyticActivityConcentration cat_act_conc_5{3.14159};
            assert(math::equal(cat_act_conc_5.mag(), 3.14159));
            assert(math::equal((cat_act_conc_5++).mag(), 3.14159));
            assert(math::equal(cat_act_conc_5.mag(), 4.14159));
            assert(math::equal((cat_act_conc_5--).mag(), 4.14159));
            assert(math::equal(cat_act_conc_5.mag(), 3.14159));
        }

        inline void action() noexcept
        {
            const si::Action act_0;
            assert(math::zero(act_0.mag()));

            const si::Action act_1{1.25};
            assert(math::equal(act_1.mag(), 1.25));

            const si::Action act_2{act_1 * 2.0};
            assert(math::equal(act_2.mag(), 2.5));

            const si::Action act_3{0.5 * act_2};
            assert(math::equal(act_3.mag(), 1.25));

            si::Action act_4{3.14159};
            assert(math::equal(act_4.mag(), 3.14159));
            assert(math::equal((++act_4).mag(), 4.14159));
            assert(math::equal(act_4.mag(), 4.14159));
            assert(math::equal((--act_4).mag(), 3.14159));
            assert(math::equal(act_4.mag(), 3.14159));

            si::Action act_5{3.14159};
            assert(math::equal(act_5.mag(), 3.14159));
            assert(math::equal((act_5++).mag(), 3.14159));
            assert(math::equal(act_5.mag(), 4.14159));
            assert(math::equal((act_5--).mag(), 4.14159));
            assert(math::equal(act_5.mag(), 3.14159));
        }



    } // namespace test
} // namespace arc
