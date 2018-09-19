/**
 *  @file   arctk/mesh/node.hpp
 *  @date   17/09/2018
 *  @author Freddy Wordingham
 *
 *  Grid node base class.
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
    namespace grid //! grid namespace
    {
        namespace node //! node namespace
        {



            //  == CLASS PROTOTYPES ==
            class Leaf;



        } // namespace node



        //  == CLASS ==
        /**
         *  Grid node base class.
         */
        class Node : public geom::shape::Aabb
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Node(const vec3& min_, const vec3& max_) noexcept;
            inline Node(const Node&) noexcept = default; //!< Defaulted copy constructor.
            inline Node(Node&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Node() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Node& operator=(const Node&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Node& operator=(Node&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual size_t                         num_nodes() const noexcept = 0;
            virtual std::vector<geom::shape::Aabb> boxes() const noexcept     = 0;

            //  -- Retrieval --
            virtual node::Leaf const* leaf(const vec3& pos_) const noexcept = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Node::Node(const vec3& min_, const vec3& max_) noexcept
          : geom::shape::Aabb(min_, max_)
        {
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
        }


        //  -- Destructors --
        inline Node::~Node() noexcept = default;



    } // namespace grid
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MESH_NODE_HPP
