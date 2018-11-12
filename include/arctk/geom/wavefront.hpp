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
#include <arctk/math/vec3.hpp>



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
            const std::string& _base;

            //  -- Transform --
            vec3 _scale;
            vec3 _rot;
            vec3 _trans;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Wavefront(const std::string& base_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const vec3& scale() const noexcept;
            inline const vec3& rot() const noexcept;
            inline const vec3& trans() const noexcept;
        };



    } // namespace geom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/geom/wavefront.inl>



//  == GUARD END ==
#endif // ARCTK_GEOM_WAVEFRONT_HPP
