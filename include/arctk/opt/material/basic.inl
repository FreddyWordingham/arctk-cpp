/**
 *  @file   arctk/opt/material/basic.inl
 *  @date   26/11/2018
 *  @author Freddy Wordingham
 *
 *  Basic optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MATERIAL_BASIC_INL
#define ARCTK_OPT_MATERIAL_BASIC_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <limits>

//  -- Arctk --
#include <arctk/opt/slice/basic.hpp>
#include <arctk/prop/limits.hpp>
#include <arctk/prop/order.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {
        namespace material //! material namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Basic::Basic(const double min_, const double max_, const double ref_index_, const double scat_coef_, const double abs_coef_, const double asym_) noexcept
              : Material(min_, max_)
              , _ref_index(std::vector<double>({min_, max_}), std::vector<double>({ref_index_, ref_index_}))
              , _scat_coef(std::vector<double>({min_, max_}), std::vector<double>({scat_coef_, scat_coef_}))
              , _abs_coef(std::vector<double>({min_, max_}), std::vector<double>({abs_coef_, abs_coef_}))
              , _asym(std::vector<double>({min_, max_}), std::vector<double>({asym_, asym_}))
            {
                assert(min_ >= 0.0);
                assert(max_ >= 0.0);
                assert(min_ <= max_);
                assert(ref_index_ >= 1.0);
                assert(scat_coef_ > 0.0);
                assert(abs_coef_ > 0.0);
                assert(asym_ >= -1.0);
                assert(asym_ <= 1.0);
            }

            inline Basic::Basic(const std::vector<double>& wavelengths_, const std::vector<double>& ref_indexs_, const std::vector<double>& scat_coefs_, const std::vector<double>& abs_coefs_, const std::vector<double>& asyms_) noexcept
              : Material(wavelengths_.front(), wavelengths_.back())
              , _ref_index(wavelengths_, ref_indexs_)
              , _scat_coef(wavelengths_, scat_coefs_)
              , _abs_coef(wavelengths_, abs_coefs_)
              , _asym(wavelengths_, asyms_)
            {
                assert(prop::limits::always_greater_than_or_equal_to(wavelengths_, 0.0));
                assert(prop::order::ascending(wavelengths_));
                assert(ref_indexs_.size() == wavelengths_.size());
                assert(prop::limits::always_greater_than_or_equal_to(ref_indexs_, 1.0));
                assert(scat_coefs_.size() == wavelengths_.size());
                assert(prop::limits::always_greater_than(scat_coefs_, 0.0));
                assert(abs_coefs_.size() == wavelengths_.size());
                assert(prop::limits::always_greater_than(abs_coefs_, 0.0));
                assert(asyms_.size() == wavelengths_.size());
                assert(prop::limits::always_greater_than_or_equal_to(asyms_, -1.0));
                assert(prop::limits::always_less_than_or_equal_to(asyms_, 1.0));
            }



            //  == METHODS ==
            //  -- Specific Optical Properties --
            inline std::unique_ptr<Slice> Basic::slice(const phys::Photon& phot_) const noexcept
            {
                return (std::make_unique<slice::Basic>(_ref_index(phot_.wavelength()), _scat_coef(phot_.wavelength()), _abs_coef(phot_.wavelength()), _asym(phot_.wavelength())));
            }



        } // namespace material
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_BASIC_INL
