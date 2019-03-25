//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview/progress.hpp"



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == CLASSES ==
            //  -- Progress --
            template <typename R, typename T>
            class Progress : public View<R>
            {
                //  == FIELDS ==
              private:
                //  -- Iterations --
                std::size_t       _current;
                const std::size_t _expected;

                //  -- Stream --
                T& _stream;

                //  -- Formatting --
                const int _length;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Progress(R& range_, T& stream_, const int length_, const std::size_t expected_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                constexpr inline auto begin() noexcept;
                constexpr inline auto begin() const noexcept;
                constexpr inline auto end() noexcept;
                constexpr inline auto end() const noexcept;
            };



        } // namespace view
    }     // namespace range



    //  == OPERATORS ==
    //  -- Pipe --
    template <typename R, typename T>
    constexpr inline range::view::Progress<R, T> operator|(R& range_, const range::preview::Progress<T>& prog_) noexcept;
    template <typename R, typename T>
    constexpr inline range::view::Progress<R, T> operator|(R&& range_, const range::preview::Progress<T>& prog_) noexcept;



} // namespace arc
