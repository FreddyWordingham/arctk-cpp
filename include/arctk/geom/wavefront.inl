/**
 *  @file   arctk/geom/wavefront.inl
 *  @date   12/11/2018
 *  @author Freddy Wordingham
 *
 *  Wavefront reader helper class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_WAVEFRONT_INL
#define ARCTK_GEOM_WAVEFRONT_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/geom/shape/mesh.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a wavefront helper object.
         *
         *  @param  file_   Path to the base wavefront file.
         *
         *  @pre    file_ may not be empty.
         */
        inline Wavefront::Wavefront(const std::string& file_) noexcept
          : _file(file_)
          , _scale(1.0, 1.0, 1.0)
          , _rot(0.0, 0.0, 0.0)
          , _trans(0.0, 0.0, 0.0)
        {
            assert(!file_.empty());
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the file path to the base wavefront file.
         *
         *  @return File path to the base wavefront file.
         */
        inline const std::string& Wavefront::file() const noexcept
        {
            return (_file);
        }

        inline const vec3& Wavefront::scale() const noexcept
        {
            return (_scale);
        }

        inline const vec3& Wavefront::rot() const noexcept
        {
            return (_rot);
        }

        inline const vec3& Wavefront::trans() const noexcept
        {
            return (_trans);
        }


        //  -- Setters --
        inline void Wavefront::set_scale(const double scale_) noexcept
        {
            _scale = vec3(scale_, scale_, scale_);
        }

        inline void Wavefront::set_scale(const vec3& scale_) noexcept
        {
            _scale = scale_;
        }

        inline void Wavefront::set_rot(const vec3& rot_) noexcept
        {
            _rot = rot_;
        }

        inline void Wavefront::set_trans(const vec3& trans_) noexcept
        {
            _trans = trans_;
        }


        //  -- Creation --
        inline shape::Mesh Wavefront::create_mesh() const noexcept
        {
            return (shape::Mesh(_file, _scale, _rot, _trans));
        }



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_WAVEFRONT_INL
