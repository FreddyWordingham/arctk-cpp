/**
 *  @file   arctk/dom/grid/fixed.hpp
 *  @date   30/08/2018
 *  @author Freddy Wordingham
 *
 *  Fixed domain gridding class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_GRID_FIXED_HPP
#define ARCTK_DOM_GRID_FIXED_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <vector>

//  -- Arctk --
#include <arctk/dom/cell/leaf.hpp>
#include <arctk/dom/grid.hpp>
#include <arctk/index.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {
        namespace grid //! gridding namespace
        {



            //  == CLASS ==
            /**
             *  Fixed domain gridding class.
             */
            class Fixed : public Grid
            {
                //  == FIELDS ==
              private:
                //  -- Cells --
                std::vector<std::vector<std::vector<cell::Leaf>>> _leaves;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Fixed(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) noexcept;

              private:
                //  -- Initialisation --
                std::vector<std::vector<std::vector<cell::Leaf>>> init_leaves(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const Cell& cell(const vec3& pos_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Fixed::Fixed(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) noexcept
              : Grid(min_, max_)
              , _leaves(init_leaves(min_, max_, res_))
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);
                PRE(res_[index::dim::cartesian::X] > 0);
                PRE(res_[index::dim::cartesian::Y] > 0);
                PRE(res_[index::dim::cartesian::Z] > 0);
            }


            //  -- Initialisation --
            std::vector<std::vector<std::vector<cell::Leaf>>> Fixed::init_leaves(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) const noexcept
            {
                std::vector<std::vector<std::vector<cell::Leaf>>> leaves;

                return (leaves);
            }



            //  == METHODS ==
            //  -- Getters --



        } // namespace grid
    }     // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_GRID_FIXED_HPP
