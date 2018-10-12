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
#include <memory>

//  -- Arctk --
#include <arctk/phys/mat.hpp>
#include <arctk/phys/photon.hpp>
#include <arctk/phys/sop.hpp>



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
            class Dumb : public Sop
            {
                //  == INSTANTIATION ==
              private:
                //  -- Optical Properties --
                const double _dist;
                const double _albedo;
                const double _asym;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Dumb(double ref_index_, double dist_, double albedo_ = 1.0, double asym_ = 1.0) noexcept;


                //  == METHODS ==
              public:
                //  -- Specific Optical Properties --
                virtual std::unique_ptr<Sop> gen(const Photon& phot_) const noexcept = 0;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Dumb::Dumb(const double ref_index_, const double dist_, const double albedo_, const double asym_) noexcept
              : Sop(ref_index_)
              , _dist(dist_)
              , _albedo(albedo_)
              , _asym(asym_)
            {
                PRE(ref_index_ >= 1.0);
                PRE(dist_ > 0.0);
                PRE((albedo_ >= 0.0) || (albedo_ <= 1.0));
                PRE((asym_ >= -1.0) || (asym_ <= 1.0));
            }



        } // namespace mat
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MAT_DUMB_HPP
