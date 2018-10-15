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
    namespace type //! type namespace
    {


        //  == ENUMERATIONS ==
        //  -- Types --
        enum class collision
        {
            INTER,
            ENT,
            LEAF,
            CELL,
            DOM
        };



    } // namespace type
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TYPE_COLLISION_HPP
