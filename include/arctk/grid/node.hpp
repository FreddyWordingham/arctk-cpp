/**
 *  @file   arctk/data/node.hpp
 *  @date   17/09/2018
 *  @author Freddy Wordingham
 *
 *  Grid node base class.
 */



//  == GUARD ==
#ifndef ARCTK_GRID_NODE_HPP
#define ARCTK_GRID_NODE_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/geom.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace grid //! grid namespace
    {



        //  == CLASS ==
        /**
         *  Grid node base class.
         */
        class Node : public geom::shape::Aabb
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Node() noexcept            = default;
            inline Node(const Node&) noexcept = default; //!< Defaulted copy constructor.
            inline Node(Node&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Node() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Node& operator=(const Node&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Node& operator=(Node&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.
        };



        //  == INSTANTIATION ==
        //  -- Destructors --
        inline Node::~Node() noexcept = default;



    } // namespace grid
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GRID_NODE_HPP
