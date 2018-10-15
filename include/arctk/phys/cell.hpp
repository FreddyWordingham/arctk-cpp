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
            double _scatters;
            double _energy;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Cell(const vec3& min_, const vec3& max_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double scatter_dens() const noexcept;

            //  -- Settings --
            inline void add_scatter(double interactions_) noexcept;
            inline void add_energy(double energy_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Cell::Cell(const vec3& min_, const vec3& max_) noexcept
          : Box(min_, max_)
          , _scatters(0.0)
          , _energy(0.0)
        {
            PRE(min_.x <= max_.x);
            PRE(min_.y <= max_.y);
            PRE(min_.z <= max_.z);
        }



        //  == METHODS ==
        //  -- Getters --
        inline double Cell::scatter_dens() const noexcept
        {
            return (_scatters / vol());
        }


        //  -- Settings --
        inline void Cell::add_scatter(const double scatters_) noexcept
        {
            PRE(scatters_ > 0.0);
            PRE(scatters_ <= 1.0);

            _scatters += scatters_;
        }

        inline void Cell::add_energy(const double energy_) noexcept
        {
            PRE(energy_ > 0.0);

            _energy += energy_;
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_CELL_HPP
