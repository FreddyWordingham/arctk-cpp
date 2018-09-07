/**
 *  @file   arctk/dom/cell/leaf.hpp
 *  @date   07/09/2018
 *  @author Freddy Wordingham
 *
 *  Domain leaf cell class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_CELL_LEAF_HPP
#define ARCTK_DOM_CELL_LEAF_HPP



//  == IMPORTS ==



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {
        namespace cell //! cell namespace
        {



            //  == CLASS ==
            /**
             *  Domain leaf cell class.
             */
            class Leaf : public Cell
            {
                //  == FIELDS ==
              private:
                //  -- Data --


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Leaf(const vec3& min_, const vec3& max_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Leaf::Leaf(const vec3& min_, const vec3& max_) noexcept
              : Cell(min_, max_)
            {
            }



            //  == METHODS ==
            //  -- Getters --



        } // namespace cell
    }     // namespace dom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DOM_CELL_LEAF_HPP
