#include "Core/Model.h"
#include "Renderer/Renderer.h"
#include "OBJLoader.h"
#include <GLFW/glfw3.h>

namespace OGLE {
    Model::Model(const std::string& path)
    {
        OBJLoader loader(path);

        m_Shader = CreateRef<Shader>("res/shaders/FlatColor.glsl");
        m_VertexArray = CreateRef<VertexArray>();
        m_VertexBuffer = CreateRef<VertexBuffer>(loader.GetData().data(), loader.GetDataSize());
        m_IndexBuffer = CreateRef<IndexBuffer>(loader.GetVertexIndices().data(), loader.GetVertexIndicesSize());
        m_Layout = CreateRef<VertexBufferLayout>();
        m_Layout->Push(3);
        m_Layout->Push(3);
        m_Layout->Push(3);

        m_VertexArray->AddBuffer(*m_VertexBuffer, *m_Layout);
        m_VertexArray->AddBuffer(*m_IndexBuffer);
        //m_Texture = CreateRef<Texture>("res/texture/wall.jpg");
    }

    void Model::Draw() const 
    {
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f)); 
        Renderer::Submit(m_Shader, m_VertexArray, transform);
    }
}