//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == CLASSES ==
        //  -- Iterator --
        template <typename I>
        class Iterator
        {
            //  == FIELDS ==
          protected:
            //  -- Iterators --
            I       _it;
            const I _end;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Iterator(const I& start_, const I& end_) noexcept;

            //  -- Destructors --
            virtual inline ~Iterator() noexcept = default;


            //  == OPERATORS ==
          public:
            //  -- Comparison --
            constexpr inline bool operator==(const Iterator& rhs_) const noexcept;
            constexpr inline bool operator!=(const Iterator& rhs_) const noexcept;
        };



    } // namespace range
} // namespace arc
