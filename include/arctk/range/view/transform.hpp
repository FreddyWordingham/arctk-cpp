//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp"



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/transform.hpp"

//  -- Std --
#include <vector>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == CLASSES ==
            //  -- Transform --
            template <typename C, typename F>
            class Transform : public View<C>
            {
                //  == ALIASES ==
              private:
                //  -- Iterator --
                using const_iterator = iterator::Transform<typename std::vector<reference>::const_iterator, F>;
                using iterator       = iterator::Transform<typename std::vector<reference>::iterator, F>;

              private:
                //  -- Transform --
                using trans_type = typename std::invoke_result_t<F, typename C::value_type>;


                //  == FIELDS ==
              private:
                //  -- Condition --
                F _trans;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Transform(const C& cont_, F trans_) noexcept;


                //  == OPERATORS ==
              public:
                //  --  Member Access --
                constexpr inline trans_type operator[](const std::size_t index_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                constexpr inline const_iterator cbegin() const noexcept;
                constexpr inline iterator       begin() noexcept;
                constexpr inline const_iterator cend() const noexcept;
                constexpr inline iterator       end() noexcept;
            };



        } // namespace view
    }     // namespace range
} // namespace arc
