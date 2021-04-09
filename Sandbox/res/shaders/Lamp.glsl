#type vertex
#version 310 es
layout (location = 0) in vec3 aPos;

uniform mediump mat4 model;
uniform mediump mat4 view;
uniform mediump mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);
}

#type fragment
#version 310 es
out mediump vec4 FragColor;

void main()
{
    FragColor = vec4(1.0);
}