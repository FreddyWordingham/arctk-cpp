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
#include <cmath>
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



        //  == CLASS SPECIALISATIONS ==
        /**
         *  Two-dimensional mathematical vector class.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        class Vec<T, 2>
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            /**
             *  First vec element.
             */
            union
            {
                T x,   //!< Cartesian x-dimension.
                  rho; //!< Polar radial-dimension.
            };

            /**
             *  Second vec element.
             */
            union
            {
                T y,     //!< Cartesian y-dimension.
                  theta; //!< Polar inclination-dimension.
            };


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Vec() noexcept;
            constexpr inline Vec(T x_, T y_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Printing --
            template <typename S>
            friend constexpr inline std::ostream& operator<<(std::ostream& stream_, const Vec<S, 2>& vec_) noexcept; // NOLINT

            //  -- Assignment --
            constexpr inline Vec<T, 2>& operator+=(T val_) noexcept;
            constexpr inline Vec<T, 2>& operator+=(const Vec<T, 2>& vec_) noexcept;
            constexpr inline Vec<T, 2>& operator-=(T val_) noexcept;
            constexpr inline Vec<T, 2>& operator-=(const Vec<T, 2>& vec_) noexcept;
            constexpr inline Vec<T, 2>& operator*=(T val_) noexcept;
            constexpr inline Vec<T, 2>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Vec<T, 2>&      operator++() noexcept;
            constexpr inline const Vec<T, 2> operator++(int) noexcept;
            constexpr inline Vec<T, 2>&      operator--() noexcept;
            constexpr inline const Vec<T, 2> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Vec<T, 2> operator+() const noexcept;
            constexpr inline Vec<T, 2> operator-() const noexcept;
            constexpr inline Vec<T, 2> operator+(T val_) const noexcept;
            constexpr inline Vec<T, 2> operator+(const Vec<T, 2>& vec_) const noexcept;
            constexpr inline Vec<T, 2> operator-(T val_) const noexcept;
            constexpr inline Vec<T, 2> operator-(const Vec<T, 2>& vec_) const noexcept;
            constexpr inline Vec<T, 2> operator*(T val_) const noexcept;
            constexpr inline T         operator*(const Vec<T, 2>& vec_) const noexcept;
            constexpr inline Vec<T, 2> operator*(const Mat<T, 2>& mat_) const noexcept;
            constexpr inline Vec<T, 2> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline T&       operator[](size_t index_) noexcept;
            constexpr inline const T& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Properties --
            constexpr inline bool normalised(T tol_ = std::numeric_limits<T>::epsilon()) const noexcept;

            //  -- Mathematical --
            constexpr inline T         sum() const noexcept;
            constexpr inline T         mag() const noexcept;
            constexpr inline T         mag_sq() const noexcept;
            constexpr inline Vec<T, 2> normal() const noexcept;
            constexpr inline void      normalise() noexcept;
        };


        /**
         *  Three-dimensional mathematical vector class.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        class Vec<T, 3>
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            /**
             *  First vec element.
             */
            union
            {
                T x,   //!< Cartesian x-dimension.
                  rho, //!< Polar radial-dimension.
                  r;   //!< Colour red-dimension.
            };

            /**
             *  Second vec element.
             */
            union
            {
                T y,     //!< Cartesian y-dimension.
                  theta, //!< Polar inclination-dimension.
                  g;     //!< Colour green-dimension.
            };

            /**
             *  Third vec element.
             */
            union
            {
                T z,   //!< Cartesian z-dimension.
                  phi, //!< Polar azimuthal-dimension.
                  b;   //!< Colour blue-dimension.
            };


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Vec() noexcept;
            constexpr inline Vec(T x_, T y_, T z_) noexcept;
            constexpr inline Vec(const Vec<T, 2>& vec_, T z_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Printing --
            template <typename S>
            friend constexpr inline std::ostream& operator<<(std::ostream& stream_, const Vec<S, 3>& vec_) noexcept; // NOLINT

            //  -- Assignment --
            constexpr inline Vec<T, 3>& operator+=(T val_) noexcept;
            constexpr inline Vec<T, 3>& operator+=(const Vec<T, 3>& vec_) noexcept;
            constexpr inline Vec<T, 3>& operator-=(T val_) noexcept;
            constexpr inline Vec<T, 3>& operator-=(const Vec<T, 3>& vec_) noexcept;
            constexpr inline Vec<T, 3>& operator*=(T val_) noexcept;
            constexpr inline Vec<T, 3>& operator/=(T val_) noexcept;
            constexpr inline Vec<T, 3>& operator^=(const Vec<T, 3>& vec_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Vec<T, 3>&      operator++() noexcept;
            constexpr inline const Vec<T, 3> operator++(int) noexcept;
            constexpr inline Vec<T, 3>&      operator--() noexcept;
            constexpr inline const Vec<T, 3> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Vec<T, 3> operator+() const noexcept;
            constexpr inline Vec<T, 3> operator-() const noexcept;
            constexpr inline Vec<T, 3> operator+(T val_) const noexcept;
            constexpr inline Vec<T, 3> operator+(const Vec<T, 3>& vec_) const noexcept;
            constexpr inline Vec<T, 3> operator-(T val_) const noexcept;
            constexpr inline Vec<T, 3> operator-(const Vec<T, 3>& vec_) const noexcept;
            constexpr inline Vec<T, 3> operator*(T val_) const noexcept;
            constexpr inline T         operator*(const Vec<T, 3>& vec_) const noexcept;
            constexpr inline Vec<T, 3> operator*(const Mat<T, 3>& mat_) const noexcept;
            constexpr inline Vec<T, 3> operator/(T val_) const noexcept;
            constexpr inline Vec<T, 3> operator^(const Vec<T, 3>& vec_) const noexcept;

            //  -- Access --
            constexpr inline T&       operator[](size_t index_) noexcept;
            constexpr inline const T& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Properties --
            constexpr inline bool normalised(T tol_ = std::sqrt(std::numeric_limits<T>::epsilon())) const noexcept;

            //  -- Mathematical --
            constexpr inline T         sum() const noexcept;
            constexpr inline T         mag() const noexcept;
            constexpr inline T         mag_sq() const noexcept;
            constexpr inline Vec<T, 3> normal() const noexcept;
            constexpr inline void      normalise() noexcept;
            constexpr inline void      rotate(const math::Vec<T, 3>& axis_, T ang_) noexcept;
        };


        /**
         *  Four-dimensional mathematical vector class.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        class Vec<T, 4>
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            /**
             *  First vec element.
             */
            union
            {
                T x, //!< Cartesian x-dimension.
                  r; //!< Colour red-dimension.
            };

            /**
             *  Second vec element.
             */
            union
            {
                T y, //!< Cartesian y-dimension.
                  g; //!< Colour green-dimension.
            };

            /**
             *  Third vec element.
             */
            union
            {
                T z, //!< Cartesian z-dimension.
                  b; //!< Colour blue-dimension.
            };

            /**
             *  Fourth vec element.
             */
            union
            {
                T w, //!< Cartesian w-dimension.
                  a; //!< Colour alpha-dimension.
            };


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Vec() noexcept;
            constexpr inline Vec(T x_, T y_, T z_, T w_) noexcept;
            constexpr inline Vec(const Vec<T, 2>& vec_, T z_, T w_) noexcept;
            constexpr inline Vec(const Vec<T, 3>& vec_, T w_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Printing --
            template <typename S>
            friend constexpr inline std::ostream& operator<<(std::ostream& stream_, const Vec<S, 4>& vec_) noexcept; // NOLINT

            //  -- Assignment --
            constexpr inline Vec<T, 4>& operator+=(T val_) noexcept;
            constexpr inline Vec<T, 4>& operator+=(const Vec<T, 4>& vec_) noexcept;
            constexpr inline Vec<T, 4>& operator-=(T val_) noexcept;
            constexpr inline Vec<T, 4>& operator-=(const Vec<T, 4>& vec_) noexcept;
            constexpr inline Vec<T, 4>& operator*=(T val_) noexcept;
            constexpr inline Vec<T, 4>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Vec<T, 4>&      operator++() noexcept;
            constexpr inline const Vec<T, 4> operator++(int) noexcept;
            constexpr inline Vec<T, 4>&      operator--() noexcept;
            constexpr inline const Vec<T, 4> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Vec<T, 4> operator+() const noexcept;
            constexpr inline Vec<T, 4> operator-() const noexcept;
            constexpr inline Vec<T, 4> operator+(T val_) const noexcept;
            constexpr inline Vec<T, 4> operator+(const Vec<T, 4>& vec_) const noexcept;
            constexpr inline Vec<T, 4> operator-(T val_) const noexcept;
            constexpr inline Vec<T, 4> operator-(const Vec<T, 4>& vec_) const noexcept;
            constexpr inline Vec<T, 4> operator*(T val_) const noexcept;
            constexpr inline T         operator*(const Vec<T, 4>& vec_) const noexcept;
            constexpr inline Vec<T, 4> operator*(const Mat<T, 4>& mat_) const noexcept;
            constexpr inline Vec<T, 4> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline T&       operator[](size_t index_) noexcept;
            constexpr inline const T& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Properties --
            constexpr inline bool normalised(T tol_ = std::numeric_limits<T>::epsilon()) const noexcept;

            //  -- Mathematical --
            constexpr inline T         sum() const noexcept;
            constexpr inline T         mag() const noexcept;
            constexpr inline T         mag_sq() const noexcept;
            constexpr inline Vec<T, 4> normal() const noexcept;
            constexpr inline void      normalise() noexcept;
        };



    } // namespace math



    //  == ALIASES ==
    //  -- Float --
    using vec2f = math::Vec<float, 2>; //!< Two-dimensional float precision vec.    // NOLINT
    using vec3f = math::Vec<float, 3>; //!< Three-dimensional float precision vec.    // NOLINT
    using vec4f = math::Vec<float, 4>; //!< Four-dimensional float precision vec.    // NOLINT
    template <size_t N>
    using vecNf = math::Vec<float, N>; //!< N-dimensional float precision vec.  // NOLINT

    //  -- Double --
    using vec2 = math::Vec<double, 2>; //!< Two-dimensional double precision vec.   // NOLINT
    using vec3 = math::Vec<double, 3>; //!< Three-dimensional double precision vec.   // NOLINT
    using vec4 = math::Vec<double, 4>; //!< Four-dimensional double precision vec.   // NOLINT
    template <size_t N>
    using vecN = math::Vec<double, N>; //!< N-dimensional double precision vec. // NOLINT



} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/vec2.inl>
#include <arctk/math/vec3.inl>
#include <arctk/math/vec4.inl>
#include <arctk/math/vecN.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_VEC_HPP
