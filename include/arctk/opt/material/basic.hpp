/**
 *  @file   arctk/opt/material/basic.hpp
 *  @date   26/11/2018
 *  @author Freddy Wordingham
 *
 *  Basic optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MATERIAL_BASIC_HPP
#define ARCTK_OPT_MATERIAL_BASIC_HPP



//  == BASE ==
#include <arctk/opt/material.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <vector>

//  -- Arctk --
#include <arctk/math/formula/linear.hpp>
#include <arctk/opt/slice.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        class Photon;
    } // namespace phys
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {
        namespace material //! material namespace
        {



            //  == CLASS ==
            /**
             *  Material with basic optical properties.
             */
            class Basic : public Material
            {
                //  == INSTANTIATION ==
              private:
                //  -- Optical Properties --
                const math::formula::Linear _ref_index; //!< Refractive index.
                const math::formula::Linear _scat_coef; //!< Scattering coefficient.
                const math::formula::Linear _abs_coef;  //!< Absorption coefficient.
                const math::formula::Linear _asym;      //!< Asymmetry factor.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Basic(double min_, double max_, double ref_index_, double scat_coef_, double abs_coef_, double asym_) noexcept;
                inline Basic(const std::vector<double>& wavelengths_, const std::vector<double>& ref_indexs_, const std::vector<double>& scat_coefs_, const std::vector<double>& abs_coefs_, const std::vector<double>& asyms_) noexcept;


                //  == METHODS ==
              public:
                //  -- Specific Optical Properties --
                // inline std::unique_ptr<Slice> slice(const phys::Photon& phot_) const noexcept override;
            };



        } // namespace material
    }     // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/material/basic.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_BASIC_HPP
