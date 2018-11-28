/**
 *  @file   arctk/opt/mat.hpp
 *  @date   28/11/2018
 *  @author Freddy Wordingham
 *
 *  Optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MAT_HPP
#define ARCTK_OPT_MAT_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>



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
            inline Mat(const Mat&) noexcept = default; //!< Defaulted copy constructor.
            inline Mat(Mat&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Mat() noexcept;

            //  -- Cloning --
            virtual std::unique_ptr<Mat> clone() const = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Mat& operator=(const Mat&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Mat& operator=(Mat&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual std::unique_ptr<Driver> driver() const noexcept = 0;
        };



    } // namespace dom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/dom/mat.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_MAT_HPP
