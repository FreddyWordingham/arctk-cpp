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
            R* _range;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline View() noexcept;
            constexpr inline View(R* const range_) noexcept;


            //  == METHODS ==
          public:
            //  -- Setters --
            constexpr inline void set_range(R* const range_) noexcept;
        };



    } // namespace range
} // namespace arc
