/**
 *  @file   arctk/dom/mat.hpp
 *  @date   28/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain material class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_MAT_HPP
#define ARCTK_DOM_MAT_HPP



//  == IMPORTS ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == CLASS ==
        /**
         *  Domain material class.
         */
        class Mat
        {
            //  == FIELDS ==
          protected:
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            // inline Block(const Block&) noexcept = default; //!< Defaulted copy constructor.
            // inline Block(Block&&) noexcept      = default; //!< Defaulted move constructor.

            // //  -- Destructors --
            // virtual ~Block() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            // inline Block& operator=(const Block&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            // inline Block& operator=(Block&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
        };



    } // namespace dom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/dom/mat.inl>



//  == GUARD END ==
#endif // ARCTK_DOM_MAT_HPP
