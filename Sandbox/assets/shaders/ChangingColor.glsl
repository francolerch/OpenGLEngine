#type vertex
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor; 
out vec2 texCoord;
uniform mat4 u_Transform;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position =  projection * view * model * u_Transform * vec4(aPos, 1.0);
    ourColor = aColor;
    texCoord = aTexCoord;
};

#type fragment
#version 330 core

in vec3 ourColor;
in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D ourTexture;
uniform sampler2D texture2;
uniform vec4 u_Color;

void main()
{
    vec4 tex = texture(ourTexture, texCoord);
    FragColor = tex;
};
