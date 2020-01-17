#include "pch.h"
#include "VertexArray.h"
#include "RendererCore.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_RendererId);
    glBindVertexArray(m_RendererId);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_RendererId);
}

void VertexArray::AddBuffer(const VertexBuffer& vb)
{
    Bind();
    vb.Bind();

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

void VertexArray::Bind() const
{
    glBindVertexArray(m_RendererId);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}
