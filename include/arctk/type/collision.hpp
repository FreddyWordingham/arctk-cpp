/**
 *  @file   arctk/type/collision.hpp
 *  @date   15/10/2018
 *  @author Freddy Wordingham
 *
 *  Collision types.
 */



//  == GUARD ==
#ifndef ARCTK_TYPE_COLLISION_HPP
#define ARCTK_TYPE_COLLISION_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace type //! typeing namespace
    {



        //  == ENUMERATIONS ==
        //  -- Types --
        /**
         *  Enumeration of collision types that a photon may undergo during simulation.
         */
        enum class collision
        {
            INTER, //!< Interaction collision event.
            ENT,   //!< Entity collision event.
            LEAF,  //!< Leaf cell collision event.
            BLOCK, //!< Domain block collision event.
            DOM    //!< Domain collision event.
        };



    } // namespace type
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TYPE_COLLISION_HPP
