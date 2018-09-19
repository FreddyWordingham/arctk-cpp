/**
 *  @file   arctk/mesh/adaptive.hpp
 *  @date   19/09/2018
 *  @author Freddy Wordingham
 *
 *  Adaptive mesh class.
 */



//  == GUARD ==
#ifndef ARCTK_MESH_ADAPTIVE_HPP
#define ARCTK_MESH_ADAPTIVE_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <memory>

//  -- Arctk --
#include <arctk/math.hpp>
#include <arctk/mesh/node.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace mesh //! mesh namespace
    {



        //  == CLASS ==
        /**
         *  Mesh node base class.
         */
        class Adaptive
        {
            //  -- Positioning --
            const vec3 _centre; //!< Centre coordinate of the node.

            //  -- Children --
            const std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> _childs;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



    } // namespace mesh
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MESH_ADAPTIVE_HPP
