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
            //  -- Data --
            I _it;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Iterator(I&& it_) noexcept;
        };



    } // namespace range
} // namespace arc
