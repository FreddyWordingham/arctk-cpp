/**
 *  @file   arctk/opt/mat/dumb.hpp
 *  @date   12/10/2018
 *  @author Freddy Wordingham
 *
 *  Dumb optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MAT_DUMB_HPP
#define ARCTK_OPT_MAT_DUMB_HPP



//  == BASE ==
#include <arctk/opt/mat.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>

//  -- Arctk --
#include <arctk/opt/sop.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace phys //! physics number namespace
    {
        class Photon;
    } // namespace phys
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
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
                const double _albedo;    //!< Single scattering albedo.
                const double _asym;      //!< Asymmetry factor.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Dumb(double ref_index_, double dist_, double albedo_, double asym_) noexcept;


                //  == METHODS ==
              public:
                //  -- Specific Optical Properties --
                inline std::unique_ptr<Sop> gen(const phys::Photon& /*unused*/) const noexcept override;
            };



        } // namespace mat
    }     // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/mat/dumb.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_MAT_DUMB_HPP
