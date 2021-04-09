#include "pch.h"
#include "Buffer.h"
#include "glad/glad.h"

namespace OGLE {
    Buffer::Buffer(const void* data, unsigned int size, GLenum type)
        :m_Data(data), m_Size(size), m_Type(type)
    {
        glGenBuffers(1, &m_RendererId);
        glBindBuffer(m_Type, m_RendererId);
        glBufferData(m_Type, size, data, GL_STATIC_DRAW);
    }

    Buffer::~Buffer()
    {
        glDeleteBuffers(1, &m_RendererId);
    }

    void Buffer::Bind() const
    {
        glBindBuffer(m_Type, m_RendererId);
    }

    void Buffer::UnBind() const
    {
        glBindBuffer(m_Type, 0);
    }
}