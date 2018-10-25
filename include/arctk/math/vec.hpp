/**
 *  @file   arctk/math/vec.hpp
 *  @date   10/07/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical vector class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_VEC_HPP
#define ARCTK_MATH_VEC_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>
#include <limits>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        template <typename T, size_t N>
        class Mat;
    } // namespace math
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Mathematical vector class.
         *
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
         */
        template <typename T, size_t N>
        class Vec
        {
            //  == ASSERTIONS ==
            //  -- Size --
            static_assert(N > 4);


            //  == FIELDS ==
          private:
            //  -- Data --
            std::array<T, N> _data{}; //!< Array of element data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Vec() noexcept = default;
            template <typename... A>
            constexpr inline explicit Vec(const A... data_) noexcept;
            template <size_t M, typename... A>
            constexpr inline explicit Vec(const Vec<T, M>& vec_, const A... data_) noexcept;

            //  -- Initialisation --
          private:
            template <typename... A>
            inline std::array<T, N> init_data(const A... data_) noexcept;
            template <size_t M, typename... A>
            inline std::array<T, N> init_data(const Vec<T, M>& vec_, const A... data_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Printing --
            template <typename S, size_t M>
            friend constexpr inline std::ostream& operator<<(std::ostream& stream_, const Vec<S, M>& vec_) noexcept;

            //  -- Assignment --
            constexpr inline Vec<T, N>& operator+=(T val_) noexcept;
            constexpr inline Vec<T, N>& operator+=(const Vec<T, N>& vec_) noexcept;
            constexpr inline Vec<T, N>& operator-=(T val_) noexcept;
            constexpr inline Vec<T, N>& operator-=(const Vec<T, N>& vec_) noexcept;
            constexpr inline Vec<T, N>& operator*=(T val_) noexcept;
            constexpr inline Vec<T, N>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Vec<T, N>&      operator++() noexcept;
            constexpr inline const Vec<T, N> operator++(int) noexcept;
            constexpr inline Vec<T, N>&      operator--() noexcept;
            constexpr inline const Vec<T, N> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Vec<T, N> operator+() const noexcept;
            constexpr inline Vec<T, N> operator-() const noexcept;
            constexpr inline Vec<T, N> operator+(T val_) const noexcept;
            constexpr inline Vec<T, N> operator+(const Vec<T, N>& vec_) const noexcept;
            constexpr inline Vec<T, N> operator-(T val_) const noexcept;
            constexpr inline Vec<T, N> operator-(const Vec<T, N>& vec_) const noexcept;
            constexpr inline Vec<T, N> operator*(T val_) const noexcept;
            constexpr inline T         operator*(const Vec<T, N>& vec_) const noexcept;
            constexpr inline Vec<T, N> operator*(const Mat<T, N>& mat_) const noexcept;
            constexpr inline Vec<T, N> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline T&       operator[](size_t index_) noexcept;
            constexpr inline const T& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const std::array<T, N>& data() const noexcept;

            //  -- Properties --
            constexpr inline bool normalised(T tol_ = std::numeric_limits<T>::epsilon()) const noexcept;

            //  -- Mathematical --
            constexpr inline T         sum() const noexcept;
            constexpr inline T         mag() const noexcept;
            constexpr inline T         mag_sq() const noexcept;
            constexpr inline Vec<T, N> normal() const noexcept;
            constexpr inline void      normalise() noexcept;
        };



    } // namespace math



    //  == ALIASES ==
    //  -- Float --
    template <size_t N>
    using vecNf = math::Vec<float, N>; //!< N-dimensional float precision vec.

    //  -- Double --
    template <size_t N>
    using vecN = math::Vec<double, N>; //!< N-dimensional double precision vec.



} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/vec.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_VEC_HPP
