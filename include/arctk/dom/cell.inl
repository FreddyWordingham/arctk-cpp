/**
 *  @file   arctk/dom/cell.inl
 *  @date   08/10/2018
 *  @author Freddy Wordingham
 *
 *  Domain cell information class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_CELL_INL
#define ARCTK_DOM_CELL_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <iostream>

//  -- Arctk --
#include <arctk/math/vec3.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



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
          , _absorbs(0.0)
          , _energy(0.0)
          , _write_mutex(std::make_unique<std::mutex>())
        {
            assert(min_.x <= max_.x);
            assert(min_.y <= max_.y);
            assert(min_.z <= max_.z);
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

        /**
         *  Get the absorption density of the cell.
         *
         *  @return Absorption density of the cell.
         */
        inline double Cell::absorb_dens() const noexcept
        {
            return (_absorbs / vol());
        }

        /**
         *  Get the energy density of the cell.
         *
         *  @return Energy density of the cell.
         */
        inline double Cell::energy_dens() const noexcept
        {
            return (_energy / vol());
        }


        //  -- Settings --
        /**
         *  Add a scattering count to the cell.
         *
         *  @param  scatters_   Scattering count to add.
         *
         *  @pre    scatters_ must be positive.
         */
        inline void Cell::add_scatter(const double scatters_) noexcept
        {
            assert(scatters_ > 0.0);

            _write_mutex->lock();

            _scatters += scatters_;

            _write_mutex->unlock();
        }

        /**
         *  Add an absorption count to the cell.
         *
         *  @param  absorbs_    Absorption count to add.
         *
         *  @pre    absorbs_ must be positive.
         */
        inline void Cell::add_absorb(const double absorbs_) noexcept
        {
            assert(absorbs_ > 0.0);

            _write_mutex->lock();

            _absorbs += absorbs_;

            _write_mutex->unlock();
        }

        /**
         *  Add a energy count to the cell.
         *
         *  @param  energy_ Energy to add.
         *
         *  @pre    energy_ must be positive.
         */
        inline void Cell::add_energy(const double energy_) noexcept
        {
            assert(energy_ > 0.0);

            _write_mutex->lock();

            _energy += energy_;

            _write_mutex->unlock();
        }



    } // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_CELL_INL
