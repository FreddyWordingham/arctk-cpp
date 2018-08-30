/**
 *  @file   arctk/dom/cell/leaf.hpp
 *  @date   30/08/2018
 *  @author Freddy Wordingham
 *
 *  Domain leaf cell class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_CELL_LEAF_HPP
#define ARCTK_DOM_CELL_LEAF_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/geom.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {
        namespace cell //! cell namespace
        {



            //  == CLASS ==
            /**
             *  Leaf cell class.
             */
            class Leaf : public Cell
            {
                //  == FIELDS ==
              private:
                //  -- Data --
                double _energy; //!< Energy of the cell (J).


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Leaf(const vec3& min_, const vec3& max_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double energy() const noexcept;
                inline double energy_density() const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Leaf::Leaf(const vec3& min_, const vec3& max_) noexcept
              : Cell(min_, max_)
              , _energy(0.0)
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);
            }



            //  == METHODS ==
            //  -- Getters --
            inline double Leaf::energy() const noexcept
            {
                return (_energy);
            }

            inline double Leaf::energy_density() const noexcept
            {
                return (_energy / vol());
            }



        } // namespace cell
    }     // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_CELL_LEAF_HPP
