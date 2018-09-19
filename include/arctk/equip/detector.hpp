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
//  -- Std --
#include <string>

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
        class Detector
        {
            //  == FIELDS ==
          private:
            //  -- Structure --
            const std::unique_ptr<geom::Shape> _surf; //!< Shape forming the surface of the detector.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Detector(const geom::Shape& surf_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const geom::Shape& surf() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a detector using surface shape.
         *
         *  @param  surf_   Surface of the detector.
         */
        inline Detector::Detector(const geom::Shape& surf_) noexcept
          : _surf(surf_)
        {
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get a const reference to the shape forming the surface of the detector.
         *
         *  @return Const reference to the shape forming the surface of the detector.
         */
        inline const geom::Shape& Detector::surf() const noexcept
        {
            return (_surf);
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_DETECTOR_HPP
