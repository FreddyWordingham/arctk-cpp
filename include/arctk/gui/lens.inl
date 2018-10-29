/**
 *  @file   arctk/gui/lens.inl
 *  @date   02/08/2018
 *  @author Freddy Wordingham
 *
 *  Scene lens class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_LENS_INL
#define ARCTK_GUI_LENS_INL



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



        //  == INSTANTIATION ==
        //  -- Destructors --
        /**
         *  Defaulted destructor method.
         */
        inline Lens::~Lens() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the projection matrix used to render the actor.
         *
         *  @return Projection matrix used to render the actor.
         */
        inline const glm::mat4& Lens::proj() const noexcept
        {
            return (_proj);
        }



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_LENS_INL
