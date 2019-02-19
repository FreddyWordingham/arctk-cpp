//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <functional>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == CLASSES ==
        //  -- View --
        template <typename C>
        class View
        {
            //  == ALIASES ==
          private:
            //  -- Types --
            using value_type     = typename C::value_type;
            using const_iterator = typename C::const_iterator;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const_iterator cbegin() const noexcept = 0;
            constexpr inline const_iterator cend() const noexcept   = 0;
        };



    } // namespace range
} // namespace arc
