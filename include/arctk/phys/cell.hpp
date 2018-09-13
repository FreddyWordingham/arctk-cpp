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
//  -- Std --
#include <array>
#include <string>
#include <tuple>

//  -- Arctk --
#include <arctk/data.hpp>
#include <arctk/debug.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Data packet base class.
         */
        class Cell : public data::Packet
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            double _vol;    //!< Volume of the cell.
            double _energy; //!< Energy contained by the cell.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Cell(double vol_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline std::tuple<double, double> data() const noexcept;
            inline std::array<std::string, 2> data_names() const noexcept;
            inline double                     vol() const noexcept;
            inline double                     energy_dens() const noexcept;

            //  -- Modifiers --
            inline void add_energy(double energy_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Cell::Cell(const double vol_) noexcept
          : _vol(vol_)
          , _energy(0.0)
        {
            PRE(vol_ > 0.0);
        }



        //  == METHODS ==
        //  -- Getters --
        inline std::tuple<double, double> Cell::data() const noexcept
        {
            return (std::tuple<double, double>(_vol, energy_dens()));
        }

        inline std::array<std::string, 2> Cell::data_names() const noexcept
        {
            return (std::array<std::string, 2>({"vol", "udens"}));
        }

        inline double Cell::vol() const noexcept
        {
            return (_vol);
        }

        inline double Cell::energy_dens() const noexcept
        {
            return (_energy / _vol);
        }


        //  -- Modifiers --
        inline void Cell::add_energy(const double energy_) noexcept
        {
            _energy += energy_;
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_CELL_HPP
