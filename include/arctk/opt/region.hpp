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

//  -- Arctk --
#include <arctk/math/vec.hpp>



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
            const vec3                  _block_size;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Region(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) noexcept;
            inline Region(const Region&) = default; //!< Defaulted copy constructor.
            inline Region(Region&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Region() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Region& operator=(const Region&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Region& operator=(Region&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          private:
            //  -- Getters --
            inline const std::array<size_t, 3>& res() const noexcept;
            inline const vec3&                  block_size() const noexcept;

            //  -- Indexing --
            inline std::array<size_t, 3> block_index(const vec3& pos_) const noexcept;
        };



    } // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/region.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_REGION_HPP
