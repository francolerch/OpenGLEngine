#type vertex
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor; 
out vec4 ourPosition;
out vec2 texCoord;

uniform float u_Time;

void main()
{
    float s = sin(u_Time) * 0.5 + 1;
    ourPosition = vec4(aPos.xyz * s, 1.0);
    gl_Position = ourPosition;
    ourColor = aColor;
    texCoord = aTexCoord;
};

#type fragment
#version 330 core

in vec3 ourColor;
in vec4 ourPosition;
in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D ourTexture;
uniform sampler2D texture2;
uniform vec4 u_Color;
uniform float u_Opacity;

void main()
{
    vec4 tex = mix(texture(ourTexture, texCoord), texture(texture2, texCoord), 0.2);
    FragColor = clamp(ourPosition.xyzw, 0.5, 1.0) * tex * vec4(ourColor.rgb * u_Color.rgb, 1.0);
};
