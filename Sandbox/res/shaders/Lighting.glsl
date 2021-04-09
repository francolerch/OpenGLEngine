#type vertex
#version 310 es
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 FragPos;
out vec3 Normal;

uniform mediump mat4 model;
uniform mediump mat4 view;
uniform mediump mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;  
    
    gl_Position = projection * view * vec4(FragPos, 1.0);
}

#type fragment
#version 310 es
out mediump vec4 FragColor;

in mediump vec3 Normal;
in mediump vec3 FragPos;

uniform mediump vec3 lightPos; 
uniform mediump vec3 viewPos; 
uniform mediump vec3 lightColor;
uniform mediump vec3 objectColor;

struct Light {
    mediump vec3 position;
    mediump vec3 ambient;
    mediump vec3 diffuse;
    mediump vec3 specular;
};

uniform Light light; 

struct Material {
    mediump vec3 ambient;
    mediump vec3 diffuse;
    mediump vec3 specular;
    mediump float shininess;
}; 
  
uniform Material material;

void main()
{
    // ambient
    mediump vec3 ambient = light.ambient * lightColor * material.ambient;
  	
    // diffuse 
    mediump vec3 norm = normalize(Normal);
    mediump vec3 lightDir = normalize(lightPos - FragPos);
    mediump float diff = max(dot(norm, lightDir), 0.0);
    mediump vec3 diffuse = light.diffuse * lightColor * (diff * material.diffuse);
    
    // specular
    mediump vec3 viewDir = normalize(viewPos - FragPos);
    mediump vec3 reflectDir = reflect(-lightDir, norm);  
    mediump float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    mediump vec3 specular = light.specular * lightColor * (spec * material.specular);  
        
    mediump vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
} 