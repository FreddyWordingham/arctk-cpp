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
            const geom::Shape& _surf;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Detector(const geom::Shape& surf_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::string& name() const noexcept;
            inline const geom::Shape& surf() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a detector using surface shape.
         *
         *  @param  surf_
         *
         * @return
         */
        inline Detector::Detector(const geom::Shape& surf_) noexcept
          : _name(name_)
          , _surf(surf_)
        {
        }



        //  == METHODS ==
        //  -- Getters --
        inline const std::string& Detector::name() const noexcept
        {
            return (_name);
        }

        inline const geom::Shape& Detector::surf() const noexcept
        {
            return (_surf);
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_DETECTOR_HPP
