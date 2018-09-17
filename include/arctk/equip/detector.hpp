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
        class Detector : public geom::Shape
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const std::string& _name;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Detector(const std::string& name_, const geom::Shape& shape_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Detector::Detector(const std::string& name_, const geom::Shape& shape_) noexcept
          : geom::Shape(shape_)
          , _name(name_)
        {
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_DETECTOR_HPP
