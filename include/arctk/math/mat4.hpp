/**
 *  @file   arctk/math/mat4.hpp
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical four-by-four matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT4_HPP
#define ARCTK_MATH_MAT4_HPP



//  == BASE ==
#include <arctk/math/mat.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cstddef>

//  -- Arctk --
#include <arctk/math/vec.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Four-by-four mathematical square matrix class.
         *
         *  @tparam T   Type stored by the mat.
         */
        template <typename T>
        class Mat<T, 4>
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            Vec<T, 4> x{}; //!< X-row of matrix.
            Vec<T, 4> y{}; //!< Y-row of matrix.
            Vec<T, 4> z{}; //!< Z-row of matrix.
            Vec<T, 4> w{}; //!< W-row of matrix.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Mat() noexcept = default;
            constexpr inline Mat(const Vec<T, 4>& x_, const Vec<T, 4>& y_, const Vec<T, 4>& z_, const Vec<T, 4>& w_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Printing --
            template <typename S>
            friend constexpr inline std::ostream& operator<<(std::ostream& stream_, const Mat<S, 4>& mat_) noexcept; // NOLINT

            //  -- Assignment --
            constexpr inline Mat<T, 4>& operator+=(T val_) noexcept;
            constexpr inline Mat<T, 4>& operator+=(const Mat<T, 4>& mat_) noexcept;
            constexpr inline Mat<T, 4>& operator-=(T val_) noexcept;
            constexpr inline Mat<T, 4>& operator-=(const Mat<T, 4>& mat_) noexcept;
            constexpr inline Mat<T, 4>& operator*=(T val_) noexcept;
            constexpr inline Mat<T, 4>& operator*=(const Mat<T, 4>& mat_) noexcept;
            constexpr inline Mat<T, 4>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Mat<T, 4>&      operator++() noexcept;
            constexpr inline const Mat<T, 4> operator++(int) noexcept;
            constexpr inline Mat<T, 4>&      operator--() noexcept;
            constexpr inline const Mat<T, 4> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Mat<T, 4> operator+() const noexcept;
            constexpr inline Mat<T, 4> operator-() const noexcept;
            constexpr inline Mat<T, 4> operator+(T val_) const noexcept;
            constexpr inline Mat<T, 4> operator+(const Mat<T, 4>& mat_) const noexcept;
            constexpr inline Mat<T, 4> operator-(T val_) const noexcept;
            constexpr inline Mat<T, 4> operator-(const Mat<T, 4>& mat_) const noexcept;
            constexpr inline Mat<T, 4> operator*(T val_) const noexcept;
            constexpr inline Vec<T, 4> operator*(const Vec<T, 4>& vec_) const noexcept;
            constexpr inline Mat<T, 4> operator*(const Mat<T, 4>& mat_) const noexcept;
            constexpr inline Mat<T, 4> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline Vec<T, 4>&       operator[](size_t index_) noexcept;
            constexpr inline const Vec<T, 4>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Mathematical --
            constexpr inline T         sum() const noexcept;
            constexpr inline T         det() const noexcept;
            constexpr inline Mat<T, 4> minors() const noexcept;
            constexpr inline Mat<T, 4> cofactor() const noexcept;
            constexpr inline Mat<T, 4> trans() const noexcept;
            constexpr inline Mat<T, 4> adj() const noexcept;
            constexpr inline Mat<T, 4> inv() const noexcept;
        };



    } // namespace math



    //  == ALIASES ==
    //  -- Float --
    using mat4f = math::Mat<float, 4>; //!< Four-dimensional float precision mat.   // NOLINT

    //  -- Double --
    using mat4 = math::Mat<double, 4>; //!< Four-dimensional double precision mat.  // NOLINT


} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/mat4.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_MAT4_HPP
