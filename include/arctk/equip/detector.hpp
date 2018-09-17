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
            //  -- Data --
            const std::string& _name;

            //  -- Structure --
            const geom::Shape& _surf;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Detector(const std::string& name_, const geom::Shape& shape_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::string& name() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Detector::Detector(const std::string& name_, const geom::Shape& shape_) noexcept
          : _name(name_)
          , _surf(shape_)
        {
        }



        //  == METHODS ==
        //  -- Getters --
        inline const std::string& Detector::name() const noexcept
        {
            return (_name);
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_DETECTOR_HPP
