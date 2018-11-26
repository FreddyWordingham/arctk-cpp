/**
 *  @file   arctk/opt/block.hpp
 *  @date   26/11/2018
 *  @author Freddy Wordingham
 *
 *  Local information class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_BLOCK_HPP
#define ARCTK_OPT_BLOCK_HPP



//  == IMPORTS ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {



        //  == CLASS ==
        /**
         *  Local information cell.
         */
        class Block
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Block()             = default; //!< Defaulted constructor.
            inline Block(const Block&) = default; //!< Defaulted copy constructor.
            inline Block(Block&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Block() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Block& operator=(const Block&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Block& operator=(Block&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
        };



    } // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/block.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_BLOCK_HPP
