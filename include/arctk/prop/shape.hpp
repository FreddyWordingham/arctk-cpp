/**
 *  @file   arctk/prop/shape.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of shape property functions.
 */



//  == GUARD ==
#ifndef ARCTK_PROP_SHAPE_HPP
#define ARCTK_PROP_SHAPE_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {
        namespace shape //! shape§ namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Shape --
            template <typename T>
            inline bool square(const std::vector<std::vector<T>>& vec_) noexcept;
            template <typename T>
            inline bool cube(const std::vector<std::vector<std::vector<T>>>& vec_) noexcept;



        } // namespace shape
    }     // namespace prop
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/prop/shape.inl>



//  == GUARD END ==
#endif // ARCTK_PROP_SHAPE_HPP
