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
    namespace mesh //! mesh namespace
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
          private:
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Node(const Node&) noexcept = default; //!< Defaulted copy constructor.
            inline Node(Node&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            inline ~Node() noexcept override;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Node& operator=(const Node&) noexcept = default; //!< Deleted copy operator. @return Reference to copied object.
            inline Node& operator=(Node&&) noexcept = default;      //!< Deleted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --

            //  -- Retrieval --
            virtual const node::Leaf& leaf(const vec3& pos_) const noexcept = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == METHODS ==
        //  -- Getters --



    } // namespace mesh
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_HPP
