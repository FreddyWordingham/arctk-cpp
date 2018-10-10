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



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace tree //! tree namespace
    {
        namespace node //! node namespace
        {



            //  == CLASS PROTOTYPES ==
            class Leaf;



        } // namespace node



        //  == CLASS ==
        /**
         *  Tree node base class.
         */
        class Node : public geom::shape::Box
        {
            //  == FIELDS ==
          protected:
            //  -- Depth --
            const size_t _depth;


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
            inline size_t                         depth() const noexcept;
            virtual size_t                        max_depth() const noexcept = 0;
            virtual size_t                        max_tris() const noexcept  = 0;
            virtual size_t                        num_nodes() const noexcept = 0;
            virtual std::vector<geom::shape::Box> boxes() const noexcept     = 0;

            //  -- Retrieval --
            virtual const node::Leaf& leaf(const vec3& pos_) const noexcept = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Node::Node(const vec3& min_, const vec3& max_, const size_t depth_) noexcept
          : Box(min_, max_)
          , _depth(depth_)
        {
            PRE(min_.x <= max_.x);
            PRE(min_.y <= max_.y);
            PRE(min_.z <= max_.z);
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



    } // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_HPP
