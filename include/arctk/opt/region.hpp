/**
 *  @file   arctk/opt/region.hpp
 *  @date   26/11/2018
 *  @author Freddy Wordingham
 *
 *  Optical region class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_REGION_HPP
#define ARCTK_OPT_REGION_HPP



//  == BASE ==
#include <arctk/geom/shape/box.hpp>



//  == IMPORTS ==
//  -- Std --
#include <array>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace math //! math namespace
    {
        template <typename T, size_t N>
        class Vec;
    } // namespace math
    //  == ALIASES ==
    using vec3 = math::Vec<double, 3>; //!< Three-dimensional double precision vec.
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {



        //  == CLASS ==
        /**
         *  Optical region class.
         */
        class Region : public geom::shape::Box
        {
            //  == FIELDS ==
          private:
            //  -- Blocks --
            const std::array<size_t, 3> _res;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Region(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) noexcept;


            //  == METHODS ==
          private:
            //  -- Getters --
            inline const std::array<size_t, 3>& res() const noexcept;
        };



    } // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/region.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_REGION_HPP
