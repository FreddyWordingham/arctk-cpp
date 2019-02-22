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
          public:
            //  -- Values --
            using value_type = typename C::value_type;


            //  == FIELDS ==
          private:
            //  -- References -
            std::vector<std::reference_wrapper<value_type>> _refs;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --



            //  == OPERATORS ==
          public:
            //  == METHODS ==
          public:
            //  -- Getters --
        };



    } // namespace range
} // namespace arc
