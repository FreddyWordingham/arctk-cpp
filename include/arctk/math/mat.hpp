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



    } // namespace math



    //  == ALIASES ==
    //  -- Float --
    template <size_t N>
    using matNf = math::Mat<float, N>; // NOLINT    //!< N-dimensional float precision mat.

    //  -- Double --
    template <size_t N>
    using matN = math::Mat<double, N>; // NOLINT    //!< N-dimensional double precision mat.



} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/vec.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_MAT_HPP
