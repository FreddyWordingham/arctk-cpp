/**
 *  @file   arctk/opt/material/elastic.inl
 *  @date   28/11/2018
 *  @author Freddy Wordingham
 *
 *  Elastic scattering material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MATERIAL_ELASTIC_INL
#define ARCTK_OPT_MATERIAL_ELASTIC_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {
        namespace material //! material namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Elastic::Elastic(const std::vector<double>& wavelengths_, const std::vector<double>& ref_indexs_, const std::vector<double>& scat_coefs_, const std::vector<double>& abs_coefs_, const std::vector<double>& asyms_) noexcept
              : _ref_index(wavelengths_, ref_indexs_)
              , _scat_coef(wavelengths_, scat_coefs_)
              , _abs_coef(wavelengths_, abs_coefs_)
              , _asym(wavelengths_, asyms_)
            {
            }



        } // namespace material
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_ELASTIC_INL
