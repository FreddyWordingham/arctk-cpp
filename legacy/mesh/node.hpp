/**
 *  @file   arctk/mesh/node.hpp
 *  @date   17/09/2018
 *  @author Freddy Wordingham
 *
 *  Mesh node base class.
 */



//  == GUARD ==
#ifndef ARCTK_MESH_NODE_HPP
#define ARCTK_MESH_NODE_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace mesh //! mesh namespace
    {
        namespace node //! node namespace
        {



            //  == CLASS PROTOTYPES ==
            class Leaf;



        } // namespace node



        //  == CLASS ==
        /**
         *  Mesh node base class.
         */
        class Node : public geom::shape::Aabb
        {
            //  == FIELDS ==
          protected:
            //  -- Properties --
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
            virtual size_t max_depth() const noexcept  = 0; //!< Get the maximum depth of this node and any of its descendents.  @return Maximum depth of this node and any of its descendents.
            virtual size_t max_shapes() const noexcept = 0; //!< Get the maximum number of shapes contained within this node and any of its descendents. @return Maximum number of shapes contained within this node and any of its descendents.
            virtual size_t num_nodes() const noexcept  = 0; //!< Get the total number of nodes related to this node. Includes this node in the count.    @return Total number of nodes related to this node.
            virtual std::vector<geom::shape::Aabb> boxes() const
              noexcept = 0; //!< Get a vector of all the axis-aligned bounding boxes of the leaf nodes descended from this node. @return Vector of all the axis-aligned bounding boxes of the leaf nodes descended from this node.

            //  -- Retrieval --
            virtual node::Leaf const* leaf(const vec3& pos_) const noexcept = 0; //!< Get the pointer to the leaf node corresponding to a given position within this node.    @param  pos_    Position to find the corresponding leaf node for.   @pre    pos_
                                                                                 //!< must be contained within this node.    @return Pointer to the leaf node corresponding to a given position within this node.
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a node with given bounds at a given depth.
         *
         *  @param  min_    Minimum bound of the mesh.
         *  @param  max_    Maximum bound of the mesh.
         *  @param  depth_  Depth of the node.
         *
         *  @pre    min_.x must be less than max_.x.
         *  @pre    min_.y must be less than max_.y.
         *  @pre    min_.z must be less than max_.z.
         */
        inline Node::Node(const vec3& min_, const vec3& max_, const size_t depth_) noexcept
          : geom::shape::Aabb(min_, max_)
          , _depth(depth_)
        {
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Node::~Node() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the depth of the node.
         *
         *  @return Depth of the node.
         */
        inline size_t Node::depth() const noexcept
        {
            return (_depth);
        }



    } // namespace mesh
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MESH_NODE_HPP
