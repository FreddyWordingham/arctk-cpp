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
//  -- Std --
#include <cmath>

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
                const int x_start = static_cast<int>(std::trunc(min_.x / cell_size_.x));
                const int x_end   = static_cast<int>(std::trunc(max_.x / cell_size_.x));
                const int y_start = static_cast<int>(std::trunc(min_.y / cell_size_.y));
                const int y_end   = static_cast<int>(std::trunc(max_.y / cell_size_.y));

                std::cout << "x_start: " << x_start << '\n';
                std::cout << "x_end  : " << x_end << '\n';
                std::cout << "y_start: " << y_start << '\n';
                std::cout << "y_end  : " << y_end << '\n';

                std::vector<GLfloat> verts(3 * 2 * ((x_end - x_start + 1) + (y_end - y_start + 1)));

                size_t index = 0;
                for (int i = x_start; i <= x_end; ++i)
                {
                    verts[index]     = i * cell_size_.x;
                    verts[index + 1] = min_.y;
                    verts[index + 2] = 0.0f;

                    verts[index + 3] = i * cell_size_.x;
                    verts[index + 4] = max_.y;
                    verts[index + 5] = 0.0f;

                    index += 6;
                }

                for (int i = y_start; i <= y_end; ++i)
                {
                    verts[index]     = min_.x;
                    verts[index + 1] = i * cell_size_.y;
                    verts[index + 2] = 0.0f;

                    verts[index + 3] = max_.x;
                    verts[index + 4] = i * cell_size_.y;
                    verts[index + 5] = 0.0f;

                    index += 6;
                }

                return (verts);
            }



        } // namespace actor
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_ACTOR_GRID_HPP
