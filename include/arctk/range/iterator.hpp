//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == CLASSES ==
        //  -- Iterator --
        template <typename T>
        class Iterator
        {
            //  == FIELDS ==
          protected:
            //  -- Data --
            const T* _pointer;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Iterator(const T* _pointer) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Comparison --
            constexpr inline bool operator==(const Iterator<T>& rhs_) const noexcept;
            constexpr inline bool operator!=(const Iterator<T>& rhs_) const noexcept;

            //  -- Member Access --
            constexpr inline const T& operator*() noexcept;
            constexpr inline const T* operator->() noexcept;
        };



    } // namespace range
} // namespace arc
