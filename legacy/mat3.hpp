/**
 *  @file   arctk/math/mat3.hpp
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical three-by-three matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT3_HPP
#define ARCTK_MATH_MAT3_HPP



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
         *  Three-by-three mathematical square matrix class.
         *
         *  @tparam T   Type stored by the mat.
         */
        template <typename T>
        class Mat<T, 3>
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            Vec<T, 3> x{}; //!< X-row of matrix.
            Vec<T, 3> y{}; //!< Y-row of matrix.
            Vec<T, 3> z{}; //!< Z-row of matrix.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Mat() noexcept = default;
            constexpr inline Mat(const Vec<T, 3>& x_, const Vec<T, 3>& y_, const Vec<T, 3>& z_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Printing --
            template <typename S>
            friend constexpr inline std::ostream& operator<<(std::ostream& stream_, const Mat<S, 3>& mat_) noexcept; // NOLINT

            //  -- Assignment --
            constexpr inline Mat<T, 3>& operator+=(T val_) noexcept;
            constexpr inline Mat<T, 3>& operator+=(const Mat<T, 3>& mat_) noexcept;
            constexpr inline Mat<T, 3>& operator-=(T val_) noexcept;
            constexpr inline Mat<T, 3>& operator-=(const Mat<T, 3>& mat_) noexcept;
            constexpr inline Mat<T, 3>& operator*=(T val_) noexcept;
            constexpr inline Mat<T, 3>& operator*=(const Mat<T, 3>& mat_) noexcept;
            constexpr inline Mat<T, 3>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Mat<T, 3>&      operator++() noexcept;
            constexpr inline const Mat<T, 3> operator++(int) noexcept;
            constexpr inline Mat<T, 3>&      operator--() noexcept;
            constexpr inline const Mat<T, 3> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Mat<T, 3> operator+() const noexcept;
            constexpr inline Mat<T, 3> operator-() const noexcept;
            constexpr inline Mat<T, 3> operator+(T val_) const noexcept;
            constexpr inline Mat<T, 3> operator+(const Mat<T, 3>& mat_) const noexcept;
            constexpr inline Mat<T, 3> operator-(T val_) const noexcept;
            constexpr inline Mat<T, 3> operator-(const Mat<T, 3>& mat_) const noexcept;
            constexpr inline Mat<T, 3> operator*(T val_) const noexcept;
            constexpr inline Vec<T, 3> operator*(const Vec<T, 3>& vec_) const noexcept;
            constexpr inline Mat<T, 3> operator*(const Mat<T, 3>& mat_) const noexcept;
            constexpr inline Mat<T, 3> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline Vec<T, 3>&       operator[](size_t index_) noexcept;
            constexpr inline const Vec<T, 3>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Mathematical --
            constexpr inline T         sum() const noexcept;
            constexpr inline T         det() const noexcept;
            constexpr inline Mat<T, 3> minors() const noexcept;
            constexpr inline Mat<T, 3> cofactor() const noexcept;
            constexpr inline Mat<T, 3> trans() const noexcept;
            constexpr inline Mat<T, 3> adj() const noexcept;
            constexpr inline Mat<T, 3> inv() const noexcept;
        };



        //  == ALIASES ==
        //  -- Float --
        using mat3f = math::Mat<float, 3>; //!< Three-dimensional float precision mat.  // NOLINT

        //  -- Double --
        using mat3 = math::Mat<double, 3>; //!< Three-dimensional double precision mat. // NOLINT



    } // namespace math
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/mat3.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_MAT3_HPP
