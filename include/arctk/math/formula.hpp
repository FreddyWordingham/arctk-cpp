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



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Mathematical function class.
         *
         *  @tparam T   Type of func domain.
         *  @tparam S   Type returned from the func.
         */
        template <typename T, typename S>
        class Formula
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            const T _min; //!< Minimum valid bound of the funcs domain.
            const T _max; //!< Maximum valid bound of the funcs domain.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Formula(T min_, T max_) noexcept;
            inline Formula(const Formula&) noexcept = default; //!< Defaulted copy constructor.
            inline Formula(Formula&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Formula() noexcept = default;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Formula& operator=(const Formula&) noexcept = default;
            inline Formula& operator=(Formula&&) noexcept = default;

            //  -- Call --
            virtual S operator()(T val_) noexcept = 0; //!< Determine the result of the function for a given value. @param  val_    Domain value of the function.   @return Result of the func for the given value.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline T min() const noexcept;
            inline T max() const noexcept;
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
        template <typename T, typename S>
        inline Formula<T, S>::Formula(const T min_, const T max_) noexcept
          : _min(min_)
          , _max(max_)
        {
            PRE(min_ < max_);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum bound of the formula.
         *
         *  @return Minimum bound of the formula.
         */
        template <typename T, typename S>
        inline T Formula<T, S>::min() const noexcept
        {
            return (_min);
        }

        /**
         *  Get the maximum bound of the formula.
         *
         *  @return Maximum bound of the formula.
         */
        template <typename T, typename S>
        inline T Formula<T, S>::max() const noexcept
        {
            return (_max);
        }



    } // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FORMULA_HPP
