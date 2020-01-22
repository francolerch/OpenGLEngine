#type vertex
#version 310 es
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;

uniform mediump mat4 model;
uniform mediump mat4 view;
uniform mediump mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;  
    TexCoords = aTexCoords;
    gl_Position = projection * view * vec4(FragPos, 1.0);
}

#type fragment
#version 310 es
out mediump vec4 FragColor;

in mediump vec3 Normal;
in mediump vec3 FragPos;
in mediump vec2 TexCoords;

struct Material {
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
    mediump vec3 texture_normal;
    mediump float shininess;
};

struct Light {
    mediump vec3 position;
    mediump vec3 direction;
    mediump vec3 ambient;
    mediump vec3 diffuse;
    mediump vec3 specular;

    mediump float constant;
    mediump float linear;
    mediump float quadratic;
};

uniform Light light;
uniform Material material;

uniform mediump vec3 lightPos;
uniform mediump vec3 viewPos;
uniform mediump vec3 lightColor;

void main()
{    
    // ambient
    mediump vec3 ambient = light.ambient * lightColor * vec3(texture(material.texture_diffuse1, TexCoords).rgb);
  	
    // diffuse 
    mediump vec3 norm = normalize(Normal);
    mediump vec3 lightDir = normalize(lightPos - FragPos);

    //mediump vec3 lightDir = normalize(-light.direction);
    mediump float diff = max(dot(norm, lightDir), 0.0);
    mediump vec3 diffuse = light.diffuse * lightColor * (diff * vec3(texture(material.texture_diffuse1, TexCoords))); 
    
    // specular
    mediump vec3 viewDir = normalize(viewPos - FragPos);
    mediump vec3 reflectDir = reflect(-lightDir, norm);  
    mediump float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    mediump vec3 specular = light.specular * lightColor * spec * vec3(texture(material.texture_specular1, TexCoords));
        
    mediump float distance = length(light.position - FragPos);
    mediump float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance)); 
    ambient  *= attenuation; 
    diffuse  *= attenuation;
    specular *= attenuation;   

    mediump vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}