/**
 *  @file   arctk/phys/mat/dumb.hpp
 *  @date   12/10/2018
 *  @author Freddy Wordingham
 *
 *  Dumb optical-properties material class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_MAT_DUMB_HPP
#define ARCTK_PHYS_MAT_DUMB_HPP



//  == IMPORTS ==
//  -- Std --
#include <limits>
#include <memory>

//  -- Arctk --
#include <arctk/phys/mat.hpp>
#include <arctk/phys/photon.hpp>
#include <arctk/phys/sop.hpp>
#include <arctk/phys/sop/dumb.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        namespace mat //! material namespace
        {



            //  == CLASS ==
            /**
             *  Material with dumb optical properties.
             */
            class Dumb : public Mat
            {
                //  == INSTANTIATION ==
              private:
                //  -- Optical Properties --
                const double _ref_index; //!< Refractive index.
                const double _dist;      //!< Interaction distance.
                const double _albedo;
                const double _asym;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Dumb(double ref_index_, double dist_, double albedo_, double asym_) noexcept;


                //  == METHODS ==
              public:
                //  -- Specific Optical Properties --
                inline std::unique_ptr<Sop> gen(const Photon& /*unused*/) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Dumb::Dumb(const double ref_index_, const double dist_, const double albedo_, const double asym_) noexcept
              : Mat(0.0, std::numeric_limits<double>::max())
              , _ref_index(ref_index_)
              , _dist(dist_)
              , _albedo(albedo_)
              , _asym(asym_)
            {
                PRE(ref_index_ >= 1.0);
                PRE(dist_ > 0.0);
                PRE((albedo_ >= 0.0) || (albedo_ <= 1.0));
                PRE((asym_ >= -1.0) || (asym_ <= 1.0));
            }



            //  == METHODS ==
            //  -- Specific Optical Properties --
            /**
             *  Generate specific-optical-proeprties for a given photon.
             *
             *  @return Specific-optical-properties for the given photon.
             */
            inline std::unique_ptr<Sop> Dumb::gen(const Photon& /*unused*/) const noexcept
            {
                return (std::make_unique<sop::Dumb>(_ref_index, _dist, _albedo, _asym));
            }



        } // namespace mat
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MAT_DUMB_HPP
