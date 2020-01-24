#include "Core/Model.h"
#include "Renderer/Renderer.h"
#include "OBJLoader.h"

namespace OGLE {
    Model::Model(const std::string& path)
    {
        OBJLoader loader(path);

        m_Shader = CreateRef<Shader>("res/shaders/FlatColor.glsl");
        m_VertexArray = CreateRef<VertexArray>();
        m_VertexBuffer = CreateRef<VertexBuffer>(loader.GetVertices().data(), loader.GetVerticesSize());
        m_IndexBuffer = CreateRef<IndexBuffer>(loader.GetIndices().data(), loader.GetIndicesSize());
        m_Layout = CreateRef<VertexBufferLayout>();
        m_Layout->Push(3);

        m_VertexArray->AddBuffer(*(m_VertexBuffer.get()), *(m_Layout.get()));
    }

    void Model::Draw() const 
    {
        Renderer::Submit(m_Shader, m_VertexArray, glm::mat4(1.f));
    }
}