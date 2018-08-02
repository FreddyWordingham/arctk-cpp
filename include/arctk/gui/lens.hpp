/**
 *  @file   arctk/gui/lens.hpp
 *  @date   02/08/2018
 *  @author Freddy Wordingham
 *
 *  Scene lens class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_LENS_HPP
#define ARCTK_GUI_LENS_HPP



//  == IMPORTS ==



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



        //  == CLASS ==
        /**
         *  Scene camera lens class.
         */
        class Lens
        {
            //  == FIELDS ==
          protected:
            //  -- Uniform --
            glm::mat4 _proj{}; //!< Projection matrix.


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual inline const glm::mat4& proj() const noexcept = 0;
        };



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_LENS_HPP
