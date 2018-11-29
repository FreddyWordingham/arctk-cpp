/**
 *  @file   arctk/opt/driver/elastic.inl
 *  @date   28/11/2018
 *  @author Freddy Wordingham
 *
 *  Elastic scattering controller class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_DRIVER_ELASTIC_INL
#define ARCTK_OPT_DRIVER_ELASTIC_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {
        namespace driver //! driver namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Elastic::Elastic(const std::vector<double>& wavelengths_, const std::vector<double>& ref_indexs_, const std::vector<double>& scat_coefs_, const std::vector<double>& abs_coefs_, const std::vector<double>& asyms_) noexcept
              : _ref_index(wavelengths_, ref_indexs_)
              , _scat_coef(wavelengths, scat_coefs_)
              , _abs_coef(wavelengths, abs_coefs_)
              , _asym(wavelengths, asyms_)
            {
            }



        } // namespace driver
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_DRIVER_ELASTIC_INL
