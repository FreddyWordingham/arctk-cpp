/**
 *  @file   arctk/gui/lens/orthographic.hpp
 *  @date   08/08/2018
 *  @author Freddy Wordingham
 *
 *  Perspective camera lens.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_LENS_ORTHOGRAPHIC_HPP
#define ARCTK_GUI_LENS_ORTHOGRAPHIC_HPP



//  == IMPORTS ==
//  -- Graphical --
#include <glm/glm.hpp>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/gui/lens.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace lens //! lens namespace
        {



            //  == CLASS ==
            /**
             *  Orthographic lens.
             */
            class Orthographic : public Lens
            {
                //  == FIELDS ==
              private:
                //  -- View --
                const glm::vec3 _min; //!< Minimum bound of the viewport.
                const glm::vec3 _max;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Orthographic(const glm::vec3& min_, const glm::vec3& max_) noexcept;


                //  == METHODS ==
              private:
                //  -- Updating --
                inline void update_view() noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct an orthographic lens with a given view viewport.
             *
             *  @param  min_    Minimum vertex of the viewport.
             *  @param  max_    Maximum vertex of the viewport.
             *
             *  @pre    min_.x must be less than max_.x.
             *  @pre    min_.y must be less than max_.y.
             *  @pre    min_.z must be less than max_.z.
             */
            inline Orthographic::Orthographic(const glm::vec3& min_, const glm::vec3& max_) noexcept
              : _min(min_)
              , _max(max_)
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);

                update_view();
            }


            //  == METHODS ==
            //  -- Updating --
            /**
             *  Update the orthographic matrix of the lens.
             */
            inline void Orthographic::update_view() noexcept
            {
                _proj = glm::ortho(_min.x, _max.x, _min.y, _max.y, _min.z, _max.z);
            }



        } // namespace lens
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_LENS_ORTHOGRAPHIC_HPP
