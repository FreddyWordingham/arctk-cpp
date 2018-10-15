/**
 *  @file   arctk/enum/collision.hpp
 *  @date   15/10/2018
 *  @author Freddy Wordingham
 *
 *  Collision enumerations.
 */



//  == GUARD ==
#ifndef ARCTK_ENUM_COLLISION_HPP
#define ARCTK_ENUM_COLLISION_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace type //! type namespace
    {


        //  == ENUMERATIONS ==
        //  -- Types --
        enum class collision
        {
            INTERACTION,
            CELL,
            NODE,
            DOM
        };



    } // namespace type
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_ENUM_COLLISION_HPP
