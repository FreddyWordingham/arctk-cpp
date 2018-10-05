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
            inline double interaction_coef() const noexcept;
            inline double ref_index() const noexcept;
            inline double albedo() const noexcept;
            inline double asym() const noexcept;
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
        inline double Properties::interaction_coef() const noexcept
        {
            return (_interaction_coef);
        }

        inline double Properties::ref_index() const noexcept
        {
            return (_ref_index);
        }

        inline double Properties::albedo() const noexcept
        {
            return (_albedo);
        }

        inline double Properties::asym() const noexcept
        {
            rtyrb
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_PROPERTIES_HPP
