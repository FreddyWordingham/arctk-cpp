//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/preview.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace preview
        {



            //  == CLASSES ==
            //  -- Filter --
            class Skip : public Preview
            {
                //  == FIELDS ==
              public:
                //  -- Skips --
                const std::size_t skip_first;
                const std::size_t skip_last;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline explicit Skip(std::size_t skip_first_, std::size_t skip_last_ = 0) noexcept;
            };



        } // namespace preview
    }     // namespace range
} // namespace arc
