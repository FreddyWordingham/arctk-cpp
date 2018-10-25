/**
 *  @file   arctk/dom/cell.hpp
 *  @date   08/10/2018
 *  @author Freddy Wordingham
 *
 *  Domain cell information class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_CELL_HPP
#define ARCTK_DOM_CELL_HPP



//  == BASE ==
#include <arctk/geom/shape/box.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        template <typename T, size_t N>
        class Vec;
    }                                  // namespace math
    using vec3 = math::Vec<double, 3>; //!< Three-dimensional double precision vec.
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
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



    } // namespace dom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/dom/cell.inl>



//  == GUARD END ==
#endif // ARCTK_DOM_CELL_HPP
