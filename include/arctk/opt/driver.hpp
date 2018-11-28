/**
 *  @file   arctk/dom/driver.hpp
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Photon controller class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_DRIVER_HPP
#define ARCTK_DOM_DRIVER_HPP



//  == IMPORTS ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == CLASS ==
        /**
         *  Photon controller class.
         */
        class Driver
        {
            //  == FIELDS ==
          protected:
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Driver(const Driver&) noexcept = default; //!< Defaulted copy constructor.
            inline Driver(Driver&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Driver() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Driver& operator=(const Driver&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Driver& operator=(Driver&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
        };



    } // namespace dom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/dom/driver.inl>



//  == GUARD END ==
#endif // ARCTK_DOM_DRIVER_HPP
