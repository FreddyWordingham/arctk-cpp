/**
 *  @file   arctk/phys/cell.hpp
 *  @date   08/10/2018
 *  @author Freddy Wordingham
 *
 *  Cell physical information class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_CELL_HPP
#define ARCTK_PHYS_CELL_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Scene information cell.
         */
        class Cell : public geom::shape::Box
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            double _interactions;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Cell(const vec3& min_, const vec3& max_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double interaction_dens() const noexcept;

            //  -- Settings --
            inline void add_interactions(double interactions_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Cell::Cell(const vec3& min_, const vec3& max_) noexcept
          : Box(min_, max_)
          , _interactions(0.0)
        {
            PRE(min_.x <= max_.x);
            PRE(min_.y <= max_.y);
            PRE(min_.z <= max_.z);
        }



        //  == METHODS ==
        //  -- Getters --
        inline double Cell::interaction_dens() const noexcept
        {
            return (_interactions / vol());
        }


        //  -- Settings --
        inline void Cell::add_interactions(const double interactions_) noexcept
        {
            PRE(interactions_ > 0.0);
            PRE(interactions_ <= 1.0);

            _interactions += interactions_;
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_CELL_HPP
