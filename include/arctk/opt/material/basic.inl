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
#include <arctk/opt/sop/simple.hpp>
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
            inline Simple::Simple(const std::vector<double>& wavelengths_, const std::vector<double>& ref_indexs_, const std::vector<double>& scat_coefs_, const std::vector<double>& abs_coefs_, const std::vector<double>& asyms_) noexcept
              : Material(wavelengths_.front(), wavelengths_.back())
              , _ref_index(wavelengths_, ref_indexs_)
              , _scat_coefs(wavelengths_, scat_coefs_)
              , _abs_coefs(wavelengths_, abs_coefs_)
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


            //  -- Initialisation --



            //  == METHODS ==



        } // namespace material
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_BASIC_INL
