/**
 *  @file   arctk/phys/material/basic.hpp
 *  @date   16/08/2018
 *  @author Freddy Wordingham
 *
 *  basic material physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_MATERIAL_BASIC_HPP
#define ARCTK_PHYS_MATERIAL_BASIC_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>
#include <arctk/phys/material.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        namespace material //! material namespace
        {



            //  == CLASS ==
            /**
             *  Basic material particle class.
             */
            class Basic : public Material
            {
                //  == FIELDS ==
              private:
                //  -- Optical --
                const math::formula::Linear _ref_index;
                const math::formula::Linear _interact_coef;
                const math::formula::Linear _albedo;
                const math::formula::Linear _asym;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Basic(std::vector<double>& wavelength_, std::vector<double>& ref_index_, std::vector<double>& scat_coef_, std::vector<double>& abs_coef, std::vector<double>& asym_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Basic::Basic(std::vector<double>& wavelength_, std::vector<double>& ref_index_, std::vector<double>& scat_coef_, std::vector<double>& abs_coef, std::vector<double>& asym_) noexcept
              : _Material(wavelength_.front(), wavelength_.back())
              , _ref_index(math::formula::Linear(wavelength_, ref_index_))
              , _interact_coef(init_coef(wavelength_, scat_coef_, abs_coef))
              , _albedo(init_albedo(wavelength_, scat_coef_, abs_coef))
              , _asym(math::formula::Linear(wavelength_, asym_))
            {
                PRE(wavelength_.size() > 1);
                PRE(ref_index_.size() > 1);
                PRE(scat_coef_.size() > 1);
                PRE(abs_coef.size() > 1);
                PRE(asym_.size() > 1);
                PRE(wavelength_.size() == ref_index_.size());
                PRE(wavelength_.size() == scat_coef_.size());
                PRE(wavelength_.size() == abs_coef.size());
                PRE(wavelength_.size() == asym_.size());
                PRE(utl::properties::ascending(wavelength_));
            }



            //  == METHODS ==
            //  -- Getters --



        } // namespace material
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_BASIC_HPP
