/**
 *  @file   arctk/geom/wavefront.hpp
 *  @date   12/11/2018
 *  @author Freddy Wordingham
 *
 *  Wavefront reader helper class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_WAVEFRONT_HPP
#define ARCTK_GEOM_WAVEFRONT_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>

//  -- Arctk --
#include <arctk/math/vec.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
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
    namespace geom //! geometry namespace
    {



        //  == CLASS ==
        /**
         *  Wavefront helper class.
         */
        class Wavefront
        {
            //  == FIELDS ==
          private:
            //  -- File --
            const std::string& _file; //!< Path to base wavefront file to read from.

            //  -- Transform --
            vec3 _scale; //!< Scaleing transformation.
            vec3 _rot;   //!< Rotation transformation.
            vec3 _trans; //!< Translation transformation.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Wavefront(const std::string& file_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::string& file() const noexcept;
            inline const vec3&        scale() const noexcept;
            inline const vec3&        rot() const noexcept;
            inline const vec3&        trans() const noexcept;

            //  -- Setters --
            inline void set_scale(double scale_) noexcept;
            inline void set_scale(const vec3& scale_) noexcept;
            inline void set_rot(const vec3& rot_) noexcept;
            inline void set_trans(const vec3& trans_) noexcept;

            //  -- Creation --
            inline shape::Mesh create_mesh() const noexcept;
        };



    } // namespace geom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/geom/wavefront.inl>



//  == GUARD END ==
#endif // ARCTK_GEOM_WAVEFRONT_HPP
