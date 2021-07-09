#type vertex
#version 310 es

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec3 aTexCoords;

uniform mediump mat4 u_ViewProjection;
uniform mediump mat4 u_Transform;

out mediump vec3 normal;
out mediump vec3 texCoords;

void main()
{
    normal = aNormal;
    texCoords = aTexCoords;
    gl_Position = u_ViewProjection * u_Transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
};

#type fragment
#version 310 es

sampler2D texture;

out mediump vec4 FragColor;

in mediump vec3 normal;
in mediump vec3 texCoords;

void main()
{
    mediump vec3 color = vec3(1.0f, 0.0f, 0.0f);
    FragColor = vec4(color, 1.0f);
};
