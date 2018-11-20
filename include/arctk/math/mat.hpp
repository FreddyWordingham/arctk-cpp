/**
 *  @file   arctk/math/mat.hpp
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical square matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT_HPP
#define ARCTK_MATH_MAT_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
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
         *  Mathematical square matrix class.
         *
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
         */
        template <typename T, size_t N>
        class Mat
        {
            //  == ASSERTIONS ==
            //  -- Size --
            static_assert(N > 4);


            //  == FRIENDS ==
            friend Vec<T, N>; //!< Vec friend used to directly access vec elements.


            //  == FIELDS ==
          private:
            //  -- Data --
            std::array<Vec<T, N>, N> _data{}; //!< Array of matrix rows.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Mat() noexcept = default;
            template <typename... A>
            constexpr inline explicit Mat(const A&... data_) noexcept;

            //  -- Initialisation --
          private:
            template <typename... A>
            inline std::array<Vec<T, N>, N> init_data(const A&... data_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Printing --
            template <typename S, size_t M>
            friend constexpr inline std::ostream& operator<<(std::ostream& stream_, const Mat<S, M>& mat_) noexcept;

            //  -- Assignment --
            constexpr inline Mat<T, N>& operator+=(T val_) noexcept;
            constexpr inline Mat<T, N>& operator+=(const Mat<T, N>& mat_) noexcept;
            constexpr inline Mat<T, N>& operator-=(T val_) noexcept;
            constexpr inline Mat<T, N>& operator-=(const Mat<T, N>& mat_) noexcept;
            constexpr inline Mat<T, N>& operator*=(T val_) noexcept;
            constexpr inline Mat<T, N>& operator*=(const Mat<T, N>& mat_) noexcept;
            constexpr inline Mat<T, N>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Mat<T, N>&      operator++() noexcept;
            constexpr inline const Mat<T, N> operator++(int) noexcept;
            constexpr inline Mat<T, N>&      operator--() noexcept;
            constexpr inline const Mat<T, N> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Mat<T, N> operator+() const noexcept;
            constexpr inline Mat<T, N> operator-() const noexcept;
            constexpr inline Mat<T, N> operator+(T val_) const noexcept;
            constexpr inline Mat<T, N> operator+(const Mat<T, N>& mat_) const noexcept;
            constexpr inline Mat<T, N> operator-(T val_) const noexcept;
            constexpr inline Mat<T, N> operator-(const Mat<T, N>& mat_) const noexcept;
            constexpr inline Mat<T, N> operator*(T val_) const noexcept;
            constexpr inline Vec<T, N> operator*(const Vec<T, N>& vec_) const noexcept;
            constexpr inline Mat<T, N> operator*(const Mat<T, N>& mat_) const noexcept;
            constexpr inline Mat<T, N> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline Vec<T, N>&       operator[](size_t index_) noexcept;
            constexpr inline const Vec<T, N>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const std::array<Vec<T, N>, N>& data() const noexcept;

            //  -- Mathematical --
            constexpr inline T         sum() const noexcept;
            constexpr inline T         det() const noexcept;
            constexpr inline T         minors(size_t row_, size_t col_) const noexcept;
            constexpr inline Mat<T, N> minors() const noexcept;
            constexpr inline T         cofactor(size_t row_, size_t col_) const noexcept;
            constexpr inline Mat<T, N> cofactor() const noexcept;
            constexpr inline Mat<T, N> trans() const noexcept;
            constexpr inline Mat<T, N> adj() const noexcept;
            constexpr inline Mat<T, N> inv() const noexcept;
        };



        //  == CLASS SPECIALISATIONS ==
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
            friend constexpr inline std::ostream& operator<<(std::ostream& stream_, const Mat<S, 2>& mat_) noexcept; // NOLINT

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
    using mat2f = math::Mat<float, 2>; //!< Two-dimensional float precision mat.    // NOLINT
    using mat3f = math::Mat<float, 3>; //!< Three-dimensional float precision mat.    // NOLINT
    using mat4f = math::Mat<float, 4>; //!< Four-dimensional float precision mat.    // NOLINT
    template <size_t N>
    using matNf = math::Mat<float, N>; //!< N-dimensional float precision mat.  // NOLINT

    //  -- Double --
    using mat2 = math::Mat<double, 2>; //!< Two-dimensional double precision mat.   // NOLINT
    using mat3 = math::Mat<double, 3>; //!< Three-dimensional double precision mat.   // NOLINT
    using mat4 = math::Mat<double, 4>; //!< Four-dimensional double precision mat.   // NOLINT
    template <size_t N>
    using matN = math::Mat<double, N>; //!< N-dimensional double precision mat. // NOLINT



} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/mat.inl>
#include <arctk/math/mat2.inl>
#include <arctk/math/mat3.inl>
#include <arctk/math/mat4.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_MAT_HPP
