#type vertex
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor; 

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor;
};

#type fragment
#version 330 core

in vec3 ourColor;
out vec4 FragColor;

uniform vec4 u_Color;

void main()
{
    FragColor =  vec4(ourColor.rgb * u_Color.rgb, 1.0);
};