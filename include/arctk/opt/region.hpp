/**
 *  @file   arctk/opt/region.hpp
 *  @date   26/11/2018
 *  @author Freddy Wordingham
 *
 *  Optical region class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_REGION_HPP
#define ARCTK_OPT_REGION_HPP



//  == BASE ==
#include <arctk/geom/shape/box.hpp>



//  == IMPORTS ==
//  -- Std --
#include <array>



//  == CLASS PROTOTYPES ==



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {



        //  == CLASS ==
        /**
         *  Optical region class.
         */
        class Region : public geom::shape::Box
        {
            //  == FIELDS ==
          private:
            //  -- Blocks --
            const std::array<size_t, 3> _res;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          private:
        };



    } // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/region.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_REGION_HPP
