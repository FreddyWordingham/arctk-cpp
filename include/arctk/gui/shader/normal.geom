R""(
//  == VERSION ==
#version 330 core



//  == LINKING ==
//  -- Layout --
layout(triangles) in;
layout(line_strip, max_vertices = 6) out;

//  -- Uniforms --
uniform mat4  model;
uniform mat4  view;
uniform mat4  proj;
uniform vec4  col;
uniform vec4  end_col = vec4(0.0, 0.0, 0.0, 0.0);
uniform float length  = 0.4;



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
    geom_col    = end_col;
    EmitVertex();

    EndPrimitive();
}
)""
