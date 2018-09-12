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
            double _energy;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Cell()                     = default;
            inline Cell(const Cell&) noexcept = default; //!< Defaulted copy constructor.
            inline Cell(Cell&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Cell() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Cell& operator=(const Cell&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Cell& operator=(Cell&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.
        };



        //  == INSTANTIATION ==
        //  -- Destructors --
        inline Cell::~Cell() noexcept = default;



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_CELL_HPP
