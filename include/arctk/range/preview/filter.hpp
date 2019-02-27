//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/preview.hpp"



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/filter.hpp"



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace preview
        {



            //  == CLASSES ==
            //  -- Filter --
            template <typename F>
            struct Filter : public Preview
            {
                //  == FIELDS ==
              public:
                //  -- Functor --
                const F pred;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Filter(const F& pred_) noexcept;
            };



        } // namespace preview
    }     // namespace range
} // namespace arc
