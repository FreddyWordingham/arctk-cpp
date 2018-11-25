/**
 *  @file   arctk/opt/mat/simple.hpp
 *  @date   29/10/2018
 *  @author Freddy Wordingham
 *
 *  Simple optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MAT_SIMPLE_HPP
#define ARCTK_OPT_MAT_SIMPLE_HPP



//  == BASE ==
#include <arctk/opt/mat.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <vector>

//  -- Arctk --
#include <arctk/math/formula/linear.hpp>
#include <arctk/opt/sop.hpp>



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
        namespace mat //! material namespace
        {



            //  == CLASS ==
            /**
             *  Material with simple optical properties.
             */
            class Simple : public Mat
            {
                //  == INSTANTIATION ==
              private:
                //  -- Optical Properties --
                const math::formula::Linear _ref_index;     //!< Refractive index.
                const math::formula::Linear _interact_coef; //!< Interaction distance.
                const math::formula::Linear _albedo;        //!< Single scattering albedo.
                const math::formula::Linear _asym;          //!< Asymmetry factor.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Simple(const std::vector<double>& wavelengths_, const std::vector<double>& ref_indexs_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_, const std::vector<double>& asyms_) noexcept;

              private:
                //  -- Initialisation --
                inline math::formula::Linear init_interact_coef(const std::vector<double>& wavelengths_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_) const noexcept;
                inline math::formula::Linear init_albedo(const std::vector<double>& wavelengths_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Specific Optical Properties --
                inline std::unique_ptr<Sop> gen(const phys::Photon& phot_) const noexcept override;
            };



        } // namespace mat
    }     // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/mat/simple.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_MAT_SIMPLE_HPP
