//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/preview.hpp" // IWYU pragma: export



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace preview
        {



            //  == CLASSES ==
            //  -- Transform --
            template <typename F>
            struct Transform : public Preview
            {
                //  == FIELDS ==
              public:
                //  -- Functor --
                const F trans;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Transform(const F& trans_) noexcept;
            };



        } // namespace preview
    }     // namespace range
} // namespace arc
