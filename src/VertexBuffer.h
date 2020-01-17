#pragma once

struct Vertex {
    float x, y;
    float r, g, b;
};

class VertexBuffer
{
private:
    unsigned int m_RendererId;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();
    void Bind() const;
    void UnBind() const;
};