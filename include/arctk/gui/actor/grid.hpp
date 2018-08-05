/**
 *  @file   arctk/gui/actor/grid.hpp
 *  @date   05/08/2018
 *  @author Freddy Wordingham
 *
 *  Grid actor class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_ACTOR_GRID_HPP
#define ARCTK_GUI_ACTOR_GRID_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/gui/actor.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace actor //! actor namespace
        {



            //  == CLASS ==
            /**
             *  Grid actor object.
             */
            class Grid : public Actor
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Grid(const glm::vec2& min_, const glm::vec2& max_, const glm::vec2& cell_size_) noexcept;

              private:
                //  -- Initialisation --
                std::vector<GLfloat> init_verts(const glm::vec2& min_, const glm::vec2& max_, const glm::vec2& cell_size_) const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Grid::Grid(const glm::vec2& min_, const glm::vec2& max_, const glm::vec2& cell_size_) noexcept
              : Actor(init_verts(min_, max_, cell_size_), {3}, GL_LINES)
            {
            }


            //  -- Initialisation --
            std::vector<GLfloat> Grid::init_verts(const glm::vec2& min_, const glm::vec2& max_, const glm::vec2& cell_size_) const noexcept
            {
            }



        } // namespace actor
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_ACTOR_GRID_HPP
