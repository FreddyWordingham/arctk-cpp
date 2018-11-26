/**
 *  @file   arctk/opt/mat/dumb.inl
 *  @date   12/10/2018
 *  @author Freddy Wordingham
 *
 *  Dumb optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MAT_DUMB_INL
#define ARCTK_OPT_MAT_DUMB_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <limits>

//  -- Arctk --
#include <arctk/opt/sop/dumb.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {
        namespace mat //! material namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a dumb material.
             *
             *  @param  ref_index_  Refractive index.
             *  @param  dist_       Interaction distance.
             *  @param  albedo_     Single scattering albedo.
             *  @param  asym_       Asymmetry factor.
             *
             *  @pre    ref_index_ must be greater than, or equal to, unity.
             *  @pre    dist_ must be positive.
             *  @pre    albedo_ must be positive.
             *  @pre    albedo_ must less than, or equal to, unity.
             *  @pre    asym_ must greater than, or equal to, minus one.
             *  @pre    asym_ must less than, or equal to, unity.
             */
            inline Dumb::Dumb(const double ref_index_, const double dist_, const double albedo_, const double asym_) noexcept
              : Mat(0.0, std::numeric_limits<double>::max())
              , _ref_index(ref_index_)
              , _dist(dist_)
              , _albedo(albedo_)
              , _asym(asym_)
            {
                assert(ref_index_ >= 1.0);
                assert(dist_ > 0.0);
                assert(albedo_ >= 0.0);
                assert(albedo_ <= 1.0);
                assert(asym_ >= -1.0);
                assert(asym_ <= 1.0);
            }



            //  == METHODS ==
            //  -- Specific Optical Properties --
            /**
             *  Generate specific-optical-proeprties for a given photon.
             *
             *  @return Specific-optical-properties for the given photon.
             */
            inline std::unique_ptr<Sop> Dumb::gen(const phys::Photon& /*unused*/) const noexcept
            {
                return (std::make_unique<sop::Dumb>(_ref_index, _dist, _albedo, _asym));
            }



        } // namespace mat
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_MAT_DUMB_INL
