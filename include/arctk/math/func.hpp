/**
 *  @file   arctk/math/func.hpp
 *  @date   11/08/2018
 *  @author Freddy Wordingham
 *
 *  Math function class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_FUNC_HPP
#define ARCTK_MATH_FUNC_HPP



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
        class Func
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            const T _min; //!< Minimum valid bound of the funcs domain.
            const T _max; //!< Maximum valid bound of the funcs domain.


            //  == OPERATORS ==
          public:
            //  -- Call --
            virtual S operator()(const T val_) noexcept = 0; //!< Determine the result of the function for a given value. @param  val_    Domain value of the function.   @return Result of the func for the given value.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline T min() const noexcept;
            inline T max() const noexcept;
        };



        //  == METHODS ==
        //  -- Getters --
        inline T Func::min() const noexcept
        {
            return (_min);
        }

        inline T Func::max() const noexcept
        {
        }



    } // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FUNC_HPP
