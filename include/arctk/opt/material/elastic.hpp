/**
 *  @file   arctk/opt/material/elastic.hpp
 *  @date   28/11/2018
 *  @author Freddy Wordingham
 *
 *  Elastic scattering material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MATERIAL_ELASTIC_HPP
#define ARCTK_OPT_MATERIAL_ELASTIC_HPP



//  == BASE ==
#include <arctk/opt/material.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <vector>

//  -- Arctk --
#include <arctk/math/formula/linear.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        class Photon;
    }                // namespace phys
    namespace random //! random number namespace
    {
        class Generator;
    } // namespace random
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {
        namespace material //! material namespace
        {



            //  == CLASS ==
            /**
             *  Elastic scattering material class.
             */
            class Elastic : public Material
            {
                //  == FIELDS ==
              private:
                //  -- Optical --
                math::formula::Linear _ref_index;
                math::formula::Linear _scat_coef;
                math::formula::Linear _abs_coef;
                math::formula::Linear _asym;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Elastic(const std::vector<double>& wavelengths_, const std::vector<double>& ref_indexs_, const std::vector<double>& scat_coefs_, const std::vector<double>& abs_coefs_, const std::vector<double>& asyms_) noexcept;

                //  -- Cloning --
                inline std::unique_ptr<Material> clone() const override;


                //  == METHODS ==
              public:
                //  -- Driver --
                inline std::unique_ptr<Driver> driver(const phys::Photon& phot_) noexcept override;

                //  -- Evolve --
                inline void evolve(double /*unused*/) noexcept override;
            };



        } // namespace material
    }     // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/material/elastic.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_ELASTIC_HPP
