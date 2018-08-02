/**
 *  @file   arctk/gui/uniform.hpp
 *  @date   01/08/2018
 *  @author Freddy Wordingham
 *
 *  Shader uniform class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_UNIFORM_HPP
#define ARCTK_GUI_UNIFORM_HPP



//  == IMPORTS ==



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



        //  == CLASS ==
        /**
         *  Shader uniform class.
         */
        class Uniform
        {
            //  == ENUMERATION ==
          public:
            //  -- Type --
            /**
             *  Enumeration of possible types to be handled by the uniform.
             */
            enum class stored
            {
                INT,
                FLOAT,
                VEC2,
                VEC3,
                VEC4,
                MAT2,
                MAT3,
                MAT4
            };


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_UNIFORM_HPP
