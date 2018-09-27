/**
 *  @file   arctk/phys/cell.hpp
 *  @date   12/09/2018
 *  @author Freddy Wordingham
 *
 *  Physics cell data packet base class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_CELL_HPP
#define ARCTK_PHYS_CELL_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Data packet base class.
         */
        class Cell : public geom::shape::Aabb
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            double _energy; //!< Energy contained by the cell.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Cell(double vol_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double energy_dens() const noexcept;

            //  -- Modifiers --
            inline void add_energy(double energy_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a data cell packet with a given volume.
         *
         *  @param  vol_    Volume of the cell.
         *
         *  @pre    vol_ must be positive.
         */
        inline Cell::Cell(const double vol_) noexcept
          : _vol(vol_)
          , _energy(0.0)
        {
            PRE(vol_ > 0.0);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the energy density of the cell.
         *
         *  @return Energy density of the cell.
         */
        inline double Cell::energy_dens() const noexcept
        {
            return (_energy / _vol);
        }


        //  -- Modifiers --
        /**
         *  Added energy to the cell.
         *
         *  @param  energy_ Amount of energy to add to the cell.
         *
         *  @pre    energy_ must be positive.
         */
        inline void Cell::add_energy(const double energy_) noexcept
        {
            PRE(energy_ > 0.0);

            _energy += energy_;
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_CELL_HPP
