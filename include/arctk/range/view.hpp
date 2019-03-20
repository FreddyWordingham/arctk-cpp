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
            R& _range;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit View(const R& range_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline size_type size() const noexcept;
        };



    } // namespace range
} // namespace arc
