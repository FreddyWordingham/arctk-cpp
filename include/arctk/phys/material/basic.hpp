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
                const math::formula::Linear _wavelength;
                const math::formula::Linear _ref_index;
                const math::formula::Linear _scat_coef;
                const math::formula::Linear _abs_coef;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==
            //  -- Getters --



        } // namespace material
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_BASIC_HPP
