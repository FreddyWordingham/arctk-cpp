/**
 *  @file   arctk/gui/shader.hpp
 *  @date   01/08/2018
 *  @author Freddy Wordingham
 *
 *  Shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_HPP
#define ARCTK_GUI_SHADER_HPP



//  == IMPORTS ==
//  -- Std --
#include <iostream>
#include <map>
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/exit.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



        //  == CLASS ==
        /**
         *  Shader class.
         */
        class Shader
        {
            //  == FIELDS ==
          private:
            //  -- Handle --
            const GLuint _handle; //!< Handle of the shader.

            //  -- Uniforms Handles --
            const GLint                        _model;    //!< Model matrix uniform handle.
            const GLint                        _view;     //!< View matrix uniform handle.
            const GLint                        _proj;     //!< Projection matrix uniform handle.
            const std::map<std::string, GLint> _uniforms; //!< Additional uniform mappings.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Shader(const std::string& vert_code_, const std::string& frag_code_, const std::vector<std::string>& uniform_names_) noexcept;
            inline Shader(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_, const std::vector<std::string>& uniform_names_) noexcept;

            //  -- Initialisation --
            inline GLint                        init_uniform(const std::string& name_) const noexcept;
            inline std::map<std::string, GLint> init_uniforms(const std::vector<std::string>& uniform_names_) const noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a shader program from vertex and fragment sub-shader programs.
         *
         *  @param  vert_code_  Vertex sub-shader code.
         *  @param  frag_code_  Fragment sub-shader code.
         *
         *  @pre    vert_code_ must not be empty.
         *  @pre    frag_code_ must not be empty.
         */
        inline Shader::Shader(const std::string& vert_code_, const std::string& frag_code_, const std::vector<std::string>& uniform_names_) noexcept
          : _handle(init_handle(vert_code_, frag_code_))
          , _model(init_uniform("model"))
          , _view(init_uniform("view"))
          , _proj(init_uniform("proj"))
          , _uniform(init_uniforms(uniform_name_))
        {
            PRE(!vert_code_.empty());
            PRE(!frag_code_.empty());
        }


        //  -- Initialisation --
        inline GLint Shader::init_uniform(const std::string& name_) const noexcept
        {
            GLint proj = glGetUniformLocation(_handle, name_);

            if (proj < 0)
            {
                std::cerr << "Unable to construct gui shader.\n"
                          << "Failed to determine the location of the: `" << name_ << "` uniform within the shader.\n";

                std::exit(exit::error::SHADER_UNIFORM_NOT_FOUND);
            }

            return (proj);
        }

        inline std::map<std::string, GLint> Shader::init_uniforms(const std::vector<std::string>& uniform_names_) const noexcept
        {
            std::map<std::string, GLint> uniforms;

            for (size_t i = 0; i < uniform_names_.size(); ++i)
            {
                PRE(uniform_names_[i] != "model");
                PRE(uniform_names_[i] != "view");
                PRE(uniform_names_[i] != "proj");

                if (uniforms.find(uniform_name_[i]) != uniforms.end())
                {
                    std::cerr << "Unable to construct gui shader.\n"
                              << "Uniform name: `" << uniform_name_[i] << "` may only have a single handle.\n";

                    std::exit(exit::error::SHADER_UNIFORM_DUPLICATE);
                }

                uniforms.emplace(std::make_pair(uniform_name_[i], init_uniform(uniform_names_[i]));
            }

            return (uniforms);
        }



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_HPP
