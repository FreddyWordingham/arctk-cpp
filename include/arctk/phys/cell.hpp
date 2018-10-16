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
            double _scatters; //!< Total scatterings that occur within in cell.
            double _energy;   //!< Total energy within the cell.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Cell(const vec3& min_, const vec3& max_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double scatter_dens() const noexcept;
            inline double energy_dens() const noexcept;

            //  -- Settings --
            inline void add_scatter(double scatters_) noexcept;
            inline void add_energy(double energy_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a cell with given bounds.
         *
         *  @param  min_    Vertex position of the box.
         *  @param  max_    Vertex position of the box.
         *
         *  @pre    min_.x must be less than, or equal to, max_.x.
         *  @pre    min_.y must be less than, or equal to, max_.y.
         *  @pre    min_.z must be less than, or equal to, max_.z.
         */
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
        /**
         *  Get the scattering density of the cell.
         *
         *  @return Scattering density of the cell.
         */
        inline double Cell::scatter_dens() const noexcept
        {
            return (_scatters / vol());
        }

        inline double Cell::energy_dens() const noexcept
        {
            return (_energy / vol());
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
