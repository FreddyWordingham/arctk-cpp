/**
 *  @file   arctk/opt/mat/simple.inl
 *  @date   29/10/2018
 *  @author Freddy Wordingham
 *
 *  Simple optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MAT_SIMPLE_INL
#define ARCTK_OPT_MAT_SIMPLE_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <limits>

//  -- Arctk --
#include <arctk/opt/sop/simple.hpp>
#include <arctk/prop/limits.hpp>
#include <arctk/prop/order.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {
        namespace mat //! material namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a simple material.
             *
             *  @param  wavelengths_    Wavelengths.
             *  @param  ref_indexs_     Corresponding refractive indices.
             *  @param  dists_          Corresponding interaction distances.
             *  @param  albedos_        Corresponding single scattering albedos.
             *  @param  asyms_          Corresponding symmetry factors.
             *
             *  @pre    wavelengths_ must all be greater than zero.
             *  @pre    wavelengths_ must be ascending.
             *  @pre    ref_indexs_ must be the same size as wavelengths_.
             *  @pre    ref_indexs_ must all be greater than, or equal to, unity.
             *  @pre    dists_ must be the same size as wavelengths_.
             *  @pre    dists_ must all be positive.
             *  @pre    albedos_ must be the same size as wavelengths_.
             *  @pre    albedos_ must all be positive.
             *  @pre    albedos_ must all less than, or equal to, unity.
             *  @pre    asyms_ must be the same size as wavelengths_.
             *  @pre    asyms_ must all greater than, or equal to, minus one.
             *  @pre    asyms_ must all less than, or equal to, unity.
             */
            inline Simple::Simple(const std::vector<double>& wavelengths_, const std::vector<double>& ref_indexs_, const std::vector<double>& dists_, const std::vector<double>& albedos_, const std::vector<double>& asyms_) noexcept
              : Mat(wavelengths_.front(), wavelengths_.back())
              , _ref_index(wavelengths_, ref_indexs_)
              , _dist(wavelengths_, dists_)
              , _albedo(wavelengths_, albedos_)
              , _asym(wavelengths_, asyms_)
            {
                assert(prop::limits::always_greater_than(wavelengths_, 0.0));
                assert(prop::order::ascending(wavelengths_));
                assert(ref_indexs_.size() == wavelengths_.size());
                assert(prop::limits::always_greater_than_or_equal_to(ref_indexs_, 1.0));
                assert(dists_.size() == wavelengths_.size());
                assert(prop::limits::always_greater_than(dists_, 0.0));
                assert(albedos_.size() == wavelengths_.size());
                assert(prop::limits::always_greater_than_or_equal_to(albedos_, 0.0));
                assert(prop::limits::always_less_than_or_equal_to(albedos_, 1.0));
                assert(asyms_.size() == wavelengths_.size());
                assert(prop::limits::always_greater_than_or_equal_to(asyms_, -1.0));
                assert(prop::limits::always_less_than_or_equal_to(asyms_, 1.0));
            }



            //  == METHODS ==
            //  -- Specific Optical Properties --
            /**
             *  Generate specific-optical-proeprties for a given photon.
             *
             *  @param  phot_   Photon to generate specific-optical-proeprties for.
             *
             *  @return Specific-optical-properties for the given photon.
             */
            inline std::unique_ptr<Sop> Simple::gen(const phys::Photon& phot_) const noexcept
            {
                return (std::make_unique<sop::Simple>(_ref_index(phot_->wavelength()), _dist(phot_->wavelength()), _albedo(phot_->wavelength()), _asym(phot_->wavelength())));
            }



        } // namespace mat
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_MAT_SIMPLE_INL
