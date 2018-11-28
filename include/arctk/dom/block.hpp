/**
 *  @file   arctk/dom/block.hpp
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain discretisation material block class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_BLOCK_HPP
#define ARCTK_DOM_BLOCK_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <string>
#include <unordered_map>

//  -- Arctk --
#include <arctk/dom/driver.hpp>
#include <arctk/dom/mat.hpp>
#include <arctk/geom/shape/box.hpp>
#include <arctk/math/vec.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        class Photon;
    } // namespace phys
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == CLASS ==
        /**
         *  Domain discretisation material block class.
         */
        class Block : geom::shape::Box
        {
            //  == FIELDS ==
          protected:
            //  -- Materials --
            std::unordered_map<std::string, std::unique_ptr<Mat>> _mats;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Block(const vec3& min_, const vec3& max_, const std::string& aether_id_, const Mat& aether_) noexcept;
            inline Block(const Block&)     = default; //!< Defaulted copy constructor.
            inline Block(Block&&) noexcept = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Block() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Block& operator=(const Block&) = default;     //!< Defaulted copy operator. @return Reference to copied object.
            inline Block& operator=(Block&&) noexcept = default; //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
        };



    } // namespace dom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/dom/block.inl>



//  == GUARD END ==
#endif // ARCTK_DOM_BLOCK_HPP
