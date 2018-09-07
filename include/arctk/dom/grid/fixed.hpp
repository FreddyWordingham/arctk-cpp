/**
 *  @file   arctk/dom/grid/fixed.hpp
 *  @date   07/09/2018
 *  @author Freddy Wordingham
 *
 *  Fixed domain gridding base class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_GRID_FIXED_HPP
#define ARCTK_DOM_GRID_FIXED_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/dom/cell/leaf.hpp>
#include <arctk/dom/grid.hpp>
#include <arctk/index.hpp>



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
                std::vector<std::vector<std::vector<cell::Leaf>>> _cells;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Fixed(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline size_t num_cells() const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Fixed::Fixed(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) noexcept
              : Grid(min_, max_)
              , _cells(res_[index::dim::cartesian::X], std::vector<std::vector<cell::Leaf>>(res_[index::dim::cartesian::Y], std::vector<cell::Leaf>(res_[index::dim::cartesian::Z])))
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);
                PRE(res_[index::dim::cartesian::X] > 0);
                PRE(res_[index::dim::cartesian::Y] > 0);
                PRE(res_[index::dim::cartesian::Z] > 0);
            }



            //  == METHODS ==
            //  -- Getters --
            inline size_t Fixed::num_cells() const noexcept
            {
                return (_cells.size() * _cells.first().size() * _cells.first().first().size());
            }



        } // namespace grid
    }     // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_GRID_FIXED_HPP
