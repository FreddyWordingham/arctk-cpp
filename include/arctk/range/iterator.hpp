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
        };



    } // namespace range
} // namespace arc
