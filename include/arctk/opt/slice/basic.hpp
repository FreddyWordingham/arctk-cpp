/**
 *  @file   arctk/opt/slice/basic.hpp
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Basic specific optical properties class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_SLICE_BASIC_HPP
#define ARCTK_OPT_SLICE_BASIC_HPP



//  == BASE ==
#include <arctk/opt/slice.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    class Block;
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
    namespace opt //! optics namespace
    {
        namespace slice //! specific optical properties namespace
        {



            //  == CLASS ==
            /**
             *  Basic specific optical properties.
             */
            class Basic : public Slice
            {
                //  == INSTANTIATION ==
              private:
                //  -- Primary Optical Properties --
                const double _ref_index; //!< Refractive index.
                const double _scat_coef; //!< Scattering coefficient.
                const double _abs_coef;  //!< Absorption coefficient.
                const double _asym;      //!< Asymmetry factor.

                //  -- Secondary Optical Properties --
                const double _interaction_coef;
                const double _albedo;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Basic(double ref_index_, double scat_coef_, double abs_coef_, double asym_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double ref_index() const noexcept override;
                inline double scat_coef() const noexcept override;
                inline double abs_coef() const noexcept override;
                inline double interaction_coef() const noexcept override;
                inline double interaction_dist(random::Generator* rng_, const Block* block_) const noexcept override;

                //  -- Interaction --
                inline bool interact(random::Generator* rng_, Block* block_, phys::Photon* phot_, double dist_) const noexcept override;
            };



        } // namespace slice
    }     // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/slice/basic.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_SLICE_BASIC_HPP
