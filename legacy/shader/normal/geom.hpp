/**
 *  @file   arctk/shader/normal/geom.hpp
 *  @date   06/08/2018
 *  @author Freddy Wordingham
 *
 *  Normal geometry subshader source code.
 */



//  == GUARD ==
#ifndef ARCTK_SHADER_NORMAL_GEOM_HPP
#define ARCTK_SHADER_NORMAL_GEOM_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace shader //! shader namespace
    {
        namespace normal //! normal shader namespace
        {



            //  == CONSTANTS ==
            //  -- Source --
            static const char* geom = R"(
                //  == VERSION ==
                #version 330 core



                //  == LINKING ==
                //  -- Layout --
                layout(triangles) in;
                layout(line_strip, max_vertices = 6) out;

                //  -- Uniforms --
                uniform float magnitude = 0.4;
                uniform mat4 proj;
                uniform mat4 view;
                uniform mat4 model;
                uniform vec4 col;



                //  == IN/OUTPUT ==
                //  -- Input --
                in vec3 vert_pos[];
                in vec3 vert_norm[];

                //  -- Output --
                out vec4 geom_col;



                //  == FUNCTION PROTOTYPES ==
                //  -- Normals --
                void create_normal(const mat4 mvp_, const vec3 pos_, const vec3 norm_);



                //  == MAIN ==
                void main()
                {
                    mat4 mvp = proj * view * model;

                    create_normal(mvp, vert_pos[0], vert_norm[0]);
                    create_normal(mvp, vert_pos[1], vert_norm[1]);
                    create_normal(mvp, vert_pos[2], vert_norm[2]);
                }



                //  == FUNCTIONS ==
                //  -- Normals --
                void create_normal(const mat4 mvp_, const vec3 pos_, const vec3 norm_)
                {
                    vec4 start  = vec4(pos_, 1.0);
                    gl_Position = mvp_ * start;
                    geom_col    = col;
                    EmitVertex();

                    vec4 end    = start + vec4(norm_ * magnitude, 0.0);
                    gl_Position = mvp_ * end;
                    geom_col    = vec4(0.0, 0.0, 0.0, 0.0);
                    EmitVertex();

                    EndPrimitive();
                }
            )"; //!< Normal geometry subshader source code.



        } // namespace normal
    }     // namespace shader
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SHADER_NORMAL_GEOM_HPP
