/**
 *  @file   arctk/opt/driver.hpp
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Optical controller class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_DRIVER_HPP
#define ARCTK_OPT_DRIVER_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {



        //  == CLASS ==
        /**
         *  Optical controller class.
         */
        class Driver
        {
            //  == FIELDS ==
          protected:
            //  -- Base --

            //  -- Derived --
            const double _interaction_coef;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Driver() noexcept;
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



    } // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/driver.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_DRIVER_HPP
