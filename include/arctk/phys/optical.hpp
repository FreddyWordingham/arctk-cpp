/**
 *  @file   arctk/phys/optical.hpp
 *  @date   16/08/2018
 *  @author Freddy Wordingham
 *
 *  Optical physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_OPTICAL_HPP
#define ARCTK_PHYS_OPTICAL_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Physical particle class.
         */
        class Optical
        {
            //  == FIELDS ==
          private:
            //  -- Properties --
            double _ref_index{};     //!< Refractive index.
            double _interact_coef{}; //!< Interaction coefficient.
            double _albedo{};        //!< Single scattering albedo.
            double _asym{};          //!< Asymmetry parameter.
            double _change_prob{};   //!< Probability of changing state.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Optical() noexcept = default;
            inline Optical(double ref_index_, double interact_coef_, double albedo_, double asym_) noexcept;
            inline Optical(double ref_index_, double interact_coef_, double albedo_, double asym_, double change_prob_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double ref_index() const noexcept;
            inline double interact_coef() const noexcept;
            inline double albedo() const noexcept;
            inline double asym() const noexcept;
            inline double change_prob() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct an optical properties object with the basic optical properties.
         *
         *  @param  ref_index_      Refractive index.
         *  @param  interact_coef_  Interaction coefficient.
         *  @param  albedo_         Single scattering albedo.
         *  @param  asym_           Asymmetry parameter.
         */
        inline Optical::Optical(const double ref_index_, const double interact_coef_, const double albedo_, const double asym_) noexcept
          : _ref_index(ref_index_)
          , _interact_coef(interact_coef_)
          , _albedo(albedo_)
          , _asym(asym_)
        {
            PRE(ref_index_ > 0.0);
            PRE(interact_coef_ > 0.0);
            PRE((albedo_ >= 0.0) && (albedo_ <= 1.0));
            PRE((asym_ >= -1.0) && (asym_ <= 1.0));
        }

        inline Optical::Optical(const double ref_index_, const double interact_coef_, const double albedo_, const double asym_, const double change_prob_) noexcept
          : _ref_index(ref_index_)
          , _interact_coef(interact_coef_)
          , _albedo(albedo_)
          , _asym(asym_)
          , _change_prob(change_prob_)
        {
            PRE(ref_index_ > 0.0);
            PRE(interact_coef_ > 0.0);
            PRE((albedo_ >= 0.0) && (albedo_ <= 1.0));
            PRE((asym_ >= -1.0) && (asym_ <= 1.0));
            PRE((change_prob_ >= 0.0) && (change_prob_ <= 1.0));
        }



        //  == METHODS ==
        //  -- Getters --
        inline double Optical::ref_index() const noexcept
        {
            return (_ref_index);
        }

        inline double Optical::interact_coef() const noexcept
        {
            return (_interact_coef);
        }

        inline double Optical::albedo() const noexcept
        {
            return (_albedo);
        }

        inline double Optical::asym() const noexcept
        {
            return (_asym);
        }

        inline double Optical::change_prob() const noexcept
        {
            return (_change_prob);
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_OPTICAL_HPP
