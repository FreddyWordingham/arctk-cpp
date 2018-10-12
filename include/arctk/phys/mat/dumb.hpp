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
            class Dumb
            {
                //  == INSTANTIATION ==
              private:
                //  -- Optical Properties --


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Dumb() noexcept;


                //  == METHODS ==
              public:
                //  -- Specific Optical Properties --
                virtual std::unique_ptr<Sop> gen(const Photon& phot_) const noexcept = 0;
            };



            //  == INSTANTIATION ==
            //  -- Destructors --



        } // namespace mat
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MAT_DUMB_HPP
