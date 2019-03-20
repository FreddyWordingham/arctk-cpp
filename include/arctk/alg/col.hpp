//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include <array>
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == CLASSES ==
        //  -- Col --
        template <typename T, std::size_t N>
        class Col
        {
            //  == FIELDS ==
          private:
            //  -- Elements --
            std::array<T, N> _elems;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Col() noexcept;
            template <typename... A>
            constexpr inline explicit Col(const A... elems_) noexcept;

          private:
            //  -- Instantiation --
            template <typename... A>
            constexpr inline std::array<T, N> init_elems(const A... elems_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            constexpr inline T&       operator[](const std::size_t index_) noexcept;
            constexpr inline const T& operator[](const std::size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const std::array<T, N>& elems() const noexcept;
        };



    } // namespace alg
} // namespace arc
