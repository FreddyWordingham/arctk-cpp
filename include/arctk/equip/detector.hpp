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
#include <memory>
#include <string>
#include <utility>

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
            std::unique_ptr<geom::Shape> _surf; //!< Shape forming the surface of the detector.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            template <typename T>
            inline explicit Detector(T&& surf_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const geom::Shape* surf() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a detector using surface shape.
         *
         *  @tparam T   Type used to form the surface.
         *
         *  @param  surf_   Surface of the detector.
         *
         *  @pre    T must be derived from geom::Shape.
         */
        template <typename T>
        inline Detector::Detector(T&& surf_) noexcept
          : _surf(std::make_unique<T>(surf_))
        {
            static_assert(std::is_base_of<geom::Shape, T>::value);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get a const reference to the shape forming the surface of the detector.
         *
         *  @return Const reference to the shape forming the surface of the detector.
         */
        inline const geom::Shape* Detector::surf() const noexcept
        {
            return (_surf.get());
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_DETECTOR_HPP
