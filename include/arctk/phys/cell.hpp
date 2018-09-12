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
#include <tuple>

//  -- Arctk --
#include <arctk/data.hpp>



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
            double _vol;
            double _energy;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Cell() noexcept;
            inline Cell(const Cell&) noexcept = default; //!< Defaulted copy constructor.
            inline Cell(Cell&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Cell() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Cell& operator=(const Cell&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Cell& operator=(Cell&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline std::tuple<double, double> data() const noexcept;
            inline double                     vol() const noexcept;
            inline double                     energy_dens() const noexcept;

            //  -- Modifiers --
            inline void add_energy(double energy_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Cell::Cell() noexcept
          : _energy(0.0)
        {
        }


        //  -- Destructors --
        inline Cell::~Cell() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        inline std::tuple<double, double> Cell::data() const noexcept
        {
            return (std::tuple<double, double>(_vol, energy_dens()));
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
        inline void Cell::add_energy(const double energy_) const noexcept
        {
            _energy += energy_;
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_CELL_HPP
