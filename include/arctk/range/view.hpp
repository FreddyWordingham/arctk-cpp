//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == CLASSES ==
        //  -- View --
        template <typename R>
        class View
        {
            //  == FIELDS ==
          protected:
            //  -- References --
            const R& _range;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline View(const R& range_) noexcept;
        };



    } // namespace range
} // namespace arc
