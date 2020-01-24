#type vertex
#version 310 es

layout (location = 0) in vec3 aPos;

uniform mediump mat4 u_ViewProjection;
uniform mediump mat4 u_Transform;
void main()
{
    gl_Position = u_ViewProjection * u_Transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
};

#type fragment
#version 310 es

out mediump vec4 FragColor;

void main()
{
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
};
