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



            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Func(T min_, T max_) noexcept;
            inline Func(const Func&) noexcept = default;
            inline Func(Func&&) noexcept      = default;

            //  -- Destructors --
            virtual inline ~Func() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Func& operator=(const Func&) noexcept = default;
            inline Func& operator=(Func&&) noexcept = default;

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
        template <typename T, typename S>
        inline Func<T, S>::Func(const T min_, const T max_) noexcept
          : _min(min_)
          , _max(max_)
        {
            PRE(min_ < max_);
        }


        //  -- Destructors --
        inline Func::~Func() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        template <typename T, typename S>
        inline T Func<T, S>::min() const noexcept
        {
            return (_min);
        }

        template <typename T, typename S>
        inline T Func<T, S>::max() const noexcept
        {
            return (_max);
        }



    } // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FUNC_HPP
