/**
 *  @file   arctk/tree/node.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Tree node base class.
 */



//  == GUARD ==
#ifndef ARCTK_TREE_NODE_HPP
#define ARCTK_TREE_NODE_HPP



//  == BASE ==
#include <arctk/geom/shape/box.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <vector>

//  -- Arctk --
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
    namespace node                     //! node namespace
    {
        class Leaf;
    } // namespace node
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace tree //! tree namespace
    {



        //  == CLASS ==
        /**
         *  Tree node base class.
         */
        class Node : public geom::shape::Box
        {
            //  == FIELDS ==
          protected:
            //  -- Depth --
            const size_t _depth; //!< Depth of the node.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Node(const vec3& min_, const vec3& max_, size_t depth_) noexcept;
            inline Node(const Node&) noexcept = default; //!< Defaulted copy constructor.
            inline Node(Node&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            inline ~Node() noexcept override;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Node& operator=(const Node&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Node& operator=(Node&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline size_t  depth() const noexcept;
            virtual size_t max_depth() const noexcept = 0; //!< Get the maximum depth of any cell contained within this cell. @return Maximum depth of any cell contained within this cell.
            virtual size_t max_tris() const noexcept  = 0; //!< Get the maximum number of triangles contained within any cell contained within this cell. @return Maximum number of triangles contained within any cell contained within this cell.
            virtual size_t num_nodes() const noexcept = 0; //!< Get the number of nodes contained within this node. @return Number of nodes contained within this node.
            virtual std::vector<geom::shape::Box> boxes() const noexcept = 0; //!< Get a vector of box shapes representing all cells contained within this cell.   @return Vector of box shapes representing all cells contained within this cell.

            //  -- Retrieval --
            virtual const node::Leaf* leaf(const vec3& pos_) const
              noexcept = 0; //!< Retrieve a pointer to the leaf cell for the given position. @param  pos_    Position to retrieve the corresponding leaf cell for.   @return Pointer to the leaf cell for the given position.
        };



    } // namespace tree
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/tree/node.inl>



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_HPP
