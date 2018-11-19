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
#include <string>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace geom //! geometric namespace
    {
        namespace shape //! shape namespace
        {
            class Mesh;
        } // namespace shape
    }     // namespace geom
} // namespace arc



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
                inline Detector(const geom::shape::Mesh& surf_) noexcept;
                inline Detector(const Detector&) = default; //!< Defaulted copy constructor.
                inline Detector(Detector&&)      = default; //!< Defaulted move constructor.

                //  -- Destructors --
                inline ~Detector() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Detector& operator=(const Detector&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Detector& operator=(Detector&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


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
