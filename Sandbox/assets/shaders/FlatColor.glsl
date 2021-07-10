#type vertex
#version 310 es

layout (location = 0) in vec3 aPos;
layout (location = 2) in vec3 aTexCoords;
layout (location = 1) in vec3 aNormal;

uniform mediump mat4 u_ViewProjection;
uniform mediump mat4 u_Transform;

out mediump vec3 normal;
out mediump vec3 texCoords;
out mediump vec3 FragPos;

void main()
{
    normal = aNormal;
    texCoords = aTexCoords;
    FragPos = vec3(u_Transform * vec4(aPos, 1.0));

    gl_Position = u_ViewProjection * u_Transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
};

#type fragment
#version 310 es

sampler2D texture;

out mediump vec4 FragColor;

in mediump vec3 normal;
in mediump vec3 texCoords;

uniform mediump vec3 lightPos;
in mediump vec3 FragPos;

void main()
{
    mediump vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
    mediump vec3 objectColor = vec3(1.0f, 0.0f, 0.0f);

    mediump float ambientStrength = 0.1;
    mediump vec3 ambient = ambientStrength * lightColor;

    mediump vec3 norm = normalize(normal);
    mediump vec3 lightDir = normalize(lightPos - FragPos);

    mediump float diff = max(dot(norm, lightDir), 0.0);
    mediump vec3 diffuse = diff * lightColor;

    mediump vec3 result = (ambient + diffuse) * objectColor;
    FragColor = vec4(result, 1.0);
    //FragColor = vec4(color, 1.0f);
};
