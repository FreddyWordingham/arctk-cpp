/**
 *  @file   arctk/dom/block.hpp
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain discretisation block class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_BLOCK_HPP
#define ARCTK_DOM_BLOCK_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>

//  -- Arctk --
#include <arctk/dom/driver.hpp>



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
         *  Domain discretisation block class.
         */
        class Block
        {
            //  == FIELDS ==
          protected:
            //  -- Data --
            double _energy;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Block(const Block&) noexcept = default; //!< Defaulted copy constructor.
            inline Block(Block&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Block() noexcept;

            //  -- Cloning --
            virtual std::unique_ptr<Block> clone() const = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Block& operator=(const Block&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Block& operator=(Block&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual std::unique_ptr<Driver> driver(const phys::Photon& phot_) const noexcept = 0;
        };



    } // namespace dom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/dom/block.inl>



//  == GUARD END ==
#endif // ARCTK_DOM_BLOCK_HPP
