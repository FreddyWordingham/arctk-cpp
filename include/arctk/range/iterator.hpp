//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == CLASSES ==
        //  -- Constiterator --
        template <typename T>
        class Iterator
        {
            //  == ALIASES ==
          public:
            //  -- Types --
            using value_type = T;


            //  == FIELDS ==
          private:
            //  -- Data --
            T* _pointer;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Iterator(const T* _pointer) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Increment / Decrement --
            constexpr inline Iterator operator++() noexcept;
            constexpr inline Iterator operator++(const int /*unused*/) noexcept;

            //  -- Comparison --
            constexpr inline bool operator==(const Iterator<T>& rhs_) noexcept;
            constexpr inline bool operator!=(const Iterator<T>& rhs_) noexcept;

            //  -- Member Access --
            constexpr inline T& operator*() noexcept;
            constexpr inline T* operator->() noexcept;
        };



    } // namespace range
} // namespace arc
