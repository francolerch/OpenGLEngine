#pragma once
#include "Core/Core.h"
#include "Renderer/Shader.h"
//#include "Texture.h"
/*#include "Renderer/VertexArray.h"
#include "Renderer/Renderer.h"
#include "Renderer/VertexBufferLayout.h"
#include "Renderer/IndexBuffer.h"
#include "Renderer/Texture.h"*/
#include "MeshLoader.h"

namespace OGLE {
    class Model
    {
    private:
        std::string m_Path;
        //Ref<Shader> m_Shader;
        Ref<Shader> m_Shader;
        /*Ref<VertexArray> m_VertexArray;
        Ref<VertexBuffer> m_VertexBuffer;
        Ref<IndexBuffer> m_IndexBuffer;
        Ref<VertexBufferLayout> m_Layout;
        Ref<Texture> m_Texture;*/
        MeshLoader m_loader;

    public:
        Model(const std::string& path);
        ~Model() = default;

        void Draw(const glm::mat4& transform);
        const Ref<Shader>& GetShader() { return m_Shader; };
    };
}