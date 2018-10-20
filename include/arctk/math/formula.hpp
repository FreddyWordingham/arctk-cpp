/**
 *  @file   arctk/math/formula.hpp
 *  @date   11/08/2018
 *  @author Freddy Wordingham
 *
 *  Math function class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_FORMULA_HPP
#define ARCTK_MATH_FORMULA_HPP



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Mathematical function class.
         */
        class Formula
        {
            //  == FIELDS ==
          protected:
            //  -- Bounds --
            const double _min; //!< Minimum valid bound of the funcs domain.
            const double _max; //!< Maximum valid bound of the funcs domain.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Formula(double min_, double max_) noexcept;
            inline Formula(const Formula&) noexcept = default; //!< Defaulted copy constructor.
            inline Formula(Formula&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Formula() noexcept = default;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Formula& operator=(const Formula&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Formula& operator=(Formula&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.

            //  -- Call --
            virtual inline double operator()(double val_) const noexcept = 0; //!< Determine the result of the function for a given value. @param  val_    Domain value of the function.   @return Result of the func for the given value.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double min() const noexcept;
            inline double max() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a formula with given domain bounds.
         *
         *  @param  min_    Minimum domain bound of the formula.
         *  @param  max_    Maximum domain bound of the formula.
         *
         *  @pre    min_ must be less than max_.
         */
        inline Formula::Formula(const double min_, const double max_) noexcept
          : _min(min_)
          , _max(max_)
        {
            assert(min_ < max_);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum bound of the formula.
         *
         *  @return Minimum bound of the formula.
         */
        inline double Formula::min() const noexcept
        {
            return (_min);
        }

        /**
         *  Get the maximum bound of the formula.
         *
         *  @return Maximum bound of the formula.
         */
        inline double Formula::max() const noexcept
        {
            return (_max);
        }



    } // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FORMULA_HPP
