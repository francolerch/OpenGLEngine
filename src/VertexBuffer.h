#pragma once
#include <array>

struct Vertex {
    float x, y;
    float r, g, b;
};

class VertexBuffer
{
private:
    unsigned int m_RendererId;
public:
    VertexBuffer(std::array<Vertex>& vertexArray);
    ~VertexBuffer();
};

VertexBuffer::VertexBuffer(std::array<Vertex>& vertexArray)
{
}

VertexBuffer::~VertexBuffer()
{
}
