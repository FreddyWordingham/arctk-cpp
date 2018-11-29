/**
 *  @file   arctk/opt/material/elastic.hpp
 *  @date   28/11/2018
 *  @author Freddy Wordingham
 *
 *  Elastic scattering material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MATERIAL_ELASTIC_HPP
#define ARCTK_OPT_MATERIAL_ELASTIC_HPP



//  == BASE ==
#include <arctk/opt/material.hpp>



//  == IMPORTS ==
//  -- Arctk --



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
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
    namespace opt //! optical namespace
    {
        namespace material //! material namespace
        {



            //  == CLASS ==
            /**
             *  Elastic scattering material class.
             */
            class Elastic : public Material
            {
                //  == FIELDS ==
              private:
                //  -- Optical --



                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
            };



        } // namespace material
    }     // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/material/elastic.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_ELASTIC_HPP
