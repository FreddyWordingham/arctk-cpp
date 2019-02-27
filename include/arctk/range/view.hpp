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
            //  == ALIASES ==
          public:
            //  -- Traits --
            using value_type = typename R::size_type;
            using size_type  = typename R::size_type;


            //  == FIELDS ==
          protected:
            //  -- Pointers --
            const R& _range;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline View(const R& range_) noexcept;
        };



    } // namespace range
} // namespace arc
