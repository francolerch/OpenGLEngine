#pragma once
#include "pch.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Renderer/Shader.h"

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec2 Tangent;
    glm::vec2 Bitangent;
};

struct Tex {
    unsigned int id;
    std::string type;
    std::string path;
};

class Mesh {
    public:
        /*  Mesh Data  */
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Tex> textures;
        /*  Functions  */
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Tex> textures);
        void Draw(Shader shader);
    private:
        /*  Render data  */
        unsigned int VAO, VBO, EBO;
        /*  Functions    */
        void setupMesh();
};