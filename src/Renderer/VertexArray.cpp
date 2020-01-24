#pragma once
#include "pch.h"
#include "VertexArray.h"

namespace OGLE {
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &m_RendererId);
        glBindVertexArray(m_RendererId);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererId);
    }

    void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
    {
        //m_VertexBuffer = vb;

        Bind();
        vb.Bind();

        const auto& elements = layout.GetElements();
        unsigned int offset = 0;

        for (unsigned int i = 0; i < elements.size(); i++)
        {
            const auto& element = elements[i];
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset);

            offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
        }
    }

    void VertexArray::AddBuffer(const IndexBuffer& vb)
    {
        m_IndexBuffer = vb;
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(m_RendererId);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }
}