/**
 *  @file   arctk/gui/camera.hpp
 *  @date   04/06/2018
 *  @author Freddy Wordingham
 *
 *  Rendering camera class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_HPP
#define ARCTK_GUI_CAMERA_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_GUI



//  == IMPORTS ==
//  -- Graphical --
#include <glm/glm.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical user interface namespace
    {



        //  == CLASS ==
        /**
         *  Graphical rendering camera class.
         */
        class Camera
        {
            //  == FIELDS ==
          private:
            //  -- Positioning --
            glm::vec3 _pos;
            glm::vec3 _dir;
            glm::vec3 _up;

            //  -- Uniform --
            glm::mat4                        _mvp;
            std::map<std::string, int>       _int_uniform;
            std::map<std::string, float>     _float_uniform;
            std::map<std::string, glm::vec2> _vec2_uniform;
            std::map<std::string, glm::vec3> _vec3_uniform;
            std::map<std::string, glm::vec4> _vec4_uniform;
            std::map<std::string, glm::mat2> _mat2_uniform;
            std::map<std::string, glm::mat3> _mat3_uniform;
            std::map<std::string, glm::mat4> _mat4_uniform;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --

            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION --



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_HPP
