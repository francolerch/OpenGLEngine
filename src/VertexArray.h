#pragma once
#include "VertexBuffer.h"

class VertexArray
{
private:
    unsigned int m_RendererId;
public:
    VertexArray();
    ~VertexArray();
    void AddBuffer(const VertexBuffer& vb);
    void Bind() const;
    void Unbind() const;
};