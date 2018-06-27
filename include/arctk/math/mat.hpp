/**
 *  @file   arctk/math/mat.hpp
 *  @date   27/06/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical square matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT_HPP
#define ARCTK_MATH_MAT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <array>

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


            //  == FIELDS ==
          private:
            //  -- Data --
            std::array<Vec<T, N>, N> _data{};


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Mat() noexcept = default;
            template <typename... A>
            constexpr inline explicit Mat(const A&... data_) noexcept;

            //  -- Initialisation --
            template <typename... A>
            inline std::array<Vec<T, N>, N> init_data(const A&... data_) noexcept;



            //  == OPERATORS ==
          public:
            //  -- Stream --
            template <typename S, typename _T, size_t _N> // NOLINT
            friend inline S& operator<<(S& stream_, const Mat<_T, _N>& mat_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const std::array<Vec<T, N>, N>& data() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, size_t N>
        template <typename... A>
        constexpr inline Mat<T, N>::Mat(const A&... data_) noexcept
          : _data(init_data(data_...))
        {
            static_assert(sizeof...(A) == N);
        }


        //  -- Initialisation --
        template <typename T, size_t N>
        template <typename... A>
        inline std::array<Vec<T, N>, N> Mat<T, N>::init_data(const A&... data_) noexcept
        {
            static_assert(sizeof...(A) == N);

            std::array<Vec<T, N>, N> data;

            size_t i = 0;
            ((data[i] = data_, ++i), ...);

            return (data);
        }



        //  == OPERATORS ==
        //  -- Stream --
        template <typename S, typename T, size_t N>
        inline S& operator<<(S& stream_, const Mat<T, N>& mat_) noexcept
        {
            stream_ << str::to_string(mat_._data);

            return (stream_);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T, size_t N>
        constexpr inline const std::array<Vec<T, N>, N>& Mat<T, N>::data() const noexcept
        {
            return (_data);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_MAT_HPP
