/**
 *  @file   arctk/equip/detector.hpp
 *  @date   17/09/2018
 *  @author Freddy Wordingham
 *
 *  Detector equipment base class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_DETECTOR_HPP
#define ARCTK_EQUIP_DETECTOR_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/geom.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {



        //  == CLASS ==
        /**
         *  Detector class.
         */
        class Detector : public geom::Shape
        {
            //  == FIELDS ==
          private:
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_DETECTOR_HPP
