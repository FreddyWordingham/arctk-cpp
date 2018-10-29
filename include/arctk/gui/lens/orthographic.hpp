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


//  == BASE ==
#include <arctk/gui/lens.hpp>



//  == IMPORTS ==
//  -- Graphical --
#include <glm/glm.hpp>



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
                const glm::vec3 _max; //!< Maximum bound of the viewport.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Orthographic(const glm::vec3& min_, const glm::vec3& max_) noexcept;


                //  == METHODS ==
              private:
                //  -- Updating --
                inline void update_view() noexcept override;
            };



        } // namespace lens
    }     // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/lens/orthographic.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_LENS_ORTHOGRAPHIC_HPP
