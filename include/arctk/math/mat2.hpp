/**
 *  @file   arctk/math/mat2.hpp
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical two-by-two matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT2_HPP
#define ARCTK_MATH_MAT2_HPP



//  == BASE ==
#include <arctk/math/mat.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cstddef>

//  -- Arctk --
#include <arctk/math/vec2.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Two-by-two mathematical square matrix class.
         *
         *  @tparam T   Type stored by the mat.
         */
        template <typename T>
        class Mat<T, 2>
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            Vec<T, 2> x{}; //!< X-row of matrix.
            Vec<T, 2> y{}; //!< Y-row of matrix.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Mat() noexcept = default;
            constexpr inline Mat(const Vec<T, 2>& x_, const Vec<T, 2>& y_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Printing --
            template <typename S>
            friend constexpr inline std::ostream& operator<<(std::ostream& stream_, const Mat<S, 2>& mat_) noexcept;

            //  -- Assignment --
            constexpr inline Mat<T, 2>& operator+=(T val_) noexcept;
            constexpr inline Mat<T, 2>& operator+=(const Mat<T, 2>& mat_) noexcept;
            constexpr inline Mat<T, 2>& operator-=(T val_) noexcept;
            constexpr inline Mat<T, 2>& operator-=(const Mat<T, 2>& mat_) noexcept;
            constexpr inline Mat<T, 2>& operator*=(T val_) noexcept;
            constexpr inline Mat<T, 2>& operator*=(const Mat<T, 2>& mat_) noexcept;
            constexpr inline Mat<T, 2>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Mat<T, 2>&      operator++() noexcept;
            constexpr inline const Mat<T, 2> operator++(int) noexcept;
            constexpr inline Mat<T, 2>&      operator--() noexcept;
            constexpr inline const Mat<T, 2> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Mat<T, 2> operator+() const noexcept;
            constexpr inline Mat<T, 2> operator-() const noexcept;
            constexpr inline Mat<T, 2> operator+(T val_) const noexcept;
            constexpr inline Mat<T, 2> operator+(const Mat<T, 2>& mat_) const noexcept;
            constexpr inline Mat<T, 2> operator-(T val_) const noexcept;
            constexpr inline Mat<T, 2> operator-(const Mat<T, 2>& mat_) const noexcept;
            constexpr inline Mat<T, 2> operator*(T val_) const noexcept;
            constexpr inline Vec<T, 2> operator*(const Vec<T, 2>& vec_) const noexcept;
            constexpr inline Mat<T, 2> operator*(const Mat<T, 2>& mat_) const noexcept;
            constexpr inline Mat<T, 2> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline Vec<T, 2>&       operator[](size_t index_) noexcept;
            constexpr inline const Vec<T, 2>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Mathematical --
            constexpr inline T         sum() const noexcept;
            constexpr inline T         det() const noexcept;
            constexpr inline Mat<T, 2> minors() const noexcept;
            constexpr inline Mat<T, 2> cofactor() const noexcept;
            constexpr inline Mat<T, 2> trans() const noexcept;
            constexpr inline Mat<T, 2> adj() const noexcept;
            constexpr inline Mat<T, 2> inv() const noexcept;
        };



    } // namespace math



    //  == ALIASES ==
    //  -- Float --
    using mat2f = math::Mat<float, 2>; // NOLINT //!< Two-dimensional float precision mat.

    //  -- Double --
    using mat2 = math::Mat<double, 2>; // NOLINT //!< Two-dimensional double precision mat.



} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/mat2.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_MAT2_HPP
