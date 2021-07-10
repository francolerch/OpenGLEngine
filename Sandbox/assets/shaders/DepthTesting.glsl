#type vertex
#version 300 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor; 
out vec2 texCoord;
uniform mat4 u_Transform;
uniform mat4 u_Mvp;

void main()
{
    gl_Position = u_Mvp * u_Transform * vec4(aPos, 1.0);
    ourColor = aColor;
    texCoord = aTexCoord;
};

#type fragment
#version 300 core

in vec3 ourColor;
in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D ourTexture;
uniform sampler2D texture2;
uniform vec4 u_Color;

float near = 0.1; 
float far  = 100.0; 
  
float LinearizeDepth(float depth) 
{
    float z = depth * 2.0 - 1.0; // back to NDC 
    return (2.0 * near * far) / (far + near - z * (far - near));	
}

void main()
{
    float depth = LinearizeDepth(gl_FragCoord.z) / far; // divide by far for demonstration
    FragColor = vec4(vec3(depth), 1.0) * vec4(1.0, 0.1, 0.6, 1.0) ;
};
