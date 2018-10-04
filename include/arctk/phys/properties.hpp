/**
 *  @file   arctk/phys/properties.hpp
 *  @date   04/10/2018
 *  @author Freddy Wordingham
 *
 *  Optical properties physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_PROPERTIES_HPP
#define ARCTK_PHYS_PROPERTIES_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Optical properties class.
         */
        class Properties
        {
            //  == FIELDS ==
          private:
            //  -- Optical --
            const double _interaction_coef;
            const double _ref_index;
            const double _albedo;
            const double _asym;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Properties(double ref_index_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Properties::Properties(const double ref_index_) noexcept
          : _ref_index(ref_index_)
        {
            PRE(ref_index_ > 0.0);
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_PROPERTIES_HPP
