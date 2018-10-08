/**
 *  @file   arctk/scene/cell.hpp
 *  @date   08/10/2018
 *  @author Freddy Wordingham
 *
 *  Scene cell information class.
 */



//  == GUARD ==
#ifndef ARCTK_SCENE_CELL_HPP
#define ARCTK_SCENE_CELL_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace scene //! scene namespace
    {



        //  == CLASS ==
        /**
         *  Scene information cell.
         */
        class Cell : public geom::shape::Box
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            double _interactions;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Cell(const vec3& min_, const vec3& max_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double interactions() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Cell::Cell(const vec3& min_, const vec3& max_) noexcept
          : Box(min_, max_)
          , _interactions(0.0)
        {
            PRE(min_.x <= max_.x);
            PRE(min_.y <= max_.y);
            PRE(min_.z <= max_.z);
        }



        //  == METHODS ==
        //  -- Getters --
        inline double Cell::interactions() const noexcept
        {
            return (_interactions);
        }



    } // namespace scene
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SCENE_CELL_HPP
