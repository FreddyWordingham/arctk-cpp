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
            inline Mat(const Mat&) noexcept = default; //!< Defaulted copy constructor.
            inline Mat(Mat&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Mat() noexcept;

            //  -- Cloning --
            virtual std::unique_ptr<Block> clone() const = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Mat& operator=(const Mat&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Mat& operator=(Mat&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


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
