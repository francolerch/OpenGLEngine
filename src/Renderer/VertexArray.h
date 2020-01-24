#pragma once
#include "pch.h"
#include "Core/Core.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"
#include "VertexBufferLayout.h"

namespace OGLE {
    class VertexArray
    {
    private:
        unsigned int m_RendererId;
        VertexBuffer m_VertexBuffer;
        IndexBuffer m_IndexBuffer;

    public:
        VertexArray();
        ~VertexArray();

        inline IndexBuffer GetIndexBuffer() const { return m_IndexBuffer; };
        void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
        void Bind() const;
        void Unbind() const;
    };
}