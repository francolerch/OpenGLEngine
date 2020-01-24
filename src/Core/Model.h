#pragma once
#include "pch.h"
#include "Renderer/Shader.h"
//#include "Texture.h"
#include "Renderer/VertexArray.h"
#include "Renderer/Renderer.h"
#include "Renderer/VertexBufferLayout.h"
#include "Renderer/IndexBuffer.h"

namespace OGLE {
    class Model
    {
    private:
        std::string m_Path;
        Ref<Shader> m_Shader;
        Ref<VertexArray> m_VertexArray;
        Ref<VertexBuffer> m_VertexBuffer;
        Ref<IndexBuffer> m_IndexBuffer;
        Ref<VertexBufferLayout> m_Layout;

    public:
        Model(const std::string& path);
        ~Model() = default;

        void Draw() const;
    };
}