//  == IMPORTS ==
//  -- Arc --
#include <arctk/math/compare.inl>
#include <arctk/si/units.inl>

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
        inline void frequency() noexcept;
        inline void force() noexcept;
        inline void pressure() noexcept;
        inline void energy() noexcept;
        inline void power() noexcept;
        inline void charge() noexcept;
        inline void potential() noexcept;
        inline void capacitance() noexcept;
        inline void resistance() noexcept;
        inline void conductance() noexcept;
        inline void magnetic_flux() noexcept;
        inline void magnetic_flux_density() noexcept;
        inline void inductance() noexcept;
        inline void absorbed_dose() noexcept;
        inline void catalytic_activity() noexcept;



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
    arc::test::frequency();
    arc::test::force();
    arc::test::pressure();
    arc::test::energy();
    arc::test::power();
    arc::test::charge();
    arc::test::potential();
    arc::test::capacitance();
    arc::test::resistance();
    arc::test::conductance();
    arc::test::magnetic_flux();
    arc::test::magnetic_flux_density();
    arc::test::inductance();
    arc::test::absorbed_dose();
    arc::test::catalytic_activity();

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
            assert(math::equal((1.0_pi).mag(), 3.14159, 1.0e-6));
        }

        inline void mass() noexcept
        {
            assert(math::equal((1.0_Ykg).mag(), 1.0e24));
            assert(math::equal(si::to_Ykg(1.0_kg), 1.0e-24));

            assert(math::equal((1.0_Zkg).mag(), 1.0e21));
            assert(math::equal(si::to_Zkg(1.0_kg), 1.0e-21));

            assert(math::equal((1.0_Ekg).mag(), 1.0e18));
            assert(math::equal(si::to_Ekg(1.0_kg), 1.0e-18));

            assert(math::equal((1.0_Pkg).mag(), 1.0e15));
            assert(math::equal(si::to_Pkg(1.0_kg), 1.0e-15));

            assert(math::equal((1.0_Tkg).mag(), 1.0e12));
            assert(math::equal(si::to_Tkg(1.0_kg), 1.0e-12));

            assert(math::equal((1.0_Gkg).mag(), 1.0e9));
            assert(math::equal(si::to_Gkg(1.0_kg), 1.0e-9));

            assert(math::equal((1.0_Mkg).mag(), 1.0e6));
            assert(math::equal(si::to_Mkg(1.0_kg), 1.0e-6));

            assert(math::equal((1.0_kkg).mag(), 1.0e3));
            assert(math::equal(si::to_kkg(1.0_kg), 1.0e-3));

            assert(math::equal((1.0_hkg).mag(), 1.0e2));
            assert(math::equal(si::to_hkg(1.0_kg), 1.0e-2));

            assert(math::equal((1.0_dakg).mag(), 1.0e1));
            assert(math::equal(si::to_dakg(1.0_kg), 1.0e-1));

            assert(math::equal((1.0_kg).mag(), 1.0));
            assert(math::equal(si::to_kg(1.0_kg), 1.0));

            assert(math::equal((1.0_dkg).mag(), 1.0e-1));
            assert(math::equal(si::to_dkg(1.0_kg), 1.0e1));

            assert(math::equal((1.0_ckg).mag(), 1.0e-2));
            assert(math::equal(si::to_ckg(1.0_kg), 1.0e2));

            assert(math::equal((1.0_mkg).mag(), 1.0e-3));
            assert(math::equal(si::to_mkg(1.0_kg), 1.0e3));

            assert(math::equal((1.0_ukg).mag(), 1.0e-6));
            assert(math::equal(si::to_ukg(1.0_kg), 1.0e6));

            assert(math::equal((1.0_nkg).mag(), 1.0e-9));
            assert(math::equal(si::to_nkg(1.0_kg), 1.0e9));

            assert(math::equal((1.0_pkg).mag(), 1.0e-12));
            assert(math::equal(si::to_pkg(1.0_kg), 1.0e12));

            assert(math::equal((1.0_fkg).mag(), 1.0e-15));
            assert(math::equal(si::to_fkg(1.0_kg), 1.0e15));

            assert(math::equal((1.0_akg).mag(), 1.0e-18));
            assert(math::equal(si::to_akg(1.0_kg), 1.0e18));

            assert(math::equal((1.0_zkg).mag(), 1.0e-21));
            assert(math::equal(si::to_zkg(1.0_kg), 1.0e21));

            assert(math::equal((1.0_ykg).mag(), 1.0e-24));
            assert(math::equal(si::to_ykg(1.0_kg), 1.0e24));

            assert(math::equal((1.0_oz).mag(), 0.0283495));
            assert(math::equal(si::to_oz(1.0_kg), 1.0 / 0.0283495));

            assert(math::equal((1.0_lb).mag(), 0.453592));
            assert(math::equal(si::to_lb(1.0_kg), 1.0 / 0.453592));

            assert(math::equal((1.0_st).mag(), 6.35029));
            assert(math::equal(si::to_st(1.0_kg), 1.0 / 6.35029));
        }

        inline void length() noexcept
        {
            assert(math::equal((1.0_Ym).mag(), 1.0e24));
            assert(math::equal(si::to_Ym(1.0_m), 1.0e-24));

            assert(math::equal((1.0_Zm).mag(), 1.0e21));
            assert(math::equal(si::to_Zm(1.0_m), 1.0e-21));

            assert(math::equal((1.0_Em).mag(), 1.0e18));
            assert(math::equal(si::to_Em(1.0_m), 1.0e-18));

            assert(math::equal((1.0_Pm).mag(), 1.0e15));
            assert(math::equal(si::to_Pm(1.0_m), 1.0e-15));

            assert(math::equal((1.0_Tm).mag(), 1.0e12));
            assert(math::equal(si::to_Tm(1.0_m), 1.0e-12));

            assert(math::equal((1.0_Gm).mag(), 1.0e9));
            assert(math::equal(si::to_Gm(1.0_m), 1.0e-9));

            assert(math::equal((1.0_Mm).mag(), 1.0e6));
            assert(math::equal(si::to_Mm(1.0_m), 1.0e-6));

            assert(math::equal((1.0_km).mag(), 1.0e3));
            assert(math::equal(si::to_km(1.0_m), 1.0e-3));

            assert(math::equal((1.0_hm).mag(), 1.0e2));
            assert(math::equal(si::to_hm(1.0_m), 1.0e-2));

            assert(math::equal((1.0_dam).mag(), 1.0e1));
            assert(math::equal(si::to_dam(1.0_m), 1.0e-1));

            assert(math::equal((1.0_m).mag(), 1.0));
            assert(math::equal(si::to_m(1.0_m), 1.0));

            assert(math::equal((1.0_dm).mag(), 1.0e-1));
            assert(math::equal(si::to_dm(1.0_m), 1.0e1));

            assert(math::equal((1.0_cm).mag(), 1.0e-2));
            assert(math::equal(si::to_cm(1.0_m), 1.0e2));

            assert(math::equal((1.0_mm).mag(), 1.0e-3));
            assert(math::equal(si::to_mm(1.0_m), 1.0e3));

            assert(math::equal((1.0_um).mag(), 1.0e-6));
            assert(math::equal(si::to_um(1.0_m), 1.0e6));

            assert(math::equal((1.0_nm).mag(), 1.0e-9));
            assert(math::equal(si::to_nm(1.0_m), 1.0e9));

            assert(math::equal((1.0_pm).mag(), 1.0e-12));
            assert(math::equal(si::to_pm(1.0_m), 1.0e12));

            assert(math::equal((1.0_fm).mag(), 1.0e-15));
            assert(math::equal(si::to_fm(1.0_m), 1.0e15));

            assert(math::equal((1.0_am).mag(), 1.0e-18));
            assert(math::equal(si::to_am(1.0_m), 1.0e18));

            assert(math::equal((1.0_zm).mag(), 1.0e-21));
            assert(math::equal(si::to_zm(1.0_m), 1.0e21));

            assert(math::equal((1.0_ym).mag(), 1.0e-24));
            assert(math::equal(si::to_ym(1.0_m), 1.0e24));

            assert(math::equal((1.0_in).mag(), 0.0254));
            assert(math::equal(si::to_in(1.0_m), 1.0 / 0.0254));

            assert(math::equal((1.0_ft).mag(), 0.3048));
            assert(math::equal(si::to_ft(1.0_m), 1.0 / 0.3048));

            assert(math::equal((1.0_yd).mag(), 0.9144));
            assert(math::equal(si::to_yd(1.0_m), 1.0 / 0.9144));

            assert(math::equal((1.0_mi).mag(), 1609.34));
            assert(math::equal(si::to_mi(1.0_m), 1.0 / 1609.34));

            assert(math::equal((1.0_nmi).mag(), 1852.0));
            assert(math::equal(si::to_nmi(1.0_m), 1.0 / 1852.0));
        }

        inline void time() noexcept
        {
            assert(math::equal((1.0_Ys).mag(), 1.0e24));
            assert(math::equal(si::to_Ys(1.0_s), 1.0e-24));

            assert(math::equal((1.0_Zs).mag(), 1.0e21));
            assert(math::equal(si::to_Zs(1.0_s), 1.0e-21));

            assert(math::equal((1.0_Es).mag(), 1.0e18));
            assert(math::equal(si::to_Es(1.0_s), 1.0e-18));

            assert(math::equal((1.0_Ps).mag(), 1.0e15));
            assert(math::equal(si::to_Ps(1.0_s), 1.0e-15));

            assert(math::equal((1.0_Ts).mag(), 1.0e12));
            assert(math::equal(si::to_Ts(1.0_s), 1.0e-12));

            assert(math::equal((1.0_Gs).mag(), 1.0e9));
            assert(math::equal(si::to_Gs(1.0_s), 1.0e-9));

            assert(math::equal((1.0_Ms).mag(), 1.0e6));
            assert(math::equal(si::to_Ms(1.0_s), 1.0e-6));

            assert(math::equal((1.0_ks).mag(), 1.0e3));
            assert(math::equal(si::to_ks(1.0_s), 1.0e-3));

            assert(math::equal((1.0_hs).mag(), 1.0e2));
            assert(math::equal(si::to_hs(1.0_s), 1.0e-2));

            assert(math::equal((1.0_das).mag(), 1.0e1));
            assert(math::equal(si::to_das(1.0_s), 1.0e-1));

            assert(math::equal((1.0_s).mag(), 1.0));
            assert(math::equal(si::to_s(1.0_s), 1.0));

            assert(math::equal((1.0_ds).mag(), 1.0e-1));
            assert(math::equal(si::to_ds(1.0_s), 1.0e1));

            assert(math::equal((1.0_cs).mag(), 1.0e-2));
            assert(math::equal(si::to_cs(1.0_s), 1.0e2));

            assert(math::equal((1.0_ms).mag(), 1.0e-3));
            assert(math::equal(si::to_ms(1.0_s), 1.0e3));

            assert(math::equal((1.0_us).mag(), 1.0e-6));
            assert(math::equal(si::to_us(1.0_s), 1.0e6));

            assert(math::equal((1.0_ns).mag(), 1.0e-9));
            assert(math::equal(si::to_ns(1.0_s), 1.0e9));

            assert(math::equal((1.0_ps).mag(), 1.0e-12));
            assert(math::equal(si::to_ps(1.0_s), 1.0e12));

            assert(math::equal((1.0_fs).mag(), 1.0e-15));
            assert(math::equal(si::to_fs(1.0_s), 1.0e15));

            assert(math::equal((1.0_as).mag(), 1.0e-18));
            assert(math::equal(si::to_as(1.0_s), 1.0e18));

            assert(math::equal((1.0_zs).mag(), 1.0e-21));
            assert(math::equal(si::to_zs(1.0_s), 1.0e21));

            assert(math::equal((1.0_ys).mag(), 1.0e-24));
            assert(math::equal(si::to_ys(1.0_s), 1.0e24));

            assert(math::equal((1.0_min).mag(), 60.0));
            assert(math::equal(si::to_min(1.0_s), 1.0 / 60.0));

            assert(math::equal((1.0_hr).mag(), 3600.0));
            assert(math::equal(si::to_hr(1.0_s), 1.0 / 3600.0));

            assert(math::equal((1.0_day).mag(), 86400.0));
            assert(math::equal(si::to_day(1.0_s), 1.0 / 86400.0));

            assert(math::equal((1.0_week).mag(), 604800.0));
            assert(math::equal(si::to_week(1.0_s), 1.0 / 604800.0));

            assert(math::equal((1.0_month).mag(), 2.628e6));
            assert(math::equal(si::to_month(1.0_s), 1.0 / 2.628e6));

            assert(math::equal((1.0_yr).mag(), 3.154e7));
            assert(math::equal(si::to_yr(1.0_s), 1.0 / 3.154e7));

            assert(math::equal((1.0_decade).mag(), 3.154e8));
            assert(math::equal(si::to_decade(1.0_s), 1.0 / 3.154e8));

            assert(math::equal((1.0_century).mag(), 3.154e9));
            assert(math::equal(si::to_century(1.0_s), 1.0 / 3.154e9));
        }

        inline void temperature() noexcept
        {
            assert(math::equal((1.0_YK).mag(), 1.0e24));
            assert(math::equal(si::to_YK(1.0_K), 1.0e-24));

            assert(math::equal((1.0_ZK).mag(), 1.0e21));
            assert(math::equal(si::to_ZK(1.0_K), 1.0e-21));

            assert(math::equal((1.0_EK).mag(), 1.0e18));
            assert(math::equal(si::to_EK(1.0_K), 1.0e-18));

            assert(math::equal((1.0_PK).mag(), 1.0e15));
            assert(math::equal(si::to_PK(1.0_K), 1.0e-15));

            assert(math::equal((1.0_TK).mag(), 1.0e12));
            assert(math::equal(si::to_TK(1.0_K), 1.0e-12));

            assert(math::equal((1.0_GK).mag(), 1.0e9));
            assert(math::equal(si::to_GK(1.0_K), 1.0e-9));

            assert(math::equal((1.0_MK).mag(), 1.0e6));
            assert(math::equal(si::to_MK(1.0_K), 1.0e-6));

            assert(math::equal((1.0_kK).mag(), 1.0e3));
            assert(math::equal(si::to_kK(1.0_K), 1.0e-3));

            assert(math::equal((1.0_hK).mag(), 1.0e2));
            assert(math::equal(si::to_hK(1.0_K), 1.0e-2));

            assert(math::equal((1.0_daK).mag(), 1.0e1));
            assert(math::equal(si::to_daK(1.0_K), 1.0e-1));

            assert(math::equal((1.0_K).mag(), 1.0));
            assert(math::equal(si::to_K(1.0_K), 1.0));

            assert(math::equal((1.0_dK).mag(), 1.0e-1));
            assert(math::equal(si::to_dK(1.0_K), 1.0e1));

            assert(math::equal((1.0_cK).mag(), 1.0e-2));
            assert(math::equal(si::to_cK(1.0_K), 1.0e2));

            assert(math::equal((1.0_mK).mag(), 1.0e-3));
            assert(math::equal(si::to_mK(1.0_K), 1.0e3));

            assert(math::equal((1.0_uK).mag(), 1.0e-6));
            assert(math::equal(si::to_uK(1.0_K), 1.0e6));

            assert(math::equal((1.0_nK).mag(), 1.0e-9));
            assert(math::equal(si::to_nK(1.0_K), 1.0e9));

            assert(math::equal((1.0_pK).mag(), 1.0e-12));
            assert(math::equal(si::to_pK(1.0_K), 1.0e12));

            assert(math::equal((1.0_fK).mag(), 1.0e-15));
            assert(math::equal(si::to_fK(1.0_K), 1.0e15));

            assert(math::equal((1.0_aK).mag(), 1.0e-18));
            assert(math::equal(si::to_aK(1.0_K), 1.0e18));

            assert(math::equal((1.0_zK).mag(), 1.0e-21));
            assert(math::equal(si::to_zK(1.0_K), 1.0e21));

            assert(math::equal((1.0_yK).mag(), 1.0e-24));
            assert(math::equal(si::to_yK(1.0_K), 1.0e24));

            assert(math::equal((1.0_oC).mag(), 274.15));
            assert(math::equal(si::to_oC(1.0_K), -272.15));

            assert(math::equal((1.0_oF).mag(), 255.927778, 1.0e-6));
            assert(math::equal(si::to_oF(1.0_K), -457.87));
        }

        inline void current() noexcept
        {
            assert(math::equal((1.0_YA).mag(), 1.0e24));
            assert(math::equal(si::to_YA(1.0_A), 1.0e-24));

            assert(math::equal((1.0_ZA).mag(), 1.0e21));
            assert(math::equal(si::to_ZA(1.0_A), 1.0e-21));

            assert(math::equal((1.0_EA).mag(), 1.0e18));
            assert(math::equal(si::to_EA(1.0_A), 1.0e-18));

            assert(math::equal((1.0_PA).mag(), 1.0e15));
            assert(math::equal(si::to_PA(1.0_A), 1.0e-15));

            assert(math::equal((1.0_TA).mag(), 1.0e12));
            assert(math::equal(si::to_TA(1.0_A), 1.0e-12));

            assert(math::equal((1.0_GA).mag(), 1.0e9));
            assert(math::equal(si::to_GA(1.0_A), 1.0e-9));

            assert(math::equal((1.0_MA).mag(), 1.0e6));
            assert(math::equal(si::to_MA(1.0_A), 1.0e-6));

            assert(math::equal((1.0_kA).mag(), 1.0e3));
            assert(math::equal(si::to_kA(1.0_A), 1.0e-3));

            assert(math::equal((1.0_hA).mag(), 1.0e2));
            assert(math::equal(si::to_hA(1.0_A), 1.0e-2));

            assert(math::equal((1.0_daA).mag(), 1.0e1));
            assert(math::equal(si::to_daA(1.0_A), 1.0e-1));

            assert(math::equal((1.0_A).mag(), 1.0));
            assert(math::equal(si::to_A(1.0_A), 1.0));

            assert(math::equal((1.0_dA).mag(), 1.0e-1));
            assert(math::equal(si::to_dA(1.0_A), 1.0e1));

            assert(math::equal((1.0_cA).mag(), 1.0e-2));
            assert(math::equal(si::to_cA(1.0_A), 1.0e2));

            assert(math::equal((1.0_mA).mag(), 1.0e-3));
            assert(math::equal(si::to_mA(1.0_A), 1.0e3));

            assert(math::equal((1.0_uA).mag(), 1.0e-6));
            assert(math::equal(si::to_uA(1.0_A), 1.0e6));

            assert(math::equal((1.0_nA).mag(), 1.0e-9));
            assert(math::equal(si::to_nA(1.0_A), 1.0e9));

            assert(math::equal((1.0_pA).mag(), 1.0e-12));
            assert(math::equal(si::to_pA(1.0_A), 1.0e12));

            assert(math::equal((1.0_fA).mag(), 1.0e-15));
            assert(math::equal(si::to_fA(1.0_A), 1.0e15));

            assert(math::equal((1.0_aA).mag(), 1.0e-18));
            assert(math::equal(si::to_aA(1.0_A), 1.0e18));

            assert(math::equal((1.0_zA).mag(), 1.0e-21));
            assert(math::equal(si::to_zA(1.0_A), 1.0e21));

            assert(math::equal((1.0_yA).mag(), 1.0e-24));
            assert(math::equal(si::to_yA(1.0_A), 1.0e24));
        }

        inline void intensity() noexcept
        {
            assert(math::equal((1.0_Ycd).mag(), 1.0e24));
            assert(math::equal(si::to_Ycd(1.0_cd), 1.0e-24));

            assert(math::equal((1.0_Zcd).mag(), 1.0e21));
            assert(math::equal(si::to_Zcd(1.0_cd), 1.0e-21));

            assert(math::equal((1.0_Ecd).mag(), 1.0e18));
            assert(math::equal(si::to_Ecd(1.0_cd), 1.0e-18));

            assert(math::equal((1.0_Pcd).mag(), 1.0e15));
            assert(math::equal(si::to_Pcd(1.0_cd), 1.0e-15));

            assert(math::equal((1.0_Tcd).mag(), 1.0e12));
            assert(math::equal(si::to_Tcd(1.0_cd), 1.0e-12));

            assert(math::equal((1.0_Gcd).mag(), 1.0e9));
            assert(math::equal(si::to_Gcd(1.0_cd), 1.0e-9));

            assert(math::equal((1.0_Mcd).mag(), 1.0e6));
            assert(math::equal(si::to_Mcd(1.0_cd), 1.0e-6));

            assert(math::equal((1.0_kcd).mag(), 1.0e3));
            assert(math::equal(si::to_kcd(1.0_cd), 1.0e-3));

            assert(math::equal((1.0_hcd).mag(), 1.0e2));
            assert(math::equal(si::to_hcd(1.0_cd), 1.0e-2));

            assert(math::equal((1.0_dacd).mag(), 1.0e1));
            assert(math::equal(si::to_dacd(1.0_cd), 1.0e-1));

            assert(math::equal((1.0_cd).mag(), 1.0));
            assert(math::equal(si::to_cd(1.0_cd), 1.0));

            assert(math::equal((1.0_dcd).mag(), 1.0e-1));
            assert(math::equal(si::to_dcd(1.0_cd), 1.0e1));

            assert(math::equal((1.0_ccd).mag(), 1.0e-2));
            assert(math::equal(si::to_ccd(1.0_cd), 1.0e2));

            assert(math::equal((1.0_mcd).mag(), 1.0e-3));
            assert(math::equal(si::to_mcd(1.0_cd), 1.0e3));

            assert(math::equal((1.0_ucd).mag(), 1.0e-6));
            assert(math::equal(si::to_ucd(1.0_cd), 1.0e6));

            assert(math::equal((1.0_ncd).mag(), 1.0e-9));
            assert(math::equal(si::to_ncd(1.0_cd), 1.0e9));

            assert(math::equal((1.0_pcd).mag(), 1.0e-12));
            assert(math::equal(si::to_pcd(1.0_cd), 1.0e12));

            assert(math::equal((1.0_fcd).mag(), 1.0e-15));
            assert(math::equal(si::to_fcd(1.0_cd), 1.0e15));

            assert(math::equal((1.0_acd).mag(), 1.0e-18));
            assert(math::equal(si::to_acd(1.0_cd), 1.0e18));

            assert(math::equal((1.0_zcd).mag(), 1.0e-21));
            assert(math::equal(si::to_zcd(1.0_cd), 1.0e21));

            assert(math::equal((1.0_ycd).mag(), 1.0e-24));
            assert(math::equal(si::to_ycd(1.0_cd), 1.0e24));
        }

        inline void amount() noexcept
        {
            assert(math::equal((1.0_Ymol).mag(), 1.0e24));
            assert(math::equal(si::to_Ymol(1.0_mol), 1.0e-24));

            assert(math::equal((1.0_Zmol).mag(), 1.0e21));
            assert(math::equal(si::to_Zmol(1.0_mol), 1.0e-21));

            assert(math::equal((1.0_Emol).mag(), 1.0e18));
            assert(math::equal(si::to_Emol(1.0_mol), 1.0e-18));

            assert(math::equal((1.0_Pmol).mag(), 1.0e15));
            assert(math::equal(si::to_Pmol(1.0_mol), 1.0e-15));

            assert(math::equal((1.0_Tmol).mag(), 1.0e12));
            assert(math::equal(si::to_Tmol(1.0_mol), 1.0e-12));

            assert(math::equal((1.0_Gmol).mag(), 1.0e9));
            assert(math::equal(si::to_Gmol(1.0_mol), 1.0e-9));

            assert(math::equal((1.0_Mmol).mag(), 1.0e6));
            assert(math::equal(si::to_Mmol(1.0_mol), 1.0e-6));

            assert(math::equal((1.0_kmol).mag(), 1.0e3));
            assert(math::equal(si::to_kmol(1.0_mol), 1.0e-3));

            assert(math::equal((1.0_hmol).mag(), 1.0e2));
            assert(math::equal(si::to_hmol(1.0_mol), 1.0e-2));

            assert(math::equal((1.0_damol).mag(), 1.0e1));
            assert(math::equal(si::to_damol(1.0_mol), 1.0e-1));

            assert(math::equal((1.0_mol).mag(), 1.0));
            assert(math::equal(si::to_mol(1.0_mol), 1.0));

            assert(math::equal((1.0_dmol).mag(), 1.0e-1));
            assert(math::equal(si::to_dmol(1.0_mol), 1.0e1));

            assert(math::equal((1.0_cmol).mag(), 1.0e-2));
            assert(math::equal(si::to_cmol(1.0_mol), 1.0e2));

            assert(math::equal((1.0_mmol).mag(), 1.0e-3));
            assert(math::equal(si::to_mmol(1.0_mol), 1.0e3));

            assert(math::equal((1.0_umol).mag(), 1.0e-6));
            assert(math::equal(si::to_umol(1.0_mol), 1.0e6));

            assert(math::equal((1.0_nmol).mag(), 1.0e-9));
            assert(math::equal(si::to_nmol(1.0_mol), 1.0e9));

            assert(math::equal((1.0_pmol).mag(), 1.0e-12));
            assert(math::equal(si::to_pmol(1.0_mol), 1.0e12));

            assert(math::equal((1.0_fmol).mag(), 1.0e-15));
            assert(math::equal(si::to_fmol(1.0_mol), 1.0e15));

            assert(math::equal((1.0_amol).mag(), 1.0e-18));
            assert(math::equal(si::to_amol(1.0_mol), 1.0e18));

            assert(math::equal((1.0_zmol).mag(), 1.0e-21));
            assert(math::equal(si::to_zmol(1.0_mol), 1.0e21));

            assert(math::equal((1.0_ymol).mag(), 1.0e-24));
            assert(math::equal(si::to_ymol(1.0_mol), 1.0e24));
        }

        inline void angle() noexcept
        {
            assert(math::equal((1.0_Yrad).mag(), 1.0e24));
            assert(math::equal(si::to_Yrad(1.0_rad), 1.0e-24));

            assert(math::equal((1.0_Zrad).mag(), 1.0e21));
            assert(math::equal(si::to_Zrad(1.0_rad), 1.0e-21));

            assert(math::equal((1.0_Erad).mag(), 1.0e18));
            assert(math::equal(si::to_Erad(1.0_rad), 1.0e-18));

            assert(math::equal((1.0_Prad).mag(), 1.0e15));
            assert(math::equal(si::to_Prad(1.0_rad), 1.0e-15));

            assert(math::equal((1.0_Trad).mag(), 1.0e12));
            assert(math::equal(si::to_Trad(1.0_rad), 1.0e-12));

            assert(math::equal((1.0_Grad).mag(), 1.0e9));
            assert(math::equal(si::to_Grad(1.0_rad), 1.0e-9));

            assert(math::equal((1.0_Mrad).mag(), 1.0e6));
            assert(math::equal(si::to_Mrad(1.0_rad), 1.0e-6));

            assert(math::equal((1.0_krad).mag(), 1.0e3));
            assert(math::equal(si::to_krad(1.0_rad), 1.0e-3));

            assert(math::equal((1.0_hrad).mag(), 1.0e2));
            assert(math::equal(si::to_hrad(1.0_rad), 1.0e-2));

            assert(math::equal((1.0_darad).mag(), 1.0e1));
            assert(math::equal(si::to_darad(1.0_rad), 1.0e-1));

            assert(math::equal((1.0_rad).mag(), 1.0));
            assert(math::equal(si::to_rad(1.0_rad), 1.0));

            assert(math::equal((1.0_drad).mag(), 1.0e-1));
            assert(math::equal(si::to_drad(1.0_rad), 1.0e1));

            assert(math::equal((1.0_crad).mag(), 1.0e-2));
            assert(math::equal(si::to_crad(1.0_rad), 1.0e2));

            assert(math::equal((1.0_mrad).mag(), 1.0e-3));
            assert(math::equal(si::to_mrad(1.0_rad), 1.0e3));

            assert(math::equal((1.0_urad).mag(), 1.0e-6));
            assert(math::equal(si::to_urad(1.0_rad), 1.0e6));

            assert(math::equal((1.0_nrad).mag(), 1.0e-9));
            assert(math::equal(si::to_nrad(1.0_rad), 1.0e9));

            assert(math::equal((1.0_prad).mag(), 1.0e-12));
            assert(math::equal(si::to_prad(1.0_rad), 1.0e12));

            assert(math::equal((1.0_frad).mag(), 1.0e-15));
            assert(math::equal(si::to_frad(1.0_rad), 1.0e15));

            assert(math::equal((1.0_arad).mag(), 1.0e-18));
            assert(math::equal(si::to_arad(1.0_rad), 1.0e18));

            assert(math::equal((1.0_zrad).mag(), 1.0e-21));
            assert(math::equal(si::to_zrad(1.0_rad), 1.0e21));

            assert(math::equal((1.0_yrad).mag(), 1.0e-24));
            assert(math::equal(si::to_yrad(1.0_rad), 1.0e24));

            assert(math::equal((1.0_deg).mag(), (180.0 / 1.0_pi).mag()));
            assert(math::equal(si::to_deg(1.0_rad), (1.0_pi / 180.0).mag()));
        }

        inline void solid_angle() noexcept
        {
            assert(math::equal((1.0_Ysr).mag(), 1.0e24));
            assert(math::equal(si::to_Ysr(1.0_sr), 1.0e-24));

            assert(math::equal((1.0_Zsr).mag(), 1.0e21));
            assert(math::equal(si::to_Zsr(1.0_sr), 1.0e-21));

            assert(math::equal((1.0_Esr).mag(), 1.0e18));
            assert(math::equal(si::to_Esr(1.0_sr), 1.0e-18));

            assert(math::equal((1.0_Psr).mag(), 1.0e15));
            assert(math::equal(si::to_Psr(1.0_sr), 1.0e-15));

            assert(math::equal((1.0_Tsr).mag(), 1.0e12));
            assert(math::equal(si::to_Tsr(1.0_sr), 1.0e-12));

            assert(math::equal((1.0_Gsr).mag(), 1.0e9));
            assert(math::equal(si::to_Gsr(1.0_sr), 1.0e-9));

            assert(math::equal((1.0_Msr).mag(), 1.0e6));
            assert(math::equal(si::to_Msr(1.0_sr), 1.0e-6));

            assert(math::equal((1.0_ksr).mag(), 1.0e3));
            assert(math::equal(si::to_ksr(1.0_sr), 1.0e-3));

            assert(math::equal((1.0_hsr).mag(), 1.0e2));
            assert(math::equal(si::to_hsr(1.0_sr), 1.0e-2));

            assert(math::equal((1.0_dasr).mag(), 1.0e1));
            assert(math::equal(si::to_dasr(1.0_sr), 1.0e-1));

            assert(math::equal((1.0_sr).mag(), 1.0));
            assert(math::equal(si::to_sr(1.0_sr), 1.0));

            assert(math::equal((1.0_dsr).mag(), 1.0e-1));
            assert(math::equal(si::to_dsr(1.0_sr), 1.0e1));

            assert(math::equal((1.0_csr).mag(), 1.0e-2));
            assert(math::equal(si::to_csr(1.0_sr), 1.0e2));

            assert(math::equal((1.0_msr).mag(), 1.0e-3));
            assert(math::equal(si::to_msr(1.0_sr), 1.0e3));

            assert(math::equal((1.0_usr).mag(), 1.0e-6));
            assert(math::equal(si::to_usr(1.0_sr), 1.0e6));

            assert(math::equal((1.0_nsr).mag(), 1.0e-9));
            assert(math::equal(si::to_nsr(1.0_sr), 1.0e9));

            assert(math::equal((1.0_psr).mag(), 1.0e-12));
            assert(math::equal(si::to_psr(1.0_sr), 1.0e12));

            assert(math::equal((1.0_fsr).mag(), 1.0e-15));
            assert(math::equal(si::to_fsr(1.0_sr), 1.0e15));

            assert(math::equal((1.0_asr).mag(), 1.0e-18));
            assert(math::equal(si::to_asr(1.0_sr), 1.0e18));

            assert(math::equal((1.0_zsr).mag(), 1.0e-21));
            assert(math::equal(si::to_zsr(1.0_sr), 1.0e21));

            assert(math::equal((1.0_ysr).mag(), 1.0e-24));
            assert(math::equal(si::to_ysr(1.0_sr), 1.0e24));
        }

        inline void area() noexcept
        {
            assert(math::equal((1.0_Ym2).mag(), 1.0e48));
            assert(math::equal(si::to_Ym2(1.0_m2), 1.0e-48));

            assert(math::equal((1.0_Zm2).mag(), 1.0e42));
            assert(math::equal(si::to_Zm2(1.0_m2), 1.0e-42));

            assert(math::equal((1.0_Em2).mag(), 1.0e36));
            assert(math::equal(si::to_Em2(1.0_m2), 1.0e-36));

            assert(math::equal((1.0_Pm2).mag(), 1.0e30));
            assert(math::equal(si::to_Pm2(1.0_m2), 1.0e-30));

            assert(math::equal((1.0_Tm2).mag(), 1.0e24));
            assert(math::equal(si::to_Tm2(1.0_m2), 1.0e-24));

            assert(math::equal((1.0_Gm2).mag(), 1.0e18));
            assert(math::equal(si::to_Gm2(1.0_m2), 1.0e-18));

            assert(math::equal((1.0_Mm2).mag(), 1.0e12));
            assert(math::equal(si::to_Mm2(1.0_m2), 1.0e-12));

            assert(math::equal((1.0_km2).mag(), 1.0e6));
            assert(math::equal(si::to_km2(1.0_m2), 1.0e-6));

            assert(math::equal((1.0_hm2).mag(), 1.0e4));
            assert(math::equal(si::to_hm2(1.0_m2), 1.0e-4));

            assert(math::equal((1.0_dam2).mag(), 1.0e2));
            assert(math::equal(si::to_dam2(1.0_m2), 1.0e-2));

            assert(math::equal((1.0_m2).mag(), 1.0));
            assert(math::equal(si::to_m2(1.0_m2), 1.0));

            assert(math::equal((1.0_dm2).mag(), 1.0e-2));
            assert(math::equal(si::to_dm2(1.0_m2), 1.0e2));

            assert(math::equal((1.0_cm2).mag(), 1.0e-4));
            assert(math::equal(si::to_cm2(1.0_m2), 1.0e4));

            assert(math::equal((1.0_mm2).mag(), 1.0e-6));
            assert(math::equal(si::to_mm2(1.0_m2), 1.0e6));

            assert(math::equal((1.0_um2).mag(), 1.0e-12));
            assert(math::equal(si::to_um2(1.0_m2), 1.0e12));

            assert(math::equal((1.0_nm2).mag(), 1.0e-18));
            assert(math::equal(si::to_nm2(1.0_m2), 1.0e18));

            assert(math::equal((1.0_pm2).mag(), 1.0e-24));
            assert(math::equal(si::to_pm2(1.0_m2), 1.0e24));

            assert(math::equal((1.0_fm2).mag(), 1.0e-30));
            assert(math::equal(si::to_fm2(1.0_m2), 1.0e30));

            assert(math::equal((1.0_am2).mag(), 1.0e-36));
            assert(math::equal(si::to_am2(1.0_m2), 1.0e36));

            assert(math::equal((1.0_zm2).mag(), 1.0e-42));
            assert(math::equal(si::to_zm2(1.0_m2), 1.0e42));

            assert(math::equal((1.0_ym2).mag(), 1.0e-48));
            assert(math::equal(si::to_ym2(1.0_m2), 1.0e48));

            assert(math::equal((1.0_in2).mag(), 0.00064516));
            assert(math::equal(si::to_in2(1.0_m2), 1.0 / 0.00064516));

            assert(math::equal((1.0_ft2).mag(), 0.092903));
            assert(math::equal(si::to_ft2(1.0_m2), 1.0 / 0.092903));

            assert(math::equal((1.0_yd2).mag(), 0.836127));
            assert(math::equal(si::to_yd2(1.0_m2), 1.0 / 0.836127));

            assert(math::equal((1.0_mi2).mag(), 2.59e6));
            assert(math::equal(si::to_mi2(1.0_m2), 1.0 / 2.59e6));

            assert(math::equal((1.0_ha).mag(), 1.0e4));
            assert(math::equal(si::to_ha(1.0_m2), 1.0 / 1.0e4));

            assert(math::equal((1.0_acre).mag(), 4046.86));
            assert(math::equal(si::to_acre(1.0_m2), 1.0 / 4046.86));
        }

        inline void volume() noexcept
        {
            assert(math::equal((1.0_Ym3).mag(), 1.0e72));
            assert(math::equal(si::to_Ym3(1.0_m3), 1.0e-72));

            assert(math::equal((1.0_Zm3).mag(), 1.0e63));
            assert(math::equal(si::to_Zm3(1.0_m3), 1.0e-63));

            assert(math::equal((1.0_Em3).mag(), 1.0e54));
            assert(math::equal(si::to_Em3(1.0_m3), 1.0e-54));

            assert(math::equal((1.0_Pm3).mag(), 1.0e45));
            assert(math::equal(si::to_Pm3(1.0_m3), 1.0e-45));

            assert(math::equal((1.0_Tm3).mag(), 1.0e36));
            assert(math::equal(si::to_Tm3(1.0_m3), 1.0e-36));

            assert(math::equal((1.0_Gm3).mag(), 1.0e27));
            assert(math::equal(si::to_Gm3(1.0_m3), 1.0e-27));

            assert(math::equal((1.0_Mm3).mag(), 1.0e18));
            assert(math::equal(si::to_Mm3(1.0_m3), 1.0e-18));

            assert(math::equal((1.0_km3).mag(), 1.0e9));
            assert(math::equal(si::to_km3(1.0_m3), 1.0e-9));

            assert(math::equal((1.0_hm3).mag(), 1.0e6));
            assert(math::equal(si::to_hm3(1.0_m3), 1.0e-6));

            assert(math::equal((1.0_dam3).mag(), 1.0e3));
            assert(math::equal(si::to_dam3(1.0_m3), 1.0e-3));

            assert(math::equal((1.0_m3).mag(), 1.0));
            assert(math::equal(si::to_m3(1.0_m3), 1.0));

            assert(math::equal((1.0_dm3).mag(), 1.0e-3));
            assert(math::equal(si::to_dm3(1.0_m3), 1.0e3));

            assert(math::equal((1.0_cm3).mag(), 1.0e-6));
            assert(math::equal(si::to_cm3(1.0_m3), 1.0e6));

            assert(math::equal((1.0_mm3).mag(), 1.0e-9));
            assert(math::equal(si::to_mm3(1.0_m3), 1.0e9));

            assert(math::equal((1.0_um3).mag(), 1.0e-18));
            assert(math::equal(si::to_um3(1.0_m3), 1.0e18));

            assert(math::equal((1.0_nm3).mag(), 1.0e-27));
            assert(math::equal(si::to_nm3(1.0_m3), 1.0e27));

            assert(math::equal((1.0_pm3).mag(), 1.0e-36));
            assert(math::equal(si::to_pm3(1.0_m3), 1.0e36));

            assert(math::equal((1.0_fm3).mag(), 1.0e-45));
            assert(math::equal(si::to_fm3(1.0_m3), 1.0e45));

            assert(math::equal((1.0_am3).mag(), 1.0e-54));
            assert(math::equal(si::to_am3(1.0_m3), 1.0e54));

            assert(math::equal((1.0_zm3).mag(), 1.0e-63));
            assert(math::equal(si::to_zm3(1.0_m3), 1.0e63));

            assert(math::equal((1.0_ym3).mag(), 1.0e-72));
            assert(math::equal(si::to_ym3(1.0_m3), 1.0e72));

            assert(math::equal((1.0_L).mag(), 1.0e-3));
            assert(math::equal(si::to_L(1.0_m3), 1.0 / 1.0e-3));

            assert(math::equal((1.0_in3).mag(), 1.6387e-5));
            assert(math::equal(si::to_in3(1.0_m3), 1.0 / 1.6387e-5));

            assert(math::equal((1.0_ft3).mag(), 0.0283168));
            assert(math::equal(si::to_ft3(1.0_m3), 1.0 / 0.0283168));

            assert(math::equal((1.0_tsp).mag(), 5.9194e-6));
            assert(math::equal(si::to_tsp(1.0_m3), 1.0 / 5.9194e-6));

            assert(math::equal((1.0_tbsp).mag(), 1.7758e-5));
            assert(math::equal(si::to_tbsp(1.0_m3), 1.0 / 1.7758e-5));

            assert(math::equal((1.0_foz).mag(), 2.8413e-5));
            assert(math::equal(si::to_foz(1.0_m3), 1.0 / 2.8413e-5));

            assert(math::equal((1.0_cup).mag(), 0.000284131));
            assert(math::equal(si::to_cup(1.0_m3), 1.0 / 0.000284131));

            assert(math::equal((1.0_pt).mag(), 0.000568261));
            assert(math::equal(si::to_pt(1.0_m3), 1.0 / 0.000568261));

            assert(math::equal((1.0_qt).mag(), 0.00113652));
            assert(math::equal(si::to_qt(1.0_m3), 1.0 / 0.00113652));

            assert(math::equal((1.0_gal).mag(), 0.00454609));
            assert(math::equal(si::to_gal(1.0_m3), 1.0 / 0.00454609));

            assert(math::equal((1.0_UStsp).mag(), 4.9289e-6));
            assert(math::equal(si::to_UStsp(1.0_m3), 1.0 / 4.9289e-6));

            assert(math::equal((1.0_UStbsp).mag(), 1.4787e-5));
            assert(math::equal(si::to_UStbsp(1.0_m3), 1.0 / 1.4787e-5));

            assert(math::equal((1.0_USfoz).mag(), 2.9574e-5));
            assert(math::equal(si::to_USfoz(1.0_m3), 1.0 / 2.9574e-5));

            assert(math::equal((1.0_UScup).mag(), 0.00024));
            assert(math::equal(si::to_UScup(1.0_m3), 1.0 / 0.00024));

            assert(math::equal((1.0_USpt).mag(), 0.000473176));
            assert(math::equal(si::to_USpt(1.0_m3), 1.0 / 0.000473176));

            assert(math::equal((1.0_USqt).mag(), 0.000946353));
            assert(math::equal(si::to_USqt(1.0_m3), 1.0 / 0.000946353));

            assert(math::equal((1.0_USgal).mag(), 0.00378541));
            assert(math::equal(si::to_USgal(1.0_m3), 1.0 / 0.00378541));
        }

        inline void frequency() noexcept
        {
            assert(math::equal((1.0_YHz).mag(), 1.0e24));
            assert(math::equal(si::to_YHz(1.0_Hz), 1.0e-24));

            assert(math::equal((1.0_ZHz).mag(), 1.0e21));
            assert(math::equal(si::to_ZHz(1.0_Hz), 1.0e-21));

            assert(math::equal((1.0_EHz).mag(), 1.0e18));
            assert(math::equal(si::to_EHz(1.0_Hz), 1.0e-18));

            assert(math::equal((1.0_PHz).mag(), 1.0e15));
            assert(math::equal(si::to_PHz(1.0_Hz), 1.0e-15));

            assert(math::equal((1.0_THz).mag(), 1.0e12));
            assert(math::equal(si::to_THz(1.0_Hz), 1.0e-12));

            assert(math::equal((1.0_GHz).mag(), 1.0e9));
            assert(math::equal(si::to_GHz(1.0_Hz), 1.0e-9));

            assert(math::equal((1.0_MHz).mag(), 1.0e6));
            assert(math::equal(si::to_MHz(1.0_Hz), 1.0e-6));

            assert(math::equal((1.0_kHz).mag(), 1.0e3));
            assert(math::equal(si::to_kHz(1.0_Hz), 1.0e-3));

            assert(math::equal((1.0_hHz).mag(), 1.0e2));
            assert(math::equal(si::to_hHz(1.0_Hz), 1.0e-2));

            assert(math::equal((1.0_daHz).mag(), 1.0e1));
            assert(math::equal(si::to_daHz(1.0_Hz), 1.0e-1));

            assert(math::equal((1.0_Hz).mag(), 1.0));
            assert(math::equal(si::to_Hz(1.0_Hz), 1.0));

            assert(math::equal((1.0_dHz).mag(), 1.0e-1));
            assert(math::equal(si::to_dHz(1.0_Hz), 1.0e1));

            assert(math::equal((1.0_cHz).mag(), 1.0e-2));
            assert(math::equal(si::to_cHz(1.0_Hz), 1.0e2));

            assert(math::equal((1.0_mHz).mag(), 1.0e-3));
            assert(math::equal(si::to_mHz(1.0_Hz), 1.0e3));

            assert(math::equal((1.0_uHz).mag(), 1.0e-6));
            assert(math::equal(si::to_uHz(1.0_Hz), 1.0e6));

            assert(math::equal((1.0_nHz).mag(), 1.0e-9));
            assert(math::equal(si::to_nHz(1.0_Hz), 1.0e9));

            assert(math::equal((1.0_pHz).mag(), 1.0e-12));
            assert(math::equal(si::to_pHz(1.0_Hz), 1.0e12));

            assert(math::equal((1.0_fHz).mag(), 1.0e-15));
            assert(math::equal(si::to_fHz(1.0_Hz), 1.0e15));

            assert(math::equal((1.0_aHz).mag(), 1.0e-18));
            assert(math::equal(si::to_aHz(1.0_Hz), 1.0e18));

            assert(math::equal((1.0_zHz).mag(), 1.0e-21));
            assert(math::equal(si::to_zHz(1.0_Hz), 1.0e21));

            assert(math::equal((1.0_yHz).mag(), 1.0e-24));
            assert(math::equal(si::to_yHz(1.0_Hz), 1.0e24));
        }

        inline void force() noexcept
        {
            assert(math::equal((1.0_YN).mag(), 1.0e24));
            assert(math::equal(si::to_YN(1.0_N), 1.0e-24));

            assert(math::equal((1.0_ZN).mag(), 1.0e21));
            assert(math::equal(si::to_ZN(1.0_N), 1.0e-21));

            assert(math::equal((1.0_EN).mag(), 1.0e18));
            assert(math::equal(si::to_EN(1.0_N), 1.0e-18));

            assert(math::equal((1.0_PN).mag(), 1.0e15));
            assert(math::equal(si::to_PN(1.0_N), 1.0e-15));

            assert(math::equal((1.0_TN).mag(), 1.0e12));
            assert(math::equal(si::to_TN(1.0_N), 1.0e-12));

            assert(math::equal((1.0_GN).mag(), 1.0e9));
            assert(math::equal(si::to_GN(1.0_N), 1.0e-9));

            assert(math::equal((1.0_MN).mag(), 1.0e6));
            assert(math::equal(si::to_MN(1.0_N), 1.0e-6));

            assert(math::equal((1.0_kN).mag(), 1.0e3));
            assert(math::equal(si::to_kN(1.0_N), 1.0e-3));

            assert(math::equal((1.0_hN).mag(), 1.0e2));
            assert(math::equal(si::to_hN(1.0_N), 1.0e-2));

            assert(math::equal((1.0_daN).mag(), 1.0e1));
            assert(math::equal(si::to_daN(1.0_N), 1.0e-1));

            assert(math::equal((1.0_N).mag(), 1.0));
            assert(math::equal(si::to_N(1.0_N), 1.0));

            assert(math::equal((1.0_dN).mag(), 1.0e-1));
            assert(math::equal(si::to_dN(1.0_N), 1.0e1));

            assert(math::equal((1.0_cN).mag(), 1.0e-2));
            assert(math::equal(si::to_cN(1.0_N), 1.0e2));

            assert(math::equal((1.0_mN).mag(), 1.0e-3));
            assert(math::equal(si::to_mN(1.0_N), 1.0e3));

            assert(math::equal((1.0_uN).mag(), 1.0e-6));
            assert(math::equal(si::to_uN(1.0_N), 1.0e6));

            assert(math::equal((1.0_nN).mag(), 1.0e-9));
            assert(math::equal(si::to_nN(1.0_N), 1.0e9));

            assert(math::equal((1.0_pN).mag(), 1.0e-12));
            assert(math::equal(si::to_pN(1.0_N), 1.0e12));

            assert(math::equal((1.0_fN).mag(), 1.0e-15));
            assert(math::equal(si::to_fN(1.0_N), 1.0e15));

            assert(math::equal((1.0_aN).mag(), 1.0e-18));
            assert(math::equal(si::to_aN(1.0_N), 1.0e18));

            assert(math::equal((1.0_zN).mag(), 1.0e-21));
            assert(math::equal(si::to_zN(1.0_N), 1.0e21));

            assert(math::equal((1.0_yN).mag(), 1.0e-24));
            assert(math::equal(si::to_yN(1.0_N), 1.0e24));
        }

        inline void pressure() noexcept
        {
            assert(math::equal((1.0_YPa).mag(), 1.0e24));
            assert(math::equal(si::to_YPa(1.0_Pa), 1.0e-24));

            assert(math::equal((1.0_ZPa).mag(), 1.0e21));
            assert(math::equal(si::to_ZPa(1.0_Pa), 1.0e-21));

            assert(math::equal((1.0_EPa).mag(), 1.0e18));
            assert(math::equal(si::to_EPa(1.0_Pa), 1.0e-18));

            assert(math::equal((1.0_PPa).mag(), 1.0e15));
            assert(math::equal(si::to_PPa(1.0_Pa), 1.0e-15));

            assert(math::equal((1.0_TPa).mag(), 1.0e12));
            assert(math::equal(si::to_TPa(1.0_Pa), 1.0e-12));

            assert(math::equal((1.0_GPa).mag(), 1.0e9));
            assert(math::equal(si::to_GPa(1.0_Pa), 1.0e-9));

            assert(math::equal((1.0_MPa).mag(), 1.0e6));
            assert(math::equal(si::to_MPa(1.0_Pa), 1.0e-6));

            assert(math::equal((1.0_kPa).mag(), 1.0e3));
            assert(math::equal(si::to_kPa(1.0_Pa), 1.0e-3));

            assert(math::equal((1.0_hPa).mag(), 1.0e2));
            assert(math::equal(si::to_hPa(1.0_Pa), 1.0e-2));

            assert(math::equal((1.0_daPa).mag(), 1.0e1));
            assert(math::equal(si::to_daPa(1.0_Pa), 1.0e-1));

            assert(math::equal((1.0_Pa).mag(), 1.0));
            assert(math::equal(si::to_Pa(1.0_Pa), 1.0));

            assert(math::equal((1.0_dPa).mag(), 1.0e-1));
            assert(math::equal(si::to_dPa(1.0_Pa), 1.0e1));

            assert(math::equal((1.0_cPa).mag(), 1.0e-2));
            assert(math::equal(si::to_cPa(1.0_Pa), 1.0e2));

            assert(math::equal((1.0_mPa).mag(), 1.0e-3));
            assert(math::equal(si::to_mPa(1.0_Pa), 1.0e3));

            assert(math::equal((1.0_uPa).mag(), 1.0e-6));
            assert(math::equal(si::to_uPa(1.0_Pa), 1.0e6));

            assert(math::equal((1.0_nPa).mag(), 1.0e-9));
            assert(math::equal(si::to_nPa(1.0_Pa), 1.0e9));

            assert(math::equal((1.0_pPa).mag(), 1.0e-12));
            assert(math::equal(si::to_pPa(1.0_Pa), 1.0e12));

            assert(math::equal((1.0_fPa).mag(), 1.0e-15));
            assert(math::equal(si::to_fPa(1.0_Pa), 1.0e15));

            assert(math::equal((1.0_aPa).mag(), 1.0e-18));
            assert(math::equal(si::to_aPa(1.0_Pa), 1.0e18));

            assert(math::equal((1.0_zPa).mag(), 1.0e-21));
            assert(math::equal(si::to_zPa(1.0_Pa), 1.0e21));

            assert(math::equal((1.0_yPa).mag(), 1.0e-24));
            assert(math::equal(si::to_yPa(1.0_Pa), 1.0e24));

            assert(math::equal((1.0_bar).mag(), 1.0e5));
            assert(math::equal(si::to_bar(1.0_Pa), 1.0 / 1.0e5));

            assert(math::equal((1.0_atm).mag(), 101325.0));
            assert(math::equal(si::to_atm(1.0_Pa), 1.0 / 101325.0));
        }

        inline void energy() noexcept
        {
            assert(math::equal((1.0_YJ).mag(), 1.0e24));
            assert(math::equal(si::to_YJ(1.0_J), 1.0e-24));

            assert(math::equal((1.0_ZJ).mag(), 1.0e21));
            assert(math::equal(si::to_ZJ(1.0_J), 1.0e-21));

            assert(math::equal((1.0_EJ).mag(), 1.0e18));
            assert(math::equal(si::to_EJ(1.0_J), 1.0e-18));

            assert(math::equal((1.0_PJ).mag(), 1.0e15));
            assert(math::equal(si::to_PJ(1.0_J), 1.0e-15));

            assert(math::equal((1.0_TJ).mag(), 1.0e12));
            assert(math::equal(si::to_TJ(1.0_J), 1.0e-12));

            assert(math::equal((1.0_GJ).mag(), 1.0e9));
            assert(math::equal(si::to_GJ(1.0_J), 1.0e-9));

            assert(math::equal((1.0_MJ).mag(), 1.0e6));
            assert(math::equal(si::to_MJ(1.0_J), 1.0e-6));

            assert(math::equal((1.0_kJ).mag(), 1.0e3));
            assert(math::equal(si::to_kJ(1.0_J), 1.0e-3));

            assert(math::equal((1.0_hJ).mag(), 1.0e2));
            assert(math::equal(si::to_hJ(1.0_J), 1.0e-2));

            assert(math::equal((1.0_daJ).mag(), 1.0e1));
            assert(math::equal(si::to_daJ(1.0_J), 1.0e-1));

            assert(math::equal((1.0_J).mag(), 1.0));
            assert(math::equal(si::to_J(1.0_J), 1.0));

            assert(math::equal((1.0_dJ).mag(), 1.0e-1));
            assert(math::equal(si::to_dJ(1.0_J), 1.0e1));

            assert(math::equal((1.0_cJ).mag(), 1.0e-2));
            assert(math::equal(si::to_cJ(1.0_J), 1.0e2));

            assert(math::equal((1.0_mJ).mag(), 1.0e-3));
            assert(math::equal(si::to_mJ(1.0_J), 1.0e3));

            assert(math::equal((1.0_uJ).mag(), 1.0e-6));
            assert(math::equal(si::to_uJ(1.0_J), 1.0e6));

            assert(math::equal((1.0_nJ).mag(), 1.0e-9));
            assert(math::equal(si::to_nJ(1.0_J), 1.0e9));

            assert(math::equal((1.0_pJ).mag(), 1.0e-12));
            assert(math::equal(si::to_pJ(1.0_J), 1.0e12));

            assert(math::equal((1.0_fJ).mag(), 1.0e-15));
            assert(math::equal(si::to_fJ(1.0_J), 1.0e15));

            assert(math::equal((1.0_aJ).mag(), 1.0e-18));
            assert(math::equal(si::to_aJ(1.0_J), 1.0e18));

            assert(math::equal((1.0_zJ).mag(), 1.0e-21));
            assert(math::equal(si::to_zJ(1.0_J), 1.0e21));

            assert(math::equal((1.0_yJ).mag(), 1.0e-24));
            assert(math::equal(si::to_yJ(1.0_J), 1.0e24));

            assert(math::equal((1.0_eV).mag(), 1.6022e-19));
            assert(math::equal(si::to_eV(1.0_J), 1.0 / 1.6022e-19));

            assert(math::equal((1.0_cal).mag(), 4.184));
            assert(math::equal(si::to_cal(1.0_J), 1.0 / 4.184));

            assert(math::equal((1.0_kcal).mag(), 4184.0));
            assert(math::equal(si::to_kcal(1.0_J), 1.0 / 4184.0));

            assert(math::equal((1.0_Wh).mag(), 3600.0));
            assert(math::equal(si::to_Wh(1.0_J), 1.0 / 3600.0));

            assert(math::equal((1.0_KWh).mag(), 3.6e6));
            assert(math::equal(si::to_KWh(1.0_J), 1.0 / 3.6e6));
        }

        inline void power() noexcept
        {
            assert(math::equal((1.0_YW).mag(), 1.0e24));
            assert(math::equal(si::to_YW(1.0_W), 1.0e-24));

            assert(math::equal((1.0_ZW).mag(), 1.0e21));
            assert(math::equal(si::to_ZW(1.0_W), 1.0e-21));

            assert(math::equal((1.0_EW).mag(), 1.0e18));
            assert(math::equal(si::to_EW(1.0_W), 1.0e-18));

            assert(math::equal((1.0_PW).mag(), 1.0e15));
            assert(math::equal(si::to_PW(1.0_W), 1.0e-15));

            assert(math::equal((1.0_TW).mag(), 1.0e12));
            assert(math::equal(si::to_TW(1.0_W), 1.0e-12));

            assert(math::equal((1.0_GW).mag(), 1.0e9));
            assert(math::equal(si::to_GW(1.0_W), 1.0e-9));

            assert(math::equal((1.0_MW).mag(), 1.0e6));
            assert(math::equal(si::to_MW(1.0_W), 1.0e-6));

            assert(math::equal((1.0_kW).mag(), 1.0e3));
            assert(math::equal(si::to_kW(1.0_W), 1.0e-3));

            assert(math::equal((1.0_hW).mag(), 1.0e2));
            assert(math::equal(si::to_hW(1.0_W), 1.0e-2));

            assert(math::equal((1.0_daW).mag(), 1.0e1));
            assert(math::equal(si::to_daW(1.0_W), 1.0e-1));

            assert(math::equal((1.0_W).mag(), 1.0));
            assert(math::equal(si::to_W(1.0_W), 1.0));

            assert(math::equal((1.0_dW).mag(), 1.0e-1));
            assert(math::equal(si::to_dW(1.0_W), 1.0e1));

            assert(math::equal((1.0_cW).mag(), 1.0e-2));
            assert(math::equal(si::to_cW(1.0_W), 1.0e2));

            assert(math::equal((1.0_mW).mag(), 1.0e-3));
            assert(math::equal(si::to_mW(1.0_W), 1.0e3));

            assert(math::equal((1.0_uW).mag(), 1.0e-6));
            assert(math::equal(si::to_uW(1.0_W), 1.0e6));

            assert(math::equal((1.0_nW).mag(), 1.0e-9));
            assert(math::equal(si::to_nW(1.0_W), 1.0e9));

            assert(math::equal((1.0_pW).mag(), 1.0e-12));
            assert(math::equal(si::to_pW(1.0_W), 1.0e12));

            assert(math::equal((1.0_fW).mag(), 1.0e-15));
            assert(math::equal(si::to_fW(1.0_W), 1.0e15));

            assert(math::equal((1.0_aW).mag(), 1.0e-18));
            assert(math::equal(si::to_aW(1.0_W), 1.0e18));

            assert(math::equal((1.0_zW).mag(), 1.0e-21));
            assert(math::equal(si::to_zW(1.0_W), 1.0e21));

            assert(math::equal((1.0_yW).mag(), 1.0e-24));
            assert(math::equal(si::to_yW(1.0_W), 1.0e24));
        }

        inline void charge() noexcept
        {
            assert(math::equal((1.0_YC).mag(), 1.0e24));
            assert(math::equal(si::to_YC(1.0_C), 1.0e-24));

            assert(math::equal((1.0_ZC).mag(), 1.0e21));
            assert(math::equal(si::to_ZC(1.0_C), 1.0e-21));

            assert(math::equal((1.0_EC).mag(), 1.0e18));
            assert(math::equal(si::to_EC(1.0_C), 1.0e-18));

            assert(math::equal((1.0_PC).mag(), 1.0e15));
            assert(math::equal(si::to_PC(1.0_C), 1.0e-15));

            assert(math::equal((1.0_TC).mag(), 1.0e12));
            assert(math::equal(si::to_TC(1.0_C), 1.0e-12));

            assert(math::equal((1.0_GC).mag(), 1.0e9));
            assert(math::equal(si::to_GC(1.0_C), 1.0e-9));

            assert(math::equal((1.0_MC).mag(), 1.0e6));
            assert(math::equal(si::to_MC(1.0_C), 1.0e-6));

            assert(math::equal((1.0_kC).mag(), 1.0e3));
            assert(math::equal(si::to_kC(1.0_C), 1.0e-3));

            assert(math::equal((1.0_hC).mag(), 1.0e2));
            assert(math::equal(si::to_hC(1.0_C), 1.0e-2));

            assert(math::equal((1.0_daC).mag(), 1.0e1));
            assert(math::equal(si::to_daC(1.0_C), 1.0e-1));

            assert(math::equal((1.0_C).mag(), 1.0));
            assert(math::equal(si::to_C(1.0_C), 1.0));

            assert(math::equal((1.0_dC).mag(), 1.0e-1));
            assert(math::equal(si::to_dC(1.0_C), 1.0e1));

            assert(math::equal((1.0_cC).mag(), 1.0e-2));
            assert(math::equal(si::to_cC(1.0_C), 1.0e2));

            assert(math::equal((1.0_mC).mag(), 1.0e-3));
            assert(math::equal(si::to_mC(1.0_C), 1.0e3));

            assert(math::equal((1.0_uC).mag(), 1.0e-6));
            assert(math::equal(si::to_uC(1.0_C), 1.0e6));

            assert(math::equal((1.0_nC).mag(), 1.0e-9));
            assert(math::equal(si::to_nC(1.0_C), 1.0e9));

            assert(math::equal((1.0_pC).mag(), 1.0e-12));
            assert(math::equal(si::to_pC(1.0_C), 1.0e12));

            assert(math::equal((1.0_fC).mag(), 1.0e-15));
            assert(math::equal(si::to_fC(1.0_C), 1.0e15));

            assert(math::equal((1.0_aC).mag(), 1.0e-18));
            assert(math::equal(si::to_aC(1.0_C), 1.0e18));

            assert(math::equal((1.0_zC).mag(), 1.0e-21));
            assert(math::equal(si::to_zC(1.0_C), 1.0e21));

            assert(math::equal((1.0_yC).mag(), 1.0e-24));
            assert(math::equal(si::to_yC(1.0_C), 1.0e24));
        }

        inline void potential() noexcept
        {
            assert(math::equal((1.0_YV).mag(), 1.0e24));
            assert(math::equal(si::to_YV(1.0_V), 1.0e-24));

            assert(math::equal((1.0_ZV).mag(), 1.0e21));
            assert(math::equal(si::to_ZV(1.0_V), 1.0e-21));

            assert(math::equal((1.0_EV).mag(), 1.0e18));
            assert(math::equal(si::to_EV(1.0_V), 1.0e-18));

            assert(math::equal((1.0_PV).mag(), 1.0e15));
            assert(math::equal(si::to_PV(1.0_V), 1.0e-15));

            assert(math::equal((1.0_TV).mag(), 1.0e12));
            assert(math::equal(si::to_TV(1.0_V), 1.0e-12));

            assert(math::equal((1.0_GV).mag(), 1.0e9));
            assert(math::equal(si::to_GV(1.0_V), 1.0e-9));

            assert(math::equal((1.0_MV).mag(), 1.0e6));
            assert(math::equal(si::to_MV(1.0_V), 1.0e-6));

            assert(math::equal((1.0_kV).mag(), 1.0e3));
            assert(math::equal(si::to_kV(1.0_V), 1.0e-3));

            assert(math::equal((1.0_hV).mag(), 1.0e2));
            assert(math::equal(si::to_hV(1.0_V), 1.0e-2));

            assert(math::equal((1.0_daV).mag(), 1.0e1));
            assert(math::equal(si::to_daV(1.0_V), 1.0e-1));

            assert(math::equal((1.0_V).mag(), 1.0));
            assert(math::equal(si::to_V(1.0_V), 1.0));

            assert(math::equal((1.0_dV).mag(), 1.0e-1));
            assert(math::equal(si::to_dV(1.0_V), 1.0e1));

            assert(math::equal((1.0_cV).mag(), 1.0e-2));
            assert(math::equal(si::to_cV(1.0_V), 1.0e2));

            assert(math::equal((1.0_mV).mag(), 1.0e-3));
            assert(math::equal(si::to_mV(1.0_V), 1.0e3));

            assert(math::equal((1.0_uV).mag(), 1.0e-6));
            assert(math::equal(si::to_uV(1.0_V), 1.0e6));

            assert(math::equal((1.0_nV).mag(), 1.0e-9));
            assert(math::equal(si::to_nV(1.0_V), 1.0e9));

            assert(math::equal((1.0_pV).mag(), 1.0e-12));
            assert(math::equal(si::to_pV(1.0_V), 1.0e12));

            assert(math::equal((1.0_fV).mag(), 1.0e-15));
            assert(math::equal(si::to_fV(1.0_V), 1.0e15));

            assert(math::equal((1.0_aV).mag(), 1.0e-18));
            assert(math::equal(si::to_aV(1.0_V), 1.0e18));

            assert(math::equal((1.0_zV).mag(), 1.0e-21));
            assert(math::equal(si::to_zV(1.0_V), 1.0e21));

            assert(math::equal((1.0_yV).mag(), 1.0e-24));
            assert(math::equal(si::to_yV(1.0_V), 1.0e24));
        }

        inline void capacitance() noexcept
        {
            assert(math::equal((1.0_YF).mag(), 1.0e24));
            assert(math::equal(si::to_YF(1.0_F), 1.0e-24));

            assert(math::equal((1.0_ZF).mag(), 1.0e21));
            assert(math::equal(si::to_ZF(1.0_F), 1.0e-21));

            assert(math::equal((1.0_EF).mag(), 1.0e18));
            assert(math::equal(si::to_EF(1.0_F), 1.0e-18));

            assert(math::equal((1.0_PF).mag(), 1.0e15));
            assert(math::equal(si::to_PF(1.0_F), 1.0e-15));

            assert(math::equal((1.0_TF).mag(), 1.0e12));
            assert(math::equal(si::to_TF(1.0_F), 1.0e-12));

            assert(math::equal((1.0_GF).mag(), 1.0e9));
            assert(math::equal(si::to_GF(1.0_F), 1.0e-9));

            assert(math::equal((1.0_MF).mag(), 1.0e6));
            assert(math::equal(si::to_MF(1.0_F), 1.0e-6));

            assert(math::equal((1.0_kF).mag(), 1.0e3));
            assert(math::equal(si::to_kF(1.0_F), 1.0e-3));

            assert(math::equal((1.0_hF).mag(), 1.0e2));
            assert(math::equal(si::to_hF(1.0_F), 1.0e-2));

            assert(math::equal((1.0_daF).mag(), 1.0e1));
            assert(math::equal(si::to_daF(1.0_F), 1.0e-1));

            assert(math::equal((1.0_F).mag(), 1.0));
            assert(math::equal(si::to_F(1.0_F), 1.0));

            assert(math::equal((1.0_dF).mag(), 1.0e-1));
            assert(math::equal(si::to_dF(1.0_F), 1.0e1));

            assert(math::equal((1.0_cF).mag(), 1.0e-2));
            assert(math::equal(si::to_cF(1.0_F), 1.0e2));

            assert(math::equal((1.0_mF).mag(), 1.0e-3));
            assert(math::equal(si::to_mF(1.0_F), 1.0e3));

            assert(math::equal((1.0_uF).mag(), 1.0e-6));
            assert(math::equal(si::to_uF(1.0_F), 1.0e6));

            assert(math::equal((1.0_nF).mag(), 1.0e-9));
            assert(math::equal(si::to_nF(1.0_F), 1.0e9));

            assert(math::equal((1.0_pF).mag(), 1.0e-12));
            assert(math::equal(si::to_pF(1.0_F), 1.0e12));

            assert(math::equal((1.0_fF).mag(), 1.0e-15));
            assert(math::equal(si::to_fF(1.0_F), 1.0e15));

            assert(math::equal((1.0_aF).mag(), 1.0e-18));
            assert(math::equal(si::to_aF(1.0_F), 1.0e18));

            assert(math::equal((1.0_zF).mag(), 1.0e-21));
            assert(math::equal(si::to_zF(1.0_F), 1.0e21));

            assert(math::equal((1.0_yF).mag(), 1.0e-24));
            assert(math::equal(si::to_yF(1.0_F), 1.0e24));
        }

        inline void resistance() noexcept
        {
            assert(math::equal((1.0_YOhm).mag(), 1.0e24));
            assert(math::equal(si::to_YOhm(1.0_Ohm), 1.0e-24));

            assert(math::equal((1.0_ZOhm).mag(), 1.0e21));
            assert(math::equal(si::to_ZOhm(1.0_Ohm), 1.0e-21));

            assert(math::equal((1.0_EOhm).mag(), 1.0e18));
            assert(math::equal(si::to_EOhm(1.0_Ohm), 1.0e-18));

            assert(math::equal((1.0_POhm).mag(), 1.0e15));
            assert(math::equal(si::to_POhm(1.0_Ohm), 1.0e-15));

            assert(math::equal((1.0_TOhm).mag(), 1.0e12));
            assert(math::equal(si::to_TOhm(1.0_Ohm), 1.0e-12));

            assert(math::equal((1.0_GOhm).mag(), 1.0e9));
            assert(math::equal(si::to_GOhm(1.0_Ohm), 1.0e-9));

            assert(math::equal((1.0_MOhm).mag(), 1.0e6));
            assert(math::equal(si::to_MOhm(1.0_Ohm), 1.0e-6));

            assert(math::equal((1.0_kOhm).mag(), 1.0e3));
            assert(math::equal(si::to_kOhm(1.0_Ohm), 1.0e-3));

            assert(math::equal((1.0_hOhm).mag(), 1.0e2));
            assert(math::equal(si::to_hOhm(1.0_Ohm), 1.0e-2));

            assert(math::equal((1.0_daOhm).mag(), 1.0e1));
            assert(math::equal(si::to_daOhm(1.0_Ohm), 1.0e-1));

            assert(math::equal((1.0_Ohm).mag(), 1.0));
            assert(math::equal(si::to_Ohm(1.0_Ohm), 1.0));

            assert(math::equal((1.0_dOhm).mag(), 1.0e-1));
            assert(math::equal(si::to_dOhm(1.0_Ohm), 1.0e1));

            assert(math::equal((1.0_cOhm).mag(), 1.0e-2));
            assert(math::equal(si::to_cOhm(1.0_Ohm), 1.0e2));

            assert(math::equal((1.0_mOhm).mag(), 1.0e-3));
            assert(math::equal(si::to_mOhm(1.0_Ohm), 1.0e3));

            assert(math::equal((1.0_uOhm).mag(), 1.0e-6));
            assert(math::equal(si::to_uOhm(1.0_Ohm), 1.0e6));

            assert(math::equal((1.0_nOhm).mag(), 1.0e-9));
            assert(math::equal(si::to_nOhm(1.0_Ohm), 1.0e9));

            assert(math::equal((1.0_pOhm).mag(), 1.0e-12));
            assert(math::equal(si::to_pOhm(1.0_Ohm), 1.0e12));

            assert(math::equal((1.0_fOhm).mag(), 1.0e-15));
            assert(math::equal(si::to_fOhm(1.0_Ohm), 1.0e15));

            assert(math::equal((1.0_aOhm).mag(), 1.0e-18));
            assert(math::equal(si::to_aOhm(1.0_Ohm), 1.0e18));

            assert(math::equal((1.0_zOhm).mag(), 1.0e-21));
            assert(math::equal(si::to_zOhm(1.0_Ohm), 1.0e21));

            assert(math::equal((1.0_yOhm).mag(), 1.0e-24));
            assert(math::equal(si::to_yOhm(1.0_Ohm), 1.0e24));
        }

        inline void conductance() noexcept
        {
            assert(math::equal((1.0_YS).mag(), 1.0e24));
            assert(math::equal(si::to_YS(1.0_S), 1.0e-24));

            assert(math::equal((1.0_ZS).mag(), 1.0e21));
            assert(math::equal(si::to_ZS(1.0_S), 1.0e-21));

            assert(math::equal((1.0_ES).mag(), 1.0e18));
            assert(math::equal(si::to_ES(1.0_S), 1.0e-18));

            assert(math::equal((1.0_PS).mag(), 1.0e15));
            assert(math::equal(si::to_PS(1.0_S), 1.0e-15));

            assert(math::equal((1.0_TS).mag(), 1.0e12));
            assert(math::equal(si::to_TS(1.0_S), 1.0e-12));

            assert(math::equal((1.0_GS).mag(), 1.0e9));
            assert(math::equal(si::to_GS(1.0_S), 1.0e-9));

            assert(math::equal((1.0_MS).mag(), 1.0e6));
            assert(math::equal(si::to_MS(1.0_S), 1.0e-6));

            assert(math::equal((1.0_kS).mag(), 1.0e3));
            assert(math::equal(si::to_kS(1.0_S), 1.0e-3));

            assert(math::equal((1.0_hS).mag(), 1.0e2));
            assert(math::equal(si::to_hS(1.0_S), 1.0e-2));

            assert(math::equal((1.0_daS).mag(), 1.0e1));
            assert(math::equal(si::to_daS(1.0_S), 1.0e-1));

            assert(math::equal((1.0_S).mag(), 1.0));
            assert(math::equal(si::to_S(1.0_S), 1.0));

            assert(math::equal((1.0_dS).mag(), 1.0e-1));
            assert(math::equal(si::to_dS(1.0_S), 1.0e1));

            assert(math::equal((1.0_cS).mag(), 1.0e-2));
            assert(math::equal(si::to_cS(1.0_S), 1.0e2));

            assert(math::equal((1.0_mS).mag(), 1.0e-3));
            assert(math::equal(si::to_mS(1.0_S), 1.0e3));

            assert(math::equal((1.0_uS).mag(), 1.0e-6));
            assert(math::equal(si::to_uS(1.0_S), 1.0e6));

            assert(math::equal((1.0_nS).mag(), 1.0e-9));
            assert(math::equal(si::to_nS(1.0_S), 1.0e9));

            assert(math::equal((1.0_pS).mag(), 1.0e-12));
            assert(math::equal(si::to_pS(1.0_S), 1.0e12));

            assert(math::equal((1.0_fS).mag(), 1.0e-15));
            assert(math::equal(si::to_fS(1.0_S), 1.0e15));

            assert(math::equal((1.0_aS).mag(), 1.0e-18));
            assert(math::equal(si::to_aS(1.0_S), 1.0e18));

            assert(math::equal((1.0_zS).mag(), 1.0e-21));
            assert(math::equal(si::to_zS(1.0_S), 1.0e21));

            assert(math::equal((1.0_yS).mag(), 1.0e-24));
            assert(math::equal(si::to_yS(1.0_S), 1.0e24));
        }

        inline void magnetic_flux() noexcept
        {
            assert(math::equal((1.0_YWb).mag(), 1.0e24));
            assert(math::equal(si::to_YWb(1.0_Wb), 1.0e-24));

            assert(math::equal((1.0_ZWb).mag(), 1.0e21));
            assert(math::equal(si::to_ZWb(1.0_Wb), 1.0e-21));

            assert(math::equal((1.0_EWb).mag(), 1.0e18));
            assert(math::equal(si::to_EWb(1.0_Wb), 1.0e-18));

            assert(math::equal((1.0_PWb).mag(), 1.0e15));
            assert(math::equal(si::to_PWb(1.0_Wb), 1.0e-15));

            assert(math::equal((1.0_TWb).mag(), 1.0e12));
            assert(math::equal(si::to_TWb(1.0_Wb), 1.0e-12));

            assert(math::equal((1.0_GWb).mag(), 1.0e9));
            assert(math::equal(si::to_GWb(1.0_Wb), 1.0e-9));

            assert(math::equal((1.0_MWb).mag(), 1.0e6));
            assert(math::equal(si::to_MWb(1.0_Wb), 1.0e-6));

            assert(math::equal((1.0_kWb).mag(), 1.0e3));
            assert(math::equal(si::to_kWb(1.0_Wb), 1.0e-3));

            assert(math::equal((1.0_hWb).mag(), 1.0e2));
            assert(math::equal(si::to_hWb(1.0_Wb), 1.0e-2));

            assert(math::equal((1.0_daWb).mag(), 1.0e1));
            assert(math::equal(si::to_daWb(1.0_Wb), 1.0e-1));

            assert(math::equal((1.0_Wb).mag(), 1.0));
            assert(math::equal(si::to_Wb(1.0_Wb), 1.0));

            assert(math::equal((1.0_dWb).mag(), 1.0e-1));
            assert(math::equal(si::to_dWb(1.0_Wb), 1.0e1));

            assert(math::equal((1.0_cWb).mag(), 1.0e-2));
            assert(math::equal(si::to_cWb(1.0_Wb), 1.0e2));

            assert(math::equal((1.0_mWb).mag(), 1.0e-3));
            assert(math::equal(si::to_mWb(1.0_Wb), 1.0e3));

            assert(math::equal((1.0_uWb).mag(), 1.0e-6));
            assert(math::equal(si::to_uWb(1.0_Wb), 1.0e6));

            assert(math::equal((1.0_nWb).mag(), 1.0e-9));
            assert(math::equal(si::to_nWb(1.0_Wb), 1.0e9));

            assert(math::equal((1.0_pWb).mag(), 1.0e-12));
            assert(math::equal(si::to_pWb(1.0_Wb), 1.0e12));

            assert(math::equal((1.0_fWb).mag(), 1.0e-15));
            assert(math::equal(si::to_fWb(1.0_Wb), 1.0e15));

            assert(math::equal((1.0_aWb).mag(), 1.0e-18));
            assert(math::equal(si::to_aWb(1.0_Wb), 1.0e18));

            assert(math::equal((1.0_zWb).mag(), 1.0e-21));
            assert(math::equal(si::to_zWb(1.0_Wb), 1.0e21));

            assert(math::equal((1.0_yWb).mag(), 1.0e-24));
            assert(math::equal(si::to_yWb(1.0_Wb), 1.0e24));
        }

        inline void magnetic_flux_density() noexcept
        {
            assert(math::equal((1.0_YT).mag(), 1.0e24));
            assert(math::equal(si::to_YT(1.0_T), 1.0e-24));

            assert(math::equal((1.0_ZT).mag(), 1.0e21));
            assert(math::equal(si::to_ZT(1.0_T), 1.0e-21));

            assert(math::equal((1.0_ET).mag(), 1.0e18));
            assert(math::equal(si::to_ET(1.0_T), 1.0e-18));

            assert(math::equal((1.0_PT).mag(), 1.0e15));
            assert(math::equal(si::to_PT(1.0_T), 1.0e-15));

            assert(math::equal((1.0_TT).mag(), 1.0e12));
            assert(math::equal(si::to_TT(1.0_T), 1.0e-12));

            assert(math::equal((1.0_GT).mag(), 1.0e9));
            assert(math::equal(si::to_GT(1.0_T), 1.0e-9));

            assert(math::equal((1.0_MT).mag(), 1.0e6));
            assert(math::equal(si::to_MT(1.0_T), 1.0e-6));

            assert(math::equal((1.0_kT).mag(), 1.0e3));
            assert(math::equal(si::to_kT(1.0_T), 1.0e-3));

            assert(math::equal((1.0_hT).mag(), 1.0e2));
            assert(math::equal(si::to_hT(1.0_T), 1.0e-2));

            assert(math::equal((1.0_daT).mag(), 1.0e1));
            assert(math::equal(si::to_daT(1.0_T), 1.0e-1));

            assert(math::equal((1.0_T).mag(), 1.0));
            assert(math::equal(si::to_T(1.0_T), 1.0));

            assert(math::equal((1.0_dT).mag(), 1.0e-1));
            assert(math::equal(si::to_dT(1.0_T), 1.0e1));

            assert(math::equal((1.0_cT).mag(), 1.0e-2));
            assert(math::equal(si::to_cT(1.0_T), 1.0e2));

            assert(math::equal((1.0_mT).mag(), 1.0e-3));
            assert(math::equal(si::to_mT(1.0_T), 1.0e3));

            assert(math::equal((1.0_uT).mag(), 1.0e-6));
            assert(math::equal(si::to_uT(1.0_T), 1.0e6));

            assert(math::equal((1.0_nT).mag(), 1.0e-9));
            assert(math::equal(si::to_nT(1.0_T), 1.0e9));

            assert(math::equal((1.0_pT).mag(), 1.0e-12));
            assert(math::equal(si::to_pT(1.0_T), 1.0e12));

            assert(math::equal((1.0_fT).mag(), 1.0e-15));
            assert(math::equal(si::to_fT(1.0_T), 1.0e15));

            assert(math::equal((1.0_aT).mag(), 1.0e-18));
            assert(math::equal(si::to_aT(1.0_T), 1.0e18));

            assert(math::equal((1.0_zT).mag(), 1.0e-21));
            assert(math::equal(si::to_zT(1.0_T), 1.0e21));

            assert(math::equal((1.0_yT).mag(), 1.0e-24));
            assert(math::equal(si::to_yT(1.0_T), 1.0e24));
        }

        inline void inductance() noexcept
        {
            assert(math::equal((1.0_YH).mag(), 1.0e24));
            assert(math::equal(si::to_YH(1.0_H), 1.0e-24));

            assert(math::equal((1.0_ZH).mag(), 1.0e21));
            assert(math::equal(si::to_ZH(1.0_H), 1.0e-21));

            assert(math::equal((1.0_EH).mag(), 1.0e18));
            assert(math::equal(si::to_EH(1.0_H), 1.0e-18));

            assert(math::equal((1.0_PH).mag(), 1.0e15));
            assert(math::equal(si::to_PH(1.0_H), 1.0e-15));

            assert(math::equal((1.0_TH).mag(), 1.0e12));
            assert(math::equal(si::to_TH(1.0_H), 1.0e-12));

            assert(math::equal((1.0_GH).mag(), 1.0e9));
            assert(math::equal(si::to_GH(1.0_H), 1.0e-9));

            assert(math::equal((1.0_MH).mag(), 1.0e6));
            assert(math::equal(si::to_MH(1.0_H), 1.0e-6));

            assert(math::equal((1.0_kH).mag(), 1.0e3));
            assert(math::equal(si::to_kH(1.0_H), 1.0e-3));

            assert(math::equal((1.0_hH).mag(), 1.0e2));
            assert(math::equal(si::to_hH(1.0_H), 1.0e-2));

            assert(math::equal((1.0_daH).mag(), 1.0e1));
            assert(math::equal(si::to_daH(1.0_H), 1.0e-1));

            assert(math::equal((1.0_H).mag(), 1.0));
            assert(math::equal(si::to_H(1.0_H), 1.0));

            assert(math::equal((1.0_dH).mag(), 1.0e-1));
            assert(math::equal(si::to_dH(1.0_H), 1.0e1));

            assert(math::equal((1.0_cH).mag(), 1.0e-2));
            assert(math::equal(si::to_cH(1.0_H), 1.0e2));

            assert(math::equal((1.0_mH).mag(), 1.0e-3));
            assert(math::equal(si::to_mH(1.0_H), 1.0e3));

            assert(math::equal((1.0_uH).mag(), 1.0e-6));
            assert(math::equal(si::to_uH(1.0_H), 1.0e6));

            assert(math::equal((1.0_nH).mag(), 1.0e-9));
            assert(math::equal(si::to_nH(1.0_H), 1.0e9));

            assert(math::equal((1.0_pH).mag(), 1.0e-12));
            assert(math::equal(si::to_pH(1.0_H), 1.0e12));

            assert(math::equal((1.0_fH).mag(), 1.0e-15));
            assert(math::equal(si::to_fH(1.0_H), 1.0e15));

            assert(math::equal((1.0_aH).mag(), 1.0e-18));
            assert(math::equal(si::to_aH(1.0_H), 1.0e18));

            assert(math::equal((1.0_zH).mag(), 1.0e-21));
            assert(math::equal(si::to_zH(1.0_H), 1.0e21));

            assert(math::equal((1.0_yH).mag(), 1.0e-24));
            assert(math::equal(si::to_yH(1.0_H), 1.0e24));
        }

        inline void absorbed_dose() noexcept
        {
            assert(math::equal((1.0_YGy).mag(), 1.0e24));
            assert(math::equal(si::to_YGy(1.0_Gy), 1.0e-24));

            assert(math::equal((1.0_ZGy).mag(), 1.0e21));
            assert(math::equal(si::to_ZGy(1.0_Gy), 1.0e-21));

            assert(math::equal((1.0_EGy).mag(), 1.0e18));
            assert(math::equal(si::to_EGy(1.0_Gy), 1.0e-18));

            assert(math::equal((1.0_PGy).mag(), 1.0e15));
            assert(math::equal(si::to_PGy(1.0_Gy), 1.0e-15));

            assert(math::equal((1.0_TGy).mag(), 1.0e12));
            assert(math::equal(si::to_TGy(1.0_Gy), 1.0e-12));

            assert(math::equal((1.0_GGy).mag(), 1.0e9));
            assert(math::equal(si::to_GGy(1.0_Gy), 1.0e-9));

            assert(math::equal((1.0_MGy).mag(), 1.0e6));
            assert(math::equal(si::to_MGy(1.0_Gy), 1.0e-6));

            assert(math::equal((1.0_kGy).mag(), 1.0e3));
            assert(math::equal(si::to_kGy(1.0_Gy), 1.0e-3));

            assert(math::equal((1.0_hGy).mag(), 1.0e2));
            assert(math::equal(si::to_hGy(1.0_Gy), 1.0e-2));

            assert(math::equal((1.0_daGy).mag(), 1.0e1));
            assert(math::equal(si::to_daGy(1.0_Gy), 1.0e-1));

            assert(math::equal((1.0_Gy).mag(), 1.0));
            assert(math::equal(si::to_Gy(1.0_Gy), 1.0));

            assert(math::equal((1.0_dGy).mag(), 1.0e-1));
            assert(math::equal(si::to_dGy(1.0_Gy), 1.0e1));

            assert(math::equal((1.0_cGy).mag(), 1.0e-2));
            assert(math::equal(si::to_cGy(1.0_Gy), 1.0e2));

            assert(math::equal((1.0_mGy).mag(), 1.0e-3));
            assert(math::equal(si::to_mGy(1.0_Gy), 1.0e3));

            assert(math::equal((1.0_uGy).mag(), 1.0e-6));
            assert(math::equal(si::to_uGy(1.0_Gy), 1.0e6));

            assert(math::equal((1.0_nGy).mag(), 1.0e-9));
            assert(math::equal(si::to_nGy(1.0_Gy), 1.0e9));

            assert(math::equal((1.0_pGy).mag(), 1.0e-12));
            assert(math::equal(si::to_pGy(1.0_Gy), 1.0e12));

            assert(math::equal((1.0_fGy).mag(), 1.0e-15));
            assert(math::equal(si::to_fGy(1.0_Gy), 1.0e15));

            assert(math::equal((1.0_aGy).mag(), 1.0e-18));
            assert(math::equal(si::to_aGy(1.0_Gy), 1.0e18));

            assert(math::equal((1.0_zGy).mag(), 1.0e-21));
            assert(math::equal(si::to_zGy(1.0_Gy), 1.0e21));

            assert(math::equal((1.0_yGy).mag(), 1.0e-24));
            assert(math::equal(si::to_yGy(1.0_Gy), 1.0e24));
        }

        inline void catalytic_activity() noexcept
        {
            assert(math::equal((1.0_Ykat).mag(), 1.0e24));
            assert(math::equal(si::to_Ykat(1.0_kat), 1.0e-24));

            assert(math::equal((1.0_Zkat).mag(), 1.0e21));
            assert(math::equal(si::to_Zkat(1.0_kat), 1.0e-21));

            assert(math::equal((1.0_Ekat).mag(), 1.0e18));
            assert(math::equal(si::to_Ekat(1.0_kat), 1.0e-18));

            assert(math::equal((1.0_Pkat).mag(), 1.0e15));
            assert(math::equal(si::to_Pkat(1.0_kat), 1.0e-15));

            assert(math::equal((1.0_Tkat).mag(), 1.0e12));
            assert(math::equal(si::to_Tkat(1.0_kat), 1.0e-12));

            assert(math::equal((1.0_Gkat).mag(), 1.0e9));
            assert(math::equal(si::to_Gkat(1.0_kat), 1.0e-9));

            assert(math::equal((1.0_Mkat).mag(), 1.0e6));
            assert(math::equal(si::to_Mkat(1.0_kat), 1.0e-6));

            assert(math::equal((1.0_kkat).mag(), 1.0e3));
            assert(math::equal(si::to_kkat(1.0_kat), 1.0e-3));

            assert(math::equal((1.0_hkat).mag(), 1.0e2));
            assert(math::equal(si::to_hkat(1.0_kat), 1.0e-2));

            assert(math::equal((1.0_dakat).mag(), 1.0e1));
            assert(math::equal(si::to_dakat(1.0_kat), 1.0e-1));

            assert(math::equal((1.0_kat).mag(), 1.0));
            assert(math::equal(si::to_kat(1.0_kat), 1.0));

            assert(math::equal((1.0_dkat).mag(), 1.0e-1));
            assert(math::equal(si::to_dkat(1.0_kat), 1.0e1));

            assert(math::equal((1.0_ckat).mag(), 1.0e-2));
            assert(math::equal(si::to_ckat(1.0_kat), 1.0e2));

            assert(math::equal((1.0_mkat).mag(), 1.0e-3));
            assert(math::equal(si::to_mkat(1.0_kat), 1.0e3));

            assert(math::equal((1.0_ukat).mag(), 1.0e-6));
            assert(math::equal(si::to_ukat(1.0_kat), 1.0e6));

            assert(math::equal((1.0_nkat).mag(), 1.0e-9));
            assert(math::equal(si::to_nkat(1.0_kat), 1.0e9));

            assert(math::equal((1.0_pkat).mag(), 1.0e-12));
            assert(math::equal(si::to_pkat(1.0_kat), 1.0e12));

            assert(math::equal((1.0_fkat).mag(), 1.0e-15));
            assert(math::equal(si::to_fkat(1.0_kat), 1.0e15));

            assert(math::equal((1.0_akat).mag(), 1.0e-18));
            assert(math::equal(si::to_akat(1.0_kat), 1.0e18));

            assert(math::equal((1.0_zkat).mag(), 1.0e-21));
            assert(math::equal(si::to_zkat(1.0_kat), 1.0e21));

            assert(math::equal((1.0_ykat).mag(), 1.0e-24));
            assert(math::equal(si::to_ykat(1.0_kat), 1.0e24));
        }



    } // namespace test
} // namespace arc
