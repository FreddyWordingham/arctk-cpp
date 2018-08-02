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
//  -- Graphical --
#include <glm/glm.hpp>



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


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Lens(const Lens&) = default; //!< Defaulted copy constructor.
            inline Lens(Lens&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Lens() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Lens& operator=(const Lens&) = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Lens& operator=(Lens&&) = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual inline const glm::mat4& proj() const noexcept = 0;
        };



        //  == INSTANTIATION --
        //  -- Destructors --
        /**
         *  Defaulted destructor method.
         */
        inline Lens::~Lens() noexcept = default;



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_LENS_HPP
