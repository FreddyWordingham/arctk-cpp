/**
 *  @file   arctk/equip/entity/detector.hpp
 *  @date   12/11/2018
 *  @author Freddy Wordingham
 *
 *  Detector entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_DETECTOR_HPP
#define ARCTK_EQUIP_ENTITY_DETECTOR_HPP



//  == BASE ==
#include <arctk/equip/entity.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <string>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace entity //! entity namespace
        {



            //  == CLASS ==
            /**
             *  Detector entity equipment class.
             */
            class Detector : public Entity
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
                //  -- Saving --
                virtual void save(const std::string& path_) const noexcept = 0; //!< Save the output of the detector.    @param  path_   Path to the output file.    @pre    path_ may not be empty.
            };



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity/detector.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_DETECTOR_HPP
